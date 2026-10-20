// Same code shape as 0x000694c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(hulk_uintptr);
class Helper_69d70 {
  public:
    int FUN_000190a0(CAutoTargetTrack*, int);
};

int CAutoTargetTrack::vfunc_12(int param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_69d70*)p)->FUN_000190a0(this, param);
    return 0;
}
