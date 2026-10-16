// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_68ce0;
class CCondition_68ce0 {
  public:
    virtual int vfunc_0(int);
};

int CJointTrack::vfunc_0(int index) {
    int* p = gTable_68ce0;
    return p[index];
}
