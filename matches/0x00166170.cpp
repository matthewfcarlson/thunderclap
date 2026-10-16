// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_166170;
class CCondition_166170 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::GrappleHealthCondition::vfunc_0(int index) {
    int* p = gTable_166170;
    return p[index];
}
