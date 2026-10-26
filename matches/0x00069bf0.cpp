// Same code shape as 0x00062300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct Helper_69bf0 {
    int f(CSweepTrack*, int);
};
extern "C" Helper_69bf0* __cdecl FUN_0008d690(int);

hulk_intptr CSweepTrack::vfunc_12(hulk_intptr a) {
    Helper_69bf0* p = FUN_0008d690(0x2c);
    if (p)
        return p->f(this, a);
    return 0;
}
