// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_12b5c0;
class CCondition_12b5c0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::ai::ThreatBallTrack::vfunc_0(int index) {
    int* p = gTable_12b5c0;
    return p[index];
}
