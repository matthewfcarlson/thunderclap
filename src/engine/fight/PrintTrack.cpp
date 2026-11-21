// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238850..0x002393a0 (kind game, layer engine, confidence high), dominant class fight::PrintTrack
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real, their destructors implicit
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbe81dc2 {
#define TREE_TU_END }
namespace fn_fbe81dc2 {} using namespace fn_fbe81dc2;
namespace fn_fbe81dc2 {
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
namespace fn_fbe81dc2 { extern "C" char DAT_004282dc[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_fbe81dc2 { extern "C" char DAT_00428330[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/fight.h"
void operator delete[](void*);   // (gx4) the game's (0x0008d340): the destructors' `delete[]` (MSVC 7.1 calls operator delete without it)

void* operator new(size_t) HULK_NEW_THROW;   // (gx2) the game's operator new (0x0008d690), null-checked
// ---- declarations shared by the functions below
namespace fn_fbe81dc2 {
class Obj_238850 {
  public:
    char pad[0xc];
    int value;
    char SetTimeBegin_00238850(int x);
};
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c20;
class CCondition_2388a0 {
  public:
    virtual int vfunc_0(int);
};
typedef unsigned int u32_2388e0;
void thunk_FUN_00267090(u32_2388e0);
extern int hulk_at_004282dc;
struct Condition_2388e0 {
    void finish_002345b0();
};
struct PrintCondition_2388e0 : Condition_2388e0 {
    void* vt;
    char pad4[8];
    u32_2388e0 a;
    u32_2388e0 b;
    void dtorish();
};
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
void __cdecl thunk_FUN_00267090(void* p);
extern int* hulk_at_004e5c28;
class CCondition_2389f0 {
  public:
    virtual int vfunc_0(int);
};
HULK_REFCOUNT_PACK   // (x64t7) pure3d::NonCopyable's stand-in: 12 bytes natively (compat/ptr.h)
class Track_238a00 {
  public:
    Track_238a00();
    virtual void Fn();
    char pad[4];
};
HULK_REFCOUNT_PACK_END
class PrintTrack : public ::fight::PrintTrack {
  public:
    PrintTrack();
};
typedef unsigned int u32_238a50;
extern u32_238a50 hulk_at_004282fc;
void __cdecl ReleaseThing_0008d340(int);
struct PrintTrack_nv_238a50 {
    void Cleanup_00236d60();
};
class Obj {
  public:
    char _m_pad_0[0x10];
    char* text;
    bool SetChannel_00238a80(const char* value);
    void Set_00236760(void*);
    void set_002367c0(void*);
};
typedef unsigned int u32_238c40;
extern void PrintSomething_00238bb0(hulk_uintptr, u32_238c40, const char*, ...);
extern char hulk_at_00428328[];
class Action_238c70 {
    char pad[0x1c];
};
class NonCopyable_238c70 {};
class IRefCount_238c70 {};
extern int FUN_00238bb0(int, int, const char*, ...);
const char formatString_238c70[] = "%s\n";
extern "C" {
void __cdecl thunk_FUN_00267090b_0008d340(void*);
}
extern "C" {
void __cdecl thunk_FUN_00267090c_0008d330(void*);
}
extern "C" {
extern char g_vftable_target;
}
struct BaseCls_238ca0 {
  public:
    void Dtor_002345b0();
};
class PrintCondition_238ca0 {
  public:
    virtual ~PrintCondition_238ca0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5(unsigned char flag);
    virtual void v6();
    char pad[8];
    void* m_p1;
    void* m_p2;
};
struct Obj_238d20 {
    virtual void F();
    virtual void R();
};
extern int hulk_at_00428330;
struct PrintAction_238d20 {
    void* vf;
    int pad[6];
    int arg;
    Obj_238d20* object;
    void Init_00232660();
    PrintAction_238d20* Build(int, Obj_238d20*);
};
class Ref_238d70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_238d70 {
  public:
    void* vptr;
};
class PrintAction_238d70 : public Action_238d70 {
  public:
    char pad[28];
    Ref_238d70* m;
    ~PrintAction_238d70();
};
class CStageCondition_238de0;
class ParamValue_238de0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_238de0 : public ParamValue_238de0 {
  public:
    int pad;
};
class CStageCondition_238e30;
class ParamValue_238e30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_238e30 : public ParamValue_238e30 {
  public:
    int pad;
};
class CStageCondition_238e80;
class ParamValue_238e80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_238e80 : public ParamValue_238e80 {
  public:
    int pad;
};
extern int hulk_at_00491ca8;
extern int hulk_at_0049850c;
extern "C" char DAT_00428330[];
class Obj_2390f0 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    void Init_00232660();
};
class Track_2390f0 {
  public:
    virtual void T0();
    virtual void T1();
    virtual void T2();
    virtual void T3();
    virtual void T4();
    virtual void T5();
    virtual void T6();
    virtual void T7();
    virtual void T8();
    virtual void T9();
    virtual void T10();
    virtual void T11();
};
extern Obj_2390f0* __cdecl Alloc_0008d690(int);
extern void* g_vftable_239150[];
class Ref_239150 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_239150 {
  public:
    void* vptr;
};
class PrintAction_239150 : public Action_239150 {
  public:
    char pad[0x1c];
    Ref_239150* m;
    PrintAction_239150* f2(unsigned char flags);
};
extern "C" char DAT_004283ac[];   // fight::ConditionFactoryCasterTemplate<fight::PrintCondition>::vftable
struct ConditionFactoryCasterTemplate_2391d0 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
extern "C" void* FUN_002343e0(const char*, ConditionFactoryCasterTemplate_2391d0*);   // (gfx1) its own name: `Find` stood for several functions natively (ambiguous binding)
extern "C" char DAT_004283b8[];   // fight::TrackFactoryCasterTemplate<fight::PrintTrack>::vftable
struct TrackFactoryCasterTemplate_239200 {   // (sweep-caster-fix1) the word its inline constructor writes (was a local polymorphic stand-in:
    void* vftable;   // clang's own vftable natively, whose slot had no definition)
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_239200*);
extern int hulk_at_004283c4;
struct ConditionFactoryTemplate_2392b0 {
    void* m_vptr;
    void base1_dtor_00238880();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
} // namespace fn_fbe81dc2
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_fbe81dc2 {
class Base {
  public:
    Base();
    virtual void a();
    virtual bool Fnb_00234270(void*);
    virtual bool Fnc_002342b0(int);
    int pad;
    int flag;
};
class PrintTrack_239320 : public Base {
  public:
    PrintTrack_239320() {
        x = 0;
        y = 0;
        z = 0;
        flag = 1;
    }
    virtual void a();
    int x;
    int y;
    int z;
};
extern int hulk_at_004283e0;


// 0x00238850 FUN_00238850 (12 B): matches/0x00238850.cpp
// sym: ?SetTimeBegin_00238850@Obj_238850@fn_fbe81dc2@@QAEDH@Z
char Obj_238850::SetTimeBegin_00238850(int x) {
    value = x;
    return 1;
}


// 0x00238880 FUN_00238880 (19 B): matches/0x00238880.cpp
// sym: ?FUN_00238880@fn_fbe81dc2@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00238880(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e5c20), ((char*)&DAT_004e5c24));
}

} // namespace fn_fbe81dc2

// 0x002388a0 fight::PrintCondition::vfunc_0 (16 B): matches/0x002388a0.cpp
// sym: ?vfunc_0@PrintCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::PrintCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5c20;
    return p[index];
}

namespace fn_fbe81dc2 {

} // namespace fn_fbe81dc2

// 0x002388e0 fight::PrintCondition::~PrintCondition (38 B): matches/0x002388e0.cpp
// sym: ??1PrintCondition@fight@@UAE@XZ
// (gx4, D19/D14) the class's destructor (was a TU-local stand-in): it frees the strings (operator delete[]), then
// the base destructor; MSVC 7.1 also inlines it into the scalar deleting destructor below
fight::PrintCondition::~PrintCondition() {
    delete[] f_0c;
    delete[] f_10;
}

namespace fn_fbe81dc2 {


} // namespace fn_fbe81dc2

// 0x00238910 FUN_00238910 (82 B): equivalent/0x00238910.cpp
// sym: ?FUN_00238910@Object_238910@owners@@QAE_NPBD@Z @ceb1083b6fd1 @w2ae63d33cad5 @vd6b9761e25d1
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00238910 @ 0x00238910
bool owners::Object_238910::FUN_00238910(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return true;
    }
    unsigned int len = 0;
    while (value[len]) ++len;
    text = (char *)FUN_0008d6d0(len + 1);
    char *out = text;
    do { *out++ = *value; } while (*value++);
    return true;
}


// 0x00238970 FUN_00238970 (82 B): matches/0x00238970.cpp
// sym: ?FUN_00238970@Obj_00238970@owners@@QAE_NPBD@Z
bool owners::Obj_00238970::FUN_00238970(const char* s)
{
    thunk_FUN_00267090(name);
    if (s == 0) {
        name = 0;
        return true;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return true;
}

namespace fn_fbe81dc2 {

// 0x002389d0 FUN_002389d0 (19 B): matches/0x002389d0.cpp
// sym: ?FUN_002389d0@fn_fbe81dc2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_002389d0() {
    FUN_00234810(((char*)&DAT_004e5c28), ((char*)&DAT_004e5c2c));
}

} // namespace fn_fbe81dc2

// 0x002389f0 fight::PrintTrack::vfunc_0 (16 B): matches/0x002389f0.cpp
// sym: ?vfunc_0@PrintTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::PrintTrack::vfunc_0(int index) {
    int* p = hulk_at_004e5c28;
    return p[index];
}

namespace fn_fbe81dc2 {

// 0x00238a00 FUN_00238a00 (36 B): matches/0x00238a00.cpp
// sym: ??0PrintTrack@fn_fbe81dc2@@QAE@XZ
PrintTrack::PrintTrack() {
    timeBegin = 0;
    f_10 = 0;
    f_14 = 0;
    f_08 = 1;
}

} // namespace fn_fbe81dc2

// 0x00238a30 fight::PrintTrack::vfunc_6 (4 B): matches/0x00238a30.cpp
// sym: ?vfunc_6@PrintTrack@fight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg fight::PrintTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00238a40 fight::PrintTrack::vfunc_7 (7 B): matches/0x00238a40.cpp
// sym: ?vfunc_7@PrintTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::PrintTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x00238a50 fight::PrintTrack::~PrintTrack (38 B): matches/0x00238a50.cpp
// sym: ??1PrintTrack@fight@@UAE@XZ
// (gx4, D19/D14) the class's destructor (was a TU-local stand-in): it frees the strings (operator delete[]), then
// the base destructor; MSVC 7.1 also inlines it into the scalar deleting destructor below
fight::PrintTrack::~PrintTrack() {
    delete[] f_10;
    delete[] f_14;
}



namespace fn_fbe81dc2 {

// 0x00238a80 FUN_00238a80 (82 B): equivalent/0x00238a80.cpp
// sym: ?SetChannel_00238a80@Obj@fn_fbe81dc2@@QAE_NPBD@Z @479a89a7457f @wf4aa5da2059f @vca9fc7a4740c
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetChannel_00238a80 @ 0x00238a80
bool Obj::SetChannel_00238a80(const char* value) { FUN_0008d340(text); if (!value) { text = 0; return true; } unsigned int length = 0; while (value[length]) ++length; text = (char*)FUN_0008d6d0(length + 1); char* dest = text; do { *dest++ = *value; } while (*value++); return true; }

} // namespace fn_fbe81dc2

// 0x00238ae0 FUN_00238ae0 (82 B): equivalent/0x00238ae0.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: ?SetText_00238ae0@Object@fn_00238ae0@@QAE_NPBD@Z @f4449191efda @w7da5b8150b6f @v1934e9c461ac
namespace fn_00238ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetText_00238ae0 @ 0x00238ae0
/* size_t: tree_prelude.h */
extern "C" void __cdecl FUN_0008d340(void *);
extern "C++" void * __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char pad[0x14];
    char *text;
    bool SetText_00238ae0(const char *source);
};
bool Object::SetText_00238ae0(const char *source) {
    FUN_0008d340(text);
    if (!source) {
        text = 0;
        return true;
    }
    const char *end = source;
    while (*end) ++end;
    text = (char *)FUN_0008d6d0((size_t)(end - source) + 1);
    char *dest = text;
    do { *dest++ = *source; } while (*source++);
    return true;
}
} // namespace fn_00238ae0

