// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14d6f0;
class CCondition_14d6f0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::HitPushbackVelocityCondition::vfunc_0(int index) {
    int* p = gTable_14d6f0;
    return p[index];
}
