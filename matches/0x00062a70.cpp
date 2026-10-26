// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_62a70;
class CCondition_62a70 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropDropTrack::vfunc_0(int index) {
    int* p = gTable_62a70;
    return p[index];
}
