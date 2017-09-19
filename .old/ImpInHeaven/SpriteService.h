#pragma once

#include <SDL.h>
#include <map>

class SpriteService
{
private:
	static std::map<std::string, SDL_Texture*> sprites;

public:
	static SDL_Texture* addSprite(std::string path, std::string name, SDL_Renderer* renderer);
	static SDL_Texture* getSprite(std::string name);
};