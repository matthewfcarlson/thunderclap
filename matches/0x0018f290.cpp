// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_18f290;
class CCondition_18f290 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::TankLocomotionTrack::vfunc_0(int index) {
    int* p = gTable_18f290;
    return p[index];
}
