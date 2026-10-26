// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_147850;
class CCondition_147850 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::CivilianAnimationTrack::vfunc_0(int index) {
    int* p = gTable_147850;
    return p[index];
}
