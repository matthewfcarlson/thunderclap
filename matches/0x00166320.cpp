// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_166320;
class CCondition_166320 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VelocityXZAngleCondition::vfunc_0(int index) {
    int* p = gTable_166320;
    return p[index];
}
