//
// Created by 32474 on 11/08/2020.
//

#include "Board_scene.h"
#include "view/board/board_tiles_pal.c"
#include "view/player/Mario.c"
#include "Player.h"

#include <libgba-sprite-engine/gba_engine.h>


std::vector<Background *> Board_scene::backgrounds() {
    return {background.get()};
}
std::vector<Sprite *> Board_scene::sprites() {
   return {player.get()};
}

void Board_scene:: load(){
    background = std::unique_ptr<Background>(new Background(0, board_tiles_palTiles, sizeof(board_tiles_palTiles), board_map, sizeof(board_map), 20, 0, MAPLAYOUT_32X32));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(
            reinterpret_cast<const COLOR *>(board_tiles_palPal), sizeof(board_tiles_palPal)));
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(MarioPal, sizeof(MarioPal)));

   /*mario = std::unique_ptr<Player>(new Player(affineBuilder.withData(MarioTiles, sizeof(MarioTiles))
            .withSize(SIZE_32_32)
            .withLocation(10, 10)
            .buildPtr()));
*/
   player = spriteBuilder
           .withData(MarioTiles, sizeof(MarioTiles))
           .withLocation(10, 10)
           .withSize(SIZE_32_32)
           .buildPtr();

   //mario = std::unique_ptr<Player>(new Player(player*));
}

void Board_scene:: tick(u16 keys){
   movePlayer(keys);
}

void Board_scene::movePlayer(u16 keys) {
    bool right, left, up, down, go;
    player->setStayWithinBounds(true);

    //RECHTS
    if(keys & KEY_RIGHT){
        int playerX = player->getX() + 1;
        int playerY = player->getY();
        go = checkBoundaries(playerX, playerY);
        if(!right & go){
            right = true;
            player->flipHorizontally(true);
            player->makeAnimated(2, 10);
            player->moveTo(player->getX() + 1 ,player->getY());
        }
    }
    else{ right = false ;}
    //LINKS
    if(keys & KEY_LEFT){
        int playerX = player->getX() - 1;
        int playerY = player->getY();
        go = checkBoundaries(playerX, playerY);
        if(!left & go){
            left = true;
            player->flipHorizontally(false);
            player->makeAnimated(2, 10);
            player->moveTo(player->getX() - 1 ,player->getY());
        }
    }
    else { left = false; }

    //BOVEN
    if(keys & KEY_UP){
        int playerX = player->getX();
        int playerY = player->getY() - 1;
        go = checkBoundaries(playerX, playerY);
        if(!up & go){
            up = true;
            player->makeAnimated(2, 10);
            player->moveTo(player->getX(), player->getY()- 1 );
        }
    }
    else{ up = false;}

    //ONDER
    if(keys & KEY_DOWN){
        int playerX = player->getX();
        int playerY = player->getY() +1;
        go = checkBoundaries(playerX, playerY);

        if(!down & go){
            down = true;
            player->makeAnimated(2, 10);
            player->moveTo(player->getX() ,player->getY() + 1);
        }
    }
    else { down = false; }
}

