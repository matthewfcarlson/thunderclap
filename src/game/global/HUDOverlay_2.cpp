// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000cc7e0..0x000d40e0 (kind game, layer game, confidence high), dominant class HUDOverlay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/content.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3fdf6d3 {
#define TREE_TU_END }
namespace fn_f3fdf6d3 {} using namespace fn_f3fdf6d3;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f3fdf6d3 {
struct Vec3_cc7e0 {
    float x, y, z;
};
struct Handle_cc7e0 {
    char pad0[8];
    Vec3_cc7e0 *pos;      // 0x08
    char pad1[4];
    unsigned int *col;  // 0x10
    void FUN_0008ef00();
};
} // namespace fn_f3fdf6d3
struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual Handle_cc7e0 *v30(int a, int b, int c, int d, int e);
    virtual void v31(Handle_cc7e0 *h);
};
namespace fn_f3fdf6d3 {
struct Pass_cc7e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
struct PassHolder_cc7e0 {
    Pass_cc7e0 *pass;
    void FUN_00293d00(const Vec3_cc7e0 *color);
    void FUN_00293bf0(float a);
    void FUN_00293da0(float a, float b, float c);
};
struct Widget_cc7e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};
struct Sub_cc7e0 {
    char pad0[0x144];
    float f144;
    float f148;
    float f14c;
};
struct Owner_cc7e0 {
    char pad0[0x11c];
    Sub_cc7e0 *sub;
    float FUN_00036090();
    hulk_freg FUN_000360b0();
};
struct Tex_cc7e0 {
    char pad0[0x10];
    int id;
};
union Word_cc7e0 {
    float f;
    unsigned int u;
};
extern float FUN_000186b0(const float &v, const float &lo, const float &hi);
extern "C" float FUN_000186f0(const float &a, const float &b);
extern "C" float FUN_00018710(const float &a, const float &b);
static __forceinline float Lerp(float a, float b, float t)
{
    return (1.0f - t) * a + b * t;
}
static __forceinline void EmitV(Handle_cc7e0 *h, float x, float z, unsigned int color)
{
    Vec3_cc7e0 *p = h->pos;
    p->x = x;
    p->y = 0.0f;
    p->z = z;
    *h->col = color;
    h->FUN_0008ef00();
}
static __forceinline void EmitP(Handle_cc7e0 *h, Vec3_cc7e0 &v, float x, float z, unsigned int color)
{
    v.x = x;
    v.y = 0.0f;
    v.z = z;
    ((owners::Obj_8ef90 *)h)->FUN_0008ef90((unsigned int *)(const Vec3_cc7e0 *)(&v), color);
}
static __forceinline float Clamp01(float v)
{
    float r;
    if (v >= 0.0f && v <= 1.0f)
        r = v;
    else if (v > 1.0f)
        r = 1.0f;
    else
        r = 0.0f;
    return r;
}
struct Frame_cc7e0 {
    Word_cc7e0 s0;        // A (clamped progress 1)
    Word_cc7e0 s1;        // B (clamped progress 2)
    Word_cc7e0 s2;        // N1 (x extent of 1ac - 1a4); scratch in mode 1
    Word_cc7e0 s3;
    Word_cc7e0 s4;        // colC
    Word_cc7e0 s5;
    Word_cc7e0 s6;
    Word_cc7e0 s7;
    Word_cc7e0 s8;
    Word_cc7e0 s9;        // N2
    Vec3_cc7e0 v;         // vertex passed to FUN_0008ef90 / f144, f148, f14c in mode 1
    Word_cc7e0 s13;
    Word_cc7e0 s14;
    Word_cc7e0 s15;
    Word_cc7e0 s16;
    Word_cc7e0 s17;
    Word_cc7e0 s18;
};
} // namespace fn_f3fdf6d3
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f3fdf6d3 {
class Thing_ce590 {
    char pad[0x264];

  public:
    void Finish_000caab0();
    void SetName(const char* s);
};
} // namespace fn_f3fdf6d3
extern U64 __cdecl FUN_0027b020(unsigned int value);
namespace fn_f3fdf6d3 {
struct Item_ce750 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void setPosition(float);
 virtual void slot13();
 virtual void setRange(float,float);
 virtual void slot15();
 virtual void setMode(int);
 virtual void slot17();
 virtual void setEnabled(int);
};
struct Collection_ce750 { char pad[0x24]; Item_ce750** begin; Item_ce750** end; };
struct Object {
  public:
    char _m_pad_0[0x248];
    Collection_ce750* collection;
    int value;
    void FUN_000ce5c0(unsigned int first, U64 result, unsigned int last);
    void FUN_000ce700(unsigned int first, unsigned int value, unsigned int last);
    void FUN_000ce750(int);
};
class Ref_ce850 {
  public:
    virtual void f();
    virtual void Release();
};
class Obj_ce850 {
  public:
    char p0[0x14];
    Ref_ce850* a;
    Ref_ce850* b;
    char p1[0x0c];
    int x[10];
    unsigned char flag;
    char p2[0x33];
    int value;
    void reset();
};
class CActorManager_ce910 {
  public:
    void f();
};
class Dummy_ce980 {
  public:
    void Call(void*);
};
class Dummy_cea00 {
  public:
    void Call(void*);
};
class Dummy_cea80 {
  public:
    void Call(void*);
};
extern "C" char DAT_0048e10c[];
extern "C" char DAT_0040a500[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
class Owner_ceaa0 {};
typedef void (Owner_ceaa0::*Fn_ceaa0)(const char*, float, float, int);
class Method4_ceaa0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_ceaa0 fn;
    Method4_ceaa0* FUN_000ceaa0(const char*, Fn_ceaa0);
};
struct Vector_ceb30 { float x,y,z; };
struct HUDOverlay_ceb30 {};
struct HUDOverlay_cec00 {
    int FUN_000cec00(int a, const char *b, const char *c);
};
struct Function_cec00 { virtual void vfunc_0(); virtual void vfunc_1(); };
class Function_cec90 {
  public:
    virtual void f0();
    virtual void f1();
};
} // namespace fn_f3fdf6d3
namespace math {
struct Vector_ced10 {
    float x, y, z;
};
}
namespace fn_f3fdf6d3 {
class HUDOverlay_ced10 {
  public:
    void Action(math::Vector_ced10);
};
class Function_ced10 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
} // namespace fn_f3fdf6d3
namespace math {
struct Vector_cedb0 {
    float x, y, z;
};
}
namespace fn_f3fdf6d3 {
class HUDOverlay_cedb0 {
  public:
    int go(int, math::Vector_cedb0);
};
class Function_cedb0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct Vector_cee60 { float x, y, z; };
struct HUDOverlay_cee60 { void FUN_000cee60(int, Vector_cee60); };
struct Arguments { int index; Vector_cee60 position; };
class HUDOverlay_cef00 {
  public:
    int Do(int, int);
};
struct Args {
    int a;
    int b;
};
class Function_cefa0 {
  public:
    virtual void f0();
    virtual void f1();
};
class HUDOverlay_cefa0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void run(unsigned char, float);
};
class HUDOverlay_cf030 {
  public:
    void Act(int, bool);
};
class Function_cf030 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_0040a590[];
class Function_cf050 {
  public:
    void Init_001d0480(int, int);
};
extern "C" char __cdecl GetFlag_001d04d0(const char*);
class Method4_cf050 : public Function_cf050 {
  public:
    hulk_intptr v;
    char pad[0x14];
    char m18;
    char pad2[3];
    int n;
    Method4_cf050(hulk_intptr, hulk_intptr);
};
} // namespace fn_f3fdf6d3
namespace math {
struct Vector_cf0e0 {
    float x, y, z;
};
}
namespace fn_f3fdf6d3 {
class HUDOverlay_cf0e0 {
  public:
    int x;
};
typedef int (HUDOverlay_cf0e0::*Fn_cf0e0)(int, int, math::Vector_cf0e0, math::Vector_cf0e0);
template <class T> inline T Pop(char*& p) {
    T v = *(T*)p;
    p += sizeof(T);
    return v;
}
class Function_cf0e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(HUDOverlay_cf0e0* o, char* a, int* out);
    int pad[5];
};
extern char hulk_at_0048e10c[];
char Lookup_001d04d0(char*);
class Function_cf160 {
  public:
    Function_cf160(int, int);
    virtual void X();
    char pad[0xc];
};
class Method3_cf160 : public Function_cf160 {
  public:
    virtual void X();
    char b10, b11, b12, pad2[5];
    char b18;
    char pad3[3];
    int m1c;
    Method3_cf160(hulk_intptr a, hulk_intptr c);
};
class CFEManager_cf290 {
  public:
    void Call(const char*, int);
};
class Function_cf290 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_0040a5c0[];
class Owner_cf2b0 {};
typedef int (Owner_cf2b0::*Fn_cf2b0)(int, const char*, int, int, int);
class Method5_cf2b0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_cf2b0 p1c;
    void FUN_001d0480(const char*, int);
    Method5_cf2b0* Init(const char*, Fn_cf2b0);
};
struct Vec_cf350 {
    unsigned int x, y, z;
};
class HUDOverlay_cf350 {
public:
    int Act(int a1, const char *a2, Vec_cf350 v3, Vec_cf350 v4, Vec_cf350 v5);
};
typedef int (HUDOverlay_cf350::*ActFn_cf350)(int, const char *, Vec_cf350, Vec_cf350, Vec_cf350);
struct Args_cf350 {
    int a1;
    const char *a2;
    Vec_cf350 v3;
    Vec_cf350 v4;
    Vec_cf350 v5;
};
class Function_cf350 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_cf460 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_cf460::*MFn_cf460)(unsigned char);
class Function_cf460 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
typedef unsigned int u32_cf490;
struct Track {
    int FUN_001d60c0();
};
struct Node {
  public:
    virtual void v0();
    virtual void v1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void v13(int a);
    virtual void v14();
    char _m_pad_4[0xc];
    float x;
    float y;
    float z;
    char _m_pad_1c[0xd0];
    Track *track;
    int FUN_001d62d0();
};
class ProgressGauge {
public:
    char pad0[0x14];
    Owner_cc7e0 *owner;           // 0x14
    char pad18[0x90 - 0x18];
    Tex_cc7e0 *tex;               // 0x90
    char pad94[0xb8 - 0x94];
    unsigned char flags;    // 0xb8
    char padb9[0x154 - 0xb9];
    float f154;
    float f158;
    char pad15c[4];
    int alpha;              // 0x160
    Widget_cc7e0 *w164;
    char pad168[0x174 - 0x168];
    float f174;
    float f178;
    float f17c;
    char pad180[0x18c - 0x180];
    float f18c;
    float f190;
    char pad194[4];
    Widget_cc7e0 *w198;
    char pad19c[4];
    int mode;               // 0x1a0
    Node *p1a4;
    Node *p1a8;
    Node *p1ac;
    Node *p1b0;
    Node *p1b4;
    Node *p1b8;
    Node *p0[3];            // 0x1bc
    Node *p1[3];            // 0x1c8
    char pad1d4[0x1e0 - 0x1d4];
    Node *p1e0;
    Node *p1e4;
    Node *p1e8;
    float w[3];             // 0x1ec

    void FUN_000cc7e0();
};
struct Lookup_ce5c0 {
    Node* FUN_000d3f10(int key);
};
struct Parent_ce5c0 {
    char pad[0x114];
    Lookup_ce5c0* lookup;
};
class Obj_ce5c0 {
public:
    int run(int key, int lo, int hi, int arg4);
    char p0[0x7c];
    Parent_ce5c0* parent;
    char p1[0x214 - 0x80];
    int counter;
    Node* node;
    int n21c;
    float f220;
    char active;
    char has;
    char pad226[2];
    int lo;
    int hi;
    char pad230[0x23c - 0x230];
    int n23c;
    int n240;
};
struct Lookup_cf4b0 {
    Node *FUN_001def30(const char *name);
};
struct Table_cf4b0 {
    float *FUN_00024280(unsigned __int64 key);
};
struct Slot_cf4b0 {
    char name[0x40];
};
struct Owner_cf4b0 {
    char pad0[0x0c];
    Lookup_cf4b0 *lookup;
    char pad1[0x20 - 0x10];
    Table_cf4b0 *table;
};
struct Ctl_cf4b0 {
    char pad0[0x0c];
    Owner_cf4b0 *owner;
    char pad1[0xb8 - 0x10];
    unsigned flags;
    char pad2[0x250 - 0xbc];
    void *p250;
    char pad3[0x264 - 0x254];
    Slot_cf4b0 slots[8];
    char pad4[0x478 - 0x464];
    float f478;
    float f47c;
    float f480;
    float f484;
    float f488;
    float f48c;
    float f490;
    int i494;

    void FUN_000cf4b0(float dt);
};
struct Vec3_cf740 {
    float x, y, z;
};
struct Pass_cf740 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
struct PassHolder_cf740 {
    Pass_cf740 *pass;
    void FUN_00293d00(const Vec3_cf740 *color);
    void FUN_00293da0(int a, int b, int c);   // float bits
    void FUN_00293bf0(float a);
};
class Effect_cf740 {
public:
    char pad0[0x218];
    Sprite *sprite;         // 0x218

