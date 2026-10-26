// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_166500;
class CCondition_166500 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_0(int index) {
    int* p = gTable_166500;
    return p[index];
}
