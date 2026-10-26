// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class R_5d200 {
  public:
    int invoke(CHapticTrack*, int);
};
extern R_5d200* FUN_0008d690(int);

hulk_intptr CHapticTrack::vfunc_12(hulk_intptr param) {
    R_5d200* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
