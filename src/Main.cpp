#include "screen/Screen.hpp"

extern int main(int argc, char **argv) {
    Screen screen;

    CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));


    SDL_Window *sdlWindow = NULL;
    sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                 SDL_WINDOW_SHOWN);

    SDL_Surface *pSurface = NULL;
    pSurface = SDL_GetWindowSurface(sdlWindow);
    SDL_Event event;
    bool end = false;
	int color = 255;
    SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, color, 0));

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
							case SDLK_a:
								color = color == 255 ? 0 : 255;
                            default:break;
                        }
                        break;

                    default:
                        break;
                }

            }
			SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, color, color));
            SDL_UpdateWindowSurface(sdlWindow);
        }

        SDL_DestroyWindow(sdlWindow);
    }


    SDL_Quit();

    return 0;
}