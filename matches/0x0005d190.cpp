// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_5d190;
class CCondition_5d190 {
  public:
    virtual int vfunc_0(int);
};

int CHapticTrack::vfunc_0(int index) {
    int* p = gTable_5d190;
    return p[index];
}
