// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_13ee40;
class CCondition_13ee40 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::WallVelocityCondition::vfunc_0(int index) {
    int* p = gTable_13ee40;
    return p[index];
}
