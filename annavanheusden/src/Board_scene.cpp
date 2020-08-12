//
// Created by 32474 on 11/08/2020.
//

#include "Board_scene.h"
#include "view/board/board_tiles_pal.c"

#include <libgba-sprite-engine/gba_engine.h>


std::vector<Background *> Board_scene::backgrounds() {
    return {background.get()};
}
std::vector<Sprite *> Board_scene::sprites() {
    return {};
}

void Board_scene:: load(){
    background = std::unique_ptr<Background>(new Background(0, board_tiles_palTiles, sizeof(board_tiles_palTiles), board_map, sizeof(board_map), 20, 0, MAPLAYOUT_32X32));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(
            reinterpret_cast<const COLOR *>(board_tiles_palPal), sizeof(board_tiles_palPal)));
}

void Board_scene:: tick(u16 keys){
    /*if(keys){
        auto board_scene = new Board_scene(engine);
        engine->transitionIntoScene(board_scene, new FadeOutScene(2));
    }
     */
}
