#include "compat/ptr.h"
#include "gen/global.h"

struct CSmartPropRemoveInstanceAction_nv_62c70 {
    int run(int, int);
};
extern CSmartPropRemoveInstanceAction* __cdecl FUN_0008d690(int);

hulk_intptr CSmartPropRemoveInstanceTrack::vfunc_12(hulk_intptr arg) {
    CSmartPropRemoveInstanceAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropRemoveInstanceAction_nv_62c70*)(((CSmartPropRemoveInstanceAction*)(p))))->run(arg, this->f_0c);
    return 0;
}
