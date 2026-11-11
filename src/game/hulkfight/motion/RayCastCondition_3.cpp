// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a910..0x0016c600 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f45cd32f {
#define TREE_TU_END }
namespace fn_f45cd32f {} using namespace fn_f45cd32f;
#include "game/hulkfight/motion.h"

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
extern "C" int __cdecl check(void*, int, void*, void*, int);
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
extern "C" void* __cdecl castThing(void*, int, void*, void*, int);
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
extern "C" int gCount_16afa0 = 0;
extern "C" void* gSlot_16afa0 = 0;
void* FUN_0008d690(unsigned int size);
struct Init_16afa0 {
};
extern "C" void __cdecl FUN_002347b0(void**, void**, int);
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
    void FUN_001653e0();
    void FUN_001653f0();
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
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f45cd32f
namespace hulkfight { namespace motion {
class VelocityYCondition_16b0b0 {
public:
    void FUN_00165400();
    void FUN_00165410();
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
    void FUN_00165420();
    void FUN_00165430();
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
    void FUN_00165510();
    void FUN_00165520();
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
    void FUN_00165690();
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
    void FUN_001656a0();
    void FUN_001656b0();
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
    void FUN_001656e0();
    void FUN_00165700();
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
    void FUN_00165750();
    void FUN_00165770();
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
    void FUN_00165780();
    void FUN_001657a0();
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
    void FUN_001658d0();
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
    void FUN_001658e0();
    void FUN_001658f0();
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
    void FUN_00165900();
    void FUN_00165920();
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
    void FUN_00165960();
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
    void FUN_00165970();
    void FUN_00165980();
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
    void FUN_001659a0();
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
    void FUN_001659b0();
    void FUN_001659c0();
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
class ConditionFactoryCasterTemplate_16c000 {
  public:
    virtual void f();
};
extern "C" void __cdecl FUN_002343e0(void*, ConditionFactoryCasterTemplate_16c000*);
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};

} // namespace fn_f45cd32f

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
template <> fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::~ParamFloatConstRange() {}


// 0x0016a970 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition>::vfunc_0 (36 B): matches/0x0016a970.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRayCastCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b74c8, 0) != 0;
}


// 0x0016a9a0 fight::ParamVector<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016a9a0.cpp
// sym: ??_G?$ParamVector@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::RayCastCondition>::~ParamVector() {}


// 0x0016a9c0 fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016a9c0.cpp
// sym: ??_G?$ParamFloatConstRange@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::~ParamFloatConstRange() {}


// 0x0016a9e0 fight::ParamBool<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016a9e0.cpp
// sym: ??_G?$ParamBool@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::RayCastCondition>::~ParamBool() {}


// 0x0016aa10 fight::ConditionFactoryCasterTemplate<hulkfight::motion::InLoadedRoomCondition>::vfunc_0 (36 B): matches/0x0016aa10.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VInLoadedRoomCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::InLoadedRoomCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &hulk_at_00491ca8, &hulk_at_004b7580, 0) != 0;
}


// 0x0016aa40 fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::vfunc_0 (30 B): matches/0x0016aa40.cpp
// sym: ??_G?$ParamBool@VInLoadedRoomCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::InLoadedRoomCondition>::~ParamBool() {}


// 0x0016aa70 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_0 (36 B): matches/0x0016aa70.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityXZCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_00491ca8, &DAT_004b7640, 0) != 0;
}


// 0x0016aaa0 fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::vfunc_0 (30 B): matches/0x0016aaa0.cpp
// sym: ??_G?$ParamEnumConstList@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::VelocityXZCondition>::~ParamEnumConstList() {}


// 0x0016aac0 fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::vfunc_0 (30 B): matches/0x0016aac0.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityXZCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::VelocityXZCondition>::~ParamFloatConstRange() {}


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
template <> fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedXZAngleCondition>::~ParamFloatConstRange() {}


// 0x0016ab50 fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_0 (36 B): matches/0x0016ab50.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRageModeStateCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
// the original asks whether a factory is the RageModeStateCondition one: dynamic_cast to
// fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition> (RTTI 0x004b77d0) from fight::ConditionFactory
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_0(void* __p0) { fight::ConditionFactory_16ab50 * p = (fight::ConditionFactory_16ab50 *)__p0;

    return dynamic_cast<fight::ConditionFactoryTemplate_16ab50<hulkfight::motion::RageModeStateCondition_16ab50>*>(p) != 0;
}


