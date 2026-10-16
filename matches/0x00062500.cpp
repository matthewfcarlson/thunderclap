// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_62500;
class CCondition_62500 {
  public:
    virtual int vfunc_0(int);
};

int CSmartPropSpawnTrack::vfunc_0(int index) {
    int* p = gTable_62500;
    return p[index];
}
