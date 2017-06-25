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

int main(int argc, char **argv) {
	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);
	//printf("DEBUG : Npath : %s", NPath);

	CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));// | SDL_INIT_AUDIO));
	//SDL_SetVideoMode(largeur, hauteur, nombre de couleurs, options);

	Screen * screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT);
	screen->get_map()->add_imp(7,7);


	// Draws the image on the screen:
	SDL_Rect rcDest = { 20, 20, 10, 10 };
    SDL_Event event;
    bool end = false;
	int color = 255;
    //SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, color, 0));
	
    Map m(20, 20);

    if (screen->get_window()) {
        while (!end) {
            while (SDL_PollEvent(&event)) {
                /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
                switch (event.type) {
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                                end = true;
                                break;
							case SDLK_UP:
								screen->get_imp()->moveUp();
								break;
							case SDLK_DOWN:
								screen->get_imp()->moveDown();
								break;
							case SDLK_RIGHT:
								screen->get_imp()->moveRight();
								break;
							case SDLK_LEFT:
								screen->get_imp()->moveLeft();
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
			screen->display_grid();
        }

        SDL_DestroyWindow(screen->get_window());
    }

	free(screen);
    SDL_Quit();

    return 0;
}