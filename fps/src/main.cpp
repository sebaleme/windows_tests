/* *****************************************************************************
##
# @file        main.cpp
# @brief       main method for the FPS game. This app implements basic games functionalities
# @copyright   MIT license
# ****************************************************************************/
#include "init.hpp"
#include "input.hpp"
#include "player_rendering_bev.hpp"
#include "map_rendering_bev.hpp"
#include "map_rendering_fv.hpp"
#include "types.hpp"
#include <iostream>


int main()
{
    std::cout << "Hello world" << std::endl;

    std::unique_ptr<CApplication> app{std::make_unique<CApplication>()};
    initSDL(*app.get());

    app->texture_fp = SDL_CreateTexture(app->renderer_fp, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING,SCREEN_WIDTH, SCREEN_HEIGHT);
    app->texture_bev = SDL_CreateTexture(app->renderer_bev, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING,SCREEN_WIDTH, SCREEN_HEIGHT);

    while(1)
    {
        // Without this, the programm stalls when we interract with the window
        // Process player position according to keyboard inputs
        doInput(app->player);
        construct_map(app->pixels_bev);
        player_rendering_bev(app->pixels_bev, app->player);
        construct_world(app->pixels_fp, app->player);

        SDL_RenderClear(app->renderer_fp);
        SDL_RenderClear(app->renderer_bev);
        SDL_UpdateTexture(app->texture_fp,NULL,app->pixels_fp,SCREEN_WIDTH*4);
        SDL_UpdateTexture(app->texture_bev,NULL,app->pixels_bev,SCREEN_WIDTH*4);
        SDL_RenderTextureRotated(app->renderer_bev,app->texture_bev,NULL,NULL,0.0,NULL,SDL_FLIP_VERTICAL);
        SDL_RenderTextureRotated(app->renderer_fp,app->texture_fp,NULL,NULL,0.0,NULL,SDL_FLIP_VERTICAL);
        // SDL_SetRenderDrawColor(app->renderer, 0xFF, 0x00, 0xFF, 0xFF);
        SDL_RenderPresent(app->renderer_bev);
        SDL_RenderPresent(app->renderer_fp);
    }

    return 0;
}