namespace fn_fbe81dc2 {

// 0x00238b60 FUN_00238b60 (20 B): matches/0x00238b60.cpp
// sym: _FUN_00238b60
// Same code shape as 0x00232d70 (propagated; names are from that function)
extern "C" void FUN_00238b60(hulk_intptr a, int b) {
    (*(int*)&DAT_004e5c30) = a;
    DAT_004e5c34 = b;
}

} // namespace fn_fbe81dc2

// 0x00238c40 fight::PrintCondition::vfunc_6 (35 B): matches/0x00238c40.cpp
// sym: ?vfunc_6@PrintCondition@fight@@UAE_NPAX00@Z
bool fight::PrintCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_uintptr x = (hulk_uintptr)__p0; hulk_uintptr y = (hulk_uintptr)__p1; hulk_uintptr z = (hulk_uintptr)__p2;

    if ((*(u32_238c40 *)&this->f_10))
        PrintSomething_00238bb0(y, (*(u32_238c40 *)&this->f_0c), hulk_at_00428328, (*(u32_238c40 *)&this->f_10));
    return true;
}


// 0x00238c70 fight::PrintAction::vfunc_3 (37 B): matches/0x00238c70.cpp
// sym: ?vfunc_3@PrintAction@fight@@UAE_NHH@Z
bool fight::PrintAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    hulk_intptr p = *(int*)((char*)&this->f_1c);
    if (*(int*)((char*)p + 0x14))
        FUN_00238bb0(*(int*)((char*)&this->f_20), *(int*)((char*)p + 0x10), formatString_238c70,
                     *(int*)((char*)p + 0x14));
    return false;
}

