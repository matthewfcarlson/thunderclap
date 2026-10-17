// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::ListenerEffectPspType::vfunc_2 @ 0x0024dc50
namespace audio { struct ListenerEffectPsp; }
struct ConfigResult { void FUN_0025fb00(audio::ListenerEffectPsp*); };
namespace om { struct Type { virtual void vfunc_0(); virtual void vfunc_1(); virtual void* vfunc_2(); virtual ConfigResult* vfunc_3(); }; }
extern char DAT_004e6628;
void* __cdecl FUN_00247530(void*);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
namespace audio {
struct ListenerEffectPsp { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); void FUN_0025e6f0(void*); };
struct ListenerEffectPspType : om::Type { virtual void* vfunc_2(); virtual ConfigResult* vfunc_3(); };
void* ListenerEffectPspType::vfunc_2() {
    ListenerEffectPsp* obj = (ListenerEffectPsp*)FUN_00247530(&DAT_004e6628);
    if (!obj) return 0;
    obj->FUN_0025e6f0(&DAT_004e6628);
    new (obj) ListenerEffectPsp;
    om::Type* config = (om::Type*)(void*)&DAT_004e6628;
    ConfigResult* result = config->vfunc_3();
    result->FUN_0025fb00(obj);
    return obj;
}
}