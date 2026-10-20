#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041aaa8[];
struct TimerSetTrack_18ea10 {
    hulk_intptr vptr;
    int pad4;
    int m8;
    int mc;
    int m10;
    int m14;
    void Init();
};
extern "C" void* __cdecl Allocate(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TimerSetTrack>::vfunc_5() {
    TimerSetTrack_18ea10* p = (TimerSetTrack_18ea10*)Allocate(0x18);
    if (p) {
        p->Init();
        p->vptr = ((hulk_intptr)DAT_0041aaa8);
        p->mc = 0;
        p->m10 = 0;
        p->m14 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