namespace fn_fbe81dc2 {

} // namespace fn_fbe81dc2

// 0x00238ca0 fight::PrintCondition::vfunc_5 (59 B): matches/0x00238ca0.cpp
// sym: ??_GPrintCondition@fight@@UAEPAXI@Z
// (gx4, D19/D14) the implicit scalar deleting destructor: MSVC 7.1 emits it beside the class's vftable, which the
// destructor (0x002388e0, this TU) stores, with that destructor inlined

namespace fn_fbe81dc2 {


} // namespace fn_fbe81dc2

// 0x00238ce0 fight::PrintTrack::vfunc_5 (59 B): matches/0x00238ce0.cpp
// sym: ??_GPrintTrack@fight@@UAEPAXI@Z
// (gx4, D19/D14) the implicit scalar deleting destructor: MSVC 7.1 emits it beside the class's vftable, which the
// destructor (0x00238a50, this TU) stores, with that destructor inlined



namespace fn_fbe81dc2 {

// 0x00238d20 FUN_00238d20 (65 B): matches/0x00238d20.cpp
// sym: ?Build@PrintAction_238d20@fn_fbe81dc2@@QAEPAU12@HPAUObj_238d20@2@@Z
// Same code shape as 0x0012db50 (propagated; names are from that function)
PrintAction_238d20* PrintAction_238d20::Build(int a, Obj_238d20* p) {
    Init_00232660();
    vf = &hulk_at_00428330;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}


// 0x00238d70 FUN_00238d70 (36 B): matches/0x00238d70.cpp
// sym: ??1PrintAction_238d70@fn_fbe81dc2@@QAE@XZ
PrintAction_238d70::~PrintAction_238d70() {
    vptr = (void**)DAT_00428330;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_238d70 *)this)->FUN_002326a0();
}

} // namespace fn_fbe81dc2

