// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_124300;
class CCondition_124300 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::TargetClearTrack::vfunc_0(int index) {
    int* p = gTable_124300;
    return p[index];
}
