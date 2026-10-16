// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_12ed60;
class CCondition_12ed60 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::DebugPrintTrack::vfunc_0(int index) {
    int* p = gTable_12ed60;
    return p[index];
}
