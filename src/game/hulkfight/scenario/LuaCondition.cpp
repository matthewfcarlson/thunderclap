// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001a1290..0x001a1ed0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::LuaCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd836fc7 {
#define TREE_TU_END }
namespace fn_fd836fc7 {} using namespace fn_fd836fc7;
namespace fn_fd836fc7 {
struct FactoryCtor { void init_002343b0(); void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/scenario.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fd836fc7 {
class Obj_1a1290 {
  public:
    char SetTimeBegin_001a1290(int x);
};
class X_1a12a0 {
  public:
    char pad[0x10];
    int mValue;
    char SetTimeEnd_001a12a0(int v);
};
extern int* hulk_at_004e16f4;
class CCondition_1a12f0 {
  public:
    virtual int vfunc_0(int);
};
class LuaCondition_1a1330 {
  public:
    int a, b;
    virtual ~LuaCondition_1a1330();
    int d;
    virtual bool hulk_slot_F_00234270(void*); void FnF_002345b0();
};
} // namespace fn_fd836fc7
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fd836fc7 {
extern "C" char* __cdecl FUN_0008d6d0(unsigned int);
class StrHolder_1a1350 {
public:
    char pad[12];
    char* text;
    int length;
    bool FUN_001a1350(const char* src, int len);
};
extern int* hulk_at_004e16fc;
class CCondition_1a13e0 {
  public:
    virtual int vfunc_0(int);
};
class Track_1a13f0 {
  public:
    Track_1a13f0();
    virtual hulk_intptr Fnf_001a13e0(int);
};
class StrHolder_1a1460 {
public:
    char pad[20];
    char* text;
    int length;
    bool SetScript_001a1460(const char* src, int len);
};
struct Script_1a16b0 {
    char pad[0x14];
    int arg;
    int result;
};
struct Provider_1a16b0 {
};
int GetThing_001d4c90();
extern const VFT hulk_at_0041c2f8;
class LuaCondition_1a1800 {
  public:
    virtual void vfunc_0();
    virtual void p_vfunc_1();
    virtual void p_vfunc_2();
    virtual void c_vfunc_3();
    virtual void p_vfunc_4();
    void* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void Cleanup_002345b0();
    char pad[8];
    void* m_p;
};
typedef unsigned char u8_1a1840;
class LuaTrack : public Track_1a13f0 {
  public:
    virtual bool m_vf1_00234270(void*);
    virtual bool m_vf2_002342b0(int);
    virtual bool m_vf3_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool m_vf4_00234350(int, int);
    virtual LuaTrack* vfunc_5(u8_1a1840 param);
    virtual void m_vf6_001a1420();
    virtual void m_vf7_001a1430();
    virtual void* m_vf8_00236ba0(void*, void*);
    virtual int m_vf9_00236bb0(hulk_intptr, hulk_intptr, hulk_intptr);
    virtual hulk_intptr m_vf10_001a1c40(hulk_intptr, hulk_intptr, hulk_intptr);
    LuaTrack();
    char _m_pad_4[0x8];
    int a;
    float b;
    union { int c; hulk_intptr m14; };
    int d;
    void helper_00236d60();
};
extern int hulk_at_0041c318;
void ReleaseA_0008d340(void* p);
void ReleaseB_0008d330(void* p);
class ParamValueScript_1a1930 {
  public:
    ParamValueScript_1a1930(int);
    virtual void f();
    char pad[12];
};
class ParamScript_1a1930 : public ParamValueScript_1a1930 {
  public:
    ParamScript_1a1930(int, int);
    virtual void f();
    int value;
};
typedef unsigned int u32_1a1950;
struct C_1a1950 {
    bool go(u32_1a1950, u32_1a1950);
};
class Param {
  public:
    char pad[0xc];
    u32_1a1950 fn;
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    bool vfunc_6(hulk_uintptr a, u32_1a1950 b, u32_1a1950 c);
};
class CStageCondition_1a1970;
class ParamValue_1a1970 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a1970 : public ParamValue_1a1970 {
  public:
    int pad;
};
class CStageCondition_1a19c0;
class ParamValue_1a19c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a19c0 : public ParamValue_1a19c0 {
  public:
    int pad;
};
class CStageCondition_1a1a10;
class ParamValue_1a1a10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a1a10 : public ParamValue_1a1a10 {
  public:
    int pad;
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004c1558;
} // namespace fn_fd836fc7
namespace fight {
class ConditionFactoryCaster_1a1a30 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class LuaCondition_1a1a30 {};
} }
namespace fight {
class TrackFactoryCaster_1a1a90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class LuaTrack_1a1a90 {};
} }
namespace fn_fd836fc7 {
extern char DAT_004c1600;
extern "C" void __cdecl FUN_001a1350();
extern "C" char DAT_0041c3ac[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_002347b0(void*, void**, int);
class Base_1a1b00 {
  public:
    virtual void V0();
};
class ParamScript : public Base_1a1b00 {
  public:
    void Init_00234c00(const char*);
    char pad[8];
    void* mFn;
};
typedef unsigned int u32_1a1c40;
struct Track_1a1c40 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};
struct Param_1a1c40 {};
struct LuaAction_1a1c40 {
    u32_1a1c40 call_001a1880(u32_1a1c40, hulk_uintptr, u32_1a1c40);
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(int);
extern void* hulk_at_0041c390[];
class Ref_1a1c70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1a1c70 {
  public:
    void* vptr;
};
class LuaAction_1a1c70 : public Action_1a1c70 {
  public:
    char pad[28];
    Ref_1a1c70* m;
    LuaAction_1a1c70* f2(unsigned char flags);
};
class ConditionFactoryCasterTemplate_1a1cf0 {
  public:
    virtual bool cast_001a1a30(void*);
};
class Obj {
  public:
    void apply_00236760(void*);
};
extern "C" void* __cdecl lookup(const char*, ConditionFactoryCasterTemplate_1a1cf0*);
class TrackFactoryCasterTemplate_1a1d20 {
  public:
    virtual bool cast_001a1a90(void*);
};
class Track {
  public:
    void* get_002367c0(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1a1d20*);
} // namespace fn_fd836fc7
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd836fc7 {
class TrackFactoryTemplate_1a1d50 {
  public:
    TrackFactoryTemplate_1a1d50() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class LuaCondition_1a1d90 : public Base {
  public:
    LuaCondition_1a1d90() throw() : Base(0) {
        a = 0;
        b = 0;
    }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int a;
    int b;
};
extern int hulk_at_0041c42c;
struct ConditionFactoryTemplate_1a1dd0 {
    void* m_vptr;
    void base1_dtor_001a12d0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1a1e00 {
  public:
    TrackFactoryTemplate_1a1e00() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0041c318[];
struct LuaTrack_1a1e40 {
    void* vf;
    char pad[8];
    int x;
    int y;
    int z;
    int q;
    void initialize_00236d40();
};
extern void* alloc_0008d690(unsigned int);
extern int hulk_at_0041c448;


// 0x001a1290 FUN_001a1290 (12 B): matches/0x001a1290.cpp
// sym: ?SetTimeBegin_001a1290@Obj_1a1290@fn_fd836fc7@@QAEDH@Z
char Obj_1a1290::SetTimeBegin_001a1290(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x001a12a0 FUN_001a12a0 (12 B): matches/0x001a12a0.cpp
// sym: ?SetTimeEnd_001a12a0@X_1a12a0@fn_fd836fc7@@QAEDH@Z
char X_1a12a0::SetTimeEnd_001a12a0(int v) {
    mValue = v;
    return 1;
}


// 0x001a12d0 FUN_001a12d0 (19 B): matches/0x001a12d0.cpp
// sym: ?FUN_001a12d0@fn_fd836fc7@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a12d0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e16f4), ((char*)&DAT_004e16f8));
}

} // namespace fn_fd836fc7

// 0x001a12f0 hulkfight::scenario::LuaCondition::vfunc_0 (16 B): matches/0x001a12f0.cpp
// sym: ?vfunc_0@LuaCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::LuaCondition::vfunc_0(int index) {
    int* p = hulk_at_004e16f4;
    return p[index];
}

namespace fn_fd836fc7 {

// 0x001a1330 FUN_001a1330 (29 B): matches/0x001a1330.cpp
// sym: ??1LuaCondition_1a1330@fn_fd836fc7@@UAE@XZ
// Same code shape as 0x0011c270 (propagated; names are from that function)
LuaCondition_1a1330::~LuaCondition_1a1330() {
    Cleanup(d);
    FnF_002345b0();
}


// 0x001a1350 FUN_001a1350 (102 B): matches/0x001a1350.cpp
// sym: ?FUN_001a1350@StrHolder_1a1350@fn_fd836fc7@@QAE_NPBDH@Z
// FUN_001a1350 @ 0x001a1350
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
bool StrHolder_1a1350::FUN_001a1350(const char* src, int len) {
    thunk_FUN_00267090(text);
    if (src != 0 && len > 0) {
        text = FUN_0008d6d0(len + 1);
        memcpy(text, src, len);
        text[len] = 0;
        length = len;
        return true;
    }
    text = 0;
    length = 0;
    return true;
}


// 0x001a13c0 FUN_001a13c0 (19 B): matches/0x001a13c0.cpp
// sym: ?FUN_001a13c0@fn_fd836fc7@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a13c0() {
    FUN_00234810(((char*)&DAT_004e16fc), ((char*)&DAT_004e1700));
}

} // namespace fn_fd836fc7

// 0x001a13e0 hulkfight::scenario::LuaTrack::vfunc_0 (16 B): matches/0x001a13e0.cpp
// sym: ?vfunc_0@LuaTrack@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::LuaTrack::vfunc_0(int index) {
    int* p = hulk_at_004e16fc;
    return p[index];
}

namespace fn_fd836fc7 {

// 0x001a13f0 FUN_001a13f0 (36 B): matches/0x001a13f0.cpp
// sym: ??0LuaTrack@fn_fd836fc7@@QAE@XZ
LuaTrack::LuaTrack() : Track_1a13f0(), a(0), b(-1.0f), c(0), d(0) {}

} // namespace fn_fd836fc7

// 0x001a1420 hulkfight::scenario::LuaTrack::vfunc_6 (4 B): matches/0x001a1420.cpp
// sym: ?vfunc_6@LuaTrack@scenario@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::scenario::LuaTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x001a1430 hulkfight::scenario::LuaTrack::vfunc_7 (7 B): matches/0x001a1430.cpp [wrapped: lost its match in the tree (codegen differs (2 of 3 instructions))]
// sym: ?GetExtent@LuaTrack_1a1430@fn_001a1430@@UAEMXZ
namespace fn_001a1430 {
// Same code shape as 0x0012b630 (propagated; names are from that function)
struct Param {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};

struct Track {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

struct LuaTrack_1a1430 : Track, Param {
  public:
    virtual void vfunc0();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual hulk_freg GetExtent();
    virtual void vfunc10();

