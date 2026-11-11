// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00092120..0x000933a0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x000929a0 FUN_000929a0 (145 B): matches/0x000929a0.cpp [isolated: conflict: Cast; on include/gen/ and not mergeable]
// sym: ?FUN_000929a0@Owner_929a0@owners@@QAEXHD@Z
#include "gen/owners.h"
extern "C" void* __cdecl Cast(void*, int, const void*, const void*, int);
struct Gallery {
    char pad[0xb0];
    char value;
};
struct Move_929a0 {
    char pad[0x2d];
    char value;
};
struct File {
    char pad[0xa8];
    char value;
};
extern int typeUnlockable;
extern int typeGallery;
extern int typeMove;
extern int typeFile;
void owners::Owner_929a0::FUN_000929a0(int index, char value) {
    Gallery* a = (Gallery*)Cast(items[index], 0, &typeUnlockable, &typeGallery, 0);
    if (a && a->value != value)
        a->value = value;
    Move_929a0* b = (Move_929a0*)Cast(items[index], 0, &typeUnlockable, &typeMove, 0);
    if (b && b->value != value)
        b->value = value;
    File* c = (File*)Cast(items[index], 0, &typeUnlockable, &typeFile, 0);
    if (c && c->value != value)
        c->value = value;
}

