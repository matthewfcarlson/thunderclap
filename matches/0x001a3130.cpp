// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1a3130;
class CCondition_1a3130 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::scenario::EffectTrack::vfunc_0(int index) {
    int* p = gTable_1a3130;
    return p[index];
}
