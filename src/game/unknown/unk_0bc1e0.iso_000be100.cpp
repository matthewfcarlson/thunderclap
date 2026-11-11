// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000bc1e0..0x000be1c0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x000be100 FUN_000be100 (156 B): matches/0x000be100.cpp [isolated: conflict: FUN_000fc3d0; on include/gen/ and not mergeable]
// sym: ?FUN_000be100@Menu_be100@owners@@QAEXXZ
// FUN_000be100 @ 0x000be100
#include "decls/data/game/unknown.h"
#include "gen/owners.h"

class Player_be100 {
  public:
    char pad[0x9a8];
    char busy;
};
class Game_be100 {
  public:
    char pad[0x2218];
    Player_be100* player;
    int mode;
};
class Singleton;
Game_be100* __cdecl FUN_000fc3d0();
extern "C" Singleton* __cdecl FUN_001d4c90();


void owners::Menu_be100::FUN_000be100() {
    if (state != 0x17)
        return;
    Player_be100* p = FUN_000fc3d0()->player;
    if (p != 0 && p->busy != 0)
        return;
    state = 0;
    if (FUN_000fc3d0()->mode == 1 && pending >= 0x266 && pending <= 0x2c9 && FUN_001d4c90() != 0) {
        index = pending - 0x265;
        int difficulty = DAT_0049cab4;
        if (difficulty < 0 || difficulty >= 3)
            difficulty = 1;
        FUN_000bc5c0("oneshot", "c00m10", difficulty, 1);
    }
    pending = -1;
}

