// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_166020;
class CCondition_166020 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VelocityAnimatedYCondition::vfunc_0(int index) {
    int* p = gTable_166020;
    return p[index];
}
