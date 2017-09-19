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
#include <time.h> //TODO : remove when random will be not used anymore
#include "utils.h"
#include "Scene.h"
#include "SpriteService.h"

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char **argv) {
	CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));// | SDL_INIT_AUDIO));
	//SDL_SetVideoMode(largeur, hauteur, nombre de couleurs, options);
	srand(time(NULL));

	SetUpProgram();

	Screen * screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT);
	Scene* scene = new Scene();
	Camera* camera = new Camera(FIXED_MODE, 1, screen->getMap()->getWidth(), screen->getMap()->getHeight());
	Imp* imp = new Imp(Vector2(7, 7), Vector2(IMP_WIDTH, IMP_HEIGHT), SpriteService::getSprite("imp"));
	Bird* bird = new Bird(Vector2(9, 9), Vector2(BIRD_WIDTH, BIRD_HEIGHT), SpriteService::getSprite("bird"));

	screen->getMap()->setImp(scene->addPlayer(imp));
	screen->getMap()->addMonster(scene->addMonster(bird));
	screen->setCamera(camera);
	camera->setTrackingOn(imp);
		

    SDL_Event event;
    bool end = false;
	int color = 255;
	
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
			screen->getMap()->updateMonsters();
			camera->update();
			screen->drawGrid();
			scene->draw(screen);

			screen->render();
        }

        SDL_DestroyWindow(screen->getWindow());
    }

	delete(screen);
    SDL_Quit();

    return 0;
}