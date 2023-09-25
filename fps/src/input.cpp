/* *****************************************************************************
##
# @file        input.cpp
# @brief       handling SDL events
# @copyright   MIT license
# ****************************************************************************/
#include "input.hpp"
#include "map.hpp"
#include "map_rendering_bev.hpp"

void angleModulo(float_t& angle)
{
	if(angle > 180.F)
	{
		angle -= 360.F;
	}
	if(angle < -180.F)
	{
		angle += 360.F;
	}
}

/// @brief 
/// @param f_player 
/// @param f_offset 
/// @param map 
/// @return 0 if no progression, 1 if x progression, 2 if y progression and 3 if x and y progression
int32_t checkFreeSpace(const StatePlayer& f_player, const StatePlayer& f_offset)
{
	int32_t result{0};

	// compute requested position
	StatePlayer next;
	next.x = f_player.x + f_offset.x;
	next.y = f_player.y + f_offset.y;

	// get candidate cell index, X direction
	int32_t cell_col = static_cast<int32_t>(next.x) / CELL_SIZE;
	int32_t cell_row = static_cast<int32_t>(next.y) / CELL_SIZE;
	int32_t xNeighborIndex = computeCellIndex(cell_row,cell_col);

	// Check freespace and update result
	if(g_map[xNeighborIndex] == 0)
	{
		result = 3;
	}
	else
	{
		// If progression not possible, check X-only progression
		cell_col = static_cast<int32_t>(next.x) / CELL_SIZE;
		cell_row = static_cast<int32_t>(f_player.y) / CELL_SIZE;
		xNeighborIndex = computeCellIndex(cell_row,cell_col);
		result = (g_map[xNeighborIndex] == 0)? 1: 0;
		// If x-only progression not possible, check y-only
		if(result == 0)
		{
			cell_col = static_cast<int32_t>(f_player.x) / CELL_SIZE;
			cell_row = static_cast<int32_t>(next.y) / CELL_SIZE;
			xNeighborIndex = computeCellIndex(cell_row,cell_col);
			result = (g_map[xNeighborIndex] == 0)? 2: 0;
		}
	}

	return result;
}

void updatePosition(StatePlayer& f_player, StatePlayer& f_offset, int32_t freespaceInfo)
{
	if((freespaceInfo == 3)||(freespaceInfo == 1))
	{
		f_player.x += f_offset.x;
	}
	if((freespaceInfo == 3)||(freespaceInfo == 2))
	{
		f_player.y += f_offset.y;
	}
}

void ProcessMovingEvent(SDL_KeyboardEvent& key, StatePlayer& f_player)
{
	StatePlayer offset{};
	float_t angleRadian{degToRad(f_player.orientation)};
	int32_t freespaceInfo{0};
	switch (key.keysym.sym) {
		case SDLK_LEFT:
			f_player.orientation += 2;
			angleModulo(f_player.orientation);
			break;
		case SDLK_RIGHT:
			f_player.orientation -= 2;
			angleModulo(f_player.orientation);
			break;
		case SDLK_UP:
			offset.x = SDL_cosf(angleRadian);
			offset.y = SDL_sinf(angleRadian);
			freespaceInfo = checkFreeSpace(f_player, offset);
			updatePosition(f_player, offset, freespaceInfo);
			break;
		case SDLK_DOWN:
			offset.x = -SDL_cosf(angleRadian);
			offset.y = -SDL_sinf(angleRadian);
			freespaceInfo = checkFreeSpace(f_player, offset);
			if(checkFreeSpace(f_player, offset))
			{
				updatePosition(f_player, offset, freespaceInfo);
			}
			break;
		default:
			break;
	}
};

void doInput(StatePlayer& f_player)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_EVENT_QUIT:
				exit(0);
				break;
			case SDL_EVENT_KEY_DOWN:
				ProcessMovingEvent(event.key, f_player);
				break;

			case SDL_EVENT_KEY_UP:
				// Do nothing
				break;

			default:
				break;
		}
	}
}