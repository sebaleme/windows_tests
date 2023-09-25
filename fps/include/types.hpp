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
#include "map.hpp"

// Cell size
static constexpr int32_t CELL_SIZE{50};

// Screen resolution
static constexpr int32_t SCREEN_WIDTH{MAP_WIDTH*CELL_SIZE};
static constexpr int32_t SCREEN_HEIGHT{MAP_HEIGHT*CELL_SIZE};

// Player size
// Should be an even number for rendering purpose
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
struct StatePlayer
{
	float_t x; 			 // metres
	float_t y;			 // metres
	float_t direction;   // degrees
	float_t radius;   	 // metres
	float_t orientation; // degrees
};

struct CApplication
{
   	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *texture;
	uint32_t pixels[SCREEN_WIDTH*SCREEN_HEIGHT];
	StatePlayer player;
};


#endif /* FSP_TYPES_HPP */