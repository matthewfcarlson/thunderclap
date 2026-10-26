// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_12e550;
class CCondition_12e550 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::DebugPrintCondition::vfunc_0(int index) {
    int* p = gTable_12e550;
    return p[index];
}
