// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14d420;
class CCondition_14d420 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::CollisionSourceTypeCondition::vfunc_0(int index) {
    int* p = gTable_14d420;
    return p[index];
}
