// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_166710;
class CCondition_166710 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VelocityAnimatedCondition::vfunc_0(int index) {
    int* p = gTable_166710;
    return p[index];
}
