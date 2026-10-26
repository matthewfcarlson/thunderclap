// Same code shape as 0x0005e050 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

class Helper_62860 {
  public:
    int go(hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

hulk_intptr CSmartPropDetachTrack::vfunc_12(hulk_intptr a) {
    void* p = FUN_0008d690(0x20);
    if (p)
        return ((Helper_62860*)p)->go(a);
    return 0;
}