// 0x0016ab80 fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_0 (30 B): matches/0x0016ab80.cpp
// sym: ??_G?$ParamEnumConstList@VRageModeStateCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::~ParamEnumConstList() {}


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
template <> fight::ParamBool<hulkfight::motion::ShoreNearCondition>::~ParamBool() {}


// 0x0016ac10 fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_0 (36 B): matches/0x0016ac10.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7948, 0) != 0;
}


// 0x0016ac40 fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_0 (30 B): matches/0x0016ac40.cpp
// sym: ??_G?$ParamEnumConstList@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::~ParamEnumConstList() {}


// 0x0016ac60 fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::vfunc_0 (30 B): matches/0x0016ac60.cpp
// sym: ??_G?$ParamFloatConstRange@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::~ParamFloatConstRange() {}


// 0x0016ac90 fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition>::vfunc_0 (36 B): matches/0x0016ac90.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VThinkingCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ThinkingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return castThing(p, 0, &typeA, &hulk_at_004b7a08, 0) != 0;
}


// 0x0016acc0 fight::ParamBool<hulkfight::motion::ThinkingCondition>::vfunc_0 (30 B): matches/0x0016acc0.cpp
// sym: ??_G?$ParamBool@VThinkingCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::ThinkingCondition>::~ParamBool() {}


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
template <> fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::~ParamEnumConstList() {}


// 0x0016ad40 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::vfunc_0 (30 B): matches/0x0016ad40.cpp
// sym: ??_G?$ParamFloatConstRange@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::~ParamFloatConstRange() {}


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
template <> fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::~ParamEnumConstList() {}


// 0x0016adc0 fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::vfunc_0 (30 B): matches/0x0016adc0.cpp
// sym: ??_G?$ParamFloatConstRange@VHealthCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::~ParamFloatConstRange() {}

namespace fn_f45cd32f {

// 0x0016afa0 FUN_0016afa0 (95 B): matches/0x0016afa0.cpp
// sym: _FUN_0016afa0
// data: gName_16afa0 = DAT_0041722c
extern "C" void FUN_0016afa0() {
    void* local;
    if (gCount_16afa0 != 0) {
        ++gCount_16afa0;
        return;
    }
    Param* p = (Param*)FUN_0008d690(0x18);
    if (p) {
        ((fight::ParamValueBool *)(((Init_16afa0*)p)))->FUN_00234860(DAT_0041722c);
        p->vptr = (void*)((hulk_intptr)DAT_00416a88);
        p->field10 = (void*)((hulk_intptr)(void (__cdecl*)())&FUN_001653d0);
        local = p;
    } else
        local = 0;
    FUN_002347b0((void**)&gSlot_16afa0, &local, 1);
    ++gCount_16afa0;
}


// 0x0016b000 FUN_0016b000 (176 B): equivalent/0x0016b000.cpp
// sym: _FUN_0016b000 @65bbcf56af44 @w2ee6ecf37182
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_0016b000 @ 0x0016b000
extern "C" void FUN_0016b000()
{
    if (DAT_004e11f4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16b000<hulkfight::motion::VelocityCondition_16b000>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b000<hulkfight::motion::VelocityCondition_16b000>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::VelocityCondition_16b000::FUN_001653e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b000<hulkfight::motion::VelocityCondition_16b000>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b000<hulkfight::motion::VelocityCondition_16b000>("velocity", &hulkfight::motion::VelocityCondition_16b000::FUN_001653f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e11f0), params, 2);
    }
    DAT_004e11f4++;
}


// 0x0016b0b0 FUN_0016b0b0 (176 B): equivalent/0x0016b0b0.cpp
// sym: _FUN_0016b0b0 @5cfe696330be @we16a982132fc
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016b0b0 @ 0x0016b0b0
extern "C" void FUN_0016b0b0()
{
    if (DAT_004e11fc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16b0b0<hulkfight::motion::VelocityYCondition_16b0b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b0b0<hulkfight::motion::VelocityYCondition_16b0b0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::VelocityYCondition_16b0b0::FUN_00165400);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b0b0<hulkfight::motion::VelocityYCondition_16b0b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b0b0<hulkfight::motion::VelocityYCondition_16b0b0>("velocity", &hulkfight::motion::VelocityYCondition_16b0b0::FUN_00165410);
        FUN_002347b0(((ParamRegistry*)&DAT_004e11f8), params, 2);
    }
    DAT_004e11fc++;
}


