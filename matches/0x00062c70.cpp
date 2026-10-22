#include "gen/global.h"

struct CSmartPropRemoveInstanceAction_62c70 {
    int run(int, int);
};
extern CSmartPropRemoveInstanceAction* __cdecl FUN_0008d690(int);

int CSmartPropRemoveInstanceTrack::vfunc_12(int arg) {
    CSmartPropRemoveInstanceAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropRemoveInstanceAction_62c70*)(p))->run(arg, this->f_0c);
    return 0;
}
