#include "EntityFactory.h"
#include "KeyboardEventComponent.h"

GameEntity* EntityFactory::createPlayerEntity(Screen* screen, SDL_Texture* texture, Vector2<int> position)
{
	GameEntity* entity = new GameEntity(position);
	entity->addAccessorComponent(new GraphicalComponent(texture, screen))->setGameElement(entity);
	entity->addModifierComponent(new MovementComponent())->setGameElement(entity);
	entity->setEventListener(new KeyboardEventComponent())->setGameElement(entity);

	return entity;
}
