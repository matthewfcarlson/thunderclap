// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_62c00;
class CCondition_62c00 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropRemoveInstanceTrack::vfunc_0(int index) {
    int* p = gTable_62c00;
    return p[index];
}
