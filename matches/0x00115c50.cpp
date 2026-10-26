// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_115c50;
class CCondition_115c50 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::MotionChaseTrack::vfunc_0(int index) {
    int* p = gTable_115c50;
    return p[index];
}
