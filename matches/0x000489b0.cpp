// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_489b0;
class CCondition_489b0 {
  public:
    virtual int vfunc_0(int);
};

int CAxisDirectionCondition::vfunc_0(int index) {
    int* p = gTable_489b0;
    return p[index];
}