    void FUN_000ce280();
    void FUN_000cf740();
};
class CActorManager_cf830 {
  public:
    void run();
};
class CActorManager_cf8b0 {
  public:
    void invoke(const char*);
};
class CActorManager_cf940 {
  public:
    void invoke(const char*);
};
class CActorManager_cf9d0 {
  public:
    void invoke(const char*);
};
} // namespace fn_f3fdf6d3
namespace math {
struct Vector_cfa40 {
    float x, y, z;
};
}
namespace fn_f3fdf6d3 {
class HUDOverlay_cfa40 {
  public:
    void Fn(const char*, float, float, math::Vector_cfa40);
};
class CActorManager_cfb70 {
  public:
    int act();
};
} // namespace fn_f3fdf6d3
namespace math {
struct Vector_cfc00 {
    float x, y, z;
};
}
namespace fn_f3fdf6d3 {
class HUDOverlay_cfc00 {
  public:
    void Show(math::Vector_cfc00);
};
class Function_cfc00 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, math::Vector_cfc00*, int);
};
class Method1_cfc00 : public Function_cfc00 {
  public:
    char pad[0x18];
    void (HUDOverlay_cfc00::*method)(math::Vector_cfc00);
    HUDOverlay_cfc00* obj;
};
struct Vector_cfd70 { float x, y, z; };
struct HUDOverlay_cfd70 {};
extern "C" unsigned char __cdecl lookup(const void*);
class Function_cfda0 {
  public:
    virtual void invoke();
    Function_cfda0(int, int);
};
class Method2_cfda0 : public Function_cfda0 {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char a;
    unsigned char b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int m;
    Method2_cfda0(int x, int y) : Function_cfda0(x, 2) {
        m = y;
        c = lookup(((int*)&DAT_0048e134));
        a = lookup(((int*)&DAT_0048e134));
        b = lookup(((int*)&DAT_0048e0f0));
    }
};
class Closure2_cfda0 : public Method2_cfda0 {
  public:
    virtual void invoke();
    int n;
    Closure2_cfda0(int x, int y, int z);
};
class HUDOverlay_cfed0 {
  public:
    void Call(unsigned char, float);
};
struct Arg_cff70 {
    const char* s;
    unsigned char b;
};
class Actor_cff70 {
  public:
    void invoke(const char*, unsigned char);
};
} // namespace fn_f3fdf6d3
namespace math {
struct Vector_d0040 { float x,y,z; };
}
namespace fn_f3fdf6d3 {
struct HUDOverlay_d0040 { void invoked(int, int, math::Vector_d0040); };
class CActorManager_d0100 {
  public:
    void Method(const char*, float);
};
struct Pair_d0100 {
    const char* s;
    float f;
};
class Actor_d01f0 {
  public:
    void fn(unsigned char);
};
} // namespace fn_f3fdf6d3
namespace math {
class Vector_d1220 { public: float x, y, z; };
}
namespace fn_f3fdf6d3 {
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f3fdf6d3
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f3fdf6d3 {
class HUDOverlay_d1220 {};
typedef void (HUDOverlay_d1220::*Fn_d1220)(const char*, float, float, math::Vector_d1220);
class Registry_d1220 { public:
    void FUN_000d1220(const char* a1, HUDOverlay_d1220* a2, Fn_d1220 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_d1220;
template<> class Closure4_d1220<HUDOverlay_d1220, void, const char*, float, float, math::Vector_d1220> : public ScriptFunctionFields { public: virtual void v(); Fn_d1220 fn; HUDOverlay_d1220* owner; Closure4_d1220(HUDOverlay_d1220* o) { owner = o; } };
class Raw_d1220 { public: void FUN_000ceaa0(const char*, Fn_d1220); };
class HUDOverlay_d1280 {};
typedef int (HUDOverlay_d1280::*Fn_d1280)(const char*, const char*, float);
class Registry_d1280 { public:
    void FUN_000d1280(const char* a1, HUDOverlay_d1280* a2, Fn_d1280 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_d1280;
template<> class Closure3_d1280<HUDOverlay_d1280, int, const char*, const char*, float> : public ScriptFunctionFields { public: virtual void v(); Fn_d1280 fn; HUDOverlay_d1280* owner; Closure3_d1280(HUDOverlay_d1280* o) { owner = o; } };
class Raw_d1280 { public: void FUN_000ceb80(const char*, Fn_d1280); };
} // namespace fn_f3fdf6d3
namespace math {
class Vector_d1530 { public: float x, y, z; };
}
namespace fn_f3fdf6d3 {
class HUDOverlay_d1530 {};
typedef int (HUDOverlay_d1530::*Fn_d1530)(int, int, math::Vector_d1530, math::Vector_d1530);
class Registry_d1530 { public:
    void FUN_000d1530(const char* a1, HUDOverlay_d1530* a2, Fn_d1530 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_d1530;
template<> class Closure4_d1530<HUDOverlay_d1530, int, int, int, math::Vector_d1530, math::Vector_d1530> : public ScriptFunctionFields { public: virtual void v(); Fn_d1530 fn; HUDOverlay_d1530* owner; Closure4_d1530(HUDOverlay_d1530* o) { owner = o; } };
class Raw_d1530 { public: void FUN_000cf050(const char*, Fn_d1530); };
} // namespace fn_f3fdf6d3
namespace math {
class Vector_d1590 { public: float x, y, z; };
}
namespace fn_f3fdf6d3 {
class HUDOverlay_d1590 {};
typedef void (HUDOverlay_d1590::*Fn_d1590)(int, int, math::Vector_d1590);
class Registry_d1590 { public:
    void FUN_000d1590(const char* a1, HUDOverlay_d1590* a2, Fn_d1590 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_d1590;
template<> class Closure3_d1590<HUDOverlay_d1590, void, int, int, math::Vector_d1590> : public ScriptFunctionFields { public: virtual void v(); Fn_d1590 fn; HUDOverlay_d1590* owner; Closure3_d1590(HUDOverlay_d1590* o) { owner = o; } };
class Raw_d1590 { public: void FUN_000cf160(const char*, Fn_d1590); };
} // namespace fn_f3fdf6d3
namespace math {
class Vector_d1640 { public: float x, y, z; };
}
namespace fn_f3fdf6d3 {
class HUDOverlay_d1640 {};
typedef int (HUDOverlay_d1640::*Fn_d1640)(int, const char*, math::Vector_d1640, math::Vector_d1640, math::Vector_d1640);
class Registry_d1640 { public:
    void FUN_000d1640(const char* a1, HUDOverlay_d1640* a2, Fn_d1640 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_d1640;
template<> class Closure5_d1640<HUDOverlay_d1640, int, int, const char*, math::Vector_d1640, math::Vector_d1640, math::Vector_d1640> : public ScriptFunctionFields { public: virtual void v(); Fn_d1640 fn; HUDOverlay_d1640* owner; Closure5_d1640(HUDOverlay_d1640* o) { owner = o; } };
class Raw_d1640 { public: void FUN_000cf2b0(const char*, Fn_d1640); };
class Typed {
public:
    virtual void v0();
    virtual unsigned long long GetTypeId();
};
class Arg_d3d80 {
public:
    int FUN_000fad90();
};
class Owner_d3d80 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void vfunc_23(void *obj, int v);
    char pad04[0xa64 - 4];
    unsigned char dirty;
};
struct FEBackground_nv_d3d80 {
    FEBackground *FUN_000d7af0(int a, int b);
    char FUN_000d7890(Arg_d3d80 *arg, void *p2, Owner_d3d80 *owner);
};
struct FEMemCardControl_nv_d3d80 {
    FEMemCardControl *FUN_000d82d0(int a, void *p1);
    char FUN_000dc230(Arg_d3d80 *arg, void *p2, Owner_d3d80 *owner);
};
struct FETextInput_nv_d3d80 {
    FETextInput *FUN_000dc590(int a);
    char FUN_000dd350(Arg_d3d80 *arg, void *p2, Owner_d3d80 *owner);
};
owners::Thing_d3ef0* thunk_FUN_000fc1b0();


// 0x000cc7e0 FUN_000cc7e0 (4769 B): equivalent/0x000cc7e0.cpp
// sym: ?FUN_000cc7e0@ProgressGauge@fn_f3fdf6d3@@QAEXXZ @90b870bd457f @w6cea4adae229
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 56/56)
// FUN_000cc7e0 @ 0x000cc7e0
// FUN_000cc7e0: debug/HUD gauge drawer (builds quads through the vertex-handle API)
void ProgressGauge::FUN_000cc7e0()
{
    if (!(flags & 1))
        return;

    Frame_cc7e0 F;

    (*(PassHolder_cc7e0**)&DAT_0052c2ac)->pass->v15(0);
    (*(PassHolder_cc7e0**)&DAT_0052c2ac)->FUN_00293d00(((Vec3_cc7e0*)&DAT_004ddf0c));
    (*(PassHolder_cc7e0**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
    (*(PassHolder_cc7e0**)&DAT_0052c2ac)->FUN_00293da0(1.2f, 1.2f, 1.2f);
    w164->v8(0, 0);
    w198->v8(0, 0);

    F.s2.f = p1ac->x - p1a4->x;
    F.s9.f = p1b8->x - p1b0->x;

    float T0 = owner->FUN_000360b0();
    double D = owner->FUN_00036090() - T0;
    F.s0.f = Clamp01((f154 - T0) / D);
    F.s1.f = Clamp01((f158 - T0) / D);

    unsigned int a24 = (unsigned int)alpha << 24;
    unsigned int colA = a24 | 0xff00;
    unsigned int colB = a24 | (f154 < f158 ? 0xff0000 : 0x79fe4);
    F.s4.u = a24 | (f174 < f178 ? 0xff0000 : 0x79fe4);

    if (mode == 0) {
        float xa = p1a4->x;
        float zA = p1a4->z;
        float zB = p1a8->z;
        float mn = F.s0.f < F.s1.f ? F.s0.f : F.s1.f;
        float X1 = mn * F.s2.f + p1a4->x;
        Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitV(h, xa, zA, colA);
        EmitV(h, X1, zA, colA);
        EmitV(h, xa, zB, colA);
        EmitV(h, X1, zB, colA);
        DAT_0052c2a8->v31(h);

        float mn2 = F.s0.f < F.s1.f ? F.s0.f : F.s1.f;
        float X1b = mn2 * F.s2.f + p1a4->x;
        float mx = F.s0.f < F.s1.f ? F.s1.f : F.s0.f;
        float X2 = mx * F.s2.f + p1a4->x;
        Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitV(h2, X1b, zA, colB);
        EmitV(h2, X2, zA, colB);
        EmitV(h2, X1b, zB, colB);
        EmitV(h2, X2, zB, colB);
        DAT_0052c2a8->v31(h2);
    } else if (mode == 1) {
        Sub_cc7e0 *s = owner->sub;
        F.v.x = s->f144;        // a
        F.v.y = s->f148;        // b
        F.v.z = s->f14c;        // c
        float cx[3];
        float cy[3];
        F.s8.f = 1.0f;
        F.s6.f = 0.0f;
        F.s7.f = 1.0f / F.v.x;
        F.s5.f = F.s7.f * f174;
        cx[0] = FUN_000186b0(F.s5.f, F.s6.f, F.s8.f);

        F.s8.f = f174 - F.v.x;
        F.s5.f = 1.0f;
        F.s3.f = 0.0f;
        F.s6.f = 1.0f / F.v.y;
        F.s2.f = F.s6.f * F.s8.f;
        cx[1] = FUN_000186b0(F.s2.f, F.s3.f, F.s5.f);

        F.s3.f = 1.0f;
        F.s2.f = 0.0f;
        F.s5.f = 1.0f / F.v.z;
        F.s8.f = (F.s8.f - F.v.y) * F.s5.f;
        cx[2] = FUN_000186b0(F.s8.f, F.s2.f, F.s3.f);

        F.s7.f = F.s7.f * f178;
        F.s8.f = 1.0f;
        F.s3.f = 0.0f;
        cy[0] = FUN_000186b0(F.s7.f, F.s3.f, F.s8.f);

        F.s7.f = 1.0f;
        F.s3.f = 0.0f;
        F.s8.f = f178 - F.v.x;
        F.s6.f = F.s8.f * F.s6.f;
        cy[1] = FUN_000186b0(F.s6.f, F.s3.f, F.s7.f);

        F.s8.f = (F.s8.f - F.v.y) * F.s5.f;
        F.s6.f = 0.0f;
        F.s7.f = 1.0f;
        cy[2] = FUN_000186b0(F.s8.f, F.s6.f, F.s7.f);

        for (int i = 0; i < 3; i++) {
            if (!(w[i] <= 0.0f)) {
                float x0 = p0[i]->x;
                float z0 = p0[i]->z;
                float z1 = p1[i]->z;
                float mn = cx[i] < cy[i] ? cx[i] : cy[i];
                float q1 = mn * w[i] + p0[i]->x;
                Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
                EmitV(h, x0, z0, colA);
                EmitV(h, q1, z0, colA);
                EmitV(h, x0, z1, colA);
                EmitV(h, q1, z1, colA);
                DAT_0052c2a8->v31(h);

                Word_cc7e0 dd;
                dd.f = cx[i] - cy[i];
                dd.u &= 0x7fffffff;
                if (!(dd.f <= 1e-05f)) {
                    float qx = w[i] * cx[i] + p0[i]->x;
                    float z0b = p0[i]->z;
                    float z1b = p1[i]->z;
                    float qy = w[i] * cy[i] + p0[i]->x;
                    float lo = qx;
                    float hi = qy;
                    if (qy < qx) {
                        lo = qy;
                        hi = qx;
                    }
                    Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
                    EmitV(h2, lo, z0b, F.s4.u);
                    EmitV(h2, hi, z0b, F.s4.u);
                    EmitV(h2, lo, z1b, F.s4.u);
                    EmitV(h2, hi, z1b, F.s4.u);
                    DAT_0052c2a8->v31(h2);
                }
            }
        }

        Handle_cc7e0 *h3 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitV(h3, p1b0->x, p1b0->z, 0x8000ff00);
        float t = F.s0.f * F.s9.f;
        EmitV(h3, t + p1b0->x, p1b0->z, 0x8000ff00);
        EmitV(h3, p1b4->x, p1b4->z, 0x8000ff00);
        EmitV(h3, t + p1b4->x, p1b4->z, 0x8000ff00);
        DAT_0052c2a8->v31(h3);
    } else if (mode == 2) {
        float N3 = p1e8->x - p1e0->x;
        float u = f18c / owner->FUN_000360b0();
        if (!(u < 1.0f))
            u = 1.0f;
        float v = f190 / owner->FUN_000360b0();
        if (!(v < 1.0f))
            v = 1.0f;
        float x0 = p1e0->x;
        float z0 = p1e0->z;
        float z1 = p1e4->z;
        float mn = u < v ? u : v;
        float q = mn * N3 + p1e0->x;
        Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h, F.v, x0, z0, colA);
        EmitP(h, F.v, q, z0, colA);
        EmitP(h, F.v, x0, z1, colA);
        EmitP(h, F.v, q, z1, colA);
        DAT_0052c2a8->v31(h);

        float mn2 = u < v ? u : v;
        float X1 = mn2 * N3 + p1e0->x;
        float mx = u < v ? v : u;
        float X2 = mx * N3 + p1e0->x;
        Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h2, F.v, X1, z0, F.s4.u);
        EmitP(h2, F.v, X2, z0, F.s4.u);
        EmitP(h2, F.v, X1, z1, F.s4.u);
        EmitP(h2, F.v, X2, z1, F.s4.u);
        DAT_0052c2a8->v31(h2);
    } else if (mode == 3 || mode == 4 || mode == 5) {
        F.s7.f = Lerp(p1b0->z, p1a4->z, f17c);          // zA
        F.s6.f = Lerp(p1b4->z, p1a8->z, f17c);          // zB
        F.s5.f = Lerp(p1b0->x, p1a4->x, f17c);          // xA
        float mn = FUN_000186f0(F.s0.f, F.s1.f);
        float xB1 = (mn * F.s2.f + p1b0->x) * (1.0f - f17c);
        float mn2 = FUN_000186f0(F.s0.f, F.s1.f);
        F.s4.f = (mn2 * F.s2.f + p1a4->x) * f17c + xB1;  // xB
        Handle_cc7e0 *h = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h, F.v, F.s5.f, F.s7.f, colA);
        EmitP(h, F.v, F.s4.f, F.s7.f, colA);
        EmitP(h, F.v, F.s5.f, F.s6.f, colA);
        EmitP(h, F.v, F.s4.f, F.s6.f, colA);
        DAT_0052c2a8->v31(h);

        F.s3.f = 1.0f - f17c;
        Node *b0c = p1b0;
        float mnA = FUN_000186f0(F.s0.f, F.s1.f);
        F.s9.f = (mnA * F.s2.f + b0c->x) * F.s3.f;      // xC
        float mnB = FUN_000186f0(F.s0.f, F.s1.f);
        F.s5.f = (mnB * F.s2.f + p1a4->x) * f17c + F.s9.f;      // xD
        float mxA = FUN_00018710(F.s0.f, F.s1.f);
        F.s9.f = (mxA * F.s2.f + b0c->x) * F.s3.f;      // xE
        float mxB = FUN_00018710(F.s0.f, F.s1.f);
        F.s4.f = (mxB * F.s2.f + p1a4->x) * f17c + F.s9.f;      // xF
        Handle_cc7e0 *h2 = DAT_0052c2a8->v30(tex->id, 1, 0x2020, 4, 0);
        EmitP(h2, F.v, F.s5.f, F.s7.f, colB);
        EmitP(h2, F.v, F.s4.f, F.s7.f, colB);
        EmitP(h2, F.v, F.s5.f, F.s6.f, colB);
        EmitP(h2, F.v, F.s4.f, F.s6.f, colB);
        DAT_0052c2a8->v31(h2);
    }

    (*(PassHolder_cc7e0**)&DAT_0052c2ac)->pass->v16(0);
}

} // namespace fn_f3fdf6d3

// 0x000cda90 FUN_000cda90 (1592 B): equivalent/0x000cda90.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_000cda90@Obj_cda90@fn_000cda90@@QAEXXZ @4534d983a0f3 @wa8ebbed18463
namespace fn_000cda90 {
// STATUS: equivalent (tools/equiv.py level 3: 19593 inputs, branch coverage 39/40, incomplete)
// FUN_000cda90 @ 0x000cda90
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Batch_cda90 {
    char pad00[8];
    unsigned int *pos;
    char pad0c[4];
    unsigned int *col;
    void FUN_0008ef00();
};

class Gfx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Batch_cda90 *Begin(unsigned int id, int a, int b, int c, int d);
    virtual void End(Batch_cda90 *b);
};

class Cam_cda90 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void Push(int a);
    virtual void Pop(int a);
};

struct Vec3f { float x, y, z; };
struct Renderer_cda90 {
    Cam_cda90 *cam;
    void FUN_00293d00(const void *v);
    void FUN_00293bf0(float a);
    void FUN_00293da0(float a, float b, float c);
};

class Widget_cda90 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void Flush(int a, int b);
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void SetValue(float v);
};

struct WList {
    char pad00[8];
    unsigned char count;
    char pad09[0x1b];
    Widget_cda90 **items;
};

struct Pt_cda90 {
    char pad00[0x10];
    float f10;
    char pad14[4];
    unsigned int f18;
};

struct Id_cda90 { char pad[0x10]; unsigned int id; };

class Obj_cda90 {
public:
    char pad00[0x90];
    Id_cda90 *p90;
    char pad94[0x24];
    unsigned int flags;
    char padbc[0x250 - 0xbc];
    Widget_cda90 *p250;
    Widget_cda90 *p254;
    Widget_cda90 *p258;
    WList *p25c;
    WList *p260;
    char pad264[0x464 - 0x264];
    Pt_cda90 *p464;
    Pt_cda90 *p468;
    float f46c;
    float f470;
    int f474;
    char pad478[8];
    float f480;
    float f484;
    float f488;
    char pad48c[8];
    int f494;
    int f498;
    float f49c;
    void FUN_000cda90();
};

union I_cda90 {
    int i;
    hulk_uintptr u;
    float f;
};

struct Frame_cda90 {
    unsigned int s10;
    unsigned int s14;
    I_cda90 s18;
    I_cda90 s1c;
    int A;
    I_cda90 s24;
    I_cda90 s28;
    I_cda90 s2c;
    float g1;
};

void Obj_cda90::FUN_000cda90()
{
    Frame_cda90 f;
    if (!(flags & 2))
        return;
    if (p250 == 0)
        return;
    hulk_freg T = f49c;
    if (T == -1.0f)
        T = f488;
    f.s2c.i = 0xfa0;
    if (f474 != 0)
        f.s2c.i = 0x189c;
    int idx = f498;
    int cnt = idx + 1;
    if (idx == -1) {
        cnt = 1 - (int)(T / (float)f.s2c.i * -5.0f);
        if (cnt > 6)
            cnt = 6;
    }
    f.s1c.f = 1.0f / (T / cnt + 1.0f);
    f.A = (int)(f.s1c.f * f480);
    f.s24.i = (int)(f.s1c.f * f484);
    int D = (int)(T / cnt + 1.0f);
    f.s2c.i = (int)f480 % D;
    f.g1 = (float)f.s2c.i * f.s1c.f;
    f.s2c.i = (int)f484 % D;
    f.s2c.f = (float)f.s2c.i * f.s1c.f;
    (*(Renderer_cda90**)&DAT_0052c2ac)->cam->Push(0);
    (*(Renderer_cda90**)&DAT_0052c2ac)->FUN_00293d00(((Vec3f*)&DAT_004ddef4));
    (*(Renderer_cda90**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
    (*(Renderer_cda90**)&DAT_0052c2ac)->FUN_00293da0((*(float*)&DAT_0049fd28), (*(float*)&DAT_0049fd28), (*(float*)&DAT_0049fd28));
    p250->Flush(0, 0);
    unsigned int alpha = (unsigned int)f494 << 24;
    unsigned int col1 = alpha | 0xff0000;
    Widget_cda90 *obj1 = p258;
    WList *wl = p260;
    if (f474 != 0) {
        obj1 = p254;
        wl = p25c;
        col1 = alpha | 0x79fe4;
    }
    f.s1c.u = (hulk_uintptr)obj1;
    unsigned int col2 = alpha | 0xf0e614;
    int A = f.A;
    if (A != f.s24.i) {
        if (f494 > 0x80) {
            f.s18.i = 0;
            if (wl->count > 0) {
                do {
                    Widget_cda90 *w = wl->items[(unsigned char)f.s18.i];
                    f.s28.i = f.s24.i;
                    if (A >= f.s24.i)
                        f.s28.i = A;
                    w->SetValue((float)f.s28.i);
                    f.s18.i++;
                    A = f.A;
                } while (f.s18.i < wl->count);
                obj1 = (Widget_cda90 *)f.s1c.u;
            }
            obj1->Flush(0, 0);
            obj1 = (Widget_cda90 *)f.s1c.u;
            A = f.A;
        }
        f.s18.i = 0;
        if (wl->count > 0) {
            do {
                Widget_cda90 *w = wl->items[(unsigned char)f.s18.i];
                f.s28.i = A;
                if (!(A < f.s24.i))
                    f.s28.i = f.s24.i;
                w->SetValue((float)f.s28.i);
                f.s18.i++;
                A = f.A;
            } while (f.s18.i < wl->count);
            obj1 = (Widget_cda90 *)f.s1c.u;
        }
    } else {
        f.s18.i = 0;
        if (wl->count > 0) {
            f.s28.f = (float)f.A;
            do {
                Widget_cda90 *w = wl->items[(unsigned char)f.s18.i];
                w->SetValue(f.s28.f);
                f.s18.i++;
            } while (f.s18.i < wl->count);
            obj1 = (Widget_cda90 *)f.s1c.u;
        }
    }
    obj1->Flush(0, 0);
    f.s2c.f = f.s2c.f;
    hulk_freg X1 = p464->f10 - f.g1 * f470;
    f.s10 = *(unsigned int *)&p464->f10;
    f.s14 = p464->f18;
    f.s18.f = X1;
    f.s1c.u = p468->f18;
    int edi;
    if (f480 > f484 && (f.s28.f = f480 - f484, f.s28.u &= 0x7fffffff, f.s28.f > 1e-5f)) {
        hulk_freg Y2 = p464->f10 - f.s2c.f * f470;
        f.s18.f = Y2;
        Batch_cda90 *b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        unsigned int *pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        edi = 0;
    } else if (f.s24.i > f.A) {
        f.s2c.f = p464->f10 - f.s2c.f * f470;
        Batch_cda90 *b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        unsigned int *pp = b->pos;
        pp[0] = f.s2c.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s2c.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        edi = 0;
    } else {
        Batch_cda90 *b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        unsigned int *pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        f.s18.f = p464->f10 - f.s2c.f * f470;
        f.s10 = 0;
        hulk_freg x1 = p464->f10 - f.g1 * f470;
        *(float *)&f.s10 = x1;
        b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        edi = 0;
    }
    (*(Renderer_cda90**)&DAT_0052c2ac)->cam->Pop(edi);
}
} // namespace fn_000cda90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000ce0d0 FUN_000ce0d0 (431 B): equivalent/0x000ce0d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Update@Target_ce0d0@fn_000ce0d0@@QAEXM@Z @9fa1e1c5257b @we98e1e5c43c8
namespace fn_000ce0d0 {
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 27/32, incomplete)
// FUN_000ce0d0 @ 0x000ce0d0

struct Obj218 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

struct Target_ce0d0 {
    char pad0[0x218];
    Obj218* obj;
    char* target;      // 0x21c, float at +0xc
    float level;       // 0x220
    char fading;       // 0x224
    char pad225[3];
    int f228;
    int f22c;
    float f230;
    char pad234[4];
    int alpha;         // 0x238
    float elapsed;     // 0x23c
    float limit;       // 0x240

    void Update(float dt);
};

static float clamp01(float v)
{
    if (v >= 0.0f && v <= 1.0f) return v;
    if (v > 1.0f) return 1.0f;
    return 0.0f;
}

void Target_ce0d0::Update(float dt)
{
    elapsed = dt + elapsed;
    if (fading) {
        if (limit > 0.0f) {
            if (elapsed > limit) fading = 0;
        }
    }
    if (fading) {
        level = clamp01(level - DAT_0049fd10);
        f230 = f230 + 0.1f;
    } else {
        level = clamp01(DAT_0049fd10 + level);
        f230 = f230 - 0.1f;
    }
    *(float*)(target + 0xc) = level;
    alpha = (int)((1.0f - level) * 255.0f);
    if (alpha > 255) alpha = 255;
    else if (alpha < 0) alpha = 0;
    if (!fading) {
        float d = level - 1.0f;
        if (d < 0.0f) d = -d;
        if (d <= 1e-05f) {
            if (obj) {
                obj->v14();
                if (obj) {
                    obj->v1();
                    obj = 0;
                }
            }
            f228 = 0;
            f22c = 0;
        }
    }
}
} // namespace fn_000ce0d0


// 0x000ce280 FUN_000ce280 (778 B): equivalent/0x000ce280.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_000ce280@Billboard_ce280@fn_000ce280@@QAEXXZ @1555ee40e07e @wad0ff6d3fbb1
namespace fn_000ce280 {
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 14/14)
// FUN_000ce280 @ 0x000ce280
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_ce280 {
    float x, y, z;
};

union Word_ce280 {
    float f;
    int i;
    unsigned int u;
};

struct Cell_ce280 {
    Word_ce280 a, b, c, d;
};

struct Source_ce280 {
    int FUN_000f7240(unsigned int lo, unsigned int hi);
};

struct Handle_ce280 {
};

struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual Handle_ce280 *v30(int a, int b, int c, int d, int e);
    virtual void v31(Handle_ce280 *h);
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57();
    virtual void v58(int on);
};

struct Pass_ce280 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_ce280 {
    Pass_ce280 *pass;
    void FUN_00293d00(const Vec3_ce280 *color);
};

struct Texture {
    char pad0[0x10];
    int id;
};

struct Builder {
    char hdr[8];
    Cell_ce280 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source_ce280 *src);
    void FUN_000f78e0();
    hulk_freg FUN_000cb750(int idx, int mode);
    hulk_freg FUN_000cb6f0(int idx, int mode);
    void FUN_000f87c0(int idx, int mode, void *extra);
};


class Billboard_ce280 {
public:
    char pad0[0x78];
    float size;             // 0x78
    Source_ce280 *source;         // 0x7c
    char pad80[0x94 - 0x80];
    char extra[0x228 - 0x94];
    unsigned int keyLo;     // 0x228
    unsigned int keyHi;     // 0x22c
    float height;           // 0x230
    Texture *texture;       // 0x234
    int alpha;              // 0x238

    void FUN_000ce280();
};

struct Frame_ce280 {
    float w;
    Word_ce280 hb;
    Vec3_ce280 v[4];
    Builder x;
};

void Billboard_ce280::FUN_000ce280()
{
    if (source == 0)
        return;
    if ((keyLo | keyHi) == 0)
        return;

    Frame_ce280 f;
    f.x.FUN_000f7fe0(source);
    int idx = source->FUN_000f7240(keyLo, keyHi);
    if (idx != -1) {
        f.x.cells[f.x.cursor].a.f = DAT_0049fd14 * size;
        f.x.cells[f.x.cursor].c.i = 2;
        int mode = DAT_0049fd18;
        f.x.cells[f.x.cursor].b.i = 1;
        f.x.scale = 1.0f;
        f.x.cells[f.x.cursor].d.u = (alpha << 24) | 0x14c828;

        f.w = f.x.FUN_000cb750(idx, mode) * 1.3f;
        float t = f.x.FUN_000cb6f0(idx, DAT_0049fd18) * 1.4f;
        if (t < height)
            height = t;
        if (height < 0.0f)
            height = 0.0f;

        f.hb.f = height;
        f.hb.u &= 0x7fffffff;
        if (!(f.hb.f <= 1e-05f)) {
            DAT_0052c2a8->v58(0);
            (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v15(0);
            Vec3_ce280 *c = &f.v[0];
            *c = (*(Vec3_ce280*)&DAT_004ddea4);
            (*(PassHolder_ce280**)&DAT_0052c2ac)->FUN_00293d00(c);
            Handle_ce280 *h = DAT_0052c2a8->v30(texture->id, 1, 0x2020, 4, 0);

            f.v[0].x = f.w * -0.5f;
            f.v[0].y = height * -0.5f;
            f.v[0].z = 0.0f;
            f.v[1].y = height * 0.5f;
            f.v[1].z = 0.0f;
            f.w = f.w * 0.5f;
            f.v[1].x = f.w;
            f.v[2].x = f.v[0].x;
            f.v[2].z = 0.0f;
            f.v[2].y = f.v[1].y;
            f.v[3].x = f.w;
            f.v[3].y = f.v[0].y;
            f.v[3].z = 0.0f;
            ((owners::Obj_8ef90 *)h)->FUN_0008ef90((unsigned int *)(const Vec3_ce280 *)(&f.v[0]), 0x7f000000);
            ((owners::Obj_8ef90 *)h)->FUN_0008ef90((unsigned int *)(const Vec3_ce280 *)(&f.v[2]), 0x7f000000);
            ((owners::Obj_8ef90 *)h)->FUN_0008ef90((unsigned int *)(const Vec3_ce280 *)(&f.v[3]), 0x7f000000);
            ((owners::Obj_8ef90 *)h)->FUN_0008ef90((unsigned int *)(const Vec3_ce280 *)(&f.v[1]), 0x7f000000);
            DAT_0052c2a8->v31(h);
            (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v16(0);
            DAT_0052c2a8->v58(1);
            if (alpha > 0) {
                (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v15(0);
                Vec3_ce280 *c2 = &f.v[1];
                *c2 = (*(Vec3_ce280*)&DAT_004ddea4);
                (*(PassHolder_ce280**)&DAT_0052c2ac)->FUN_00293d00(c2);
                f.x.FUN_000f87c0(idx, DAT_0049fd18, extra);
                (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v16(0);
            }
        }
    }
    f.x.FUN_000f78e0();
}
} // namespace fn_000ce280
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3fdf6d3 {

// 0x000ce590 FUN_000ce590 (41 B): matches/0x000ce590.cpp
// sym: ?SetName@Thing_ce590@fn_f3fdf6d3@@QAEXPBD@Z
void Thing_ce590::SetName(const char* s) {
    ((owners::Obj_cac60 *)this)->FUN_000cac60();
    strncpy((char*)this + 0x264, s, 0x40);
    Finish_000caab0();
}


// 0x000ce5c0 FUN_000ce5c0 (314 B): equivalent/0x000ce5c0.cpp
// sym: ?run@Obj_ce5c0@fn_f3fdf6d3@@QAEHHHHH@Z @3e1284b9f20e @w7d6324eba870
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 13/14, incomplete)
// FUN_000ce5c0 @ 0x000ce5c0
int Obj_ce5c0::run(int key, int lo_, int hi_, int arg4)
{
    counter = (counter + 1) % 10000;
    if (counter == 0)
        counter = 1;
    n240 = arg4;
    n23c = 0;

    Node* found = parent->lookup->FUN_000d3f10(key);
    if (found == 0) {
        active = 0;
        has = 0;
        lo = 0;
        hi = 0;
        return counter;
    }
    if (active != 0)
        return counter;

    if (node != 0) {
        node->v14();
        if (node != 0) {
            node->v1();
            node = 0;
        }
    }
    active = 1;
    found->v0();
    if (node != 0)
        node->v1();
    node = found;
    found->v13(n21c);
    if ((lo_ | hi_) != 0) {
        lo = lo_;
        has = 1;
        hi = hi_;
        f220 = 1.0f;
        return counter;
    }
    has = 0;
    lo = 0;
    hi = 0;
    f220 = 1.0f;
    return counter;
}


// 0x000ce700 FUN_000ce700 (68 B): matches/0x000ce700.cpp
// sym: ?FUN_000ce700@Object@fn_f3fdf6d3@@QAEXIII@Z
void Object::FUN_000ce700(unsigned int first, unsigned int value, unsigned int last) {
    if (value)
        FUN_000ce5c0(first, FUN_0027b020(value), last);
    else
        FUN_000ce5c0(first, 0, last);
}


// 0x000ce750 FUN_000ce750 (242 B): equivalent/0x000ce750.cpp
// sym: ?FUN_000ce750@Object@fn_f3fdf6d3@@QAEXH@Z @bb3fc3d5ab2e @w248e16db59e9
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 10/10)
// FUN_000ce750 @ 0x000ce750
void Object::FUN_000ce750(int v) {
 if(v != 0 && value == v) return;
 value = v;
 float first = 0.0f, last = 0.0f;
 int mode = 1, enabled = 0;
 if(v != 0) {
 int n = v * 30;
 first = (float)(n - 29);
 last = (float)n;
 mode = 2; enabled = 1;
 }
 if((unsigned char)(collection->end - collection->begin) == 0) return;
 int i = 0;
 do {
 Item_ce750* item = collection->begin[(unsigned char)i];
 item->setRange(first,last);
 item->setPosition(first);
 item->setMode(mode);
 item->setEnabled(enabled);
 ++i;
 } while(i < (unsigned char)(collection->end - collection->begin));
}


// 0x000ce850 FUN_000ce850 (82 B): matches/0x000ce850.cpp
// sym: ?reset@Obj_ce850@fn_f3fdf6d3@@QAEXXZ
void Obj_ce850::reset() {
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    flag = 0;
    value = 0xff;
    for (int i = 0; i < 10; i++)
        x[i] = 0;
}

} // namespace fn_f3fdf6d3

// 0x000ce8f0 Method0<HUDOverlay,void>::vfunc_0 (30 B): matches/0x000ce8f0.cpp
// sym: ??_G?$Method0@VHUDOverlay@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<HUDOverlay, void>::~Method0() {}


// 0x000ce910 Method0<HUDOverlay,void>::vfunc_2 (12 B): matches/0x000ce910.cpp
// sym: ?vfunc_2@?$Method0@VHUDOverlay@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<HUDOverlay, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_ce910 * a = (CActorManager_ce910 *)__p0;

    (a->*(*(void (CActorManager_ce910::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<HUDOverlay, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xce8f0)
#endif


// 0x000ce960 Method1<HUDOverlay,void,const_char_*>::vfunc_0 (30 B): matches/0x000ce960.cpp
// sym: ??_G?$Method1@VHUDOverlay@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<HUDOverlay, void, const char *>::~Method1() {}


// 0x000ce980 Method1<HUDOverlay,void,const_char_*>::vfunc_2 (19 B): matches/0x000ce980.cpp
// sym: ?vfunc_2@?$Method1@VHUDOverlay@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<HUDOverlay, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_ce980* d = (Dummy_ce980*)a;
    (d->*(*(void (Dummy_ce980::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<HUDOverlay, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xce960)
#endif


// 0x000ce9e0 Method1<HUDOverlay,void,int>::vfunc_0 (30 B): matches/0x000ce9e0.cpp
// sym: ??_G?$Method1@VHUDOverlay@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<HUDOverlay, void, int>::~Method1() {}


// 0x000cea00 Method1<HUDOverlay,void,int>::vfunc_2 (19 B): matches/0x000cea00.cpp
// sym: ?vfunc_2@?$Method1@VHUDOverlay@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<HUDOverlay, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_cea00* d = (Dummy_cea00*)a;
    (d->*(*(void (Dummy_cea00::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<HUDOverlay, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xce9e0)
#endif


// 0x000cea60 Method1<HUDOverlay,void,float>::vfunc_0 (30 B): matches/0x000cea60.cpp
// sym: ??_G?$Method1@VHUDOverlay@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<HUDOverlay, void, float>::~Method1() {}


// 0x000cea80 Method1<HUDOverlay,void,float>::vfunc_2 (19 B): matches/0x000cea80.cpp
// sym: ?vfunc_2@?$Method1@VHUDOverlay@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<HUDOverlay, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_cea80* d = (Dummy_cea80*)a;
    (d->*(*(void (Dummy_cea80::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<HUDOverlay, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcea60)
#endif

namespace fn_f3fdf6d3 {

// 0x000ceaa0 FUN_000ceaa0 (102 B): matches/0x000ceaa0.cpp
// sym: ?FUN_000ceaa0@Method4_ceaa0@fn_f3fdf6d3@@QAEPAV12@PBDP8Owner_ceaa0@2@AEX0MMH@Z@Z
// FUN_000ceaa0 @ 0x000ceaa0
Method4_ceaa0* Method4_ceaa0::FUN_000ceaa0(const char* name, Fn_ceaa0 fp) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (void*)DAT_0040a500;
    fn = fp;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(DAT_0048e10c);
    return this;
}

} // namespace fn_f3fdf6d3

// 0x000ceb10 Method4<HUDOverlay,void,const_char_*,float,float,math::Vector>::vfunc_0 (30 B): matches/0x000ceb10.cpp
// sym: ??_G?$Method4@VHUDOverlay@@XPBDMMVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<HUDOverlay, void, const char *, float, float,math::Vector>::~Method4() {}


// 0x000ceb30 Method4<HUDOverlay,void,const_char_*,float,float,math::Vector>::vfunc_2 (80 B): equivalent/0x000ceb30.cpp
// sym: ?vfunc_2@?$Method4@VHUDOverlay@@XPBDMMVVector@math@@@@UAEXPAX00@Z @80c1e69fabd4 @wa9e830b47232
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<HUDOverlay,void,const_char_*,float,float,math::Vector>::vfunc_2 @ 0x000ceb30
template <> void Method4<HUDOverlay, void, const char *, float, float,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_ceb30 * object = (HUDOverlay_ceb30 *)__p0; const unsigned int * args = (const unsigned int *)__p1; void * unused = (void *)__p2;

    union Bits { unsigned int u; float f; } a, b, x, y, z;
    a.u=args[1]; b.u=args[2];
    x.u=args[3]; y.u=args[4]; z.u=args[5];
    Vector_ceb30 v; v.x=x.f; v.y=y.f; v.z=z.f;
    (object->*(*(void (HUDOverlay_ceb30::**)(const char *, float, float, Vector_ceb30))&this->f_1c))((const char*)args[0], a.f, b.f, v);
}
#if defined(HULK_PTR64)
template class Method4<HUDOverlay, void, const char *, float, float,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xceb10)
#endif


// 0x000ceb80 FUN_000ceb80 (89 B): matches/0x000ceb80.cpp [wrapped: conflict: HUDOverlay; Method3]
// sym: ??0?$Method3@VHUDOverlay@fn_000ceb80@@HPBDPBDM@fn_000ceb80@@QAE@PBDP8HUDOverlay@1@AEH00M@Z@Z
namespace fn_000ceb80 {

// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

// Method3<HUDOverlay, int, const char*, const char*, float>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class HUDOverlay {};
class Function_ceb80 : public ScriptFunctionFields {
  public:
    Function_ceb80(const char*, int);
    virtual void f();
};
template <class T, class U, class V, class W, class X> class Method3 : public Function_ceb80 {
  public:
    Method3(const char*, U (T::*)(V, W, X));
    virtual void f();
    U (T::*id)(V, W, X);
};
template <>
Method3<HUDOverlay, int, const char*, const char*, float>::Method3(const char* x,
                                                                   int (HUDOverlay::*y)(const char*, const char*, float))
    : Function_ceb80(x, 3) {
    id = y;
    retType = FUN_001d04d0(((const char*)&DAT_0048e134));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
} // namespace fn_000ceb80
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000cebe0 Method3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x000cebe0.cpp
// sym: ??_G?$Method3@VHUDOverlay@@HPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<HUDOverlay, int, const char *, const char *, float>::~Method3() {}


// 0x000cec00 Method3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 (43 B): equivalent/0x000cec00.cpp
// sym: ?vfunc_2@?$Method3@VHUDOverlay@@HPBDPBDM@@UAEXPAX00@Z @4f7964c43f8f @w871789d8cadc
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Method3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 @ 0x000cec00
template <> void Method3<HUDOverlay, int, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cec00 * object = (HUDOverlay_cec00 *)__p0; unsigned int * arguments = (unsigned int *)__p1; int * result = (int *)__p2;

    int value = (object->*(*(int (HUDOverlay_cec00::**)(int, const char *, const char *))&this->f_1c))(arguments[0], (const char *)arguments[1], (const char *)arguments[2]);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Method3<HUDOverlay, int, const char *, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcebe0)
#endif


// 0x000cec70 Method0<HUDOverlay,int>::vfunc_0 (30 B): matches/0x000cec70.cpp
// sym: ??_G?$Method0@VHUDOverlay@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<HUDOverlay, int>::~Method0() {}


// 0x000cec90 Method0<HUDOverlay,int>::vfunc_2 (22 B): matches/0x000cec90.cpp
// sym: ?vfunc_2@?$Method0@VHUDOverlay@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<HUDOverlay, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method0<HUDOverlay, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcec70)
#endif


// 0x000cecf0 Method1<HUDOverlay,void,math::Vector>::vfunc_0 (30 B): matches/0x000cecf0.cpp
// sym: ??_G?$Method1@VHUDOverlay@@XVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<HUDOverlay, void,math::Vector>::~Method1() {}


// 0x000ced10 Method1<HUDOverlay,void,math::Vector>::vfunc_2 (39 B): matches/0x000ced10.cpp
// sym: ?vfunc_2@?$Method1@VHUDOverlay@@XVVector@math@@@@UAEXPAX00@Z
template <> void Method1<HUDOverlay, void,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_ced10 * o = (HUDOverlay_ced10 *)__p0; math::Vector_ced10 * v = (math::Vector_ced10 *)__p1;

    (o->*(*(void (HUDOverlay_ced10::**)(math::Vector_ced10))&this->f_1c))(*v);
}
#if defined(HULK_PTR64)
template class Method1<HUDOverlay, void,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcecf0)
#endif


// 0x000ced90 Method2<HUDOverlay,int,int,math::Vector>::vfunc_0 (30 B): matches/0x000ced90.cpp
// sym: ??_G?$Method2@VHUDOverlay@@HHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<HUDOverlay, int, int,math::Vector>::~Method2() {}


// 0x000cedb0 Method2<HUDOverlay,int,int,math::Vector>::vfunc_2 (58 B): matches/0x000cedb0.cpp
// sym: ?vfunc_2@?$Method2@VHUDOverlay@@HHVVector@math@@@@UAEXPAX00@Z
template <> void Method2<HUDOverlay, int, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cedb0 * obj = (HUDOverlay_cedb0 *)__p0; int * args = (int *)__p1; int * out = (int *)__p2;

    int (HUDOverlay_cedb0::*call)(int, math::Vector_cedb0) = (*(int (HUDOverlay_cedb0::**)(int, math::Vector_cedb0))&this->f_1c);
    int a = *args;
    math::Vector_cedb0 v = *(math::Vector_cedb0*)++args;
    int r = (obj->*call)(a, v);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<HUDOverlay, int, int,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xced90)
#endif


// 0x000cee40 Method2<HUDOverlay,void,int,math::Vector>::vfunc_0 (30 B): matches/0x000cee40.cpp
// sym: ??_G?$Method2@VHUDOverlay@@XHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<HUDOverlay, void, int,math::Vector>::~Method2() {}


// 0x000cee60 Method2<HUDOverlay,void,int,math::Vector>::vfunc_2 (48 B): equivalent/0x000cee60.cpp
// sym: ?vfunc_2@?$Method2@VHUDOverlay@@XHVVector@math@@@@UAEXPAX00@Z @db11992ea1ff @w81b0a50beed9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method2<HUDOverlay,void,int,math::Vector>::vfunc_2 @ 0x000cee60
template <> void Method2<HUDOverlay, void, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cee60 * owner = (HUDOverlay_cee60 *)__p0; const Arguments * args = (const Arguments *)__p1; int unused = (int)__p2;

    (owner->*(*(void (HUDOverlay_cee60::**)(int, Vector_cee60))&this->f_1c))(args->index, args->position);
}
#if defined(HULK_PTR64)
template class Method2<HUDOverlay, void, int,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcee40)
#endif


// 0x000ceee0 Method2<HUDOverlay,int,int,const_char_*>::vfunc_0 (30 B): matches/0x000ceee0.cpp
// sym: ??_G?$Method2@VHUDOverlay@@HHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<HUDOverlay, int, int, const char *>::~Method2() {}


// 0x000cef00 Method2<HUDOverlay,int,int,const_char_*>::vfunc_2 (33 B): matches/0x000cef00.cpp
// sym: ?vfunc_2@?$Method2@VHUDOverlay@@HHPBD@@UAEXPAX00@Z
template <> void Method2<HUDOverlay, int, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cef00 * obj = (HUDOverlay_cef00 *)__p0; Args * args = (Args *)__p1; int * out = (int *)__p2;

    int (HUDOverlay_cef00::*fn)(int, int) = (*(int (HUDOverlay_cef00::**)(int, int))&this->f_1c);
    int a = args->a;
    int b = args->b;
    int result = (obj->*fn)(a, b);
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Method2<HUDOverlay, int, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xceee0)
#endif


// 0x000cef80 Method2<HUDOverlay,void,bool,float>::vfunc_0 (30 B): matches/0x000cef80.cpp
// sym: ??_G?$Method2@VHUDOverlay@@X_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<HUDOverlay, void, bool, float>::~Method2() {}


// 0x000cefa0 Method2<HUDOverlay,void,bool,float>::vfunc_2 (24 B): matches/0x000cefa0.cpp
// sym: ?vfunc_2@?$Method2@VHUDOverlay@@X_NM@@UAEXPAX00@Z
template <> void Method2<HUDOverlay, void, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * p = (void *)__p1; void * c = (void *)__p2;

    HUDOverlay_cefa0* h = (HUDOverlay_cefa0*)a;
    (h->*(*(void (HUDOverlay_cefa0::**)(unsigned char, float))&this->f_1c))(*(unsigned char*)p, *(float*)((char*)p + 4));
}
#if defined(HULK_PTR64)
template class Method2<HUDOverlay, void, bool, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcef80)
#endif


// 0x000cf010 Method2<HUDOverlay,void,int,bool>::vfunc_0 (30 B): matches/0x000cf010.cpp
// sym: ??_G?$Method2@VHUDOverlay@@XH_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<HUDOverlay, void, int, bool>::~Method2() {}


// 0x000cf030 Method2<HUDOverlay,void,int,bool>::vfunc_2 (25 B): matches/0x000cf030.cpp
// sym: ?vfunc_2@?$Method2@VHUDOverlay@@XH_N@@UAEXPAX00@Z
template <> void Method2<HUDOverlay, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cf030 * h = (HUDOverlay_cf030 *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    struct Args {
        int i;
        bool flag;
    };
    Args* p = (Args*)b;
    (h->*(*(void (HUDOverlay_cf030::**)(int, bool))&this->f_1c))(p->i, p->flag);
}
#if defined(HULK_PTR64)
template class Method2<HUDOverlay, void, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf010)
#endif

namespace fn_f3fdf6d3 {

// 0x000cf050 FUN_000cf050 (102 B): matches/0x000cf050.cpp
// sym: ??0Method4_cf050@fn_f3fdf6d3@@QAE@HH@Z
Method4_cf050::Method4_cf050(hulk_intptr a, hulk_intptr b) {
    Init_001d0480(a, 4);
    v = ((hulk_intptr)DAT_0040a590);
    n = b;
    m18 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x10) = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x11) = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x12) = GetFlag_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    *((char*)this + 0x13) = GetFlag_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}

} // namespace fn_f3fdf6d3

// 0x000cf0c0 Method4<HUDOverlay,int,int,int,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x000cf0c0.cpp
// sym: ??_G?$Method4@VHUDOverlay@@HHHVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<HUDOverlay, int, int, int,math::Vector,math::Vector>::~Method4() {}


// 0x000cf0e0 Method4<HUDOverlay,int,int,int,math::Vector,math::Vector>::vfunc_2 (115 B): matches/0x000cf0e0.cpp
// sym: ?vfunc_2@?$Method4@VHUDOverlay@@HHHVVector@math@@V23@@@UAEXPAX00@Z
template <> void Method4<HUDOverlay, int, int, int,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cf0e0 * o = (HUDOverlay_cf0e0 *)__p0; char * args = (char *)__p1; int * out = (int *)__p2;

    Fn_cf0e0 fn = (*(Fn_cf0e0 *)&this->f_1c);
    char* p = args;
    int a1 = Pop<int>(p);
    int a2 = Pop<int>(p);
    math::Vector_cf0e0 a3 = Pop<math::Vector_cf0e0>(p);
    math::Vector_cf0e0 a4 = Pop<math::Vector_cf0e0>(p);
    int r = (o->*fn)(a1, a2, a3, a4);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method4<HUDOverlay, int, int, int,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf0c0)
#endif

namespace fn_f3fdf6d3 {

// 0x000cf160 FUN_000cf160 (89 B): matches/0x000cf160.cpp
// sym: ??0Method3_cf160@fn_f3fdf6d3@@QAE@HH@Z
Method3_cf160::Method3_cf160(hulk_intptr a, hulk_intptr c) : Function_cf160(a, 3) {
    m1c = c;
    b18 = Lookup_001d04d0(((char*)&DAT_0048e100));
    b10 = Lookup_001d04d0(((char*)&DAT_0048e134));
    b11 = Lookup_001d04d0(((char*)&DAT_0048e134));
    b12 = Lookup_001d04d0(hulk_at_0048e10c);
}

} // namespace fn_f3fdf6d3

// 0x000cf1c0 Method3<HUDOverlay,void,int,int,math::Vector>::vfunc_0 (30 B): matches/0x000cf1c0.cpp
// sym: ??_G?$Method3@VHUDOverlay@@XHHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<HUDOverlay, void, int, int,math::Vector>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<HUDOverlay, void, int, int,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf1c0)
#endif


// 0x000cf1e0 Method3<HUDOverlay,void,int,int,math::Vector>::vfunc_2 (57 B): matches/0x000cf1e0.cpp [wrapped: conflict: Arguments; Function; HUDOverlay; Method3]
// sym: ?vfunc_2@Method3@fn_000cf1e0@@UAEXPAUHUDOverlay@2@PAUArguments@2@PAX@Z
namespace fn_000cf1e0 {
namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
struct HUDOverlay {
    void FUN_00000000(int, int, math::Vector);
};
struct Arguments {
    int a, b;
    math::Vector v;
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(HUDOverlay*, Arguments*, void*);
};
struct Method3 : Function {
    char reserved[24];
    void (HUDOverlay::*callback)(int, int, math::Vector);
    virtual void vfunc_2(HUDOverlay*, Arguments*, void*);
};
void Method3::vfunc_2(HUDOverlay* object, Arguments* args, void* unused) {
    int* p = &args->a;
    int a = *p++;
    int b = *p++;
    math::Vector v = *(math::Vector*)p;
    (object->*callback)(a, b, v);
}
} // namespace fn_000cf1e0


// 0x000cf270 Method2<HUDOverlay,void,int,int>::vfunc_0 (30 B): matches/0x000cf270.cpp
// sym: ??_G?$Method2@VHUDOverlay@@XHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<HUDOverlay, void, int, int>::~Method2() {}


// 0x000cf290 Method2<HUDOverlay,void,int,int>::vfunc_2 (23 B): matches/0x000cf290.cpp
// sym: ?vfunc_2@?$Method2@VHUDOverlay@@XHH@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<HUDOverlay, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_cf290* m = (CFEManager_cf290*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_cf290::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<HUDOverlay, void, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf270)
#endif

namespace fn_f3fdf6d3 {

// 0x000cf2b0 FUN_000cf2b0 (115 B): matches/0x000cf2b0.cpp
// sym: ?Init@Method5_cf2b0@fn_f3fdf6d3@@QAEPAV12@PBDP8Owner_cf2b0@2@AEHH0HHH@Z@Z
// FUN_000cf2b0 @ 0x000cf2b0
Method5_cf2b0* Method5_cf2b0::Init(const char* arg, Fn_cf2b0 value) {
    FUN_001d0480(arg, 5);
    vptr = (void*)DAT_0040a5c0;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    return this;
}

} // namespace fn_f3fdf6d3

// 0x000cf330 Method5<HUDOverlay,int,int,const_char_*,math::Vector,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x000cf330.cpp
// sym: ??_G?$Method5@VHUDOverlay@@HHPBDVVector@math@@V23@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<HUDOverlay, int, int, const char *,math::Vector,math::Vector,math::Vector>::~Method5() {}


// 0x000cf350 Method5<HUDOverlay,int,int,const_char_*,math::Vector,math::Vector,math::Vector>::vfunc_2 (166 B): equivalent/0x000cf350.cpp
// sym: ?vfunc_2@?$Method5@VHUDOverlay@@HHPBDVVector@math@@V23@V23@@@UAEXPAX00@Z @7e2cce862d80 @wd72534a0dbce
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method5<HUDOverlay,int,int,const_char_*,math::Vector,math::Vector,math::Vector>::vfunc_2 @ 0x000cf350
template <> void Method5<HUDOverlay, int, int, const char *,math::Vector,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cf350 * obj = (HUDOverlay_cf350 *)__p0; Args_cf350 * args = (Args_cf350 *)__p1; int * out = (int *)__p2;

