#include "compat/ptr.h"
#include "gen/fight.h"

class CTargetTrack_77790 {
  public:
    int a, b, c, d, e;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int CTargetTrack_vftable;

template <> void* fight::TrackFactoryTemplate<CTargetTrack>::vfunc_5() {
    CTargetTrack_77790* p = (CTargetTrack_77790*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(hulk_ulongptr*)p = (hulk_ulongptr)&CTargetTrack_vftable;
        p->d = 0;
        p->e = (int)0xbf800000;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)((CTargetTrack_77790*)0);
}
