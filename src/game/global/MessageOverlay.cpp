// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d40e0..0x000d6e00 (kind game, layer game, confidence high), dominant class MessageOverlay
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
#define TREE_TU_BEGIN namespace fn_f27eef39 {
#define TREE_TU_END }
namespace fn_f27eef39 {} using namespace fn_f27eef39;
namespace fn_f27eef39 { extern "C" char DAT_0040a47c[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"
#include "decls/managers.h"
#include "decls/view.h"   // (recs1) pure3d::View
#include "game/script_bind.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f27eef39 {
struct V3_d40e0 {
    float x, y, z;
};
struct Source_d40e0 {
    char pad0[0x34];
    int value;
};
struct Mode_d40e0 {
    char pad0[0x10c];
    int kind;
};
struct Camera {
    char pad0[0x2c];
    void *rig;
    hulk_freg FUN_000d6d90(void *owner);
};
hulk_freg __cdecl FUN_000f6a70(void *rig, V3_d40e0 *v, Mode_d40e0 *mode);
struct Item_d40e0 {
    short w0;
    char pad02[0xfe];
    int v100;
    float f104;
    int v108;
};
class Screen_d40e0 {
public:
    char pad0[4];
    bool f4;
    char pad5[3];
    Source_d40e0 *source;
    Mode_d40e0 *mode;
    int f10;
    char pad14[0x248 - 0x14];
    bool flagA;
    char pad249[0x484 - 0x249];
    bool flagB;
    char pad485[7];
    Item_d40e0 items[3];
    char pad7b0[4];
    float f7b4;
    int f7b8;
    bool f7bc;
    char pad7bd[7];
    bool f7c4;
    char pad7c5[3];
    int f7c8;
    int f7cc;
    float f7d0;
    char pad7d4[0x804 - 0x7d4];
    int f804;
    float f808;
    bool f80c;

    void FUN_000d40e0(Source_d40e0 *src, Mode_d40e0 *m, Camera *cam);
};
struct Rec_d4390 {
    char pad0[0x218];
    float score;
    char pad21c[0x18];
    char active;
    char pad235[7];
};
class Pool_d4390 {
public:
    char pad0[0x14];
    Rec_d4390 recs[2];
    Rec_d4390* FUN_000d4390();
};
class Obj_d45e0 {
  public:
    void Set(char c);
    char pad[0x7c4];
    char value;
};
class Obj {
  public:
    char _m_pad_0[0x18];
    void* p;
    char _m_pad_1c[0x7b4];
    float value;
    void Set(float x);
    void Other_000d4620(float, float, float, unsigned int, unsigned int);
    void Fn(float, float, float, float, float, float, float);
};
class Obj_d4780 {
public:
    void FUN_000d4620(int mode, int a, int b, unsigned int color, float scale);
    void Set(int a, int b, float r, float g, float bl);
};
class Obj_d47d0 {
public:
    void FUN_000d4620(int mode, int a, int b, unsigned int color, float scale);
    void Set(int a, int b, float r, float g, float bl);
};
class Obj_d4850 {
  public:
    char pad[0x80c];
    unsigned char field;
    unsigned char Set(unsigned char x);
};
struct Curve {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6();
    virtual float slot7(); virtual void slot8(); virtual float slot9(float);
};
struct Sample { float gain; char padding[12]; };
struct Player {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9();
    char padding[4];
    Sample samples[8];
    int activeSample;
    hulk_freg FUN_000d4900(float input, int index);
};
struct Interface {
    virtual void unused0(); virtual void unused1(); virtual void unused2();
    virtual void unused3(); virtual void unused4(); virtual void unused5();
    virtual void unused6(); virtual float getDivisor();
    virtual void unused8(); virtual void unused9();
    virtual float evaluate(float value);
};
struct Record { float weight; char unused[12]; };
struct Owner {
    Interface **entries;
    char unused[4];
    Record records[8];
    int active;
    double FUN_000d4950(float value, int index);
};
struct Vec_d49b0 {
 float x,y,z;
 bool FUN_0022d2b0(Vec_d49b0* other, float tolerance);
};
struct Clock_d4ae0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float Period();
};
struct Timer {
    char pad0[0x24];
    Clock_d4ae0 *clock;
};
struct Profile_d4ae0 {
    char pad0[0x88];
    int cur;
};
void __cdecl FUN_00294b80(char *text);
extern "C" int __cdecl FUN_000fb830(char *buf, int size, char *text, float value, int extra);
void __cdecl FUN_000fb690(char *dst, char *src, int size);
class Formatter_d4ae0 {
public:
    char pad0[0xc];
    Timer *timer;
    int FUN_000d4ae0(char *text, Profile_d4ae0 *prof, hulk_intptr extra);
};
struct MessageSink {
};
union FloatBits_d5290 {
    float f;
    unsigned int u;
};
class MessageOverlay_d5290 {
public:
    char pad0[0x10];
    MessageSink *sink;
    char pad14[0x240 - 0x14];
    int f240;
    char pad244[4];
    unsigned char b248;
    char pad249[0x47c - 0x249];
    int f47c;
    char pad480[4];
    unsigned char b484;
    char pad485[0x7cc - 0x485];
    float slide;
    void Update(float dt);
};
class Gauge_d5440 {
public:
    char pad000[0x22c];
    float level0;           // 0x22c
    float rate0;            // 0x230
    char pad234[0xc];
    int hold0;              // 0x240
    char pad244[4];
    char enabled0;          // 0x248
    char pad249[0x468 - 0x249];
    float level1;           // 0x468
    float rate1;            // 0x46c
    char pad470[0xc];
    int hold1;              // 0x47c
    char pad480[4];
    char enabled1;          // 0x484
    void FUN_000d5440();
};
class Dummy_d5530 {
  public:
    void Call(void*);
};
extern "C" char DAT_0040b1a8[];
class Owner_d5550 {};
typedef void (Owner_d5550::*Fn_d5550)(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
class Method7_d5550 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_d5550 owner;
    void FUN_001d0480(const char*, int);
    Method7_d5550* Init(const char*, Fn_d5550);
};
struct Function_d5600 {
    virtual void f0();
    virtual void f1();
};
void FUN_000d5620(const char*, const char*, const char*, int);
struct Obj_d5620;
typedef void (Obj_d5620::*Fn_d5620)(int, int, int, int, int, int, int);
struct Obj_d5620 {
    int x;
};
class Owner_d5660 {};
typedef void (Owner_d5660::*Fn_d5660)(const char*, int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl check(const char*);
extern const char hulk_at_0048e10c[];
class Function_d5660 : public CtorV_001d0480 {
  public:
    Function_d5660(const char* str) : CtorV_001d0480(str, 3) { }
};
class Method3_d5660 : public Function_d5660 {
  public:
    virtual bool Fnf_001d04c0(int, int);
    Fn_d5660 value;
    Method3_d5660(const char*, Fn_d5660);
};
} // namespace fn_f27eef39
namespace math {
struct Vector_d56e0 {
    float x, y, z;
};
}
namespace fn_f27eef39 {
class MessageOverlay_d56e0 {
  public:
    void Show(const char*, int, math::Vector_d56e0);
};
class Function_d56e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CActorManager_d5780 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_d5780::*MFn_d5780)(unsigned char);
class Function_d5780 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_d5800 {
  public:
    void f();
};
class Dummy_d5870 {
  public:
    void Call(void*);
};
extern "C" char DAT_0040b1f8[];
extern "C" char DAT_0048e10c[];
class Owner_d5890 {};
typedef void (Owner_d5890::*Fn_d5890)(int, const char*, int, int, float);
class Method5_d5890 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_d5890 p1c;
    void FUN_001d0480(const char*, int);
    Method5_d5890* Init(const char*, Fn_d5890);
};
} // namespace fn_f27eef39
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
namespace fn_f27eef39 {
struct Slot_d5980 {
    float from[3];
    float to[3];
    float cur;
    float limit;
    char pad0[0x34 - 0x20];
    char active;
    char pad1[0x23c - 0x35];
};
class MessageOverlay_d5980 : public Overlay {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(float dt);
    virtual void vfunc_4();
    virtual void vfunc_5();

    void FUN_000d49b0(float *a, float *b);
    void FUN_000d5290(float dt);

    // The slot array and the timers overlap in the original layout, so
    // fields are reached through typed accessors on the raw bytes.
    char raw[0x808 - 4];

