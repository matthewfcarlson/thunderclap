// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_147580;
class CCondition_147580 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::CivilianThrowTrack::vfunc_0(int index) {
    int* p = gTable_147580;
    return p[index];
}
