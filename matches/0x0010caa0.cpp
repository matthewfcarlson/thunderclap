// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_10caa0;
class CCondition_10caa0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::HulkActionRecentCondition::vfunc_0(int index) {
    int* p = gTable_10caa0;
    return p[index];
}
