//
// Created by 32474 on 11/08/2020.
//

#include "Board_scene.h"
std::vector<Background *> Board_scene::backgrounds() {
    //return {background.get()};
}
std::vector<Sprite *> Board_scene::sprites() {
    return {};
}

void Board_scene:: load(){
  /*  background = std::unique_ptr<Background>(new Background(0, titlescreenTiles, sizeof(titlescreenTiles), titlescreenMap, sizeof(titlescreenMap)));
    background->useMapScreenBlock(0);
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(titlescreenPal, sizeof(titlescreenPal)));
    */
}

void Board_scene:: tick(u16 keys){
    /*if(keys){
        auto board_scene = new Board_scene(engine);
        engine->transitionIntoScene(board_scene, new FadeOutScene(2));
    }
     */
}
