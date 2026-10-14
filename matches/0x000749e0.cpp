namespace fight {
template <class T> struct TrackFactoryCasterTemplate {
    virtual void cast();
};
} // namespace fight
class CHapticTrack;
struct Registry {
    void FUN_002367c0(void*);
    void FUN_00236400();
};
extern void __cdecl FUN_002369c0(Registry*);
extern void __cdecl FUN_0012de00(Registry*, const char*);
extern void __cdecl FUN_00132530(Registry*, const char*);
extern void __cdecl FUN_00132500(Registry*, const char*);
extern void __cdecl FUN_001325c0(Registry*, const char*);
extern void __cdecl FUN_001324d0(Registry*, const char*);
extern void __cdecl FUN_00132590(Registry*, const char*);
extern void __cdecl FUN_001325f0(Registry*, const char*);
extern void __cdecl FUN_001a1d20(Registry*, const char*);
extern void __cdecl FUN_001a9a90(Registry*, const char*);
extern void __cdecl FUN_001a97d0(Registry*, const char*);
extern void __cdecl FUN_00146130(Registry*, const char*);
extern void __cdecl FUN_001463a0(Registry*, const char*);
extern void* __cdecl FUN_00236ac0(const char*, fight::TrackFactoryCasterTemplate<CHapticTrack>*);
bool __cdecl FUN_000749e0(Registry* registry) {
    FUN_002369c0(registry);
    FUN_0012de00(registry, "postEvent_string");
    FUN_00132530(registry, "dialogue");
    FUN_00132500(registry, "nisSound");
    FUN_001325c0(registry, "stat");
    FUN_001324d0(registry, "statBeginTrial");
    FUN_00132590(registry, "statEndTrial");
    FUN_001325f0(registry, "xp");
    FUN_001a1d20(registry, "lua");
    FUN_001a9a90(registry, "nisAnimation");
    FUN_001a97d0(registry, "effect");
    FUN_00146130(registry, "effectSlowMotion");
    FUN_001463a0(registry, "effectMotionBlur");
    fight::TrackFactoryCasterTemplate<CHapticTrack> caster;
    registry->FUN_002367c0(FUN_00236ac0("rumble", &caster));
    registry->FUN_00236400();
    return true;
}