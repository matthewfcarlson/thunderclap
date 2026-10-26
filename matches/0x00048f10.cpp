// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48f10;
class CCondition_48f10 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CCollisionHeightCondition::vfunc_0(int index) {
    int* p = gTable_48f10;
    return p[index];
}
