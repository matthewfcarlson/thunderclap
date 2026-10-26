// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_12f0b0;
class CCondition_12f0b0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::XPTrack::vfunc_0(int index) {
    int* p = gTable_12f0b0;
    return p[index];
}
