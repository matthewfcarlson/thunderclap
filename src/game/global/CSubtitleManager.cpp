// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001be0e0..0x001c1200 (kind game, layer game, confidence high), dominant class CSubtitleManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fed79ca6 {
#define TREE_TU_END }
namespace fn_fed79ca6 {} using namespace fn_fed79ca6;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fed79ca6 {
struct Key {
    int a, b;
};
class Table {
  public:
    char pad[0x3c];
    struct Entry {
        __int64 key;
        char pad[16];
    }* items;
    int count;
    int Find(Key k);
};
class Overlay_1be200 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class Overlay_1be210 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
struct Builder {
    char pad00[8];
    float* pos;
    char pad0c[4];
    int* color;
    void FUN_0008ef00();
};
} // namespace fn_fed79ca6
class Gfx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual Builder* v78(int a, int b, int c, int d, int e);
    virtual void v7c(Builder* b);
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8(int a);
};
namespace fn_fed79ca6 {
class Device_1be260 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c(int a);
    virtual void v40(int a);
};
struct DeviceHolder {
    Device_1be260* device;
    void FUN_00293d00(char* p);
};
struct Layer_1be260 {
    char pad00[0x10];
    int handle;
};
class Quad_1be260 {
public:
    char pad00[0x10];
    float size;
    char pad14[4];
    Layer_1be260* layer;
    void FUN_001be260();
};
class Inner_1be490 {
  public:
    char pad0[8];
    int a;
    char b;
    char padD[3];
    int c;
    int d;
    char pad18[4];
    short f;
};
class Outer_1be490 {
  public:
    char pad0[0x2c];
    Inner_1be490* p;
    char pad30[0x20];
    int q;
    void Reset();
};
struct Owner_1bee10 {
    char pad0[0x24];
    int values[1];
    int FUN_000f7240(int a, int b);
};
struct Slot_1bee10 {
    float weight;
    int a;
    int b;
    int value;
};
struct Blender_1bee10 {
    Owner_1bee10 *owner;
    int current;
    Slot_1bee10 slots[8];
    int index;
    float scale;
    Blender_1bee10 *FUN_000f7fe0(Owner_1bee10 *o);
    void FUN_000f78e0();
};
extern "C" int __cdecl FUN_000fba10(int handle, int a, int b, int value, float t, int extra);
class Effect_1bee10 {
public:
    char pad0[0x10];
    int keyA;
    int keyB;
    char pad18[0x20 - 0x18];
    int mode;
    char pad24[4];
    int handle;
    char pad2c[0x44 - 0x2c];
    Owner_1bee10 *owner;

    int FUN_001bee10();
};
extern void* hulk_at_0042147c[];
class Ref_1bef80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Overlay_1bef80 {
  public:
    void* vptr;
};
class CSubtitleOverlay_1bef80 : public Overlay_1bef80 {
  public:
    char pad[0x14];
    Ref_1bef80* m18;
    ~CSubtitleOverlay_1bef80() throw();
};
struct DrawEntry { float size; int a; int b; unsigned color; };
struct TextBuilder { char prefix[8]; DrawEntry entries[8]; int count; float scale; void FUN_000f7fe0(void*); void FUN_000f81b0(void*, int, void*); void FUN_000f78e0(); };
struct RenderDevice_1befb0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(int); virtual void s16(int); };
struct RenderContext { RenderDevice_1befb0* device; void FUN_00293d00(void*); };
struct CSubtitleOverlay_1befb0 : Overlay { int unk4; void* text; int unkC; float visibility; unsigned alpha; int unk18; char textData[0x104]; char position[4]; void FUN_001be260(); virtual void vfunc_4(); };
class CFEManager_1bf3a0 {
  public:
    void Call(const char*, int);
};
class Function_1bf3a0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1bf420 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1bf420::*MFn_1bf420)(unsigned char);
class Function_1bf420 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Dummy_1bf4a0 {
  public:
    void Call(void*);
};
extern "C" char DAT_004214d0[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
class Method4_1bf4c0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn fn;
    Method4_1bf4c0* FUN_001bf4c0(const char*, ScriptMemberFn);
};
struct CSubtitleManager_1bf550 { void invoke(int, float, const char *, float); };
struct SubtitleArgs {
  public:
    union { const char* first; int number; };
    union { const char* second; float start; };
    union { const char *text; float time; };
    float end;
};
struct Function_1bf550 { virtual void vfunc_0(); virtual void vfunc_1(); };
class CSubtitleManager_1bf5f0 {
  public:
    void V0();
    void V1();
    void V2();
    void V3();
    void V4();
    void V5();
    void V6();
    void V7(int, int);
};
class Function_1bf5f0 {
  public:
    virtual void V0();
    virtual void V1();
};
class CActorManager_1bf670;
typedef unsigned char(__fastcall* Fn_1bf670)(CActorManager_1bf670*);
class Dummy_1bf6f0 {
  public:
    void Call(void*);
};
struct CSubtitleManager_1bf790 {
    void FUN_001bf790(float, float, float);
};
struct Float3 {
    float x, y, z;
};
struct Function_1bf790 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_00421520[];
class Method3_1bf7c0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    void Init_001d0480(const char*, int);
    Method3_1bf7c0* Setup(const char*, ScriptMemberFn);
};
struct CSubtitleManager_1bf840 { };
struct Arguments {
  public:
    union { const char *first; int number; };
    union { const char *second; float time; };
    union { const char *text; float third; };
    float duration;
};
typedef unsigned int u32_1bf860;
struct Sub_1bf860 {
    u32_1bf860 f0;
    u32_1bf860 f4;
    u32_1bf860 f8;
    u8 fC;
    u8 pad[3];
    u32_1bf860 f10;
    u32_1bf860 f14;
    u8 pad2[4];
    u16 f1c;
};
struct Obj_1bf860 {
    u32_1bf860 f0;
    u32_1bf860 f4;
    char pad8[5];
    u8 fD;
    char padE[0x12];
    u32_1bf860 f20;
    u8 f24;
    char pad25[7];
    Sub_1bf860* f2C;
    char pad30[0x20];
    u32_1bf860 f50;
    char pad54;
    u8 f55;

    void Reset(char b);
};
struct Tracker_1bf8b0 {
    int FUN_000f7240(int a, int b);
};
class Handler_1bf8b0 {
public:
    void FUN_001bf8b0();
    void FUN_001bea80();
    void FUN_001bec90();
    void FUN_001be4b0(int v);
    void FUN_001be7f0(int v);

    char pad0[0xc];
    char active;
    char forced;
    char pad1[2];
    int keyA;
    int keyB;
    char pad2[0x20 - 0x18];
    int mode;
    char enabled;
    char pad3[0x34 - 0x25];
    Tracker_1bf8b0 *trackA;
    Tracker_1bf8b0 *trackB;
    char pad4[0x50 - 0x3c];
    int pending;
};
struct Owner_1bf9b0 {
    int FUN_000f7240(int a, int b);
};
struct SubObj_1bf9b0 {
    char data[4];
};
struct Sink_1bf9b0 {
    char pad0[8];
    Owner_1bf9b0 *owner;
    bool flag;
    char padd[0x1c - 0xd];
    SubObj_1bf9b0 sub;
};
struct Key_1bf9b0 {
    float t;
    float dur;
    int a;
    int b;
};
extern "C" void __cdecl FUN_000fb690(SubObj_1bf9b0 *sub, int value, int n);
class Track {
public:
    float time;
    int count;
    Key_1bf9b0 *keys;
    char pad0c;
    bool active;
    char pad0e[2];
    int keyA;
    int keyB;
    int subIndex;
    int subCount;
    int mode;
    char pad24;
    char pad25[3];
    int *handles;
    Sink_1bf9b0 *sink;
    char pad30[4];
    Owner_1bf9b0 *ownerA;
    Owner_1bf9b0 *ownerB;
    char pad3c[8];
    Owner_1bf9b0 *current;
    char pad48[8];
    int busy;
    char pad54;
    char flag55;

