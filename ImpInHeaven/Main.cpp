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
#include "World.h"
#include "EntityFactory.h"

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
	//Scene* scene = new Scene();
	Map* map = new Map(GRID_WIDTH, GRID_HEIGHT);
	Camera* camera = new Camera(FIXED_MODE, 1, map->getWidth(), map->getHeight());
	/*Imp* imp = new Imp(Vector2<int>(7, 7), Vector2<int>(IMP_WIDTH, IMP_HEIGHT), SpriteService::getSprite("imp"));
	Bird* bird = new Bird(Vector2<int>(9, 9), Vector2<int>(BIRD_WIDTH, BIRD_HEIGHT), SpriteService::getSprite("bird"));*/

	World* world = new World();
	GameElement* imp = EntityFactory::createPlayerEntity(screen, SpriteService::getSprite("imp"), Vector2<int>(0, 0));
	world->setMap(map);
	world->addElement(imp);;

	/*screen->getMap()->setImp(scene->addPlayer(imp));
	screen->getMap()->addMonster(scene->addMonster(bird));*/
	screen->setCamera(camera);
	screen->setMap(map);
	camera->setTrackingOn(imp);
		

    SDL_Event event;
    bool end = false;
	
    if (screen->getWindow()) {
        while (!end) {
            while (SDL_PollEvent(&event)) {
				world->handleEvent(&event);
				if (imp->getState() == DEAD)
				{
					end = true;
				}

            }
			//screen->getMap()->updateMonsters();
			screen->drawGrid();
			world->update();
			camera->update();

			screen->render();
        }

        SDL_DestroyWindow(screen->getWindow());
    }

	delete(screen);
    SDL_Quit();

    return 0;
}
