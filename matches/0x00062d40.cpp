// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

class R_62d40 {
  public:
    int invoke(CPropActorSetStateTrack*, int);
};
extern R_62d40* FUN_0008d690(int);

int CPropActorSetStateTrack::vfunc_12(int param) {
    R_62d40* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