    Slot_d5980 *slot(int i) { return (Slot_d5980 *)(raw + (0x214 - 4) + i * 0x23c); }
    float *floatAt(int off) { return (float *)(raw + (off - 4)); }
    char *byteAt(int off) { return raw + (off - 4); }
};
struct ThisWrap_000d5fa0 {
    void sink_000d4b60(void*, const char*, const char*, const char*, const char*, const char*,
                               const char*);
    void FUN_000d5fa0(void* p);
};
class Function_d5fd0 {
  public:
    virtual void f();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    int x;
    Function_d5fd0(const char*, int);
};
extern "C" unsigned char __cdecl get(hulk_uintptr);
class Method1_d5fd0 : public Function_d5fd0 {
  public:
    virtual void f();
    Method1_d5fd0(const char* s, int n) : Function_d5fd0(s, 1) {
        x = n;
        b = get(((hulk_intptr)((char*)&DAT_0048e100)));
        a = get(((hulk_intptr)((char*)&DAT_0048e0f0)));
    }
};
class Closure1_d5fd0 : public Method1_d5fd0 {
  public:
    virtual void f();
    int y;
    Closure1_d5fd0(const char*, int, int);
};
class CActorManager_d6040 {
  public:
    void invoke(const char*);
};
class MessageOverlay_d60b0 {
  public:
    void Method(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
};
class Actor_d6200 {
  public:
    void fn(unsigned char);
};
class CActorManager_d6280 {
  public:
    void run();
};
class CActorManager_d6300 {
  public:
    void invoke(const char*);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)
} // namespace fn_f27eef39
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f27eef39 {
class MessageOverlay_d6410 {};
typedef void (MessageOverlay_d6410::*Fn_d6410)(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
class Registry_d6410 { public:
    void FUN_000d6410(const char* a1, MessageOverlay_d6410* a2, Fn_d6410 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7_d6410;
template<> class Closure7_d6410<MessageOverlay_d6410, void, const char*, const char*, const char*, const char*, const char*, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_d6410 fn; MessageOverlay_d6410* owner; Closure7_d6410(MessageOverlay_d6410* o) { owner = o; } };
class Raw_d6410 { public: void FUN_000d5550(const char*, Fn_d6410); };
} // namespace fn_f27eef39
namespace math {
class Vector_d6470 { public: float x, y, z; };
}
namespace fn_f27eef39 {
class MessageOverlay_d6470 {};
typedef void (MessageOverlay_d6470::*Fn_d6470)(const char*, int, math::Vector_d6470);
class Registry_d6470 { public:
    void FUN_000d6470(const char* a1, MessageOverlay_d6470* a2, Fn_d6470 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_d6470;
template<> class Closure3_d6470<MessageOverlay_d6470, void, const char*, int, math::Vector_d6470> : public ScriptFunctionFields { public: virtual void v(); Fn_d6470 fn; MessageOverlay_d6470* owner; Closure3_d6470(MessageOverlay_d6470* o) { owner = o; } };
class Raw_d6470 { public: void FUN_000d5660(const char*, Fn_d6470); };
} // namespace fn_f27eef39
namespace math {
class Vector_d65e0 { public: float x, y, z; };
}
namespace fn_f27eef39 {
class MessageOverlay_d65e0 {};
typedef void (MessageOverlay_d65e0::*Fn_d65e0)(int, const char*, int, math::Vector_d65e0, float);
class Registry_d65e0 { public:
    void FUN_000d65e0(const char* a1, MessageOverlay_d65e0* a2, Fn_d65e0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_d65e0;
template<> class Closure5_d65e0<MessageOverlay_d65e0, void, int, const char*, int, math::Vector_d65e0, float> : public ScriptFunctionFields { public: virtual void v(); Fn_d65e0 fn; MessageOverlay_d65e0* owner; Closure5_d65e0(MessageOverlay_d65e0* o) { owner = o; } };
class Raw_d65e0 { public: void FUN_000d5890(const char*, Fn_d65e0); };
class Overlay_d68e0 {
    char pad[0x7b8];
};
class Overlay_d68f0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
} // namespace fn_f27eef39
namespace pure3d {
class NonCopyable_d6900 : public ::Overlay {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_d6900* f2(unsigned char);
};
}
namespace fn_f27eef39 {
struct Data_d6a20 { float x,y,z; };
// (recs1) the View and the camera this TU constructs: the slots it calls; a View's words after its vptr are
// decls/view.h's (HULK_VIEW_WORDS, as HulkView lays them out)
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(float,float); virtual void v6(); virtual void v7(float); virtual void v8(); virtual void v9(float);
 HULK_VIEW_WORDS
 Node* FUN_00294880(); Node* FUN_002939a0();    void FUN_00294980(Node*);
 void FUN_00293e90(int); void FUN_00293af0(int*); void FUN_00293a90(int*);
};
struct Manager_d6a20 {virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual float v16();};
extern void* __cdecl FUN_00263ea0(unsigned);
extern "C" void __cdecl FUN_0009f790(float,float,float*,float*);
// (recs1) COverlayManager on its record (decls/managers.h; was a view with 32-bit pads): its View and camera
struct Target_d6a20 : HulkOverlayManager { void FUN_000d6a20(); };
struct Clock_d6b20 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual float sample();
};
struct Effect_d6b20 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void set(float angle, float scale);
};
struct Owner_d6b20 { void FUN_00294980(Effect_d6b20*); };
struct Target_d6b20 {
 char pad0[4]; Owner_d6b20* owner; unsigned state; char padC[32]; Effect_d6b20* effect;
 void FUN_000d6b20(hulk_uintptr unused);
};
struct X {
    char pad[4];
    Obj* obj;
    int state;
    void Run(float);   // (gfx4) the frame time 0x00086a40 passes (unused)
};
extern "C" void __cdecl use_000c5a60(void*);
extern char hulk_at_0049e11c[], hulk_at_004a0a40[];
class Slots_d6d90 {
  public:
    char pad[12];
    int values[8];
    hulk_freg Add(int value);
};


// 0x000d40e0 FUN_000d40e0 (641 B): equivalent/0x000d40e0.cpp
// sym: ?FUN_000d40e0@Screen_d40e0@fn_f27eef39@@QAEXPAUSource_d40e0@2@PAUMode_d40e0@2@PAUCamera@2@@Z @5691ab75f445 @wb2c510e3ea28 @vf2014a752c4c
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 8/8)
// FUN_000d40e0 @ 0x000d40e0
void Screen_d40e0::FUN_000d40e0(Source_d40e0 *src, Mode_d40e0 *m, Camera *cam)
{
    V3_d40e0 v;
    source = src;
    mode = m;
    v.x = DAT_004de600 * -0.5f;
    v.y = DAT_004de604 * 0.5f;
    v.z = 0;
    f7b4 = FUN_000f6a70(cam->rig, &v, m);
    DAT_004ddf98 = 0;
    f808 = DAT_004a06c0 * (mode->kind == 3 ? DAT_004a06c4 : DAT_004a06c8);
    v.x = DAT_004de600;
    v.y = DAT_004de604;
    double aExt = DAT_004de600 * -0.5f;
    volatile float aF = (float)aExt;
    DAT_004ddfc8 = 0;
    double bExt = DAT_004de604 * -0.5f;
    volatile float t1 = (float)(v.y * 0.12f);
    (*(float*)&DAT_004ddfc0) = (float)(v.x * 0.6f + aExt);
    DAT_004ddfc4 = (float)(t1 + bExt);
    if (mode->kind == 3) {
        DAT_004ddfc4 = -8.08f;
        DAT_004a06d0 = 0.183f;
    }
    DAT_004ddfd4 = 0;
    double b2Ext = DAT_004de604 * 0.5f;
    DAT_004ddfe0 = 0;
    DAT_004ddfec = 0;
    volatile float b2F = (float)b2Ext;
    double cExt = v.x * -0.05f;
    double dExt = v.y * 0.25f;
    (*(float*)&DAT_004ddfcc) = (float)(aF - cExt);
    DAT_004ddfd0 = (float)(b2F - dExt);
    volatile float e = (float)(v.y * 0.31f);
    DAT_004ddfd8 = (float)(aF - cExt);
    DAT_004ddfdc = (float)(b2Ext - e);
    double fExt = v.y * 0.41f;
    DAT_004ddfe4 = (float)(aF - cExt);
    DAT_004ddfe8 = (float)(b2F - fExt);
    int j = 0;
    const int *p;
    for (p = DAT_004a06f8; p < DAT_004a06f8 + 3; p++) {   // (recs1, find2 G19) the table's own 3 entries (was DAT_004a0704: another data item, not laid out after it natively)
        items[j].w0 = 0;
        items[j].v100 = *p;
        items[j].f104 = 1000.0f;
        items[j].v108 = 0;
        j++;
    }
    f7b8 = 0;
    f4 = true;
    f7bc = false;
    f7c4 = false;
    f10 = source->value;
    flagA = false;
    flagB = false;
    cam->FUN_000d6d90(this);
    f7c8 = 0;
    f7cc = 0;
    f804 = 0;
    f7d0 = (*(float*)&DAT_004a06b0);
    f80c = true;
}


// 0x000d4390 FUN_000d4390 (103 B): equivalent/0x000d4390.cpp
// sym: ?FUN_000d4390@Pool_d4390@fn_f27eef39@@QAEPAURec_d4390@2@XZ @abd12bac6c61 @wa034f1005beb @v171e3dad29ea
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000d4390 @ 0x000d4390
Rec_d4390* Pool_d4390::FUN_000d4390() {
    int best = -1;
    float bestScore = 0.0f;
    for (int i = 0; i < 2; i++) {
        if (!recs[i].active)
            return &recs[i];
        if (best < 0 || bestScore < recs[i].score) {
            bestScore = recs[i].score;
            best = i;
        }
    }
    recs[best].active = 0;
    return &recs[best];
}

} // namespace fn_f27eef39

// 0x000d4400 FUN_000d4400 (395 B): equivalent/0x000d4400.cpp
// sym: ?FUN_000d4400@Accum_d4400@owners@@QAEXHM@Z @1b2df47e64f5 @wed602a1373c3 @v73ae00b1d3f9
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 17/18, incomplete)
// FUN_000d4400 @ 0x000d4400
void owners::Accum_d4400::FUN_000d4400(int id, float amount)
{
    float x = id ? -amount : amount;
    float v0 = 0.0f;
    float v1 = x;
    float v2 = 0.0f;

    if (flag0 && id0 == id) {
        float scale = (*(float*)&DAT_003f32dc);
        if (id == 0)
            scale = DAT_004a06bc;
        float w0 = v0, w1 = v1, w2 = v2;
        if (count0 < 1) {
            damp0 = scale * damp0;
            count0++;
        } else {
            w0 *= scale;
            w1 *= scale;
            w2 = scale * w2;
        }
        sum0 = w0 + sum0;
        sum1 = w1 + sum1;
        sum2 = w2 + sum2;
    }
    if (flag1 && id1 == id) {
        float scale = (*(float*)&DAT_003f32dc);
        if (id == 0)
            scale = DAT_004a06bc;
        float w0 = v0, w1 = v1, w2 = v2;
        if (count1 < 1) {
            damp1 = scale * damp1;
            count1++;
        } else {
            w0 *= scale;
            w1 *= scale;
            w2 = scale * w2;
        }
        sum3 = w0 + sum3;
        sum4 = w1 + sum4;
        sum5 = w2 + sum5;
    }
}

namespace fn_f27eef39 {

// 0x000d4590 FUN_000d4590 (64 B): matches/0x000d4590.cpp
// sym: ?RemoveNewlines@fn_f27eef39@@YGXPAD@Z
void __stdcall RemoveNewlines(char* text) {
    char* p;
    char c;
    p = strchr(text, 10);
    while (p != 0) {
        c = *p;
        while (c != 0) {
            *p = p[1];
            ++p;
            c = *p;
        }
        p = strchr(text, 10);
    }
}


// 0x000d45e0 FUN_000d45e0 (13 B): matches/0x000d45e0.cpp
// sym: ?Set@Obj_d45e0@fn_f27eef39@@QAEXD@Z
void Obj_d45e0::Set(char c) {
    value = c;
}

} // namespace fn_f27eef39

// 0x000d45f0 MessageOverlay::vfunc_5 (3 B): matches/0x000d45f0.cpp
// sym: ?vfunc_5@MessageOverlay@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void MessageOverlay::vfunc_5(int a) {
    (void)a;
}

namespace fn_f27eef39 {

// 0x000d4600 FUN_000d4600 (30 B): matches/0x000d4600.cpp
// sym: ?Set@Obj@fn_f27eef39@@QAEXM@Z
// data: zero = DAT_003f32e0
void Obj::Set(float x) {
    if (x >= DAT_003f32e0)
        value = x;
}

} // namespace fn_f27eef39

// 0x000d4620 FUN_000d4620 (244 B): equivalent/0x000d4620.cpp [wrapped: compile error C2120: 'void' illegal with all types]
// sym: ?FUN_000d4620@Object@fn_000d4620@@QAEXHPBDHHM@Z @60c4dce3bbf2 @w7289c5dc547b @v26716a37b7ed
namespace fn_000d4620 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000d4620 @ 0x000d4620


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*,const char*,unsigned int);
#endif

