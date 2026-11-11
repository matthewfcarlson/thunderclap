// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
// (tree_prelude.h: not needed)


// 0x001cb0a0 FUN_001cb0a0 (120 B): matches/0x001cb0a0.cpp [isolated: conflict: FUN_001d4c90; World; on include/gen/ and not mergeable]
// sym: ?FUN_001cb0a0@Actor_1cb0a0@owners@@QAE_NXZ
#include "decls/address.h"
#include "gen/owners.h"
class Writer_1cb0a0 {
  public:
    void Close_001d1d10();
};
class Mgr_1cb0a0 {
  public:
    char pad[0x44];
};
class Info_1cb0a0 {
  public:
    const char* Name_00036d00();
};
class Look_1cb0a0 {
  public:
};
struct World {
    char pad[0x44];
    Look_1cb0a0* look;
};
Writer_1cb0a0* FUN_001d4c90();
bool owners::Actor_1cb0a0::FUN_001cb0a0() {
    Writer_1cb0a0* w = FUN_001d4c90();
    if (!w)
        return false;
    if (!((owners::Obj_1d2e80 *)w)->FUN_001d2e80())
        return false;
    ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"tv", (hulk_uintptr)(&mName));
    World* g = DAT_004dd700;
    int id = mId;
    if (!g) {
        w->Close_001d1d10();
        return false;
    }
    Look_1cb0a0* l = g->look;
    Info_1cb0a0* i = ((Info_1cb0a0 *)((owners::ThisWrap_00059c10 *)l)->FUN_00059c10((void *)(hulk_uintptr)(int)id));
    if (i)
        ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)(i->Name_00036d00()));
    else
        ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)"UNKNOWN");
    w->Close_001d1d10();
    return true;
}

