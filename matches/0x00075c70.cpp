#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fc10c[];
void* __cdecl FUN_0008d690(unsigned int);
struct Obj_75c70 {
    int pad0[5];
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CAlertStatusTrack>::vfunc_5() {
    Obj_75c70* p = (Obj_75c70*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fc10c);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
