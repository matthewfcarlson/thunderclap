// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_115bb0;
class CCondition_115bb0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::MotionTargetTrack::vfunc_0(int index) {
    int* p = gTable_115bb0;
    return p[index];
}
