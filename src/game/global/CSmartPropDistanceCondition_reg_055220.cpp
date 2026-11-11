// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00055220..0x00056af0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb762e08 {
#define TREE_TU_END }
namespace fn_fb762e08 {} using namespace fn_fb762e08;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb762e08 {
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};


// 0x00055220 fight::ParamNameConstList<CSmartPropDistanceCondition>::vfunc_7 (12 B): matches/0x00055220.cpp
// sym: ?vfunc_6@ParamBranch@fn_fb762e08@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fb762e08

// 0x00055250 fight::ParamName<CSmartPropGrabbableNameCondition>::vfunc_7 (12 B): matches/0x00055250.cpp [wrapped: same definition as 0x00055220 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00055250@@UAEXPAX@Z
namespace fn_00055250 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00055250


// 0x00055280 fight::ParamNameList<CCharacterTemplateCondition>::vfunc_7 (12 B): matches/0x00055280.cpp [wrapped: same definition as 0x00055220 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00055280@@UAEXPAX@Z
namespace fn_00055280 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00055280


// 0x000552b0 fight::ParamNameList<CCharacterTemplateVariationCondition>::vfunc_7 (12 B): matches/0x000552b0.cpp [wrapped: same definition as 0x00055220 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000552b0@@UAEXPAX@Z
namespace fn_000552b0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_000552b0


// 0x000552e0 fight::ParamNameList<CGrappleCharacterTemplateCondition>::vfunc_7 (12 B): matches/0x000552e0.cpp [wrapped: same definition as 0x00055220 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000552e0@@UAEXPAX@Z
namespace fn_000552e0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_000552e0


// 0x000552f0 fight::ParamName<CNameFlagConditionBase>::vfunc_0 (30 B): matches/0x000552f0.cpp
// sym: ??_G?$ParamName@VCNameFlagConditionBase@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CNameFlagConditionBase>::~ParamName() {}


// 0x00055310 fight::ParamName<CSmartPropNameCondition>::vfunc_0 (30 B): matches/0x00055310.cpp
// sym: ??_G?$ParamName@VCSmartPropNameCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CSmartPropNameCondition>::~ParamName() {}


// 0x00055330 fight::ParamNameConstList<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00055330.cpp
// sym: ??_G?$ParamNameConstList@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CSmartPropDistanceCondition>::~ParamNameConstList() {}


// 0x00055350 fight::ParamName<CSmartPropGrabbableNameCondition>::vfunc_0 (30 B): matches/0x00055350.cpp
// sym: ??_G?$ParamName@VCSmartPropGrabbableNameCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CSmartPropGrabbableNameCondition>::~ParamName() {}


// 0x00055370 fight::ParamNameList<CCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x00055370.cpp
// sym: ??_G?$ParamNameList@VCCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameList<CCharacterTemplateCondition>::~ParamNameList() {}


// 0x00055390 fight::ParamNameList<CCharacterTemplateVariationCondition>::vfunc_0 (30 B): matches/0x00055390.cpp
// sym: ??_G?$ParamNameList@VCCharacterTemplateVariationCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameList<CCharacterTemplateVariationCondition>::~ParamNameList() {}


// 0x000553b0 fight::ParamNameList<CGrappleCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x000553b0.cpp
// sym: ??_G?$ParamNameList@VCGrappleCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameList<CGrappleCharacterTemplateCondition>::~ParamNameList() {}


