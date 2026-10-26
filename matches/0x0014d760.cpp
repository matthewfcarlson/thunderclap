// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14d760;
class CCondition_14d760 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::CollisionThrownObjectCondition::vfunc_0(int index) {
    int* p = gTable_14d760;
    return p[index];
}
