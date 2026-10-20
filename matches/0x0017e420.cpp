#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00417a78[];
class DriftTrack {
  public:
    volatile int a[8];
};
void* __cdecl Alloc(unsigned int);
class InitObj_17e420 {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_5() {
    DriftTrack* p = (DriftTrack*)Alloc(0x20);
    if (p) {
        ((InitObj_17e420*)p)->Init();
        p->a[3] = 0;
        p->a[0] = ((hulk_intptr)DAT_00417a78);
        p->a[4] = (int)0xbf800000;
        p->a[5] = 0;
        p->a[6] = 0;
        p->a[7] = 0;
        p->a[2] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