    int FUN_001bee10();
    void FUN_001bf9b0();
};
typedef unsigned int u32_1bfc30;
struct State_1bfc30 {
    char pad[0x58];
    int query_001be0e0(int, int);
};
struct sSubtitleCallback_1bfc30 {
    virtual void f0();
    virtual void f1(int, int);
};
extern void* g_vftable_1bfc80[];
class Ref_1bfc80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Overlay_1bfc80 {
  public:
    void* vptr;
    void Fin();
};
void Free_0008d330(void*) throw();
class CSubtitleOverlay_1bfc80 : public Overlay_1bfc80 {
  public:
    char pad[0x14];
    Ref_1bfc80* m18;
    CSubtitleOverlay_1bfc80* f0(unsigned char fl);
};
class CActorManager_1bfdf0 {
  public:
    void Method(const char*, float);
};
struct Pair_1bfdf0 {
    const char* s;
    float f;
};
class Actor_1bfe80 {
  public:
    void fn(unsigned char);
};
class CActorManager_1bff10 {
  public:
    void invoke(const char*);
};
struct CSubtitleManager_1bff80 { void FUN_001bff80(int, float, const char *, float); };
class CActorManager_1c0030 {
  public:
    void Method(const char*, float);
};
struct Pair_1c0030 {
    const char* s;
    float f;
};
class CActorManager_1c00b0;
typedef unsigned char(__fastcall* Fn_1c00b0)(CActorManager_1c00b0*);
class CActorManager_1c0140 {
  public:
    void invoke(const char*);
};
struct CSubtitleManager_1c01b0 { char padding[4]; };
struct CSubtitleManager_1c0230 { void placeholder(); };
struct Vec3_1c0360 { float x, y, z; };
struct Entry_1c0360 {
    float a;
    float b;
    int c;
    int d;
};
struct Child_1c0360 {
    char pad0[8];
    int field08;
    char flag0c;
    char pad0d[3];
    int field10;
    int field14;
    char pad18[4];
    short word1c;
};
struct Source_1c0360 {
    char pad0[0x2c];
    int field2c;
};
struct Holder_1c0360 {
    Source_1c0360 *FUN_000862b0();
};
float __cdecl FUN_000f6a70(int a, Vec3_1c0360 *v, int target);
class Shake_1c0360 {
public:
    float value;
    int count;
    Entry_1c0360 *entries;
    char pad0c;
    char flag0d;
    char pad0e[0x12];
    int mode;
    char flag24;
    char pad25[7];
    Child_1c0360 *child;
    char pad30[8];
    int target;
    char pad3c[0x10];
    Holder_1c0360 *holder;
    int field50;
    char pad54;
    char flag55;
    void FUN_001c0360(int newMode, int newCount);
};
struct Listener_1c04e0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(float dt);
};
struct StateHolder {
    int* FUN_00086270();
};
struct Clock_1c04e0 {
    float FUN_00085f80();
};
} // namespace fn_fed79ca6
struct World {
    char pad[0x58];
    Clock_1c04e0* clock;
};
namespace fn_fed79ca6 {
struct Fader_1c04e0 {
    float timer;
    int pending;
    char pad0[4];
    bool active;
    bool fadeIn;
    char pad2[0x20 - 0x0e];
    int mode;
    char pad3[0x2c - 0x24];
    Listener_1c04e0* listener;
    char pad4[0x4c - 0x30];
    StateHolder* state;
    int alpha;
    void FUN_001bf9b0();
    void Update(float dt);
};
class Manager {
  public:
    char pad[0x54];
    char flag;
    void Do_001c0650(int, int, int);
};
class sSubtitleCallback_1c06f0 {
  public:
    virtual void vfunc_0(int, int);
    virtual void vfunc_1();
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_fed79ca6
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_fed79ca6 {
class CSubtitleManager_1c0810 {};
typedef void (CSubtitleManager_1c0810::*Fn_1c0810)(int, float, const char*, float);
class Registry_1c0810 { public:
    void FUN_001c0810(const char* a1, CSubtitleManager_1c0810* a2, Fn_1c0810 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1c0810;
template<> class Closure4_1c0810<CSubtitleManager_1c0810, void, int, float, const char*, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1c0810 fn; CSubtitleManager_1c0810* owner; Closure4_1c0810(CSubtitleManager_1c0810* o) { owner = o; } };
class Raw_1c0810 { public: void FUN_001bf4c0(const char*, Fn_1c0810); };
class CSubtitleManager_1c0980 {};
typedef void (CSubtitleManager_1c0980::*Fn_1c0980)(float, float, float);
class Registry_1c0980 { public:
    void FUN_001c0980(const char* a1, CSubtitleManager_1c0980* a2, Fn_1c0980 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1c0980;
template<> class Closure3_1c0980<CSubtitleManager_1c0980, void, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1c0980 fn; CSubtitleManager_1c0980* owner; Closure3_1c0980(CSubtitleManager_1c0980* o) { owner = o; } };
class Raw_1c0980 { public: void FUN_001bf710(const char*, Fn_1c0980); };
class CSubtitleManager_1c09e0 {};
typedef void (CSubtitleManager_1c09e0::*Fn_1c09e0)(const char*, const char*, float);
class Registry_1c09e0 { public:
    void FUN_001c09e0(const char* a1, CSubtitleManager_1c09e0* a2, Fn_1c09e0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1c09e0;
template<> class Closure3_1c09e0<CSubtitleManager_1c09e0, void, const char*, const char*, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1c09e0 fn; CSubtitleManager_1c09e0* owner; Closure3_1c09e0(CSubtitleManager_1c09e0* o) { owner = o; } };
class Raw_1c09e0 { public: void FUN_001bf7c0(const char*, Fn_1c09e0); };
struct State_1c0a40 {
    char pad[0xd0];
    unsigned value;
};
struct Context {
    State_1c0a40*** FUN_000862e0();
};
struct Effect_1c0a40 {
};
extern int __cdecl FUN_00266da0(int);
struct Object {
    char pad[0x30];
    unsigned value;
    Effect_1c0a40* first;
    Effect_1c0a40* second;
    char gap[0x10];
    Context* context;
    void FUN_001c0360(int, int);
    int FUN_001c0a40(Context* arg);
};
extern "C" unsigned __int64 __cdecl compute_002672f0(int, int, int);
class Obj {
  public:
    void use_001c0650(int, unsigned __int64);
    void fn(int a, int b);
};


// 0x001be0e0 FUN_001be0e0 (69 B): matches/0x001be0e0.cpp
// sym: ?Find@Table@fn_fed79ca6@@QAEHUKey@2@@Z
int Table::Find(Key k) {
    int result = -1;
    for (int i = 0; i < count; i++) {
        if (items[i].key == *(__int64*)&k) {
            result = i;
            break;
        }
    }
    return result;
}

} // namespace fn_fed79ca6

// 0x001be170 FUN_001be170 (131 B): matches/0x001be170.cpp [wrapped: conflict: CSubtitleOverlay]
// sym: ??0CSubtitleOverlay@fn_001be170@@QAE@XZ
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_001be170 {

int Push_00266da0(int) throw();

struct CDropShadowDisplayEffect_1be170 {
    void Init_000dee40() throw();
};
struct Node2_1be170 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int, bool);
};
struct Shader_1be170 {
    int pad[3];
    Node2_1be170* c;
    int pad2[3];
    virtual void init();
    Shader_1be170() throw();
};
class Overlay_1be170 {
  public:
    virtual void f0();
    bool b4;
    Overlay_1be170() throw() { b4 = true; }
};
class CSubtitleOverlay : public Overlay_1be170 {
  public:
    int m8;
    char mc;
    int m10;
    int m14;
    Shader_1be170* m18;
    char pad[0x11c - 0x1c];
    char b11c;
    char b11d;
    char pad2[2];
    CDropShadowDisplayEffect_1be170 sub;
    virtual void f0();
    CSubtitleOverlay() throw();
};
CSubtitleOverlay::CSubtitleOverlay() throw() {
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    b11c = 0;
    b11d = 0;
    sub.Init_000dee40();
    int old = Push_00266da0(0xe);
    m18 = new Shader_1be170;
    m18->init();
    Shader_1be170* q = m18;
    q->c->v6(0x444d4c42, true);
    Push_00266da0(old);
}
} // namespace fn_001be170


// 0x001be200 CSubtitleOverlay::vfunc_1 (8 B): matches/0x001be200.cpp
// sym: ?vfunc_1@CSubtitleOverlay@@UAEXXZ
void CSubtitleOverlay::vfunc_1() {
    *((char*)this + 0x11d) = 1;
}


// 0x001be210 CSubtitleOverlay::vfunc_2 (8 B): matches/0x001be210.cpp
// sym: ?vfunc_2@CSubtitleOverlay@@UAEXXZ
void CSubtitleOverlay::vfunc_2() {
    this->f_11d = 0;
}

namespace fn_fed79ca6 {

// 0x001be260 FUN_001be260 (355 B): equivalent/0x001be260.cpp
// sym: ?FUN_001be260@Quad_1be260@fn_fed79ca6@@QAEXXZ @33ba7fe919d2 @web21514ecb22
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_001be260 @ 0x001be260
void Quad_1be260::FUN_001be260()
{
    DAT_0052c2a8->ve8(0);
    (*(DeviceHolder**)&DAT_0052c2ac)->device->v3c(0);
    (*(DeviceHolder**)&DAT_0052c2ac)->FUN_00293d00(((char*)&DAT_004e2308));
    Builder* b = DAT_0052c2a8->v78(layer->handle, 1, 0x2020, 4, 0);
    float left = DAT_004c4c4c * (*(float*)&DAT_003f3db0);
    float top = size * (*(float*)&DAT_003f3db0);
    float right = DAT_004c4c4c * (*(float*)&DAT_003f32f4);
    float bottom = size * (*(float*)&DAT_003f32f4);
    {
        float* p = b->pos;
        p[1] = top;
        p[0] = left;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    {
        float* p = b->pos;
        p[0] = left;
        p[1] = bottom;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    {
        float* p = b->pos;
        p[0] = right;
        p[1] = top;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    {
        float* p = b->pos;
        p[0] = right;
        p[1] = bottom;
        p[2] = 0;
        b->color[0] = 0x7f000000;
        b->FUN_0008ef00();
    }
    DAT_0052c2a8->v7c(b);
    (*(DeviceHolder**)&DAT_0052c2ac)->device->v40(0);
    DAT_0052c2a8->ve8(1);
}

// 0x001be400 thunk_FUN_001d04a0 (5 B): not yet verified

// 0x001be490 FUN_001be490 (25 B): matches/0x001be490.cpp
// sym: ?Reset@Outer_1be490@fn_fed79ca6@@QAEXXZ
void Outer_1be490::Reset() {
    Inner_1be490* x = p;
    q = 0;
    x->b = 0;
    x->c = 0;
    x->a = 0;
    x->d = 0;
    x->f = 0;
}

} // namespace fn_fed79ca6

// 0x001be4b0 FUN_001be4b0 (820 B): equivalent/0x001be4b0.cpp [wrapped: conflict: Gfx; Overlay]
// sym: ?FUN_001be4b0@Overlay@fn_001be4b0@@QAEXH@Z @a86a0cf25440 @w7ba0268b6800
namespace fn_001be4b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 14/14)
// FUN_001be4b0 @ 0x001be4b0
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

struct Vec3_1be4b0 { float x, y, z; };

struct Owner;

struct Slot_1be4b0 {
    float weight;
    int a;
    int b;
    int value;
};

struct Blender_1be4b0 {
    Owner* owner;
    int current;
    Slot_1be4b0 slots[8];
    int index;
    float scale;
    Blender_1be4b0* FUN_000f7fe0(Owner* o);
    void FUN_000f81b0(int v, int font, int flag);
    void FUN_000f87c0(int v, int font, int flag);
    void FUN_000f78e0();
};

struct Poly {
    char pad00[8];
    Vec3_1be4b0* pos;
    char pad0c[4];
    int* color;
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
    virtual void v24(int mode);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Poly* v30(int a, int b, int c, int d, int e);
    virtual void v31(Poly* p);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int a);
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int a);
    virtual char v59();
};
class Viewport_1be4b0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual float v16();
};
class Layer_1be4b0 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
};

struct Canvas {
    Layer_1be4b0* layer;
    void FUN_00293d00(Vec3_1be4b0* v);
    void FUN_00293da0(float x, float y, float z);
};

struct Panel_1be4b0 {
    char pad00[0x10];
    int f10;
};


class Overlay {
  public:
    char pad0[0x18];
    int current;
    int count;
    char pad20[8];
    int* items;
    char pad2c[0x38 - 0x2c];
    Owner* ref;
    char pad3c[0x44 - 0x3c];
    Owner* owner;
    char pad48[8];
    int alpha;
    char b54;
    char b55;
    char pad56[2];
    Panel_1be4b0* panel;
    void FUN_001be4b0(int index);
};

void Overlay::FUN_001be4b0(int index)
{
    struct Frame {
        float width;
        float tmp;
        Vec3_1be4b0 v;
        int saved55;
        union {
            char c;
            int i;
        } mode;
        int savedMode;
        float rightA;
        char pad_ac[0xc];
        float rightB;
        char pad_a0[8];
        Blender_1be4b0 b;
    } f;
    if (owner == 0)
        return;
    f.b.FUN_000f7fe0(owner);
    char wide;
    if (b54 && owner == ref)
        wide = 1;
    else
        wide = (*(Viewport_1be4b0**)&DAT_0052c2a4)->v16() > 1.5f;
    f.savedMode = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    f.saved55 = DAT_0052c2a8->v55();
    DAT_0052c2a8->v54(0);
    f.mode.c = DAT_0052c2a8->v59();
    DAT_0052c2a8->v58(0);
    f.width = (float)(*(Viewport_1be4b0**)&DAT_0052c2a4)->v7();
    f.tmp = (float)(*(Viewport_1be4b0**)&DAT_0052c2a4)->v6();
    f.b.slots[f.b.index].weight = DAT_004c4c28 * DAT_004c4c1c;
    f.b.slots[f.b.index].a = 1;
    f.b.slots[f.b.index].b = 3;
    f.b.slots[f.b.index].value = (alpha << 24) | 0xffffff;
    f.b.scale = (*(float*)&DAT_004c4c18);
    (*(Canvas**)&DAT_0052c2ac)->layer->v21(0);
    f.width = f.width * 0.5f;
    f.v.x = f.width;
    if (b55) {
        f.v.z = (*(float*)&DAT_004c4c2c);
        f.v.y = f.tmp - DAT_004c4c24;
    } else {
        f.v.z = (*(float*)&DAT_004c4c2c);
        f.v.y = f.tmp - DAT_004c4c20;
    }
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(1.0f, -1.0f, 1.0f);
    if (wide) {
        Poly* p = DAT_0052c2a8->v30(panel->f10, 1, 0x2020, 4, 0);
        float left = f.width * -0.8f;
        float right = f.width * 0.8f;
        Vec3_1be4b0* pv = p->pos;
        pv->y = -4.0f;
        pv->z = 0.0f;
        f.rightA = right;
        f.v.x = left;
        f.rightB = right;
        pv->x = left;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        pv = p->pos;
        pv->x = f.v.x;
        pv->y = 29.0f;
        pv->z = 0.0f;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        pv = p->pos;
        pv->x = f.rightA;
        pv->y = -4.0f;
        pv->z = 0.0f;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        pv = p->pos;
        pv->x = f.rightB;
        pv->y = 29.0f;
        pv->z = 0.0f;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        DAT_0052c2a8->v31(p);
    }
    if (count > 1)
        f.b.FUN_000f81b0(items[current], (*(int*)&DAT_004e22f0), 0);
    else
        f.b.FUN_000f87c0(index, (*(int*)&DAT_004e22f0), 0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    DAT_0052c2a8->v24(f.savedMode);
    DAT_0052c2a8->v54(f.saved55);
    DAT_0052c2a8->v58(f.mode.i);
    f.b.FUN_000f78e0();
}
} // namespace fn_001be4b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001be7f0 FUN_001be7f0 (507 B): equivalent/0x001be7f0.cpp [wrapped: conflict: Canvas; Gfx; Overlay]
// sym: ?FUN_001be7f0@Overlay@fn_001be7f0@@QAEXH@Z @dd80bea84fda @w8edb879ee5a6
namespace fn_001be7f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 4/4)
// FUN_001be7f0 @ 0x001be7f0
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

