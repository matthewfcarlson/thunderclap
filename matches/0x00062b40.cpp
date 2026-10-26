// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_62b40;
class CCondition_62b40 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropEventTrack::vfunc_0(int index) {
    int* p = gTable_62b40;
    return p[index];
}
