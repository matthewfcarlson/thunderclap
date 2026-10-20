#include "compat/ptr.h"
extern "C" char DAT_003fbd50[];
class CDrainHealthTrack {
  public:
    int a, b, c, d, e, f;
    void init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class Entity {
  public:
    virtual void v3();
    virtual void v4();
};
class LoadObject {
  public:
    virtual void v0();
    virtual void v1();
};
class IRefCount {
  public:
    virtual void r0();
};
class TrackFactoryTemplate : public TrackFactory, public Entity, public LoadObject, public IRefCount {
  public:
    CDrainHealthTrack* vfunc_5();
};
CDrainHealthTrack* TrackFactoryTemplate::vfunc_5() {
    CDrainHealthTrack* p = (CDrainHealthTrack*)FUN_0008d690(0x18);
    if (p) {
        p->init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fbd50);
        p->d = 0;
        p->e = 0x3f800000;
        p->f = 0;
        p->c = 1;
    } else
        return 0;
    return p;
}