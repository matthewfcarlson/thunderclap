#include "gen/global.h"

class R_5aad0 {
  public:
    int invoke(CGrappleAttachTrack*, int);
};
extern R_5aad0* FUN_0008d690(int);

int CGrappleAttachTrack::vfunc_12(int param) {
    R_5aad0* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
