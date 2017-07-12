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
#include <chrono>
#include "ChronoService.h"

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std::chrono_literals;
constexpr std::chrono::nanoseconds timestep(16ms); //1/60 = 16ms

int main(int argc, char **argv) {
	CHECK_INIT_SDL(SDL_Init(SDL_INIT_VIDEO));// | SDL_INIT_AUDIO));
	//SDL_SetVideoMode(largeur, hauteur, nombre de couleurs, options);
	srand(time(NULL));

	SetUpProgram();

	Screen * screen = new Screen(WINDOW_WIDTH, WINDOW_HEIGHT);
	Map* map = new Map(GRID_WIDTH, GRID_HEIGHT);
	Camera* camera = new Camera(FIXED_MODE, 1, map->getWidth(), map->getHeight());
	World* world = new World();
	GameElement* imp = EntityFactory::createPlayerEntity(screen, SpriteService::getSprite("imp"), Vector2<int>(0, 0));
	GameElement* enemy = EntityFactory::createIAEntity(screen, SpriteService::getSprite("imp"), Vector2<int>(0, 0));

	world->setMap(map);
	world->addElement(imp);
	world->addElement(enemy);
	screen->setCamera(camera);
	screen->setMap(map);
	camera->setTrackingOn(imp);
		
	using clock = std::chrono::high_resolution_clock;
	std::chrono::nanoseconds lag(0ns);
	auto time_start = clock::now();

    SDL_Event event;
    bool end = false;
	
    if (screen->getWindow()) {
        while (!end) {
			auto delta_time = clock::now() - time_start;
			time_start = clock::now();
			lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

            while (SDL_PollEvent(&event)) {
				world->handleEvent(&event);
				if (imp->getState() == DEAD)
				{
					end = true;
				}

            }

			while (lag >= timestep) {
				lag -= timestep;

				world->update(delta_time);
			}

			screen->drawGrid();
			world->render(delta_time);
			camera->update();
			screen->render();
			
        }

        SDL_DestroyWindow(screen->getWindow());
    }

	delete(screen);
    SDL_Quit();

    return 0;
}
