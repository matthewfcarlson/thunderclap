// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0014bb60 @ 0x0014bb60
namespace hulkfight { namespace motion { class GrappleAttachJointCondition; class GrappleAttachedCondition; class CivilianAttachedCondition; class CivilianTargetCondition; class GrappleOrientationCondition; } }
namespace fight {
template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); };
}
extern void* __cdecl FUN_002343e0(const char*, void*);
struct Registry { void FUN_00236760(void*); };
void __cdecl FUN_0014bb60(Registry* registry) {
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleOrientationCondition> orientation;
 registry->FUN_00236760(FUN_002343e0("grappleOrientation", &orientation));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachJointCondition> joint;
 registry->FUN_00236760(FUN_002343e0("grappleAttachJoint", &joint));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachedCondition> attached;
 registry->FUN_00236760(FUN_002343e0("grappleAttached", &attached));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition> civilian;
 registry->FUN_00236760(FUN_002343e0("civilianAttached", &civilian));
 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianTargetCondition> target;
 registry->FUN_00236760(FUN_002343e0("civilianTarget", &target));
}