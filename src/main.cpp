#include <entityx/entityx.h>
#include "components/position.hpp"

using namespace entityx;

int main(int argc, char**argv) {

    EntityX ex;
    Entity entity = ex.entities.create();

    //Assign component
    entity.assign<FPosition>(1.0f, 2.0f);

    //Retrieve component
    ComponentHandle<FPosition> position = entity.component<FPosition>();
    printf("%f, %f\n", position.get()->x, position.get()->y);

    return EXIT_SUCCESS;
}