struct Lookup_d4620 {   };
extern void __cdecl FUN_000fb690(char*,const char*,int);
extern "C" void __cdecl FUN_000fc020(char*,int,const char*,...);
extern int __cdecl FUN_00294b80(const char*);
struct Slot_d4620 { char text[256]; int value; int zero; float duration; };
struct Object { char pad0[12]; Lookup_d4620* lookup; char pad1[0x47c]; Slot_d4620 slots[3]; char pad2[0x5c]; unsigned char enabled; void FUN_000d4620(int,const char*,int,int,float); };
void Object::FUN_000d4620(int index,const char* name,int mode,int value,float duration) {
 if (!enabled || index<0 || index>=3 || !name) return;
 strncpy(((char*)&DAT_004de000),name,255);
 DAT_004de0ff=0;
 int id=((int)((owners::A_f7d30 *)lookup)->FUN_000f7d30((hulk_intptr)(((char*)&DAT_004de000))));
 if(id==-1) return;
 const char* source=((const char *)((owners::C_f7220 *)lookup)->FUN_000f7220((hulk_intptr)id));
 Slot_d4620& slot=slots[index];
 if(mode<0) FUN_000fb690(slot.text,source,128);
 else FUN_000fc020(slot.text,128,source,mode);
 if(FUN_00294b80(slot.text)>127) return;
 slot.value=value;
 slot.zero=0;
 slot.duration=duration<0.0f ? 3.0f : duration;
}
} // namespace fn_000d4620

namespace fn_f27eef39 {

// 0x000d4720 FUN_000d4720 (82 B): matches/0x000d4720.cpp
// sym: ?Fn@Obj@fn_f27eef39@@QAEXMMMMMMM@Z
void Obj::Fn(float a, float b, float c, float d, float e, float f, float g) {
    unsigned int color = (int)d;
    color |= 0xffffff00;
    color <<= 8;
    color |= (int)e;
    color <<= 8;
    color |= (int)f;
    Other_000d4620(a, b, c, color, *(volatile unsigned int*)&g);
}


// 0x000d4780 FUN_000d4780 (79 B): equivalent/0x000d4780.cpp
// sym: ?Set@Obj_d4780@fn_f27eef39@@QAEXHHMMM@Z @12d2a6b3a9bf @w6fa99b620028 @v79bfc0e592db
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d4780 @ 0x000d4780
void Obj_d4780::Set(int a, int b, float r, float g, float bl)
{
    unsigned int color = (((0xffffff00 | (int)r) << 8 | (int)g) << 8) | (int)bl;
    FUN_000d4620(1, a, b, color, 3.0f);
}


// 0x000d47d0 FUN_000d47d0 (79 B): equivalent/0x000d47d0.cpp
// sym: ?Set@Obj_d47d0@fn_f27eef39@@QAEXHHMMM@Z @17378d77282b @wf46041920d37 @v355aca13bc38
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d47d0 @ 0x000d47d0
void Obj_d47d0::Set(int a, int b, float r, float g, float bl)
{
    unsigned int color = (((0xffffff00 | (int)r) << 8 | (int)g) << 8) | (int)bl;
    FUN_000d4620(2, a, b, color, 3.0f);
}

} // namespace fn_f27eef39

// 0x000d4820 FUN_000d4820 (33 B): matches/0x000d4820.cpp
// sym: ?FUN_000d4820@Obj_d4820@owners@@QAEXHM@Z
void owners::Obj_d4820::FUN_000d4820(int index, float value) {
    if (index >= 0 && index < 3)
        items[index][0] = value;
}

namespace fn_f27eef39 {

// 0x000d4850 FUN_000d4850 (13 B): matches/0x000d4850.cpp
// sym: ?Set@Obj_d4850@fn_f27eef39@@QAEEE@Z
unsigned char Obj_d4850::Set(unsigned char x) {
    field = x;
    return x;
}

// 0x000d4860 thunk_FUN_001d04a0 (5 B): not yet verified

// 0x000d4900 FUN_000d4900 (69 B): equivalent/0x000d4900.cpp
// sym: ?FUN_000d4900@Player@fn_f27eef39@@QAEMMH@Z @de5894143770 @we0a7c0bb5b76 @vb74f27f1bdd5
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_000d4900 @ 0x000d4900
hulk_freg Player::FUN_000d4900(float input, int index)
{
    void **table = *(void ***)this;
    Curve *first = (Curve *)table[9];
    Curve *chosen = (Curve *)table[9 + index];
    Sample *sample = &samples[activeSample];
    float factor = DAT_0040cc38 / first->slot7();
    float output = chosen->slot9(input);
    return output * sample->gain * factor;
}


// 0x000d4950 FUN_000d4950 (69 B): equivalent/0x000d4950.cpp
// sym: ?FUN_000d4950@Owner@fn_f27eef39@@QAENMH@Z @6a4d052c23be @wf551bcbf5f17 @v3c6644046861
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_000d4950 @ 0x000d4950
double Owner::FUN_000d4950(float value, int index)
{
    Interface *selected = entries[9 + index];
    float *weight = &records[active].weight;
    hulk_freg divisor = entries[9]->getDivisor();
    float ratio = 14.0f / divisor;
    return (double)selected->evaluate(value) * *weight * ratio;
}


// 0x000d49b0 FUN_000d49b0 (299 B): equivalent/0x000d49b0.cpp
// sym: ?FUN_000d49b0@fn_f27eef39@@YGXPAUVec_d49b0@1@0@Z @353eccc4bc4b @wbc62799c5fa3 @v1d62e0c3537e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 17/20, incomplete)
// FUN_000d49b0 @ 0x000d49b0
void __stdcall FUN_000d49b0(Vec_d49b0* target, Vec_d49b0* current) {
 if(current->FUN_0022d2b0(target, 0.00001f)) return;
 for(int i=0;i<3;++i) {
  float* a = i==0 ? &current->x : i==1 ? &current->y : &current->z;
  float* b = i==0 ? &target->x : i==1 ? &target->y : &target->z;
  double delta = (double)*b - (double)*a;
  float lower = -DAT_004a06e4;
  if (!(delta >= lower)) {
   if(delta > DAT_004a06e4) delta=DAT_004a06e4;
   else delta=lower;
  } else if (!(delta <= DAT_004a06e4)) delta=DAT_004a06e4;
  *a = (float)(delta + *a);
 }
}


// 0x000d4ae0 FUN_000d4ae0 (117 B): equivalent/0x000d4ae0.cpp
// sym: ?FUN_000d4ae0@Formatter_d4ae0@fn_f27eef39@@QAEHPADPAUProfile_d4ae0@2@H@Z @935e07219b8a @w83fe00541fd4 @v291ba3252e8f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d4ae0 @ 0x000d4ae0
int Formatter_d4ae0::FUN_000d4ae0(char *text, Profile_d4ae0 *prof, hulk_intptr extra)
{
    FUN_00294b80(text);
    int r = FUN_000fb830(DAT_004de100, 0x100, text,
                         16.0f / ((14.0f / timer->clock->Period()) * *(float *)((char *)prof + prof->cur * 16 + 8)),
                         extra);
    FUN_000fb690(text, DAT_004de100, 0x100);
    return r;
}

} // namespace fn_f27eef39

