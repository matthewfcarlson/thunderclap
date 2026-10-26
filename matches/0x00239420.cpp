// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern int* gTable_239420;
class CCondition_239420 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr fight::ExecuteTrack::vfunc_0(int index) {
    int* p = gTable_239420;
    return p[index];
}
