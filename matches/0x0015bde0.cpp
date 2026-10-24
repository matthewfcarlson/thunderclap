#include "gen/hulkfight.h"

#include "compat/ptr.h"
extern "C" char DAT_00415a40[];
struct Sub_15bde0 {
    void init();
};
struct HeliLocomotionTrack_nv_15bde0 {
    void parent();
};

void hulkfight::motion::HeliLocomotionTrack::FUN_0015bde0() {
    Sub_15bde0* p = (Sub_15bde0*)((char*)this + 0xa0);
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_00415a40);
    p->init();
    ((HeliLocomotionTrack_nv_15bde0*)this)->parent();
}
