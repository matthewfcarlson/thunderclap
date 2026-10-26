// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_49470;
class CCondition_49470 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropTypeCondition::vfunc_0(int index) {
    int* p = gTable_49470;
    return p[index];
}
