// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14e470;
class CCondition_14e470 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::NoHitPushbackTrack::vfunc_0(int index) {
    int* p = gTable_14e470;
    return p[index];
}
