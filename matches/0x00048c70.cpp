// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48c70;
class CCondition_48c70 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CCollisionDirectionCondition::vfunc_0(int index) {
    int* p = gTable_48c70;
    return p[index];
}
