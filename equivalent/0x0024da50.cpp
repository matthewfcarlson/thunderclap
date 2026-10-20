// STATUS: equivalent (tools/equiv.py level 3: 19943 inputs, branch coverage 2/2)
// audio::ListenerEffectPs2Type::vfunc_2 @ 0x0024da50
#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void* operator new(size_t, void* p) throw() { return p; }
struct Factory;
struct ListenerEffectPs2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void FUN_0025e6f0(Factory*);
};
struct Factory {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual ListenerEffectPs2* vfunc_3(ListenerEffectPs2*);
};
extern "C" ListenerEffectPs2* __cdecl FUN_00247530(Factory*);
struct Returned { void FUN_0025fb00(ListenerEffectPs2*); };
namespace audio {
struct ListenerEffectPs2Type {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual ListenerEffectPs2* vfunc_2();
    virtual void vfunc_3();
};
ListenerEffectPs2* ListenerEffectPs2Type::vfunc_2() {
    Factory* factory = (Factory*)&(*(void**)&DAT_004e6548);
    ListenerEffectPs2* mem = FUN_00247530(factory);
    if (!mem) return 0;
    mem->FUN_0025e6f0(factory);
    ListenerEffectPs2* effect = new (mem) ListenerEffectPs2;
    ListenerEffectPs2* result = factory->vfunc_3(effect);
    ((Returned*)result)->FUN_0025fb00(effect);
    return effect;
}
}