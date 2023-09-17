/* *****************************************************************************
##
# @file        types.hpp
# @brief       Type definition used in the FPS programm
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_TYPES_HPP
#define FSP_TYPES_HPP

#include <SDL3/SDL.h>
#include "colors.hpp"

// Map size
static constexpr int8_t MAP_WIDTH{8};
static constexpr int8_t MAP_HEIGHT{8};
// Cell size
static constexpr int32_t CELL_SIZE{50};

// Screen resolution
static constexpr int32_t SCREEN_WIDTH{MAP_WIDTH*CELL_SIZE};
static constexpr int32_t SCREEN_HEIGHT{MAP_HEIGHT*CELL_SIZE};

// Player size
static constexpr int32_t CURSOR_SIZE{8};

// View definition
// Objects are 2m high
// The distance of top row pixels is (HEIGHT_CEILING - HEIGHT_OBSERVER) / tan(VERTICAL_FOV/2)
static constexpr float_t HORIZONTAL_FOV{120.F}; // degree
static constexpr float_t VERTICAL_FOV{90.F}; // degree
static constexpr float_t DISTANCE_OBSERVER{1.F}; // meter
static constexpr float_t HEIGHT_OBSERVER{1.5F}; // meter
static constexpr float_t HEIGHT_CEILING{2.F}; // meter

static constexpr float_t HORIZONTAL_RES{HORIZONTAL_FOV/SCREEN_WIDTH}; // degree per pixel
static constexpr float_t VERTICAL_RES{VERTICAL_FOV/SCREEN_HEIGHT}; // degree per pixel

// X is horizontal, Y is vertical
// (0,0) is bottom left
struct position
{
	float_t x; 			 // metres
	float_t y;			 // metres
	float_t direction;   // degree
};

struct CApplication
{
   	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *texture;
	uint32_t pixels[SCREEN_WIDTH*SCREEN_HEIGHT];
	position player;

	// 0 means empty, else an object
	// each value is represented through a color
	uint8_t map[MAP_WIDTH*MAP_HEIGHT]=
		// Create map
	{
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,2,0,0,1,
		1,0,0,0,2,2,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,2,0,0,0,0,1,
		1,1,1,1,1,1,1,1,
	};
};


#endif /* FSP_TYPES_HPP */