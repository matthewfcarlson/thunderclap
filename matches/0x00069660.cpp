// Same code shape as 0x000694c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(unsigned int);
class Helper_69660 {
  public:
    int FUN_000190a0(CKeyPoseTrack*, hulk_intptr);
};

hulk_intptr CKeyPoseTrack::vfunc_12(hulk_intptr param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_69660*)p)->FUN_000190a0(this, param);
    return 0;
}
