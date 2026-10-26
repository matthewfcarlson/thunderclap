// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_49760;
class CCondition_49760 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropAngleCondition::vfunc_0(int index) {
    int* p = gTable_49760;
    return p[index];
}
