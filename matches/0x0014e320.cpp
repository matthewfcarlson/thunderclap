// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14e320;
class CCondition_14e320 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::GroundSlideTrack::vfunc_0(int index) {
    int* p = gTable_14e320;
    return p[index];
}
