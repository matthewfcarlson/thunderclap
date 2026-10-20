// STATUS: equivalent (tools/equiv.py level 3: 19943 inputs, branch coverage 2/2)
// audio::ListenerEffectPs2Type::vfunc_2 @ 0x0024da50
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void* operator new(size_t, void* p) throw() { return p; }
struct Factory;
struct ListenerEffectPs2_24da50 {
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
    virtual ListenerEffectPs2_24da50* vfunc_3();
};
extern "C" ListenerEffectPs2_24da50* __cdecl FUN_00247530(Factory*);
struct Returned { void FUN_0025fb00(ListenerEffectPs2_24da50*); };
namespace audio {

}
void* audio::ListenerEffectPs2Type::vfunc_2() {
    Factory* factory = (Factory*)&(*(void**)&DAT_004e6548);
    ListenerEffectPs2_24da50* mem = FUN_00247530(factory);
    if (!mem) return (void*)(0);
    mem->FUN_0025e6f0(factory);
    ListenerEffectPs2_24da50* effect = new (mem) ListenerEffectPs2_24da50;
    ((Returned*)factory->vfunc_3())->FUN_0025fb00(effect);
    return (void*)(effect);
}
