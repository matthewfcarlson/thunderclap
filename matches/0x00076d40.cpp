#include "compat/ptr.h"
#include "gen/fight.h"

class CInvincibleTrack_76d40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int x;
    int one;
    int zero;
    int neg;
    int tail;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int cvtable_76d40;

template <> void* fight::TrackFactoryTemplate<CInvincibleTrack>::vfunc_5() {
    CInvincibleTrack_76d40* p = (CInvincibleTrack_76d40*)FUN_0008d690(0x18);
    CInvincibleTrack_76d40* r;
    if (p) {
        p->Init();
        *(hulk_intptr*)p = (hulk_intptr)&cvtable_76d40;
        p->zero = 0;
        p->neg = (int)0xbf800000;
        p->tail = 0;
        p->one = 1;
        r = p;
    } else
        r = 0;
    return (void*)(r);
}
