// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_124020;
class CCondition_124020 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::TargetDistanceXZCondition::vfunc_0(int index) {
    int* p = gTable_124020;
    return p[index];
}
