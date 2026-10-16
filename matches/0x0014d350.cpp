// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14d350;
class CCondition_14d350 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::CollisionThrowCondition::vfunc_0(int index) {
    int* p = gTable_14d350;
    return p[index];
}
