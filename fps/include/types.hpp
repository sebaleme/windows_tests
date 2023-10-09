/* *****************************************************************************
##
# @file        types.hpp
# @brief       Type definition used in the FPS programm
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_TYPES_HPP
#define FSP_TYPES_HPP

#include <SDL3/SDL.h>
#include <cassert>
#include "colors.hpp"
#include "map.hpp"
#include "state_player.hpp"

// C++11 compile time square root using binary search
#define MID ((lo + hi + 1) / 2)
constexpr int32_t sqrt_helper(int32_t x, int32_t lo, int32_t hi)
{
  return lo == hi ? lo : ((x / MID < MID)
      ? sqrt_helper(x, lo, MID - 1) : sqrt_helper(x, MID, hi));
}
constexpr int32_t ct_sqrt(int32_t x)
{
	assert( x > 0);
  	return sqrt_helper(x, 0, x / 2 + 1);
}

// Cell size
static constexpr int32_t CELL_SIZE_PIXELS{50};

// Screen resolution
static constexpr int32_t SCREEN_WIDTH{MAP_WIDTH*CELL_SIZE_PIXELS};
static constexpr int32_t SCREEN_HEIGHT{MAP_HEIGHT*CELL_SIZE_PIXELS};
static constexpr int32_t SCREEN_MAXDISTSQUARED{SCREEN_HEIGHT*SCREEN_HEIGHT + SCREEN_WIDTH*SCREEN_WIDTH};
static constexpr int32_t SCREEN_MAXDIST{ct_sqrt(SCREEN_MAXDISTSQUARED)};

// Conversion distance size
static constexpr int32_t MIN_OBJECTSIZE{100};
static constexpr float_t OBJECT_SIZE_BETA{static_cast<float_t>(SCREEN_HEIGHT)};
static constexpr float_t OBJECT_SIZE_ALPHA{static_cast<float_t>(MIN_OBJECTSIZE - OBJECT_SIZE_BETA) / static_cast<float_t>(SCREEN_MAXDIST)};

// Physical units
static constexpr float_t BEV_CELL_TO_METERS{4.F};

// Player attribute
// Should be an even number for rendering purpose
static constexpr int32_t CURSOR_SIZE{8};

// View definition
// Objects are 2m high
// The distance of top row pixels is (WALL_HEIGHT - HEIGHT_OBSERVER) / tan(VERTICAL_FOV/2)
static constexpr float_t HORIZONTAL_FOV{90.F}; // degree
static constexpr float_t HORIZONTAL_INCREMENT{HORIZONTAL_FOV / static_cast<float_t>(SCREEN_WIDTH)}; // degree
static constexpr float_t HORIZONTAL_DELTA{ HORIZONTAL_INCREMENT /3.F }; // degree
static constexpr float_t HALF_HORIZONTAL_FOV_RAD{(HORIZONTAL_FOV/2)*static_cast<float_t>(SDL_PI_F)/180.F}; // degree
static constexpr float_t VERTICAL_FOV{60.F}; // degree
static constexpr float_t HEIGHT_OBSERVER{1.5F}; // meter
static constexpr float_t WALL_HEIGHT{2.F}; // meter
// The wall is the location of the scene projection
static constexpr float_t DIST_PROJPLAN_PLAYER{.5F}; // meter

// static constexpr float_t HORIZONTAL_RES{HORIZONTAL_FOV/SCREEN_WIDTH}; // degree per pixel
static constexpr float_t HORIZONTAL_RES{HORIZONTAL_FOV/SCREEN_WIDTH}; // degree per pixel
static constexpr float_t VERTICAL_RES{VERTICAL_FOV/SCREEN_HEIGHT}; // degree per pixel

// FUnctions cannot be used in constexpr hence variable compute in init
static float_t VERTICAL_SIZE_PROJPLAN{0.F}; // degree
static float_t VERTICAL_INCREMENT{0.F}; // meter

struct CApplication
{
   	SDL_Renderer *renderer_fp;
   	SDL_Renderer *renderer_bev;
	SDL_Window *window_fp;
	SDL_Window *window_bev;
	SDL_Texture *texture_fp;
	SDL_Texture *texture_bev;
	uint32_t pixels_fp[SCREEN_WIDTH*SCREEN_HEIGHT];
	uint32_t pixels_bev[SCREEN_WIDTH*SCREEN_HEIGHT];
	StatePlayer player;
};

inline float_t degToRad(const float_t angleDeg)
{
	return angleDeg*SDL_PI_F/180.F;
}

inline float_t radToDeg(const float_t angleRad)
{
	return angleRad*180.F/SDL_PI_F;
}


#endif /* FSP_TYPES_HPP */