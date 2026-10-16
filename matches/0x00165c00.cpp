// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165c00;
class CCondition_165c00 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::VelocityYCondition::vfunc_0(int index) {
    int* p = gTable_165c00;
    return p[index];
}
