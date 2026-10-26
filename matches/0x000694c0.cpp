#include "compat/ptr.h"
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(unsigned int);
class Helper_694c0 {
  public:
    int FUN_000190a0(CDropTrack*, int);
};

hulk_intptr CDropTrack::vfunc_12(hulk_intptr param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_694c0*)p)->FUN_000190a0(this, param);
    return 0;
}