    int mFlags;
    float mMinX;
    float mMaxX;
    float mWidth;
    float mHeight;
};

hulk_freg LuaTrack_1a1430::GetExtent() {
    return mMaxX - mMinX;
}
} // namespace fn_001a1430


// 0x001a1440 FUN_001a1440 (29 B): matches/0x001a1440.cpp [wrapped: conflict: LuaTrack]
// sym: ?Run@LuaTrack@fn_001a1440@@QAEXXZ
namespace fn_001a1440 {
typedef unsigned int u32_1a1440;
extern void* LuaTrack_vft;
void __cdecl cleanup_0008d340(u32_1a1440);
struct LuaTrack {
    void* vft;
    char pad[0x10];
    u32_1a1440 field14;
    void Tail_00236d60();
    void Run();
};
void LuaTrack::Run() {
    vft = &LuaTrack_vft;
    cleanup_0008d340(field14);
    Tail_00236d60();
}
} // namespace fn_001a1440

namespace fn_fd836fc7 {

// 0x001a1460 FUN_001a1460 (102 B): matches/0x001a1460.cpp
// sym: ?SetScript_001a1460@StrHolder_1a1460@fn_fd836fc7@@QAE_NPBDH@Z
// SetScript_001a1460 @ 0x001a1460
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
bool StrHolder_1a1460::SetScript_001a1460(const char* src, int len) {
    thunk_FUN_00267090(text);
    if (src != 0 && len > 0) {
        text = FUN_0008d6d0(len + 1);
        memcpy(text, src, len);
        text[len] = 0;
        length = len;
        return true;
    }
    text = 0;
    length = 0;
    return true;
}

} // namespace fn_fd836fc7

// 0x001a16b0 hulkfight::scenario::LuaAction::vfunc_3 (71 B): matches/0x001a16b0.cpp
// sym: ?vfunc_3@LuaAction@scenario@hulkfight@@UAE_NHH@Z
bool hulkfight::scenario::LuaAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    hulk_intptr x = GetThing_001d4c90();
    if (!x)
        return false;
    Script_1a16b0* s = (*(Script_1a16b0 * *)&this->f_1c);
    int edi = s->result;
    if (edi) {
        int edx = s->arg;
        if (edx && !this->f_24) {
            this->f_24 = ((int)((owners::Object_1d2890 *)(((Provider_1a16b0*)x)))->FUN_001d2890((unsigned int)edx, (unsigned int)edi, 0));
            return true;
        }
    }
    return false;
}


// 0x001a1700 hulkfight::scenario::LuaAction::vfunc_5 (233 B): equivalent/0x001a1700.cpp [wrapped: conflict: hulkfight::scenario::LuaAction]
// sym: ?vfunc_5@LuaAction@scenario@hulkfight@fn_001a1700@@UAE_NHH@Z @b6005a4dca24 @w52f43a4c1438
namespace fn_001a1700 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::scenario::LuaAction::vfunc_5 @ 0x001a1700
struct TypeInfo_1a1700 { unsigned int data; }; extern TypeInfo_1a1700 DAT_00494b44, DAT_00494b60, DAT_004c13d0;
struct Object { char pad[8]; unsigned int id; };
extern Object* __cdecl FUN_00344e74(void*, int, TypeInfo_1a1700*, TypeInfo_1a1700*, int);
extern unsigned int __cdecl FUN_001d0440();
extern void* __cdecl FUN_001d0430(unsigned int);
struct Context { void FUN_001d2ee0(Object*); void FUN_001d1cb0(); void FUN_001d1d50(const char*,const char*); void FUN_001d1d30(); bool FUN_001d29b0(void*,bool*); };
extern Context* __cdecl FUN_001d4c90();
struct Handle_1a1700 { void FUN_001cb170(); };
namespace hulkfight { namespace scenario {
struct LuaAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, int); char pad[28]; void* object; void* script; Handle_1a1700 handle; };
bool LuaAction::vfunc_5(int n,int unused) { if(n>0) return true; if(!script) return false; Context* ctx=FUN_001d4c90(); if(!ctx) return false; Object* o=FUN_00344e74(object,0,&DAT_00494b44,&DAT_004c13d0,0); if(o) { unsigned int id=o->id; if(FUN_001d0440()!=id) { FUN_001d0430(o->id); handle.FUN_001cb170(); } } else { o=FUN_00344e74(object,0,&DAT_00494b44,&DAT_00494b60,0); if(o) ctx->FUN_001d2ee0(o); } ctx->FUN_001d1cb0(); ctx->FUN_001d1d50("node","DO NOT USE THIS IN RELEASE MODE!  Talk to Kevin..."); ctx->FUN_001d1d30(); bool result=false; if(!ctx->FUN_001d29b0(script,&result)) script=0; return script!=0; }
}}
} // namespace fn_001a1700

