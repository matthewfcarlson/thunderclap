// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165c70;
class CCondition_165c70 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VelocityAnimatedXZCondition::vfunc_0(int index) {
    int* p = gTable_165c70;
    return p[index];
}
