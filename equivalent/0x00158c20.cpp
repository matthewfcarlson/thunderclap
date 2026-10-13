// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00158c20 @ 0x00158c20
namespace hulkfight { namespace motion {
class InterruptAccumulatorCondition;
class CollisionInterruptPriorityCondition;
class CollisionSourceTypeCondition;
class CollisionSourceNameCondition;
class CollisionTargetNameCondition;
class CollisionSourceIsMissileCondition;
class CollisionSourceNodeCondition;
class CollisionSourceForceMagnitudeCondition;
class CollisionTargetPriorityCondition;
class CollisionTargetIsTargetCondition;
class CollisionTargetTypeCondition;
class CollisionSourceSizeCondition;
class CollisionTargetSizeCondition;
class HitPushbackCondition;
class HitPushbackVelocityCondition;
class CollisionChargeCondition;
class CollisionDamageHealthCompareCondition;
class CollisionThrowCondition;
class CollisionThrownObjectCondition;
class CollisionExplosionCondition;
class CollisionDevastatorCondition;
} }
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void Create();
};
}
struct Registry {
    void FUN_00236760(void*);
};
extern void* __cdecl FUN_002343e0(const char*, void*);
void __cdecl FUN_00158c20(Registry* registry) {
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition> caster;
        registry->FUN_00236760(FUN_002343e0("interruptAccumulator", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionInterruptPriority", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceIsMissileCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceIsMissile", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceNode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceForceMagnitude", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetPriority", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetIsTarget", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition> caster;
        registry->FUN_00236760(FUN_002343e0("hitPushback", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("hitPushbackVelocity", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionCharge", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionDamageHealthCompare", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionThrow", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionThrownObject", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionExplosion", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionDevastator", &caster));
    }
}
