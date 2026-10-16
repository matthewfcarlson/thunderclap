// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_15b960;
class CCondition_15b960 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::ClimbLocomotion4Track::vfunc_0(int index) {
    int* p = gTable_15b960;
    return p[index];
}
