// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00329430..0x0032b0a0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dSimpleShader
// (tree_prelude.h: not needed)


// 0x00329da0 FUN_00329da0 (91 B): matches/0x00329da0.cpp [isolated: conflict: DAT_0039db08; on include/gen/ and not mergeable]
// sym: ?FUN_00329da0@C_329da0@owners@@QAEXHHH@Z
#include "gen/owners.h"
// The D3D texture-stage state words (the original's 0x0039db50 + 0x80 * stage, four stages): these definitions are
// this object's own copies, so they hold every stage the function writes ([stage * 32]). At [32] the stage 1..3 writes
// ran past them into the next globals of the port builds (wmenu1: on wasm, the tree's globals section, where they
// overwrote the options menu's handler vftable and the app crashed when a setting changed in the pause menu).
extern int DAT_0039db08;
extern int DAT_0039db50[4 * 32];
extern int DAT_0039db58[4 * 32];
int DAT_0039db08;
int DAT_0039db50[4 * 32];
int DAT_0039db58[4 * 32];
void owners::C_329da0::FUN_00329da0(int i, int x, int y) {
    if (a[i] != x) {
        a[i] = x;
        DAT_0039db08 |= 0x800;
        DAT_0039db50[i * 32] = x;
    }
    if (b[i] != y) {
        b[i] = y;
        DAT_0039db08 |= 0x800;
        DAT_0039db58[i * 32] = y;
    }
}

