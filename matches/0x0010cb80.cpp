// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_10cb80;
class CCondition_10cb80 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::LeashedCondition::vfunc_0(int index) {
    int* p = gTable_10cb80;
    return p[index];
}
