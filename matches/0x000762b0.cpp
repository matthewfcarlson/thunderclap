#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fc148[];
class CDeathTrack_762b0 {
  public:
    int pad[4];
    void init();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CDeathTrack>::vfunc_5() {
    CDeathTrack_762b0* p = (CDeathTrack_762b0*)operator_new(0x10);
    if (p) {
        p->init();
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_003fc148);
        *(unsigned long*)((char*)p + 0xc) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
