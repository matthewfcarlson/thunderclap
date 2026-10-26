// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_49a10;
class CCondition_49a10 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropStateCondition::vfunc_0(int index) {
    int* p = gTable_49a10;
    return p[index];
}
