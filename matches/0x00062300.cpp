#include "compat/ptr.h"
#include "gen/global.h"

struct Helper_62300 {
    int f(CSmartPropAttachTrack*, int);
};
extern "C" Helper_62300* __cdecl FUN_0008d690(int);

hulk_intptr CSmartPropAttachTrack::vfunc_12(hulk_intptr a) {
    Helper_62300* p = FUN_0008d690(0x2c);
    if (p)
        return p->f(this, a);
    return 0;
}
