/* *****************************************************************************
##
# @file        main.cpp
# @brief       main method for the FPS game. This app implements basic games functionalities
# @copyright   MIT license
# ****************************************************************************/
#include "init.hpp"
#include "input.hpp"
#include "types.hpp"
#include <iostream>


int main()
{
    std::cout << "Hello world" << std::endl;

    std::unique_ptr<CApplication> app{std::make_unique<CApplication>()};
    initSDL(*app.get());

    app->texture = SDL_CreateTexture(app->renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING,SCREEN_WIDTH, SCREEN_HEIGHT);

    while(1)
    {
        // Without this, the programm stalls when we interract with the window
        doInput();
        int32_t i{50};
        while(i<SCREEN_WIDTH*SCREEN_HEIGHT)
        {
            app->pixels[i] = 0xFFFF00FF;
            i += SCREEN_WIDTH;
        }

        SDL_UpdateTexture(app->texture,NULL,app->pixels,SCREEN_WIDTH*4);
        SDL_RenderTextureRotated(app->renderer,app->texture,NULL,NULL,0.0,NULL,SDL_FLIP_VERTICAL);
    }

    return 0;
}