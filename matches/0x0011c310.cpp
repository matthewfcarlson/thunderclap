// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_11c310;
class CCondition_11c310 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::ai::RoutTrack::vfunc_0(int index) {
    int* p = gTable_11c310;
    return p[index];
}