namespace fn_fd836fc7 {

// 0x001a17f0 hulkfight::scenario::LuaAction::vfunc_4 (1 B): matches/0x001a17f0.cpp
// sym: ?FUN_001a17f0@fn_fd836fc7@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001a17f0() {}


// 0x001a1800 hulkfight::scenario::LuaCondition::vfunc_5 (50 B): matches/0x001a1800.cpp
// sym: ?vfunc_5@LuaCondition_1a1800@fn_fd836fc7@@QAEPAXE@Z
// Same code shape as 0x0011cbc0 (propagated; names are from that function)
void* LuaCondition_1a1800::vfunc_5(unsigned char flag) {
    *(const VFT**)this = &hulk_at_0041c2f8;
    ai_free(m_p);
    Cleanup_002345b0();
    if (flag & 1) {
        ai_delete(this);
    }
    return this;
}


// 0x001a1840 hulkfight::scenario::LuaTrack::vfunc_5 (50 B): matches/0x001a1840.cpp
// sym: ?vfunc_5@LuaTrack@fn_fd836fc7@@UAEPAV12@E@Z
LuaTrack* LuaTrack::vfunc_5(u8_1a1840 param) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0041c318;
    ReleaseA_0008d340((void*)m14);
    helper_00236d60();
    if (param & 1)
        ReleaseB_0008d330(this);
    return this;
}

} // namespace fn_fd836fc7

