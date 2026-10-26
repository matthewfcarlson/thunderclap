// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_193bc0;
class CCondition_193bc0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::PropGrabbableIsMissileCondition::vfunc_0(int index) {
    int* p = gTable_193bc0;
    return p[index];
}
