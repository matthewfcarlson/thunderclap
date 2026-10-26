// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_6a8b0;
class CCondition_6a8b0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CUninterruptibleTrack::vfunc_0(int index) {
    int* p = gTable_6a8b0;
    return p[index];
}
