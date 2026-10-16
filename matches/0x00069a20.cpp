// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_69a20 {
  public:
    int invoke(CMoveAddTrack*, int);
};
extern R_69a20* FUN_0008d690(int);

int CMoveAddTrack::vfunc_12(int param) {
    R_69a20* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
