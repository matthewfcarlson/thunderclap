// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_15bc80;
class CCondition_15bc80 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::HeliLocomotionTrack::vfunc_0(int index) {
    int* p = gTable_15bc80;
    return p[index];
}
