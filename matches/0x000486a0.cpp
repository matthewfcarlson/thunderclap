// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_486a0;
class CCondition_486a0 {
  public:
    virtual int vfunc_0(int);
};

int CAxisTimeCondition::vfunc_0(int index) {
    int* p = gTable_486a0;
    return p[index];
}
