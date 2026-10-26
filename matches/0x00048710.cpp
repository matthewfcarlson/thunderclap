// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48710;
class CCondition_48710 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CAxisSpeedCondition::vfunc_0(int index) {
    int* p = gTable_48710;
    return p[index];
}