// 0x00238dc0 fight::ParamString<fight::PrintCondition>::vfunc_6 (26 B): matches/0x00238dc0.cpp
// sym: ?vfunc_6@?$ParamString@VPrintCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::PrintCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<fight::PrintCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<fight::PrintCondition>*)a)->*(*(bool (fight::ParamString<fight::PrintCondition>::**)(int))&this->f_10))(b);
}


// 0x00238de0 fight::ParamString<fight::PrintCondition>::vfunc_2 (11 B): matches/0x00238de0.cpp
// sym: ?vfunc_2@?$ParamString@VPrintCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::PrintCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00238e10 fight::ParamFloatConstRange<fight::PrintTrack>::vfunc_6 (26 B): matches/0x00238e10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPrintTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::PrintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::PrintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::PrintTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::PrintTrack>::**)(int))&this->f_10))(b);
}


// 0x00238e30 fight::ParamFloatConstRange<fight::PrintTrack>::vfunc_2 (11 B): matches/0x00238e30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPrintTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::PrintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00238e60 fight::ParamString<fight::PrintTrack>::vfunc_6 (26 B): matches/0x00238e60.cpp
// sym: ?vfunc_6@?$ParamString@VPrintCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::PrintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<fight::PrintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<fight::PrintTrack>*)a)->*(*(bool (fight::ParamString<fight::PrintTrack>::**)(int))&this->f_10))(b);
}


