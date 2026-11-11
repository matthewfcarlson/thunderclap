// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023c2c0..0x0023c500 (kind game, layer engine, confidence high), dominant class fight::Reference
// (tree_prelude.h: not needed)


// 0x0023c2e0 FUN_0023c2e0 (25 B): matches/0x0023c2e0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?target@Reference_23c2e0@@QAEXXZ
// Same code shape as 0x00231960 (propagated; names are from that function)
#include "gen/fight.h"
extern void* hulk_at_00428824;
struct Sub_23c2e0 {
    void init_00234150();
};
struct Reference_23c2e0 {
    void* vt;
    char pad[0x24];
    void target();
};
void Reference_23c2e0::target() {
    vt = &hulk_at_00428824;
    ((Sub_23c2e0*)((char*)this + 0x28))->init_00234150();
    ((fight::Branch *)this)->FUN_00233970();
}

