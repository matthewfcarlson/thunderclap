// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_62990;
class CCondition_62990 {
  public:
    virtual int vfunc_0(int);
};

int CSmartPropThrowingTrack::vfunc_0(int index) {
    int* p = gTable_62990;
    return p[index];
}