// 0x00238e80 fight::ParamString<fight::PrintTrack>::vfunc_2 (11 B): matches/0x00238e80.cpp
// sym: ?vfunc_2@?$ParamString@VPrintCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::PrintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00238ea0 fight::ConditionFactoryCasterTemplate<fight::PrintCondition>::vfunc_0 (36 B): matches/0x00238ea0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPrintCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::PrintCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00238ed0 fight::ParamString<fight::PrintCondition>::vfunc_0 (30 B): matches/0x00238ed0.cpp
// sym: ??_G?$ParamString@VPrintCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) the implicit destructor of the class: its scalar deleting destructor is emitted beside the vftable by
// the registration below that constructs it (FUN_00238f70 / FUN_00239010)


// 0x00238f00 fight::TrackFactoryCasterTemplate<fight::PrintTrack>::vfunc_0 (36 B): matches/0x00238f00.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPrintTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::PrintTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00238f30 fight::ParamFloatConstRange<fight::PrintTrack>::vfunc_0 (30 B): matches/0x00238f30.cpp
// sym: ??_G?$ParamFloatConstRange@VPrintTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) the implicit destructor of the class: its scalar deleting destructor is emitted beside the vftable by
// the registration below that constructs it (FUN_00238f70 / FUN_00239010)


// 0x00238f50 fight::ParamString<fight::PrintTrack>::vfunc_0 (30 B): matches/0x00238f50.cpp
// sym: ??_G?$ParamString@VPrintTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) the implicit destructor of the class: its scalar deleting destructor is emitted beside the vftable by
// the registration below that constructs it (FUN_00238f70 / FUN_00239010)


// 0x00238f70 FUN_00238f70 (158 B): matches/0x00238f70.cpp
// sym: ?FUN_00238f70@fn_fbe81dc2@@YAXXZ
// The parameters of fight::PrintCondition (gx2, D18: merged from PrintTrack.new_throw.cpp; constructs the real
// ParamString<PrintCondition>, whose vftable and scalar deleting destructor 0x00238ed0 this emits)
namespace fn_fbe81dc2 {
extern "C" void __cdecl FUN_002347b0(void*, void*, int);   // (decl1) as defined (ParamValueBool_2.cpp)
void FUN_00238f70()
{
    if (DAT_004e5c24 == 0) {
        fight::ParamValue* params[2];
        params[0] = new fight::ParamString<fight::PrintCondition>("channel", &owners::Object_238910::FUN_00238910);
        params[1] = new fight::ParamString<fight::PrintCondition>("text", &owners::Obj_00238970::FUN_00238970);
        FUN_002347b0(DAT_004e5c20, params, 2);
    }
    DAT_004e5c24++;
}
} // namespace fn_fbe81dc2


