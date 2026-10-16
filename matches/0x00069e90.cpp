// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_69e90;
class CCondition_69e90 {
  public:
    virtual int vfunc_0(int);
};

int CDrainHealthTrack::vfunc_0(int index) {
    int* p = gTable_69e90;
    return p[index];
}