struct Vec3_1be7f0 { float x, y, z; };

struct Owner;

struct Slot_1be7f0 {
    float weight;
    int a;
    int b;
    int value;
};

struct Blender_1be7f0 {
    Owner* owner;
    int current;
    Slot_1be7f0 slots[8];
    int index;
    float scale;
    Blender_1be7f0* FUN_000f7fe0(Owner* o);
    void FUN_000f81b0(int v, int font, int flag);
    void FUN_000f87c0(int v, int font, int flag);
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
    virtual void v24(int mode);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int a);
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int a);
    virtual char v59();
};

class Viewport_1be7f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};

class Layer_1be7f0 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
};

struct Canvas {
    Layer_1be7f0* layer;
    void FUN_00293d00(Vec3_1be7f0* v);
    void FUN_00293da0(float x, float y, float z);
};


class Overlay {
  public:
    char pad0[0x18];
    int current;
    int count;
    char pad20[8];
    int* items;
    char pad2c[0x44 - 0x2c];
    Owner* owner;
    char pad48[8];
    int alpha;
    void FUN_001be7f0(int index);
};

void Overlay::FUN_001be7f0(int index)
{
    struct Frame {
        float tmp;
        union {
            char c;
            int i;
        } mode;
        float width;
        Vec3_1be7f0 v;
        Blender_1be7f0 b;
    } f;
    if (owner == 0)
        return;
    int savedMode = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    int saved55 = DAT_0052c2a8->v55();
    DAT_0052c2a8->v54(0);
    f.mode.c = DAT_0052c2a8->v59();
    DAT_0052c2a8->v58(0);
    f.b.FUN_000f7fe0(owner);
    f.b.slots[f.b.index].weight = DAT_004c4c34 * DAT_004c4c1c;
    f.b.slots[f.b.index].a = 1;
    f.b.slots[f.b.index].b = 3;
    f.b.slots[f.b.index].value = (alpha << 24) | 0xffffff;
    f.b.scale = (*(float*)&DAT_004c4c18);
    f.width = (float)(*(Viewport_1be7f0**)&DAT_0052c2a4)->v7();
    f.tmp = (float)(*(Viewport_1be7f0**)&DAT_0052c2a4)->v6();
    (*(Canvas**)&DAT_0052c2ac)->layer->v21(0);
    f.v.x = f.width * 0.5f;
    f.v.z = (*(float*)&DAT_004c4c38);
    f.v.y = f.tmp - DAT_004c4c20;
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(1.0f, -1.0f, 1.0f);
    if (count > 1)
        f.b.FUN_000f81b0(items[current], (*(int*)&DAT_004e22f0), 0);
    else
        f.b.FUN_000f87c0(index, (*(int*)&DAT_004e22f0), 0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    DAT_0052c2a8->v24(savedMode);
    DAT_0052c2a8->v54(saved55);
    DAT_0052c2a8->v58(f.mode.i);
    f.b.FUN_000f78e0();
}
} // namespace fn_001be7f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001be9f0 FUN_001be9f0 (140 B): equivalent/0x001be9f0.cpp [wrapped: conflict: FUN_002672f0; FUN_0027b020]
// sym: ?FUN_001be9f0@BindingTable@fn_001be9f0@@QAEXPBD0M@Z @966d1d186fda @w033a0bbbfc7c
namespace fn_001be9f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001be9f0 @ 0x001be9f0
// Register a (name id, value id) -> float binding unless the name id is already known or the table is full.
struct Id64_1be9f0 {
    unsigned int lo;
    unsigned int hi;
};

extern "C++" __declspec(nothrow) Id64_1be9f0 __cdecl FUN_002672f0(const char* name, int a, int b);
extern "C++" __declspec(nothrow) Id64_1be9f0 __cdecl FUN_0027b020(const char* name);

struct Binding_1be9f0 {
    Id64_1be9f0 name;
    Id64_1be9f0 value;
    float amount;
    int pad14;
};

class BindingTable {
public:
    char pad0[0x3c];
    Binding_1be9f0* items;
    int count;

    int FUN_001be0e0(unsigned int lo, unsigned int hi);
    void FUN_001be9f0(const char* name, const char* valueName, float amount);
};