// 0x00239010 FUN_00239010 (213 B): matches/0x00239010.cpp
// sym: ?FUN_00239010@fn_fbe81dc2@@YAXXZ
// The parameters of fight::PrintTrack (gx2, D18: merged from PrintTrack.iso_00239010.cpp; constructs the real
// ParamFloatConstRange<PrintTrack> / ParamString<PrintTrack>: their scalar deleting destructors 0x00238f30, 0x00238f50)
namespace fn_fbe81dc2 {
void FUN_00239010() {
    if (!DAT_004e5c2c) {
        fight::ParamValue* params[3];
        params[0] = new fight::ParamFloatConstRange<fight::PrintTrack>("timeBegin", &Obj_238850::SetTimeBegin_00238850);
        params[1] = new fight::ParamString<fight::PrintTrack>("channel", &Obj::SetChannel_00238a80);
        params[2] = new fight::ParamString<fight::PrintTrack>("text", &fn_00238ae0::Object::SetText_00238ae0);
        FUN_002347b0(&DAT_004e5c28, params, 3);
    }
    ++DAT_004e5c2c;
}
} // namespace fn_fbe81dc2


// 0x002390f0 fight::PrintTrack::vfunc_10 (86 B): matches/0x002390f0.cpp
// sym: ?vfunc_10@PrintTrack@fight@@UAEHHHH@Z
hulk_intptr fight::PrintTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { Obj_2390f0 * a = (Obj_2390f0 *)__p0; Obj_2390f0 * b = (Obj_2390f0 *)__p1; Obj_2390f0 * p = (Obj_2390f0 *)__p2;

    Obj_2390f0* q = Alloc_0008d690(0x24);
    if (q) {
        q->Init_00232660();
        *(fight::PrintTrack**)((char*)q + 0x1c) = this;
        *(hulk_uintptr*)q = ((hulk_intptr)DAT_00428330);
        *(Obj_2390f0**)((char*)q + 0x20) = 0;
        if (p)
            p->F0();
        Obj_2390f0* old = *(Obj_2390f0**)((char*)q + 0x20);
        if (old)
            old->F1();
        *(Obj_2390f0**)((char*)q + 0x20) = p;
        return (hulk_intptr)(q);
    }
    return (int)(0);
}

namespace fn_fbe81dc2 {

// 0x00239150 fight::PrintAction::vfunc_2 (57 B): matches/0x00239150.cpp
// sym: ?f2@PrintAction_239150@fn_fbe81dc2@@QAEPAV12@E@Z
PrintAction_239150* PrintAction_239150::f2(unsigned char flags) {
    vptr = ((void**)DAT_00428330);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_239150 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x002391d0 FUN_002391d0 (38 B): matches/0x002391d0.cpp
// sym: _FUN_002391d0
extern "C" void FUN_002391d0(Obj* obj, const char* name) {
    ConditionFactoryCasterTemplate_2391d0 caster;
    caster.vftable = (void*)DAT_004283ac;   // (sweep-caster-fix1) the game's vftable by address
    obj->Set_00236760(FUN_002343e0(name, &caster));
}


// 0x00239200 FUN_00239200 (38 B): matches/0x00239200.cpp
// sym: _FUN_00239200
extern "C" void FUN_00239200(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_239200 caster;
    caster.vftable = (void*)DAT_004283b8;   // (sweep-caster-fix1) the game's vftable by address
    void* p = FUN_00236ac0(name, &caster);
    obj->set_002367c0(p);
}


// 0x002392b0 fight::ConditionFactoryTemplate<fight::PrintCondition>::vfunc_2 (43 B): matches/0x002392b0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_2392b0@fn_fbe81dc2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_2392b0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004283c4;
    base1_dtor_00238880();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fbe81dc2

// 0x00239320 fight::TrackFactoryTemplate<fight::PrintTrack>::vfunc_5 (66 B): matches/0x00239320.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPrintTrack@fight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<fight::PrintTrack>::vfunc_5() {
    return (void*)(new PrintTrack_239320);
}

namespace fn_fbe81dc2 {

// 0x00239370 fight::TrackFactoryTemplate<fight::PrintTrack>::vfunc_2 (43 B): matches/0x00239370.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fbe81dc2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004283e0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fbe81dc2