    ActFn_cf350 fn = (*(ActFn_cf350 *)&this->f_1c);
    int r = (obj->*fn)(args->a1, args->a2, args->v3, args->v4, args->v5);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method5<HUDOverlay, int, int, const char *,math::Vector,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf330)
#endif


// 0x000cf440 Method1<HUDOverlay,void,bool>::vfunc_0 (30 B): matches/0x000cf440.cpp
// sym: ??_G?$Method1@VHUDOverlay@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<HUDOverlay, void, bool>::~Method1() {}


// 0x000cf460 Method1<HUDOverlay,void,bool>::vfunc_2 (21 B): matches/0x000cf460.cpp
// sym: ?vfunc_2@?$Method1@VHUDOverlay@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<HUDOverlay, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_cf460 * obj = (CActorManager_cf460 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_cf460 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<HUDOverlay, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf440)
#endif


// 0x000cf490 content::LoadInventory::DynamicCaster<pure3d::Locator>::vfunc_0 (30 B): matches/0x000cf490.cpp
// sym: ?vfunc_0@?$DynamicCaster@VLocator@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::Locator>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    __RTDynamicCast((void*)((hulk_uintptr)p), 0, (void*)(&type_refcount), (void*)(&type_animation), 0);
}

namespace fn_f3fdf6d3 {

// 0x000cf4b0 FUN_000cf4b0 (644 B): equivalent/0x000cf4b0.cpp
// sym: ?FUN_000cf4b0@Ctl_cf4b0@fn_f3fdf6d3@@QAEXM@Z @cbb983266a71 @wfe6c034b5f33
// STATUS: equivalent (tools/equiv.py level 3: 20035 inputs, branch coverage 36/36)
// FUN_000cf4b0 @ 0x000cf4b0
// FUN_000cf4b0 @ 0x000cf4b0
// equiv-conv: FUN_000cb7d0 ecx edx stack
void Ctl_cf4b0::FUN_000cf4b0(float dt)
{
    if (!(flags & 2))
        return;
    if (!p250)
        return;

    float fx = 0.0f;
    float fy = 0.0f;
    for (int i = 0; i < 8; i++) {
        if (slots[i].name[0] == 0)
            continue;
        Table_cf4b0 *tbl = owner->table;
        float *e = tbl->FUN_00024280(FUN_002672f0(slots[i].name, 0, 0));
        if (e) {
            fx += e[0x1b0c / 4];
            fy += e[0x1b10 / 4];
        } else {
            Node *n = owner->lookup->FUN_001def30(slots[i].name);
            if (n) {
                fx += (float)n->FUN_001d62d0();
                fy += (float)n->track->FUN_001d60c0();
            }
        }
    }

    fx = fx - 1.0f;
    f488 = fy;
    f480 = fx;
    float d = fx - f484;
    if (d < 0) d = -d;
    if (!(d <= 1e-05f)) {
        float d2 = fx - f478;
        if (d2 < 0) d2 = -d2;
        if (!(d2 <= 1e-05f)) {
            f490 = 0.0f;
            float t = fx - f484;
            if (t < 0) t = -t;
            float v = 0.125f * t + 600.0f;
            float r = (t > v) ? v : 4.0f;
            if (!(t < 4.0f) && t <= v)
                r = t;
            f48c = r;
        }
        if (!(f490 <= 0.5f))
            FUN_000cb7d0(&f484, &f480, dt * f48c);
        int *p = &i494;
        if ((*(char*)&DAT_004dde79) == 0) {
            *p += DAT_0049fcb0;
            if (*p > 0xff) {
                *p = 0xff;
                (*(char*)&DAT_004dde79) = 1;
            }
        } else {
            *p -= DAT_0049fcb0;
            if (*p < 0) {
                *p = 0;
                (*(char*)&DAT_004dde79) = 0;
            }
        }
    } else {
        int *p = &i494;
        *p += DAT_0049fcb0;
        if (*p > 0xff)
            *p = 0xff;
    }
    f490 = dt + f490;
    f478 = f480;
    f47c = f484;
}


// 0x000cf740 FUN_000cf740 (144 B): matches/0x000cf740.cpp
// sym: ?FUN_000cf740@Effect_cf740@fn_f3fdf6d3@@QAEXXZ
// FUN_000cf740 @ 0x000cf740
void Effect_cf740::FUN_000cf740()
{
    FUN_000ce280();
    if (sprite != 0) {
        (*(PassHolder_cf740**)&DAT_0052c2ac)->pass->v15(0);
        (*(PassHolder_cf740**)&DAT_0052c2ac)->FUN_00293d00(((Vec3_cf740*)&DAT_004ddec8));
        Vec3_cf740 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        (*(PassHolder_cf740**)&DAT_0052c2ac)->FUN_00293d00(&zero);
        int k = DAT_0049fd0c;
        (*(PassHolder_cf740**)&DAT_0052c2ac)->FUN_00293da0(k, k, k);
        sprite->v8(0, 0);
        (*(PassHolder_cf740**)&DAT_0052c2ac)->pass->v16(0);
    }
}

} // namespace fn_f3fdf6d3

