// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
// (tree_prelude.h: not needed)


// 0x001ca330 FUN_001ca330 (154 B): equivalent/0x001ca330.cpp [isolated: conflict: FUN_001d4c90; World; on include/gen/ and not mergeable]
// sym: ?FUN_001ca330@WaypointEvent_1ca330@owners@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca330 @ 0x001ca330
#include "decls/address.h"
#include "gen/owners.h"
struct Actor_1ca330 { const char* FUN_00036d00(); };
struct ActorTable_1ca330 {  };
struct World { char pad[0x44]; ActorTable_1ca330* actors; };
struct Writer_1ca330 {
    void FUN_001d1e10(const char* key, int value);
    void FUN_001d1d10();
};
Writer_1ca330* FUN_001d4c90();


bool owners::WaypointEvent_1ca330::FUN_001ca330()
{
    Writer_1ca330* w = FUN_001d4c90();
    if (w && ((owners::Obj_1d2e80 *)w)->FUN_001d2e80()) {
        ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"path", (hulk_uintptr)path);
        ((owners::Obj_1d1dd0 *)w)->FUN_001d1dd0((hulk_intptr)"waypoint", waypoint);
        w->FUN_001d1e10("first_time", firstTime);
        int id = actorId;
        if (DAT_004dd700) {
            Actor_1ca330* a = ((Actor_1ca330 *)((owners::ThisWrap_00059c10 *)(DAT_004dd700->actors))->FUN_00059c10((void *)(hulk_uintptr)(int)id));
            const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
            ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)name);
            w->FUN_001d1d10();
            return true;
        }
        w->FUN_001d1d10();
    }
    return false;
}

