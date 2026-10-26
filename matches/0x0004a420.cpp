// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_4a420;
class CCondition_4a420 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CClimbableCondition::vfunc_0(int index) {
    int* p = gTable_4a420;
    return p[index];
}
