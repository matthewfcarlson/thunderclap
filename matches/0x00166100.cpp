// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_166100;
class CCondition_166100 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::TargetHealthPercentCondition::vfunc_0(int index) {
    int* p = gTable_166100;
    return p[index];
}
