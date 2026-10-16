// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_5df00;
class CCondition_5df00 {
  public:
    virtual int vfunc_0(int);
};

int CSnapToWallTrack::vfunc_0(int index) {
    int* p = gTable_5df00;
    return p[index];
}
