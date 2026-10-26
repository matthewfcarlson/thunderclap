// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_123ee0;
class CCondition_123ee0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::HasTargetCondition::vfunc_0(int index) {
    int* p = gTable_123ee0;
    return p[index];
}
