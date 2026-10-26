// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_124430;
class CCondition_124430 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::ClearProjectileDistanceTrack::vfunc_0(int index) {
    int* p = gTable_124430;
    return p[index];
}
