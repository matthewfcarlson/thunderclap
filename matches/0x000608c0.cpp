// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_608c0;
class CCondition_608c0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CEffectStopTrack::vfunc_0(int index) {
    int* p = gTable_608c0;
    return p[index];
}
