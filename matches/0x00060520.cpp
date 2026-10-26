// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_60520;
class CCondition_60520 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CMotionTrailTrack::vfunc_0(int index) {
    int* p = gTable_60520;
    return p[index];
}
