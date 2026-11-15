// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016c600..0x0016d360 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeCondition
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3263be4 {
#define TREE_TU_END }
namespace fn_f3263be4 {} using namespace fn_f3263be4;
namespace fn_f3263be4 {
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
namespace fn_f3263be4 { extern "C" char DAT_00416658[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/hulkfight/motion.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f5579237 { class Vec3_1655f0; } 
namespace fn_f5579237 { struct Src_165470; } 
namespace fn_f5579237 { struct Src_1654b0; } 
namespace fn_f5579237 { struct Src_1657f0; } 
namespace fn_f5579237 { struct Vec3_165830; } 
namespace fn_f5579237 { struct Obj_165470 { bool Set(struct fn_f5579237::Src_165470 *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1654b0 { bool Set(struct fn_f5579237::Src_1654b0 *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1655f0 { bool Set(class fn_f5579237::Vec3_1655f0 const *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1657f0 { bool Set(struct fn_f5579237::Src_1657f0 *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_165830 { bool Copy(struct fn_f5579237::Vec3_165830 *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f3263be4 {
void* FUN_0008d690(unsigned int size);
class RayCastTargetCondition {
public:
    void FUN_00165440();
    bool FUN_00165470(void*); /* (unb4) as defined; address taken only */
    bool FUN_001654b0(void*); /* (unb4) as defined; address taken only */
    bool FUN_001654e0(int); /* (unb4) as defined; address taken only */
    char FUN_00165500(char); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class RayCastConeCondition {
public:
    void FUN_001655c0();
    bool FUN_001655f0(void*); /* (unb4) as defined; address taken only */
    char FUN_00165620(int); /* (unb4) as defined; address taken only */
    char FUN_00165640(int); /* (unb4) as defined; address taken only */
    char FUN_00165660(int); /* (unb4) as defined; address taken only */
    char FUN_00165680(char); /* (unb4) as defined; address taken only */
};
class RayCastCondition {
public:
    void FUN_001657c0();
    bool FUN_001657f0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00165830(void*); /* (unb4) as defined; address taken only */
    char FUN_00165860(int); /* (unb4) as defined; address taken only */
    char FUN_00165880(char); /* (unb4) as defined; address taken only */
    char FUN_001658a0(char); /* (unb4) as defined; address taken only */
    bool FUN_001658c0(int); /* (unb4) as defined; address taken only */
};
extern void* __cdecl Alloc_0008d690(unsigned int);
class Condition_16d2f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init_00234590(int);
    int x;
    int y;
    int z;
    int w;
    int q;
};
extern int hulk_at_004174f8;
struct ConditionFactoryTemplate_16d330 {
    void* m_vptr;
    void base1_dtor_00165a30();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};


} // namespace fn_f3263be4

// 0x0016a340 fight::ParamVector<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016a340.cpp
// sym: ??_G?$ParamVector@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastTargetCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a360 fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016a360.cpp
// sym: ??_G?$ParamFloatConstRange@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastTargetCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a380 fight::ParamBool<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016a380.cpp
// sym: ??_G?$ParamBool@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastTargetCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a580 fight::ParamVector<hulkfight::motion::RayCastConeCondition>::vfunc_0 (30 B): matches/0x0016a580.cpp
// sym: ??_G?$ParamVector@VRayCastConeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastConeCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a5a0 fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>::vfunc_0 (30 B): matches/0x0016a5a0.cpp
// sym: ??_G?$ParamFloatConstRange@VRayCastConeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastConeCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a5c0 fight::ParamBool<hulkfight::motion::RayCastConeCondition>::vfunc_0 (30 B): matches/0x0016a5c0.cpp
// sym: ??_G?$ParamBool@VRayCastConeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastConeCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a9a0 fight::ParamVector<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016a9a0.cpp
// sym: ??_G?$ParamVector@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a9c0 fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016a9c0.cpp
// sym: ??_G?$ParamFloatConstRange@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016a9e0 fight::ParamBool<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016a9e0.cpp
// sym: ??_G?$ParamBool@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016c450 fight::ParamNameConstList<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016c450.cpp
// sym: ??_G?$ParamNameConstList@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016c470 fight::ParamNameConstList<hulkfight::motion::RayCastConeCondition>::vfunc_0 (30 B): matches/0x0016c470.cpp
// sym: ??_G?$ParamNameConstList@VRayCastConeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016c490 fight::ParamNameConstList<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016c490.cpp
// sym: ??_G?$ParamNameConstList@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016c600 / FUN_0016c830 / FUN_0016cb50)



// 0x0016c600 FUN_0016c600 (307 B): matches/0x0016c600.cpp
// sym: _FUN_0016c600
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::RayCastTargetCondition>, ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>, ParamNameConstList<hulkfight::motion::RayCastTargetCondition>, ParamVector<hulkfight::motion::RayCastTargetCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016c600()
{
    if (DAT_004e120c == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamNameConstList< ::hulkfight::motion::RayCastTargetCondition>("joint", &owners::A_165440::FUN_00165440);
        params[1] = new ::fight::ParamVector< ::hulkfight::motion::RayCastTargetCondition>("offset", &fn_f5579237::Obj_165470::Set);
        params[2] = new ::fight::ParamVector< ::hulkfight::motion::RayCastTargetCondition>("direction", &fn_f5579237::Obj_1654b0::Set);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RayCastTargetCondition>("length", &owners::Obj_1654e0::FUN_001654e0);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::RayCastTargetCondition>("hitFound", &owners::X_165500::FUN_00165500);
        FUN_002347b0(&DAT_004e1208, params, 5);
    }
    DAT_004e120c++;
}



// 0x0016c830 FUN_0016c830 (358 B): matches/0x0016c830.cpp
// sym: _FUN_0016c830
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::RayCastConeCondition>, ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>, ParamNameConstList<hulkfight::motion::RayCastConeCondition>, ParamVector<hulkfight::motion::RayCastConeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016c830()
{
    if (DAT_004e1234 == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamNameConstList< ::hulkfight::motion::RayCastConeCondition>("joint", &owners::Obj_1655c0::FUN_001655c0);
        params[1] = new ::fight::ParamVector< ::hulkfight::motion::RayCastConeCondition>("offset", &fn_f5579237::Obj_1655f0::Set);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RayCastConeCondition>("length", &owners::Obj_165620::FUN_00165620);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RayCastConeCondition>("angle", &owners::X_165640::FUN_00165640);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RayCastConeCondition>("stepSize", &owners::X_165660::FUN_00165660);
        params[5] = new ::fight::ParamBool< ::hulkfight::motion::RayCastConeCondition>("hitFound", &owners::Obj_165680::FUN_00165680);
        FUN_002347b0(&DAT_004e1230, params, 6);
    }
    DAT_004e1234++;
}



// 0x0016cb50 FUN_0016cb50 (409 B): matches/0x0016cb50.cpp
// sym: _FUN_0016cb50
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::RayCastCondition>, ParamFloatConstRange<hulkfight::motion::RayCastCondition>, ParamNameConstList<hulkfight::motion::RayCastCondition>, ParamVector<hulkfight::motion::RayCastCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016cb50()
{
    if (DAT_004e127c == 0) {
        ::fight::ParamValue* params[7];
        params[0] = new ::fight::ParamNameConstList< ::hulkfight::motion::RayCastCondition>("joint", &owners::Obj_1657c0::FUN_001657c0);
        params[1] = new ::fight::ParamVector< ::hulkfight::motion::RayCastCondition>("offset", &fn_f5579237::Obj_1657f0::Set);
        params[2] = new ::fight::ParamVector< ::hulkfight::motion::RayCastCondition>("direction", &fn_f5579237::Obj_165830::Copy);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RayCastCondition>("length", &owners::Target_165860::FUN_00165860);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::RayCastCondition>("hitFound", &owners::A_165880::FUN_00165880);
        params[5] = new ::fight::ParamBool< ::hulkfight::motion::RayCastCondition>("testForGroundPointAtEnd", &owners::T_1658a0::FUN_001658a0);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::RayCastCondition>("allowedHeightAtEnd", &owners::Obj_1658c0::FUN_001658c0);
        FUN_002347b0(&DAT_004e1278, params, 7);
    }
    DAT_004e127c++;
}



// 0x0016cea0 FUN_0016cea0 (1029 B): matches/0x0016cea0.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_0016cea0
namespace fn_0016cea0 {
// FUN_0016cea0 @ 0x0016cea0
namespace hulkfight { namespace motion { class RayCastCondition; class RayCastConeCondition; class RayCastTargetCondition; class TargetCharacterTemplateCondition; class CharacterPropStatusCondition; class TargetHealthPercentCondition; class VelocityCondition; class VelocityYCondition; class VelocityXZCondition; class VelocityXZAngleCondition; class VelocityAnimatedCondition; class VelocityAnimatedYCondition; class VelocityAnimatedXZCondition; class VelocityAnimatedXZAngleCondition; class ChargeCondition; class TurningVelocityCondition; class IntentionButtonDownAnyCondition; class IntentionInputCondition; class TargetingCondition; class TargetMotionStateCondition; class LocomotionMotionStateCondition; class TargetLocomotionMotionStateCondition; class ThinkingCondition; class HealthCondition; class GrappleHealthCondition; class GrappleReactionTypeCondition; class HealthPercentCondition; class InLoadedRoomCondition; class ShoreNearCondition; class RageModeStateCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_16cea0 { void FUN_00236760(void*); };
extern "C" void* __cdecl FUN_002343e0(const char*, void*);
extern "C" void __cdecl FUN_0016cea0(Registry_16cea0* r)
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
} // namespace fn_0016cea0


// 0x0016d2f0 fight::ConditionFactoryTemplate<hulkfight::motion::ChargeCondition>::vfunc_5 (61 B): matches/0x0016d2f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00113f80 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::ChargeCondition>::vfunc_5() {
    Condition_16d2f0* p = (Condition_16d2f0*)Alloc_0008d690(0x18);
    void* result;
    if (p) {
        p->Init_00234590(0);
        *(int**)p = ((int*)DAT_00416658);
        p->z = 0;
        p->w = 0;
        p->q = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}

namespace fn_f3263be4 {

// 0x0016d330 fight::ConditionFactoryTemplate<hulkfight::motion::ChargeCondition>::vfunc_2 (43 B): matches/0x0016d330.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16d330@fn_f3263be4@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16d330::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004174f8;
    base1_dtor_00165a30();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f3263be4
