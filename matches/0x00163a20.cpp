// FUN_00163a20 @ 0x00163a20
namespace hulkfight { namespace motion { class PhaseCondition; class JointPlantedCondition; class LocomotingCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_163a20 { void FUN_00236760(void *factory); };
void *__cdecl FUN_002343e0(const char *name, void *caster);

void __cdecl FUN_00163a20(Registry_163a20 *r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::PhaseCondition> caster;
        r->FUN_00236760(FUN_002343e0("phase", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::JointPlantedCondition> caster;
        r->FUN_00236760(FUN_002343e0("jointPlanted", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition> caster;
        r->FUN_00236760(FUN_002343e0("locomoting", &caster));
    }
}
