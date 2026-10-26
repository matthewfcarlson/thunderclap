// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_5acf0;
class CCondition_5acf0 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CGrappleOpportunityTrack::vfunc_0(int index) {
    int* p = gTable_5acf0;
    return p[index];
}
