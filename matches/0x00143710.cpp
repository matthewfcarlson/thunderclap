// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_143710;
class CCondition_143710 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::HitEffectTrack::vfunc_0(int index) {
    int* p = gTable_143710;
    return p[index];
}
