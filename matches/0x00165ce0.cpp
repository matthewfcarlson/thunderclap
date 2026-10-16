// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165ce0;
class CCondition_165ce0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::RayCastTargetCondition::vfunc_0(int index) {
    int* p = gTable_165ce0;
    return p[index];
}
