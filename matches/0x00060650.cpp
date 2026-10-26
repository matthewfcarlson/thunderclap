// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_60650;
class CCondition_60650 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CEffectTrack::vfunc_0(int index) {
    int* p = gTable_60650;
    return p[index];
}
