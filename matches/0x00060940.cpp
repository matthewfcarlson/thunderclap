// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class R_60940 {
  public:
    int invoke(CEffectStopTrack*, hulk_intptr);
};
extern R_60940* FUN_0008d690(int);

hulk_intptr CEffectStopTrack::vfunc_12(hulk_intptr param) {
    R_60940* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
