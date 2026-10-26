// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_488b0;
class CCondition_488b0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CAxisArcCondition::vfunc_0(int index) {
    int* p = gTable_488b0;
    return p[index];
}
