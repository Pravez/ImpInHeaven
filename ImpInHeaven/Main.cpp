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
#include "utils.h"
#include "Scene.h"

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

	SetUpProgram();

	Screen * screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT);
	Scene* scene = new Scene();
	screen->getMap()->setImp(scene->addPlayer(new Imp(Vector2(7, 7), Vector2(IMP_WIDTH, IMP_HEIGHT), screen->getImpSprite())));


	// Draws the image on the screen:
	SDL_Rect rcDest = { 20, 20, 10, 10 };
    SDL_Event event;
    bool end = false;
	int color = 255;
    //SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, color, 0));
	
    Map m(20, 20);

    if (screen->getWindow()) {
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
								screen->getMap()->moveUp();
								break;
							case SDLK_DOWN:
								screen->getMap()->moveDown();
								break;
							case SDLK_RIGHT:
								screen->getMap()->moveRight();
								break;
							case SDLK_LEFT:
								screen->getMap()->moveLeft();
								break;
							case SDLK_a:
								color = color == 255 ? 0 : 255;
                            default:break;
                        }
                        break;

                    default:
                        break;
                }
				if (screen->getImp()->isDead())
				{
					end = true;
				}

            }
			screen->drawGrid();
			scene->draw(screen);

			screen->update();
        }

        SDL_DestroyWindow(screen->getWindow());
    }

	delete(screen);
    SDL_Quit();

    return 0;
}