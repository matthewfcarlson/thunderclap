// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14d8b0;
class CCondition_14d8b0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::CollisionChargeCondition::vfunc_0(int index) {
    int* p = gTable_14d8b0;
    return p[index];
}
