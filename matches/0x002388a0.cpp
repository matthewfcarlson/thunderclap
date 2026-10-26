// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern int* gTable_2388a0;
class CCondition_2388a0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr fight::PrintCondition::vfunc_0(int index) {
    int* p = gTable_2388a0;
    return p[index];
}
