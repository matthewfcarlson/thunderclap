#include "gen/fight.h"

extern "C" char DAT_004142a0[];
class HitPauseTrack_159cb0 {
  public:
    virtual void A();
    virtual void B();
    HitPauseTrack_159cb0();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitPauseTrack>::vfunc_5() {
    HitPauseTrack_159cb0* p = (HitPauseTrack_159cb0*)operator_new(0x18);
    if (p) {
        p->HitPauseTrack_159cb0::HitPauseTrack_159cb0();
        int* q = (int*)p;
        q[0] = ((int)DAT_004142a0);
        q[3] = 0;
        q[4] = 0;
        q[5] = 0;
        q[2] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
