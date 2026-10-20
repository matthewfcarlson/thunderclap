#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004194dc[];
typedef unsigned int u32_18c1b0;
extern void* __cdecl operator_new(unsigned int);
class ShieldArcTrack_18c1b0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    u32_18c1b0 pad;
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_5() {
    ShieldArcTrack_18c1b0* p = (ShieldArcTrack_18c1b0*)operator_new(0x14);
    if (p) {
        p->Init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004194dc);
        *(u32_18c1b0*)((char*)p + 0xc) = 0;
        *(u32_18c1b0*)((char*)p + 0x10) = 0x3fc90fdb;
        *(u32_18c1b0*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
