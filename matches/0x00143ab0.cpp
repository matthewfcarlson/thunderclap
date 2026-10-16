// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_143ab0;
class CCondition_143ab0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::MotionTrailStopTrack::vfunc_0(int index) {
    int* p = gTable_143ab0;
    return p[index];
}
