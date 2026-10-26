// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_115af0;
class CCondition_115af0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::MotionLocatorTrack::vfunc_0(int index) {
    int* p = gTable_115af0;
    return p[index];
}