void BindingTable::FUN_001be9f0(const char* name, const char* valueName, float amount)
{
    if (count >= 0x47e) {
        return;
    }
    Id64_1be9f0 key = FUN_002672f0(name, 0, 0);
    Id64_1be9f0 value = FUN_0027b020(valueName);
    if (FUN_001be0e0(key.lo, key.hi) == -1) {
        items[count].name.lo = key.lo;
        items[count].name.hi = key.hi;
        items[count].value.lo = value.lo;
        items[count].value.hi = value.hi;
        items[count].amount = amount;
        count = count + 1;
    }
}
} // namespace fn_001be9f0

namespace fn_fed79ca6 {

// 0x001bee10 FUN_001bee10 (332 B): equivalent/0x001bee10.cpp
// sym: ?FUN_001bee10@Effect_1bee10@fn_fed79ca6@@QAEHXZ @0b3c77af49bc @w605c2c6cd930
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 9/10, incomplete)
// FUN_001bee10 @ 0x001bee10
int Effect_1bee10::FUN_001bee10()
{
    int result = 1;
    if (owner == 0)
        return result;

    Blender_1bee10 b;
    b.FUN_000f7fe0(owner);
    b.slots[b.index].weight = DAT_004c4c1c;
    b.slots[b.index].a = 1;
    b.slots[b.index].b = 3;
    b.scale = (*(float*)&DAT_004c4c18);
    int r = owner->FUN_000f7240(keyA, keyB);
    if (r != -1) {
        float num;
        switch (mode) {
        case 0:
            b.slots[b.index].weight = DAT_004c4c28 * DAT_004c4c1c;
            num = DAT_004c4c30;
            break;
        case 1:
            b.slots[b.index].weight = DAT_004c4c34 * DAT_004c4c1c;
            num = DAT_004c4c3c;
            break;
        case 2:
            b.slots[b.index].weight = DAT_004c4c44 * DAT_004c4c40;
            num = DAT_004c4c48;
            break;
        default:
            b.FUN_000f78e0();
            return result;
        }
        float t = num / b.slots[b.index].weight;
        int extra = b.owner->values[(*(int*)&DAT_004e22f0)];
        int value = ((int)((owners::C_f7220 *)owner)->FUN_000f7220((hulk_intptr)r));
        result = FUN_000fba10(handle, 10, 0x80, value, t, extra);
    }
    b.FUN_000f78e0();
    return result;
}


// 0x001bef80 FUN_001bef80 (36 B): matches/0x001bef80.cpp
// sym: ??1CSubtitleOverlay_1bef80@fn_fed79ca6@@QAE@XZ
CSubtitleOverlay_1bef80::~CSubtitleOverlay_1bef80() throw() {
    vptr = hulk_at_0042147c;
    _ReadWriteBarrier();
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    vptr = g_vftable2;
}


// 0x001befb0 CSubtitleOverlay::vfunc_4 (263 B): equivalent/0x001befb0.cpp
// sym: ?vfunc_4@CSubtitleOverlay_1befb0@fn_fed79ca6@@UAEXXZ @485424b1c9e3 @wd6e4bf83885b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSubtitleOverlay::vfunc_4 @ 0x001befb0
void CSubtitleOverlay_1befb0::vfunc_4() {
 union {float f; unsigned u;} v; v.f=visibility; v.u &= 0x7fffffff;
 if (v.f <= 1e-05f) return;
 if (!text) return;
 TextBuilder builder; builder.FUN_000f7fe0(text);
 builder.entries[builder.count].size=DAT_004c4c44*DAT_004c4c40;
 builder.entries[builder.count].b=2;
 builder.entries[builder.count].a=1;
 builder.scale=(*(float*)&DAT_004c4c18);
 builder.entries[builder.count].color=(alpha<<24)|0x1ed2dc;
 FUN_001be260();
 (*(RenderContext**)&DAT_0052c2ac)->device->s15(0);
 (*(RenderContext**)&DAT_0052c2ac)->FUN_00293d00(((char*)&DAT_004e2308));
 builder.FUN_000f81b0(textData,(*(int*)&DAT_004e22f0),position);
 (*(RenderContext**)&DAT_0052c2ac)->device->s16(0);
 builder.FUN_000f78e0();
}

} // namespace fn_fed79ca6

// 0x001bf0c0 FUN_001bf0c0 (624 B): equivalent/0x001bf0c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001bf0c0@Fader_1bf0c0@fn_001bf0c0@@QAEXM@Z @89aabb2f27f9 @w03236053cada
namespace fn_001bf0c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 30/30)
// FUN_001bf0c0 @ 0x001bf0c0
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


struct Owner_1bf0c0 { char pad[0x24]; int values[1]; };
struct Slot_1bf0c0 { float weight; int a; int b; int value; };
struct Blender_1bf0c0 {
    Owner_1bf0c0 *owner; int current; Slot_1bf0c0 slots[8]; int index; float scale;
    Blender_1bf0c0 *FUN_000f7fe0(Owner_1bf0c0 *o);
    void FUN_000f78e0();
    hulk_freg FUN_000d4900(void *p, int k);
};
struct Sink_1bf0c0 {
    hulk_freg FUN_000d6d90(void *who);
    void FUN_000d6dd0(void *who);
};
struct Holder_1bf0c0 { Sink_1bf0c0 *FUN_000862b0(); };
struct World { char pad[0x54]; Holder_1bf0c0 *holder; };

union FBits_1bf0c0 { float f; unsigned u; };

static float absf(float v)
{
    FBits_1bf0c0 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class Fader_1bf0c0 {
public:
    char pad0[8];
    Owner_1bf0c0 *owner;
    bool active;
    char pad0d[3];
    float level;
    int alpha;
    char pad18[4];
    char target[0x100];
    bool started;

    void FUN_001bf0c0(float dt);
};

void Fader_1bf0c0::FUN_001bf0c0(float dt)
{
    if ((active || !(absf(level) <= (*(float*)&DAT_0042144c))) && !started) {
        DAT_004dd700->holder->FUN_000862b0()->FUN_000d6d90(this);
        started = true;
        alpha = 0;
    }
    if (active && owner != 0) {
        Blender_1bf0c0 b;
        b.FUN_000f7fe0(owner);
        b.slots[b.index].weight = DAT_004c4c44 * DAT_004c4c40;
        b.slots[b.index].b = 2;
        b.slots[b.index].a = 1;
        b.scale = (*(float*)&DAT_004c4c18);
        DAT_004e22f8 = b.FUN_000d4900(target, (*(int*)&DAT_004e22f0)) * (*(float*)&DAT_0040a4b4);
        b.FUN_000f78e0();
        float diff = absf(level - DAT_004e22f8);
        if (!(diff <= (*(float*)&DAT_0042144c))) {
            level = DAT_004c4c54 * dt + level;
            if (!(level < DAT_004e22f8))
                level = DAT_004e22f8;
        } else {
            level = DAT_004e22f8;
            if (alpha < 0xff) {
                alpha += 0x14;
                if (alpha > 0xff)
                    alpha = 0xff;
            }
        }
        return;
    }
    if (absf(level) <= (*(float*)&DAT_0042144c)) {
        level = 0;
        DAT_004dd700->holder->FUN_000862b0()->FUN_000d6dd0(this);
        alpha = 0;
        started = false;
        return;
    }
    if (alpha > 0) {
        alpha -= 10;
        if (alpha < 0)
            alpha = 0;
    }
    if (alpha == 0) {
        level = level - DAT_004c4c54 * dt;
        if (!((*(float*)&DAT_003f32e0) < level))
            level = (*(float*)&DAT_003f32e0);
        if (absf(level) <= (*(float*)&DAT_0042144c)) {
            DAT_004dd700->holder->FUN_000862b0()->FUN_000d6dd0(this);
            started = false;
        }
    }
}
} // namespace fn_001bf0c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bf380 Method2<CSubtitleManager,void,int,int>::vfunc_0 (30 B): matches/0x001bf380.cpp
// sym: ??_G?$Method2@VCSubtitleManager@@XHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSubtitleManager, void, int, int>::~Method2() {}


// 0x001bf3a0 Method2<CSubtitleManager,void,int,int>::vfunc_2 (23 B): matches/0x001bf3a0.cpp
// sym: ?vfunc_2@?$Method2@VCSubtitleManager@@XHH@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSubtitleManager, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1bf3a0* m = (CFEManager_1bf3a0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1bf3a0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSubtitleManager, void, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf380)
#endif


// 0x001bf400 Method1<CSubtitleManager,void,bool>::vfunc_0 (30 B): matches/0x001bf400.cpp
// sym: ??_G?$Method1@VCSubtitleManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSubtitleManager, void, bool>::~Method1() {}


// 0x001bf420 Method1<CSubtitleManager,void,bool>::vfunc_2 (21 B): matches/0x001bf420.cpp
// sym: ?vfunc_2@?$Method1@VCSubtitleManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CSubtitleManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1bf420 * obj = (CActorManager_1bf420 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1bf420 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSubtitleManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf400)
#endif


// 0x001bf480 Method1<CSubtitleManager,void,int>::vfunc_0 (30 B): matches/0x001bf480.cpp
// sym: ??_G?$Method1@VCSubtitleManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSubtitleManager, void, int>::~Method1() {}


