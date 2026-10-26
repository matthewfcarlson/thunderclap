// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern int* gTable_2372b0;
class CCondition_2372b0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr fight::OpportunityTrack::vfunc_0(int index) {
    int* p = gTable_2372b0;
    return p[index];
}
