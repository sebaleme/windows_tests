/* *****************************************************************************
##
# @file        input.cpp
# @brief       handling SDL events
# @copyright   MIT license
# ****************************************************************************/
#include "input.hpp"

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

void ProcessMovingEvent(SDL_KeyboardEvent& key, position& f_player)
{
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
		f_player.x += SDL_cosf(f_player.orientation*SDL_PI_F/180.F);
		f_player.y += SDL_sinf(f_player.orientation*SDL_PI_F/180.F);		
		break;
	case SDLK_DOWN:
		f_player.x -= SDL_cosf(f_player.orientation*SDL_PI_F/180.F);
		f_player.y -= SDL_sinf(f_player.orientation*SDL_PI_F/180.F);
		break;
	default:
		break;
	}
};

void doInput(position& f_player)
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