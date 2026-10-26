// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48d50;
class CCondition_48d50 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CNameFlagConditionBase::vfunc_0(int index) {
    int* p = gTable_48d50;
    return p[index];
}
