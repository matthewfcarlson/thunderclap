#include "compat/ptr.h"
#include "gen/global.h"

class Helper_5e050 {
  public:
    int go(hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

hulk_intptr CClearHitRecordsTrack::vfunc_12(hulk_intptr a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_5e050*)p)->go(a);
    return 0;
}
