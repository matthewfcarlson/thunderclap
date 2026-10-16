// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_16fe70;
class CCondition_16fe70 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::RestPoseTrack::vfunc_0(int index) {
    int* p = gTable_16fe70;
    return p[index];
}