// 0x0016b160 FUN_0016b160 (176 B): equivalent/0x0016b160.cpp
// sym: _FUN_0016b160 @9a742b4e728d @w277339f15ed6
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_0016b160 @ 0x0016b160
extern "C" void FUN_0016b160()
{
    if (DAT_004e1204 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16b160<hulkfight::motion::VelocityAnimatedXZCondition_16b160>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b160<hulkfight::motion::VelocityAnimatedXZCondition_16b160>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::VelocityAnimatedXZCondition_16b160::FUN_00165420);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b160<hulkfight::motion::VelocityAnimatedXZCondition_16b160>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b160<hulkfight::motion::VelocityAnimatedXZCondition_16b160>("velocity", &hulkfight::motion::VelocityAnimatedXZCondition_16b160::FUN_00165430);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1200), params, 2);
    }
    DAT_004e1204++;
}


// 0x0016b210 FUN_0016b210 (176 B): equivalent/0x0016b210.cpp
// sym: _FUN_0016b210 @d078a14366b8 @w46927a39d6ca
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_0016b210 @ 0x0016b210
extern "C" void FUN_0016b210()
{
    if (DAT_004e1214 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16b210<hulkfight::motion::TurningVelocityCondition_16b210>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b210<hulkfight::motion::TurningVelocityCondition_16b210>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::TurningVelocityCondition_16b210::FUN_00165510);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b210<hulkfight::motion::TurningVelocityCondition_16b210>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b210<hulkfight::motion::TurningVelocityCondition_16b210>("turningVelocity", &hulkfight::motion::TurningVelocityCondition_16b210::FUN_00165520);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1210), params, 2);
    }
    DAT_004e1214++;
}


// 0x0016b540 FUN_0016b540 (95 B): equivalent/0x0016b540.cpp
// sym: _FUN_0016b540 @afb279ff636a @w21ba9d3b4660
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0016b540 @ 0x0016b540
extern "C" void FUN_0016b540()
{
    if (DAT_004e123c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_16b540<hulkfight::motion::TargetingCondition_16b540>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_16b540<hulkfight::motion::TargetingCondition_16b540>("isTargeting", &hulkfight::motion::TargetingCondition_16b540::FUN_00165690);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1238), params, 1);
    }
    DAT_004e123c++;
}


// 0x0016b5a0 FUN_0016b5a0 (176 B): equivalent/0x0016b5a0.cpp
// sym: _FUN_0016b5a0 @010eb0f86f33 @w5a12fea2dc6e
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_0016b5a0 @ 0x0016b5a0
extern "C" void FUN_0016b5a0()
{
    if (DAT_004e1244 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16b5a0<hulkfight::motion::VelocityAnimatedYCondition_16b5a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b5a0<hulkfight::motion::VelocityAnimatedYCondition_16b5a0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::VelocityAnimatedYCondition_16b5a0::FUN_001656a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b5a0<hulkfight::motion::VelocityAnimatedYCondition_16b5a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b5a0<hulkfight::motion::VelocityAnimatedYCondition_16b5a0>("velocity", &hulkfight::motion::VelocityAnimatedYCondition_16b5a0::FUN_001656b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1240), params, 2);
    }
    DAT_004e1244++;
}


// 0x0016b710 FUN_0016b710 (176 B): equivalent/0x0016b710.cpp
// sym: _FUN_0016b710 @53f3dedc3108 @w7d5c17e8fef2
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_0016b710 @ 0x0016b710
extern "C" void FUN_0016b710()
{
    if (DAT_004e1254 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16b710<hulkfight::motion::TargetHealthPercentCondition_16b710>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b710<hulkfight::motion::TargetHealthPercentCondition_16b710>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::TargetHealthPercentCondition_16b710::FUN_001656e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b710<hulkfight::motion::TargetHealthPercentCondition_16b710>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b710<hulkfight::motion::TargetHealthPercentCondition_16b710>("percent", &hulkfight::motion::TargetHealthPercentCondition_16b710::FUN_00165700);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1250), params, 2);
    }
    DAT_004e1254++;
}

} // namespace fn_f45cd32f

// 0x0016b8c0 FUN_0016b8c0 (95 B): equivalent/0x0016b8c0.cpp [wrapped: conflict: fight::ParamString]
// sym: _FUN_0016b8c0 @678beaf13593 @wa21ba04a65b6
namespace fn_0016b8c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_0016b8c0 @ 0x0016b8c0


