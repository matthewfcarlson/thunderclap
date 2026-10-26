// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_123e00;
class CCondition_123e00 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::TargetOrientationCondition::vfunc_0(int index) {
    int* p = gTable_123e00;
    return p[index];
}
