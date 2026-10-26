#include "gen/pure3d.h"
#include "decls/data/game/global.h"
// data: zero_3226b0 = DAT_003f32e0

struct ThisCall_00322990 {
    void FUN_00322990();
};
struct ThisCall_003226d0 {
    void FUN_003226d0();
};

void pure3d::d3dExtFramebufferEffects::vfunc_2() {
    if ((*(float *)&this->f_18) != DAT_003f32e0)
        ((ThisCall_00322990*)(this))->FUN_00322990();
    else
        ((ThisCall_003226d0*)(this))->FUN_003226d0();
}
