// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_5abe0 {
  public:
    int invoke(CGrappleSwapTrack*, int);
};
extern R_5abe0* FUN_0008d690(int);

int CGrappleSwapTrack::vfunc_12(int param) {
    R_5abe0* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
