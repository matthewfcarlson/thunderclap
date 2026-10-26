// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern int* gTable_23f110;
class CCondition_23f110 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr fight::BreakPointTrack::vfunc_0(int index) {
    int* p = gTable_23f110;
    return p[index];
}
