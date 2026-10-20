#include "compat/ptr.h"
#include "gen/fight.h"

class FaceTargetTrack_10bfb0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int pad;
    int m8;
    int mc;
    float m10;
    FaceTargetTrack_10bfb0();
};
extern void* __cdecl Allocate(unsigned int);
extern int FaceVtable;

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_5() {
    FaceTargetTrack_10bfb0* p = (FaceTargetTrack_10bfb0*)Allocate(0x14);
    if (p) {
        p->FaceTargetTrack_10bfb0::FaceTargetTrack_10bfb0();
        *(hulk_intptr*)p = (hulk_intptr)&FaceVtable;
        p->mc = 0;
        p->m10 = -1.0f;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
