// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_166390;
class CCondition_166390 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::RayCastCondition::vfunc_0(int index) {
    int* p = gTable_166390;
    return p[index];
}
