//
// Created by 32474 on 11/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOARD_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_BOARD_SCENE_H


#include <libgba-sprite-engine/scene.h>

class Board_scene: public Scene {
private:

public:
    Board_scene(std::shared_ptr<GBAEngine> engine): Scene(engine){}

    //implemented methods Scene
    std::vector<Sprite *> sprites() override;
    std:: vector<Background *> backgrounds() override;
    void load() override; //one-time scene loading (create objects) (+ forgroundPalette & backgroundPalette)
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOARD_SCENE_H
