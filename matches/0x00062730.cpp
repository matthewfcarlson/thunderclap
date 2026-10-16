// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_62730;
class CCondition_62730 {
  public:
    virtual int vfunc_0(int);
};

int CSmartPropSetStateTrack::vfunc_0(int index) {
    int* p = gTable_62730;
    return p[index];
}