// 0x000cf810 Closure0<HUDOverlay,void>::vfunc_0 (30 B): matches/0x000cf810.cpp
// sym: ??_G?$Method1@VHUDOverlay@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<HUDOverlay, void>::~Closure0() {}


// 0x000cf830 Closure0<HUDOverlay,void>::vfunc_2 (11 B): matches/0x000cf830.cpp
// sym: ?vfunc_2@?$Closure0@VHUDOverlay@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<HUDOverlay, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_cf830 * *)&this->f_20)->*(*(void (CActorManager_cf830::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<HUDOverlay, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf810)
#endif


// 0x000cf840 FUN_000cf840 (76 B): matches/0x000cf840.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_000cf840@@QAE@PBDPAVOwner_cf840@1@P821@AEX0@Z@Z
namespace fn_000cf840 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

// Closure1<Owner, void, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_cf840 {};
typedef void (Owner_cf840::*Fn_cf840)(const char*);
class Base : public ScriptFunctionFields {
  public:
    virtual void invoke();
    Base(const char*, int);
};
class Closure1_cf840 : public Base {
  public:
    virtual void invoke();
    Fn_cf840 object;
    Closure1_cf840(const char*, Owner_cf840*, Fn_cf840);
};
class Closure1 : public Closure1_cf840 {
  public:
    virtual void invoke();
    Owner_cf840* other;
    Closure1(const char*, Owner_cf840*, Fn_cf840);
};
Closure1::Closure1(const char* s, Owner_cf840* obj, Fn_cf840 p) : Closure1_cf840(s, obj, p) {
    other = obj;
}
Closure1_cf840::Closure1_cf840(const char* s, Owner_cf840* obj, Fn_cf840 p) : Base(s, 1) {
    object = p;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
} // namespace fn_000cf840
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000cf890 Closure1<HUDOverlay,void,const_char_*>::vfunc_0 (30 B): matches/0x000cf890.cpp
// sym: ??_G?$Method1@VHUDOverlay@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<HUDOverlay, void, const char *>::~Closure1() {}