// 0x001bf4a0 Method1<CSubtitleManager,void,int>::vfunc_2 (19 B): matches/0x001bf4a0.cpp
// sym: ?vfunc_2@?$Method1@VCSubtitleManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSubtitleManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1bf4a0* d = (Dummy_1bf4a0*)a;
    (d->*(*(void (Dummy_1bf4a0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSubtitleManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf480)
#endif

namespace fn_fed79ca6 {

// 0x001bf4c0 FUN_001bf4c0 (102 B): matches/0x001bf4c0.cpp
// sym: ?FUN_001bf4c0@Method4_1bf4c0@fn_fed79ca6@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
// FUN_001bf4c0 @ 0x001bf4c0
// Method4's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
Method4_1bf4c0* Method4_1bf4c0::FUN_001bf4c0(const char* name, ScriptMemberFn m) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_004214d0;
    fn = m;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}

} // namespace fn_fed79ca6

// 0x001bf530 Method4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_0 (30 B): matches/0x001bf530.cpp
// sym: ??_G?$Method4@VCSubtitleManager@@XHMPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSubtitleManager, void, int, float, const char *, float>::~Method4() {}


// 0x001bf550 Method4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 (46 B): equivalent/0x001bf550.cpp
// sym: ?vfunc_2@?$Method4@VCSubtitleManager@@XHMPBDM@@UAEXPAX00@Z @06f2e20faa8a @w46d3e918715f
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 @ 0x001bf550
template <> void Method4<CSubtitleManager, void, int, float, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSubtitleManager_1bf550 * manager = (CSubtitleManager_1bf550 *)__p0; SubtitleArgs * arguments = (SubtitleArgs *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSubtitleManager_1bf550::**)(int, float, const char *, float))&this->f_1c))(arguments->number, arguments->start, arguments->text, arguments->end);
}
#if defined(HULK_PTR64)
template class Method4<CSubtitleManager, void, int, float, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf530)
#endif


// 0x001bf5d0 Method2<CSubtitleManager,void,int,const_char_*>::vfunc_0 (30 B): matches/0x001bf5d0.cpp
// sym: ??_G?$Method2@VCSubtitleManager@@XHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSubtitleManager, void, int, const char *>::~Method2() {}


// 0x001bf5f0 Method2<CSubtitleManager,void,int,const_char_*>::vfunc_2 (23 B): matches/0x001bf5f0.cpp
// sym: ?vfunc_2@?$Method2@VCSubtitleManager@@XHH@@UAEXPAX00@Z
template <> void Method2<CSubtitleManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr manager = (hulk_intptr)__p0; int * pair = (int *)__p1; hulk_intptr a = (hulk_intptr)__p2;

    int x = pair[0];
    int y = pair[1];
    CSubtitleManager_1bf5f0* m = (CSubtitleManager_1bf5f0*)manager;
    (m->*(*(void (CSubtitleManager_1bf5f0::**)(int, int))&this->f_1c))(x, y);
}
#if defined(HULK_PTR64)
template class Method2<CSubtitleManager, void, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf5d0)
#endif


// 0x001bf650 Method0<CSubtitleManager,bool>::vfunc_0 (30 B): matches/0x001bf650.cpp
// sym: ??_G?$Method0@VCSubtitleManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CSubtitleManager, bool>::~Method0() {}


// 0x001bf670 Method0<CSubtitleManager,bool>::vfunc_2 (22 B): matches/0x001bf670.cpp
// sym: ?vfunc_2@?$Method0@VCSubtitleManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CSubtitleManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1bf670 * obj = (CActorManager_1bf670 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_1bf670 fn = (*(Fn_1bf670 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method0<CSubtitleManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf650)
#endif


// 0x001bf6d0 Method1<CSubtitleManager,void,float>::vfunc_0 (30 B): matches/0x001bf6d0.cpp
// sym: ??_G?$Method1@VCSubtitleManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSubtitleManager, void, float>::~Method1() {}


// 0x001bf6f0 Method1<CSubtitleManager,void,float>::vfunc_2 (19 B): matches/0x001bf6f0.cpp
// sym: ?vfunc_2@?$Method1@VCSubtitleManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSubtitleManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1bf6f0* d = (Dummy_1bf6f0*)a;
    (d->*(*(void (Dummy_1bf6f0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSubtitleManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf6d0)
#endif


// 0x001bf710 FUN_001bf710 (89 B): matches/0x001bf710.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_001bf710@@QAE@HH@Z
namespace fn_001bf710 {

extern "C++" __declspec(nothrow) char __cdecl ReadFlag_001d04d0(const char*);
class Function_1bf710 {
  public:
    Function_1bf710(int, int);
    virtual void Fn();
    char pad[0xc];
    char f10, f11, f12;
    char pad2[5];
    char f18;
    char pad3[3];
    int field;
};
class Method3 : public Function_1bf710 {
  public:
    Method3(hulk_intptr, hulk_intptr);
    virtual void Fn();
};
Method3::Method3(hulk_intptr a, hulk_intptr b) : Function_1bf710(a, 3) {
    field = b;
    f18 = ReadFlag_001d04d0(((char*)&DAT_0048e100));
    f10 = ReadFlag_001d04d0(((char*)&DAT_0048e128));
    f11 = ReadFlag_001d04d0(((char*)&DAT_0048e128));
    f12 = ReadFlag_001d04d0(((char*)&DAT_0048e128));
}
} // namespace fn_001bf710


// 0x001bf770 Method3<CSubtitleManager,void,float,float,float>::vfunc_0 (30 B): matches/0x001bf770.cpp
// sym: ??_G?$Method3@VCSubtitleManager@@XMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSubtitleManager, void, float, float, float>::~Method3() {}


// 0x001bf790 Method3<CSubtitleManager,void,float,float,float>::vfunc_2 (35 B): matches/0x001bf790.cpp
// sym: ?vfunc_2@?$Method3@VCSubtitleManager@@XMMM@@UAEXPAX00@Z
template <> void Method3<CSubtitleManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSubtitleManager_1bf790 * manager = (CSubtitleManager_1bf790 *)__p0; const Float3 * values = (const Float3 *)__p1; void * unused = (void *)__p2;

    const Float3* v = values;
    volatile unsigned int& x = *(volatile unsigned int*)&values;
    x = *(const unsigned int*)&v->x;
    (manager->*(*(void (CSubtitleManager_1bf790::**)(float, float, float))&this->f_1c))(*(float*)&values, v->y, v->z);
}
#if defined(HULK_PTR64)
template class Method3<CSubtitleManager, void, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf770)
#endif

namespace fn_fed79ca6 {

// 0x001bf7c0 FUN_001bf7c0 (89 B): matches/0x001bf7c0.cpp
// sym: ?Setup@Method3_1bf7c0@fn_fed79ca6@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
// Method3's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
Method3_1bf7c0* Method3_1bf7c0::Setup(const char* a, ScriptMemberFn b) {
    Init_001d0480(a, 3);
    vptr = ((hulk_intptr)DAT_00421520);
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_fed79ca6

// 0x001bf820 Method3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x001bf820.cpp
// sym: ??_G?$Method3@VCSubtitleManager@@XPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSubtitleManager, void, const char *, const char *, float>::~Method3() {}


// 0x001bf840 Method3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 (29 B): equivalent/0x001bf840.cpp
// sym: ?vfunc_2@?$Method3@VCSubtitleManager@@XPBDPBDM@@UAEXPAX00@Z @a7a6d240b96d @w7a58705a9035
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x001bf840
template <> void Method3<CSubtitleManager, void, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSubtitleManager_1bf840 * manager = (CSubtitleManager_1bf840 *)__p0; Arguments * args = (Arguments *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSubtitleManager_1bf840::**)(const char *, const char *, float))&this->f_1c))(args->first, args->second, args->third);
}
#if defined(HULK_PTR64)
template class Method3<CSubtitleManager, void, const char *, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bf820)
#endif

