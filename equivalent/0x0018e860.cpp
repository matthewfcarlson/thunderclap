// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0018e860 @ 0x0018e860
namespace hulkfight { namespace motion { class VarCompareCondition; class GrappleVarCompareCondition; class TimerCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry { void FUN_00236760(void *factory); };
void *__cdecl FUN_002343e0(const char *name, void *caster);

void __cdecl FUN_0018e860(Registry *r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::VarCompareCondition> caster;
        r->FUN_00236760(FUN_002343e0("varCompare", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleVarCompareCondition> caster;
        r->FUN_00236760(FUN_002343e0("grappleVarCompare", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::TimerCondition> caster;
        r->FUN_00236760(FUN_002343e0("timer", &caster));
    }
}
