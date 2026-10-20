#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041c318[];
struct LuaTrack_1a1e40 {
    void* vf;
    char pad[8];
    int x;
    int y;
    int z;
    int q;
    void initialize();
};
extern void* alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<hulkfight::scenario::LuaTrack>::vfunc_5() {
    LuaTrack_1a1e40* p = (LuaTrack_1a1e40*)alloc(0x1c);
    if (p) {
        p->initialize();
        p->vf = (void*)((hulk_intptr)DAT_0041c318);
        p->x = 0;
        p->y = (int)0xbf800000;
        p->z = 0;
        p->q = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
