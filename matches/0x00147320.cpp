// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_147320;
class CCondition_147320 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::GrappleOrientationCondition::vfunc_0(int index) {
    int* p = gTable_147320;
    return p[index];
}