// 0x000d50f0 FUN_000d50f0 (403 B): equivalent/0x000d50f0.cpp [wrapped: conflict: Overlay]
// sym: ?FUN_000d50f0@FadeQuad@fn_000d50f0@@QAEXXZ @745a28f3cd24 @w2b5f957df668 @v1ec4fb1f4102
namespace fn_000d50f0 {
// STATUS: equivalent (tools/equiv.py level 3: 19840 inputs, branch coverage 2/2)
// FUN_000d50f0 @ 0x000d50f0
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

struct V3_d50f0 {
    float x, y, z;
};

struct VertexBuf_d50f0 {
    char pad0[8];
    V3_d50f0 *vertex;
    char pad0c[4];
    unsigned *color;
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
    virtual VertexBuf_d50f0 *beginQuad(int obj, int one, int flags, int four, int zero);
    virtual void endQuad(VertexBuf_d50f0 *buf);
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void setState(int on);
};

class Provider_d50f0 {
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

struct ProviderRef_d50f0 {
    Provider_d50f0 *provider;
    void FUN_00293d00(void *state);
};

struct Overlay {
    char pad0[0x10];
    int f10;
};


class FadeQuad {
public:
    char pad0[0x7c0];
    Overlay *overlay;
    char pad7c4[8];
    float amount;
    void FUN_000d50f0();
};

void FadeQuad::FUN_000d50f0()
{
    float a = amount;
    if (a < 0.0f)
        a = -a;
    if (a <= 1e-05f)
        return;

    DAT_0052c2a8->setState(0);
    (*(ProviderRef_d50f0**)&DAT_0052c2ac)->provider->v15(0);
    (*(ProviderRef_d50f0**)&DAT_0052c2ac)->FUN_00293d00(((char*)&DAT_004ddfc0));

    VertexBuf_d50f0 *buf = DAT_0052c2a8->beginQuad(overlay->f10, 1, 0x2020, 4, 0);

    float x0 = DAT_004a06d4 * -0.5f;   // (tri1) a writable global (16.6 at load), read as the original does, not folded
    float y0 = DAT_004a06d0 * -0.5f;
    float x1 = amount * 0.5f;
    float y1 = DAT_004a06d0 * 0.5f;

    V3_d50f0 *v = buf->vertex;
    v->y = y0;
    v->x = x0;
    v->z = 0.0f;
    unsigned *color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    v = buf->vertex;
    v->x = x0;
    v->y = y1;
    v->z = 0.0f;
    color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    v = buf->vertex;
    v->x = x1;
    v->y = y0;
    v->z = 0.0f;
    color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    v = buf->vertex;
    v->x = x1;
    v->y = y1;
    v->z = 0.0f;
    color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    DAT_0052c2a8->endQuad(buf);
    (*(ProviderRef_d50f0**)&DAT_0052c2ac)->provider->v16(0);
    DAT_0052c2a8->setState(1);
}
} // namespace fn_000d50f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f27eef39 {

// 0x000d5290 FUN_000d5290 (427 B): equivalent/0x000d5290.cpp
// sym: ?Update@MessageOverlay_d5290@fn_f27eef39@@QAEXM@Z @e244a1a4966d @w5380f5ecd84f @v447fffc1a9fa
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 23/24, incomplete)
// FUN_000d5290 @ 0x000d5290
void MessageOverlay_d5290::Update(float dt)
{
    bool open = false;
    if (f240 == 0 && b248)
        open = true;
    if (f47c == 0 && b484)
        open = true;

    FloatBits_d5290 a;

    if (open) {
        a.f = slide;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f)
            ((owners::Owner_1ebd00 *)sink)->FUN_001ebd00("MessageBox", "HUD_new_message");

        a.f = slide - DAT_004a06d4;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f) {
            slide = DAT_004a06d4;
            return;
        }
        slide = DAT_004a06dc * dt + slide;
        if (slide < DAT_004a06d4)
            return;
        slide = DAT_004a06d4;
    } else {
        a.f = slide - DAT_004a06d4;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f)
            ((owners::Owner_1ebd00 *)sink)->FUN_001ebd00("MessageBox", "HUD_new_message");

        a.f = slide;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f) {
            slide = 0.0f;
            return;
        }
        slide = slide - DAT_004a06dc * dt;
        if (0.0f < slide)
            return;
        slide = 0.0f;
    }
}


// 0x000d5440 FUN_000d5440 (131 B): equivalent/0x000d5440.cpp
// sym: ?FUN_000d5440@Gauge_d5440@fn_f27eef39@@QAEXXZ @fb18ac719662 @wfd00825ab5a6 @vd66588816d80
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000d5440 @ 0x000d5440
void Gauge_d5440::FUN_000d5440()
{
    if (enabled0 && hold0 == 0) {
        double v = (0.15f + rate0) + 0.1f;
        level0 = (v > level0) ? (float)v : level0;
    }
    if (enabled1 && hold1 == 0) {
        double v = (0.15f + rate1) + 0.1f;
        level1 = (v > level1) ? (float)v : level1;
    }
}

} // namespace fn_f27eef39

// 0x000d5510 Method1<MessageOverlay,void,const_char_*>::vfunc_0 (30 B): matches/0x000d5510.cpp
// sym: ?vfunc_0@Method1_d5510@fn_000d5510@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<MessageOverlay, void, const char *>::~Method1() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d5510 {
struct Method1_d5510 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_d5510::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d5510
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d5530 Method1<MessageOverlay,void,const_char_*>::vfunc_2 (19 B): matches/0x000d5530.cpp
// sym: ?vfunc_2@Method1_d5530@fn_000d5530@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<MessageOverlay, void, const char *>::vfunc_2`.
namespace fn_000d5530 {
struct Method1_d5530 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_d5530::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_d5530* d = (Dummy_d5530*)a;
    (d->*(*(void (Dummy_d5530::**)(void *))&this->f_1c))(*b);
}
} // namespace fn_000d5530

namespace fn_f27eef39 {

// 0x000d5550 FUN_000d5550 (141 B): matches/0x000d5550.cpp
// sym: ?Init@Method7_d5550@fn_f27eef39@@QAEPAV12@PBDP8Owner_d5550@2@AEX0000000@Z@Z
// FUN_000d5550 @ 0x000d5550
// Method7 registration constructor: base init, vftable, then the seven result/argument type tags.
Method7_d5550* Method7_d5550::Init(const char* name, Fn_d5550 value) {
    FUN_001d0480(name, 7);
    vptr = (void*)DAT_0040b1a8;
    owner = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}

} // namespace fn_f27eef39

// 0x000d55e0 Method7<MessageOverlay,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000d55e0.cpp
// sym: ?vfunc_0@Method7_d55e0@fn_000d55e0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method7<MessageOverlay, void, const char *, const char *, const
// char *, const char *, const char *, const char *, const char *>::~Method7() {}` stood for it, which natively defines
// no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d55e0 {
struct Method7_d55e0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method7_d55e0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d55e0
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d5600 Method7<MessageOverlay,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (30 B): matches/0x000d5600.cpp
// sym: ?vfunc_2@Method7_d5600@fn_000d5600@@QAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method7<MessageOverlay, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2`.
namespace fn_000d5600 {
struct Method7_d5600 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(const char *, const char *, const char *, const char *, const char *, const char *, const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method7_d5600::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_000d5620(a, b, c, (*(int *)&this->f_1c));
}
} // namespace fn_000d5600

