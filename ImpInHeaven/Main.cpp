#include "Screen.hpp"
#include "Map.hpp"
#include <string>
#include <windows.h>
#include <iostream>
#include <SDL_image.h>

#ifdef WIN32
#include <SDL.h>
#else
#include <SDL.h>
#endif

#include <Windows.h>
#include <iostream>
#include <sstream>

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define GRID_WIDTH 4
#define GRID_HEIGHT 4

int main(int argc, char **argv) {
    //Screen screen;
	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);
	//printf("DEBUG : Npath : %s", NPath);

	CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));// | SDL_INIT_AUDIO));
	//SDL_SetVideoMode(largeur, hauteur, nombre de couleurs, options);

    SDL_Window *sdlWindow = NULL;
    sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,
                                 SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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
	std::string path = "C:/Users/utilisateur1/Desktop/ImpInHeaven/ImpInHeaven/ImpInHeaven/images/tile.bmp";
    SDL_Texture *img = IMG_LoadTexture(renderer, path.c_str());
	if (img == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		DBOUT("Wrong path : " << IMG_GetError());
	}
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
			width = 100;
			height = 100;
			int x_mid = WINDOW_WIDTH / 2;
			int y_mid = WINDOW_HEIGHT / 2;

            SDL_RenderClear(renderer);
            for(int i = 0;i < GRID_WIDTH;++i){
                for(int j = 0;j <GRID_HEIGHT;++j){

					if (i <= GRID_WIDTH / 2) {
						pos.x = x_mid - ((GRID_WIDTH / 2) - i) * width;
						if (GRID_WIDTH % 2 == 1) {
							pos.x -= width / 2;
						}
					}
					else {
						pos.x = x_mid + (i - (GRID_WIDTH / 2)) * width;
						if (GRID_WIDTH % 2 == 1) {
							pos.x -= width / 2;
						}
					}

					if (j <= GRID_HEIGHT / 2) {
						pos.y = y_mid - ((GRID_HEIGHT / 2) - j) * height;
						if (GRID_HEIGHT% 2 == 1) {
							pos.y -= height / 2;
						}
					}
					else {
						pos.y = y_mid + (j - (GRID_HEIGHT / 2)) * height;
						if (GRID_HEIGHT % 2 == 1) {
							pos.y -= height / 2;
						}

					}
					//pos.x = (i - j) * (width / 2); +200;
					//pos.y = (i + j) * (height / 2); +200;
					pos.w = width;// / 2;
					pos.h = height;// / 2;
					mini.x = pos.x;//(i-j)*(width/2)+200;
					mini.y = pos.y;// (i + j)*(height / 2) + 200;

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