namespace fn_fed79ca6 {

// 0x001bf860 FUN_001bf860 (65 B): matches/0x001bf860.cpp
// sym: ?Reset@Obj_1bf860@fn_fed79ca6@@QAEXD@Z
void Obj_1bf860::Reset(char b) {
    f4 = 0;
    f0 = 0xbf800000;
    fD = 0;
    f24 = 0;
    f55 = 0;
    if (f20 == 2)
        f2C->fC = 0;
    if (b) {
        f50 = 0;
        Sub_1bf860* s = f2C;
        s->fC = 0;
        s->f10 = 0;
        s->f8 = 0;
        s->f14 = 0;
        s->f1c = 0;
    }
}


// 0x001bf8b0 FUN_001bf8b0 (162 B): equivalent/0x001bf8b0.cpp
// sym: ?FUN_001bf8b0@Handler_1bf8b0@fn_fed79ca6@@QAEXXZ @37c8d28873ec @wd1c1e50c339d
// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 31/32, incomplete)
// FUN_001bf8b0 @ 0x001bf8b0
void Handler_1bf8b0::FUN_001bf8b0()
{
    if (enabled && trackA && trackB) {
        if (mode == 0)
            FUN_001bea80();
        else if (mode == 1)
            FUN_001bec90();
    }

    if (active && (forced || pending)) {
        int r;
        if (!trackA && !trackB)
            return;
        bool found = false;
        if (trackA) {
            r = trackA->FUN_000f7240(keyA, keyB);
            found = (r != -1);
        }
        if (!found) {
            if (!trackB)
                return;
            r = trackB->FUN_000f7240(keyA, keyB);
            if (r == -1)
                return;
        }
        if (mode == 0)
            FUN_001be4b0(r);
        else if (mode == 1)
            FUN_001be7f0(r);
    }
}


// 0x001bf9b0 FUN_001bf9b0 (631 B): equivalent/0x001bf9b0.cpp
// sym: ?FUN_001bf9b0@Track@fn_fed79ca6@@QAEXXZ @65f74749ad71 @w0404d650a7e5
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 53/58, incomplete)
// FUN_001bf9b0 @ 0x001bf9b0
void Track::FUN_001bf9b0()
{
    int i = 0;
    float prevEnd = -1.0f;
    if (count <= 0)
        return;
    do {
        Key_1bf9b0 *k = &keys[i];
        float t0 = k->t;
        float t1 = DAT_004c4c10 + t0;
        if (k->dur > 0.0f) {
            t1 = t0 + k->dur;
        } else if (i >= count - 1) {
            t1 = DAT_004c4c14 + t0;
        } else {
            if (k[1].t > t1)
                t1 = k[1].t;
        }
        if (t0 > -1.0f) {
            if (!active) {
                if (time >= t0 && time > prevEnd) {
                    active = true;
                    keyA = k->a;
                    keyB = k->b;
                    int r = -1;
                    if (ownerA != 0) {
                        r = ownerA->FUN_000f7240(keyA, keyB);
                        if (r != -1) {
                            current = ownerA;
                            if (sink != 0)
                                sink->owner = ownerA;
                        }
                    }
                    if (r == -1) {
                        if (ownerB != 0) {
                            r = ownerB->FUN_000f7240(keyA, keyB);
                            if (r == -1) {
                                current = 0;
                                if (sink != 0)
                                    sink->owner = 0;
                                return;
                            }
                            current = ownerB;
                            if (sink != 0)
                                sink->owner = ownerB;
                        }
                    }
                    if (r == -1) {
                        current = 0;
                        if (sink != 0)
                            sink->owner = 0;
                        return;
                    }
                    subIndex = 0;
                    subCount = 1;
                    subCount = FUN_001bee10();
                }
            }
            if (active) {
                int c = subCount;
                if (c > 1) {
                    int step = subIndex + 1;
                    if (t0 + (t1 - t0) / c * step < time && subIndex < c - 1)
                        subIndex = step;
                }
            }
            if (time >= t1) {
                active = false;
                keys[i].t = -1.0f;
                if (i == count - 1 && busy == 0) {
                    count = 0;
                    time = -1.0f;
                    active = false;
                    pad24 = 0;
                    flag55 = 0;
                    if (mode == 2)
                        sink->flag = false;
                }
            }
            if (mode == 2) {
                sink->flag = active;
                if (active) {
                    if (subCount > 1) {
                        FUN_000fb690(&sink->sub, handles[subIndex], 0x80);
                    } else if (current != 0) {
                        int slot = current->FUN_000f7240(keyA, keyB);
                        FUN_000fb690(&sink->sub, ((int)((owners::C_f7220 *)current)->FUN_000f7220((hulk_intptr)slot)), 0x80);
                    }
                }
            }
        }
        prevEnd = t1;
        i++;
    } while (i < count);
}

} // namespace fn_fed79ca6

// 0x001bfc30 sSubtitleManagerCallback::vfunc_1 (68 B): matches/0x001bfc30.cpp
// sym: ?vfunc_1@sSubtitleManagerCallback@@UAEXHH@Z
void sSubtitleManagerCallback::vfunc_1(int a, int b) {
    State_1bfc30* p = (*(State_1bfc30 * *)&this->f_04);
    if (p && p->query_001be0e0(a, b) != -1 && *(int*)((char*)p + 0x20) == 2) {
        *(u32_1bfc30*)((char*)p + 4) = 0;
        *(u32_1bfc30*)p = 0xbf800000;
        *((unsigned char*)p + 0xd) = 0;
        *((unsigned char*)p + 0x24) = 0;
        *((unsigned char*)p + 0x55) = 0;
        *((unsigned char*)(*(hulk_uintptr*)((char*)p + 0x2c)) + 0xc) = 0;
    }
}

namespace fn_fed79ca6 {

// 0x001bfc80 CSubtitleOverlay::vfunc_0 (56 B): matches/0x001bfc80.cpp
// sym: ?f0@CSubtitleOverlay_1bfc80@fn_fed79ca6@@QAEPAV12@E@Z
CSubtitleOverlay_1bfc80* CSubtitleOverlay_1bfc80::f0(unsigned char fl) {
    vptr = g_vftable_1bfc80;
    _ReadWriteBarrier();
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    vptr = g_vftable2;
    if (fl & 1)
        Free_0008d330(this);
    return this;
}

} // namespace fn_fed79ca6

// 0x001bfcc0 CSubtitleOverlay::vfunc_3 (167 B): equivalent/0x001bfcc0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_3@CSubtitleOverlay@fn_001bfcc0@@UAEXM@Z @8574aeae8576 @we389c51e7a71
namespace fn_001bfcc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// CSubtitleOverlay::vfunc_3 @ 0x001bfcc0
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

static float Abs(float v)
{
    union { float f; unsigned int u; } x;
    x.f = v;
    x.u &= 0x7fffffff;
    return x.f;
}

struct Clock_1bfcc0 { float FUN_00085f80(); };
struct World { char pad0[0x58]; Clock_1bfcc0 *clock; };

class Overlay {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(float dt);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[8];
    char active;              // 0xc
    char pad0d[3];
    float timer;              // 0x10
    char pad14[0x11d - 0x14];
    char hidden;              // 0x11d
    void FUN_001bf0c0(float dt);
};

class CSubtitleOverlay : public Overlay {
public:
    virtual void vfunc_3(float dt);
};

void CSubtitleOverlay::vfunc_3(float dt)
{
    if (hidden)
        return;
    if (!active && Abs(timer) <= 1e-5f)
        return;
    if (Abs(dt) <= 1e-5f) {
        dt = DAT_004dd700->clock->FUN_00085f80();
        if (dt < 0.1f) {
            FUN_001bf0c0(dt);
            return;
        }
        dt = 0.1f;
    }
    FUN_001bf0c0(dt);
}
} // namespace fn_001bfcc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bfd70 FUN_001bfd70 (89 B): matches/0x001bfd70.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001bfd70@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001bfd70 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_004214a0[2];
extern void* hulk_at_00421530[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_004214a0;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_00421530;
    owner = a2;
}
} // namespace fn_001bfd70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bfdd0 Closure2<CSubtitleManager,void,int,int>::vfunc_0 (30 B): matches/0x001bfdd0.cpp
// sym: ??_G?$Method1@VCSubtitleManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSubtitleManager, void, int, int>::~Closure2() {}


// 0x001bfdf0 Closure2<CSubtitleManager,void,int,int>::vfunc_2 (22 B): matches/0x001bfdf0.cpp
// sym: ?vfunc_2@?$Closure2@VCSubtitleManager@@XHH@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSubtitleManager, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1bfdf0 * p = (Pair_1bfdf0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1bfdf0 * *)&this->f_20)->*(*(void (CActorManager_1bfdf0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CSubtitleManager, void, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bfdd0)
#endif


// 0x001bfe10 FUN_001bfe10 (76 B): matches/0x001bfe10.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001bfe10@@QAE@PAX00@Z
namespace fn_001bfe10 {
// data: firstName = DAT_0048e100, secondName = DAT_0048e0e4

typedef unsigned int uint;
extern "C++" __declspec(nothrow) unsigned char __cdecl lookup_001d04d0(const char*);
class Function_1bfe10 {
  public:
    Function_1bfe10(void*, int);
    virtual void v0();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* p;
};
class Method1 : public Function_1bfe10 {
  public:
    Method1(void* x, void* z) : Function_1bfe10(x, 1) {
        p = z;
        b = lookup_001d04d0(((char*)&DAT_0048e100));
        a = lookup_001d04d0(((char*)&DAT_0048e0e4));
    }
    virtual void v0();
};
class Closure1 : public Method1 {
  public:
    void* q;
    Closure1(void*, void*, void*);
    virtual void v0();
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    q = y;
}
} // namespace fn_001bfe10


// 0x001bfe60 Closure1<CSubtitleManager,void,bool>::vfunc_0 (30 B): matches/0x001bfe60.cpp
// sym: ??_G?$Method2@VCSubtitleManager@@XHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSubtitleManager, void, bool>::~Closure1() {}


// 0x001bfe80 Closure1<CSubtitleManager,void,bool>::vfunc_2 (20 B): matches/0x001bfe80.cpp
// sym: ?vfunc_2@?$Closure1@VCSubtitleManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CSubtitleManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1bfe80 * *)&this->f_20)->*(*(void (Actor_1bfe80::**)(unsigned char))&this->f_1c))(*arg);
}
#if defined(HULK_PTR64)
template class Closure1<CSubtitleManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bfe60)
#endif


// 0x001bfea0 FUN_001bfea0 (76 B): matches/0x001bfea0.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0Closure1@fn_001bfea0@@QAE@PBDPAVCSubtitleManager@1@P8ScriptBoundClass@@AEXXZ@Z
namespace fn_001bfea0 {
// data: hulk_at_0048e100 = DAT_0048e100, hulk_at_0048e134 = DAT_0048e134

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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class CSubtitleManager;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char*);
};
Base::Base(const char* p) : CtorV_001d0480(p, 1) {
}
class Closure1_1bfea0 : public Base {
  public:
    virtual void call(int);
    ScriptMemberFn fn;
    Closure1_1bfea0(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_1bfea0 {
  public:
    virtual void call(int);
    CSubtitleManager* owner;
    Closure1(const char*, CSubtitleManager*, ScriptMemberFn);
};
Closure1_1bfea0::Closure1_1bfea0(const char* p, ScriptMemberFn m) : Base(p) {
    fn = m;
    retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}
Closure1::Closure1(const char* p, CSubtitleManager* o, ScriptMemberFn m) : Closure1_1bfea0(p, m) {
    owner = o;
}
} // namespace fn_001bfea0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bfef0 Closure1<CSubtitleManager,void,int>::vfunc_0 (30 B): matches/0x001bfef0.cpp
// sym: ??_G?$Method1@VCSubtitleManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSubtitleManager, void, int>::~Closure1() {}


// 0x001bff10 Closure1<CSubtitleManager,void,int>::vfunc_2 (18 B): matches/0x001bff10.cpp
// sym: ?vfunc_2@?$Closure1@VCSubtitleManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSubtitleManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1bff10 * *)&this->f_20)->*(*(void (CActorManager_1bff10::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CSubtitleManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bfef0)
#endif


// 0x001bff60 Closure4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_0 (30 B): matches/0x001bff60.cpp
// sym: ??_G?$Method3@VCSubtitleManager@@XPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CSubtitleManager, void, int, float, const char *, float>::~Closure4() {}


// 0x001bff80 Closure4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 (45 B): equivalent/0x001bff80.cpp
// sym: ?vfunc_2@?$Closure4@VCSubtitleManager@@XHMPBDM@@UAEXPAX00@Z @35da6a76506a @w1cb96e5ab494
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 @ 0x001bff80
template <> void Closure4<CSubtitleManager, void, int, float, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * arguments = (Arguments *)__p1; hulk_intptr other = (hulk_intptr)__p2;

