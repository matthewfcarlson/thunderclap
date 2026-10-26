// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_5d920;
class CCondition_5d920 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CCollisionTrack::vfunc_0(int index) {
    int* p = gTable_5d920;
    return p[index];
}
