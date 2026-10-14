class CLuaNumberCondition;
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void Create();
};
} // namespace fight
struct Registry_56460 {
    void FUN_00236760(void*);
    void FUN_002363f0();
};
extern void __cdecl FUN_00236940(Registry_56460*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CLuaNumberCondition>*);
extern void __cdecl FUN_00132620(Registry_56460*);
extern void __cdecl FUN_001ac340(Registry_56460*, const char*);
extern void __cdecl FUN_001ac460(Registry_56460*, const char*);
extern void __cdecl FUN_001ac220(Registry_56460*, const char*);
extern void __cdecl FUN_001a94a0(Registry_56460*, const char*);
extern void __cdecl FUN_001a9560(Registry_56460*, const char*);
extern void __cdecl FUN_001a9740(Registry_56460*, const char*);
extern void __cdecl FUN_001a96b0(Registry_56460*, const char*);
extern void __cdecl FUN_001a95f0(Registry_56460*, const char*);
extern void __cdecl FUN_001a9620(Registry_56460*, const char*);
extern void __cdecl FUN_001a94d0(Registry_56460*, const char*);
extern void __cdecl FUN_001a95c0(Registry_56460*, const char*);
extern void __cdecl FUN_001a9590(Registry_56460*, const char*);
extern void __cdecl FUN_001a1cf0(Registry_56460*, const char*);
extern void __cdecl FUN_001ac2b0(Registry_56460*, const char*);
extern void __cdecl FUN_001ac580(Registry_56460*, const char*);
extern void __cdecl FUN_001ac310(Registry_56460*, const char*);
extern void __cdecl FUN_001ac2e0(Registry_56460*, const char*);
bool __cdecl FUN_00056460(Registry_56460* registry) {
    FUN_00236940(registry);
    fight::ConditionFactoryCasterTemplate<CLuaNumberCondition> caster;
    registry->FUN_00236760(FUN_002343e0("luaNumber", &caster));
    FUN_00132620(registry);
    FUN_001ac340(registry, "event_CharacterTemplate");
    FUN_001ac460(registry, "event_CharacterTemplateVariation");
    FUN_001ac220(registry, "event_TriggerVolumeName");
    FUN_001a94a0(registry, "nodeIsNotRunning");
    FUN_001a9560(registry, "nodeShouldRunImmediately");
    FUN_001a9740(registry, "event_PropName");
    FUN_001a96b0(registry, "event_PropStateName");
    FUN_001a95f0(registry, "event_PropStateDesc");
    FUN_001a9620(registry, "event_PropType");
    FUN_001a94d0(registry, "event_String");
    FUN_001a95c0(registry, "event_LocomotionStateName");
    FUN_001a9590(registry, "event_LocomotionStateNamePrevious");
    FUN_001a1cf0(registry, "lua");
    FUN_001ac2b0(registry, "event");
    FUN_001ac580(registry, "event_PathName");
    FUN_001ac310(registry, "event_Waypoint");
    FUN_001ac2e0(registry, "event_FirstTime");
    registry->FUN_002363f0();
    return true;
}
