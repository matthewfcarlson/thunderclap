// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_181010;
class CCondition_181010 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::BallAndChainReturnTrack::vfunc_0(int index) {
    int* p = gTable_181010;
    return p[index];
}
