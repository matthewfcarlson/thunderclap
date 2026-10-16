// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14d620;
class CCondition_14d620 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::CollisionTargetSizeCondition::vfunc_0(int index) {
    int* p = gTable_14d620;
    return p[index];
}
