#include "screen/Screen.hpp"

extern int main(int argc, char **argv) {
    Screen screen;

    CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));



    SDL_Window *sdlWindow = NULL;
    sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                 SDL_WINDOW_SHOWN);

    if(sdlWindow) {
        SDL_Delay(5000);
        SDL_DestroyWindow(sdlWindow);
    }


    SDL_Quit();

    return 0;
}