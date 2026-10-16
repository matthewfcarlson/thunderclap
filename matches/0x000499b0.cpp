// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_499b0;
class CCondition_499b0 {
  public:
    virtual int vfunc_0(int);
};

int CSmartPropCSMableCondition::vfunc_0(int index) {
    int* p = gTable_499b0;
    return p[index];
}
