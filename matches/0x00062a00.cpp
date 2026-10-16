// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_62a00 {
  public:
    int invoke(CSmartPropThrowingTrack*, int);
};
extern R_62a00* FUN_0008d690(int);

int CSmartPropThrowingTrack::vfunc_12(int param) {
    R_62a00* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
