/* *****************************************************************************
##
# @file        input.cpp
# @brief       handling SDL events
# @copyright   MIT license
# ****************************************************************************/
#include "input.hpp"

void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_EVENT_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}