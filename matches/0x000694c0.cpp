#include "compat/ptr.h"
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(hulk_uintptr);
class Helper_694c0 {
  public:
    int FUN_000190a0(CDropTrack*, int);
};

int CDropTrack::vfunc_12(int param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_694c0*)p)->FUN_000190a0(this, param);
    return 0;
}
