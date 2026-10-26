// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14e060;
class CCondition_14e060 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::HitFloatTrack::vfunc_0(int index) {
    int* p = gTable_14e060;
    return p[index];
}