// 0x000cf8b0 Closure1<HUDOverlay,void,const_char_*>::vfunc_2 (18 B): matches/0x000cf8b0.cpp
// sym: ?vfunc_2@?$Closure1@VHUDOverlay@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<HUDOverlay, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_cf8b0 * *)&this->f_20)->*(*(void (CActorManager_cf8b0::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<HUDOverlay, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf890)
#endif


// 0x000cf8d0 FUN_000cf8d0 (76 B): matches/0x000cf8d0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000cf8d0@@QAE@HHH@Z
namespace fn_000cf8d0 {
// data: str1 = DAT_0048e100, str2 = DAT_0048e134

class Function_cf8d0 {
  public:
    Function_cf8d0(int, int);
    virtual void f();
    char pad[12];
};
char __cdecl query_001d04d0(const char*);
class Method1 : public Function_cf8d0 {
  public:
    Method1(int a, int b) : Function_cf8d0(a, 1) {
        v = b;
        c = query_001d04d0(((const char*)&DAT_0048e100));
        d = query_001d04d0(((const char*)&DAT_0048e134));
    }
    virtual void f();
    char d;
    char x[7];
    char c;
    char y[3];
    int v;
};
class Closure1 : public Method1 {
  public:
    Closure1(int a, int b, int z);
    virtual void f();
    int w;
};
Closure1::Closure1(int a, int b, int z) : Method1(a, z) {
    w = b;
}
} // namespace fn_000cf8d0


// 0x000cf920 Closure1<HUDOverlay,void,int>::vfunc_0 (30 B): matches/0x000cf920.cpp
// sym: ??_G?$Method0@VHUDOverlay@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<HUDOverlay, void, int>::~Closure1() {}


// 0x000cf940 Closure1<HUDOverlay,void,int>::vfunc_2 (18 B): matches/0x000cf940.cpp
// sym: ?vfunc_2@?$Closure1@VHUDOverlay@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<HUDOverlay, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_cf940 * *)&this->f_20)->*(*(void (CActorManager_cf940::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<HUDOverlay, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf920)
#endif


// 0x000cf960 FUN_000cf960 (76 B): matches/0x000cf960.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000cf960@@QAE@PBDPAVOwner_cf960@1@P821@AEXM@Z@Z
namespace fn_000cf960 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

// Closure1<Owner, void, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_cf960 {};
typedef void (Owner_cf960::*Fn_cf960)(float);
class Function_cf960 : public ScriptFunctionFields {
  public:
    virtual void Invoke(float);
    Function_cf960(const char*, int);
};
class Method1 : public Function_cf960 {
  public:
    virtual void Invoke(float);
    Fn_cf960 obj;
    Method1(const char* x, Fn_cf960 y) : Function_cf960(x, 1) {
        obj = y;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    Owner_cf960* extra;
    Closure1(const char*, Owner_cf960*, Fn_cf960);
};
Closure1::Closure1(const char* x, Owner_cf960* y, Fn_cf960 z) : Method1(x, z) {
    extra = y;
}
} // namespace fn_000cf960
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000cf9b0 Closure1<HUDOverlay,void,float>::vfunc_0 (30 B): matches/0x000cf9b0.cpp
// sym: ??_G?$Method1@VHUDOverlay@@XVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<HUDOverlay, void, float>::~Closure1() {}


// 0x000cf9d0 Closure1<HUDOverlay,void,float>::vfunc_2 (18 B): matches/0x000cf9d0.cpp
// sym: ?vfunc_2@?$Closure1@VHUDOverlay@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<HUDOverlay, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_cf9d0 * *)&this->f_20)->*(*(void (CActorManager_cf9d0::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<HUDOverlay, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcf9b0)
#endif


// 0x000cfa20 Closure4<HUDOverlay,void,const_char_*,float,float,math::Vector>::vfunc_0 (30 B): matches/0x000cfa20.cpp
// sym: ??_G?$Method2@VHUDOverlay@@XHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<HUDOverlay, void, const char *, float, float,math::Vector>::~Closure4() {}


// 0x000cfa40 Closure4<HUDOverlay,void,const_char_*,float,float,math::Vector>::vfunc_2 (79 B): matches/0x000cfa40.cpp
// sym: ?vfunc_2@?$Closure4@VHUDOverlay@@XPBDMMVVector@math@@@@UAEXPAX00@Z
template <> void Closure4<HUDOverlay, void, const char *, float, float,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * args = (void *)__p1; void * extra = (void *)__p2;

    char* p = (char*)args;
    const char* s = *(const char**)p;
    p += 4;
    float a = *(float*)p;
    p += 4;
    float b = *(float*)p;
    p += 4;
    math::Vector_cfa40 v = *(math::Vector_cfa40*)p;
    ((*(HUDOverlay_cfa40 * *)&this->f_20)->*(*(void (HUDOverlay_cfa40::**)(const char *, float, float, math::Vector_cfa40))&this->f_1c))(s, a, b, v);
}
#if defined(HULK_PTR64)
template class Closure4<HUDOverlay, void, const char *, float, float,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfa20)
#endif


// 0x000cfac0 Closure3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x000cfac0.cpp
// sym: ??_G?$Method2@VHUDOverlay@@HHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<HUDOverlay, int, const char *, const char *, float>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<HUDOverlay, int, const char *, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfac0)
#endif


// 0x000cfb50 Closure0<HUDOverlay,int>::vfunc_0 (30 B): matches/0x000cfb50.cpp
// sym: ??_G?$Method2@VHUDOverlay@@X_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<HUDOverlay, int>::~Closure0() {}


// 0x000cfb70 Closure0<HUDOverlay,int>::vfunc_2 (23 B): matches/0x000cfb70.cpp
// sym: ?vfunc_2@?$Closure0@VHUDOverlay@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<HUDOverlay, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_cfb70* obj = (*(CActorManager_cfb70 * *)&this->f_20);
    int (CActorManager_cfb70::*fn)() = (*(int (CActorManager_cfb70::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Closure0<HUDOverlay, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfb50)
#endif


// 0x000cfb90 FUN_000cfb90 (76 B): matches/0x000cfb90.cpp [wrapped: conflict: Closure1; DAT_0048e10c; Method1]
// sym: ??0Closure1@fn_000cfb90@@QAE@PBDPAVOwner_cfb90@1@P821@AEXH@Z@Z
namespace fn_000cfb90 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern const char DAT_0048e10c[];
// Closure1<Owner, void, A1>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_cfb90 {};
typedef void (Owner_cfb90::*Fn_cfb90)(int);
class Function_cfb90 : public ScriptFunctionFields {
  public:
    Function_cfb90(const char*, int);
    virtual void f();
};
class Method1 : public Function_cfb90 {
  public:
    Method1(const char* a, Fn_cfb90 c) : Function_cfb90(a, 1) {
        p = c;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(DAT_0048e10c);
    }
    virtual void g();
    Fn_cfb90 p;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char*, Owner_cfb90*, Fn_cfb90);
    virtual void g();
    Owner_cfb90* q;
};
Closure1::Closure1(const char* a, Owner_cfb90* b, Fn_cfb90 c) : Method1(a, c) {
    q = b;
}
} // namespace fn_000cfb90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000cfbe0 Closure1<HUDOverlay,void,math::Vector>::vfunc_0 (30 B): matches/0x000cfbe0.cpp
// sym: ??_G?$Method2@VHUDOverlay@@XH_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<HUDOverlay, void,math::Vector>::~Closure1() {}