    float time = arguments->time;
    ((*(CSubtitleManager_1bff80 * *)&this->f_20)->*(*(void (CSubtitleManager_1bff80::**)(int, float, const char *, float))&this->f_1c))(arguments->number, time, arguments->text, arguments->duration);
}
#if defined(HULK_PTR64)
template class Closure4<CSubtitleManager, void, int, float, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1bff60)
#endif


// 0x001bffb0 FUN_001bffb0 (89 B): matches/0x001bffb0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001bffb0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001bffb0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_004214e0[2];
extern void* hulk_at_00421570[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_004214e0;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_00421570;
    owner = a2;
}
} // namespace fn_001bffb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001c0030 Closure2<CSubtitleManager,void,int,const_char_*>::vfunc_2 (22 B): matches/0x001c0030.cpp
// sym: ?vfunc_2@?$Closure2@VCSubtitleManager@@XHH@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSubtitleManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1c0030 * p = (Pair_1c0030 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1c0030 * *)&this->f_20)->*(*(void (CActorManager_1c0030::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x001c00b0 Closure0<CSubtitleManager,bool>::vfunc_2 (23 B): matches/0x001c00b0.cpp
// sym: ?vfunc_2@?$Closure0@VCSubtitleManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CSubtitleManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_1c00b0* o = (*(CActorManager_1c00b0 * *)&this->f_20);
    Fn_1c00b0 fn = (*(Fn_1c00b0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}


// 0x001c00d0 FUN_001c00d0 (76 B): matches/0x001c00d0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001c00d0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001c00d0 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1c00d0 : public ScriptFunctionFields {
  public:
    Function_1c00d0(const char*, int);
    virtual void Run();
};
class Method1 : public Function_1c00d0 {
  public:
    Method1(const char* a, ScriptMemberFn c) : Function_1c00d0(a, 1) {
        p = c;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    }
    virtual void Run();
    ScriptMemberFn p;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* a, void* b, ScriptMemberFn c);
    virtual void Run();
    void* q;
};
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    q = b;
}
} // namespace fn_001c00d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001c0140 Closure1<CSubtitleManager,void,float>::vfunc_2 (18 B): matches/0x001c0140.cpp
// sym: ?vfunc_2@?$Closure1@VCSubtitleManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSubtitleManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1c0140 * *)&this->f_20)->*(*(void (CActorManager_1c0140::**)(const char *))&this->f_1c))(*b);
}


// 0x001c01b0 Closure3<CSubtitleManager,void,float,float,float>::vfunc_2 (34 B): equivalent/0x001c01b0.cpp
// sym: ?vfunc_2@?$Closure3@VCSubtitleManager@@XMMM@@UAEXPAX00@Z @737c210bc5da @waa2711c8626c
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSubtitleManager,void,float,float,float>::vfunc_2 @ 0x001c01b0
template <> void Closure3<CSubtitleManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const float * values = (const float *)__p1; void * unused2 = (void *)__p2;

    ((*(CSubtitleManager_1c01b0 * *)&this->f_20)->*(*(void (CSubtitleManager_1c01b0::**)(float, float, float))&this->f_1c))(values[0], values[1], values[2]);
}


// 0x001c0230 Closure3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 (28 B): equivalent/0x001c0230.cpp
// sym: ?vfunc_2@?$Closure3@VCSubtitleManager@@XPBDPBDM@@UAEXPAX00@Z @737c210bc5da @we909f5656d8a
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x001c0230
template <> void Closure3<CSubtitleManager, void, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const SubtitleArgs * args = (const SubtitleArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CSubtitleManager_1c0230 * *)&this->f_20)->*(*(void (CSubtitleManager_1c0230::**)(const char *, const char *, float))&this->f_1c))(args->first, args->second, args->time);
}


// 0x001c0250 FUN_001c0250 (271 B): equivalent/0x001c0250.cpp [wrapped: conflict: sSubtitleManagerCallback]
// sym: ?cleanup@Manager_1c0250@fn_001c0250@@QAEXXZ @ec0eef484f2f @wc5e8d7b862ba
namespace fn_001c0250 {
// STATUS: equivalent (tools/equiv.py level 3: 2181 inputs, branch coverage 22/22)
// FUN_001c0250 @ 0x001c0250
struct sSubtitleManagerCallback { virtual void slot0(); unsigned value; };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*,const void*,unsigned);
#endif

void __cdecl FUN_0008d330(void*);
void __cdecl FUN_0008d340(void*);
struct Item_1c0250 { virtual void destroy(unsigned); unsigned pad4; unsigned field8; unsigned char flagC; char padD[3]; unsigned field10, field14; char pad18[4]; unsigned short field1C; };
struct Resource_1c0250 { void FUN_000f6f60(); };
struct Last { virtual void slot0(); virtual void release(); };
struct Manager_1c0250 {
 float value; unsigned field4; void* field8; char padC; unsigned char flagD; char padE[18]; unsigned type; unsigned char flag24; char pad25[3]; void** entries; Item_1c0250* item; sSubtitleManagerCallback* callback; Resource_1c0250* resource34; Resource_1c0250* resource38; void* buffer; unsigned count; char pad44[12]; unsigned field50; char pad54; unsigned char flag55; char pad56[2]; Last* last;
 void cleanup();
};
void Manager_1c0250::cleanup() {
 field4=0; value=-1.0f; flagD=0; flag24=0; flag55=0;
 if(type==2) item->flagC=0;
 field50=0;
 Item_1c0250* p=item; p->flagC=0; p->field10=0; p->field8=0; p->field14=0; p->field1C=0;
 if(callback) { sSubtitleManagerCallback* c=callback; sSubtitleManagerCallback reset; reset.value=0; memcpy(c,&reset,sizeof(reset)); FUN_0008d330(c); callback=0; }
 if(item) { item->destroy(1); item=0; }
 void* b=buffer; count=0; if(b) { FUN_0008d340(b); buffer=0; }
 Resource_1c0250* r=resource38; if(r) { r->FUN_000f6f60(); FUN_0008d330(r); resource38=0; }
 r=resource34; if(r) { r->FUN_000f6f60(); FUN_0008d330(r); resource34=0; }
 if(field8) { FUN_0008d340(field8); field8=0; }
 for(int i=0;i<10;++i) { if(entries[i]) { FUN_0008d340(entries[i]); entries[i]=0; } }
 if(entries) { FUN_0008d340(entries); entries=0; }
 if(last) { last->release(); last=0; }
}
} // namespace fn_001c0250

namespace fn_fed79ca6 {

// 0x001c0360 FUN_001c0360 (383 B): equivalent/0x001c0360.cpp
// sym: ?FUN_001c0360@Shake_1c0360@fn_fed79ca6@@QAEXHH@Z @32b8ff1d3dc0 @w89caf8b7033f
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 18/18)
// FUN_001c0360 @ 0x001c0360
void Shake_1c0360::FUN_001c0360(int newMode, int newCount)
{
    if (entries != 0 || count != 0) {
        count = 0;
        value = -1.0f;
        flag0d = 0;
        flag24 = 0;
        flag55 = 0;
        if (mode == 2)
            child->flag0c = 0;
        Child_1c0360 *c = child;
        field50 = 0;
        c->flag0c = 0;
        c->field10 = 0;
        c->field08 = 0;
        c->field14 = 0;
        c->word1c = 0;
    }
    mode = newMode;
    value = -1.0f;
    if (newCount > 0x46)
        return;
    count = newCount;
    for (int i = 0; i < count; i++) {
        Entry_1c0360 *e = &entries[i];
        e->a = -1.0f;
        e->b = -1.0f;
    }
    switch (mode) {
    case 0:
    case 1:
        DAT_004e2308 = 0.0f;
        DAT_004e230c = 0.0f;
        DAT_004e2310 = 0.0f;
        break;
    case 2: {
        DAT_004e2310 = 0.0f;
        float a = DAT_004de600;
        float b = DAT_004de604;
        float ha = a * -0.5f;
        float hb = b * -0.5f;
        float sa = a * 0.6f;
        DAT_004e2308 = sa + ha;
        DAT_004e230c = b * 0.26f + hb;
        Source_1c0360 *src = holder->FUN_000862b0();
        Vec3_1c0360 v;
        v.x = DAT_004de600 * -0.5f;
        v.z = 0.0f;
        v.y = DAT_004de604 * 0.5f;
        DAT_004c4c40 = FUN_000f6a70(src->field2c, &v, target);
        break;
    }
    }
}


