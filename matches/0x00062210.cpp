// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_62210;
class CCondition_62210 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropAttachTrack::vfunc_0(int index) {
    int* p = gTable_62210;
    return p[index];
}
