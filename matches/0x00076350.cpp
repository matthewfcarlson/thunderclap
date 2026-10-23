#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_003fbd50[];
class CDrainHealthTrack_76350 {
  public:
    int a, b, c, d, e, f;
    void init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TrackFactory_76350 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class Entity_76350 {
  public:
    virtual void v3();
    virtual void v4();
};
class LoadObject_76350 {
  public:
    virtual void v0();
    virtual void v1();
};
class IRefCount_76350 {
  public:
    virtual void r0();
};

template <> void* fight::TrackFactoryTemplate<CDrainHealthTrack>::vfunc_5() {
    CDrainHealthTrack_76350* p = (CDrainHealthTrack_76350*)FUN_0008d690(0x18);
    if (p) {
        p->init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fbd50);
        p->d = 0;
        p->e = 0x3f800000;
        p->f = 0;
        p->c = 1;
    } else
        return (void*)(0);
    return (void*)(p);
}
