#include "gen/fight.h"

extern "C" char DAT_00417ad8[];
class MomentumXZAddTrack_17e5a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int pad;
    int c;
    int d;
    float x;
    float y;
    void Init();
};
extern "C" void* __cdecl Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_5() {
    MomentumXZAddTrack_17e5a0* p = (MomentumXZAddTrack_17e5a0*)Alloc(0x18);
    if (p) {
        p->Init();
        p->x = -1.0f;
        p->y = -1.0f;
        *(volatile int*)p = ((int)DAT_00417ad8);
        p->d = 0;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
