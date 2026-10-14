namespace hulkfight {
namespace motion {
class PropMissionCriticalCondition;
class SmartPropGrabbableCondition;
class GrapplePropStateByNameCondition;
class PropGrabbableIsThrownCondition;
class PropMassCondition;
class PropAtRestCondition;
class PropIsAttachedCondition;
class PropStateByNameCondition;
class PropStateByIndexCondition;
class PropMissileCountCondition;
class PropCollidedWithWorldCondition;
class SmartPropIsCargoCondition;
class CSMPropIsCharacterCondition;
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void create();
    virtual void cast();
    virtual void other();
};
} // namespace fight
extern void* __cdecl FUN_002343e0(const char*, void*);
struct Registry_18b310 {
    void* FUN_00236760(void*);
};
void* __cdecl FUN_0018b310(Registry_18b310* registry) {
    using namespace hulkfight::motion;
    {
        fight::ConditionFactoryCasterTemplate<PropAtRestCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propAtRest", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropStateByIndexCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propStateByIndex", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropStateByNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propStateByName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<GrapplePropStateByNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grapplePropStateByName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropIsAttachedCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propIsAttached", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSMPropIsCharacterCondition> caster;
        registry->FUN_00236760(FUN_002343e0("csmPropIsCharacter", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<SmartPropIsCargoCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropIsCargo", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<SmartPropGrabbableCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropGrabbable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropCollidedWithWorldCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propCollidedWithWorld", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMissileCountCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propMissileCount", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropGrabbableIsThrownCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propGrabbableIsThrown", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMissionCriticalCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propMissionCritical", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMassCondition> caster;
        return registry->FUN_00236760(FUN_002343e0("propMass", &caster));
    }
}
