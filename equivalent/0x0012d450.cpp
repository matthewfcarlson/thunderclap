// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0012d450 @ 0x0012d450
namespace hulkfight { namespace ai { class ThreatCondition; class ThreatDistanceCondition; class ThreatAngleCondition; class ShotFailCountCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry { void FUN_00236760(void*); };
void* __cdecl FUN_002343e0(const char*, void*);
void __cdecl FUN_0012d450(Registry* r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatCondition> caster;
        r->FUN_00236760(FUN_002343e0("threat", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatAngleCondition> caster;
        r->FUN_00236760(FUN_002343e0("threatAngle", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ThreatDistanceCondition> caster;
        r->FUN_00236760(FUN_002343e0("threatDistance", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::ShotFailCountCondition> caster;
        r->FUN_00236760(FUN_002343e0("shotFailCount", &caster));
    }
}
