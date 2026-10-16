// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_5dfe0;
class CCondition_5dfe0 {
  public:
    virtual int vfunc_0(int);
};

int CClearHitRecordsTrack::vfunc_0(int index) {
    int* p = gTable_5dfe0;
    return p[index];
}
