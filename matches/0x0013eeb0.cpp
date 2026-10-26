// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_13eeb0;
class CCondition_13eeb0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::WallRunTrack::vfunc_0(int index) {
    int* p = gTable_13eeb0;
    return p[index];
}
