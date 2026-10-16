// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_15c030;
class CCondition_15c030 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_0(int index) {
    int* p = gTable_15c030;
    return p[index];
}
