#include "gen/global.h"
#include "decls/data/game/global.h"
// data: zeroValue_60750 = DAT_003f32e0
#include "compat/ptr.h"


hulk_freg CEffectTrack::vfunc_7() {
    if (this->f_50)
        return this->f_10 - this->f_0c;
    return (*(float*)&DAT_003f32e0);
}
