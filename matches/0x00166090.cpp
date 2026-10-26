// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_166090;
class CCondition_166090 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_0(int index) {
    int* p = gTable_166090;
    return p[index];
}