bool Board_scene::checkBoundaries(int xPlayer, int yPlayer) {
    int positieBord = getPosition(xPlayer, yPlayer);
    bool go = false;
    switch(positieBord) {
        case 0: //buiten het spel, doe niks
            go = false;
            break;
        case 1: //op de tegels
            go = true;
            break;
        case 2: //in een tunnel
            go = true;
            // NAAR MINIGAME
            break;
    }
    return go;
}
int Board_scene::getPosition(int xPos, int yPos) {
    int spelbord[31][31];
    //0 = buiten het bord
    //1 = op het bord
    //2 = tunnel naar minigame
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            spelbord[i][j] = 0; //alles op 0 zetten
        }
    }
    //rij 0
    for (int i = 5; i < 27; i++) {
        spelbord[i][0] = 1;
    };
    //rij 1
    for (int i = 0; i < 4; i++) {
        spelbord[i][1] = 2;
    };
    for (int i = 5; i < 27; i++) {
        spelbord[i][1] = 1;
    };
    //rij 2
    for (int i = 0; i < 4; i++) {
        spelbord[i][2] = 2;
    };
    for (int i = 5; i < 27; i++) {
        spelbord[i][2] = 1;
    };
    //rij 3
    for (int i = 0; i < 4; i++) {
        spelbord[i][3] = 2;
    };
    for (int i = 5; i < 27; i++) {
        spelbord[i][3] = 1;
    };
    for (int i = 28; i < 32 ; i++) {
        spelbord[i][3] = 2;
    }
    //rij 4
    for (int i = 0; i < 4; i++) {
        spelbord[i][4] = 2;
    };
    for (int i = 5; i < 8; i++) {
        spelbord[i][4] = 1;
    };
    for (int i = 24; i < 27; i++) {
        spelbord[i][4] = 1;
    };
    for (int i = 28; i < 32 ; i++) {
        spelbord[i][4] = 2;
    }
    //rij5
    for (int i = 0; i < 8; i++) {
        spelbord[i][5] = 1;
    };
    for (int i = 24; i < 27; i++) {
        spelbord[i][5] = 1;
    };
    for (int i = 28; i < 32 ; i++) {
        spelbord[i][5] = 2;
    }
    //rij 6 en 7
    for (int i = 0; i < 32; i++) {
        for(int j = 6; j<8; j++) {
            spelbord[i][j] = 1;
        }
    }
    //rij 8
    for (int i = 9; i < 32 ; i++) {
        spelbord[i][8] = 1;
    }
    //rij 9
    for (int i = 9; i < 12 ; i++) {
        spelbord[i][9] = 1;
    }
    for (int i = 14; i < 17 ; i++) {
        spelbord[i][9] = 1;
    }
    for (int i = 26; i < 29 ; i++) {
        spelbord[i][9] = 1;
    }
    //rij10 en 11
    for(int j = 10; j<12; j++) {
        for (int i = 5; i < 12; i++) {
            spelbord[i][j] = 1;
        }
        for (int i = 14; i < 17; i++) {
            spelbord[i][j] = 1;
        }
        for (int i = 26; i < 29; i++) {
            spelbord[i][j] = 1;
        }
    }
    //rij 12
    for (int i = 0; i < 4; i++) {
        spelbord[i][12] = 2;
    }
    for (int i = 5; i < 12; i++) {
        spelbord[i][12] = 1;
    }
    for (int i = 14; i < 17; i++) {
        spelbord[i][12] = 1;
    }
    for (int i = 26; i < 29; i++) {
        spelbord[i][12] = 1;
    }
    //rij 13 14 15
    for(int j = 13; j<16; j++) {
        for (int i = 0; i < 4; i++) {
            spelbord[i][j] = 2;
        }
        for (int i = 5; i < 8; i++) {
            spelbord[i][j] = 1;
        }
        for (int i = 14; i < 17; i++) {
            spelbord[i][j] = 1;
        }
        for (int i = 20; i < 24; i++) {
            spelbord[i][j] = 2;
        }
        for (int i = 26; i < 29; i++) {
            spelbord[i][j] = 1;
        }
    }

        //rij 16
        for (int i = 0; i < 4; i++) {
            spelbord[i][16] = 2;
        }
        for (int i = 5; i < 8; i++) {
            spelbord[i][16] = 1;
        }
        for (int i = 9; i < 13; i++) {
            spelbord[i][16] = 2;
        }
        for (int i = 14; i < 17; i++) {
            spelbord[i][16] = 1;
        }
        for (int i = 20; i < 24; i++) {
            spelbord[i][16] = 2;
        }
        for (int i = 26; i < 29; i++) {
            spelbord[i][16] = 1;
        }
        //rij 17 18
        for(int j = 17; j<19; j++) {
            for (int i = 0; i < 4; i++) {
                spelbord[i][j] = 2;
            }
            for (int i = 5; i < 8; i++) {
                spelbord[i][j] = 1;
            }
            for (int i = 9; i < 13; i++) {
                spelbord[i][j] = 2;
            }
            for (int i = 14; i < 29; i++) {
                spelbord[i][j] = 1;
            }
        }
        //rij 19
        for (int i = 0; i < 13; i++) {
            spelbord[i][19] = 1;
        }
        for (int i = 14; i < 29; i++) {
            spelbord[i][19] = 1;
        }

        return spelbord[xPos][yPos];
    }

