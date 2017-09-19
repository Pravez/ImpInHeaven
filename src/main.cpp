#include <entityx/entityx.h>
#include "components/position.hpp"
#include "logic/Level.hpp"
#include <SFML/Graphics.hpp>

using namespace entityx;

int main(int argc, char**argv) {

    EntityX ex;
    Entity entity = ex.entities.create();

    //Assign component
    entity.assign<FPosition>(1.0f, 2.0f);

    //Retrieve component
    ComponentHandle<FPosition> position = entity.component<FPosition>();
    printf("%f, %f\n", position.get()->x, position.get()->y);


    /*sf::Window App(sf::VideoMode(800, 600), "ImpInHeaven");

    while (App.isOpen()) {
        sf::Event event;
        while(App.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                App.close();
        }
        App.display();
    }*/

    Level level;

    while(true) {
        level.update(0.1);
    }

    return EXIT_SUCCESS;
}