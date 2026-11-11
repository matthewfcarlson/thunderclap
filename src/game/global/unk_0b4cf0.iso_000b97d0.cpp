// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b4cf0..0x000bba40 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x000b97d0 FUN_000b97d0 (91 B): matches/0x000b97d0.cpp [isolated: conflict: FUN_000fc3d0; on include/gen/ and not mergeable]
// sym: ?Target@State_b97d0@@QAEXXZ
#include "gen/global.h"
class Actor_b97d0 {
  public:
    void FnA_00089390();
};
class State_b97d0 {
  public:
    char pad0[0x10];
    int state;
    char pad14[0x20];
    Actor_b97d0* a;
    Actor_b97d0* b;
    void Target();
};
struct Manager_b97d0 {
    char pad[0x2218];
    void* item;
    int value;
};
struct Item_b97d0 {
    char pad[0x9a8];
    char busy;
};
extern Manager_b97d0* FUN_000fc3d0();
extern "C" void __cdecl FUN_000fc300();
void State_b97d0::Target() {
    if (state == 0x15) {
        Manager_b97d0* m = FUN_000fc3d0();
        if (m->item == 0 || !((Item_b97d0*)m->item)->busy) {
            state = 9;
            m = FUN_000fc3d0();
            if (m->value == 1 && state != 3) {
                a->FnA_00089390();
                if (b)
                    ((::CScenarioManager *)b)->FUN_001cc620(5);
                FUN_000fc300();
            }
        }
    }
}

