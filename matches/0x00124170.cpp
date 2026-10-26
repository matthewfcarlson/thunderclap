// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_124170;
class CCondition_124170 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::TargetDirectionXZCondition::vfunc_0(int index) {
    int* p = gTable_124170;
    return p[index];
}
