//
// Created by 32474 on 13/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
#define GBA_SPRITE_ENGINE_PROJECT_PLAYER_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include "../../../../../../../../../../../../Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/unique_ptr.h"

class Player {
private:
    std::unique_ptr<AffineSprite> walkingSprite;
    bool left, right, up, down;
public:
    ///constructor
    Player(std::unique_ptr<Sprite> sprite);

    Sprite* getWalkingSprite(){return walkingSprite.get();}
    bool isLeft(){return left;}
    bool isRight(){return right;}
    bool isUp(){return up;}
    bool isDown(){return down;}

    void tick(u16 keys);

};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
