// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_15be20;
class CCondition_15be20 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::LocomotionSteerTrack::vfunc_0(int index) {
    int* p = gTable_15be20;
    return p[index];
}
