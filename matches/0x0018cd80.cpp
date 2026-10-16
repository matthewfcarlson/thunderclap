// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_18cd80;
class CCondition_18cd80 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VarCompareCondition::vfunc_0(int index) {
    int* p = gTable_18cd80;
    return p[index];
}
