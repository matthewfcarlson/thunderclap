#include "compat/ptr.h"
#include "gen/physics.h"
extern "C" char DAT_0043209c[];
struct PoseDriver_30eb10 {
    void InitBase();
};
physics::PoseDriver* __fastcall FUN_0030eb10(physics::PoseDriver* self) {
    ((PoseDriver_30eb10*)(self))->InitBase();
    *(void**)self = (void*)((hulk_intptr)DAT_0043209c);
    (*(char *)&self->f_10) = 1;
    return self;
}