// 0x001c04e0 FUN_001c04e0 (231 B): equivalent/0x001c04e0.cpp
// sym: ?Update@Fader_1c04e0@fn_fed79ca6@@QAEXM@Z @b3c00ed792fd @w6778cb5d8182
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 22/24, incomplete)
// FUN_001c04e0 @ 0x001c04e0
void Fader_1c04e0::Update(float dt) {
    if (!active)
        return;
    if (*state->FUN_00086270() != 6) {
        float absDt = dt < 0.0f ? -dt : dt;
        if (!(absDt > 1e-05f)) {
            float step = DAT_004dd700->clock->FUN_00085f80();
            if (step < 0.1f)
                dt = step;
            else
                dt = 0.1f;
        }
    }
    if (timer < 0.0f)
        timer = dt;
    else
        timer += dt;
    if (pending > 0)
        FUN_001bf9b0();
    if (fadeIn) {
        if (alpha < 255) {
            alpha += 10;
            if (alpha > 255)
                alpha = 255;
        }
    } else {
        if (alpha > 0) {
            alpha -= 10;
            if (alpha < 0)
                alpha = 0;
        }
    }
    if (mode == 2)
        listener->vf3(dt);
}

} // namespace fn_fed79ca6

// 0x001c05d0 FUN_001c05d0 (121 B): matches/0x001c05d0.cpp
// sym: ?FUN_001c05d0@Obj_1c05d0@owners@@QAEXMM@Z
// data: gZero_1c05d0 = DAT_003f32e0
void owners::Obj_1c05d0::FUN_001c05d0(float a, float b) {
    if (!active || !ptr)
        return;
    if (value < DAT_003f32e0)
        value = 0.0f;
    else
        value = a / b;
    Tick();
    if (up) {
        if (amount >= 255)
            return;
        amount += 10;
        if (amount <= 255)
            return;
        amount = 255;
    } else {
        if (amount <= 0)
            return;
        amount -= 10;
        if (amount >= 0)
            return;
        amount = 0;
    }
}


// 0x001c0650 FUN_001c0650 (157 B): equivalent/0x001c0650.cpp [wrapped: conflict: Track]
// sym: ?FUN_001c0650@Shake_1c0650@fn_001c0650@@QAEXHHH@Z @b38f2ae01263 @w441318cbe28a
namespace fn_001c0650 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 10/10)
// FUN_001c0650 @ 0x001c0650
// Shake::FUN_001c0650 @ 0x001c0650: reset and start the shake for a looked-up entry
struct Entry_1c0650 {
    int a;
    float b;
    int c;
    int d;
};

struct Child_1c0650 {
    char pad0[0xc];
    char flag0c;
};

struct Track {
    char pad0[8];
    int f08;
    int f0c;
    float f10;
    int f14;
};

class Shake_1c0650 {
public:
    float value;            // 0x00
    int count;              // 0x04
    Entry_1c0650 *volatile entries; // 0x08 (re-read between the stores: it can alias this)
    char pad0c;
    char flag0d;
    char pad0e[0x12];
    int mode;               // 0x20
    char flag24;
    char pad25[7];
    Child_1c0650 *child;           // 0x2c
    char pad30[0xc];
    Track *tracks;          // 0x3c
    char pad40[0x14];
    char flag54;
    char flag55;
    int FUN_001be0e0(int a, int b);
    void FUN_001c0360(int a, int b);
    void FUN_001c0650(int unused, int a, int b);
};

void Shake_1c0650::FUN_001c0650(int unused, int a, int b)
{
    int idx = FUN_001be0e0(a, b);
    if (idx == -1)
        return;

    count = 0;
    value = -1.0f;
    flag0d = 0;
    flag24 = 0;
    flag55 = 0;
    if (mode == 2)
        child->flag0c = 0;

    FUN_001c0360(unused, 1);

    Track *t = &tracks[idx];
    float f10 = t->f10;
    int f08 = t->f08;
    int f0c = t->f0c;
    if (count > 0) {
        entries->a = 0;
        Entry_1c0650 *e = entries;
        e->c = f08;
        e->d = f0c;
        entries->b = f10;
    }
    flag55 = (flag54 != 0);
}
} // namespace fn_001c0650


// 0x001c06f0 sSubtitleManagerCallback::vfunc_0 (44 B): matches/0x001c06f0.cpp
// sym: ?vfunc_0@sSubtitleManagerCallback@@UAEXHH@Z
void sSubtitleManagerCallback::vfunc_0(int a, int b) {
    Manager* p = (*(Manager * *)&this->f_04);
    if (p) {
        if (!p->flag)
            p->Do_001c0650(2, a, b);
        else
            p->Do_001c0650(0, a, b);
    }
}

namespace fn_fed79ca6 {

// 0x001c0810 FUN_001c0810 (83 B): equivalent/0x001c0810.cpp
// sym: ?FUN_001c0810@Registry_1c0810@fn_fed79ca6@@QAEXPBDPAVCSubtitleManager_1c0810@2@P832@AEXHM0M@Z@Z @937e99a9bd59 @w543c43762e71
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001c0810 @ 0x001c0810
// FUN_001c0810 @ 0x001c0810  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1c0810::FUN_001c0810(const char* a1, CSubtitleManager_1c0810* a2, Fn_1c0810 a3) {
    typedef Closure4_1c0810<CSubtitleManager_1c0810, void, int, float, const char*, float> Alloc_1c0810;
    HULK_SIZE32(Alloc_1c0810, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1c0810));
    void* x = 0;
    if (m) {
        ((Raw_1c0810*)m)->FUN_001bf4c0(a1, a3);
        x = new (m) Closure4_1c0810<CSubtitleManager_1c0810, void, int, float, const char*, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_fed79ca6

// 0x001c08c0 FUN_001c08c0 (109 B): equivalent/0x001c08c0.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_001c08c0@Registry_1c08c0@fn_001c08c0@@QAEXPBDPAVCSubtitleManager@2@P832@AE_NXZ@Z @23736c715d11 @w7a5c8bbfd4bb
namespace fn_001c08c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001c08c0 @ 0x001c08c0
// FUN_001c08c0 @ 0x001c08c0  (generated by work/closure/gen.py)
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


class CSubtitleManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1c08c0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1c08c0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1c08c0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1c08c0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1c08c0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001c08c0(const char* name, CSubtitleManager* owner, bool (CSubtitleManager::*fn)());
};

void Registry_1c08c0::FUN_001c08c0(const char* name, CSubtitleManager* owner, bool (CSubtitleManager::*fn)()) {
    typedef Closure0<CSubtitleManager, bool> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CSubtitleManager, bool>));
    Closure0<CSubtitleManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CSubtitleManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001c08c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fed79ca6 {

// 0x001c0980 FUN_001c0980 (83 B): equivalent/0x001c0980.cpp
// sym: ?FUN_001c0980@Registry_1c0980@fn_fed79ca6@@QAEXPBDPAVCSubtitleManager_1c0980@2@P832@AEXMMM@Z@Z @b68fcedd5a74 @w0241c93b9d7a
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001c0980 @ 0x001c0980
// FUN_001c0980 @ 0x001c0980  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1c0980::FUN_001c0980(const char* a1, CSubtitleManager_1c0980* a2, Fn_1c0980 a3) {
    typedef Closure3_1c0980<CSubtitleManager_1c0980, void, float, float, float> Alloc_1c0980;
    HULK_SIZE32(Alloc_1c0980, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1c0980));
    void* x = 0;
    if (m) {
        ((Raw_1c0980*)m)->FUN_001bf710(a1, a3);
        x = new (m) Closure3_1c0980<CSubtitleManager_1c0980, void, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001c09e0 FUN_001c09e0 (83 B): equivalent/0x001c09e0.cpp
// sym: ?FUN_001c09e0@Registry_1c09e0@fn_fed79ca6@@QAEXPBDPAVCSubtitleManager_1c09e0@2@P832@AEX00M@Z@Z @f38ea2728376 @w8e301e312103
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001c09e0 @ 0x001c09e0
// FUN_001c09e0 @ 0x001c09e0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1c09e0::FUN_001c09e0(const char* a1, CSubtitleManager_1c09e0* a2, Fn_1c09e0 a3) {
    typedef Closure3_1c09e0<CSubtitleManager_1c09e0, void, const char*, const char*, float> Alloc_1c09e0;
    HULK_SIZE32(Alloc_1c09e0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1c09e0));
    void* x = 0;
    if (m) {
        ((Raw_1c09e0*)m)->FUN_001bf7c0(a1, a3);
        x = new (m) Closure3_1c09e0<CSubtitleManager_1c09e0, void, const char*, const char*, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001c0a40 FUN_001c0a40 (110 B): matches/0x001c0a40.cpp
// sym: ?FUN_001c0a40@Object@fn_fed79ca6@@QAEHPAUContext@2@@Z
int Object::FUN_001c0a40(Context* arg) {
    int previous = FUN_00266da0(14);
    context = arg;
    State_1c0a40*** result = arg->FUN_000862e0();
    (**result)->value = value;
    if (first)
        ((owners::Obj_f86f0 *)first)->FUN_000f86f0(900, (hulk_intptr)50400);
    if (second)
        ((owners::Obj_f86f0 *)second)->FUN_000f86f0(250, (hulk_intptr)13000);
    FUN_001c0360(2, 0);
    return FUN_00266da0(previous);
}


// 0x001c0ca0 FUN_001c0ca0 (38 B): matches/0x001c0ca0.cpp
// sym: ?fn@Obj@fn_fed79ca6@@QAEXHH@Z
void Obj::fn(int a, int b) {
    unsigned __int64 v = compute_002672f0(b, 0, 0);
    use_001c0650(a, v);
}

} // namespace fn_fed79ca6
