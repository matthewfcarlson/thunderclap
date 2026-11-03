#include "gen/owners.h"
class Writer_1cafd0 {
  public:
    void Close();
};
class Mgr_1cafd0 {
  public:
    char pad[0x44];
};
class Info_1cafd0 {
  public:
    const char* Name();
};
class Look_1cafd0 {
  public:
};
struct G_1cafd0 {
    char pad[0x44];
    Look_1cafd0* look;
};
extern G_1cafd0* g_game_1cafd0;
Writer_1cafd0* GetWriter();
bool owners::Actor_1cafd0::FUN_001cafd0() {
    Writer_1cafd0* w = GetWriter();
    if (!w)
        return false;
    if (!((owners::Obj_1d2e80 *)w)->FUN_001d2e80())
        return false;
    ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"tv", (hulk_uintptr)(&mName));
    G_1cafd0* g = g_game_1cafd0;
    int id = mId;
    if (!g) {
        w->Close();
        return false;
    }
    Look_1cafd0* l = g->look;
    Info_1cafd0* i = ((Info_1cafd0 *)((owners::ThisWrap_00059c10 *)l)->FUN_00059c10((void *)(hulk_uintptr)(int)id));
    if (i)
        ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)(i->Name()));
    else
        ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)"UNKNOWN");
    w->Close();
    return true;
}
