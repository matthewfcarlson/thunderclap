// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_49860;
class CCondition_49860 {
  public:
    virtual int vfunc_0(int);
};

int CSmartPropGrabbableNameCondition::vfunc_0(int index) {
    int* p = gTable_49860;
    return p[index];
}
