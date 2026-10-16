// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_14dd60;
class CCondition_14dd60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::HitPauseTrack::vfunc_0(int index) {
    int* p = gTable_14dd60;
    return p[index];
}
