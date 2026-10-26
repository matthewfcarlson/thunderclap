#include "compat/ptr.h"
#include "gen/global.h"

class Alloc_6a650 {
  public:
    int method(CJumpAttackTrack*, hulk_intptr);
};
extern Alloc_6a650* FUN_0008d690(int);

hulk_intptr CJumpAttackTrack::vfunc_12(hulk_intptr param) {
    Alloc_6a650* p = FUN_0008d690(0x34);
    if (p)
        return p->method(this, param);
    return 0;
}
