// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0016cea0 @ 0x0016cea0
namespace hulkfight { namespace motion { class RayCastCondition; class RayCastConeCondition; class RayCastTargetCondition; class TargetCharacterTemplateCondition; class CharacterPropStatusCondition; class TargetHealthPercentCondition; class VelocityCondition; class VelocityYCondition; class VelocityXZCondition; class VelocityXZAngleCondition; class VelocityAnimatedCondition; class VelocityAnimatedYCondition; class VelocityAnimatedXZCondition; class VelocityAnimatedXZAngleCondition; class ChargeCondition; class TurningVelocityCondition; class IntentionButtonDownAnyCondition; class IntentionInputCondition; class TargetingCondition; class TargetMotionStateCondition; class LocomotionMotionStateCondition; class TargetLocomotionMotionStateCondition; class ThinkingCondition; class HealthCondition; class GrappleHealthCondition; class GrappleReactionTypeCondition; class HealthPercentCondition; class InLoadedRoomCondition; class ShoreNearCondition; class RageModeStateCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_16cea0 { void FUN_00236760(void*); };
void* __cdecl FUN_002343e0(const char*, void*);
void __cdecl FUN_0016cea0(Registry_16cea0* r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition> caster;
        r->FUN_00236760(FUN_002343e0("rayCast", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastConeCondition> caster;
        r->FUN_00236760(FUN_002343e0("rayCastCone", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition> caster;
        r->FUN_00236760(FUN_002343e0("rayCastTarget", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetCharacterTemplateCondition> caster;
        r->FUN_00236760(FUN_002343e0("targetCharacterTemplate", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CharacterPropStatusCondition> caster;
        r->FUN_00236760(FUN_002343e0("characterPropStatus", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition> caster;
        r->FUN_00236760(FUN_002343e0("targetHealthPercent", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocity", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityYCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocityY", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocityXZ", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZAngleCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocityXZAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocityAnimated", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedYCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocityAnimatedY", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocityAnimatedXZ", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition> caster;
        r->FUN_00236760(FUN_002343e0("velocityAnimatedXZAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition> caster;
        r->FUN_00236760(FUN_002343e0("charge", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition> caster;
        r->FUN_00236760(FUN_002343e0("turningVelocity", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionButtonDownAnyCondition> caster;
        r->FUN_00236760(FUN_002343e0("intentionButtonDownAny", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::IntentionInputCondition> caster;
        r->FUN_00236760(FUN_002343e0("intentionInput", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetingCondition> caster;
        r->FUN_00236760(FUN_002343e0("targeting", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetMotionStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("targetMotionState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotionMotionStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("locomotionState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("targetLocomotionState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition> caster;
        r->FUN_00236760(FUN_002343e0("thinking", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthCondition> caster;
        r->FUN_00236760(FUN_002343e0("health", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleHealthCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleHealth", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleReactionTypeCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleReactionType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition> caster;
        r->FUN_00236760(FUN_002343e0("healthPercent", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::InLoadedRoomCondition> caster;
        r->FUN_00236760(FUN_002343e0("inLoadedRoom", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::ShoreNearCondition> caster;
        r->FUN_00236760(FUN_002343e0("shoreNear", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition> caster;
        r->FUN_00236760(FUN_002343e0("rageModeState", &caster));
    }
}
