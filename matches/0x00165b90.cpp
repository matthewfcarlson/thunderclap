// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165b90;
class CCondition_165b90 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VelocityCondition::vfunc_0(int index) {
    int* p = gTable_165b90;
    return p[index];
}
