//
// Created by 32474 on 11/08/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include "Titlescreen_scene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    Titlescreen_scene* startScene  = new Titlescreen_scene(engine);
    engine->setScene(startScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}