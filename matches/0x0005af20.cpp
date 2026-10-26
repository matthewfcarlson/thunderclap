// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_5af20;
class CCondition_5af20 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CGrappleSequenceTrack::vfunc_0(int index) {
    int* p = gTable_5af20;
    return p[index];
}
