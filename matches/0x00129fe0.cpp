namespace hulkfight {
namespace ai {
class HasTargetCondition;
class AcquireTargetCondition;
class TargetTypeCondition;
class TargetDistanceCondition;
class TargetDistanceXZCondition;
class TargetDistanceYCondition;
class TargetOrientationCondition;
class TargetArcCondition;
class TargetVelocityCondition;
class TargetVelocityXZCondition;
class TargetVelocityYCondition;
class TargetDirectionCondition;
class TargetDirectionXZCondition;
class TargetDirectionYCondition;
class TargetAngleYCondition;
class CanSeeTargetCondition;
class TargetInvincibleCondition;
class TargetFirstShotCondition;
class ProjectileDistanceCondition;
} // namespace ai
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    virtual void create();
};
} // namespace fight
extern void* __cdecl FUN_002343e0(const char*, void*);
struct Registry {
    void* FUN_00236760(void*);
};
void* __cdecl FUN_00129fe0(Registry* registry) {
#define REGISTER(TYPE, TEXT)                                                                                 \
    {                                                                                                        \
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::TYPE> caster;                                   \
        result = registry->FUN_00236760(FUN_002343e0(TEXT, &caster));                                        \
    }
    void* result;
    REGISTER(HasTargetCondition, "hasTarget")
    REGISTER(AcquireTargetCondition, "acquireTarget")
    REGISTER(TargetTypeCondition, "targetType")
    REGISTER(TargetDistanceCondition, "targetDistance")
    REGISTER(TargetDistanceXZCondition, "targetDistanceXZ")
    REGISTER(TargetDistanceYCondition, "targetDistanceY")
    REGISTER(TargetOrientationCondition, "targetOrientation")
    REGISTER(TargetArcCondition, "targetArc")
    REGISTER(TargetVelocityCondition, "targetVelocity")
    REGISTER(TargetVelocityXZCondition, "targetVelocityXZ")
    REGISTER(TargetVelocityYCondition, "targetVelocityY")
    REGISTER(TargetDirectionCondition, "targetDirection")
    REGISTER(TargetDirectionXZCondition, "targetDirectionXZ")
    REGISTER(TargetDirectionYCondition, "targetDirectionY")
    REGISTER(TargetAngleYCondition, "targetAngleY")
    REGISTER(CanSeeTargetCondition, "canSeeTarget")
    REGISTER(TargetInvincibleCondition, "targetInvincible")
    REGISTER(TargetFirstShotCondition, "targetFirstShot")
    REGISTER(ProjectileDistanceCondition, "projectileDistance")
    return result;
}
