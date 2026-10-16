// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_62940 {
  public:
    int invoke(CSmartPropThrowTrack*, int);
};
extern R_62940* FUN_0008d690(int);

int CSmartPropThrowTrack::vfunc_12(int param) {
    R_62940* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