void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class TargetCharacterTemplateCondition {
public:
    void FUN_00166230();
};
}
}

class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0016b8c0()
{
    if (DAT_004e1264 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<hulkfight::motion::TargetCharacterTemplateCondition>("text", &hulkfight::motion::TargetCharacterTemplateCondition::FUN_00166230);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1260), params, 1);
    }
    DAT_004e1264++;
}
} // namespace fn_0016b8c0

namespace fn_f45cd32f {

// 0x0016b920 FUN_0016b920 (176 B): equivalent/0x0016b920.cpp
// sym: _FUN_0016b920 @7e01e3481016 @w1324e689dbe4
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016b920 @ 0x0016b920
extern "C" void FUN_0016b920()
{
    if (DAT_004e126c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16b920<hulkfight::motion::CharacterPropStatusCondition_16b920>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b920<hulkfight::motion::CharacterPropStatusCondition_16b920>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::CharacterPropStatusCondition_16b920::FUN_00165750);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b920<hulkfight::motion::CharacterPropStatusCondition_16b920>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b920<hulkfight::motion::CharacterPropStatusCondition_16b920>("number", &hulkfight::motion::CharacterPropStatusCondition_16b920::FUN_00165770);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1268), params, 2);
    }
    DAT_004e126c++;
}


// 0x0016b9d0 FUN_0016b9d0 (158 B): equivalent/0x0016b9d0.cpp
// sym: _FUN_0016b9d0 @4c6f7b4d9f46 @w586aaaf69a7e
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_0016b9d0 @ 0x0016b9d0
extern "C" void FUN_0016b9d0()
{
    if (DAT_004e1274 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b9d0<hulkfight::motion::VelocityXZAngleCondition_16b9d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_16b9d0<hulkfight::motion::VelocityXZAngleCondition_16b9d0>("angle", &hulkfight::motion::VelocityXZAngleCondition_16b9d0::FUN_00165780);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16b9d0<hulkfight::motion::VelocityXZAngleCondition_16b9d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b9d0<hulkfight::motion::VelocityXZAngleCondition_16b9d0>("arc", &hulkfight::motion::VelocityXZAngleCondition_16b9d0::FUN_001657a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1270), params, 2);
    }
    DAT_004e1274++;
}


// 0x0016ba70 FUN_0016ba70 (95 B): equivalent/0x0016ba70.cpp
// sym: _FUN_0016ba70 @c2dc74f297d4 @w8e0c95553bdc
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_0016ba70 @ 0x0016ba70
extern "C" void FUN_0016ba70()
{
    if (DAT_004e1284 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_16ba70<hulkfight::motion::InLoadedRoomCondition_16ba70>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_16ba70<hulkfight::motion::InLoadedRoomCondition_16ba70>("isInLoadedRoom", &hulkfight::motion::InLoadedRoomCondition_16ba70::FUN_001658d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1280), params, 1);
    }
    DAT_004e1284++;
}


// 0x0016bad0 FUN_0016bad0 (176 B): equivalent/0x0016bad0.cpp
// sym: _FUN_0016bad0 @ab99c3cefad8 @wc06cd3847845
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016bad0 @ 0x0016bad0
extern "C" void FUN_0016bad0()
{
    if (DAT_004e128c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16bad0<hulkfight::motion::VelocityXZCondition_16bad0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16bad0<hulkfight::motion::VelocityXZCondition_16bad0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::VelocityXZCondition_16bad0::FUN_001658e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16bad0<hulkfight::motion::VelocityXZCondition_16bad0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16bad0<hulkfight::motion::VelocityXZCondition_16bad0>("velocity", &hulkfight::motion::VelocityXZCondition_16bad0::FUN_001658f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1288), params, 2);
    }
    DAT_004e128c++;
}


// 0x0016bb80 FUN_0016bb80 (158 B): equivalent/0x0016bb80.cpp
// sym: _FUN_0016bb80 @161559f2e1d6 @w42b3ce94b75d
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0016bb80 @ 0x0016bb80
extern "C" void FUN_0016bb80()
{
    if (DAT_004e1294 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>("angle", &hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80::FUN_00165900);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>("arc", &hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80::FUN_00165920);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1290), params, 2);
    }
    DAT_004e1294++;
}


