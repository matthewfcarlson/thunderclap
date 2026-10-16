// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_147180;
class CCondition_147180 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::GrappleAttachJointCondition::vfunc_0(int index) {
    int* p = gTable_147180;
    return p[index];
}