// 0x001a1880 FUN_001a1880 (127 B): matches/0x001a1880.cpp [wrapped: conflict: DAT_00494b44]
// sym: ??0LuaAction@fn_001a1880@@QAE@HHPAVSub_1a1880@1@@Z
namespace fn_001a1880 {
class Sub_1a1880 {
  public:
    virtual void F();
    virtual void G();
    Sub_1a1880();
    char pad[0xdc];
};
class Result_1a1880 {
  public:
    Sub_1a1880* Convert_001d03c0();
};
struct Action_1a1880 {
    virtual void V();
    Action_1a1880();
    char pad[0x18];
};
extern char DAT_00494b44;
extern char DAT_004c13d0;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif

class LuaAction : public Action_1a1880 {
  public:
    LuaAction(int a, int b, Sub_1a1880* arg);
    virtual void V();
    int m1c;
    Sub_1a1880* m20;
    int m24;
    Sub_1a1880 sub;
};
LuaAction::LuaAction(int a, int b, Sub_1a1880* arg) : m20(0), m24(0) {
    m1c = b;
    if (arg)
        arg->F();
    if (m20)
        m20->G();
    m20 = arg;
    Result_1a1880* r = ((Result_1a1880 *)__RTDynamicCast((void*)(arg), 0, &DAT_00494b44, &DAT_004c13d0, 0));
    if (r)
        memcpy(&sub, r->Convert_001d03c0(), 0xe0);
}
} // namespace fn_001a1880


