// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_627f0;
class CCondition_627f0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropDetachTrack::vfunc_0(int index) {
    int* p = gTable_627f0;
    return p[index];
}
