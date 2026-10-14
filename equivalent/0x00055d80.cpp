// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00055d80 @ 0x00055d80
class CAlertStatusCondition;
class CCharacterSizeCondition;
class CCharacterTemplateCondition;
class CCharacterTemplateVariationCondition;
class CClimbEdgeCondition;
class CClimbableCondition;
class CFightNodeCondition;
class CFightNodeParentCondition;
class CFightNodePrevCondition;
class CFightNodeTimeCondition;
class CGrappleAlertStatusCondition;
class CGrappleCharacterTemplateCondition;
class CGrappleFightNodeCondition;
class CGrappleFightNodeParentCondition;
class CGrappleFightNodeTimeCondition;
class CGrappleMotionStateCondition;
class CGrappleSizeCondition;
class CGrappleTimerCondition;
class CGroundDistanceCondition;
class CInactivityTimerCondition;
class CIntentionSpeedCondition;
class CIsGrappledCondition;
class CIsHelicopterCondition;
class CIsInvincibleCondition;
class CLuaNumberCondition;
class CMotionClimbAngleCondition;
class CMotionHitCondition;
class CMotionStateCondition;
class CNameFlagCondition;
class CPropActorStateCondition;
class CRageModeCondition;
class CSmartPropAngleCondition;
class CSmartPropAttachedCondition;
class CSmartPropCSMableCondition;
class CSmartPropDistanceCondition;
class CSmartPropGrabbableNameCondition;
class CSmartPropNameCondition;
class CSmartPropStateCondition;
class CSmartPropTypeCondition;
class CSmartPropWeaponTypeCondition;
class CSmartPropWeaponizableTypeCondition;
class CStageCondition;
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void Create();
};
}
struct Registry {
    void FUN_00236760(void*);
    void FUN_002363f0();
};
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CCharacterSizeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CCharacterTemplateCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CClimbEdgeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CClimbableCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CFightNodeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CFightNodeParentCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CFightNodePrevCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CFightNodeTimeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGrappleTimerCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CGroundDistanceCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CIntentionSpeedCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CIsGrappledCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CLuaNumberCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CMotionHitCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CMotionStateCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CNameFlagCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CPropActorStateCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CRageModeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropNameCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropTypeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CStageCondition>*);
extern void __cdecl FUN_001138a0(Registry*, const char*);
extern void __cdecl FUN_001138d0(Registry*, const char*);
extern void __cdecl FUN_00113900(Registry*, const char*);
extern void __cdecl FUN_00113930(Registry*, const char*);
extern void __cdecl FUN_00113990(Registry*, const char*);
extern void __cdecl FUN_001139f0(Registry*, const char*);
extern void __cdecl FUN_00113a20(Registry*, const char*);
extern void __cdecl FUN_00113a50(Registry*, const char*);
extern void __cdecl FUN_00113a80(Registry*, const char*);
extern void __cdecl FUN_00113ab0(Registry*, const char*);
extern void __cdecl FUN_00113ae0(Registry*, const char*);
extern void __cdecl FUN_00113b10(Registry*, const char*);
extern void __cdecl FUN_00113b40(Registry*, const char*);
extern void __cdecl FUN_00113b70(Registry*, const char*);
extern void __cdecl FUN_0011a980(Registry*, const char*);
extern void __cdecl FUN_0011a9b0(Registry*, const char*);
extern void __cdecl FUN_0011a9e0(Registry*, const char*);
extern void __cdecl FUN_0011aa10(Registry*, const char*);
extern void __cdecl FUN_00122b70(Registry*, const char*);
extern void __cdecl FUN_00129fe0(Registry*);
extern void __cdecl FUN_0012d450(Registry*);
extern void __cdecl FUN_00132620(Registry*);
extern void __cdecl FUN_0013d3c0(Registry*);
extern void __cdecl FUN_00142910(Registry*);
extern void __cdecl FUN_0014bb60(Registry*);
extern void __cdecl FUN_00158c20(Registry*);
extern void __cdecl FUN_00163a20(Registry*);
extern void __cdecl FUN_0016cea0(Registry*);
extern void __cdecl FUN_0018b310(Registry*);
extern void __cdecl FUN_0018e860(Registry*);
extern void __cdecl FUN_0019e3e0(Registry*);
extern void __cdecl FUN_001a1cf0(Registry*, const char*);
extern void __cdecl FUN_00236940(Registry*);
bool __cdecl FUN_00055d80(Registry* registry) {
    FUN_00236940(registry);
    FUN_00132620(registry);
    FUN_001138a0(registry, "on_blocked_triangle");
    FUN_001139f0(registry, "leashed");
    FUN_00129fe0(registry);
    FUN_0012d450(registry);
    FUN_001138d0(registry, "aiFightNodeParent");
    FUN_00113930(registry, "ai_history_name");
    FUN_00113a50(registry, "formation_ready");
    FUN_00113a20(registry, "keyWordWait");
    FUN_00113b10(registry, "randomKeyWordWait");
    FUN_00113b40(registry, "token");
    FUN_00113a80(registry, "inactive");
    FUN_00113900(registry, "defending");
    FUN_00113ab0(registry, "hulk_action_count");
    FUN_0011a9e0(registry, "computeDropZone");
    FUN_0011a980(registry, "hasGroundPoint");
    FUN_0011aa10(registry, "hasGroundPointExtended");
    FUN_00113b70(registry, "fighting_other_NPC");
    FUN_00113ae0(registry, "props_to_suck");
    FUN_00113990(registry, "props_to_chuck");
    FUN_0016cea0(registry);
    FUN_00142910(registry);
    FUN_0018b310(registry);
    FUN_0018e860(registry);
    FUN_0013d3c0(registry);
    FUN_00163a20(registry);
    FUN_0014bb60(registry);
    FUN_00158c20(registry);
    FUN_0019e3e0(registry);
    FUN_0011a9b0(registry, "locatorDistance");
    FUN_00122b70(registry, "pathLocatorTest");
    FUN_001a1cf0(registry, "lua");
    {
        fight::ConditionFactoryCasterTemplate<CAlertStatusCondition> caster;
        registry->FUN_00236760(FUN_002343e0("alertStatus", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCharacterSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("characterSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCharacterTemplateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("characterTemplate", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition> caster;
        registry->FUN_00236760(FUN_002343e0("characterTemplateVariation", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CClimbableCondition> caster;
        registry->FUN_00236760(FUN_002343e0("climbable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CClimbEdgeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("climbEdge", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("fightNode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodeParentCondition> caster;
        registry->FUN_00236760(FUN_002343e0("fightNodeParent", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodePrevCondition> caster;
        registry->FUN_00236760(FUN_002343e0("fightNodePrevious", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodeTimeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("fightNodeTime", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleAlertStatus", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleCharacterTemplate", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleFightNode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleFightNodeParent", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleFightNodeTime", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleMotionStateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleMotionState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleTimerCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grappleTimer", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGroundDistanceCondition> caster;
        registry->FUN_00236760(FUN_002343e0("groundDistance", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition> caster;
        registry->FUN_00236760(FUN_002343e0("inactivityTimer", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIntentionSpeedCondition> caster;
        registry->FUN_00236760(FUN_002343e0("intentionSpeed", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIsGrappledCondition> caster;
        registry->FUN_00236760(FUN_002343e0("isGrappled", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition> caster;
        registry->FUN_00236760(FUN_002343e0("isHelicopter", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition> caster;
        registry->FUN_00236760(FUN_002343e0("isInvincible", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CLuaNumberCondition> caster;
        registry->FUN_00236760(FUN_002343e0("luaNumber", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition> caster;
        registry->FUN_00236760(FUN_002343e0("motionClimbAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CMotionHitCondition> caster;
        registry->FUN_00236760(FUN_002343e0("motionHit", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CMotionStateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("motionState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CNameFlagCondition> caster;
        registry->FUN_00236760(FUN_002343e0("nameFlag", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CPropActorStateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propActorState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CRageModeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("rageMode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropAttached", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropCSMable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropDistance", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropGrabbableName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropWeaponizableType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropWeaponType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CStageCondition> caster;
        registry->FUN_00236760(FUN_002343e0("stage", &caster));
    }
    registry->FUN_002363f0();
    return true;
}
