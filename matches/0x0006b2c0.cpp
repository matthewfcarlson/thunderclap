// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_6b2c0 {
  public:
    int invoke(CTargetTrack*, int);
};
extern R_6b2c0* FUN_0008d690(int);

int CTargetTrack::vfunc_12(int param) {
    R_6b2c0* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
