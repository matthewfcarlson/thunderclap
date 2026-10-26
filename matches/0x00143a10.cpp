// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_143a10;
class CCondition_143a10 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::MotionBlurTrack::vfunc_0(int index) {
    int* p = gTable_143a10;
    return p[index];
}
