// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00238850..0x002393a0 (kind game, layer engine, confidence high), dominant class fight::PrintTrack
#include "tree_prelude.h"
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
    ~PrintAction_238d70() throw();
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
class ConditionFactoryCasterTemplate_2391d0 {
  public:
    virtual bool Cast_00238ea0(void*);
};
extern "C" void* Find(const char*, ConditionFactoryCasterTemplate_2391d0*);
class TrackFactoryCasterTemplate_239200 {
  public:
    virtual bool cast_00238f00(void*);
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
    Base() throw();
    virtual void a();
    virtual bool Fnb_00234270(void*);
    virtual bool Fnc_002342b0(int);
    int pad;
    int flag;
};
class PrintTrack_239320 : public Base {
  public:
    PrintTrack_239320() throw() {
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

// 0x002388e0 FUN_002388e0 (38 B): matches/0x002388e0.cpp
// sym: ?dtorish@PrintCondition_2388e0@fn_fbe81dc2@@QAEXXZ
// Same code shape as 0x0012e590 (propagated; names are from that function)
void PrintCondition_2388e0::dtorish() {
    u32_2388e0 x = a;
    vt = &hulk_at_004282dc;
    thunk_FUN_00267090(x);
    thunk_FUN_00267090(b);
    Condition_2388e0::finish_002345b0();
}

} // namespace fn_fbe81dc2

// 0x00238910 FUN_00238910 (82 B): equivalent/0x00238910.cpp
// sym: ?FUN_00238910@Object_238910@owners@@QAE_NPBD@Z @ceb1083b6fd1 @w2ae63d33cad5
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


// 0x00238a50 FUN_00238a50 (38 B): matches/0x00238a50.cpp
// sym: ?FUN_00238a50@PrintTrack@fight@@QAEXXZ
void fight::PrintTrack::FUN_00238a50() {
    *(hulk_uintptr*)this = (hulk_uintptr)&hulk_at_004282fc;
    ReleaseThing_0008d340(this->f_10);
    ReleaseThing_0008d340(this->f_14);
    ((PrintTrack_nv_238a50*)this)->Cleanup_00236d60();
}

namespace fn_fbe81dc2 {

// 0x00238a80 FUN_00238a80 (82 B): equivalent/0x00238a80.cpp
// sym: ?SetChannel_00238a80@Obj@fn_fbe81dc2@@QAE_NPBD@Z @479a89a7457f @wf4aa5da2059f
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetChannel_00238a80 @ 0x00238a80
bool Obj::SetChannel_00238a80(const char* value) { FUN_0008d340(text); if (!value) { text = 0; return true; } unsigned int length = 0; while (value[length]) ++length; text = (char*)FUN_0008d6d0(length + 1); char* dest = text; do { *dest++ = *value; } while (*value++); return true; }

} // namespace fn_fbe81dc2

// 0x00238ae0 FUN_00238ae0 (82 B): equivalent/0x00238ae0.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: ?SetText_00238ae0@Object@fn_00238ae0@@QAE_NPBD@Z @f4449191efda @w7da5b8150b6f
namespace fn_00238ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetText_00238ae0 @ 0x00238ae0
/* size_t: tree_prelude.h */
extern "C" void __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
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

// 0x00238ca0 fight::PrintCondition::vfunc_5 (59 B): matches/0x00238ca0.cpp
// sym: ?v5@PrintCondition_238ca0@fn_fbe81dc2@@UAEPAXE@Z
// Same code shape as 0x0012fc90 (propagated; names are from that function)
void* PrintCondition_238ca0::v5(unsigned char flag) {
    *(char**)this = ((char*)DAT_004282dc);
    thunk_FUN_00267090(m_p1);
    thunk_FUN_00267090b_0008d340(m_p2);
    ((BaseCls_238ca0*)this)->Dtor_002345b0();
    if (flag & 1) {
        thunk_FUN_00267090c_0008d330(this);
    }
    return this;
}

} // namespace fn_fbe81dc2

// 0x00238ce0 fight::PrintTrack::vfunc_5 (59 B): matches/0x00238ce0.cpp [wrapped: conflict: PrintTrack]
// sym: ?vfunc_5@PrintTrack@fn_00238ce0@@UAEPAV12@E@Z
namespace fn_00238ce0 {
extern "C" char DAT_004282fc[];
void __cdecl thunk_FUN_00267090(void* p);
void __cdecl thunk_FUN_00267090_b(void* p);
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    void FUN_00236d60();
    char pad[8];
    int a;
    int b;
};
class PrintTrack : public Track {
  public:
    virtual PrintTrack* vfunc_5(unsigned char);
};
PrintTrack* PrintTrack::vfunc_5(unsigned char p) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004282fc);
    thunk_FUN_00267090((void*)(*(hulk_intptr*)((char*)&this->b)));
    thunk_FUN_00267090((void*)(*(hulk_intptr*)((char*)this + 0x14)));
    FUN_00236d60();
    if (p & 1)
        thunk_FUN_00267090_b((void*)this);
    return this;
}
} // namespace fn_00238ce0

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
PrintAction_238d70::~PrintAction_238d70() throw() {
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
template <> fight::ParamString<fight::PrintCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<fight::PrintCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x238ed0)
#endif


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
template <> fight::ParamFloatConstRange<fight::PrintTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<fight::PrintTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x238f30)
#endif


// 0x00238f50 fight::ParamString<fight::PrintTrack>::vfunc_0 (30 B): matches/0x00238f50.cpp
// sym: ??_G?$ParamString@VPrintTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<fight::PrintTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<fight::PrintTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x238f50)
#endif


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
    obj->Set_00236760(Find(name, &caster));
}


// 0x00239200 FUN_00239200 (38 B): matches/0x00239200.cpp
// sym: _FUN_00239200
extern "C" void FUN_00239200(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_239200 caster;
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
