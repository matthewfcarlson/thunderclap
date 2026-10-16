// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14e180;
class CCondition_14e180 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::HitPushbackAddTrack::vfunc_0(int index) {
    int* p = gTable_14e180;
    return p[index];
}
