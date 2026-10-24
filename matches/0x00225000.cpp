#include "gen/choreo2.h"

#include "compat/ptr.h"
extern "C" char DAT_00427368[];
struct Inner_225000 {
    virtual void A();
    virtual void B();
};
extern int gCount_225000;
struct AnimationDriver_nv_225000 {
    void Tail();
};

void choreo2::AnimationDriver::FUN_00225000() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427368);
    (*(Inner_225000 * *)&this->f_20)->B();
    --gCount_225000;
    ((AnimationDriver_nv_225000*)this)->Tail();
}
