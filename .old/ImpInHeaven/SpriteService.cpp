#include "SpriteService.h"
#include "utils.h"
#include <SDL_image.h>

std::map<std::string, SDL_Texture*> SpriteService::sprites;

SDL_Texture* SpriteService::addSprite(std::string rel_path, std::string name, SDL_Renderer* renderer)
{
	rel_path = std::string(WORKINGDIR_PATH) + rel_path;
	auto sprite = IMG_LoadTexture(renderer, rel_path.c_str());
	if (sprite == nullptr) {
		printf("Unable to load image %s! SDL_image Error: %s\n", rel_path.c_str(), IMG_GetError());
	}
	sprites.insert(std::pair<std::string, SDL_Texture*>(name, sprite));
	return sprite;
}

SDL_Texture* SpriteService::getSprite(std::string name)
{
	return sprites.at(name);
}
