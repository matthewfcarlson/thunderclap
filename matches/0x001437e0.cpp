// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1437e0;
class CCondition_1437e0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::SlowMotionTrack::vfunc_0(int index) {
    int* p = gTable_1437e0;
    return p[index];
}
