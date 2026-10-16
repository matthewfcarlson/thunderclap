// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170a60;
class CCondition_170a60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::TargetIconDistanceTrack::vfunc_0(int index) {
    int* p = gTable_170a60;
    return p[index];
}
