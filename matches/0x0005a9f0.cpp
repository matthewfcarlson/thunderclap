// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_5a9f0;
class CCondition_5a9f0 {
  public:
    virtual int vfunc_0(int);
};

int CGrappleAttachTrack::vfunc_0(int index) {
    int* p = gTable_5a9f0;
    return p[index];
}
