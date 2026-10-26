// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_147420;
class CCondition_147420 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::GrappleThrowTrack::vfunc_0(int index) {
    int* p = gTable_147420;
    return p[index];
}
