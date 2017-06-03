#include "screen/Screen.hpp"

SDL_Surface *pSurface;

#define SIZE_X 50
#define SIZE_Y 50
#define TILE_WIDTH 4
#define TILE_HEIGHT 4

void draw(){
    for(int i = 0;i < SIZE_X;i++){
        for(int j = 0;j < SIZE_Y;j++){
            SDL_Rect rect;
        }
    }
}

extern int main(int argc, char **argv) {
    Screen screen;

    CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));


    SDL_Window *sdlWindow = NULL;
    sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                 SDL_WINDOW_SHOWN);

    pSurface = NULL;
    pSurface = SDL_GetWindowSurface(sdlWindow);
    SDL_Event event;
    bool end = false;

    if (sdlWindow) {
        while (!end) {
            while (SDL_PollEvent(&event)) {
                /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
                switch (event.type) {
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                                end = true;
                                break;
                            default:break;
                        }
                        break;

                    default:
                        break;
                }

            }

            SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, 255, 0));
            SDL_UpdateWindowSurface(sdlWindow);
        }

        SDL_DestroyWindow(sdlWindow);
    }


    SDL_Quit();

    return EXIT_SUCCESS;
}