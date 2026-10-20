#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00413678[];
typedef unsigned int u32_14c030;
struct GrappleStruggleTrack_14c030 {
    u32_14c030 a0, a4, a8, ac, a10, a14, a18, a1c, a20;
    void initialize();
};
void* __cdecl alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_5() {
    GrappleStruggleTrack_14c030* p = (GrappleStruggleTrack_14c030*)alloc(0x24);
    if (p) {
        p->initialize();
        p->ac = 0;
        p->a14 = 0;
        p->a18 = 0;
        p->a1c = 0;
        p->a20 = 0;
        p->a0 = ((hulk_intptr)DAT_00413678);
        p->a10 = 0xbf800000;
        p->a8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
