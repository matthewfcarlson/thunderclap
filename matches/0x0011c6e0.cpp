// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_11c6e0;
class CCondition_11c6e0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::StrafeCircleTrack::vfunc_0(int index) {
    int* p = gTable_11c6e0;
    return p[index];
}
