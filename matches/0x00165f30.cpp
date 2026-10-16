// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_165f30;
class CCondition_165f30 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::RayCastConeCondition::vfunc_0(int index) {
    int* p = gTable_165f30;
    return p[index];
}
