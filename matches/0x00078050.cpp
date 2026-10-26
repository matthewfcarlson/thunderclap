// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class R_78050 {
  public:
    int invoke(CExplosionTrack*, hulk_intptr);
};
extern R_78050* FUN_0008d690(int);

hulk_intptr CExplosionTrack::vfunc_12(hulk_intptr param) {
    R_78050* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
