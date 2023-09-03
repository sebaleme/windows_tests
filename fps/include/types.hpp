/* *****************************************************************************
##
# @file        types.hpp
# @brief       Type definition used in the FPS programm
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_TYPES_HPP
#define FSP_TYPES_HPP

#include <SDL3/SDL.h>

static constexpr int32_t SCREEN_WIDTH{1280};
static constexpr int32_t SCREEN_HEIGHT{720};

struct CApplication
{
   	SDL_Renderer *renderer;
	SDL_Window *window; 
};


#endif /* FSP_TYPES_HPP */