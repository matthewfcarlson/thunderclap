// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170260;
class CCondition_170260 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::LocomotionStateTrack::vfunc_0(int index) {
    int* p = gTable_170260;
    return p[index];
}
