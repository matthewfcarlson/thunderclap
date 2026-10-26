// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_5ab20;
class CCondition_5ab20 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CGrappleSwapTrack::vfunc_0(int index) {
    int* p = gTable_5ab20;
    return p[index];
}
