// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_6a140;
class CCondition_6a140 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CIntangibleTrack::vfunc_0(int index) {
    int* p = gTable_6a140;
    return p[index];
}
