// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_180630;
class CCondition_180630 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::SmartPropGrabbableCondition::vfunc_0(int index) {
    int* p = gTable_180630;
    return p[index];
}
