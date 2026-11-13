// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016c600..0x0016d360 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeCondition
#include "tree_prelude.h"
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

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f3263be4 {
void* FUN_0008d690(unsigned int size);
class RayCastTargetCondition {
public:
    void FUN_00165440();
    void FUN_00165470();
    void FUN_001654b0();
    void FUN_001654e0();
    void FUN_00165500();
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class RayCastConeCondition {
public:
    void FUN_001655c0();
    void FUN_001655f0();
    void FUN_00165620();
    void FUN_00165640();
    void FUN_00165660();
    void FUN_00165680();
};
class RayCastCondition {
public:
    void FUN_001657c0();
    void FUN_001657f0();
    void FUN_00165830();
    void FUN_00165860();
    void FUN_00165880();
    void FUN_001658a0();
    void FUN_001658c0();
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


// 0x0016c600 FUN_0016c600 (307 B): equivalent/0x0016c600.cpp
// sym: _FUN_0016c600 @c85cbac477ad @wbbcc7cd746fa
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0016c600 @ 0x0016c600
extern "C" void FUN_0016c600()
{
    if (DAT_004e120c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamNameConstList<RayCastTargetCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamNameConstList<RayCastTargetCondition>("joint", &RayCastTargetCondition::FUN_00165440);
        mem = FUN_0008d690((int)sizeof(ParamVector<RayCastTargetCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamVector<RayCastTargetCondition>("offset", &RayCastTargetCondition::FUN_00165470);
        mem = FUN_0008d690((int)sizeof(ParamVector<RayCastTargetCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<RayCastTargetCondition>("direction", &RayCastTargetCondition::FUN_001654b0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RayCastTargetCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<RayCastTargetCondition>("length", &RayCastTargetCondition::FUN_001654e0);
        mem = FUN_0008d690((int)sizeof(ParamBool<RayCastTargetCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<RayCastTargetCondition>("hitFound", &RayCastTargetCondition::FUN_00165500);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1208), params, 5);
    }
    DAT_004e120c++;
}


// 0x0016c830 FUN_0016c830 (358 B): equivalent/0x0016c830.cpp
// sym: _FUN_0016c830 @d865513f22a8 @w81afde01dcb8
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 14/14)
// FUN_0016c830 @ 0x0016c830
extern "C" void FUN_0016c830()
{
    if (DAT_004e1234 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamNameConstList<RayCastConeCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamNameConstList<RayCastConeCondition>("joint", &RayCastConeCondition::FUN_001655c0);
        mem = FUN_0008d690((int)sizeof(ParamVector<RayCastConeCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamVector<RayCastConeCondition>("offset", &RayCastConeCondition::FUN_001655f0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RayCastConeCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<RayCastConeCondition>("length", &RayCastConeCondition::FUN_00165620);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RayCastConeCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<RayCastConeCondition>("angle", &RayCastConeCondition::FUN_00165640);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RayCastConeCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<RayCastConeCondition>("stepSize", &RayCastConeCondition::FUN_00165660);
        mem = FUN_0008d690((int)sizeof(ParamBool<RayCastConeCondition>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<RayCastConeCondition>("hitFound", &RayCastConeCondition::FUN_00165680);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1230), params, 6);
    }
    DAT_004e1234++;
}


// 0x0016cb50 FUN_0016cb50 (409 B): equivalent/0x0016cb50.cpp
// sym: _FUN_0016cb50 @b7d3b16e90d7 @wbc471039f669
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_0016cb50 @ 0x0016cb50
extern "C" void FUN_0016cb50()
{
    if (DAT_004e127c == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<RayCastCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamNameConstList<RayCastCondition>("joint", &RayCastCondition::FUN_001657c0);
        mem = FUN_0008d690((int)sizeof(ParamVector<RayCastCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamVector<RayCastCondition>("offset", &RayCastCondition::FUN_001657f0);
        mem = FUN_0008d690((int)sizeof(ParamVector<RayCastCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<RayCastCondition>("direction", &RayCastCondition::FUN_00165830);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RayCastCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<RayCastCondition>("length", &RayCastCondition::FUN_00165860);
        mem = FUN_0008d690((int)sizeof(ParamBool<RayCastCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<RayCastCondition>("hitFound", &RayCastCondition::FUN_00165880);
        mem = FUN_0008d690((int)sizeof(ParamBool<RayCastCondition>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<RayCastCondition>("testForGroundPointAtEnd", &RayCastCondition::FUN_001658a0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<RayCastCondition>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<RayCastCondition>("allowedHeightAtEnd", &RayCastCondition::FUN_001658c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1278), params, 7);
    }
    DAT_004e127c++;
}

} // namespace fn_f3263be4

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
