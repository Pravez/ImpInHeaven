#include "screen/Screen.hpp"
#include "graphics/Map.hpp"
#include <SDL_image.h>

//#ifdef WIN32 || _WIN32
#include <SDL.h>
//#else
//#include <SDL2/SDL.h>
//#endif


int main(int argc, char **argv) {
    Screen screen;

    CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));


    SDL_Window *sdlWindow = NULL;
    sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                 SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 190, 40, 156, 255);
    SDL_RenderClear(renderer);


	/*SDL_Surface *image = IMG_Load("resources/images/fox.jpg");
	if (!image)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		return 1;
	}*/

	// Draws the image on the screen:
	SDL_Rect rcDest = { 20, 20, 10, 10 };

    SDL_Surface *pSurface = NULL;
    pSurface = SDL_GetWindowSurface(sdlWindow);
    SDL_Event event;
    SDL_Rect pos;
    SDL_Rect mini;
    bool end = false;
	int color = 255;
    //SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, color, 0));

    int width, height;
    SDL_Texture *img = IMG_LoadTexture(renderer, "resources/images/tile.png");
    SDL_QueryTexture(img, NULL, NULL, &width, &height);

    Map m(20, 20);

    mini.h = 4;
    mini.w = 4;

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


            SDL_RenderClear(renderer);
            for(int i = 0;i < 2;++i){
                for(int j = 0;j <2;++j){
                    pos.x = (i - j) * (width/2)+200;
                    pos.y = (i + j) * (height/2)+200;
                    pos.w = width/2;
                    pos.h = height/2;
                    mini.x = (i-j)*(width/2)+200;
                    mini.y = (i+j)*(height/2)+200;

                    //Y'a 2 méthodes pour faire afficher, le RenderCopy (avec un renderer)
                    //et le FillRect (avec le updateWindowSurface), et j'ai l'impression que les deux
                    //ne peuvent pas cohabiter ...
                    SDL_RenderCopy(renderer, img, NULL, &pos);
                    SDL_FillRect(pSurface, &mini, SDL_MapRGB(pSurface->format, 255, 255, 0));
                }
            }
            

            SDL_RenderPresent(renderer);
            //SDL_UpdateWindowSurface(sdlWindow);
        }

        SDL_DestroyWindow(sdlWindow);
    }


    SDL_Quit();

    return 0;
}