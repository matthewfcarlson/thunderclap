// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_69b00 {
  public:
    int invoke(CMoveAddYTrack*, int);
};
extern R_69b00* FUN_0008d690(int);

int CMoveAddYTrack::vfunc_12(int param) {
    R_69b00* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
