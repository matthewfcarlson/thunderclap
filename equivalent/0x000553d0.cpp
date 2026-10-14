// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000553d0 @ 0x000553d0
class CAlertStatusCondition;
class CAxisArcCondition;
class CAxisDirectionCondition;
class CAxisDoubleTapCondition;
class CAxisDownCondition;
class CAxisPressCondition;
class CAxisReleaseCondition;
class CAxisSpeedCondition;
class CAxisUpCondition;
class CButtonDownCondition;
class CButtonPressCondition;
class CButtonReleaseCondition;
class CButtonUpCondition;
class CCharacterSizeCondition;
class CCharacterTemplateCondition;
class CCharacterTemplateVariationCondition;
class CClimbEdgeCondition;
class CClimbableCondition;
class CCollisionDirectionCondition;
class CCollisionFlagCondition;
class CCollisionHeightCondition;
class CCollisionHitLocationCondition;
class CCollisionInterruptCondition;
class CCollisionPushbackDirectionCondition;
class CCollisionPushbackVelocityCondition;
class CCollisionPushbackYAngleCondition;
class CCollisionPushbackYCondition;
class CCollisionStunTimeCondition;
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
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_553d0 { void FUN_00236760(void*); void FUN_002363f0(); };
void* __cdecl FUN_002343e0(const char*, void*);
void __cdecl FUN_00236940(Registry_553d0*);
void __cdecl FUN_00132620(Registry_553d0*);
void __cdecl FUN_001138d0(Registry_553d0*, const char*);
void __cdecl FUN_00113a20(Registry_553d0*, const char*);
void __cdecl FUN_00113b10(Registry_553d0*, const char*);
void __cdecl FUN_00113b40(Registry_553d0*, const char*);
void __cdecl FUN_00113ab0(Registry_553d0*, const char*);
void __cdecl FUN_001139f0(Registry_553d0*, const char*);
void __cdecl FUN_00129fe0(Registry_553d0*);
void __cdecl FUN_0012d450(Registry_553d0*);
void __cdecl FUN_00113900(Registry_553d0*, const char*);
void __cdecl FUN_00113a80(Registry_553d0*, const char*);
void __cdecl FUN_00113b70(Registry_553d0*, const char*);
void __cdecl FUN_00113ae0(Registry_553d0*, const char*);
void __cdecl FUN_00113990(Registry_553d0*, const char*);
void __cdecl FUN_0016cea0(Registry_553d0*);
void __cdecl FUN_00142910(Registry_553d0*);
void __cdecl FUN_0018b310(Registry_553d0*);
void __cdecl FUN_0018e860(Registry_553d0*);
void __cdecl FUN_0013d3c0(Registry_553d0*);
void __cdecl FUN_00163a20(Registry_553d0*);
void __cdecl FUN_0014bb60(Registry_553d0*);
void __cdecl FUN_00158c20(Registry_553d0*);
void __cdecl FUN_0019e3e0(Registry_553d0*);
void __cdecl FUN_0011a9b0(Registry_553d0*, const char*);
void __cdecl FUN_0011a9e0(Registry_553d0*, const char*);
void __cdecl FUN_0011a980(Registry_553d0*, const char*);
void __cdecl FUN_0011aa10(Registry_553d0*, const char*);
void __cdecl FUN_001a1cf0(Registry_553d0*, const char*);
bool __cdecl FUN_000553d0(Registry_553d0* r)
{
    FUN_00236940(r);
    FUN_00132620(r);
    FUN_001138d0(r, "aiFightNodeParent");
    FUN_00113a20(r, "keyWordWait");
    FUN_00113b10(r, "randomKeyWordWait");
    FUN_00113b40(r, "token");
    FUN_00113ab0(r, "hulk_action_count");
    FUN_001139f0(r, "leashed");
    FUN_00129fe0(r);
    FUN_0012d450(r);
    FUN_00113900(r, "defending");
    FUN_00113ab0(r, "hulk_action_count");
    FUN_00113a80(r, "inactive");
    FUN_00113b70(r, "fighting_other_NPC");
    FUN_00113ae0(r, "props_to_suck");
    FUN_00113990(r, "props_to_chuck");
    FUN_0016cea0(r);
    FUN_00142910(r);
    FUN_0018b310(r);
    FUN_0018e860(r);
    FUN_0013d3c0(r);
    FUN_00163a20(r);
    FUN_0014bb60(r);
    FUN_00158c20(r);
    FUN_0019e3e0(r);
    FUN_0011a9b0(r, "locatorDistance");
    FUN_0011a9e0(r, "computeDropZone");
    FUN_0011a980(r, "hasGroundPoint");
    FUN_0011aa10(r, "hasGroundPointExtended");
    FUN_001a1cf0(r, "lua");
    {
        fight::ConditionFactoryCasterTemplate<CAlertStatusCondition> caster;
        r->FUN_00236760(FUN_002343e0("alertStatus", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisArcCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisArc", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisDirectionCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisDirection", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisDoubleTapCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisDoubleTap", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisDownCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisDown", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisPressCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisPress", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisReleaseCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisRelease", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisSpeedCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisSpeed", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CAxisUpCondition> caster;
        r->FUN_00236760(FUN_002343e0("axisUp", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CButtonDownCondition> caster;
        r->FUN_00236760(FUN_002343e0("buttonDown", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CButtonPressCondition> caster;
        r->FUN_00236760(FUN_002343e0("buttonPress", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CButtonReleaseCondition> caster;
        r->FUN_00236760(FUN_002343e0("buttonRelease", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CButtonUpCondition> caster;
        r->FUN_00236760(FUN_002343e0("buttonUp", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCharacterSizeCondition> caster;
        r->FUN_00236760(FUN_002343e0("characterSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCharacterTemplateCondition> caster;
        r->FUN_00236760(FUN_002343e0("characterTemplate", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition> caster;
        r->FUN_00236760(FUN_002343e0("characterTemplateVariation", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CClimbableCondition> caster;
        r->FUN_00236760(FUN_002343e0("climbable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CClimbEdgeCondition> caster;
        r->FUN_00236760(FUN_002343e0("climbEdge", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionDirectionCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionDirection", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionFlagCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionFlag", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionHeightCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionHeight", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionHitLocationCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionHitLocation", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionInterruptCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionInterrupt", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionPushbackDirection", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionPushbackVelocityCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionPushbackVelocity", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionPushbackYCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionPushbackY", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionPushbackYAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CCollisionStunTimeCondition> caster;
        r->FUN_00236760(FUN_002343e0("collisionStunTime", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodeCondition> caster;
        r->FUN_00236760(FUN_002343e0("fightNode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodeParentCondition> caster;
        r->FUN_00236760(FUN_002343e0("fightNodeParent", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodePrevCondition> caster;
        r->FUN_00236760(FUN_002343e0("fightNodePrevious", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CFightNodeTimeCondition> caster;
        r->FUN_00236760(FUN_002343e0("fightNodeTime", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleAlertStatus", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleCharacterTemplate", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleFightNode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleFightNodeParent", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleFightNodeTime", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleMotionStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleMotionState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGrappleTimerCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleTimer", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CGroundDistanceCondition> caster;
        r->FUN_00236760(FUN_002343e0("groundDistance", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition> caster;
        r->FUN_00236760(FUN_002343e0("inactivityTimer", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIntentionSpeedCondition> caster;
        r->FUN_00236760(FUN_002343e0("intentionSpeed", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIsGrappledCondition> caster;
        r->FUN_00236760(FUN_002343e0("isGrappled", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition> caster;
        r->FUN_00236760(FUN_002343e0("isHelicopter", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition> caster;
        r->FUN_00236760(FUN_002343e0("isInvincible", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CLuaNumberCondition> caster;
        r->FUN_00236760(FUN_002343e0("luaNumber", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition> caster;
        r->FUN_00236760(FUN_002343e0("motionClimbAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CMotionHitCondition> caster;
        r->FUN_00236760(FUN_002343e0("motionHit", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CMotionStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("motionState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CNameFlagCondition> caster;
        r->FUN_00236760(FUN_002343e0("nameFlag", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CPropActorStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("propActorState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CRageModeCondition> caster;
        r->FUN_00236760(FUN_002343e0("rageMode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropAttached", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropCSMable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropDistance", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropGrabbableName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropNameCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropTypeCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropWeaponizableType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition> caster;
        r->FUN_00236760(FUN_002343e0("smartPropWeaponType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CStageCondition> caster;
        r->FUN_00236760(FUN_002343e0("stage", &caster));
    }
    r->FUN_002363f0();
    return true;
}
