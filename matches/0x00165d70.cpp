// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165d70;
class CCondition_165d70 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::TurningVelocityCondition::vfunc_0(int index) {
    int* p = gTable_165d70;
    return p[index];
}
