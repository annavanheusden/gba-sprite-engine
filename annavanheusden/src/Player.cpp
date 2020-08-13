//
// Created by 32474 on 13/08/2020.
//

#include "Player.h"
#include <cmath>
#include <libgba-sprite-engine/gba/tonc_memdef.h>


void Player::tick(u16 keys){
    //RECHTS
    if(keys & KEY_RIGHT){
        if(!right){
            right = true;
            walkingSprite->flipHorizontally(true);
            walkingSprite->moveTo(walkingSprite->getX() + 1 ,walkingSprite->getY());
        }
    }
    else{ right = false ;}
    //LINKS
    if(keys & KEY_LEFT){
        if(!left){
            left = true;
            walkingSprite->moveTo(walkingSprite->getX() - 1 ,walkingSprite->getY());
        }
    }
    else { left = false; }

    //BOVEN
    if(keys & KEY_UP){
        if(!up){
            up = true;
            walkingSprite->moveTo(walkingSprite->getX(), walkingSprite->getY()+ 1 );
        }
    }
    else{ up = false;}

    //ONDER
    if(keys & KEY_DOWN){
        if(!down){
            down = true;
            walkingSprite->moveTo(walkingSprite->getX() ,walkingSprite->getY() - 1);
        }
    }
    else { down = false; }
}