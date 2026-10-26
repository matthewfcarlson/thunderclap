// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_18f150;
class CCondition_18f150 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::ImpulseVelocityTrack::vfunc_0(int index) {
    int* p = gTable_18f150;
    return p[index];
}
