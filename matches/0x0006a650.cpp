#include "gen/global.h"

class Alloc_6a650 {
  public:
    int method(CJumpAttackTrack*, int);
};
extern Alloc_6a650* FUN_0008d690(int);

int CJumpAttackTrack::vfunc_12(int param) {
    Alloc_6a650* p = FUN_0008d690(0x34);
    if (p)
        return p->method(this, param);
    return 0;
}
