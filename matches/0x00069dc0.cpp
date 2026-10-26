// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_69dc0;
class CCondition_69dc0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CDamageTrack::vfunc_0(int index) {
    int* p = gTable_69dc0;
    return p[index];
}
