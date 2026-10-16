// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14da10;
class CCondition_14da10 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::CollisionTargetTypeCondition::vfunc_0(int index) {
    int* p = gTable_14da10;
    return p[index];
}
