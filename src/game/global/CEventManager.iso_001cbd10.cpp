// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
// (tree_prelude.h: not needed)


// 0x001cbd10 FUN_001cbd10 (39 B): matches/0x001cbd10.cpp [isolated: lost its match in the tree (codegen differs (15 of 26 instructions)); on include/gen/ and not mergeable]
// sym: ?FUN_001cbd10@CEventManager@@QAEXI@Z
#include "gen/global.h"
#include "gen/owners.h"

typedef unsigned int u32_1cbd10;
struct Local_1cbd10 {
    char pad[32];
};
struct CEventManager_nv_1cbd10 {
    void Run_001cbc20(Local_1cbd10*);
};

void CEventManager::FUN_001cbd10(unsigned int __p0) { u32_1cbd10 arg = (u32_1cbd10)__p0;

    Local_1cbd10 local;
    ((owners::Result_1cae40 *)&local)->FUN_001cae40((hulk_uintptr)arg);
    ((CEventManager_nv_1cbd10*)this)->Run_001cbc20(&local);
}