// 0x000cfc00 Closure1<HUDOverlay,void,math::Vector>::vfunc_2 (38 B): matches/0x000cfc00.cpp
// sym: ?vfunc_2@?$Closure1@VHUDOverlay@@XVVector@math@@@@UAEXPAX00@Z
template <> void Closure1<HUDOverlay, void,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { math::Vector_cfc00 * v = (math::Vector_cfc00 *)__p1;

    ((*(HUDOverlay_cfc00 * *)&this->f_20)->*(*(void (HUDOverlay_cfc00::**)(math::Vector_cfc00))&this->f_1c))(*v);
}
#if defined(HULK_PTR64)
template class Closure1<HUDOverlay, void,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfbe0)
#endif


// 0x000cfc30 FUN_000cfc30 (89 B): matches/0x000cfc30.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_000cfc30@@QAE@HHH@Z
namespace fn_000cfc30 {
// data: gA_cfc30 = DAT_0048e134

extern char gB_cfc30[];
extern "C++" __declspec(nothrow) char Get_001d04d0(char const*);
class Function_cfc30 {
  public:
    Function_cfc30(int, int);
    virtual void f();
    char pad[12];
};
class Method2 : public Function_cfc30 {
  public:
    Method2(int a, int c);
    virtual void f();
    char x;
    char y;
    char pad2[6];
    char z;
    char pad3[3];
    int value;
};
class Closure2 : public Method2 {
  public:
    Closure2(int a, int b, int c);
    virtual void f();
    int other;
};
inline Method2::Method2(int a, int c) : Function_cfc30(a, 2) {
    value = c;
    z = Get_001d04d0(((char*)&DAT_0048e134));
    x = Get_001d04d0(((char*)&DAT_0048e134));
    y = Get_001d04d0(gB_cfc30);
}
Closure2::Closure2(int a, int b, int c) : Method2(a, c) {
    other = b;
}
} // namespace fn_000cfc30


// 0x000cfc90 Closure2<HUDOverlay,int,int,math::Vector>::vfunc_0 (30 B): matches/0x000cfc90.cpp
// sym: ??_G?$Method4@VHUDOverlay@@HHHVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<HUDOverlay, int, int,math::Vector>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<HUDOverlay, int, int,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfc90)
#endif


// 0x000cfcb0 Closure2<HUDOverlay,int,int,math::Vector>::vfunc_2 (61 B): equivalent/0x000cfcb0.cpp [wrapped: conflict: Args; Closure2; HUDOverlay]
// sym: ?vfunc_2@Closure2@fn_000cfcb0@@UAEXHPAUArgs@2@PAH@Z @69c5af852677 @w0dfc1d6ccf29
namespace fn_000cfcb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<HUDOverlay,int,int,math::Vector>::vfunc_2 @ 0x000cfcb0
namespace math { struct Vector { float x,y,z; }; }
struct HUDOverlay { int FUN_00000000(int, math::Vector); };
struct Args { int number; math::Vector vector; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int ignored, Args* arguments, int* result);
    char padding[0x18];
    int (HUDOverlay::*method)(int, math::Vector);
    HUDOverlay* object;
};
void Closure2::vfunc_2(int ignored, Args* arguments, int* result) {
    int value = (object->*method)(arguments->number, arguments->vector);
    if (result) *result = value;
}
} // namespace fn_000cfcb0


// 0x000cfcf0 FUN_000cfcf0 (89 B): matches/0x000cfcf0.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_000cfcf0@@QAE@PBDPAVOwner_cfcf0@1@P821@AEXHH@Z@Z
namespace fn_000cfcf0 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

// Closure2<Owner, void, int, A2>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_cfcf0 {};
typedef void (Owner_cfcf0::*Fn_cfcf0)(int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern char DAT_0048e10c[];
class Function_cfcf0 : public CtorV_001d0480 {
  public:
    Function_cfcf0(const char* x) : CtorV_001d0480(x, 2) { }
};
class Method2 : public Function_cfcf0 {
  public:
    virtual void f();
    Fn_cfcf0 d;
    Method2(const char* x, Fn_cfcf0 y) : Function_cfcf0(x) {
        d = y;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
        argTypes[1] = FUN_001d04d0(DAT_0048e10c);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void f();
    Owner_cfcf0* e;
    Closure2(const char*, Owner_cfcf0*, Fn_cfcf0);
};
Closure2::Closure2(const char* x, Owner_cfcf0* y, Fn_cfcf0 z) : Method2(x, z) {
    e = y;
}
} // namespace fn_000cfcf0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000cfd50 Closure2<HUDOverlay,void,int,math::Vector>::vfunc_0 (30 B): matches/0x000cfd50.cpp
// sym: ??_G?$Method3@VHUDOverlay@@XHHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<HUDOverlay, void, int,math::Vector>::~Closure2() {}


// 0x000cfd70 Closure2<HUDOverlay,void,int,math::Vector>::vfunc_2 (47 B): equivalent/0x000cfd70.cpp
// sym: ?vfunc_2@?$Closure2@VHUDOverlay@@XHVVector@math@@@@UAEXPAX00@Z @24b1dd12cec5 @wc560a9a5bfca
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure2<HUDOverlay,void,int,math::Vector>::vfunc_2 @ 0x000cfd70
template <> void Closure2<HUDOverlay, void, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const void * args = (const void *)__p1;

    const int* words = (const int*)args;
    Vector_cfd70 vector;
    vector.x = *(const float*)(words + 1);
    vector.y = *(const float*)(words + 2);
    vector.z = *(const float*)(words + 3);
    ((*(HUDOverlay_cfd70 * *)&this->f_20)->*(*(void (HUDOverlay_cfd70::**)(int, Vector_cfd70))&this->f_1c))(words[0], vector);
}
#if defined(HULK_PTR64)
template class Closure2<HUDOverlay, void, int,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfd50)
#endif

namespace fn_f3fdf6d3 {

// 0x000cfda0 FUN_000cfda0 (89 B): matches/0x000cfda0.cpp
// sym: ??0Closure2_cfda0@fn_f3fdf6d3@@QAE@HHH@Z
// data: gA_cfda0 = DAT_0048e134
Closure2_cfda0::Closure2_cfda0(int x, int y, int z) : Method2_cfda0(x, z) {
    n = y;
}

} // namespace fn_f3fdf6d3

// 0x000cfe00 Closure2<HUDOverlay,int,int,const_char_*>::vfunc_0 (30 B): matches/0x000cfe00.cpp
// sym: ??_G?$Method2@VHUDOverlay@@XHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<HUDOverlay, int, int, const char *>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<HUDOverlay, int, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfe00)
#endif


// 0x000cfe50 FUN_000cfe50 (89 B): matches/0x000cfe50.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_000cfe50@@QAE@PBDPAVOwner_cfe50@1@P821@AEX_NM@Z@Z
namespace fn_000cfe50 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

// data: a_cfe50 = DAT_0048e100
// Closure2<Owner, void, bool, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_cfe50 {};
typedef void (Owner_cfe50::*Fn_cfe50)(bool, float);
class Function_cfe50 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_cfe50(const char*, int);
};
class Method2 : public Function_cfe50 {
  public:
    virtual bool Fng_001d04c0(int, int);
    Fn_cfe50 obj;
    Method2(const char* p, Fn_cfe50 q) : Function_cfe50(p, 2) {
        obj = q;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(&DAT_0048e0e4);
        argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void Fnh_000cfed0(void*, void*, void*);
    Owner_cfe50* extra;
    Closure2(const char* p, Owner_cfe50* q, Fn_cfe50 r);
};
Closure2::Closure2(const char* p, Owner_cfe50* q, Fn_cfe50 r) : Method2(p, r) {
    extra = q;
}
} // namespace fn_000cfe50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000cfeb0 Closure2<HUDOverlay,void,bool,float>::vfunc_0 (30 B): matches/0x000cfeb0.cpp
// sym: ??_G?$Method1@VHUDOverlay@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<HUDOverlay, void, bool, float>::~Closure2() {}


// 0x000cfed0 Closure2<HUDOverlay,void,bool,float>::vfunc_2 (23 B): matches/0x000cfed0.cpp
// sym: ?vfunc_2@?$Closure2@VHUDOverlay@@X_NM@@UAEXPAX00@Z
template <> void Closure2<HUDOverlay, void, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * args = (unsigned char *)__p1;

    ((*(HUDOverlay_cfed0 * *)&this->f_20)->*(*(void (HUDOverlay_cfed0::**)(unsigned char, float))&this->f_1c))(args[0], *(float*)(args + 4));
}
#if defined(HULK_PTR64)
template class Closure2<HUDOverlay, void, bool, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xcfeb0)
#endif


// 0x000cfef0 FUN_000cfef0 (89 B): matches/0x000cfef0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure2@fn_000cfef0@@QAE@PBDPAVHUDOverlay@1@P821@AEXH_N@Z@Z
namespace fn_000cfef0 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

// data: a_cfef0 = DAT_0048e100
// Closure2<HUDOverlay, void, int, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class HUDOverlay {};
typedef void (HUDOverlay::*Fn_cfef0)(int, bool);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base_cfef0 : public CtorV_001d0480 {
  public:
    Base_cfef0(const char* n) : CtorV_001d0480(n, 2) { }
};
class Closure2_cfef0 : public Base_cfef0 {
  public:
    virtual bool Fnf_001d04c0(int, int);
    Fn_cfef0 arg;
    Closure2_cfef0(const char*, Fn_cfef0);
};
Closure2_cfef0::Closure2_cfef0(const char* n, Fn_cfef0 v) : Base_cfef0(n) {
    arg = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
class Closure2 : public Closure2_cfef0 {
  public:
    HUDOverlay* val;
    Closure2(const char*, HUDOverlay*, Fn_cfef0);
};
Closure2::Closure2(const char* n, HUDOverlay* v, Fn_cfef0 w) : Closure2_cfef0(n, w) {
    val = v;
}
} // namespace fn_000cfef0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000cff70 Closure2<HUDOverlay,void,int,bool>::vfunc_2 (24 B): matches/0x000cff70.cpp
// sym: ?vfunc_2@?$Closure2@VHUDOverlay@@XH_N@@UAEXPAX00@Z
// Same code shape as 0x0002ec60 (propagated; names are from that function)
template <> void Closure2<HUDOverlay, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_cff70 * p = (Arg_cff70 *)__p1;

    ((*(Actor_cff70 * *)&this->f_20)->*(*(void (Actor_cff70::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}


// 0x000cffe0 Closure4<HUDOverlay,int,int,int,math::Vector,math::Vector>::vfunc_2 (12 B): matches/0x000cffe0.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_000cffe0@@UAEXHHH@Z
namespace fn_000cffe0 {
// Same code shape as 0x0002ff10 (propagated; names are from that function)
class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, int, int);
    char pad[0x18];
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int, int, int);
};
void Closure2::vfunc_2(int x, int a2, int a3) {
    Method2::vfunc_2(val, a2, a3);
}
} // namespace fn_000cffe0


// 0x000d0040 Closure3<HUDOverlay,void,int,int,math::Vector>::vfunc_2 (56 B): equivalent/0x000d0040.cpp
// sym: ?vfunc_2@?$Closure3@VHUDOverlay@@XHHVVector@math@@@@UAEXPAX00@Z @8edf7df33cb8 @wcf864df72b4f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<HUDOverlay,void,int,int,math::Vector>::vfunc_2 @ 0x000d0040
template <> void Closure3<HUDOverlay, void, int, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const int * args = (const int *)__p1; void * unused2 = (void *)__p2;

    math::Vector_d0040 v;
    const math::Vector_d0040* source = (const math::Vector_d0040*)(args+2);
    v = *source;
    ((*(HUDOverlay_d0040 * *)&this->f_20)->*(*(void (HUDOverlay_d0040::**)(int, int, math::Vector_d0040))&this->f_1c))(args[0],args[1],v);
}


// 0x000d0080 FUN_000d0080 (89 B): matches/0x000d0080.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure2@fn_000d0080@@QAE@PBDPAVOwner_d0080@1@P821@AEXHH@Z@Z
namespace fn_000d0080 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

// Closure2<Owner, void, int, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_d0080 {};
typedef void (Owner_d0080::*Fn_d0080)(int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base_d0080 : public CtorV_001d0480 {
  public:
    Base_d0080(const char* p) : CtorV_001d0480(p, 2) { }
};
class Closure2_d0080 : public Base_d0080 {
  public:
    virtual void f();
    Fn_d0080 m1;
    Closure2_d0080(const char*, Owner_d0080*, Fn_d0080);
};
Closure2_d0080::Closure2_d0080(const char* p, Owner_d0080* a, Fn_d0080 b) : Base_d0080(p) {
    m1 = b;
    retType = FUN_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e134));
    argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e134));
}
class Closure2 : public Closure2_d0080 {
  public:
    virtual void f();
    Owner_d0080* m2;
    Closure2(const char*, Owner_d0080*, Fn_d0080);
};
Closure2::Closure2(const char* p, Owner_d0080* a, Fn_d0080 b) : Closure2_d0080(p, a, b) {
    m2 = a;
}
} // namespace fn_000d0080
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d0100 Closure2<HUDOverlay,void,int,int>::vfunc_2 (22 B): matches/0x000d0100.cpp
// sym: ?vfunc_2@?$Closure2@VHUDOverlay@@XHH@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<HUDOverlay, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_d0100 * p = (Pair_d0100 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_d0100 * *)&this->f_20)->*(*(void (CActorManager_d0100::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x000d0170 Closure5<HUDOverlay,int,int,const_char_*,math::Vector,math::Vector,math::Vector>::vfunc_2 (12 B): matches/0x000d0170.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_000d0170@@UAEXHHH@Z
namespace fn_000d0170 {
// Same code shape as 0x0002ff10 (propagated; names are from that function)
class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, int, int);
    char pad[0x18];
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int, int, int);
};
void Closure2::vfunc_2(int x, int a2, int a3) {
    Method2::vfunc_2(val, a2, a3);
}
} // namespace fn_000d0170


// 0x000d0180 FUN_000d0180 (76 B): matches/0x000d0180.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000d0180@@QAE@PAX00@Z
namespace fn_000d0180 {
class Function_d0180 {
  public:
    Function_d0180(void*, int);
    virtual void run();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* p;
};
extern "C++" __declspec(nothrow) unsigned char fn_001d04d0(void*);
extern void* hulk_at_0048e100;
extern void* hulk_at_0048e0e4;
class Method1 : public Function_d0180 {
  public:
    Method1(void* x, void* y) : Function_d0180(x, 1) {
        p = y;
        b = fn_001d04d0(&hulk_at_0048e100);
        a = fn_001d04d0(&hulk_at_0048e0e4);
    }
    virtual void run();
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void run();
    void* q;
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    q = y;
}
} // namespace fn_000d0180


// 0x000d01f0 Closure1<HUDOverlay,void,bool>::vfunc_2 (20 B): matches/0x000d01f0.cpp
// sym: ?vfunc_2@?$Closure1@VHUDOverlay@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<HUDOverlay, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_d01f0 * *)&this->f_20)->*(*(void (Actor_d01f0::**)(unsigned char))&this->f_1c))(*arg);
}


// 0x000d0240 HUDOverlay::vfunc_3 (935 B): equivalent/0x000d0240.cpp [wrapped: conflict: HUDOverlay; Overlay]
// sym: ?vfunc_3@HUDOverlay@fn_000d0240@@UAEXM@Z @ea55fcda357c @wb42f3ab46563
namespace fn_000d0240 {
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 30/30)
// HUDOverlay::vfunc_3 @ 0x000d0240
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

class Ref_d0240 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x1b0c - 4];
    float f1b0c;
    char pad1b10[4];
    float f1b14;
    char pad1b18[0x20b0 - 0x1b18];
    int f20b0;
    float FUN_00036090();
};

struct Target_d0240 {
    char pad00[0x124];
    Ref_d0240* ref;
};

struct Holder_d0240 {
    char pad00[0x20];
    Target_d0240* target;
};

