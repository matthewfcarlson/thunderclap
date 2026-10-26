// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_4a5c0;
class CCondition_4a5c0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CRageModeCondition::vfunc_0(int index) {
    int* p = gTable_4a5c0;
    return p[index];
}
