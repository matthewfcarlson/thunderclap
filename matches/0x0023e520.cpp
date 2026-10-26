// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern int* gTable_23e520;
class CCondition_23e520 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr fight::StopTrack::vfunc_0(int index) {
    int* p = gTable_23e520;
    return p[index];
}
