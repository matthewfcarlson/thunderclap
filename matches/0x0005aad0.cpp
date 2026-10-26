#include "compat/ptr.h"
#include "gen/global.h"

class R_5aad0 {
  public:
    int invoke(CGrappleAttachTrack*, hulk_intptr);
};
extern R_5aad0* FUN_0008d690(int);

hulk_intptr CGrappleAttachTrack::vfunc_12(hulk_intptr param) {
    R_5aad0* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}
