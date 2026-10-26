// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14dc90;
class CCondition_14dc90 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::HitReactionFloatTrack::vfunc_0(int index) {
    int* p = gTable_14dc90;
    return p[index];
}
