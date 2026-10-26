// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_166490;
class CCondition_166490 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::VelocityXZCondition::vfunc_0(int index) {
    int* p = gTable_166490;
    return p[index];
}
