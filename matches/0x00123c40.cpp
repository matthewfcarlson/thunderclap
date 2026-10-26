// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_123c40;
class CCondition_123c40 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::TargetDistanceCondition::vfunc_0(int index) {
    int* p = gTable_123c40;
    return p[index];
}
