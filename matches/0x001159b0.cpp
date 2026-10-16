// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_1159b0;
class CCondition_1159b0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::MotionFacingTrack::vfunc_0(int index) {
    int* p = gTable_1159b0;
    return p[index];
}
