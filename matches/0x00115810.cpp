// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_115810;
class CCondition_115810 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::HasGroundPointExtendedCondition::vfunc_0(int index) {
    int* p = gTable_115810;
    return p[index];
}
