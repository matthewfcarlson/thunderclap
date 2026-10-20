#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040f530[];
extern "C" void* __cdecl Alloc(unsigned int);
class StrafeCircleHBTrack_123030 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x24];
    StrafeCircleHBTrack_123030();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::StrafeCircleHBTrack>::vfunc_5() {
    StrafeCircleHBTrack_123030* p = (StrafeCircleHBTrack_123030*)Alloc(0x28);
    if (p) {
        p->StrafeCircleHBTrack_123030::StrafeCircleHBTrack_123030();
        int* q = (int*)p;
        q[3] = 0;
        q[5] = 0;
        q[6] = 0;
        q[7] = 0;
        q[8] = 0;
        q[0] = ((hulk_intptr)DAT_0040f530);
        q[4] = (int)0xbf800000;
        q[9] = (int)0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}
