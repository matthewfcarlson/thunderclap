// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_5ac30;
class CCondition_5ac30 {
  public:
    virtual int vfunc_0(int);
};

int CGrappleDetachTrack::vfunc_0(int index) {
    int* p = gTable_5ac30;
    return p[index];
}
