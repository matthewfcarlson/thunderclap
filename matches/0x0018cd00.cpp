// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_18cd00;
class CCondition_18cd00 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::GrappleVarCompareCondition::vfunc_0(int index) {
    int* p = gTable_18cd00;
    return p[index];
}
