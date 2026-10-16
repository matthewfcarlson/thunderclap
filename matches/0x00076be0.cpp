#include "gen/fight.h"

extern "C" char DAT_003fbe04[];
class CIntangibleTrack_76be0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad;
    int c;
    int d;
    int e;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CIntangibleTrack>::vfunc_5() {
    CIntangibleTrack_76be0* p = (CIntangibleTrack_76be0*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003fbe04);
        p->d = 0;
        p->e = (int)0xbf800000;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
