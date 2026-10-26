// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int* gTable_1a13e0;
class CCondition_1a13e0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr hulkfight::scenario::LuaTrack::vfunc_0(int index) {
    int* p = gTable_1a13e0;
    return p[index];
}