namespace fn_f27eef39 {

// 0x000d5620 FUN_000d5620 (62 B): matches/0x000d5620.cpp
// sym: ?FUN_000d5620@fn_f27eef39@@YAXPAUObj_d5620@1@PAHHP821@AEXHHHHHHH@Z@Z
// Same code shape as 0x00094490 (propagated; names are from that function)
void __cdecl FUN_000d5620(Obj_d5620* a, int* p, int b, Fn_d5620 fn) {
    int* q = p;
    int v0 = *q;
    q++;
    int v1 = *q;
    q++;
    int v2 = *q;
    q++;
    int v3 = *q;
    q++;
    int v4 = *q;
    q++;
    int v5 = *q;
    q++;
    int v6 = *q;
    (a->*fn)(v0, v1, v2, v3, v4, v5, v6);
}


// 0x000d5660 FUN_000d5660 (89 B): matches/0x000d5660.cpp
// sym: ??0Method3@fn_000d5660@fn_f27eef39@@QAE@PBDP8Owner_d5660@12@AEXXZ@Z
namespace fn_000d5660 {
// (script1) Method3<class MessageOverlay,void,const char *,int,class math::Vector>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_0040b1b8[];   // Method3<class MessageOverlay,void,const char *,int,class math::Vector>
class Owner_d5660 {};
typedef void (Owner_d5660::*Fn_d5660)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_d5660 fn;
    Method3(const char* name, Fn_d5660 function);
};
Method3::Method3(const char* name, Fn_d5660 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_0040b1b8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
}
} // namespace fn_000d5660

} // namespace fn_f27eef39

// 0x000d56c0 Method3<MessageOverlay,void,const_char_*,int,math::Vector>::vfunc_0 (30 B): matches/0x000d56c0.cpp
// sym: ?vfunc_0@Vector_d56c0@fn_000d56c0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<MessageOverlay, void, const char *,
// int,math::Vector>::~Method3() {}` stood for it, which natively defines no function for the vftable slot (with the
// `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d56c0 {
struct Vector_d56c0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_d56c0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d56c0
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d56e0 Method3<MessageOverlay,void,const_char_*,int,math::Vector>::vfunc_2 (57 B): matches/0x000d56e0.cpp
// sym: ?vfunc_2@Method3_d56e0@fn_000d56e0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<MessageOverlay, void, const char *, int,math::Vector>::vfunc_2`.
namespace fn_000d56e0 {
struct Method3_d56e0 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(const char *, int, math::Vector);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_d56e0::vfunc_2(void* __p0, void* __p1, void* __p2) { MessageOverlay_d56e0 * obj = (MessageOverlay_d56e0 *)__p0; void * args = (void *)__p1; void * other = (void *)__p2;

    char* p = (char*)args;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector_d56e0 v = *(math::Vector_d56e0*)p;
    (obj->*(*(void (MessageOverlay_d56e0::**)(const char *, int, math::Vector_d56e0))&this->f_1c))(s, i, v);
}
} // namespace fn_000d56e0


// 0x000d5760 Method1<MessageOverlay,void,bool>::vfunc_0 (30 B): matches/0x000d5760.cpp
// sym: ?vfunc_0@Method1_d5760@fn_000d5760@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<MessageOverlay, void, bool>::~Method1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d5760 {
struct Method1_d5760 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_d5760::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d5760
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d5780 Method1<MessageOverlay,void,bool>::vfunc_2 (21 B): matches/0x000d5780.cpp
// sym: ?vfunc_2@Method1_d5780@fn_000d5780@@QAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<MessageOverlay, void, bool>::vfunc_2`.
namespace fn_000d5780 {
struct Method1_d5780 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_d5780::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_d5780 * obj = (CActorManager_d5780 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_d5780 *)&this->f_1c))(*b);
}
} // namespace fn_000d5780


// 0x000d57e0 Method0<MessageOverlay,void>::vfunc_0 (30 B): matches/0x000d57e0.cpp
// sym: ?vfunc_0@Method0_d57e0@fn_000d57e0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<MessageOverlay, void>::~Method0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d57e0 {
struct Method0_d57e0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_d57e0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d57e0
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d5800 Method0<MessageOverlay,void>::vfunc_2 (12 B): matches/0x000d5800.cpp
// sym: ?vfunc_2@Method0_d5800@fn_000d5800@@QAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<MessageOverlay, void>::vfunc_2`.
namespace fn_000d5800 {
struct Method0_d5800 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_d5800::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_d5800 * a = (CActorManager_d5800 *)__p0;

    (a->*(*(void (CActorManager_d5800::**)())&this->f_1c))();
}
} // namespace fn_000d5800


// 0x000d5850 Method1<MessageOverlay,void,float>::vfunc_0 (30 B): matches/0x000d5850.cpp
// sym: ?vfunc_0@Method1_d5850@fn_000d5850@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<MessageOverlay, void, float>::~Method1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d5850 {
struct Method1_d5850 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_d5850::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d5850
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d5870 Method1<MessageOverlay,void,float>::vfunc_2 (19 B): matches/0x000d5870.cpp
// sym: ?vfunc_2@Method1_d5870@fn_000d5870@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<MessageOverlay, void, float>::vfunc_2`.
namespace fn_000d5870 {
struct Method1_d5870 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_d5870::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_d5870* d = (Dummy_d5870*)a;
    (d->*(*(void (Dummy_d5870::**)(void *))&this->f_1c))(*b);
}
} // namespace fn_000d5870