// 0x001a1900 FUN_001a1900 (36 B): matches/0x001a1900.cpp [wrapped: conflict: LuaAction]
// sym: ??1LuaAction@fn_001a1900@@UAE@XZ
namespace fn_001a1900 {
extern "C" char DAT_0041c390[];
extern "C" void _ReadWriteBarrier();
class Thing_1a1900 {
  public:
    virtual void A();
    virtual void Release();
};
class Action_1a1900 {
  public:
    virtual ~Action_1a1900() throw();
};
class LuaAction : public Action_1a1900 {
  public:
    char pad[0x1c];
    Thing_1a1900* mThing;
    virtual ~LuaAction() throw();
};
LuaAction::~LuaAction() throw() {
    *(void**)this = (void*)((hulk_intptr)DAT_0041c390);
    _ReadWriteBarrier();
    if (mThing) {
        mThing->Release();
        mThing = 0;
    }
}
} // namespace fn_001a1900

namespace fn_fd836fc7 {

// 0x001a1930 FUN_001a1930 (32 B): matches/0x001a1930.cpp
// sym: ??0ParamScript_1a1930@fn_fd836fc7@@QAE@HH@Z
ParamScript_1a1930::ParamScript_1a1930(int a, int b) : ParamValueScript_1a1930(a) {
    value = b;
}


// 0x001a1950 fight::ParamScript<hulkfight::scenario::LuaCondition>::vfunc_6 (31 B): matches/0x001a1950.cpp
// sym: ?vfunc_6@Param@fn_fd836fc7@@QAE_NIII@Z
// Same code shape as 0x00177c20 (propagated; names are from that function)
bool Param::vfunc_6(hulk_uintptr a, u32_1a1950 b, u32_1a1950 c) {
    if (!fn)
        return false;
    typedef bool (C_1a1950::*Fn)(u32_1a1950, u32_1a1950);
    Fn p = *(Fn*)&fn;
    return ((C_1a1950*)a->*p)(b, c);
}

} // namespace fn_fd836fc7

// 0x001a1970 fight::ParamScript<hulkfight::scenario::LuaCondition>::vfunc_2 (11 B): matches/0x001a1970.cpp
// sym: ?vfunc_2@?$ParamScript@VLuaCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamScript<hulkfight::scenario::LuaCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a19a0 fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::vfunc_6 (26 B): matches/0x001a19a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLuaTrack@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::**)(int))&this->f_10))(b);
}


// 0x001a19c0 fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::vfunc_2 (11 B): matches/0x001a19c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLuaTrack@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a19f0 fight::ParamScript<hulkfight::scenario::LuaTrack>::vfunc_6 (31 B): matches/0x001a19f0.cpp [wrapped: conflict: Param]
// sym: ?vfunc_6@Param@fn_001a19f0@@QAE_NIII@Z
namespace fn_001a19f0 {
// Same code shape as 0x00177c20 (propagated; names are from that function)
typedef unsigned int u32_1a19f0;
struct C_1a19f0 {
    bool go(u32_1a19f0, u32_1a19f0);
};
class Param {
  public:
    char pad[0xc];
    u32_1a19f0 fn;
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    bool vfunc_6(hulk_uintptr a, u32_1a19f0 b, u32_1a19f0 c);
};
bool Param::vfunc_6(hulk_uintptr a, u32_1a19f0 b, u32_1a19f0 c) {
    if (!fn)
        return false;
    typedef bool (C_1a19f0::*Fn)(u32_1a19f0, u32_1a19f0);
    Fn p = *(Fn*)&fn;
    return ((C_1a19f0*)a->*p)(b, c);
}
} // namespace fn_001a19f0


