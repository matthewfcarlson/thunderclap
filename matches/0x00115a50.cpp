// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_115a50;
class CCondition_115a50 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::MotionBoostTrack::vfunc_0(int index) {
    int* p = gTable_115a50;
    return p[index];
}
