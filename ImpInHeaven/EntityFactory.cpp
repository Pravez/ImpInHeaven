#include "EntityFactory.h"
#include "KeyboardEventComponent.h"
#include "TimeComponent.h"
#include "AutonomousBehaviorComponent.h"

GameEntity* EntityFactory::createPlayerEntity(Screen* screen, SDL_Texture* texture, Vector2<int> position)
{
	GameEntity* entity = new GameEntity(position);
	entity->addAccessorComponent(new GraphicalComponent(texture, screen))->setGameElement(entity);
	entity->addModifierComponent(new MovementComponent())->setGameElement(entity);
	entity->setEventListener(new KeyboardEventComponent())->setGameElement(entity);
	entity->getListenerBoolean() = true;

	entity->setDirection(SOUTH);

	return entity;
}

GameEntity* EntityFactory::createIAEntity(Screen* screen, SDL_Texture* texture, Vector2<int> position)
{
	GameEntity* entity = new GameEntity(position);
	entity->addAccessorComponent(new GraphicalComponent(texture, screen))->setGameElement(entity);
	entity->addModifierComponent(new TimeComponent(std::chrono::seconds(1)))->setGameElement(entity);
	entity->addModifierComponent(new AutonomousBehaviorComponent())->setGameElement(entity);
	entity->addModifierComponent(new MovementComponent())->setGameElement(entity);

	entity->setDirection(SOUTH);

	return entity;
}
