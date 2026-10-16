// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_12d9a0;
class CCondition_12d9a0 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::PostEvent_StringTrack::vfunc_0(int index) {
    int* p = gTable_12d9a0;
    return p[index];
}
