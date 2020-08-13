//
// Created by 32474 on 11/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOARD_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_BOARD_SCENE_H


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include "../../engine/include/libgba-sprite-engine/gba_engine.h"
#include "../../engine/include/libgba-sprite-engine/sprites/sprite.h"
#include "../../engine/include/libgba-sprite-engine/background/background.h"
#include "../../engine/include/libgba-sprite-engine/gba/tonc_types.h"
#include "Player.h"

class Board_scene: public Scene {
private:
    std::unique_ptr<Background> background;
    std::unique_ptr<Player> mario;
    std::unique_ptr<Sprite> player;
    SpriteBuilder<Sprite> spriteBuilder;
public:
    Board_scene(std::shared_ptr<GBAEngine> engine): Scene(engine){}

    //implemented methods Scene
    std::vector<Sprite *> sprites() override;
    std:: vector<Background *> backgrounds() override;
    void load() override; //one-time scene loading (create objects) (+ forgroundPalette & backgroundPalette)
    void tick(u16 keys) override;
    void movePlayer(u16 keys);
    bool checkBoundaries(int xPos, int yPos);
    int getPosition(int xPos, int yPos);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOARD_SCENE_H