namespace fn_f27eef39 {

// 0x000d5890 FUN_000d5890 (115 B): matches/0x000d5890.cpp
// sym: ?Init@Method5_d5890@fn_f27eef39@@QAEPAV12@PBDP8Owner_d5890@2@AEXH0HHM@Z@Z
// FUN_000d5890 @ 0x000d5890
Method5_d5890* Method5_d5890::Init(const char* arg, Fn_d5890 value) {
    FUN_001d0480(arg, 5);
    vptr = (void*)DAT_0040b1f8;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f27eef39

// 0x000d5910 Method5<MessageOverlay,void,int,const_char_*,int,math::Vector,float>::vfunc_0 (30 B): matches/0x000d5910.cpp
// sym: ?vfunc_0@Method5_d5910@fn_000d5910@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method5<MessageOverlay, void, int, const char *,
// int,math::Vector, float>::~Method5() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's
// body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d5910 {
struct Method5_d5910 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method5_d5910::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d5910


// 0x000d5930 Method5<MessageOverlay,void,int,const_char_*,int,math::Vector,float>::vfunc_2 (70 B): matches/0x000d5930.cpp [wrapped: conflict: Function; MessageOverlay; Method5]
// sym: ?vfunc_2@Method5@fn_000d5930@@QAEXPAVMessageOverlay@2@PAXH@Z
namespace fn_000d5930 {
namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class MessageOverlay {
  public:
    void Show(int, const char*, int, math::Vector, float);
};
class Function { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
  public:
    void a();
    void b();
};
class Method5 : public Function {
  public:
    void vfunc_2(MessageOverlay*, void*, int);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
    typedef void (MessageOverlay::*Fn)(int, const char*, int, math::Vector, float);
    Fn fn;
};
void Method5::vfunc_2(MessageOverlay* obj, void* p, int) {
    int* q = (int*)p;
    int a = *q++;
    const char* b = *(const char**)q++;
    int c = *q++;
    math::Vector d = *(math::Vector*)q;
    q += 3;
    float e = *(float*)q;
    Fn f = fn;
    (obj->*f)(a, b, c, d, e);
}
} // namespace fn_000d5930

namespace fn_f27eef39 {

// 0x000d5980 MessageOverlay::vfunc_3 (406 B): equivalent/0x000d5980.cpp
// sym: ?vfunc_3@MessageOverlay_d5980@fn_f27eef39@@UAEXM@Z @59f281d01059 @wfbf81464c448 @v46eec883b36e
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 16/16)
// MessageOverlay::vfunc_3 @ 0x000d5980
void MessageOverlay_d5980::vfunc_3(float dt)
{
    hulk_freg margin = DAT_004a06b8 + DAT_004a06ac + DAT_004a06a8;
    if (*byteAt(0x7bc))
        return;
    for (int i = 0; i < 2; i++) {
        Slot_d5980 *s = slot(i);
        if (s->active) {
            FUN_000d49b0(s->to, s->from);
            hulk_freg d = *floatAt(0x7cc) - DAT_004a06d4;
            if (fabs(d) <= 1e-5f)
                s->cur += dt;
            if (margin + s->limit < s->cur)
                s->active = 0;
        }
    }
    *floatAt(0x590) += dt;
    *floatAt(0x69c) += dt;
    *floatAt(0x7a8) += dt;
    FUN_000d5290(dt);
    hulk_freg phase = dt * 6.2831855f + *floatAt(0x804);
    *floatAt(0x7fc) = (sin(phase) + 1.0f) * 0.5f;
    int turns = (int)(phase * 0.15915494f);
    *floatAt(0x804) = phase - (float)turns * 6.2831855f;
    hulk_freg v = *floatAt(0x804);
    if (v >= 0.0f && v <= 6.2831855f)
        *floatAt(0x804) = v;
    else if (!(v > 6.2831855f))
        *floatAt(0x804) = 0.0f;
    else
        *floatAt(0x804) = 6.2831855f;
}

} // namespace fn_f27eef39

// 0x000d5b20 MessageOverlay::vfunc_4 (1124 B): equivalent/0x000d5b20.cpp [wrapped: conflict: MessageOverlay]
// sym: ?v4@MessageOverlay@fn_000d5b20@@UAEXXZ @bab9c6051620 @w5f7282723151 @vee3e12d82103
namespace fn_000d5b20 {
// STATUS: equivalent (tools/equiv.py level 3: 20046 inputs, branch coverage 27/28, incomplete)
// MessageOverlay::vfunc_4 @ 0x000d5b20

struct Rec_d5b20 {
    int a, b, c;
};

class Dev_d5b20 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
struct Ctx_d5b20 {
    Dev_d5b20 *dev;
    void FUN_00293d00(void *p);
    void FUN_00293d40(float a, float b, int c);
};

class Obj24_d5b20 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6();
    virtual float v7();
    virtual void v8();
    virtual float v9(void *p);
    virtual float v10(void *p);
};
struct Owner_d5b20 {
    char pad[0x24];
    Obj24_d5b20 *p24;
};

struct Builder {
    char data[8];
    void FUN_000f7fe0(Owner_d5b20 *o);
    void FUN_000f78e0();
    void FUN_000f81b0(void *a, int b, void *c);
};

struct Vtx_d5b20 {
    float a;
    int b;
    int c;
    unsigned int color;
};
struct Q_d5b20 {
    int a, b;
    float c;
};

struct Elem_d5b20 {
    char obj[0x200];
    char obj2[0x18];
    float f0, f4, f8;
    int fc, f10;
    char pad22c[8];
    char flag;
    char pad235[0x23c - 0x235];
};
struct Item_d5b20 {
    char pad0[0x100];
    unsigned int color;
    float f0, f4;
};

struct Frame_d5b20 {
    float u;
    float s;
    Rec_d5b20 *savedRec;
    float t1;
    Q_d5b20 q;
    Builder a;
    Vtx_d5b20 v[8];
    int n;
    float w;
};

class MessageOverlay {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    char pad04[8];
    Owner_d5b20 *owner;
    char pad10[4];
    Elem_d5b20 elems[2];
    Item_d5b20 items[3];
    char pad7b0[4];
    float f7b4;
    float f7b8;
    char pad7bc[0x7d4 - 0x7bc];
    char f7d4[4];
    void FUN_000d50f0();
};

void MessageOverlay::v4()
{
    if (!owner)
        return;
    Frame_d5b20 f;
    FUN_000d50f0();
    f.a.FUN_000f7fe0(owner);
    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
    f.q.a = 0;
    f.q.b = 0;
    f.q.c = f7b8;
    (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d00(&f.q);
    for (int k = 0; k < 2; k++) {
        Elem_d5b20 *e = &elems[k];
        if (e->flag) {
            f.v[f.n].a = e->f8 * f7b4;
            f.v[f.n].c = e->f10;
            f.v[f.n].b = e->fc;
            f.w = (*(float*)&DAT_004a06cc);
            int alpha;
            if (e->f0 < DAT_004a06a8) {
                alpha = 0;
            } else if (DAT_004a06ac + DAT_004a06a8 > e->f0) {
                alpha = (int)((e->f0 - DAT_004a06a8) / DAT_004a06ac * 255.0f);
            } else if (DAT_004a06ac + e->f4 + DAT_004a06a8 > e->f0) {
                alpha = 0xff;
            } else {
                f.u = (DAT_004a06b8 - (((e->f0 - DAT_004a06a8) - DAT_004a06ac) - e->f4)) / DAT_004a06b8;
                hulk_freg u;
                if (1.0f < f.u)
                    u = 1.0f;
                else if (0.0f < f.u)
                    u = f.u;
                else
                    u = 0.0f;
                alpha = (int)(u * 255.0f);
            }
            f.v[f.n].color = (alpha << 24) | 0xfef618;
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
            (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d00(e->obj2);
            f.a.FUN_000f81b0(e->obj, DAT_004ddf98, f7d4);
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
        }
    }
    float *tbl = ((float*)&DAT_0040b158);
    Rec_d5b20 *rec = ((Rec_d5b20*)&DAT_004ddfcc);
    for (int k = 0; (Rec_d5b20 *)rec < (Rec_d5b20 *)&(*(float*)&DAT_004ddff0); k++, rec++, tbl++) {
        Item_d5b20 *it = &items[k];
        if (it->f0 < (*(float*)&DAT_004ddff0)) {
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
            (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d00(rec);
            if (it->f4 + 0.5f > it->f0) {
                f.v[f.n].a = f7b4 * *tbl;
                f.v[f.n].b = 0;
                f.v[f.n].c = 1;
                unsigned int col = it->color;
                if (it->f0 >= it->f4) {
                    int a = 0xff - (int)((it->f0 - it->f4) * 510.0f);
                    col = ((unsigned int)a << 24) | (col & 0xffffff);
                }
                f.v[f.n].color = col;
                f.a.FUN_000f81b0(it, 0, f7d4);
            }
            if (it->f0 < 1.0f) {
                Obj24_d5b20 *o = owner->p24;
                if (o) {
                    double q = 14.0f / o->v7();
                    double tf = *tbl * f7b4; // MSVC would reassociate the product
                    f.s = tf * q;
                    f.t1 = o->v10(it) * f.s;
                    f.s = o->v9(it) * f.s;
                    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
                    (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d40(f.t1 * 0.5f, f.s * -0.5f, 0);
                    f.v[f.n].a = (1.0f + it->f0) * *tbl * f7b4;
                    f.v[f.n].b = 1;
                    f.v[f.n].c = 2;
                    int a = (int)(it->f0 * 255.0f);
                    f.v[f.n].color = ((unsigned int)(-1 - a) << 24) | (it->color & 0xffffff);
                    f.a.FUN_000f81b0(it, 0, 0);
                    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
                }
            }
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
        }
    }
    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
    f.a.FUN_000f78e0();
}
} // namespace fn_000d5b20

// 0x000d5f90 thunk_FUN_000d4b60 (5 B): not yet verified
namespace fn_f27eef39 {

// 0x000d5fa0 FUN_000d5fa0 (43 B): matches/0x000d5fa0.cpp
// sym: ?FUN_000d5fa0@ThisWrap_000d5fa0@fn_f27eef39@@QAEXPAX@Z
void ThisWrap_000d5fa0::FUN_000d5fa0(void* p) {
    this->sink_000d4b60(p, "FIXME", "FIXME", "FIXME", "FIXME", "FIXME", "FIXME");
}


// 0x000d5fd0 FUN_000d5fd0 (76 B): matches/0x000d5fd0.cpp
// sym: ??0Closure1@fn_000d5fd0@fn_f27eef39@@QAE@PBDPAVOwner_d5fd0@12@P8312@AEXXZ@Z
namespace fn_000d5fd0 {
// (script1) Closure1<class MessageOverlay,void,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040b198[];   // Method1<class MessageOverlay,void,const char *>
extern "C" char DAT_0040b218[];   // Closure1<class MessageOverlay,void,const char *>
class Owner_d5fd0 {};
typedef void (Owner_d5fd0::*Fn_d5fd0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_d5fd0 fn;
    Owner_d5fd0* owner;
    Closure1(const char* name, Owner_d5fd0* object, Fn_d5fd0 function);
};
Closure1::Closure1(const char* name, Owner_d5fd0* object, Fn_d5fd0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_0040b198;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0040b218;
    owner = object;
}
} // namespace fn_000d5fd0

} // namespace fn_f27eef39

// 0x000d6020 Closure1<MessageOverlay,void,const_char_*>::vfunc_0 (30 B): matches/0x000d6020.cpp
// sym: ?vfunc_0@Closure1_d6020@fn_000d6020@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<MessageOverlay, void, const char *>::~Closure1() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d6020 {
struct Closure1_d6020 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_d6020::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d6020
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d6040 Closure1<MessageOverlay,void,const_char_*>::vfunc_2 (18 B): matches/0x000d6040.cpp
// sym: ?vfunc_2@Closure1_d6040@fn_000d6040@@QAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<MessageOverlay, void, const char *>::vfunc_2`.
namespace fn_000d6040 {
struct Closure1_d6040 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_d6040::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_d6040 * *)&this->f_20)->*(*(void (CActorManager_d6040::**)(const char *))&this->f_1c))(*b);
}
} // namespace fn_000d6040


// 0x000d6090 Closure7<MessageOverlay,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000d6090.cpp
// sym: ?vfunc_0@Closure7_d6090@fn_000d6090@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure7<MessageOverlay, void, const char *, const char *, const
// char *, const char *, const char *, const char *, const char *>::~Closure7() {}` stood for it, which natively defines
// no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d6090 {
struct Closure7_d6090 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure7_d6090::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d6090
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d60b0 Closure7<MessageOverlay,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (73 B): matches/0x000d60b0.cpp
// sym: ?vfunc_2@Closure7_d60b0@fn_000d60b0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure7<MessageOverlay, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2`.
namespace fn_000d60b0 {
struct Closure7_d60b0 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(const char *, const char *, const char *, const char *, const char *, const char *, const char *);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure7_d60b0::vfunc_2(void* __p0, void* __p1, void* __p2) { const char ** a = (const char **)__p1;

    const char* first = *a;
    const char* b = *++a;
    const char* c = *++a;
    const char* d = *++a;
    const char* e = *++a;
    const char* f = *++a;
    const char* g = *++a;
    ((*(MessageOverlay_d60b0 * *)&this->f_20)->*(*(void (MessageOverlay_d60b0::**)(const char *, const char *, const char *, const char *, const char *, const char *, const char *))&this->f_1c))(first, b, c, d, e, f, g);
}
} // namespace fn_000d60b0


