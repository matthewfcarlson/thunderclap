// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1812d0;
class CCondition_1812d0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::BallAndChainSpinTrack::vfunc_0(int index) {
    int* p = gTable_1812d0;
    return p[index];
}
