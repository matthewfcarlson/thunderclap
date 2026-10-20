#include "compat/ptr.h"
#include "gen/fight.h"

struct MotionFleeTrack_11b2a0 {
    hulk_intptr vtable;
    char pad4[8];
    int a;
    int b;
    int c;
    void ctor();
};
void* __cdecl operator_new(unsigned int);
extern char MotionFleeVtable;

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_5() {
    MotionFleeTrack_11b2a0* p = (MotionFleeTrack_11b2a0*)operator_new(0x18);
    if (p) {
        p->ctor();
        p->vtable = (hulk_intptr)&MotionFleeVtable;
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = (int)0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}
