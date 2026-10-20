#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fc058[];
extern "C" void* __cdecl FUN_0008d690(int);
struct Obj_774c0 {
    int vptr;
    int x4;
    int m8;
    int mc;
    int m10;
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CRageModeTrack>::vfunc_5() {
    Obj_774c0* p = (Obj_774c0*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        p->vptr = ((hulk_intptr)DAT_003fc058);
        p->mc = 0;
        p->m10 = 0;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
