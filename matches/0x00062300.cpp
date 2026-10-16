#include "gen/global.h"

struct Helper_62300 {
    int f(CSmartPropAttachTrack*, int);
};
extern "C" Helper_62300* __cdecl FUN_0008d690(int);

int CSmartPropAttachTrack::vfunc_12(int a) {
    Helper_62300* p = FUN_0008d690(0x2c);
    if (p)
        return p->f(this, a);
    return 0;
}
