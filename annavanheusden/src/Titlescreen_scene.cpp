//
// Created by 32474 on 11/08/2020.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include "Titlescreen_scene.h"
#include "view/titlescreen/titlescreen.h"
#include "Board_scene.h"
#include <libgba-sprite-engine/gba_engine.h>
#include "../../engine/include/libgba-sprite-engine/palette/palette_manager.h"
#include "../../engine/include/libgba-sprite-engine/effects/fade_out_scene.h"
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/background/text_stream.h>

std::vector<Background *> Titlescreen_scene::backgrounds() {
    return {background.get()};
}
std::vector<Sprite *> Titlescreen_scene::sprites() {
    return {};
}

void Titlescreen_scene:: load(){
    background = std::unique_ptr<Background>(new Background(0, titlescreenTiles, sizeof(titlescreenTiles), titlescreenMap,
                                                            sizeof(titlescreenMap), 20, 0, MAPLAYOUT_32X32));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(
            reinterpret_cast<const COLOR *>(titlescreenPal), sizeof(titlescreenPal)));

}

void Titlescreen_scene:: tick(u16 keys){
    if(keys){
        auto board_scene = new Board_scene(engine);
        engine->transitionIntoScene(board_scene, new FadeOutScene(2));
    }
}