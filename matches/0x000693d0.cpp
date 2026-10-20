#include "compat/ptr.h"
#include "gen/global.h"

class Alloc_693d0 {
  public:
    int call(CJumpTrack*, int);
};
extern int __cdecl FUN_0008d690(int);

int CJumpTrack::vfunc_12(int param) {
    hulk_intptr x = FUN_0008d690(0x3c);
    if (x)
        return ((Alloc_693d0*)x)->call(this, param);
    return 0;
}
