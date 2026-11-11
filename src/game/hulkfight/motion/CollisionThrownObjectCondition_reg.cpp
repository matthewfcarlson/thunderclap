// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00157800..0x00158f00 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4e72ed8 {
#define TREE_TU_END }
namespace fn_f4e72ed8 {} using namespace fn_f4e72ed8;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4e72ed8 {
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class TrackFactoryCasterTemplate_157b10 {
  public:
    TrackFactoryCasterTemplate_157b10() {}
    virtual void cast();
};
extern "C" void __cdecl Use_00236ac0(void*, TrackFactoryCasterTemplate_157b10*);
} // namespace fn_f4e72ed8
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f4e72ed8 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class CollisionThrownObjectCondition_157ee0 {
public:
    void FUN_0014c5e0();
    void FUN_0014c5f0();
};
} }
namespace fn_f4e72ed8 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f4e72ed8
namespace fight {
template <class T>
class ParamBool_157ee0 : public ParamBoolBase {
public:
    ParamBool_157ee0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_157ee0 : public ParamNameBase {
public:
    ParamName_157ee0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class CollisionTargetNameCondition_158040 {
public:
    void FUN_0014c690();
    void FUN_0014c6a0();
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_158040 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_158040(const char* name, const char** n, int c, void (T::*s)())
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
class ParamName_158040 : public ParamNameBase {
public:
    ParamName_158040(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
extern "C" char DAT_00415024[];
class B_1580f0 {
  public:
    void Fn_00236760(void*);
};
extern "C" void* FUN_002343e0(void*, void*);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class CollisionSourceNameCondition_1581b0 {
public:
    void FUN_0014c740();
    void FUN_0014c750();
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_1581b0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1581b0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamName_1581b0 : public ParamNameBase {
public:
    ParamName_1581b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
class TrackFactoryCasterTemplate_158260 {
  public:
    virtual Track* Cast(void*);
};
Track* FindTrack_00236ac0(const char*, TrackFactoryCasterTemplate_158260*);
class TrackFactoryCasterTemplate_158290 {
  public:
    virtual void f() {}
};
class Obj {
  public:
    void Set_002367c0(void*);
    void add_002367c0(void*);
    void use_002367c0(void*);
    void Set_002367c0(Track*);
    void Fn_002367c0(void*);
    void set_002367c0(void*);
};
extern void* __cdecl find_00236ac0(void*, TrackFactoryCasterTemplate_158290*);
class TrackFactoryCasterTemplate_1582c0 {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply_002367c0(void*);
};
class Owner {
  public:
    void Apply_002367c0(Track*);
    void set_002367c0(void*);
    void bind_002367c0(Track*);
    void* Get_002367c0(void*);
};
extern "C" void* FUN_00236ac0(void*, TrackFactoryCasterTemplate_1582c0*);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class HitReactionFloatTrack_1582f0 {
public:
    void FUN_0014c880();
    void FUN_0014c8a0();
    void FUN_0014c8c0();
    void FUN_0014c8e0();
    void FUN_0014c900();
    void FUN_0014c920();
    void FUN_0014c950();
    void FUN_0014c970();
    void FUN_0014c990();
    void FUN_0014c9b0();
    void FUN_0014c9d0();
    void FUN_0014c9f0();
    void FUN_0014ca10();
    void FUN_0014ca30();
    void FUN_0014ca50();
    void FUN_0014ca70();
    void FUN_0014ca90();
};
} }
namespace fn_f4e72ed8 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f4e72ed8
namespace fight {
template <class T>
class ParamBool_1582f0 : public ParamBoolBase {
public:
    ParamBool_1582f0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_1582f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1582f0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_1582f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1582f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_1582f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1582f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_1582f0 : public ParamNameBase {
public:
    ParamName_1582f0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
class TrackFactoryCasterTemplate_1586a0 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Set_002367c0(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_1586a0*);
class TrackFactoryCasterTemplate_1586d0 {
  public:
    virtual void cast();
};
void* lookup_00236ac0(void*, TrackFactoryCasterTemplate_1586d0*);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class HitReactionTrack_158700 {
public:
    void FUN_0014caf0();
    void FUN_0014cb10();
    void FUN_0014cb30();
    void FUN_0014cb50();
    void FUN_0014cb70();
    void FUN_0014cb90();
    void FUN_0014cbb0();
    void FUN_0014cbd0();
    void FUN_0014cbf0();
    void FUN_0014cc20();
    void FUN_0014cc40();
    void FUN_0014cc60();
    void FUN_0014cc80();
    void FUN_0014cca0();
};
} }
namespace fight {
template <class T>
class ParamBool_158700 : public ParamBoolBase {
public:
    ParamBool_158700(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_158700 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_158700(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_158700 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_158700(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_158700 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_158700(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_158700 : public ParamNameBase {
public:
    ParamName_158700(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
class TrackFactoryCasterTemplate_158a10 {
  public:
    virtual void Cast();
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_158a10*);
class TrackFactoryCasterTemplate_158a40 {
  public:
    virtual void f();
};
void* __cdecl find_00236ac0(const char*, TrackFactoryCasterTemplate_158a40*);
class TrackFactoryCasterTemplate_158aa0 {
  public:
    virtual void Dummy();
};
Track* Find_00236ac0(const char*, TrackFactoryCasterTemplate_158aa0*);
class TrackFactoryCasterTemplate_158ad0 {
  public:
    virtual void cast();
};
Track* __cdecl lookup_00236ac0(void*, TrackFactoryCasterTemplate_158ad0*);
class TrackFactoryCasterTemplate_158b00 {
  public:
    virtual void Cast();
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_158b00*);
class TrackFactoryCasterTemplate_158b30 {
  public:
    virtual void cast();
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_158b30*);
class TrackFactoryCasterTemplate_158b60 {
  public:
    virtual void Cast();
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_158b60*);
class TrackFactoryCasterTemplate_158b90 {
  public:
    virtual void Cast();
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_158b90*);
class TrackFactoryCasterTemplate_158bc0 {
  public:
    virtual void Cast();
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_158bc0*);
class Factory {
  public:
    void Add_002367c0(void*);
};


// 0x00157800 fight::ParamName<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_7 (12 B): matches/0x00157800.cpp
// sym: ?vfunc_6@ParamBranch@fn_f4e72ed8@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f4e72ed8

// 0x001578b0 fight::ParamName<hulkfight::motion::CollisionTargetNameCondition>::vfunc_7 (12 B): matches/0x001578b0.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001578b0@@UAEXPAX@Z
namespace fn_001578b0 {
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
} // namespace fn_001578b0


// 0x00157960 fight::ParamName<hulkfight::motion::CollisionSourceNameCondition>::vfunc_7 (12 B): matches/0x00157960.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00157960@@UAEXPAX@Z
namespace fn_00157960 {
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
} // namespace fn_00157960


// 0x001579f0 fight::ParamName<hulkfight::motion::HitReactionFloatTrack>::vfunc_7 (12 B): matches/0x001579f0.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001579f0@@UAEXPAX@Z
namespace fn_001579f0 {
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
} // namespace fn_001579f0


// 0x00157a60 fight::ParamName<hulkfight::motion::HitReactionTrack>::vfunc_7 (12 B): matches/0x00157a60.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00157a60@@UAEXPAX@Z
namespace fn_00157a60 {
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
} // namespace fn_00157a60

namespace fn_f4e72ed8 {

// 0x00157b10 FUN_00157b10 (27 B): matches/0x00157b10.cpp
// sym: ?target@fn_f4e72ed8@@YAXPAX@Z
void __cdecl target(void* p) {
    TrackFactoryCasterTemplate_157b10 c;
    Use_00236ac0(p, &c);
}

} // namespace fn_f4e72ed8

// 0x00157bd0 fight::ParamName<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_0 (30 B): matches/0x00157bd0.cpp
// sym: ??_G?$ParamName@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::CollisionThrownObjectCondition>::~ParamName() {}


// 0x00157bf0 fight::ParamName<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0 (30 B): matches/0x00157bf0.cpp
// sym: ??_G?$ParamName@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::CollisionTargetNameCondition>::~ParamName() {}


// 0x00157c10 fight::ParamName<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0 (30 B): matches/0x00157c10.cpp
// sym: ??_G?$ParamName@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::CollisionSourceNameCondition>::~ParamName() {}


// 0x00157c30 fight::ParamName<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x00157c30.cpp
// sym: ??_G?$ParamName@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::HitReactionFloatTrack>::~ParamName() {}


// 0x00157c50 fight::ParamName<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00157c50.cpp
// sym: ??_G?$ParamName@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::HitReactionTrack>::~ParamName() {}

namespace fn_f4e72ed8 {

// 0x00157ee0 FUN_00157ee0 (158 B): equivalent/0x00157ee0.cpp
// sym: _FUN_00157ee0 @7f3db43ff51b @wfa1d5c5ab6b4
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00157ee0 @ 0x00157ee0
extern "C" void FUN_00157ee0()
{
    if (DAT_004e108c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_157ee0<hulkfight::motion::CollisionThrownObjectCondition_157ee0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_157ee0<hulkfight::motion::CollisionThrownObjectCondition_157ee0>("thrownObject", &hulkfight::motion::CollisionThrownObjectCondition_157ee0::FUN_0014c5e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_157ee0<hulkfight::motion::CollisionThrownObjectCondition_157ee0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_157ee0<hulkfight::motion::CollisionThrownObjectCondition_157ee0>("name", &hulkfight::motion::CollisionThrownObjectCondition_157ee0::FUN_0014c5f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1088), params, 2);
    }
    DAT_004e108c++;
}


// 0x00158040 FUN_00158040 (176 B): equivalent/0x00158040.cpp
// sym: _FUN_00158040 @0651be27d437 @wbf4df28ee310
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_00158040 @ 0x00158040
extern "C" void FUN_00158040()
{
    if (DAT_004e10ac == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_158040<hulkfight::motion::CollisionTargetNameCondition_158040>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_158040<hulkfight::motion::CollisionTargetNameCondition_158040>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &hulkfight::motion::CollisionTargetNameCondition_158040::FUN_0014c690);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_158040<hulkfight::motion::CollisionTargetNameCondition_158040>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_158040<hulkfight::motion::CollisionTargetNameCondition_158040>("name", &hulkfight::motion::CollisionTargetNameCondition_158040::FUN_0014c6a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10a8), params, 2);
    }
    DAT_004e10ac++;
}


// 0x001580f0 FUN_001580f0 (38 B): matches/0x001580f0.cpp
// sym: ?FUN_001580f0@fn_f4e72ed8@@YAXPAVB_1580f0@1@PAX1@Z
void FUN_001580f0(B_1580f0* b, void* a, void* x) {
    void* local;
    *(void**)&local = (void*)((hulk_intptr)DAT_00415024);
    void* p = FUN_002343e0(a, &local);
    b->Fn_00236760(p);
}


// 0x001581b0 FUN_001581b0 (176 B): equivalent/0x001581b0.cpp
// sym: _FUN_001581b0 @da36d9eb1e60 @w58ad79bbe09e
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001581b0 @ 0x001581b0
extern "C" void FUN_001581b0()
{
    if (DAT_004e10cc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1581b0<hulkfight::motion::CollisionSourceNameCondition_1581b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_1581b0<hulkfight::motion::CollisionSourceNameCondition_1581b0>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &hulkfight::motion::CollisionSourceNameCondition_1581b0::FUN_0014c740);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1581b0<hulkfight::motion::CollisionSourceNameCondition_1581b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_1581b0<hulkfight::motion::CollisionSourceNameCondition_1581b0>("name", &hulkfight::motion::CollisionSourceNameCondition_1581b0::FUN_0014c750);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10c8), params, 2);
    }
    DAT_004e10cc++;
}


// 0x00158260 FUN_00158260 (38 B): matches/0x00158260.cpp
// sym: _FUN_00158260
extern "C" void FUN_00158260(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_158260 caster;
    Track* track = FindTrack_00236ac0(name, &caster);
    owner->Apply_002367c0(track);
}


// 0x00158290 FUN_00158290 (38 B): matches/0x00158290.cpp
// sym: _FUN_00158290
extern "C" void FUN_00158290(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158290 caster;
    obj->add_002367c0(find_00236ac0(name, &caster));
}


// 0x001582c0 FUN_001582c0 (38 B): matches/0x001582c0.cpp
// sym: _FUN_001582c0
extern "C" void FUN_001582c0(Track* t, void* name) {
    TrackFactoryCasterTemplate_1582c0 caster;
    t->apply_002367c0(FUN_00236ac0(name, &caster));
}


// 0x001582f0 FUN_001582f0 (937 B): equivalent/0x001582f0.cpp
// sym: _FUN_001582f0 @67467da642a3 @wf542561044fd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_001582f0 @ 0x001582f0
extern "C" void FUN_001582f0()
{
    if (DAT_004e10e4 == 0) {
        void* params[17];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("timeBegin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c880);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c8a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("direction", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c8c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("flag", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c8e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("interruptPriority", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c900);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackDirection", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c920);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("damageMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c950);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("damageMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c970);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackDistanceMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c990);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackDistanceMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c9b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackTimeMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c9d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("pushbackTimeMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014c9f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("heightMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("heightMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("stunTimeMin", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("stunTimeMax", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca70);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_1582f0<hulkfight::motion::HitReactionFloatTrack_1582f0>("ignoreHitRecord", &hulkfight::motion::HitReactionFloatTrack_1582f0::FUN_0014ca90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10e0), params, 17);
    }
    DAT_004e10e4++;
}


// 0x001586a0 FUN_001586a0 (38 B): matches/0x001586a0.cpp
// sym: _FUN_001586a0
extern "C" void FUN_001586a0(Receiver* receiver, void* value) {
    TrackFactoryCasterTemplate_1586a0 caster;
    receiver->Set_002367c0(Find_00236ac0(value, &caster));
}


// 0x001586d0 FUN_001586d0 (38 B): matches/0x001586d0.cpp
// sym: _FUN_001586d0
extern "C" void FUN_001586d0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_1586d0 caster;
    void* x = lookup_00236ac0(name, &caster);
    owner->set_002367c0(x);
}


// 0x00158700 FUN_00158700 (784 B): equivalent/0x00158700.cpp
// sym: _FUN_00158700 @5f47b849a605 @wac1c461f78f2
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 30/30)
// FUN_00158700 @ 0x00158700
extern "C" void FUN_00158700()
{
    if (DAT_004e10f4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("timeBegin", &hulkfight::motion::HitReactionTrack_158700::FUN_0014caf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_158700<hulkfight::motion::HitReactionTrack_158700>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("direction", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_158700<hulkfight::motion::HitReactionTrack_158700>("flag", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("damage", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb70);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("interruptPriority", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cb90);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_158700<hulkfight::motion::HitReactionTrack_158700>("interrupt", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cbb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("hitReactionTime", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cbd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("pushbackDirection", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("pushbackDistance", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("pushbackTime", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("height", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_158700<hulkfight::motion::HitReactionTrack_158700>("stunTime", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cc80);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_158700<hulkfight::motion::HitReactionTrack_158700>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool_158700<hulkfight::motion::HitReactionTrack_158700>("ignoreHitRecord", &hulkfight::motion::HitReactionTrack_158700::FUN_0014cca0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10f0), params, 14);
    }
    DAT_004e10f4++;
}


// 0x00158a10 FUN_00158a10 (38 B): matches/0x00158a10.cpp
// sym: _FUN_00158a10
extern "C" void __cdecl FUN_00158a10(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_158a10 caster;
    void* p = FUN_00236ac0(key, &caster);
    obj->Set_002367c0(p);
}


// 0x00158a40 FUN_00158a40 (38 B): matches/0x00158a40.cpp
// sym: _FUN_00158a40
extern "C" void __cdecl FUN_00158a40(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158a40 c;
    obj->use_002367c0(find_00236ac0(name, &c));
}

} // namespace fn_f4e72ed8

// 0x00158a70 FUN_00158a70 (38 B): matches/0x00158a70.cpp [wrapped: conflict: find]
// sym: _FUN_00158a70
namespace fn_00158a70 {
class TrackFactoryCasterTemplate_158a70 {
  public:
    virtual void cast();
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(void*, TrackFactoryCasterTemplate_158a70*);
class Object {
  public:
    void attach_002367c0(void*);
};
extern "C" void __cdecl FUN_00158a70(Object* obj, void* name) {
    TrackFactoryCasterTemplate_158a70 caster;
    obj->attach_002367c0(find_00236ac0(name, &caster));
}
} // namespace fn_00158a70

namespace fn_f4e72ed8 {

// 0x00158aa0 FUN_00158aa0 (38 B): matches/0x00158aa0.cpp
// sym: _FUN_00158aa0
extern "C" void FUN_00158aa0(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158aa0 caster;
    Track* track = Find_00236ac0(name, &caster);
    obj->Set_002367c0(track);
}


// 0x00158ad0 FUN_00158ad0 (38 B): matches/0x00158ad0.cpp
// sym: _FUN_00158ad0
extern "C" void __cdecl FUN_00158ad0(Owner* owner, void* key) {
    TrackFactoryCasterTemplate_158ad0 caster;
    owner->bind_002367c0(lookup_00236ac0(key, &caster));
}


// 0x00158b00 FUN_00158b00 (38 B): matches/0x00158b00.cpp
// sym: _FUN_00158b00
extern "C" void __cdecl FUN_00158b00(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158b00 caster;
    void* result = Find_00236ac0(name, &caster);
    obj->Fn_002367c0(result);
}


// 0x00158b30 FUN_00158b30 (38 B): matches/0x00158b30.cpp
// sym: _FUN_00158b30
extern "C" void FUN_00158b30(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158b30 c;
    obj->set_002367c0(FUN_00236ac0(name, &c));
}


// 0x00158b60 FUN_00158b60 (38 B): matches/0x00158b60.cpp
// sym: _FUN_00158b60
extern "C" void FUN_00158b60(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158b60 caster;
    void* p = FUN_00236ac0(name, &caster);
    obj->Set_002367c0(p);
}


// 0x00158b90 FUN_00158b90 (38 B): matches/0x00158b90.cpp
// sym: _FUN_00158b90
extern "C" void* FUN_00158b90(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_158b90 caster;
    return owner->Get_002367c0(Find_00236ac0(name, &caster));
}


// 0x00158bc0 FUN_00158bc0 (38 B): matches/0x00158bc0.cpp
// sym: _FUN_00158bc0
extern "C" void FUN_00158bc0(Factory* f, void* name) {
    TrackFactoryCasterTemplate_158bc0 caster;
    void* obj = Find_00236ac0(name, &caster);
    f->Add_002367c0(obj);
}

} // namespace fn_f4e72ed8

// 0x00158bf0 FUN_00158bf0 (38 B): matches/0x00158bf0.cpp [wrapped: conflict: Find]
// sym: _FUN_00158bf0
namespace fn_00158bf0 {
class TrackFactoryCasterTemplate_158bf0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_158bf0*);
extern "C" void FUN_00158bf0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158bf0 caster;
    void* p = Find_00236ac0(name, &caster);
    obj->Apply_002367c0(p);
}
} // namespace fn_00158bf0


// 0x00158c20 FUN_00158c20 (723 B): matches/0x00158c20.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00158c20
namespace fn_00158c20 {
// FUN_00158c20 @ 0x00158c20
namespace hulkfight { namespace motion {
class InterruptAccumulatorCondition;
class CollisionInterruptPriorityCondition;
class CollisionSourceTypeCondition;
class CollisionSourceNameCondition;
class CollisionTargetNameCondition;
class CollisionSourceIsMissileCondition;
class CollisionSourceNodeCondition;
class CollisionSourceForceMagnitudeCondition;
class CollisionTargetPriorityCondition;
class CollisionTargetIsTargetCondition;
class CollisionTargetTypeCondition;
class CollisionSourceSizeCondition;
class CollisionTargetSizeCondition;
class HitPushbackCondition;
class HitPushbackVelocityCondition;
class CollisionChargeCondition;
class CollisionDamageHealthCompareCondition;
class CollisionThrowCondition;
class CollisionThrownObjectCondition;
class CollisionExplosionCondition;
class CollisionDevastatorCondition;
} }
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void Create();
};
}
struct Registry_158c20 {
    void FUN_00236760(void*);
};
extern void* __cdecl FUN_002343e0(const char*, void*);
extern "C" void __cdecl FUN_00158c20(Registry_158c20* registry) {
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition> caster;
        registry->FUN_00236760(FUN_002343e0("interruptAccumulator", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionInterruptPriority", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceIsMissileCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceIsMissile", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceNode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceForceMagnitude", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetPriority", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetIsTarget", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition> caster;
        registry->FUN_00236760(FUN_002343e0("hitPushback", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("hitPushbackVelocity", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionCharge", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionDamageHealthCompare", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionThrow", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionThrownObject", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionExplosion", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionDevastator", &caster));
    }
}
} // namespace fn_00158c20

