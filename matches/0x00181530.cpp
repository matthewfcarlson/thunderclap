// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_181530;
class CCondition_181530 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::motion::PropDamageTrack::vfunc_0(int index) {
    int* p = gTable_181530;
    return p[index];
}