struct Parent_d0240 {
    char pad00[0x20];
    Target_d0240* target;
};

struct Clock_d0240 {
    int FUN_00090110();
};

struct Timer {
    Clock_d0240* FUN_00086370();
};

struct World {
    char pad00[0x54];
    Timer* timer;
};

struct Updater_d0240 {
    void FUN_000c9810(float dt);
};



void FUN_00025960(Ref_d0240** slot, Ref_d0240* value);
void FUN_000a0d40(Ref_d0240** slot);
float FUN_000186b0(float* v, float* lo, float* hi);

struct Frame_d0240 {
    float hi;
    float lo;
    float v;
    float w;
    int gap10;
    int gap14;
    float t20;
    float t24;
    int gap20;
    float t2c;
    float t30;
    int gap2c;
};

class Overlay {
public:
    virtual void vfunc_0();
};

class HUDOverlay : public Overlay {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(float dt);

    char pad04[8];
    Parent_d0240* parent;
    char pad10[4];
    Ref_d0240* ref;
    Ref_d0240* ref2;
    char pad1c[0x50 - 0x1c];
    char hidden;
    char pad51[0x88 - 0x51];
    Updater_d0240* updater;
    char pad8c[0xa8 - 0x8c];
    float a8;
    int lastValue;
    float b0;
    int b4;
    char padb8[0x144 - 0xb8];
    float elapsed;
    char pad148[0x154 - 0x148];
    float f154;
    float f158;
    char pad15c[4];
    int f160;
    char pad164[0x174 - 0x164];
    float f174;
    float f178;

    void FUN_000cbc40(float dt);
    void FUN_000cf4b0(float dt);
    void FUN_000ce0d0(float dt);
};

void HUDOverlay::vfunc_3(float dt)
{
    if (!parent)
        return;
    if (hidden)
        return;

    volatile Frame_d0240 f;
    f.w = DAT_004de600;
    double x1 = DAT_004de600 * -0.5f;
    double hh = DAT_004de604 * 0.5f;
    DAT_004ddf14 = 0;
    DAT_004ddeb8 = 0;
    f.t20 = (float)x1;
    DAT_004ddea0 = 0;
    DAT_004ddf08 = 0;
    f.t30 = DAT_004de604 * -0.1f;
    DAT_004ddf0c = f.w * 0.06f + f.t20;
    DAT_004ddf10 = f.t30 + hh;
    f.t20 = (float)x1;
    f.t24 = DAT_004de604 * -0.5f;
    DAT_004ddeb0 = f.w * 0.1f + f.t20;
    DAT_004ddeb4 = DAT_004de604 * 0.36f + f.t24;
    f.t20 = (float)x1;
    f.t24 = DAT_004de604 * -0.5f;
    DAT_004dde98 = f.w * 0.1f + f.t20;
    DAT_004dde9c = DAT_004de604 * 0.4f + f.t24;
    f.t30 = DAT_004de604 * -0.18f;
    DAT_004ddf00 = f.w * 0.04f + x1;
    DAT_004ddf04 = f.t30 + hh;
    double ah = DAT_0049fd1c * f.w;
    f.hi = (float)ah;
    f.t30 = -(DAT_0049fd20 * DAT_004de604);
    DAT_004ddec8 = ah + x1;
    DAT_004ddecc = f.t30 + hh;
    (*(float*)&DAT_004dded0) = 0;
    f.t2c = (float)x1;
    (*(float*)((char*)&DAT_004ddea4 + 8)) = 0;
    f.t24 = -(DAT_0049fd24 * DAT_004de604);
    (*(float*)&DAT_004ddea4) = f.hi + f.t2c;
    (*(float*)((char*)&DAT_004ddea4 + 4)) = f.t24 + hh;

    Ref_d0240* want = parent->target->ref;
    if (want != ref && want) {
        FUN_00025960(&ref, want);
        if (ref) {
            float h = ref->f1b0c;
            f160 = 0xff;
            f154 = h;
            f158 = h;
            f.hi = ref->f1b0c;
            float d = f.hi - ref->FUN_00036090();
            f174 = d;
            f178 = d;
        }
    }
    if (ref && ref->f20b0)
        FUN_000a0d40(&ref);
    if (ref2 && ref2->f20b0)
        FUN_000a0d40(&ref2);

    int value = DAT_004dd700->timer->FUN_00086370()->FUN_00090110();
    if (value != lastValue) {
        float s = DAT_0049fcf0 * 0.4f;
        int delta = value - lastValue;
        lastValue = value;
        if (s > a8)
            a8 = s + a8;
        if (delta > 100) {
            if (b0 > 0.0f)
                b4 = b4 + delta;
            else
                b4 = delta;
            f.hi = 0.5f;
            f.lo = 0;
            f.v = b4 * 0.00166666671f;
            b0 = FUN_000186b0((float*)&f.v, (float*)&f.lo, (float*)&f.hi) + 0.5f;
        }
    } else {
        a8 = a8 - dt;
        if (a8 < 0.0f)
            a8 = 0;
        b0 = b0 - dt;
        if (b0 < 0.0f)
            b0 = 0;
    }

    updater->FUN_000c9810(dt);
    FUN_000cbc40(dt);
    FUN_000cf4b0(dt);
    FUN_000ce0d0(dt);
    elapsed = dt + elapsed;
}
} // namespace fn_000d0240
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d05f0 HUDOverlay::vfunc_4 (2754 B): equivalent/0x000d05f0.cpp [wrapped: conflict: Gfx; HUDOverlay; World]
// sym: ?vfunc_4@HUDOverlay@fn_000d05f0@@UAEXXZ @c425a2cebb0c @w6c5151344659
namespace fn_000d05f0 {
// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 76/76)
// HUDOverlay::vfunc_4 @ 0x000d05f0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __fastcall __security_check_cookie(unsigned int);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double floor(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

extern unsigned int DAT_004d9968;
extern int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

struct V3_d05f0 {
    float x, y, z;
};

struct Metrics_d05f0 {
    int dummy;
};

struct Slot_d05f0 {
    float weight;
    int a;
    int b;
    int value;
};

struct SlotStack_d05f0 {
    Slot_d05f0 slots[8];
    int index;
    float scale;
    void FUN_000f78f0();
};

struct Label_d05f0 {
    int f0;
    char rest[0x20];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const void *name, Metrics_d05f0 *font, int flag);
};

struct Layout_d05f0 {
    Metrics_d05f0 *font;
    int current;
    SlotStack_d05f0 stack;
    Layout_d05f0 *FUN_000f7fe0(Metrics_d05f0 *font);
    void FUN_000f87f0(Label_d05f0 *e, void *arg);
    void FUN_000f80e0(const char *text, int a, const void *b);
    void FUN_000f78e0();
};

class Gfx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual int v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(int a, int b);
};

class Layer_d05f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Canvas {
    Layer_d05f0 *layer;
    void FUN_00293d00(const void *v);
    void FUN_00293bf0(float angle);
    void FUN_00293da0(float a, float b, float c);
};

class UiObj_d05f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float a, int b);
    virtual char v7();
    virtual void v8(int a, int b);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(float a);
    virtual void v13();
    virtual void v14(float a, float b);
    virtual void v15(float *a, float *b);
    virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
};

struct UiVec_d05f0 {
    char pad0[0x24];
    UiObj_d05f0 **begin;
    UiObj_d05f0 **end;
};

struct Clock_d05f0 {
    float FUN_00085f80();
};
struct Obj10_d05f0 {
    int FUN_00059a50(V3_d05f0 *out);
};
struct World {
    char pad0[0x10];
    Obj10_d05f0 *p10;
};
struct ObjMgr {
    World *FUN_00024280(unsigned __int64 id);
};
struct Owner_d05f0 {
    char pad0[0x20];
    ObjMgr *objmgr;
    char pad24[0x58 - 0x24];
    Clock_d05f0 *clock;
};
struct Obj80 {
    float FUN_001cc8a0();
};
struct Part_d05f0 {
    void FUN_000c75b0();
    void FUN_000c72e0();
    void FUN_000c8850();
};


struct Frame_d05f0 {
    int padLow;
    float dist2;                // 0x00
    float out1;                 // 0x04
    union {
        int n1;
        float out2b;
    } s8;                       // 0x08
    union {
        float out2a;
        int n23;
    } sc;                       // 0x0c
    float dist1;                // 0x10
    Layout_d05f0 layout;              // 0x14
    union {
        char buf[0x44];
        Label_d05f0 e2;
        int digits[6];
        V3_d05f0 p3;
    } u;                        // 0xa4
    unsigned int cookie;        // 0xe8
};

class HUDOverlay {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x0c - 4];
    Owner_d05f0 *owner;
    char pad10[0x78 - 0x10];
    float f78;
    Metrics_d05f0 *font;
    Obj80 *p80;
    char pad84[4];
    Part_d05f0 *p88;
    Part_d05f0 *p8c;
    char pad90[4];
    char f94[0x14];
    float fa8;
    int iac;
    float fb0;
    int ib4;
    int flags;
    char fbc[0x13c - 0xbc];
    float f13c;
    float f140;
    float f144;
    int i148;
    char pad14c[0x1f8 - 0x14c];
    UiObj_d05f0 *p1f8;
    UiObj_d05f0 *arr[6];
    char pad214[0x244 - 0x214];
    UiObj_d05f0 *p244;
    UiVec_d05f0 *p248;
    int i24c;
    char pad250[0x4a0 - 0x250];
    UiObj_d05f0 *p4a0;
    char pad4a4[0x4ac - 0x4a4];
    UiVec_d05f0 *p4ac;
    UiVec_d05f0 *p4b0;
    UiVec_d05f0 *p4b4;
    V3_d05f0 v4b8;
    char name4c4[0x504 - 0x4c4];
    float f504;
    UiObj_d05f0 *p508;
    void FUN_000cc7e0();
    void FUN_000cf740();
    void FUN_000cda90();
    void FUN_000cab50();
};

void HUDOverlay::vfunc_4()
{
    Frame_d05f0 f;
    f.cookie = DAT_004d9968;
    int nscr = DAT_0052c2a8->v34();
    for (int i = 0; i < nscr; i++)
        DAT_0052c2a8->v38(i, 0);

    if (flags & 0x400) {
        p8c->FUN_000c75b0();
        p8c->FUN_000c72e0();
    }
    if (flags & 4)
        p88->FUN_000c8850();

    SlotStack_d05f0 *st = &f.layout.stack;
    if (flags & 0x200) {
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d00(((V3_d05f0*)&DAT_004ddf00));
        f.layout.FUN_000f7fe0(font);
        st->FUN_000f78f0();
        st->slots[st->index].b = 1;
        st->slots[st->index].a = 0;
        if (fb0 > 0.0f) {
            st->slots[st->index].weight = ((fb0 / DAT_0049fcf4) * 2.0f + 1.0f) * f78 * DAT_0049fd00;
            st->slots[st->index].value = 0xc4fef618;
            FUN_000964a0(f.u.buf, 0x40, "%d", ib4);
            f.layout.FUN_000f80e0(f.u.buf, DAT_0049fd08, 0);
        }
        FUN_000964a0(f.u.buf, 0x40, "%d", iac);
        if (fa8 > 0.0f) {
            st->slots[st->index].weight = ((fa8 / DAT_0049fcf0) * 2.0f + 1.0f) * f78 * DAT_0049fd00;
            st->slots[st->index].value = 0xc4fef618;
            f.layout.FUN_000f80e0(f.u.buf, DAT_0049fd08, 0);
        }
        st->slots[st->index].value = 0xfffef618;
        float k;
        if (fa8 > 0.2f)
            k = 1.2f;
        else
            k = 1.0f;
        st->slots[st->index].weight = k * f78 * DAT_0049fd00;
        f.layout.FUN_000f80e0(f.u.buf, DAT_0049fd08, f94);
        if (st->index > 0)
            st->index--;
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
        f.layout.FUN_000f78e0();
    }

    if (f144 < f140) {
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        f.layout.FUN_000f7fe0(font);
        f.u.e2.FUN_000f7930();
        f.u.e2.FUN_000f8500(fbc, font, 1);
        f.u.e2.f0 = DAT_0049fcf8;
        st->FUN_000f78f0();
        int alpha = (int)((f144 / f140) * 255.0f);
        st->slots[st->index].value = ((255 - alpha) << 24) | (i148 & 0xffffff);
        st->slots[st->index].b = 2;
        st->slots[st->index].a = 1;
        st->slots[st->index].weight = (f144 / f140) * f13c * f78;
        f.layout.FUN_000f87f0(&f.u.e2, 0);
        if (st->index > 0)
            st->index--;
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
        f.u.e2.FUN_000f7960();
        f.layout.FUN_000f78e0();
    }

    FUN_000cc7e0();
    if (flags & 0x10) {
        float x = p80->FUN_001cc8a0();
        int n1 = (int)floor(x);
        f.u.digits[5] = (n1 / 600) % 6;
        int n2 = (int)floor(x);
        f.u.digits[0] = (n2 / 60) % 10 + 10;
        int n3 = (int)floor(x);
        f.u.digits[1] = (n3 / 10) % 6 + 20;
        int n4 = (int)floor(x);
        f.u.digits[2] = n4 % 10 + 30;
        int n5 = (int)floor(x * 10.0f);
        f.u.digits[3] = n5 % 10 + 40;
        int n6 = (int)floor(x * 100.0f);
        f.u.digits[4] = n6 % 10 + 50;
        for (int i = 0; i < 6; i++) {
            if (arr[i] != 0) {
                arr[i]->v12((float)f.u.digits[i]);
                arr[i]->v7();
            }
        }
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d00(((V3_d05f0*)&DAT_004dde98));
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
        float c = (*(float*)&DAT_0049fcfc);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(c, c, c);
        if (p1f8 != 0)
            p1f8->v8(0, 0);
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    }

    FUN_000cf740();
    if ((flags & 0xa) && p244 != 0) {
        p244->v6(owner->clock->FUN_00085f80() * 1000.0f, 0);
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d00(((V3_d05f0*)&DAT_004ddef4));
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
        float c = (*(float*)&DAT_0049fd28);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(c, c, c);
        p244->v8(0, 0);
        if (i24c == 4 && p244->v7()) {
            unsigned char cnt = (unsigned char)(p248->end - p248->begin);
            for (int i = 0; i < cnt; i++) {
                UiObj_d05f0 *o = p248->begin[(unsigned char)i];
                o->v14(125.0f, 217.0f);
                o->v12(125.0f);
                o->v16(2);
                o->v18(-1);
                cnt = (unsigned char)(p248->end - p248->begin);
            }
        }
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    }

    FUN_000cda90();
    if ((flags & 0x20) && p4a0 != 0) {
        f.dist1 = 0.0f;
        f.dist2 = 0.0f;
        ObjMgr *om1 = owner->objmgr;
        World *w1 = om1->FUN_00024280(FUN_002672f0("hulk", 0, 0));
        if (w1 != 0) {
            V3_d05f0 &p = f.u.p3;
            w1->p10->FUN_00059a50(&p);
            f.dist1 = (float)sqrt((p.z - v4b8.z) * (p.z - v4b8.z) + (p.y - v4b8.y) * (p.y - v4b8.y) + (p.x - v4b8.x) * (p.x - v4b8.x));
        }
        ObjMgr *om2 = owner->objmgr;
        World *w2 = om2->FUN_00024280(FUN_002672f0(name4c4, 0, 0));
        if (w2 != 0) {
            V3_d05f0 &p = f.u.p3;
            w2->p10->FUN_00059a50(&p);
            f.dist2 = (float)sqrt((p.z - v4b8.z) * (p.z - v4b8.z) + (p.y - v4b8.y) * (p.y - v4b8.y) + (p.x - v4b8.x) * (p.x - v4b8.x));
        }
        if (p4ac != 0) {
            f.s8.n1 = (unsigned char)(p4ac->end - p4ac->begin);
            for (int i = 0; i < f.s8.n1; i++) {
                p4ac->begin[(unsigned char)i]->v15(&f.out1, &f.sc.out2a);
                float denom = (f504 == 0.0f) ? 1.0f : f504;
                p4ac->begin[(unsigned char)i]->v12(((f.sc.out2a - f.out1) / denom) * f.dist2);
                p4ac->begin[(unsigned char)i]->v7();
            }
        }
        if (p4b0 != 0) {
            f.sc.n23 = (unsigned char)(p4b0->end - p4b0->begin);
            for (int i = 0; i < f.sc.n23; i++) {
                p4b0->begin[(unsigned char)i]->v15(&f.out1, &f.s8.out2b);
                float denom = (f504 == 0.0f) ? 1.0f : f504;
                p4b0->begin[(unsigned char)i]->v12(((f.s8.out2b - f.out1) / denom) * f.dist1);
                p4b0->begin[(unsigned char)i]->v7();
            }
        }
        if (p4b4 != 0) {
            f.sc.n23 = (unsigned char)(p4b4->end - p4b4->begin);
            for (int i = 0; i < f.sc.n23; i++) {
                p4b4->begin[(unsigned char)i]->v15(&f.out1, &f.s8.out2b);
                float denom = (f504 == 0.0f) ? 1.0f : f504;
                p4b4->begin[(unsigned char)i]->v12(((f.s8.out2b - f.out1) / denom) * f.dist2);
                p4b4->begin[(unsigned char)i]->v7();
            }
        }
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d00(((V3_d05f0*)&DAT_004ddeb0));
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
        float c = (*(float*)&DAT_0049fcc4);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(c, c, c);
        p4a0->v8(0, 0);
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    }

    if (flags & 0x800) {
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(4.0f, 4.0f, 4.0f);
        p508->v8(0, 0);
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    }
    FUN_000cab50();
    __security_check_cookie(f.cookie);
}
} // namespace fn_000d05f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d10c0 FUN_000d10c0 (109 B): equivalent/0x000d10c0.cpp [wrapped: conflict: Closure0; HUDOverlay; Method0]
// sym: ?FUN_000d10c0@Registry_d10c0@fn_000d10c0@@QAEXPBDPAVHUDOverlay@2@P832@AEXXZ@Z @d14d43ebce67 @w55bc884abc8a
namespace fn_000d10c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000d10c0 @ 0x000d10c0
// FUN_000d10c0 @ 0x000d10c0  (generated by work/closure/gen.py)
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class HUDOverlay { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_d10c0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_d10c0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_d10c0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_d10c0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_d10c0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000d10c0(const char* name, HUDOverlay* owner, void (HUDOverlay::*fn)());
};

