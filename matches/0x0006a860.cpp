// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class R_6a860 {
  public:
    int invoke(CDriftTrack*, hulk_intptr);
};
extern R_6a860* FUN_0008d690(int);

hulk_intptr CDriftTrack::vfunc_12(hulk_intptr param) {
    R_6a860* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