// 0x000d6150 Closure3<MessageOverlay,void,const_char_*,int,math::Vector>::vfunc_2 (56 B): equivalent/0x000d6150.cpp [wrapped: conflict: Closure3; MessageOverlay]
// sym: ?vfunc_2@Closure3@fn_000d6150@@QAEXPAXPAUArguments@2@0@Z @d2144190d08a @w32681aba3ab9 @v421573433cee
namespace fn_000d6150 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<MessageOverlay,void,const_char_*,int,math::Vector>::vfunc_2 @ 0x000d6150
namespace math { struct Vector { float x,y,z; }; }
struct MessageOverlay { void FUN_000d6150(const char*, int, math::Vector); };
struct Arguments { const char *text; int count; math::Vector position; };
struct Closure3 { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
    void vfunc_0();
    void vfunc_1();
    void vfunc_2(void *unused, Arguments *args, void *unused2);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char padding[0x18])
    void (MessageOverlay::*method)(const char *, int, math::Vector);
    MessageOverlay *object;
};
void Closure3::vfunc_2(void *unused, Arguments *args, void *unused2) {
    (object->*method)(args->text, args->count, args->position);
}
} // namespace fn_000d6150


// 0x000d6190 FUN_000d6190 (76 B): matches/0x000d6190.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000d6190@@QAE@PBDPAVOwner_d6190@1@P821@AEXXZ@Z
namespace fn_000d6190 {
// (script1) Closure1<class MessageOverlay,void,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040b1c8[];   // Method1<class MessageOverlay,void,bool>
extern "C" char DAT_0040b248[];   // Closure1<class MessageOverlay,void,bool>
class Owner_d6190 {};
typedef void (Owner_d6190::*Fn_d6190)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_d6190 fn;
    Owner_d6190* owner;
    Closure1(const char* name, Owner_d6190* object, Fn_d6190 function);
};
Closure1::Closure1(const char* name, Owner_d6190* object, Fn_d6190 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_0040b1c8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_0040b248;
    owner = object;
}
} // namespace fn_000d6190


// 0x000d6200 Closure1<MessageOverlay,void,bool>::vfunc_2 (20 B): matches/0x000d6200.cpp
// sym: ?vfunc_2@Closure1_d6200@fn_000d6200@@QAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<MessageOverlay, void, bool>::vfunc_2`.
namespace fn_000d6200 {
struct Closure1_d6200 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(bool);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_d6200::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_d6200 * *)&this->f_20)->*(*(void (Actor_d6200::**)(unsigned char))&this->f_1c))(*arg);
}
} // namespace fn_000d6200


// 0x000d6280 Closure0<MessageOverlay,void>::vfunc_2 (11 B): matches/0x000d6280.cpp
// sym: ?vfunc_2@Closure0_d6280@fn_000d6280@@QAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<MessageOverlay, void>::vfunc_2`.
namespace fn_000d6280 {
struct Closure0_d6280 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_d6280::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_d6280 * *)&this->f_20)->*(*(void (CActorManager_d6280::**)())&this->f_1c))();
}
} // namespace fn_000d6280


// 0x000d6290 FUN_000d6290 (76 B): matches/0x000d6290.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000d6290@@QAE@PBDPAVOwner_d6290@1@P821@AEXXZ@Z
namespace fn_000d6290 {
// (script1) Closure1<class MessageOverlay,void,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040b1e8[];   // Method1<class MessageOverlay,void,float>
extern "C" char DAT_0040b268[];   // Closure1<class MessageOverlay,void,float>
class Owner_d6290 {};
typedef void (Owner_d6290::*Fn_d6290)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_d6290 fn;
    Owner_d6290* owner;
    Closure1(const char* name, Owner_d6290* object, Fn_d6290 function);
};
Closure1::Closure1(const char* name, Owner_d6290* object, Fn_d6290 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_0040b1e8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_0040b268;
    owner = object;
}
} // namespace fn_000d6290
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d6300 Closure1<MessageOverlay,void,float>::vfunc_2 (18 B): matches/0x000d6300.cpp
// sym: ?vfunc_2@Closure1_d6300@fn_000d6300@@QAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<MessageOverlay, void, float>::vfunc_2`.
namespace fn_000d6300 {
struct Closure1_d6300 : hulk_script::FunctionGenView {
    void (::MessageOverlay::*f_1c)(float);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_d6300::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_d6300 * *)&this->f_20)->*(*(void (CActorManager_d6300::**)(const char *))&this->f_1c))(*b);
}
} // namespace fn_000d6300


// 0x000d6370 Closure5<MessageOverlay,void,int,const_char_*,int,math::Vector,float>::vfunc_2 (69 B): equivalent/0x000d6370.cpp [wrapped: conflict: Arguments; Closure5; MessageOverlay]
// sym: ?vfunc_2@Closure5@fn_000d6370@@QAEXHPBUArguments@2@H@Z @875b921ad142 @w594de1369214 @vad007faeb160
namespace fn_000d6370 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure5<MessageOverlay,void,int,const_char_*,int,math::Vector,float>::vfunc_2 @ 0x000d6370
struct Vector { float x, y, z; };
struct MessageOverlay {
    void invoke(int number, const char *text, int kind, Vector position, float duration);
};
struct Arguments {
    int number;
    const char *text;
    int kind;
    Vector position;
    float duration;
};
struct Closure5 { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
    void vfunc_0();
    void vfunc_1();
    void vfunc_2(int unused, const Arguments *args, int unused2);
    char reserved[24];
    void (MessageOverlay::*method)(int, const char *, int, Vector, float);
    MessageOverlay *object;
};
void Closure5::vfunc_2(int unused, const Arguments *args, int unused2) {
    (object->*method)(args->number, args->text, args->kind, args->position, args->duration);
}
} // namespace fn_000d6370

