// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48ff0;
class CCondition_48ff0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CCollisionPushbackYCondition::vfunc_0(int index) {
    int* p = gTable_48ff0;
    return p[index];
}
