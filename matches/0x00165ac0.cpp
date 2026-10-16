// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165ac0;
class CCondition_165ac0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::TargetMotionStateCondition::vfunc_0(int index) {
    int* p = gTable_165ac0;
    return p[index];
}
