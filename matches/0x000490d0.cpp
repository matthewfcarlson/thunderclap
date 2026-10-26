// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_490d0;
class CCondition_490d0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CCollisionStunTimeCondition::vfunc_0(int index) {
    int* p = gTable_490d0;
    return p[index];
}
