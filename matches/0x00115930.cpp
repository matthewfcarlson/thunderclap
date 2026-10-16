// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_115930;
class CCondition_115930 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::MotionStopTrack::vfunc_0(int index) {
    int* p = gTable_115930;
    return p[index];
}
