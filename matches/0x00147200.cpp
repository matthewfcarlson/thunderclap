// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_147200;
class CCondition_147200 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::GrappleAttachedCondition::vfunc_0(int index) {
    int* p = gTable_147200;
    return p[index];
}
