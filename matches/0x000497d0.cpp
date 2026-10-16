// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_497d0;
class CCondition_497d0 {
  public:
    virtual int vfunc_0(int);
};

int CSmartPropDistanceCondition::vfunc_0(int index) {
    int* p = gTable_497d0;
    return p[index];
}
