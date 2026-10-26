// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_14e210;
class CCondition_14e210 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::HealthTrack::vfunc_0(int index) {
    int* p = gTable_14e210;
    return p[index];
}
