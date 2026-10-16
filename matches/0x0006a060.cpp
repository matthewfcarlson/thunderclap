// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_6a060;
class CCondition_6a060 {
  public:
    virtual int vfunc_0(int);
};

int CInvincibleTrack::vfunc_0(int index) {
    int* p = gTable_6a060;
    return p[index];
}
