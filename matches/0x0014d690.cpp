// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14d690;
class CCondition_14d690 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_0(int index) {
    int* p = gTable_14d690;
    return p[index];
}
