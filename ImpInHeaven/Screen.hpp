#ifndef IMPINHEAVEN_SCREEN_HPP
#define IMPINHEAVEN_SCREEN_HPP

#include <SDL.h>
#include <cstdio>

#define CHECK_INIT_SDL(func) if(func != 0){ fprintf(stderr, "Failed to init (%s)\n", SDL_GetError()); return -1;}

class Screen {



};


#endif //IMPINHEAVEN_SCREEN_HPP
