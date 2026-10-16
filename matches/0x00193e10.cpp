// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_193e10;
class CCondition_193e10 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::MissileThrowTrack::vfunc_0(int index) {
    int* p = gTable_193e10;
    return p[index];
}
