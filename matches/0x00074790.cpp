struct Registry {
    void FUN_002367c0(void*);
    void FUN_00236400();
};
class CAlertStatusTrack;
class CEffectTrack;
class CEffectStopTrack;
class CIntangibleTrack;
class CUninterruptibleTrack;
namespace fight {
template <class T> struct TrackFactoryCasterTemplate {
    virtual void cast();
};
} // namespace fight
void* __cdecl FUN_00236ac0(const char*, void*);
void __cdecl FUN_002369c0(Registry*);
#define DECL(a) void __cdecl FUN_##a(Registry*, const char*);
DECL(0012de00)
DECL(00132530) DECL(00132500) DECL(00132560) DECL(001325c0) DECL(001324d0) DECL(00132590) DECL(001325f0)
    DECL(00129f80) DECL(00129fb0) DECL(00113c90) DECL(00122c00) DECL(00122c90) DECL(00122c60) DECL(00122c30)
        DECL(00122cc0) DECL(00122ba0) DECL(00122bd0) DECL(0012d2e0) DECL(00113cc0) DECL(00113c30)
            DECL(00113d20) DECL(00113ba0) DECL(00113c60) DECL(00113cf0) DECL(00113bd0) DECL(0017dd30)
                DECL(0017dcd0) DECL(0017d580) DECL(0018a0a0) DECL(0017d1b0) DECL(00158b30)
                    DECL(001a1d20) void __cdecl FUN_0011ae60(Registry*);
void __cdecl FUN_0010bf20(Registry*);
void __cdecl FUN_0018e8d0(Registry*);
bool __cdecl FUN_00074790(Registry* r) {
    FUN_002369c0(r);
    FUN_0012de00(r, "postEvent_string");
    FUN_00132530(r, "dialogue");
    FUN_00132500(r, "nisSound");
    FUN_00132560(r, "debugPrint");
    FUN_001325c0(r, "stat");
    FUN_001324d0(r, "statBeginTrial");
    FUN_00132590(r, "statEndTrial");
    FUN_001325f0(r, "xp");
    FUN_00129f80(r, "acquireTarget");
    FUN_00129fb0(r, "clearProjectileDistance");
    FUN_00113c90(r, "button");
    FUN_00122c00(r, "strafeRun");
    FUN_00122c90(r, "strafeCircle");
    FUN_00122c60(r, "strafeCircleHB");
    FUN_00122c30(r, "strafeLateralHB");
    FUN_00122cc0(r, "path");
    FUN_00122ba0(r, "rout");
    FUN_00122bd0(r, "pathFormation");
    FUN_0012d2e0(r, "threatDodge");
    FUN_0011ae60(r);
    FUN_0010bf20(r);
    FUN_00113cc0(r, "ai_history_set");
    FUN_00113c30(r, "hulk_action");
    FUN_00113d20(r, "semaphoreWait");
    FUN_00113ba0(r, "semaphoreClear");
    FUN_00113c60(r, "keywordWait");
    FUN_00113cf0(r, "token");
    FUN_00113bd0(r, "tokenSupress");
    FUN_0018e8d0(r);
    FUN_0017dd30(r, "teleportToLocator");
    FUN_0017dcd0(r, "teleportRelative");
    FUN_0017d580(r, "driftToPosition");
    FUN_0018a0a0(r, "propDrop");
    FUN_0017d1b0(r, "locomotionState");
    FUN_00158b30(r, "health");
    {
        fight::TrackFactoryCasterTemplate<CIntangibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("intangible", &caster));
    }
    FUN_001a1d20(r, "lua");
    {
        fight::TrackFactoryCasterTemplate<CAlertStatusTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("alertStatus", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CEffectTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("effect", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CEffectStopTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("effectStop", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CUninterruptibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("uninterruptible", &caster));
    }
    r->FUN_00236400();
    return true;
}