// 0x001a1a10 fight::ParamScript<hulkfight::scenario::LuaTrack>::vfunc_2 (11 B): matches/0x001a1a10.cpp
// sym: ?vfunc_2@?$ParamScript@VLuaCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamScript<hulkfight::scenario::LuaTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a1a30 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::LuaCondition>::vfunc_0 (36 B): matches/0x001a1a30.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VLuaCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::LuaCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c1558, 0) != 0;
}


// 0x001a1a60 fight::ParamScript<hulkfight::scenario::LuaCondition>::vfunc_0 (30 B): matches/0x001a1a60.cpp
// sym: ??_G?$ParamScript@VLuaCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamScript<hulkfight::scenario::LuaCondition>::~ParamScript() {}
#if defined(HULK_PTR64)
template class fight::ParamScript<hulkfight::scenario::LuaCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a1a60)
#endif


// 0x001a1a90 fight::TrackFactoryCasterTemplate<hulkfight::scenario::LuaTrack>::vfunc_0 (36 B): matches/0x001a1a90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VLuaTrack@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::scenario::LuaTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c1600, 0) != 0;
}


// 0x001a1ac0 fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::vfunc_0 (30 B): matches/0x001a1ac0.cpp
// sym: ??_G?$ParamFloatConstRange@VLuaTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a1ac0)
#endif


// 0x001a1ae0 fight::ParamScript<hulkfight::scenario::LuaTrack>::vfunc_0 (30 B): matches/0x001a1ae0.cpp
// sym: ??_G?$ParamScript@VLuaTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamScript<hulkfight::scenario::LuaTrack>::~ParamScript() {}
#if defined(HULK_PTR64)
template class fight::ParamScript<hulkfight::scenario::LuaTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a1ae0)
#endif

namespace fn_fd836fc7 {

// 0x001a1b00 FUN_001a1b00 (95 B): matches/0x001a1b00.cpp
// sym: ?FUN_001a1b00@fn_fd836fc7@@YAXXZ
// data: g_count_1a1b00 = DAT_004e16f8, g_slot_1a1b00 = DAT_004e16f4
void FUN_001a1b00() {
    void* tmp;
    if ((*(int*)&DAT_004e16f8) == 0) {
        ParamScript* p = (ParamScript*)FUN_0008d690(0x18);
        if (p) {
            p->Init_00234c00((const char*)((hulk_intptr)((char*)&DAT_0041c420)));
            *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041c3ac);
            *(hulk_uintptr*)((char*)p + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_001a1350);
            tmp = p;
        } else
            tmp = 0;
        FUN_002347b0(((void**)&DAT_004e16f4), &tmp, 1);
    }
    ++(*(int*)&DAT_004e16f8);
}

} // namespace fn_fd836fc7

// 0x001a1b60 FUN_001a1b60 (213 B): equivalent/0x001a1b60.cpp [wrapped: conflict: fight::ParamFloatConstRange; fight::ParamScript]
// sym: ?FUN_001a1b60@fn_001a1b60@@YAXXZ @e821b5c161a2 @w0447def177e4
namespace fn_001a1b60 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001a1b60 @ 0x001a1b60


void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_001a1290();
void __cdecl SetTimeEnd_001a12a0();
void __cdecl SetScript_001a1460();
namespace hulkfight { namespace scenario { class LuaTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamScript {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234c00(const char*);
};
}
void __cdecl FUN_002347b0(int*, void**, int);
void FUN_001a1b60() {
 if (!(*(int*)&DAT_004e1700)) {
 void* items[3];
 typedef fight::ParamFloatConstRange<hulkfight::scenario::LuaTrack> FloatParam;
 typedef fight::ParamScript<hulkfight::scenario::LuaTrack> ScriptParam;
 FloatParam* a = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(a) { a->FUN_00234960("timeBegin"); new (a) FloatParam; a->callback = SetTimeBegin_001a1290; }
 items[0] = a;
 FloatParam* b = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
 if(b) { b->FUN_00234960("timeEnd"); new (b) FloatParam; b->callback = SetTimeEnd_001a12a0; }
 items[1] = b;
 ScriptParam* c = (ScriptParam*)FUN_0008d690((int)sizeof(ScriptParam));
 if(c) { c->FUN_00234c00("script"); new (c) ScriptParam; c->callback = SetScript_001a1460; }
 items[2] = c;
 FUN_002347b0(&DAT_004e16fc, items, 3);
 }
 ++(*(int*)&DAT_004e1700);
}
} // namespace fn_001a1b60


