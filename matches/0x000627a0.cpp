// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_627a0 {
  public:
    int invoke(CSmartPropSetStateTrack*, int);
};
extern R_627a0* FUN_0008d690(int);

int CSmartPropSetStateTrack::vfunc_12(int param) {
    R_627a0* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
