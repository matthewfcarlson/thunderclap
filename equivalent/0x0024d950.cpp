// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::ListenerEffectGcType::vfunc_2 @ 0x0024d950
typedef unsigned int size_t;
inline void* operator new(size_t, void* location) { return location; }
namespace audio {
struct ListenerEffectGc {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void FUN_0025e6f0(void*);
};
struct ListenerEffectGcType {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual ListenerEffectGc* vfunc_2();
    virtual void vfunc_3();
};
}
struct Registry {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
};
extern Registry DAT_004e64d8;
extern "C" audio::ListenerEffectGc* __cdecl FUN_00247530(void*);
struct Result { void FUN_0025fb00(audio::ListenerEffectGc*); };
audio::ListenerEffectGc* audio::ListenerEffectGcType::vfunc_2() {
    ListenerEffectGc* effect = FUN_00247530(&DAT_004e64d8);
    if (!effect) return 0;
    effect->FUN_0025e6f0(&DAT_004e64d8);
    new (effect) ListenerEffectGc;
    Registry* registry = &DAT_004e64d8;
    Result* result = (Result*)registry->vfunc_3();
    result->FUN_0025fb00(effect);
    return effect;
}