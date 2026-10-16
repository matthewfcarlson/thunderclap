// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_170890;
class CCondition_170890 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::JointPivotTrackerTrack::vfunc_0(int index) {
    int* p = gTable_170890;
    return p[index];
}
