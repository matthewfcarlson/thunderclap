// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_124240;
class CCondition_124240 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::TargetInvincibleCondition::vfunc_0(int index) {
    int* p = gTable_124240;
    return p[index];
}
