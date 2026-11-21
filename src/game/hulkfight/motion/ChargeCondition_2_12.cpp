// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a910..0x0016c600 (kind game, layer game, confidence high, dominant class hulkfight::motion::RayCastCondition); was game/hulkfight/motion/RayCastCondition_3.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "decls/data/game/global.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "decls/data/engine/fight.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f45cd32f {
#define TREE_TU_END }
namespace fn_f45cd32f {} using namespace fn_f45cd32f;
#include "game/hulkfight/motion.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f5579237 { struct A_165430 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct A_165950 { bool SetRageMode_00165950(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct C_165390 { char SetCharge_00165390(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct C_1655a0 { char SetCompare_001655a0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct O_165580 { bool SetCompare_00165580(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct O_165720 { char SetHealth_00165720(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct O_1659f0 { bool SetConstant_001659f0(void *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_165380 { char SetCompare_00165380(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1653a0 { bool SetType_001653a0(void *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1653b0 { bool SetCompare_001653b0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1653c0 { bool SetMotionState_001653c0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_165550 { char Fn(char); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_165570 { bool Set(char); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_165590 { bool SetLocomotionMotionState_00165590(void *); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1656c0 { char SetCompare_001656c0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1656d0 { bool SetLocomotionMotionState_001656d0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_165710 { bool SetCompare_00165710(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1659d0 { char SetCompare_001659d0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct Obj_1659e0 { bool SetHealth_001659e0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct X_1653d0 { char Set(char); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct X_165540 { char Fn(char); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct X_165560 { char Set(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct X_1655b0 { bool SetConstant_001655b0(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct X_165730 { char SetConstant_00165730(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
namespace fn_f5579237 { struct X_165940 { bool SetCompare_00165940(int); }; }   // (gx3, D18) setters, as defined in unk_165380.cpp
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f45cd32f {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b7408;
} // namespace fn_f45cd32f
namespace fight {
class ConditionFactoryCaster_16a910 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VelocityXZAngleCondition_16a910 {};
} }
namespace fight {
class ConditionFactoryCaster_16a970 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class RayCastCondition_16a970 {};
} }
namespace fn_f45cd32f {
extern char DAT_004b74c8;
class Condition_16aa10 {
  public:
    virtual void f();
};
class ConditionFactoryCasterTemplate_16aa10 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* hulk_at_00491ca8;
extern void* hulk_at_004b7580;
} // namespace fn_f45cd32f
namespace fight {
class ConditionFactoryCaster_16aa70 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VelocityXZCondition_16aa70 {};
} }
namespace fn_f45cd32f {
extern char DAT_004b7640;
} // namespace fn_f45cd32f
namespace fight {
class ConditionFactory_16ab50 {
  public:
    virtual ~ConditionFactory_16ab50() throw();
};
}
namespace fight {
template <class T> class ConditionFactoryTemplate_16ab50 : public ConditionFactory_16ab50 {};
}
namespace fight {
class ConditionFactoryCaster_16ab50 {
  public:
    virtual bool vfunc_0(ConditionFactory_16ab50*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class RageModeStateCondition_16ab50;
} }
namespace fn_f45cd32f {
class ShoreNearCondition_16abb0;
extern char DAT_004b7890;
} // namespace fn_f45cd32f
namespace fight {
class ConditionFactoryCaster_16abb0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class ConditionFactoryCaster_16ac10 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HealthPercentCondition_16ac10 {};
} }
namespace fn_f45cd32f {
extern char DAT_004b7948;
extern int typeA;
extern int hulk_at_004b7a08;
} // namespace fn_f45cd32f
namespace fight {
class ConditionFactoryCaster_16ac90 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
}
namespace fn_f45cd32f {
extern char DAT_004b7ac8;
} // namespace fn_f45cd32f
namespace fight {
class ConditionFactoryCaster_16acf0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VelocityAnimatedCondition_16acf0 {};
} }
namespace fn_f45cd32f {
extern char DAT_004b7b88;
} // namespace fn_f45cd32f
namespace fight {
class ConditionFactoryCaster_16ad70 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class HealthCondition_16ad70;
} }
namespace fn_f45cd32f {
extern "C" void __cdecl FUN_001653d0();
extern "C" char DAT_00416a88[];
// (dg1) the registered list and its count are the game's items DAT_004e11e8 (records.h: pointer-sized) and DAT_004e11ec,
// not local definitions that only the Wine link bound to them by address
void* FUN_0008d690(unsigned int size);
struct Init_16afa0 {
};
struct Param {
    void* vptr;
    char pad4[12];
    void* field10;
};
} // namespace fn_f45cd32f
inline void* operator new(size_t, void* p) throw() { return p; }
namespace hulkfight { namespace motion {
class VelocityCondition_16b000 {
public:
    char FUN_001653e0(int); /* (unb4) as defined; address taken only */
    char FUN_001653f0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f45cd32f {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f45cd32f
namespace fight {
template <class T>
class ParamEnumConstList_16b000 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b000(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16b000 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b000(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f45cd32f {
} // namespace fn_f45cd32f
namespace hulkfight { namespace motion {
class VelocityYCondition_16b0b0 {
public:
    bool FUN_00165400(int); /* (unb4) as defined; address taken only */
    bool FUN_00165410(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16b0b0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b0b0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16b0b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b0b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VelocityAnimatedXZCondition_16b160 {
public:
    bool FUN_00165420(int); /* (unb4) as defined; address taken only */
    char FUN_00165430(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16b160 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b160(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16b160 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b160(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class TurningVelocityCondition_16b210 {
public:
    char FUN_00165510(int); /* (unb4) as defined; address taken only */
    char FUN_00165520(float); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16b210 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b210(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16b210 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b210(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class TargetingCondition_16b540 {
public:
    bool FUN_00165690(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f45cd32f {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f45cd32f
namespace fight {
template <class T>
class ParamBool_16b540 : public ParamBoolBase {
public:
    ParamBool_16b540(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VelocityAnimatedYCondition_16b5a0 {
public:
    char FUN_001656a0(int); /* (unb4) as defined; address taken only */
    bool FUN_001656b0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16b5a0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b5a0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16b5a0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b5a0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class TargetHealthPercentCondition_16b710 {
public:
    char FUN_001656e0(int); /* (unb4) as defined; address taken only */
    char FUN_00165700(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16b710 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b710(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16b710 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b710(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CharacterPropStatusCondition_16b920 {
public:
    bool FUN_00165750(int); /* (unb4) as defined; address taken only */
    char FUN_00165770(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16b920 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b920(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16b920 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b920(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VelocityXZAngleCondition_16b9d0 {
public:
    char FUN_00165780(float); /* (unb4) as defined; address taken only */
    bool FUN_001657a0(float); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_16b9d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b9d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class InLoadedRoomCondition_16ba70 {
public:
    char FUN_001658d0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_16ba70 : public ParamBoolBase {
public:
    ParamBool_16ba70(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VelocityXZCondition_16bad0 {
public:
    bool FUN_001658e0(int); /* (unb4) as defined; address taken only */
    char FUN_001658f0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16bad0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16bad0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16bad0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16bad0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VelocityAnimatedXZAngleCondition_16bb80 {
public:
    char FUN_00165900(float); /* (unb4) as defined; address taken only */
    bool FUN_00165920(float); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_16bb80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16bb80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class ShoreNearCondition_16bce0 {
public:
    char FUN_00165960(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_16bce0 : public ParamBoolBase {
public:
    ParamBool_16bce0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class HealthPercentCondition_16bd40 {
public:
    bool FUN_00165970(int); /* (unb4) as defined; address taken only */
    char FUN_00165980(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16bd40 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16bd40(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16bd40 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16bd40(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class ThinkingCondition_16bdf0 {
public:
    char FUN_001659a0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_16bdf0 : public ParamBoolBase {
public:
    ParamBool_16bdf0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VelocityAnimatedCondition_16be50 {
public:
    bool FUN_001659b0(int); /* (unb4) as defined; address taken only */
    char FUN_001659c0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_16be50 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16be50(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_16be50 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16be50(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f45cd32f {
extern "C" char DAT_004170c8[];   // fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vftable
struct ConditionFactoryCasterTemplate_16c000 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
extern "C" void __cdecl FUN_002343e0(void*, ConditionFactoryCasterTemplate_16c000*);
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};

} // namespace fn_f45cd32f

// 0x0016a080 fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_0 (30 B): matches/0x0016a080.cpp
// sym: ??_G?$ParamEnumConstList@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ChargeCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a0a0 fight::ParamFloatConstRange<hulkfight::motion::ChargeCondition>::vfunc_0 (30 B): matches/0x0016a0a0.cpp
// sym: ??_G?$ParamFloatConstRange@VChargeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from ChargeCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a100 fight::ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>::vfunc_0 (30 B): matches/0x0016a100.cpp
// sym: ??_G?$ParamEnumConstList@VTargetMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a160 fight::ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>::vfunc_0 (30 B): matches/0x0016a160.cpp
// sym: ??_G?$ParamBool@VIntentionButtonDownAnyCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a1c0 fight::ParamEnumConstList<hulkfight::motion::VelocityCondition>::vfunc_0 (30 B): matches/0x0016a1c0.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a1e0 fight::ParamFloatConstRange<hulkfight::motion::VelocityCondition>::vfunc_0 (30 B): matches/0x0016a1e0.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a240 fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_0 (30 B): matches/0x0016a240.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityYCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a260 fight::ParamFloatConstRange<hulkfight::motion::VelocityYCondition>::vfunc_0 (30 B): matches/0x0016a260.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityYCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityYCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a2c0 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_0 (30 B): matches/0x0016a2c0.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityAnimatedXZCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityAnimatedXZCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a2e0 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_0 (30 B): matches/0x0016a2e0.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityAnimatedXZCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityAnimatedXZCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a3e0 fight::ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>::vfunc_0 (30 B): matches/0x0016a3e0.cpp
// sym: ??_G?$ParamEnumConstList@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TurningVelocityCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a400 fight::ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>::vfunc_0 (30 B): matches/0x0016a400.cpp
// sym: ??_G?$ParamFloatConstRange@VTurningVelocityCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TurningVelocityCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a460 fight::ParamBool<hulkfight::motion::IntentionInputCondition>::vfunc_0 (30 B): matches/0x0016a460.cpp
// sym: ??_G?$ParamBool@VIntentionInputCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastConeCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a4c0 fight::ParamEnumConstList<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_0 (30 B): matches/0x0016a4c0.cpp
// sym: ??_G?$ParamEnumConstList@VLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastConeCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a520 fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_0 (30 B): matches/0x0016a520.cpp
// sym: ??_G?$ParamEnumConstList@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RayCastConeCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a620 fight::ParamBool<hulkfight::motion::TargetingCondition>::vfunc_0 (30 B): matches/0x0016a620.cpp
// sym: ??_G?$ParamBool@VTargetingCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityAnimatedYCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a680 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_0 (30 B): matches/0x0016a680.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityAnimatedYCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a6a0 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_0 (30 B): matches/0x0016a6a0.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from VelocityAnimatedYCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a700 fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_0 (30 B): matches/0x0016a700.cpp
// sym: ??_G?$ParamEnumConstList@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetHealthPercentCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a760 fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0 (30 B): matches/0x0016a760.cpp
// sym: ??_G?$ParamEnumConstList@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetHealthPercentCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a780 fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0 (30 B): matches/0x0016a780.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from TargetHealthPercentCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a7e0 fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_0 (30 B): matches/0x0016a7e0.cpp
// sym: ??_G?$ParamEnumConstList@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from GrappleHealthCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a800 fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>::vfunc_0 (30 B): matches/0x0016a800.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from GrappleHealthCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a860 fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x0016a860.cpp
// sym: ??_G?$ParamString@VTargetCharacterTemplateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CharacterPropStatusCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a8c0 fight::ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>::vfunc_0 (30 B): matches/0x0016a8c0.cpp
// sym: ??_G?$ParamEnumConstList@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CharacterPropStatusCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a8e0 fight::ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>::vfunc_0 (30 B): matches/0x0016a8e0.cpp
// sym: ??_G?$ParamFloatConstRange@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CharacterPropStatusCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0016ade0 / FUN_0016aee0 / FUN_0016afa0 / FUN_0016b000 / FUN_0016b0b0 / FUN_0016b160 / FUN_0016b210 / FUN_0016b2c0 / FUN_0016b3c0 / FUN_0016b480 / FUN_0016b540 / FUN_0016b5a0 / FUN_0016b650 / FUN_0016b710 / FUN_0016b7c0 / FUN_0016b8c0 / FUN_0016b920 / FUN_0016b9d0 / FUN_0016ba70 / FUN_0016bad0 / FUN_0016bb80 / FUN_0016bc20 / FUN_0016bce0 / FUN_0016bd40 / FUN_0016bdf0 / FUN_0016be50 / FUN_0016bf00)



// 0x0016a910 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_0 (36 B): matches/0x0016a910.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7408, 0) != 0;
}


// 0x0016a940 fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::vfunc_0 (30 B): matches/0x0016a940.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016a970 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition>::vfunc_0 (36 B): matches/0x0016a970.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRayCastCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b74c8, 0) != 0;
}


// 0x0016aa10 fight::ConditionFactoryCasterTemplate<hulkfight::motion::InLoadedRoomCondition>::vfunc_0 (36 B): matches/0x0016aa10.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VInLoadedRoomCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::InLoadedRoomCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004b7580, 0) != 0;
}


// 0x0016aa40 fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::vfunc_0 (30 B): matches/0x0016aa40.cpp
// sym: ??_G?$ParamBool@VInLoadedRoomCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016aa70 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_0 (36 B): matches/0x0016aa70.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityXZCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_00491ca8), (void*)(hulk_uintptr)(&DAT_004b7640), 0)) != 0;
}


// 0x0016aaa0 fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_0 (30 B): matches/0x0016aaa0.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016aac0 fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::vfunc_0 (30 B): matches/0x0016aac0.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016aaf0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_0 (36 B): matches/0x0016aaf0.cpp [wrapped: conflict: DAT_00491ca8; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityAnimatedXZAngleCondition@motion@hulkfight@fn_0016aaf0@@@fight@fn_0016aaf0@@UAE_NPAX@Z
namespace fn_0016aaf0 {
extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class VelocityAnimatedXZAngleCondition {};
} // namespace motion
} // namespace hulkfight
extern const int DAT_00491ca8, DAT_004b7708;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_0(
    void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7708, 0) != 0;
}
} // namespace fn_0016aaf0


// 0x0016ab20 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_0 (30 B): matches/0x0016ab20.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityAnimatedXZAngleCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016ab50 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_0 (36 B): matches/0x0016ab50.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRageModeStateCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
// the original asks whether a factory is the RageModeStateCondition one: dynamic_cast to
// fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition> (RTTI 0x004b77d0) from fight::ConditionFactory
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_0(void* __p0) { fight::ConditionFactory_16ab50 * p = (fight::ConditionFactory_16ab50 *)__p0;

    return ((fight::ConditionFactoryTemplate_16ab50<hulkfight::motion::RageModeStateCondition_16ab50>*)dynamic_cast< ::fight::ConditionFactoryTemplate< ::hulkfight::motion::RageModeStateCondition>*>((::fight::ConditionFactory*)(p))) != 0;
}


// 0x0016ab80 fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_0 (30 B): matches/0x0016ab80.cpp
// sym: ??_G?$ParamEnumConstList@VRageModeStateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016abb0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_0 (36 B): matches/0x0016abb0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VShoreNearCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7890, 0) != 0;
}


// 0x0016abe0 fight::ParamBool<hulkfight::motion::ShoreNearCondition>::vfunc_0 (30 B): matches/0x0016abe0.cpp
// sym: ??_G?$ParamBool@VShoreNearCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016ac10 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_0 (36 B): matches/0x0016ac10.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7948, 0) != 0;
}


// 0x0016ac40 fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_0 (30 B): matches/0x0016ac40.cpp
// sym: ??_G?$ParamEnumConstList@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016ac60 fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::vfunc_0 (30 B): matches/0x0016ac60.cpp
// sym: ??_G?$ParamFloatConstRange@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016ac90 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition>::vfunc_0 (36 B): matches/0x0016ac90.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VThinkingCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &typeA, &hulk_at_004b7a08, 0) != 0;
}


// 0x0016acc0 fight::ParamBool<hulkfight::motion::ThinkingCondition>::vfunc_0 (30 B): matches/0x0016acc0.cpp
// sym: ??_G?$ParamBool@VThinkingCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016acf0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_0 (36 B): matches/0x0016acf0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7ac8, 0) != 0;
}


// 0x0016ad20 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_0 (30 B): matches/0x0016ad20.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016ad40 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::vfunc_0 (30 B): matches/0x0016ad40.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016ad70 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthCondition>::vfunc_0 (36 B): matches/0x0016ad70.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHealthCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7b88, 0) != 0;
}


// 0x0016ada0 fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_0 (30 B): matches/0x0016ada0.cpp
// sym: ??_G?$ParamEnumConstList@VHealthCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x0016adc0 fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::vfunc_0 (30 B): matches/0x0016adc0.cpp
// sym: ??_G?$ParamFloatConstRange@VHealthCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_f45cd32f {

} // namespace fn_f45cd32f

namespace fn_f45cd32f {

} // namespace fn_f45cd32f

// 0x0016ade0 FUN_0016ade0 (245 B): matches/0x0016ade0.cpp
// sym: _FUN_0016ade0
// (gx2, D18) from RayCastCondition_3.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::motion::ChargeCondition>, ParamFloatConstRange<hulkfight::motion::ChargeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016ade0()
{
    if (DAT_004e11dc == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::ChargeCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f5579237::Obj_165380::SetCompare_00165380);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ChargeCondition>("charge", &fn_f5579237::C_165390::SetCharge_00165390);
        params[2] = new ::fight::ParamEnumConstList< ::hulkfight::motion::ChargeCondition>("type", (void*)&DAT_004b4d7c, 3, &fn_f5579237::Obj_1653a0::SetType_001653a0);
        FUN_002347b0(&DAT_004e11d8, params, 3);
    }
    DAT_004e11dc++;
}



// 0x0016aee0 FUN_0016aee0 (192 B): matches/0x0016aee0.cpp
// sym: ?FUN_0016aee0@@YAXXZ
// (gx2, D18) from RayCastCondition_3.iso_0016aee0.cpp; constructs the real ParamEnumConstList<hulkfight::motion::TargetMotionStateCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_0016aee0()
{
    if (DAT_004e11e4 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::TargetMotionStateCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f5579237::Obj_1653b0::SetCompare_001653b0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::TargetMotionStateCondition>("motionState", (void*)&DAT_0048f57c, DAT_003f5bb8, &fn_f5579237::Obj_1653c0::SetMotionState_001653c0);
        FUN_002347b0(&DAT_004e11e0, params, 2);
    }
    DAT_004e11e4++;
}



// 0x0016afa0 FUN_0016afa0 (95 B): matches/0x0016afa0.cpp
// sym: _FUN_0016afa0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::IntentionButtonDownAnyCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016afa0()
{
    if ((*(int*)&DAT_004e11ec) == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::IntentionButtonDownAnyCondition>("anyButtonDown", &fn_f5579237::X_1653d0::Set);
        FUN_002347b0(&DAT_004e11e8, params, 1);
    }
    (*(int*)&DAT_004e11ec)++;
}



// 0x0016b000 FUN_0016b000 (176 B): matches/0x0016b000.cpp
// sym: _FUN_0016b000
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::VelocityCondition>, ParamFloatConstRange<hulkfight::motion::VelocityCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b000()
{
    if (DAT_004e11f4 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::VelocityCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_1653e0::FUN_001653e0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityCondition>("velocity", &owners::X_1653f0::FUN_001653f0);
        FUN_002347b0(&DAT_004e11f0, params, 2);
    }
    DAT_004e11f4++;
}



// 0x0016b0b0 FUN_0016b0b0 (176 B): matches/0x0016b0b0.cpp
// sym: _FUN_0016b0b0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::VelocityYCondition>, ParamFloatConstRange<hulkfight::motion::VelocityYCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b0b0()
{
    if (DAT_004e11fc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::VelocityYCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_165400::FUN_00165400);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityYCondition>("velocity", &owners::Obj_165410::FUN_00165410);
        FUN_002347b0(&DAT_004e11f8, params, 2);
    }
    DAT_004e11fc++;
}



// 0x0016b160 FUN_0016b160 (176 B): matches/0x0016b160.cpp
// sym: _FUN_0016b160
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::VelocityAnimatedXZCondition>, ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b160()
{
    if (DAT_004e1204 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::VelocityAnimatedXZCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_165420::FUN_00165420);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityAnimatedXZCondition>("velocity", &fn_f5579237::A_165430::Set);
        FUN_002347b0(&DAT_004e1200, params, 2);
    }
    DAT_004e1204++;
}



// 0x0016b210 FUN_0016b210 (176 B): matches/0x0016b210.cpp
// sym: _FUN_0016b210
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::TurningVelocityCondition>, ParamFloatConstRange<hulkfight::motion::TurningVelocityCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b210()
{
    if (DAT_004e1214 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::TurningVelocityCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_165510::FUN_00165510);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TurningVelocityCondition>("turningVelocity", &owners::Thing_165520::FUN_00165520);
        FUN_002347b0(&DAT_004e1210, params, 2);
    }
    DAT_004e1214++;
}



// 0x0016b2c0 FUN_0016b2c0 (256 B): matches/0x0016b2c0.cpp
// sym: ?FUN_0016b2c0@@YAXXZ
// (gx2, D18) from RayCastCondition_3.iso_0016b2c0.cpp; constructs the real ParamBool<hulkfight::motion::IntentionInputCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_0016b2c0()
{
    if (DAT_004e121c == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::IntentionInputCondition>("buttonDown", &fn_f5579237::X_165540::Fn);
        params[1] = new ::fight::ParamBool< ::hulkfight::motion::IntentionInputCondition>("buttonPressed", &fn_f5579237::Obj_165550::Fn);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::IntentionInputCondition>("axisDown", &fn_f5579237::X_165560::Set);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::IntentionInputCondition>("axisPressed", &fn_f5579237::Obj_165570::Set);
        FUN_002347b0(&DAT_004e1218, params, 4);
    }
    DAT_004e121c++;
}



// 0x0016b3c0 FUN_0016b3c0 (192 B): matches/0x0016b3c0.cpp
// sym: ?FUN_0016b3c0@@YAXXZ
// (gx2, D18) from RayCastCondition_3.iso_0016b3c0.cpp; constructs the real ParamEnumConstList<hulkfight::motion::LocomotionMotionStateCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_0016b3c0()
{
    if (DAT_004e1224 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::LocomotionMotionStateCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f5579237::O_165580::SetCompare_00165580);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::LocomotionMotionStateCondition>("locomotionMotionState", (void*)&DAT_0048f590, DAT_003f5bbc, &fn_f5579237::Obj_165590::SetLocomotionMotionState_00165590);
        FUN_002347b0(&DAT_004e1220, params, 2);
    }
    DAT_004e1224++;
}



// 0x0016b480 FUN_0016b480 (190 B): matches/0x0016b480.cpp
// sym: _FUN_0016b480
// (gx2, D18) from RayCastCondition_3.iso_0016b480.cpp; constructs the real ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b480()
{
    if (DAT_004e122c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::GrappleReactionTypeCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f5579237::C_1655a0::SetCompare_001655a0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::GrappleReactionTypeCondition>("constant", (void*)&DAT_004b4d98, 3, &fn_f5579237::X_1655b0::SetConstant_001655b0);
        FUN_002347b0(&DAT_004e1228, params, 2);
    }
    DAT_004e122c++;
}



// 0x0016b540 FUN_0016b540 (95 B): matches/0x0016b540.cpp
// sym: _FUN_0016b540
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::TargetingCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b540()
{
    if (DAT_004e123c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::TargetingCondition>("isTargeting", &owners::Obj_165690::FUN_00165690);
        FUN_002347b0(&DAT_004e1238, params, 1);
    }
    DAT_004e123c++;
}



// 0x0016b5a0 FUN_0016b5a0 (176 B): matches/0x0016b5a0.cpp
// sym: _FUN_0016b5a0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>, ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b5a0()
{
    if (DAT_004e1244 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::VelocityAnimatedYCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_1656a0::FUN_001656a0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityAnimatedYCondition>("velocity", &owners::X_1656b0::FUN_001656b0);
        FUN_002347b0(&DAT_004e1240, params, 2);
    }
    DAT_004e1244++;
}



// 0x0016b650 FUN_0016b650 (192 B): matches/0x0016b650.cpp
// sym: _FUN_0016b650
// (gx2, D18) from RayCastCondition_3.iso_0016b650.cpp; constructs the real ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b650()
{
    if (DAT_004e124c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::TargetLocomotionMotionStateCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f5579237::Obj_1656c0::SetCompare_001656c0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::TargetLocomotionMotionStateCondition>("locomotionMotionState", (void*)&DAT_0048f590, DAT_003f5bbc, &fn_f5579237::Obj_1656d0::SetLocomotionMotionState_001656d0);
        FUN_002347b0(&DAT_004e1248, params, 2);
    }
    DAT_004e124c++;
}



// 0x0016b710 FUN_0016b710 (176 B): matches/0x0016b710.cpp
// sym: _FUN_0016b710
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>, ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b710()
{
    if (DAT_004e1254 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::TargetHealthPercentCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_1656e0::FUN_001656e0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::TargetHealthPercentCondition>("percent", &owners::Obj_165700::FUN_00165700);
        FUN_002347b0(&DAT_004e1250, params, 2);
    }
    DAT_004e1254++;
}



// 0x0016b7c0 FUN_0016b7c0 (245 B): matches/0x0016b7c0.cpp
// sym: _FUN_0016b7c0
// (gx2, D18) from RayCastCondition_3.iso_0016b7c0.cpp; constructs the real ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>, ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b7c0()
{
    if (DAT_004e125c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::GrappleHealthCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f5579237::Obj_165710::SetCompare_00165710);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrappleHealthCondition>("health", &fn_f5579237::O_165720::SetHealth_00165720);
        params[2] = new ::fight::ParamEnumConstList< ::hulkfight::motion::GrappleHealthCondition>("constant", (void*)&DAT_004b4d88, 4, &fn_f5579237::X_165730::SetConstant_00165730);
        FUN_002347b0(&DAT_004e1258, params, 3);
    }
    DAT_004e125c++;
}



// 0x0016b8c0 FUN_0016b8c0 (95 B): matches/0x0016b8c0.cpp
// sym: _FUN_0016b8c0
// (gx2, D18) rewritten; constructs the real ParamString<hulkfight::motion::TargetCharacterTemplateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b8c0()
{
    if (DAT_004e1264 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamString< ::hulkfight::motion::TargetCharacterTemplateCondition>("text", &owners::Thing_166230::FUN_00166230);
        FUN_002347b0(&DAT_004e1260, params, 1);
    }
    DAT_004e1264++;
}



// 0x0016b920 FUN_0016b920 (176 B): matches/0x0016b920.cpp
// sym: _FUN_0016b920
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::CharacterPropStatusCondition>, ParamFloatConstRange<hulkfight::motion::CharacterPropStatusCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b920()
{
    if (DAT_004e126c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CharacterPropStatusCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::C_165750::FUN_00165750);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::CharacterPropStatusCondition>("number", &owners::Obj_165770::FUN_00165770);
        FUN_002347b0(&DAT_004e1268, params, 2);
    }
    DAT_004e126c++;
}



// 0x0016b9d0 FUN_0016b9d0 (158 B): matches/0x0016b9d0.cpp
// sym: _FUN_0016b9d0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016b9d0()
{
    if (DAT_004e1274 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityXZAngleCondition>("angle", &owners::Obj_165780::FUN_00165780);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityXZAngleCondition>("arc", &owners::A_1657a0::FUN_001657a0);
        FUN_002347b0(&DAT_004e1270, params, 2);
    }
    DAT_004e1274++;
}



// 0x0016ba70 FUN_0016ba70 (95 B): matches/0x0016ba70.cpp
// sym: _FUN_0016ba70
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::InLoadedRoomCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016ba70()
{
    if (DAT_004e1284 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::InLoadedRoomCondition>("isInLoadedRoom", &owners::T_1658d0::FUN_001658d0);
        FUN_002347b0(&DAT_004e1280, params, 1);
    }
    DAT_004e1284++;
}



// 0x0016bad0 FUN_0016bad0 (176 B): matches/0x0016bad0.cpp
// sym: _FUN_0016bad0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::VelocityXZCondition>, ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016bad0()
{
    if (DAT_004e128c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::VelocityXZCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_1658e0::FUN_001658e0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityXZCondition>("velocity", &owners::X_1658f0::FUN_001658f0);
        FUN_002347b0(&DAT_004e1288, params, 2);
    }
    DAT_004e128c++;
}



// 0x0016bb80 FUN_0016bb80 (158 B): matches/0x0016bb80.cpp
// sym: _FUN_0016bb80
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016bb80()
{
    if (DAT_004e1294 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityAnimatedXZAngleCondition>("angle", &owners::Angle_165900::FUN_00165900);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityAnimatedXZAngleCondition>("arc", &owners::O_165920::FUN_00165920);
        FUN_002347b0(&DAT_004e1290, params, 2);
    }
    DAT_004e1294++;
}



// 0x0016bc20 FUN_0016bc20 (192 B): matches/0x0016bc20.cpp
// sym: _FUN_0016bc20
// (gx2, D18) from RayCastCondition_3.iso_0016bc20.cpp; constructs the real ParamEnumConstList<hulkfight::motion::RageModeStateCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016bc20()
{
    if (DAT_004e129c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::RageModeStateCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f5579237::X_165940::SetCompare_00165940);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::RageModeStateCondition>("rageMode", (void*)&DAT_00496fd8, DAT_003fb900, &fn_f5579237::A_165950::SetRageMode_00165950);
        FUN_002347b0(&DAT_004e1298, params, 2);
    }
    DAT_004e129c++;
}



// 0x0016bce0 FUN_0016bce0 (95 B): matches/0x0016bce0.cpp
// sym: _FUN_0016bce0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::ShoreNearCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016bce0()
{
    if (DAT_004e12a4 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::ShoreNearCondition>("isNearShore", &owners::X_165960::FUN_00165960);
        FUN_002347b0(&DAT_004e12a0, params, 1);
    }
    DAT_004e12a4++;
}



// 0x0016bd40 FUN_0016bd40 (176 B): matches/0x0016bd40.cpp
// sym: _FUN_0016bd40
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::HealthPercentCondition>, ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016bd40()
{
    if (DAT_004e12ac == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::HealthPercentCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::O_165970::FUN_00165970);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HealthPercentCondition>("percent", &owners::C_165980::FUN_00165980);
        FUN_002347b0(&DAT_004e12a8, params, 2);
    }
    DAT_004e12ac++;
}



// 0x0016bdf0 FUN_0016bdf0 (95 B): matches/0x0016bdf0.cpp
// sym: _FUN_0016bdf0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::ThinkingCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016bdf0()
{
    if (DAT_004e12b4 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::ThinkingCondition>("thinking", &owners::Obj_1659a0::FUN_001659a0);
        FUN_002347b0(&DAT_004e12b0, params, 1);
    }
    DAT_004e12b4++;
}



// 0x0016be50 FUN_0016be50 (176 B): matches/0x0016be50.cpp
// sym: _FUN_0016be50
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>, ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016be50()
{
    if (DAT_004e12bc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::VelocityAnimatedCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::X_1659b0::FUN_001659b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::VelocityAnimatedCondition>("velocity", &owners::Obj_1659c0::FUN_001659c0);
        FUN_002347b0(&DAT_004e12b8, params, 2);
    }
    DAT_004e12bc++;
}



// 0x0016bf00 FUN_0016bf00 (245 B): matches/0x0016bf00.cpp
// sym: _FUN_0016bf00
// (gx2, D18) from RayCastCondition_3.iso_0016bf00.cpp; constructs the real ParamEnumConstList<hulkfight::motion::HealthCondition>, ParamFloatConstRange<hulkfight::motion::HealthCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0016bf00()
{
    if (DAT_004e12c4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::HealthCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f5579237::Obj_1659d0::SetCompare_001659d0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HealthCondition>("health", &fn_f5579237::Obj_1659e0::SetHealth_001659e0);
        params[2] = new ::fight::ParamEnumConstList< ::hulkfight::motion::HealthCondition>("constant", (void*)&DAT_004b4d88, 4, &fn_f5579237::O_1659f0::SetConstant_001659f0);
        FUN_002347b0(&DAT_004e12c0, params, 3);
    }
    DAT_004e12c4++;
}

namespace fn_f45cd32f {


// 0x0016c000 FUN_0016c000 (27 B): matches/0x0016c000.cpp
// sym: ?target@fn_f45cd32f@@YAXPAX@Z
void __cdecl target(void* p) {
    ConditionFactoryCasterTemplate_16c000 c;
    c.vftable = (void*)DAT_004170c8;   // (sweep-caster-fix1) the game's vftable by address
    FUN_002343e0(p, &c);
}


// 0x0016c100 fight::ParamNameConstList<hulkfight::motion::RayCastTargetCondition>::vfunc_7 (12 B): matches/0x0016c100.cpp
// sym: ?vfunc_6@ParamBranch@fn_f45cd32f@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}

} // namespace fn_f45cd32f

// 0x0016c1d0 fight::ParamNameConstList<hulkfight::motion::RayCastConeCondition>::vfunc_7 (12 B): matches/0x0016c1d0.cpp [wrapped: same definition as 0x0016c100 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0016c1d0@@UAEXPAX@Z
namespace fn_0016c1d0 {
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
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0016c1d0


// 0x0016c320 fight::ParamNameConstList<hulkfight::motion::RayCastCondition>::vfunc_7 (12 B): matches/0x0016c320.cpp [wrapped: same definition as 0x0016c100 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0016c320@@UAEXPAX@Z
namespace fn_0016c320 {
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
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_0016c320

