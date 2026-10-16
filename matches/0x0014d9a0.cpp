// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14d9a0;
class CCondition_14d9a0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_0(int index) {
    int* p = gTable_14d9a0;
    return p[index];
}
