#include "compat/ptr.h"
#include "gen/fight.h"

class HitWaitTrack_159d70 {
  public:
    virtual void V();
    int pad[2];
    int a;
    int b;
    HitWaitTrack_159d70();
};
extern void* __cdecl Alloc(hulk_uintptr);
extern int HitWaitTrack_vftable;

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitWaitTrack>::vfunc_5() {
    HitWaitTrack_159d70* p = (HitWaitTrack_159d70*)Alloc(0x14);
    if (p) {
        p->HitWaitTrack_159d70::HitWaitTrack_159d70();
        *(hulk_intptr*)p = (hulk_intptr)&HitWaitTrack_vftable;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
