// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_5ddf0;
class CCondition_5ddf0 {
  public:
    virtual int vfunc_0(int);
};

int CStunAnimationTrack::vfunc_0(int index) {
    int* p = gTable_5ddf0;
    return p[index];
}
