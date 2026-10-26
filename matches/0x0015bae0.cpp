// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_15bae0;
class CCondition_15bae0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::LocomotionStrafe4Track::vfunc_0(int index) {
    int* p = gTable_15bae0;
    return p[index];
}
