// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001296f0..0x0012a270 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f63a58e9 {
#define TREE_TU_END }
namespace fn_f63a58e9 {} using namespace fn_f63a58e9;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f63a58e9 {
struct RefCounted_1296f0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041003c[];
class TargetClearAction_1296f0 {
  public:
    TargetClearAction_1296f0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1296f0* m_20;
};
} // namespace fn_f63a58e9
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f63a58e9 {
extern "C" void* FUN_0008d690(unsigned int size);
class TargetArcCondition {
public:
    char FUN_00123530(float); /* (unb4) as defined; address taken only */
    char FUN_00123550(float); /* (unb4) as defined; address taken only */
    char FUN_00123580(char); /* (unb4) as defined; address taken only */
    void FUN_00123590();
    bool FUN_001235c0(void*); /* (unb4) as defined; address taken only */
    char FUN_001235f0(char); /* (unb4) as defined; address taken only */
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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class TrackFactoryCasterTemplate_129f50 {
  public:
    virtual bool Cast_00128360(void*);
};
class Object {
  public:
    void Use_002367c0(void*);
};
extern "C" void* Find(void*, TrackFactoryCasterTemplate_129f50*);
class TrackFactoryCasterTemplate_129f80 {
  public:
    virtual bool Cast_001283e0(void*);
};
class Track {
  public:
    void Add_002367c0(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_129f80*);
class TrackFactoryCasterTemplate_129fb0 {
  public:
    virtual bool Fnf_00128480(void*);
};
class Target {
  public:
    void Run_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_129fb0*);


// 0x001296f0 hulkfight::ai::TargetClearAction::vfunc_2 (71 B): matches/0x001296f0.cpp
// sym: ?vfunc_2@TargetClearAction_1296f0@fn_f63a58e9@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TargetClearAction_1296f0* TargetClearAction_1296f0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041003c;
    RefCounted_1296f0* q = *(RefCounted_1296f0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x001297a0 fight::ParamName<hulkfight::ai::TargetArcCondition>::vfunc_7 (12 B): matches/0x001297a0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f63a58e9@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f63a58e9

// 0x00129a30 fight::ParamName<hulkfight::ai::TargetArcCondition>::vfunc_0 (30 B): matches/0x00129a30.cpp
// sym: ??_G?$ParamName@VTargetArcCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::TargetArcCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::TargetArcCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x129a30)
#endif

namespace fn_f63a58e9 {

// 0x00129ab0 FUN_00129ab0 (358 B): equivalent/0x00129ab0.cpp
// sym: _FUN_00129ab0 @ec913ce85def @w760f01215ec4
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_00129ab0 @ 0x00129ab0
extern "C" void FUN_00129ab0()
{
    if (DAT_004e0d70 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetArcCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<TargetArcCondition>("angle", (void (TargetArcCondition::*)())&TargetArcCondition::FUN_00123530);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetArcCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TargetArcCondition>("arc", (void (TargetArcCondition::*)())&TargetArcCondition::FUN_00123550);
        mem = FUN_0008d690((int)sizeof(ParamBool<TargetArcCondition>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<TargetArcCondition>("useCameraDirection", (void (TargetArcCondition::*)())&TargetArcCondition::FUN_00123580);
        mem = FUN_0008d690((int)sizeof(ParamName<TargetArcCondition>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamName<TargetArcCondition>("joint", &TargetArcCondition::FUN_00123590);
        mem = FUN_0008d690((int)sizeof(ParamVector<TargetArcCondition>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<TargetArcCondition>("direction", (void (TargetArcCondition::*)())&TargetArcCondition::FUN_001235c0);
        mem = FUN_0008d690((int)sizeof(ParamBool<TargetArcCondition>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<TargetArcCondition>("useHulk", (void (TargetArcCondition::*)())&TargetArcCondition::FUN_001235f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d6c), params, 6);
    }
    DAT_004e0d70++;
}


// 0x00129f50 FUN_00129f50 (38 B): matches/0x00129f50.cpp
// sym: _FUN_00129f50
extern "C" void FUN_00129f50(Object* obj, void* name) {
    TrackFactoryCasterTemplate_129f50 caster;
    obj->Use_002367c0(Find(name, &caster));
}


// 0x00129f80 FUN_00129f80 (38 B): matches/0x00129f80.cpp
// sym: _FUN_00129f80
extern "C" void FUN_00129f80(Track* track, const char* name) {
    TrackFactoryCasterTemplate_129f80 caster;
    track->Add_002367c0(FUN_00236ac0(name, &caster));
}


// 0x00129fb0 FUN_00129fb0 (38 B): matches/0x00129fb0.cpp
// sym: _FUN_00129fb0
extern "C" void FUN_00129fb0(Target* target, void* name) {
    TrackFactoryCasterTemplate_129fb0 caster;
    void* p = FUN_00236ac0(name, &caster);
    target->Run_002367c0(p);
}

} // namespace fn_f63a58e9

// 0x00129fe0 FUN_00129fe0 (655 B): matches/0x00129fe0.cpp [wrapped: macros]
// sym: _FUN_00129fe0
namespace fn_00129fe0 {
namespace hulkfight {
namespace ai {
class HasTargetCondition;
class AcquireTargetCondition;
class TargetTypeCondition;
class TargetDistanceCondition;
class TargetDistanceXZCondition;
class TargetDistanceYCondition;
class TargetOrientationCondition;
class TargetArcCondition;
class TargetVelocityCondition;
class TargetVelocityXZCondition;
class TargetVelocityYCondition;
class TargetDirectionCondition;
class TargetDirectionXZCondition;
class TargetDirectionYCondition;
class TargetAngleYCondition;
class CanSeeTargetCondition;
class TargetInvincibleCondition;
class TargetFirstShotCondition;
class ProjectileDistanceCondition;
} // namespace ai
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    virtual void create();
};
} // namespace fight
extern "C" void* __cdecl FUN_002343e0(const char*, void*);
struct Registry {
    void* FUN_00236760(void*);
};
extern "C" void* __cdecl FUN_00129fe0(Registry* registry) {
#define REGISTER(TYPE, TEXT)                                                                                 \
    {                                                                                                        \
        fight::ConditionFactoryCasterTemplate<hulkfight::ai::TYPE> caster;                                   \
        result = registry->FUN_00236760(FUN_002343e0(TEXT, &caster));                                        \
    }
    void* result;
    REGISTER(HasTargetCondition, "hasTarget")
    REGISTER(AcquireTargetCondition, "acquireTarget")
    REGISTER(TargetTypeCondition, "targetType")
    REGISTER(TargetDistanceCondition, "targetDistance")
    REGISTER(TargetDistanceXZCondition, "targetDistanceXZ")
    REGISTER(TargetDistanceYCondition, "targetDistanceY")
    REGISTER(TargetOrientationCondition, "targetOrientation")
    REGISTER(TargetArcCondition, "targetArc")
    REGISTER(TargetVelocityCondition, "targetVelocity")
    REGISTER(TargetVelocityXZCondition, "targetVelocityXZ")
    REGISTER(TargetVelocityYCondition, "targetVelocityY")
    REGISTER(TargetDirectionCondition, "targetDirection")
    REGISTER(TargetDirectionXZCondition, "targetDirectionXZ")
    REGISTER(TargetDirectionYCondition, "targetDirectionY")
    REGISTER(TargetAngleYCondition, "targetAngleY")
    REGISTER(CanSeeTargetCondition, "canSeeTarget")
    REGISTER(TargetInvincibleCondition, "targetInvincible")
    REGISTER(TargetFirstShotCondition, "targetFirstShot")
    REGISTER(ProjectileDistanceCondition, "projectileDistance")
    return result;
}
} // namespace fn_00129fe0
#undef REGISTER

