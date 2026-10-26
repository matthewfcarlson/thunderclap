#include "compat/ptr.h"
#include "gen/global.h"

class Alloc_693d0 {
  public:
    int call(CJumpTrack*, hulk_intptr);
};
extern int __cdecl FUN_0008d690(int);

hulk_intptr CJumpTrack::vfunc_12(hulk_intptr param) {
    hulk_intptr x = FUN_0008d690(0x3c);
    if (x)
        return ((Alloc_693d0*)x)->call(this, param);
    return 0;
}
