// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_13efc0;
class CCondition_13efc0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::WallJumpTrack::vfunc_0(int index) {
    int* p = gTable_13efc0;
    return p[index];
}
