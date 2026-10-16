// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/fight.h"

extern int* gTable_23dfb0;
class CCondition_23dfb0 {
  public:
    virtual int vfunc_0(int);
};

int fight::WaitTrack::vfunc_0(int index) {
    int* p = gTable_23dfb0;
    return p[index];
}
