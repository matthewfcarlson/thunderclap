// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_69510;
class CCondition_69510 {
  public:
    virtual int vfunc_0(int);
};

int CKeyPoseTrack::vfunc_0(int index) {
    int* p = gTable_69510;
    return p[index];
}