namespace fn_f27eef39 {

// 0x000d6410 FUN_000d6410 (83 B): equivalent/0x000d6410.cpp
// sym: ?FUN_000d6410@Registry_d6410@fn_f27eef39@@QAEXPBDPAVMessageOverlay_d6410@2@P832@AEX0000000@Z@Z @e38d30a5b951 @wcbe43a24ae63 @v40efffec8494
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d6410 @ 0x000d6410
// FUN_000d6410 @ 0x000d6410  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d6410::FUN_000d6410(const char* a1, MessageOverlay_d6410* a2, Fn_d6410 a3) {
    typedef Closure7_d6410<MessageOverlay_d6410, void, const char*, const char*, const char*, const char*, const char*, const char*, const char*> Alloc_d6410;
    HULK_SIZE32(Alloc_d6410, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d6410));
    void* x = 0;
    if (m) {
        ((Raw_d6410*)m)->FUN_000d5550(a1, a3);
        x = new (m) Closure7_d6410<MessageOverlay_d6410, void, const char*, const char*, const char*, const char*, const char*, const char*, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000d6470 FUN_000d6470 (83 B): equivalent/0x000d6470.cpp
// sym: ?FUN_000d6470@Registry_d6470@fn_f27eef39@@QAEXPBDPAVMessageOverlay_d6470@2@P832@AEX0HVVector_d6470@math@@@Z@Z @7b3840338a5e @w86ca6e81286a @v70f2e522bc42
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d6470 @ 0x000d6470
// FUN_000d6470 @ 0x000d6470  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d6470::FUN_000d6470(const char* a1, MessageOverlay_d6470* a2, Fn_d6470 a3) {
    typedef Closure3_d6470<MessageOverlay_d6470, void, const char*, int, math::Vector_d6470> Alloc_d6470;
    HULK_SIZE32(Alloc_d6470, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d6470));
    void* x = 0;
    if (m) {
        ((Raw_d6470*)m)->FUN_000d5660(a1, a3);
        x = new (m) Closure3_d6470<MessageOverlay_d6470, void, const char*, int, math::Vector_d6470>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f27eef39

// 0x000d6520 FUN_000d6520 (109 B): matches/0x000d6520.cpp [wrapped: conflict: Closure0; MessageOverlay; Method0]
// sym: ?FUN_000d6520@Registry_d6520@fn_000d6520@@QAEXPBDPAVOwner_d6520@2@P832@AEXXZ@Z
namespace fn_000d6520 {
// (script1) ScriptHandler's registration of a Closure0<class MessageOverlay,void>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_0040b1d8[];   // Method0<class MessageOverlay,void>
extern "C" char DAT_0040b258[];   // Closure0<class MessageOverlay,void>
class Owner_d6520 {};
typedef void (Owner_d6520::*Fn_d6520)();
struct Closure_d6520 : hulk_script::ScriptFunction {
    Fn_d6520 fn;
    Owner_d6520* owner;
    Closure_d6520(const char* name, Owner_d6520* object, Fn_d6520 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_0040b1d8;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
        vftable = DAT_0040b258;
        owner = object;
    }
};
struct Registry_d6520 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_000d6520(const char* name, Owner_d6520* object, Fn_d6520 function);
};
void Registry_d6520::FUN_000d6520(const char* name, Owner_d6520* object, Fn_d6520 function) {
    Closure_d6520* c = new Closure_d6520(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_000d6520
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f27eef39 {

// 0x000d65e0 FUN_000d65e0 (83 B): equivalent/0x000d65e0.cpp
// sym: ?FUN_000d65e0@Registry_d65e0@fn_f27eef39@@QAEXPBDPAVMessageOverlay_d65e0@2@P832@AEXH0HVVector_d65e0@math@@M@Z@Z @3ab0dbad306f @w482e20843b7f @v69ba479d2192
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000d65e0 @ 0x000d65e0
// FUN_000d65e0 @ 0x000d65e0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_d65e0::FUN_000d65e0(const char* a1, MessageOverlay_d65e0* a2, Fn_d65e0 a3) {
    typedef Closure5_d65e0<MessageOverlay_d65e0, void, int, const char*, int, math::Vector_d65e0, float> Alloc_d65e0;
    HULK_SIZE32(Alloc_d65e0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_d65e0));
    void* x = 0;
    if (m) {
        ((Raw_d65e0*)m)->FUN_000d5890(a1, a3);
        x = new (m) Closure5_d65e0<MessageOverlay_d65e0, void, int, const char*, int, math::Vector_d65e0, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f27eef39

// 0x000d68e0 MessageOverlay::vfunc_1 (8 B): matches/0x000d68e0.cpp
// sym: ?vfunc_1@MessageOverlay@@UAEXXZ
void MessageOverlay::vfunc_1() {
    this->f_7bc = 1;
}


// 0x000d68f0 MessageOverlay::vfunc_2 (8 B): matches/0x000d68f0.cpp
// sym: ?vfunc_2@MessageOverlay@@UAEXXZ
void MessageOverlay::vfunc_2() {
    this->f_7bc = 0;
}


// 0x000d6900 MessageOverlay::vfunc_0 (31 B): matches/0x000d6900.cpp
// sym: ?f2@NonCopyable_d6900@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_d6900* pure3d::NonCopyable_d6900::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0040a47c;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}


// 0x000d6970 FUN_000d6970 (101 B): equivalent/0x000d6970.cpp [wrapped: conflict: COverlayManager]
// sym: ??0COverlayManager@fn_000d6970@@QAE@XZ @9b17649b1575 @w1c9100588a19 @v65f11f368645
namespace fn_000d6970 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000d6970 @ 0x000d6970

struct Device_d6970 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual float v16();
};
// (x64t9-mgr) include/decls/managers.h's HulkOverlayManager: the view, the state, eight items, the camera
struct COverlayManager {
 virtual void* slot0_000d6e70(char);
 void* field4;
 unsigned int field8;
 void* entries[8];
 void* field2c;
 COverlayManager();
};
HULK_MGR_SAME(COverlayManager, HulkOverlayManager);
COverlayManager::COverlayManager() {
 field4=0; field8=0;
 for (int i=0;i<8;++i) entries[i]=0;
 field2c=0;
 DAT_004de600=22.3f;
 float scale=(*(Device_d6970**)&DAT_0052c2a4)->v16();
 DAT_004de604=17.3f;
 DAT_004de600=scale*DAT_004de600*0.75f;
}
} // namespace fn_000d6970

namespace fn_f27eef39 {

// 0x000d6a20 FUN_000d6a20 (253 B): equivalent/0x000d6a20.cpp
// sym: ?FUN_000d6a20@Target_d6a20@fn_f27eef39@@QAEXXZ @6b5bbcd43f60 @wd7ccc883cc32 @vbd0f73941c03
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_000d6a20 @ 0x000d6a20
void Target_d6a20::FUN_000d6a20(){
 Node* p=(Node*)FUN_0008d690(sizeof(HulkView)); /* (recs1) the View record (0x140 on the 32-bit builds) */ view=p?p->FUN_00294880():0; ((Node*)view)->v0(); ((Node*)view)->clearColour=0; ((Node*)view)->FUN_00293e90(0xff282828); ((Node*)view)->clearMask=2;
 p=(Node*)FUN_00263ea0((sizeof(::pure3d::VectorCamera)+7)/8*8); /* (allocsize1) gen's VectorCamera (0xf4), 8-rounded: 0xf8 */ camera=p?p->FUN_002939a0():0; ((Node*)camera)->v0(); ((Node*)camera)->v7(0.1f); ((Node*)camera)->v9(100.0f); ((Node*)camera)->FUN_00293af0((int *)(Data_d6a20 *)(((Data_d6a20*)&DAT_004a0a74))); ((Node*)camera)->FUN_00293a90((int *)(Data_d6a20 *)(((Data_d6a20*)&DAT_004a0a80)));
 float aspect=(*(Manager_d6a20**)&DAT_0052c2a4)->v16(); float a,b; FUN_0009f790(90.0f,aspect,&a,&b); ((Node*)camera)->v5(a*(*(float*)&DAT_003f32b8),1.0f); ((Node*)view)->FUN_00294980((Node*)camera);
}


// 0x000d6b20 FUN_000d6b20 (141 B): matches/0x000d6b20.cpp
// sym: ?FUN_000d6b20@Target_d6b20@fn_f27eef39@@QAEXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000d6b20 @ 0x000d6b20
void Target_d6b20::FUN_000d6b20(hulk_uintptr unused) {
 state = 0;
 float time = (*(Clock_d6b20**)&DAT_0052c2a4)->sample();
 float angle, other;
 FUN_0009f790(90.0f, time, &angle, &other);
 effect->set(angle * 0.0174532924f, 1.0f);
 owner->FUN_00294980(effect);
 DAT_004de600 = 22.3f;
 DAT_004de600 = (*(Clock_d6b20**)&DAT_0052c2a4)->sample() * DAT_004de600 * 0.75f;
}


// 0x000d6c30 FUN_000d6c30 (63 B): matches/0x000d6c30.cpp
// sym: ?Run@X@fn_f27eef39@@QAEXM@Z
void X::Run(float) {
    if (state != 3) {
        void* p = obj->p;
        use_000c5a60(__RTDynamicCast(p, 0, (void*)(hulk_at_0049e11c), (void*)(hulk_at_004a0a40), 0));
        if (state == 2)
            state = 0;
    }
}

} // namespace fn_f27eef39

// 0x000d6c70 FUN_000d6c70 (288 B): equivalent/0x000d6c70.cpp [wrapped: conflict: Gfx]
// sym: ?run@Target_d6c70@fn_000d6c70@@QAEXXZ @0a72b72efb43 @w125c0023f3f3 @v0b5e0fbc8607
namespace fn_000d6c70 {
// STATUS: equivalent (tools/equiv.py level 3: 7465 inputs, branch coverage 6/6)
// FUN_000d6c70 @ 0x000d6c70
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

struct Clock_d6c70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual float v16(); };
struct Shape_d6c70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(float,float); };
struct Item_d6c70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); unsigned char active; };
struct Scene_d6c70 { void FUN_00294980(Shape_d6c70*); void FUN_00293ef0(); void FUN_00294080(); };
struct Gfx {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void setMode(int); virtual int getMode(); virtual void setFlag(unsigned int); virtual unsigned char getFlag();
};
  
extern "C" void __cdecl FUN_0009f790(float,float,float*,float*);
struct Target_d6c70 { char pad0[4]; Scene_d6c70* scene; char pad8[4]; Item_d6c70* items[8]; Shape_d6c70* shape; void run(); };
void Target_d6c70::run() {
union { float f; unsigned int bits; unsigned char bytes[4]; } saved;
saved.f=(*(Clock_d6c70**)&DAT_0052c2a4)->v16();
float a,b; FUN_0009f790(90.0f,saved.f,&a,&b);
shape->v5(a*0.0174532924f,1.0f);
scene->FUN_00294980(shape);
DAT_004de600=22.3f;
DAT_004de600=(*(Clock_d6c70**)&DAT_0052c2a4)->v16()*DAT_004de600*0.75f;
scene->FUN_00293ef0();
saved.bytes[0]=DAT_0052c2a8->getFlag();
DAT_0052c2a8->setFlag(0);
int mode=DAT_0052c2a8->getMode();
DAT_0052c2a8->setMode(1);
for(int i=0;i<8;++i) { Item_d6c70* item=items[i]; if(item && item->active) item->v4(); }
DAT_0052c2a8->setFlag(saved.bits);
DAT_0052c2a8->setMode(mode);
scene->FUN_00294080();
}
} // namespace fn_000d6c70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f27eef39 {

// 0x000d6d90 FUN_000d6d90 (63 B): matches/0x000d6d90.cpp
// sym: ?Add@Slots_d6d90@fn_f27eef39@@QAEMH@Z
hulk_freg Slots_d6d90::Add(int value) {
    int i = 0;
    do {
        if (values[i] == 0) {
            values[i] = value;
            return (float)(i + 1) * 0.01f;
        }
        ++i;
    } while (i < 8);
    return (float)(i + 1) * 0.01f;
}

} // namespace fn_f27eef39

// 0x000d6dd0 FUN_000d6dd0 (45 B): matches/0x000d6dd0.cpp
// sym: ?FUN_000d6dd0@Slots_d6dd0@owners@@QAEXH@Z
void owners::Slots_d6dd0::FUN_000d6dd0(hulk_intptr value) {
    for (int i = 0; i < 8; ++i) {
        if (values[i] == ((int)value)) {
            values[i] = 0;
            return;
        }
    }
}

