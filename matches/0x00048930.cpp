// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_48930;
class CCondition_48930 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CAxisDoubleTapCondition::vfunc_0(int index) {
    int* p = gTable_48930;
    return p[index];
}
