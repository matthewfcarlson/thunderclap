// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class R_68f60 {
  public:
    int invoke(CClimbingTrack*, hulk_intptr);
};
extern R_68f60* FUN_0008d690(int);

hulk_intptr CClimbingTrack::vfunc_12(hulk_intptr param) {
    R_68f60* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