// 0x0016bce0 FUN_0016bce0 (95 B): equivalent/0x0016bce0.cpp
// sym: _FUN_0016bce0 @c97db56f26ae @w06a05fd3c618
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0016bce0 @ 0x0016bce0
extern "C" void FUN_0016bce0()
{
    if (DAT_004e12a4 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_16bce0<hulkfight::motion::ShoreNearCondition_16bce0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_16bce0<hulkfight::motion::ShoreNearCondition_16bce0>("isNearShore", &hulkfight::motion::ShoreNearCondition_16bce0::FUN_00165960);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12a0), params, 1);
    }
    DAT_004e12a4++;
}


// 0x0016bd40 FUN_0016bd40 (176 B): equivalent/0x0016bd40.cpp
// sym: _FUN_0016bd40 @252de8f0f878 @w4b9070c35c60
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_0016bd40 @ 0x0016bd40
extern "C" void FUN_0016bd40()
{
    if (DAT_004e12ac == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16bd40<hulkfight::motion::HealthPercentCondition_16bd40>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16bd40<hulkfight::motion::HealthPercentCondition_16bd40>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::HealthPercentCondition_16bd40::FUN_00165970);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16bd40<hulkfight::motion::HealthPercentCondition_16bd40>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16bd40<hulkfight::motion::HealthPercentCondition_16bd40>("percent", &hulkfight::motion::HealthPercentCondition_16bd40::FUN_00165980);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12a8), params, 2);
    }
    DAT_004e12ac++;
}


// 0x0016bdf0 FUN_0016bdf0 (95 B): equivalent/0x0016bdf0.cpp
// sym: _FUN_0016bdf0 @34c4296d0e91 @w29b9b2389849
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0016bdf0 @ 0x0016bdf0
extern "C" void FUN_0016bdf0()
{
    if (DAT_004e12b4 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_16bdf0<hulkfight::motion::ThinkingCondition_16bdf0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_16bdf0<hulkfight::motion::ThinkingCondition_16bdf0>("thinking", &hulkfight::motion::ThinkingCondition_16bdf0::FUN_001659a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12b0), params, 1);
    }
    DAT_004e12b4++;
}


// 0x0016be50 FUN_0016be50 (176 B): equivalent/0x0016be50.cpp
// sym: _FUN_0016be50 @2673c43dc072 @wcb4ec3e1db12
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_0016be50 @ 0x0016be50
extern "C" void FUN_0016be50()
{
    if (DAT_004e12bc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16be50<hulkfight::motion::VelocityAnimatedCondition_16be50>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16be50<hulkfight::motion::VelocityAnimatedCondition_16be50>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::VelocityAnimatedCondition_16be50::FUN_001659b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16be50<hulkfight::motion::VelocityAnimatedCondition_16be50>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16be50<hulkfight::motion::VelocityAnimatedCondition_16be50>("velocity", &hulkfight::motion::VelocityAnimatedCondition_16be50::FUN_001659c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12b8), params, 2);
    }
    DAT_004e12bc++;
}


// 0x0016c000 FUN_0016c000 (27 B): matches/0x0016c000.cpp
// sym: ?target@fn_f45cd32f@@YAXPAX@Z
void __cdecl target(void* p) {
    ConditionFactoryCasterTemplate_16c000 c;
    FUN_002343e0(p, &c);
}


// 0x0016c100 fight::ParamNameConstList<hulkfight::motion::RayCastTargetCondition>::vfunc_7 (12 B): matches/0x0016c100.cpp
// sym: ?vfunc_6@ParamBranch@fn_f45cd32f@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_0016c320


// 0x0016c450 fight::ParamNameConstList<hulkfight::motion::RayCastTargetCondition>::vfunc_0 (30 B): matches/0x0016c450.cpp
// sym: ??_G?$ParamNameConstList@VRayCastTargetCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::RayCastTargetCondition>::~ParamNameConstList() {}


// 0x0016c470 fight::ParamNameConstList<hulkfight::motion::RayCastConeCondition>::vfunc_0 (30 B): matches/0x0016c470.cpp
// sym: ??_G?$ParamNameConstList@VRayCastConeCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::RayCastConeCondition>::~ParamNameConstList() {}


// 0x0016c490 fight::ParamNameConstList<hulkfight::motion::RayCastCondition>::vfunc_0 (30 B): matches/0x0016c490.cpp
// sym: ??_G?$ParamNameConstList@VRayCastCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::RayCastCondition>::~ParamNameConstList() {}

