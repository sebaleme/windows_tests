/* *****************************************************************************
##
# @file        input.cpp
# @brief       handling SDL events
# @copyright   MIT license
# ****************************************************************************/
#include "input.hpp"

void ProcessMovingEvent(SDL_KeyboardEvent& key, position& f_player)
{
	switch (key.keysym.sym) {
	case SDLK_LEFT:
		f_player.x -= 1;
		break;
	case SDLK_RIGHT:
		f_player.x += 1;
		break;
	case SDLK_UP:
		f_player.y += 1;
		break;
	case SDLK_DOWN:
		f_player.y -= 1;
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