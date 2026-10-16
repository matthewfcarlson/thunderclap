#include "gen/pure3d.h"

extern const float zero_3226b0;
void FUN_00322990();
void FUN_003226d0();

void pure3d::d3dExtFramebufferEffects::vfunc_2() {
    if ((*(float *)&this->f_18) != zero_3226b0)
        FUN_00322990();
    else
        FUN_003226d0();
}
