// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00051480..0x00056af0 (kind game, layer game, confidence high), merged by D32: global/CStageCondition_params_factory.cpp
// piece 0x00055220..0x00056af0 (kind game, layer game, confidence low); was game/global/CSmartPropDistanceCondition_reg_055220.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/unknown.h"   // (gx3, D18) for the merged registrations
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/engine/fight.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb762e08 {
#define TREE_TU_END }
namespace fn_fb762e08 {} using namespace fn_fb762e08;
#include "game/global.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f64b1530 { struct C_47ef0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct C_47f10 { char Set(void const *); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47e90 { bool SetCompare_00047e90(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47ea0 { int * GetName_00047ea0(); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47eb0 { bool SetAttachmentIndex_00047eb0(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47ee0 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp
namespace fn_f64b1530 { struct Obj_47f00 { char * Get(); }; }   // (gx3, D18) setters, as defined in unk_047970.cpp

// ---- declarations shared by the functions below
namespace fn_fb762e08 {
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};


} // namespace fn_fb762e08

// 0x000517b0 fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_0 (30 B): matches/0x000517b0.cpp
// sym: ??_G?$ParamEnumConstList@VCNameFlagConditionBase@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CButtonCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)



// 0x00051a40 fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_0 (30 B): matches/0x00051a40.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropNameCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)



// 0x00051a60 fight::ParamIntConstRange<CSmartPropNameCondition>::vfunc_0 (30 B): matches/0x00051a60.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropNameCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropWeaponizableTypeCondition_params_0519a0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)



// 0x00051aa0 fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00051aa0.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropDistanceCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)



// 0x00051ac0 fight::ParamFloatConstRange<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00051ac0.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropDistanceCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)



// 0x00051af0 fight::ParamVector<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00051af0.cpp
// sym: ??_G?$ParamVector@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CSmartPropDistanceCondition_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)



// 0x00051b10 fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_0 (30 B): matches/0x00051b10.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropGrabbableNameCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CLuaNumberCondition_params_051b10.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)



// 0x00051c50 fight::ParamEnumConstList<CCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x00051c50.cpp
// sym: ??_G?$ParamEnumConstList@VCCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)

namespace fn_fb762e08 {


} // namespace fn_fb762e08

// 0x00051c70 fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_0 (30 B): matches/0x00051c70.cpp
// sym: ??_G?$ParamEnumConstList@VCCharacterTemplateVariationCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)

namespace fn_fb762e08 {


} // namespace fn_fb762e08

// 0x00051c90 fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x00051c90.cpp
// sym: ??_G?$ParamEnumConstList@VCGrappleCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CClimbableCondition_params_051c50.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00056570 / FUN_00056620 / FUN_00056710 / FUN_00056830 / FUN_000568e0 / FUN_00056990 / FUN_00056a40)

