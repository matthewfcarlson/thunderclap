#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004179e8[];
extern "C" void* FUN_0008d690(unsigned int);
class Base_17e2a0 {
  public:
    void init();
};
struct LocomotionStateTrack_17e2a0 {
    int vf;
    int pad;
    int m8;
    int mc;
    int m10;
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_5() {
    LocomotionStateTrack_17e2a0* p = (LocomotionStateTrack_17e2a0*)FUN_0008d690(0x14);
    if (p) {
        ((Base_17e2a0*)p)->init();
        p->vf = ((hulk_intptr)DAT_004179e8);
        p->mc = 0;
        p->m10 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