void Registry_d10c0::FUN_000d10c0(const char* name, HUDOverlay* owner, void (HUDOverlay::*fn)()) {
    typedef Closure0<HUDOverlay, void> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<HUDOverlay, void>));
    Closure0<HUDOverlay, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<HUDOverlay, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000d10c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3fdf6d3 {

// 0x000d1220 FUN_000d1220 (83 B): equivalent/0x000d1220.cpp
// sym: ?FUN_000d1220@Registry_d1220@fn_f3fdf6d3@@QAEXPBDPAVHUDOverlay_d1220@2@P832@AEX0MMVVector_d1220@math@@@Z@Z @eaefa4165180 @w2d2ece7f4dee
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d1220 @ 0x000d1220
// FUN_000d1220 @ 0x000d1220  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d1220::FUN_000d1220(const char* a1, HUDOverlay_d1220* a2, Fn_d1220 a3) {
    typedef Closure4_d1220<HUDOverlay_d1220, void, const char*, float, float, math::Vector_d1220> Alloc_d1220;
    HULK_SIZE32(Alloc_d1220, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d1220));
    void* x = 0;
    if (m) {
        ((Raw_d1220*)m)->FUN_000ceaa0(a1, a3);
        x = new (m) Closure4_d1220<HUDOverlay_d1220, void, const char*, float, float, math::Vector_d1220>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000d1280 FUN_000d1280 (83 B): equivalent/0x000d1280.cpp
// sym: ?FUN_000d1280@Registry_d1280@fn_f3fdf6d3@@QAEXPBDPAVHUDOverlay_d1280@2@P832@AEH00M@Z@Z @501ae160e5c4 @w12140262ef53
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d1280 @ 0x000d1280
// FUN_000d1280 @ 0x000d1280  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d1280::FUN_000d1280(const char* a1, HUDOverlay_d1280* a2, Fn_d1280 a3) {
    typedef Closure3_d1280<HUDOverlay_d1280, int, const char*, const char*, float> Alloc_d1280;
    HULK_SIZE32(Alloc_d1280, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d1280));
    void* x = 0;
    if (m) {
        ((Raw_d1280*)m)->FUN_000ceb80(a1, a3);
        x = new (m) Closure3_d1280<HUDOverlay_d1280, int, const char*, const char*, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f3fdf6d3

// 0x000d12e0 FUN_000d12e0 (109 B): equivalent/0x000d12e0.cpp [wrapped: conflict: Closure0; HUDOverlay; Method0]
// sym: ?FUN_000d12e0@Registry_d12e0@fn_000d12e0@@QAEXPBDPAVHUDOverlay@2@P832@AEHXZ@Z @b0d52a81f178 @w193961f72513
namespace fn_000d12e0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000d12e0 @ 0x000d12e0
// FUN_000d12e0 @ 0x000d12e0  (generated by work/closure/gen.py)
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class HUDOverlay { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_d12e0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_d12e0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_d12e0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_d12e0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_d12e0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000d12e0(const char* name, HUDOverlay* owner, int (HUDOverlay::*fn)());
};

void Registry_d12e0::FUN_000d12e0(const char* name, HUDOverlay* owner, int (HUDOverlay::*fn)()) {
    typedef Closure0<HUDOverlay, int> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<HUDOverlay, int>));
    Closure0<HUDOverlay, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<HUDOverlay, int>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000d12e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3fdf6d3 {

// 0x000d1530 FUN_000d1530 (83 B): equivalent/0x000d1530.cpp
// sym: ?FUN_000d1530@Registry_d1530@fn_f3fdf6d3@@QAEXPBDPAVHUDOverlay_d1530@2@P832@AEHHHVVector_d1530@math@@2@Z@Z @6def611a554a @w2adedb321a26
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d1530 @ 0x000d1530
// FUN_000d1530 @ 0x000d1530  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d1530::FUN_000d1530(const char* a1, HUDOverlay_d1530* a2, Fn_d1530 a3) {
    typedef Closure4_d1530<HUDOverlay_d1530, int, int, int, math::Vector_d1530, math::Vector_d1530> Alloc_d1530;
    HULK_SIZE32(Alloc_d1530, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d1530));
    void* x = 0;
    if (m) {
        ((Raw_d1530*)m)->FUN_000cf050(a1, a3);
        x = new (m) Closure4_d1530<HUDOverlay_d1530, int, int, int, math::Vector_d1530, math::Vector_d1530>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000d1590 FUN_000d1590 (83 B): equivalent/0x000d1590.cpp
// sym: ?FUN_000d1590@Registry_d1590@fn_f3fdf6d3@@QAEXPBDPAVHUDOverlay_d1590@2@P832@AEXHHVVector_d1590@math@@@Z@Z @8324940f4bf6 @wf98953dbe1fe
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d1590 @ 0x000d1590
// FUN_000d1590 @ 0x000d1590  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d1590::FUN_000d1590(const char* a1, HUDOverlay_d1590* a2, Fn_d1590 a3) {
    typedef Closure3_d1590<HUDOverlay_d1590, void, int, int, math::Vector_d1590> Alloc_d1590;
    HULK_SIZE32(Alloc_d1590, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d1590));
    void* x = 0;
    if (m) {
        ((Raw_d1590*)m)->FUN_000cf160(a1, a3);
        x = new (m) Closure3_d1590<HUDOverlay_d1590, void, int, int, math::Vector_d1590>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000d1640 FUN_000d1640 (83 B): equivalent/0x000d1640.cpp
// sym: ?FUN_000d1640@Registry_d1640@fn_f3fdf6d3@@QAEXPBDPAVHUDOverlay_d1640@2@P832@AEHH0VVector_d1640@math@@22@Z@Z @381e4c8dfb53 @wcc6bb976d3d7
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d1640 @ 0x000d1640
// FUN_000d1640 @ 0x000d1640  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d1640::FUN_000d1640(const char* a1, HUDOverlay_d1640* a2, Fn_d1640 a3) {
    typedef Closure5_d1640<HUDOverlay_d1640, int, int, const char*, math::Vector_d1640, math::Vector_d1640, math::Vector_d1640> Alloc_d1640;
    HULK_SIZE32(Alloc_d1640, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d1640));
    void* x = 0;
    if (m) {
        ((Raw_d1640*)m)->FUN_000cf2b0(a1, a3);
        x = new (m) Closure5_d1640<HUDOverlay_d1640, int, int, const char*, math::Vector_d1640, math::Vector_d1640, math::Vector_d1640>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f3fdf6d3

// 0x000d2c30 FUN_000d2c30 (1330 B): equivalent/0x000d2c30.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_000d2c30@HealthBar@fn_000d2c30@@QAEXXZ @03fff861fc42 @w9185900df052
namespace fn_000d2c30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 62/62)
// FUN_000d2c30 @ 0x000d2c30
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d {
class CompositeDrawable_d2c30;
class Locator_d2c30;
}

class Res_d2c30 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Composite_d2c30 : public Res_d2c30 {
public:
    char pad04[0x44];
    Res_d2c30 *child48;
    void FUN_002998d0(int v);
};

class Inventory_d2c30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res_d2c30 *get(void *caster, unsigned int lo, unsigned int hi);
};

struct Flags_d2c30 {
    bool FUN_00092940(int id);
};

struct Holder_d2c30 {
};

struct World {
    char pad0[0x54];
    Holder_d2c30 *holder;
};


static Res_d2c30 *GetLocator(const char *name)
{
    Inventory_d2c30 *inv = (*(Inventory_d2c30**)&DAT_004dd9cc);
    unsigned __int64 h = FUN_0027b020(name);
    content::LoadInventory::DynamicCaster<pure3d::Locator_d2c30> c;
    return inv->get(&c, (unsigned int)h, (unsigned int)(h >> 32));
}

class HealthBar {
public:
    char pad0[0x164];
    Res_d2c30 *r164;
    Res_d2c30 *r168;
    char pad16c[0x1a4 - 0x16c];
    Res_d2c30 *r1a4;
    Res_d2c30 *r1a8;
    Res_d2c30 *r1ac;
    Res_d2c30 *r1b0;
    Res_d2c30 *r1b4;
    Res_d2c30 *r1b8;
    char pad1bc[0x1e0 - 0x1bc];
    Res_d2c30 *r1e0;
    Res_d2c30 *r1e4;
    Res_d2c30 *r1e8;
    void FUN_000d2c30();
};

void HealthBar::FUN_000d2c30()
{
    Flags_d2c30 *fl = ((Flags_d2c30 *)((owners::A_86340 *)(DAT_004dd700->holder))->FUN_00086340());
    const char *n1;
    const char *n2;
    const char *n3;
    if (!fl->FUN_00092940(0x27b)) {
        n1 = "FE_healthmin";
        n2 = "LOC_health_topdistanceShape";
        n3 = "LOC_health_top_topdistanceShape";
    } else if (!fl->FUN_00092940(0x298)) {
        n1 = "FE_healthmin1";
        n2 = "LOC_health1_topdistanceShape";
        n3 = "LOC_health_top_topdistance1Shape";
    } else if (!fl->FUN_00092940(0x2ba)) {
        n1 = "FE_healthmin2";
        n2 = "LOC_health2_topdistanceShape";
        n3 = "LOC_health_top_topdistance2Shape";
    } else {
        n1 = "FE_healthmin3";
        n2 = "LOC_health3_topdistanceShape";
        n3 = "LOC_health_top_topdistance3Shape";
    }

    Composite_d2c30 *comp;
    {
        Inventory_d2c30 *inv = (*(Inventory_d2c30**)&DAT_004dd9cc);
        unsigned __int64 h = FUN_0027b020(n1);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_d2c30> c;
        comp = (Composite_d2c30 *)inv->get(&c, (unsigned int)h, (unsigned int)(h >> 32));
    }
    Res_d2c30 *r = GetLocator(n2);
    if (r)
        r->AddRef();
    if (r1ac)
        r1ac->Release();
    r1ac = r;

    r = GetLocator(n3);
    if (r)
        r->AddRef();
    if (r1b8)
        r1b8->Release();
    r1b8 = r;
    comp->FUN_002998d0(0);

    if (comp)
        comp->AddRef();
    if (r164)
        r164->Release();
    r164 = comp;
    Res_d2c30 *ch = comp->child48;
    if (ch)
        ch->AddRef();
    if (r168)
        r168->Release();
    r168 = ch;

    r = GetLocator("LOC_health_topShape");
    if (r)
        r->AddRef();
    if (r1a4)
        r1a4->Release();
    r1a4 = r;

    r = GetLocator("LOC_health_botShape");
    if (r)
        r->AddRef();
    if (r1a8)
        r1a8->Release();
    r1a8 = r;

    r = GetLocator("LOC_health_2_topShape");
    if (r)
        r->AddRef();
    if (r1b0)
        r1b0->Release();
    r1b0 = r;

    r = GetLocator("LOC_health_2_botShape");
    if (r)
        r->AddRef();
    if (r1b4)
        r1b4->Release();
    r1b4 = r;

    r = GetLocator("LOC_adrenaline_surge_topShape");
    if (r)
        r->AddRef();
    if (r1e0)
        r1e0->Release();
    r1e0 = r;

    r = GetLocator("LOC_adrenaline_surge_botShape");
    if (r)
        r->AddRef();
    if (r1e4)
        r1e4->Release();
    r1e4 = r;

    r = GetLocator("LOC_adrenaline_surge_topdistanceShape");
    if (r)
        r->AddRef();
    if (r1e8)
        r1e8->Release();
    r1e8 = r;
}
} // namespace fn_000d2c30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3fdf6d3 {

// 0x000d3d80 FUN_000d3d80 (341 B): equivalent/0x000d3d80.cpp
// sym: _FUN_000d3d80 @59087fc545ad @w52946d4b2e5f
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 18/18)
// FUN_000d3d80 @ 0x000d3d80
extern "C" char __cdecl FUN_000d3d80(void *p1, void *p2, Owner_d3d80 *owner, Arg_d3d80 *arg, Typed *typed)
{
    if (typed->GetTypeId() == (*(unsigned long long*)&DAT_004ddf30)) {
        int a = arg->FUN_000fad90();
        int b = arg->FUN_000fad90();
        FEBackground *mem = (FEBackground *)FUN_0008d690(0x158);
        FEBackground *obj = 0;
        if (mem)
            obj = ((FEBackground_nv_d3d80*)(((FEBackground*)(mem))))->FUN_000d7af0(a, b);
        owner->vfunc_23(obj, a);
        return ((FEBackground_nv_d3d80*)(((FEBackground*)(obj))))->FUN_000d7890(arg, p2, owner);
    }
    if (typed->GetTypeId() == (*(unsigned long long*)&DAT_004ddf50)) {
        int a = arg->FUN_000fad90();
        FEMemCardControl *mem = (FEMemCardControl *)FUN_0008d690(0x458);
        FEMemCardControl *obj = 0;
        if (mem)
            obj = ((FEMemCardControl_nv_d3d80*)(((FEMemCardControl*)(mem))))->FUN_000d82d0(a, p1);
        owner->vfunc_23(obj, a);
        owner->dirty = 1;
        return ((FEMemCardControl_nv_d3d80*)(((FEMemCardControl*)(obj))))->FUN_000dc230(arg, p2, owner);
    }
    if (typed->GetTypeId() == (*(unsigned long long*)&DAT_004ddf58)) {
        int a = arg->FUN_000fad90();
        FETextInput *mem = (FETextInput *)FUN_0008d690(0x180);
        FETextInput *obj = 0;
        if (mem)
            obj = ((FETextInput_nv_d3d80*)(((FETextInput*)(mem))))->FUN_000dc590(a);
        owner->vfunc_23(obj, a);
        owner->dirty = 1;
        return ((FETextInput_nv_d3d80*)(((FETextInput*)(obj))))->FUN_000dd350(arg, p2, owner);
    }
    return 0;
}


// 0x000d3ee0 FUN_000d3ee0 (6 B): matches/0x000d3ee0.cpp
// sym: _FUN_000d3ee0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_000d3ee0() {
    return (int*)&DAT_0040b020;
}

} // namespace fn_f3fdf6d3

// 0x000d3ef0 FUN_000d3ef0 (31 B): equivalent/0x000d3ef0.cpp
// sym: ?FUN_000d3ef0@Thing_d3ef0@owners@@QAEXHH@Z @f95fca18c774 @w3947bbc3aaf5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d3ef0 @ 0x000d3ef0
void owners::Thing_d3ef0::FUN_000d3ef0(hulk_intptr a, hulk_intptr b) {
    first = ((int)a);
    second = ((int)b);
    thunk_FUN_000fc1b0()->FUN_000f7050(this);
}