namespace fn_fb762e08 {


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
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00055310 fight::ParamName<CSmartPropNameCondition>::vfunc_0 (30 B): matches/0x00055310.cpp
// sym: ??_G?$ParamName@VCSmartPropNameCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00055330 fight::ParamNameConstList<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00055330.cpp
// sym: ??_G?$ParamNameConstList@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00055350 fight::ParamName<CSmartPropGrabbableNameCondition>::vfunc_0 (30 B): matches/0x00055350.cpp
// sym: ??_G?$ParamName@VCSmartPropGrabbableNameCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00055370 fight::ParamNameList<CCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x00055370.cpp
// sym: ??_G?$ParamNameList@VCCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00055390 fight::ParamNameList<CCharacterTemplateVariationCondition>::vfunc_0 (30 B): matches/0x00055390.cpp
// sym: ??_G?$ParamNameList@VCCharacterTemplateVariationCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x000553b0 fight::ParamNameList<CGrappleCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x000553b0.cpp
// sym: ??_G?$ParamNameList@VCGrappleCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


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
namespace fight {
// (sweep-caster-fix1) the caster as the word its inline constructor writes: the game's vftable by address, per T
// (a local polymorphic stand-in got clang's own vftable natively, whose slot had no definition)
extern "C" char DAT_003f81a8[];   // ConditionFactoryCasterTemplate<CAlertStatusCondition>'s vftable
extern "C" char DAT_003f81b4[];   // ConditionFactoryCasterTemplate<CAxisArcCondition>'s vftable
extern "C" char DAT_003f81c0[];   // ConditionFactoryCasterTemplate<CAxisDirectionCondition>'s vftable
extern "C" char DAT_003f81cc[];   // ConditionFactoryCasterTemplate<CAxisDoubleTapCondition>'s vftable
extern "C" char DAT_003f81d8[];   // ConditionFactoryCasterTemplate<CAxisDownCondition>'s vftable
extern "C" char DAT_003f81e4[];   // ConditionFactoryCasterTemplate<CAxisPressCondition>'s vftable
extern "C" char DAT_003f81f0[];   // ConditionFactoryCasterTemplate<CAxisReleaseCondition>'s vftable
extern "C" char DAT_003f81fc[];   // ConditionFactoryCasterTemplate<CAxisSpeedCondition>'s vftable
extern "C" char DAT_003f8208[];   // ConditionFactoryCasterTemplate<CAxisUpCondition>'s vftable
extern "C" char DAT_003f8214[];   // ConditionFactoryCasterTemplate<CButtonDownCondition>'s vftable
extern "C" char DAT_003f8220[];   // ConditionFactoryCasterTemplate<CButtonPressCondition>'s vftable
extern "C" char DAT_003f822c[];   // ConditionFactoryCasterTemplate<CButtonReleaseCondition>'s vftable
extern "C" char DAT_003f8238[];   // ConditionFactoryCasterTemplate<CButtonUpCondition>'s vftable
extern "C" char DAT_003f8244[];   // ConditionFactoryCasterTemplate<CCharacterSizeCondition>'s vftable
extern "C" char DAT_003f8250[];   // ConditionFactoryCasterTemplate<CCharacterTemplateCondition>'s vftable
extern "C" char DAT_003f825c[];   // ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>'s vftable
extern "C" char DAT_003f8274[];   // ConditionFactoryCasterTemplate<CClimbEdgeCondition>'s vftable
extern "C" char DAT_003f8268[];   // ConditionFactoryCasterTemplate<CClimbableCondition>'s vftable
extern "C" char DAT_003f8280[];   // ConditionFactoryCasterTemplate<CCollisionDirectionCondition>'s vftable
extern "C" char DAT_003f828c[];   // ConditionFactoryCasterTemplate<CCollisionFlagCondition>'s vftable
extern "C" char DAT_003f8298[];   // ConditionFactoryCasterTemplate<CCollisionHeightCondition>'s vftable
extern "C" char DAT_003f82a4[];   // ConditionFactoryCasterTemplate<CCollisionHitLocationCondition>'s vftable
extern "C" char DAT_003f82b0[];   // ConditionFactoryCasterTemplate<CCollisionInterruptCondition>'s vftable
extern "C" char DAT_003f82bc[];   // ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition>'s vftable
extern "C" char DAT_003f82c8[];   // ConditionFactoryCasterTemplate<CCollisionPushbackVelocityCondition>'s vftable
extern "C" char DAT_003f82e0[];   // ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition>'s vftable
extern "C" char DAT_003f82d4[];   // ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>'s vftable
extern "C" char DAT_003f82ec[];   // ConditionFactoryCasterTemplate<CCollisionStunTimeCondition>'s vftable
extern "C" char DAT_003f82f8[];   // ConditionFactoryCasterTemplate<CFightNodeCondition>'s vftable
extern "C" char DAT_003f8304[];   // ConditionFactoryCasterTemplate<CFightNodeParentCondition>'s vftable
extern "C" char DAT_003f8310[];   // ConditionFactoryCasterTemplate<CFightNodePrevCondition>'s vftable
extern "C" char DAT_003f831c[];   // ConditionFactoryCasterTemplate<CFightNodeTimeCondition>'s vftable
extern "C" char DAT_003f8328[];   // ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>'s vftable
extern "C" char DAT_003f8334[];   // ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>'s vftable
extern "C" char DAT_003f8340[];   // ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>'s vftable
extern "C" char DAT_003f834c[];   // ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>'s vftable
extern "C" char DAT_003f8358[];   // ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>'s vftable
extern "C" char DAT_003f8364[];   // ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>'s vftable
extern "C" char DAT_003f8370[];   // ConditionFactoryCasterTemplate<CGrappleSizeCondition>'s vftable
extern "C" char DAT_003f837c[];   // ConditionFactoryCasterTemplate<CGrappleTimerCondition>'s vftable
extern "C" char DAT_003f8388[];   // ConditionFactoryCasterTemplate<CGroundDistanceCondition>'s vftable
extern "C" char DAT_003f8394[];   // ConditionFactoryCasterTemplate<CInactivityTimerCondition>'s vftable
extern "C" char DAT_003f83a0[];   // ConditionFactoryCasterTemplate<CIntentionSpeedCondition>'s vftable
extern "C" char DAT_003f83ac[];   // ConditionFactoryCasterTemplate<CIsGrappledCondition>'s vftable
extern "C" char DAT_003f83b8[];   // ConditionFactoryCasterTemplate<CIsHelicopterCondition>'s vftable
extern "C" char DAT_003f83c4[];   // ConditionFactoryCasterTemplate<CIsInvincibleCondition>'s vftable
extern "C" char DAT_003f83d0[];   // ConditionFactoryCasterTemplate<CLuaNumberCondition>'s vftable
extern "C" char DAT_003f83dc[];   // ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>'s vftable
extern "C" char DAT_003f83e8[];   // ConditionFactoryCasterTemplate<CMotionHitCondition>'s vftable
extern "C" char DAT_003f83f4[];   // ConditionFactoryCasterTemplate<CMotionStateCondition>'s vftable
extern "C" char DAT_003f8400[];   // ConditionFactoryCasterTemplate<CNameFlagCondition>'s vftable
extern "C" char DAT_003f840c[];   // ConditionFactoryCasterTemplate<CPropActorStateCondition>'s vftable
extern "C" char DAT_003f8418[];   // ConditionFactoryCasterTemplate<CRageModeCondition>'s vftable
extern "C" char DAT_003f8424[];   // ConditionFactoryCasterTemplate<CSmartPropAngleCondition>'s vftable
extern "C" char DAT_003f8430[];   // ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>'s vftable
extern "C" char DAT_003f843c[];   // ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>'s vftable
extern "C" char DAT_003f8448[];   // ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>'s vftable
extern "C" char DAT_003f8454[];   // ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>'s vftable
extern "C" char DAT_003f8460[];   // ConditionFactoryCasterTemplate<CSmartPropNameCondition>'s vftable
extern "C" char DAT_003f846c[];   // ConditionFactoryCasterTemplate<CSmartPropStateCondition>'s vftable
extern "C" char DAT_003f8478[];   // ConditionFactoryCasterTemplate<CSmartPropTypeCondition>'s vftable
extern "C" char DAT_003f8490[];   // ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>'s vftable
extern "C" char DAT_003f8484[];   // ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>'s vftable
extern "C" char DAT_003f849c[];   // ConditionFactoryCasterTemplate<CStageCondition>'s vftable
template <class T> struct ConditionFactoryCasterTemplate {
    void* vftable;
    ConditionFactoryCasterTemplate();
};
template <> inline ConditionFactoryCasterTemplate<CAlertStatusCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81a8; }
template <> inline ConditionFactoryCasterTemplate<CAxisArcCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81b4; }
template <> inline ConditionFactoryCasterTemplate<CAxisDirectionCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81c0; }
template <> inline ConditionFactoryCasterTemplate<CAxisDoubleTapCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81cc; }
template <> inline ConditionFactoryCasterTemplate<CAxisDownCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81d8; }
template <> inline ConditionFactoryCasterTemplate<CAxisPressCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81e4; }
template <> inline ConditionFactoryCasterTemplate<CAxisReleaseCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81f0; }
template <> inline ConditionFactoryCasterTemplate<CAxisSpeedCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81fc; }
template <> inline ConditionFactoryCasterTemplate<CAxisUpCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8208; }
template <> inline ConditionFactoryCasterTemplate<CButtonDownCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8214; }
template <> inline ConditionFactoryCasterTemplate<CButtonPressCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8220; }
template <> inline ConditionFactoryCasterTemplate<CButtonReleaseCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f822c; }
template <> inline ConditionFactoryCasterTemplate<CButtonUpCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8238; }
template <> inline ConditionFactoryCasterTemplate<CCharacterSizeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8244; }
template <> inline ConditionFactoryCasterTemplate<CCharacterTemplateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8250; }
template <> inline ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f825c; }
template <> inline ConditionFactoryCasterTemplate<CClimbEdgeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8274; }
template <> inline ConditionFactoryCasterTemplate<CClimbableCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8268; }
template <> inline ConditionFactoryCasterTemplate<CCollisionDirectionCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8280; }
template <> inline ConditionFactoryCasterTemplate<CCollisionFlagCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f828c; }
template <> inline ConditionFactoryCasterTemplate<CCollisionHeightCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8298; }
template <> inline ConditionFactoryCasterTemplate<CCollisionHitLocationCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82a4; }
template <> inline ConditionFactoryCasterTemplate<CCollisionInterruptCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82b0; }
template <> inline ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82bc; }
template <> inline ConditionFactoryCasterTemplate<CCollisionPushbackVelocityCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82c8; }
template <> inline ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82e0; }
template <> inline ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82d4; }
template <> inline ConditionFactoryCasterTemplate<CCollisionStunTimeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82ec; }
template <> inline ConditionFactoryCasterTemplate<CFightNodeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82f8; }
template <> inline ConditionFactoryCasterTemplate<CFightNodeParentCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8304; }
template <> inline ConditionFactoryCasterTemplate<CFightNodePrevCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8310; }
template <> inline ConditionFactoryCasterTemplate<CFightNodeTimeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f831c; }
template <> inline ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8328; }
template <> inline ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8334; }
template <> inline ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8340; }
template <> inline ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f834c; }
template <> inline ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8358; }
template <> inline ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8364; }
template <> inline ConditionFactoryCasterTemplate<CGrappleSizeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8370; }
template <> inline ConditionFactoryCasterTemplate<CGrappleTimerCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f837c; }
template <> inline ConditionFactoryCasterTemplate<CGroundDistanceCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8388; }
template <> inline ConditionFactoryCasterTemplate<CInactivityTimerCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8394; }
template <> inline ConditionFactoryCasterTemplate<CIntentionSpeedCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83a0; }
template <> inline ConditionFactoryCasterTemplate<CIsGrappledCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83ac; }
template <> inline ConditionFactoryCasterTemplate<CIsHelicopterCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83b8; }
template <> inline ConditionFactoryCasterTemplate<CIsInvincibleCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83c4; }
template <> inline ConditionFactoryCasterTemplate<CLuaNumberCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83d0; }
template <> inline ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83dc; }
template <> inline ConditionFactoryCasterTemplate<CMotionHitCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83e8; }
template <> inline ConditionFactoryCasterTemplate<CMotionStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83f4; }
template <> inline ConditionFactoryCasterTemplate<CNameFlagCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8400; }
template <> inline ConditionFactoryCasterTemplate<CPropActorStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f840c; }
template <> inline ConditionFactoryCasterTemplate<CRageModeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8418; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropAngleCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8424; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8430; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f843c; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8448; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8454; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropNameCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8460; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f846c; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropTypeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8478; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8490; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8484; }
template <> inline ConditionFactoryCasterTemplate<CStageCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f849c; }
}
struct Registry_553d0 { bool FUN_00236760(void*); void FUN_002363f0(); };
void* __cdecl FUN_002343e0(const char*, void*);
void __cdecl FUN_00236940(Registry_553d0*);
extern "C" void __cdecl FUN_00132620(void*);   // (decl1) as defined (GameStateCondition.cpp)
extern "C" void __cdecl FUN_001138d0(void *, void *);
extern "C" void __cdecl FUN_00113a20(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113b10(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113b40(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" bool __cdecl FUN_00113ab0(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_001139f0(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" bool __cdecl FUN_00129fe0(void*);   // (decl1) as defined (TargetDirectionYCondition_16.cpp)
extern "C" void __cdecl FUN_0012d450(void*);   // (decl1) as defined (ThreatDistanceCondition.cpp)
extern "C" void __cdecl FUN_00113900(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113a80(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113b70(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113ae0(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113990(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_0016cea0(void*);   // (decl1) as defined (ChargeCondition_2_13.cpp)
extern "C" void __cdecl FUN_00142910(void*);   // (decl1) as defined (WallJumpAction.cpp)
extern "C" bool __cdecl FUN_0018b310(void*);   // (decl1) as defined (PropMissionCriticalCondition_28.cpp)
extern "C" void __cdecl FUN_0018e860(void*);   // (decl1) as defined (TimerCondition.cpp)
extern "C" void __cdecl FUN_0013d3c0(void*);   // (decl1) as defined (AnimationVelocityScaledAction.cpp)
extern "C" void __cdecl FUN_00163a20(void*);   // (decl1) as defined (HeliLocomotionAction_2.cpp)
extern "C" void __cdecl FUN_0014bb60(void*);   // (decl1) as defined (GrappleThrowAction.cpp)
extern "C" void __cdecl FUN_00158c20(void*);   // (decl1) as defined (InterruptAccumulatorCondition_19.cpp)
extern "C" void __cdecl FUN_0019e3e0(void*);   // (decl1) as defined (FireProjectileAction_2.cpp)
extern "C" void __cdecl FUN_0011a9b0(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_0011a9e0(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_0011a980(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_0011aa10(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_001a1cf0(void*, const char*);   // (decl1) as defined (LuaCondition.cpp)
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
// (sweep-caster-fix1) the caster as the word its inline constructor writes: the game's vftable by address, per T
// (a local polymorphic stand-in got clang's own vftable natively, whose slot had no definition)
extern "C" char DAT_003f81a8[];   // ConditionFactoryCasterTemplate<CAlertStatusCondition>'s vftable
extern "C" char DAT_003f8244[];   // ConditionFactoryCasterTemplate<CCharacterSizeCondition>'s vftable
extern "C" char DAT_003f8250[];   // ConditionFactoryCasterTemplate<CCharacterTemplateCondition>'s vftable
extern "C" char DAT_003f825c[];   // ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>'s vftable
extern "C" char DAT_003f8274[];   // ConditionFactoryCasterTemplate<CClimbEdgeCondition>'s vftable
extern "C" char DAT_003f8268[];   // ConditionFactoryCasterTemplate<CClimbableCondition>'s vftable
extern "C" char DAT_003f82f8[];   // ConditionFactoryCasterTemplate<CFightNodeCondition>'s vftable
extern "C" char DAT_003f8304[];   // ConditionFactoryCasterTemplate<CFightNodeParentCondition>'s vftable
extern "C" char DAT_003f8310[];   // ConditionFactoryCasterTemplate<CFightNodePrevCondition>'s vftable
extern "C" char DAT_003f831c[];   // ConditionFactoryCasterTemplate<CFightNodeTimeCondition>'s vftable
extern "C" char DAT_003f8328[];   // ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>'s vftable
extern "C" char DAT_003f8334[];   // ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>'s vftable
extern "C" char DAT_003f8340[];   // ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>'s vftable
extern "C" char DAT_003f834c[];   // ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>'s vftable
extern "C" char DAT_003f8358[];   // ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>'s vftable
extern "C" char DAT_003f8364[];   // ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>'s vftable
extern "C" char DAT_003f8370[];   // ConditionFactoryCasterTemplate<CGrappleSizeCondition>'s vftable
extern "C" char DAT_003f837c[];   // ConditionFactoryCasterTemplate<CGrappleTimerCondition>'s vftable
extern "C" char DAT_003f8388[];   // ConditionFactoryCasterTemplate<CGroundDistanceCondition>'s vftable
extern "C" char DAT_003f8394[];   // ConditionFactoryCasterTemplate<CInactivityTimerCondition>'s vftable
extern "C" char DAT_003f83a0[];   // ConditionFactoryCasterTemplate<CIntentionSpeedCondition>'s vftable
extern "C" char DAT_003f83ac[];   // ConditionFactoryCasterTemplate<CIsGrappledCondition>'s vftable
extern "C" char DAT_003f83b8[];   // ConditionFactoryCasterTemplate<CIsHelicopterCondition>'s vftable
extern "C" char DAT_003f83c4[];   // ConditionFactoryCasterTemplate<CIsInvincibleCondition>'s vftable
extern "C" char DAT_003f83d0[];   // ConditionFactoryCasterTemplate<CLuaNumberCondition>'s vftable
extern "C" char DAT_003f83dc[];   // ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>'s vftable
extern "C" char DAT_003f83e8[];   // ConditionFactoryCasterTemplate<CMotionHitCondition>'s vftable
extern "C" char DAT_003f83f4[];   // ConditionFactoryCasterTemplate<CMotionStateCondition>'s vftable
extern "C" char DAT_003f8400[];   // ConditionFactoryCasterTemplate<CNameFlagCondition>'s vftable
extern "C" char DAT_003f840c[];   // ConditionFactoryCasterTemplate<CPropActorStateCondition>'s vftable
extern "C" char DAT_003f8418[];   // ConditionFactoryCasterTemplate<CRageModeCondition>'s vftable
extern "C" char DAT_003f8424[];   // ConditionFactoryCasterTemplate<CSmartPropAngleCondition>'s vftable
extern "C" char DAT_003f8430[];   // ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>'s vftable
extern "C" char DAT_003f843c[];   // ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>'s vftable
extern "C" char DAT_003f8448[];   // ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>'s vftable
extern "C" char DAT_003f8454[];   // ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>'s vftable
extern "C" char DAT_003f8460[];   // ConditionFactoryCasterTemplate<CSmartPropNameCondition>'s vftable
extern "C" char DAT_003f846c[];   // ConditionFactoryCasterTemplate<CSmartPropStateCondition>'s vftable
extern "C" char DAT_003f8478[];   // ConditionFactoryCasterTemplate<CSmartPropTypeCondition>'s vftable
extern "C" char DAT_003f8490[];   // ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>'s vftable
extern "C" char DAT_003f8484[];   // ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>'s vftable
extern "C" char DAT_003f849c[];   // ConditionFactoryCasterTemplate<CStageCondition>'s vftable
template <class T> struct ConditionFactoryCasterTemplate {
    void* vftable;
    ConditionFactoryCasterTemplate();
};
template <> inline ConditionFactoryCasterTemplate<CAlertStatusCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f81a8; }
template <> inline ConditionFactoryCasterTemplate<CCharacterSizeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8244; }
template <> inline ConditionFactoryCasterTemplate<CCharacterTemplateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8250; }
template <> inline ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f825c; }
template <> inline ConditionFactoryCasterTemplate<CClimbEdgeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8274; }
template <> inline ConditionFactoryCasterTemplate<CClimbableCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8268; }
template <> inline ConditionFactoryCasterTemplate<CFightNodeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f82f8; }
template <> inline ConditionFactoryCasterTemplate<CFightNodeParentCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8304; }
template <> inline ConditionFactoryCasterTemplate<CFightNodePrevCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8310; }
template <> inline ConditionFactoryCasterTemplate<CFightNodeTimeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f831c; }
template <> inline ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8328; }
template <> inline ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8334; }
template <> inline ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8340; }
template <> inline ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f834c; }
template <> inline ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8358; }
template <> inline ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8364; }
template <> inline ConditionFactoryCasterTemplate<CGrappleSizeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8370; }
template <> inline ConditionFactoryCasterTemplate<CGrappleTimerCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f837c; }
template <> inline ConditionFactoryCasterTemplate<CGroundDistanceCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8388; }
template <> inline ConditionFactoryCasterTemplate<CInactivityTimerCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8394; }
template <> inline ConditionFactoryCasterTemplate<CIntentionSpeedCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83a0; }
template <> inline ConditionFactoryCasterTemplate<CIsGrappledCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83ac; }
template <> inline ConditionFactoryCasterTemplate<CIsHelicopterCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83b8; }
template <> inline ConditionFactoryCasterTemplate<CIsInvincibleCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83c4; }
template <> inline ConditionFactoryCasterTemplate<CLuaNumberCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83d0; }
template <> inline ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83dc; }
template <> inline ConditionFactoryCasterTemplate<CMotionHitCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83e8; }
template <> inline ConditionFactoryCasterTemplate<CMotionStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83f4; }
template <> inline ConditionFactoryCasterTemplate<CNameFlagCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8400; }
template <> inline ConditionFactoryCasterTemplate<CPropActorStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f840c; }
template <> inline ConditionFactoryCasterTemplate<CRageModeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8418; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropAngleCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8424; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8430; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f843c; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8448; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8454; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropNameCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8460; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropStateCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f846c; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropTypeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8478; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8490; }
template <> inline ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f8484; }
template <> inline ConditionFactoryCasterTemplate<CStageCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f849c; }

}
struct Registry_55d80 {
    bool FUN_00236760(void*);
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
extern "C" void __cdecl FUN_00113900(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113930(Registry_55d80*, const char*);
extern "C" void __cdecl FUN_00113990(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_001139f0(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113a20(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113a50(Registry_55d80*, const char*);
extern "C" void __cdecl FUN_00113a80(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" bool __cdecl FUN_00113ab0(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113ae0(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113b10(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113b40(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_00113b70(void*, const char*);   // (decl1) as defined (unk_1133f0.cpp)
extern "C" void __cdecl FUN_0011a980(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_0011a9b0(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_0011a9e0(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_0011aa10(void*, const char*);   // (decl1) as defined (MotionClosestWaypointAction_2.cpp)
extern "C" void __cdecl FUN_00122b70(Registry_55d80*, const char*);
extern "C" bool __cdecl FUN_00129fe0(void*);   // (decl1) as defined (TargetDirectionYCondition_16.cpp)
extern "C" void __cdecl FUN_0012d450(void*);   // (decl1) as defined (ThreatDistanceCondition.cpp)
extern "C" void __cdecl FUN_00132620(void*);   // (decl1) as defined (GameStateCondition.cpp)
extern "C" void __cdecl FUN_0013d3c0(void*);   // (decl1) as defined (AnimationVelocityScaledAction.cpp)
extern "C" void __cdecl FUN_00142910(void*);   // (decl1) as defined (WallJumpAction.cpp)
extern "C" void __cdecl FUN_0014bb60(void*);   // (decl1) as defined (GrappleThrowAction.cpp)
extern "C" void __cdecl FUN_00158c20(void*);   // (decl1) as defined (InterruptAccumulatorCondition_19.cpp)
extern "C" void __cdecl FUN_00163a20(void*);   // (decl1) as defined (HeliLocomotionAction_2.cpp)
extern "C" void __cdecl FUN_0016cea0(void*);   // (decl1) as defined (ChargeCondition_2_13.cpp)
extern "C" bool __cdecl FUN_0018b310(void*);   // (decl1) as defined (PropMissionCriticalCondition_28.cpp)
extern "C" void __cdecl FUN_0018e860(void*);   // (decl1) as defined (TimerCondition.cpp)
extern "C" void __cdecl FUN_0019e3e0(void*);   // (decl1) as defined (FireProjectileAction_2.cpp)
extern "C" void __cdecl FUN_001a1cf0(void*, const char*);   // (decl1) as defined (LuaCondition.cpp)
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
// (sweep-caster-fix1) the caster as the word its inline constructor writes: the game's vftable by address, per T
// (a local polymorphic stand-in got clang's own vftable natively, whose slot had no definition)
extern "C" char DAT_003f83d0[];   // ConditionFactoryCasterTemplate<CLuaNumberCondition>'s vftable
template <class T> struct ConditionFactoryCasterTemplate {
    void* vftable;
    ConditionFactoryCasterTemplate();
};
template <> inline ConditionFactoryCasterTemplate<CLuaNumberCondition>::ConditionFactoryCasterTemplate() { vftable = (void*)DAT_003f83d0; }

} // namespace fight
struct Registry_56460 {
    bool FUN_00236760(void*);
    void FUN_002363f0();
};
extern void __cdecl FUN_00236940(Registry_56460*);
extern void* __cdecl FUN_002343e0(const char*, fight::ConditionFactoryCasterTemplate<CLuaNumberCondition>*);
extern "C" void __cdecl FUN_00132620(void*);   // (decl1) as defined (GameStateCondition.cpp)
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
extern "C" void __cdecl FUN_001a1cf0(void*, const char*);   // (decl1) as defined (LuaCondition.cpp)
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


// 0x00056570 FUN_00056570 (176 B): matches/0x00056570.cpp
// sym: _FUN_00056570
// (gx2, D18) from CSmartPropDistanceCondition_reg_055220.iso_00056570.cpp; constructs the real ParamEnumConstList<CNameFlagConditionBase>, ParamName<CNameFlagConditionBase>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00056570()
{
    if (DAT_004dc46c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CNameFlagConditionBase>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::Obj_47d20::FUN_00047d20);
        params[1] = new ::fight::ParamName< ::CNameFlagConditionBase>("flag", &owners::Obj_47d30::FUN_00047d30);
        FUN_002347b0(&DAT_004dc468, params, 2);
    }
    DAT_004dc46c++;
}



// 0x00056620 FUN_00056620 (231 B): matches/0x00056620.cpp
// sym: ?FUN_00056620@@YAXXZ
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CSmartPropNameCondition>, ParamIntConstRange<CSmartPropNameCondition>, ParamName<CSmartPropNameCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_00056620()
{
    if (DAT_004dc4c4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropNameCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f64b1530::Obj_47e90::SetCompare_00047e90);
        params[1] = new ::fight::ParamName< ::CSmartPropNameCondition>("name", &fn_f64b1530::Obj_47ea0::GetName_00047ea0);
        params[2] = new ::fight::ParamIntConstRange< ::CSmartPropNameCondition>("attachmentIndex", &fn_f64b1530::Obj_47eb0::SetAttachmentIndex_00047eb0);
        FUN_002347b0(&DAT_004dc4c0, params, 3);
    }
    DAT_004dc4c4++;
}



// 0x00056710 FUN_00056710 (274 B): matches/0x00056710.cpp
// sym: ?FUN_00056710@@YAXXZ
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CSmartPropDistanceCondition>, ParamFloatConstRange<CSmartPropDistanceCondition>, ParamNameConstList<CSmartPropDistanceCondition>, ParamVector<CSmartPropDistanceCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_00056710()
{
    if (DAT_004dc4d4 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropDistanceCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f64b1530::Obj_47ee0::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::CSmartPropDistanceCondition>("distance", &fn_f64b1530::C_47ef0::Set);
        params[2] = new ::fight::ParamNameConstList< ::CSmartPropDistanceCondition>("joint", &fn_f64b1530::Obj_47f00::Get);
        params[3] = new ::fight::ParamVector< ::CSmartPropDistanceCondition>("offset", &fn_f64b1530::C_47f10::Set);
        FUN_002347b0(&DAT_004dc4d0, params, 4);
    }
    DAT_004dc4d4++;
}



// 0x00056830 FUN_00056830 (176 B): matches/0x00056830.cpp
// sym: _FUN_00056830
// (gx2, D18) from CSmartPropDistanceCondition_reg_055220.iso_00056830.cpp; constructs the real ParamEnumConstList<CSmartPropGrabbableNameCondition>, ParamName<CSmartPropGrabbableNameCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00056830()
{
    if (DAT_004dc4dc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CSmartPropGrabbableNameCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::X_47f30::FUN_00047f30);
        params[1] = new ::fight::ParamName< ::CSmartPropGrabbableNameCondition>("name", &owners::Obj_47f40::FUN_00047f40);
        FUN_002347b0(&DAT_004dc4d8, params, 2);
    }
    DAT_004dc4dc++;
}



// 0x000568e0 FUN_000568e0 (176 B): matches/0x000568e0.cpp
// sym: _FUN_000568e0
// (gx2, D18) from CSmartPropDistanceCondition_reg_055220.iso_000568e0.cpp; constructs the real ParamEnumConstList<CCharacterTemplateCondition>, ParamNameList<CCharacterTemplateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000568e0()
{
    if (DAT_004dc50c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCharacterTemplateCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::Obj_47fe0::FUN_00047fe0);
        params[1] = new ::fight::ParamNameList< ::CCharacterTemplateCondition>("characterTemplate", &owners::Obj_47ff0::FUN_00047ff0);
        FUN_002347b0(&DAT_004dc508, params, 2);
    }
    DAT_004dc50c++;
}



// 0x00056990 FUN_00056990 (176 B): matches/0x00056990.cpp
// sym: _FUN_00056990
// (gx2, D18) from CSmartPropDistanceCondition_reg_055220.iso_00056990.cpp; constructs the real ParamEnumConstList<CCharacterTemplateVariationCondition>, ParamNameList<CCharacterTemplateVariationCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00056990()
{
    if (DAT_004dc514 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CCharacterTemplateVariationCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::A_48000::FUN_00048000);
        params[1] = new ::fight::ParamNameList< ::CCharacterTemplateVariationCondition>("CharacterTemplateVariation", &owners::Obj_48010::FUN_00048010);
        FUN_002347b0(&DAT_004dc510, params, 2);
    }
    DAT_004dc514++;
}



// 0x00056a40 FUN_00056a40 (176 B): matches/0x00056a40.cpp
// sym: _FUN_00056a40
// (gx2, D18) from CSmartPropDistanceCondition_reg_055220.iso_00056a40.cpp; constructs the real ParamEnumConstList<CGrappleCharacterTemplateCondition>, ParamNameList<CGrappleCharacterTemplateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00056a40()
{
    if (DAT_004dc51c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::CGrappleCharacterTemplateCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::X_48020::FUN_00048020);
        params[1] = new ::fight::ParamNameList< ::CGrappleCharacterTemplateCondition>("characterTemplate", &owners::Obj_48030::FUN_00048030);
        FUN_002347b0(&DAT_004dc518, params, 2);
    }
    DAT_004dc51c++;
}


