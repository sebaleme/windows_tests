/* *****************************************************************************
##
# @file        init.cpp
# @brief       Initializing SDL rendering class
# @copyright   MIT license
# ****************************************************************************/

#include "init.hpp"
#include <SDL3/SDL.h>
#include <stdio.h>

void initSDL(CApplication& app)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("Shooter 01", SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, NULL, rendererFlags);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	// Initialize player position
	app.player.x = CELL_SIZE + 2.F;
	app.player.y = CELL_SIZE + 2.F;
	app.player.radius = static_cast<float_t>(app.player.x*app.player.x + app.player.y*app.player.y);
	app.player.orientation = 0.F;
	printf("Init done; player at position: %f, %f\n", app.player.x, app.player.y);
}