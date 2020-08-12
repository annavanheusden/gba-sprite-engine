
//{{BLOCK(titlescreen)

//======================================================================
//
//	titlescreen, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 309 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 19776 + 2048 = 22336
//
//	Time-stamp: 2020-08-12, 12:31:01
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TITLESCREEN_H
#define GRIT_TITLESCREEN_H

#define titlescreenTilesLen 19776
extern const unsigned int titlescreenTiles[4944];

#define titlescreenMapLen 2048
extern const unsigned int titlescreenMap[512];

#define titlescreenPalLen 512
extern const unsigned int titlescreenPal[128];

#endif // GRIT_TITLESCREEN_H

//}}BLOCK(titlescreen)
