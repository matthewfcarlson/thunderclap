// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_49570;
class CCondition_49570 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropNameCondition::vfunc_0(int index) {
    int* p = gTable_49570;
    return p[index];
}
