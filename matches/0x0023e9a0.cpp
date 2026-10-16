#include "gen/fight.h"

extern "C" char DAT_00428db0[];
typedef unsigned int uint;
extern "C" void* __cdecl operator_new(unsigned int);
class Inner_23e9a0 {
  public:
    void init();
};
class StopTrack_23e9a0 {
  public:
    virtual void dummy();
    char pad4[4];
    int flag;
    int zero;
    float value;
    Inner_23e9a0 inner;
    void init();
};

template <> void* fight::TrackFactoryTemplate<fight::StopTrack>::vfunc_5() {
    StopTrack_23e9a0* p = (StopTrack_23e9a0*)operator_new(0x18);
    if (p) {
        p->init();
        *(uint*)p = ((int)DAT_00428db0);
        p->zero = 0;
        p->value = -1.0f;
        p->inner.init();
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
