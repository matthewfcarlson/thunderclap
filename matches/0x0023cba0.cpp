// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/fight.h"

extern int* gTable_23cba0;
class CCondition_23cba0 {
  public:
    virtual int vfunc_0(int);
};

int fight::PlatformCondition::vfunc_0(int index) {
    int* p = gTable_23cba0;
    return p[index];
}
