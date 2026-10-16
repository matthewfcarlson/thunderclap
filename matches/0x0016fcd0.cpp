// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_16fcd0;
class CCondition_16fcd0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::JointTrackerTrack::vfunc_0(int index) {
    int* p = gTable_16fcd0;
    return p[index];
}
