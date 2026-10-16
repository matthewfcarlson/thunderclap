// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_5ab20;
class CCondition_5ab20 {
  public:
    virtual int vfunc_0(int);
};

int CGrappleSwapTrack::vfunc_0(int index) {
    int* p = gTable_5ab20;
    return p[index];
}