// 0x001a1c40 hulkfight::scenario::LuaTrack::vfunc_10 (48 B): matches/0x001a1c40.cpp
// sym: ?vfunc_10@LuaTrack@scenario@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::scenario::LuaTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1a1c40 a = (u32_1a1c40)__p0; u32_1a1c40 b = (u32_1a1c40)__p1; u32_1a1c40 c = (u32_1a1c40)__p2;

    LuaAction_1a1c40* p = (LuaAction_1a1c40*)FUN_0008d690(0x108);
    if (p)
        return (int)(p->call_001a1880(a, (hulk_uintptr)this, c));
    return (int)(0);
}

namespace fn_fd836fc7 {

// 0x001a1c70 hulkfight::scenario::LuaAction::vfunc_2 (57 B): matches/0x001a1c70.cpp
// sym: ?f2@LuaAction_1a1c70@fn_fd836fc7@@QAEPAV12@E@Z
LuaAction_1a1c70* LuaAction_1a1c70::f2(unsigned char flags) {
    vptr = hulk_at_0041c390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1a1c70 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x001a1cf0 FUN_001a1cf0 (38 B): matches/0x001a1cf0.cpp
// sym: _FUN_001a1cf0
extern "C" void __cdecl FUN_001a1cf0(Obj* obj, const char* name) {
    ConditionFactoryCasterTemplate_1a1cf0 caster;
    obj->apply_00236760(lookup(name, &caster));
}


// 0x001a1d20 FUN_001a1d20 (38 B): matches/0x001a1d20.cpp
// sym: _FUN_001a1d20
extern "C" void* FUN_001a1d20(Track* t, const char* name) {
    TrackFactoryCasterTemplate_1a1d20 c;
    return t->get_002367c0(FUN_00236ac0(name, &c));
}

} // namespace fn_fd836fc7

// 0x001a1d50 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::LuaCondition>::vfunc_1 (60 B): matches/0x001a1d50.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VLuaCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::LuaCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a1d50));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_1a1d50* t = new (mem) TrackFactoryTemplate_1a1d50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a1d90 fight::ConditionFactoryTemplate<hulkfight::scenario::LuaCondition>::vfunc_5 (54 B): matches/0x001a1d90.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VLuaCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::LuaCondition>::vfunc_5() {
    return (void*)(new LuaCondition_1a1d90);
}

namespace fn_fd836fc7 {

// 0x001a1dd0 fight::ConditionFactoryTemplate<hulkfight::scenario::LuaCondition>::vfunc_2 (43 B): matches/0x001a1dd0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1a1dd0@fn_fd836fc7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1a1dd0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041c42c;
    base1_dtor_001a12d0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd836fc7

// 0x001a1e00 fight::TrackFactoryCasterTemplate<hulkfight::scenario::LuaTrack>::vfunc_1 (60 B): matches/0x001a1e00.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VLuaTrack@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::scenario::LuaTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a1e00));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_1a1e00* t = new (mem) TrackFactoryTemplate_1a1e00();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a1e40 fight::TrackFactoryTemplate<hulkfight::scenario::LuaTrack>::vfunc_5 (66 B): matches/0x001a1e40.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VLuaTrack@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::scenario::LuaTrack>::vfunc_5() {
    LuaTrack_1a1e40* p = (LuaTrack_1a1e40*)alloc_0008d690(0x1c);
    if (p) {
        p->initialize_00236d40();
        p->vf = (void*)((hulk_intptr)DAT_0041c318);
        p->x = 0;
        p->y = (int)0xbf800000;
        p->z = 0;
        p->q = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fd836fc7 {

// 0x001a1e90 fight::TrackFactoryTemplate<hulkfight::scenario::LuaTrack>::vfunc_2 (43 B): matches/0x001a1e90.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd836fc7@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041c448;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd836fc7