// 0x000553d0 FUN_000553d0 (2465 B): matches/0x000553d0.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_000553d0
namespace fn_000553d0 {
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
extern "C" void __cdecl FUN_001138d0(void *, void *);
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
extern "C" bool __cdecl FUN_000553d0(Registry_553d0* r)
{
    FUN_00236940(r);
    FUN_00132620(r);
    FUN_001138d0((Registry_553d0 *)r, (void *)(const char *)"aiFightNodeParent");
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
} // namespace fn_000553d0


// 0x00055d80 FUN_00055d80 (1753 B): matches/0x00055d80.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00055d80
namespace fn_00055d80 {
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
struct Registry_55d80 {
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
extern "C" void __cdecl FUN_001138a0(Registry_55d80*, const char*);
extern "C" void __cdecl FUN_001138d0(void *, void *);
extern void __cdecl FUN_00113900(Registry_55d80*, const char*);
extern "C" void __cdecl FUN_00113930(Registry_55d80*, const char*);
extern void __cdecl FUN_00113990(Registry_55d80*, const char*);
extern void __cdecl FUN_001139f0(Registry_55d80*, const char*);
extern void __cdecl FUN_00113a20(Registry_55d80*, const char*);
extern "C" void __cdecl FUN_00113a50(Registry_55d80*, const char*);
extern void __cdecl FUN_00113a80(Registry_55d80*, const char*);
extern void __cdecl FUN_00113ab0(Registry_55d80*, const char*);
extern void __cdecl FUN_00113ae0(Registry_55d80*, const char*);
extern void __cdecl FUN_00113b10(Registry_55d80*, const char*);
extern void __cdecl FUN_00113b40(Registry_55d80*, const char*);
extern void __cdecl FUN_00113b70(Registry_55d80*, const char*);
extern void __cdecl FUN_0011a980(Registry_55d80*, const char*);
extern void __cdecl FUN_0011a9b0(Registry_55d80*, const char*);
extern void __cdecl FUN_0011a9e0(Registry_55d80*, const char*);
extern void __cdecl FUN_0011aa10(Registry_55d80*, const char*);
extern "C" void __cdecl FUN_00122b70(Registry_55d80*, const char*);
extern void __cdecl FUN_00129fe0(Registry_55d80*);
extern void __cdecl FUN_0012d450(Registry_55d80*);
extern void __cdecl FUN_00132620(Registry_55d80*);
extern void __cdecl FUN_0013d3c0(Registry_55d80*);
extern void __cdecl FUN_00142910(Registry_55d80*);
extern void __cdecl FUN_0014bb60(Registry_55d80*);
extern void __cdecl FUN_00158c20(Registry_55d80*);
extern void __cdecl FUN_00163a20(Registry_55d80*);
extern void __cdecl FUN_0016cea0(Registry_55d80*);
extern void __cdecl FUN_0018b310(Registry_55d80*);
extern void __cdecl FUN_0018e860(Registry_55d80*);
extern void __cdecl FUN_0019e3e0(Registry_55d80*);
extern void __cdecl FUN_001a1cf0(Registry_55d80*, const char*);
extern void __cdecl FUN_00236940(Registry_55d80*);
extern "C" bool __cdecl FUN_00055d80(Registry_55d80* registry) {
    FUN_00236940(registry);
    FUN_00132620(registry);
    FUN_001138a0(registry, "on_blocked_triangle");
    FUN_001139f0(registry, "leashed");
    FUN_00129fe0(registry);
    FUN_0012d450(registry);
    FUN_001138d0((Registry_55d80 *)registry, (void *)(const char *)"aiFightNodeParent");
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
} // namespace fn_00055d80


// 0x00056460 FUN_00056460 (260 B): matches/0x00056460.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00056460
namespace fn_00056460 {
class CLuaNumberCondition;
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void Create();
};
} // namespace fight
struct Registry_56460 {
    void FUN_00236760(void*);
    void FUN_002363f0();
};
extern void __cdecl FUN_00236940(Registry_56460*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CLuaNumberCondition>*);
extern void __cdecl FUN_00132620(Registry_56460*);
extern "C" void __cdecl FUN_001ac340(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001ac460(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001ac220(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a94a0(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a9560(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a9740(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a96b0(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a95f0(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a9620(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a94d0(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a95c0(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001a9590(Registry_56460*, const char*);
extern void __cdecl FUN_001a1cf0(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001ac2b0(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001ac580(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001ac310(Registry_56460*, const char*);
extern "C" void __cdecl FUN_001ac2e0(Registry_56460*, const char*);
extern "C" bool __cdecl FUN_00056460(Registry_56460* registry) {
    FUN_00236940(registry);
    fight::ConditionFactoryCasterTemplate<CLuaNumberCondition> caster;
    registry->FUN_00236760(FUN_002343e0("luaNumber", &caster));
    FUN_00132620(registry);
    FUN_001ac340(registry, "event_CharacterTemplate");
    FUN_001ac460(registry, "event_CharacterTemplateVariation");
    FUN_001ac220(registry, "event_TriggerVolumeName");
    FUN_001a94a0(registry, "nodeIsNotRunning");
    FUN_001a9560(registry, "nodeShouldRunImmediately");
    FUN_001a9740(registry, "event_PropName");
    FUN_001a96b0(registry, "event_PropStateName");
    FUN_001a95f0(registry, "event_PropStateDesc");
    FUN_001a9620(registry, "event_PropType");
    FUN_001a94d0(registry, "event_String");
    FUN_001a95c0(registry, "event_LocomotionStateName");
    FUN_001a9590(registry, "event_LocomotionStateNamePrevious");
    FUN_001a1cf0(registry, "lua");
    FUN_001ac2b0(registry, "event");
    FUN_001ac580(registry, "event_PathName");
    FUN_001ac310(registry, "event_Waypoint");
    FUN_001ac2e0(registry, "event_FirstTime");
    registry->FUN_002363f0();
    return true;
}
} // namespace fn_00056460


// 0x00056620 FUN_00056620 (231 B): equivalent/0x00056620.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamIntConstRange; fight::ParamName]
// sym: ?target@fn_00056620@@YAXXZ @6c8a472bc475 @w2d94e896f50a
inline void* operator new(size_t,void* p) { return p; }
namespace fn_00056620 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_00056620 @ 0x00056620


namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; void* list; int count; void (*callback)(); int extra; void FUN_00234cc0(const char*); };
template<class T> struct ParamName { virtual void slot0(); char pad[12]; void (*callback)(); int extra; void FUN_00234a90(const char*); };
template<class T> struct ParamIntConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int extra; void FUN_002348e0(const char*); };
}
class CSmartPropNameCondition;
   
void SetCompare_00047e90(); void GetName_00047ea0(); void SetAttachmentIndex_00047eb0();
void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_002347b0(void*,void**,int);
void target() {
 if (!DAT_004dc4c4) {
 void* params[3];
 fight::ParamEnumConstList<CSmartPropNameCondition>* a = (fight::ParamEnumConstList<CSmartPropNameCondition>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CSmartPropNameCondition>));
 if(a) { int count=(*(int*)&DAT_00427760); a->FUN_00234cc0("compare"); a->count=count; new (a) fight::ParamEnumConstList<CSmartPropNameCondition>; a->list=((int*)&DAT_00427758); a->callback=SetCompare_00047e90; }
 params[0]=a;
 fight::ParamName<CSmartPropNameCondition>* b=(fight::ParamName<CSmartPropNameCondition>*)FUN_0008d690((int)sizeof(fight::ParamName<CSmartPropNameCondition>));
 if(b) { b->FUN_00234a90("name"); new (b) fight::ParamName<CSmartPropNameCondition>; b->callback=GetName_00047ea0; } params[1]=b;
 fight::ParamIntConstRange<CSmartPropNameCondition>* c=(fight::ParamIntConstRange<CSmartPropNameCondition>*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<CSmartPropNameCondition>));
 if(c) { c->FUN_002348e0("attachmentIndex"); new (c) fight::ParamIntConstRange<CSmartPropNameCondition>; c->callback=SetAttachmentIndex_00047eb0; } params[2]=c;
 FUN_002347b0(&DAT_004dc4c0,params,3);
 }
 ++DAT_004dc4c4;
}
} // namespace fn_00056620


// 0x00056710 FUN_00056710 (274 B): equivalent/0x00056710.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamFloatConstRange; fight::ParamNameConstList; fight::ParamVector]
// sym: ?target@fn_00056710@@YAXXZ @7c45722bf0c8 @w6a06e7073dac
namespace fn_00056710 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// FUN_00056710 @ 0x00056710

void* __cdecl FUN_0008d690(unsigned);

void __cdecl FUN_00047ee0();
void __cdecl FUN_00047ef0();
void __cdecl FUN_00047f00();
void __cdecl FUN_00047f10();
void __cdecl FUN_002347b0(void*,void**,int);
class CSmartPropDistanceCondition;
struct FUN_00234cc0 { virtual void slot(); char pad[12]; const char* values; int count; void (*callback)(); int extra; FUN_00234cc0(const char* = "compare"); };
struct FUN_00234960 { virtual void slot(); char pad[12]; void (*callback)(); int extra; FUN_00234960(const char* = "distance"); };
struct FUN_00234ba0 { virtual void slot(); char pad[12]; void (*callback)(); int extra; FUN_00234ba0(const char* = "joint"); };
struct FUN_00234e50 { virtual void slot(); char pad[12]; void (*callback)(); int extra; FUN_00234e50(const char* = "offset"); };
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot(); };
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot(); };
template<class T> struct ParamNameConstList : FUN_00234ba0 { virtual void slot(); };
template<class T> struct ParamVector : FUN_00234e50 { virtual void slot(); };
}
void __cdecl target() {
 if (!DAT_004dc4d4) {
 void* list[4];
 void* p=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CSmartPropDistanceCondition>));
 if(p) {
 int n=(*(int*)&DAT_00427754);
 fight::ParamEnumConstList<CSmartPropDistanceCondition>* a=new(p) fight::ParamEnumConstList<CSmartPropDistanceCondition>;
 a->count=n; a->values="lwB"; a->callback=FUN_00047ee0; list[0]=a;
 } else list[0]=0;
 p=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CSmartPropDistanceCondition>));
 if(p) { fight::ParamFloatConstRange<CSmartPropDistanceCondition>* a=new(p) fight::ParamFloatConstRange<CSmartPropDistanceCondition>; a->callback=FUN_00047ef0; list[1]=a; } else list[1]=0;
 p=FUN_0008d690((int)sizeof(fight::ParamNameConstList<CSmartPropDistanceCondition>));
 if(p) { fight::ParamNameConstList<CSmartPropDistanceCondition>* a=new(p) fight::ParamNameConstList<CSmartPropDistanceCondition>; a->callback=FUN_00047f00; list[2]=a; } else list[2]=0;
 p=FUN_0008d690((int)sizeof(fight::ParamVector<CSmartPropDistanceCondition>));
 if(p) { fight::ParamVector<CSmartPropDistanceCondition>* a=new(p) fight::ParamVector<CSmartPropDistanceCondition>; a->callback=FUN_00047f10; list[3]=a; } else list[3]=0;
 FUN_002347b0(&DAT_004dc4d0,list,4);
 }
 ++DAT_004dc4d4;
}
} // namespace fn_00056710

