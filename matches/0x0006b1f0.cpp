#include "compat/ptr.h"
#include "gen/global.h"

class Alloc_6b1f0 {
  public:
    int method(CWallSlideTrack*, int);
};
extern void* __cdecl FUN_0008d690(unsigned int);

hulk_intptr CWallSlideTrack::vfunc_12(hulk_intptr param) {
    Alloc_6b1f0* p = (Alloc_6b1f0*)FUN_0008d690(0x38);
    if (p)
        return p->method(this, param);
    return 0;
}
