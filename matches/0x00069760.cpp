// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_69760 {
  public:
    int invoke(CSoundTrack*, int);
};
extern R_69760* FUN_0008d690(int);

int CSoundTrack::vfunc_12(int param) {
    R_69760* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
