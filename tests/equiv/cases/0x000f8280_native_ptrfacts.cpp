// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// (regress, tri2) ptrfacts: `call [0x4de948]` through a fuzzed .bss function pointer: the code its fuzzed value hits (0x00200000, thiscall) is not the callee, so ecx is no argument
// object 0x000f1570..0x000f8690 (kind game, layer game, confidence high), dominant class FEThingsBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5892d97 {
#define TREE_TU_END }
namespace fn_f5892d97 {} using namespace fn_f5892d97;
namespace fn_f5892d97 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5892d97 {
struct Controller_f1570 { void FUN_000f8b00(float); };
struct Interface_f1570 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39(); virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47(); virtual void slot48(int); };
struct Link_f1570 { char pad[4]; Interface_f1570* iface; };
struct Owner_f1570 { char pad[8]; Link_f1570* link; };
class Curve_f1650 {
public:
    virtual void v0();
    virtual float v1(int a, int b);
};
class Sink_f1650 { public: void FUN_000f8b00(float v); };
class Mode_f1650 {
public:
    virtual void v0();
};
class C_f1650 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(int mode);
    char pad[0x182c - 4];
    Curve_f1650 *curve;
};
class B_f1650 { public: char pad[4]; C_f1650 *c; };
class A_f1650 { public: char pad[8]; B_f1650 *b; };
class Slider_f1650 {
public:
    char pad0[0x14];
    A_f1650 *a;
    char pad18[0x150 - 0x18];
    float value;
    int state;
    char pad158[4];
    float lo;
    float hi;
    char pad164[0x170 - 0x164];
    int curveArg0;
    int curveArg1;
    float rate;
    char pad17c[4];
    Sink_f1650 *sink;
    void FUN_000e9e60();
    void FUN_000f1650(float dt);
};
class Curve_f1890 {
public:
    virtual void v0();
    virtual float v1(int a, int b);
};
class Sink_f1890 { public: void FUN_000f8b00(float v); };
class Mode_f1890 {
public:
    virtual void v0();
};
class C_f1890 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(int mode);
    char pad[0x182c - 4];
    Curve_f1890 *curve;
};
class B_f1890 { public: char pad[4]; C_f1890 *c; };
class A_f1890 { public: char pad[8]; B_f1890 *b; };
class Slider_f1890 {
public:
    char pad0[0x14];
    A_f1890 *a;
    char pad18[0x150 - 0x18];
    float value;
    int state;
    char pad158[4];
    float lo;
    float hi;
    char pad164[0x170 - 0x164];
    int curveArg0;
    int curveArg1;
    float rate;
    char pad17c[4];
    Sink_f1890 *sink;
    void FUN_000e9e60();
    void FUN_000f1890(float dt);
};
struct HSlider_nv_f19e0 {
    void UpdateA_000f1650(float);
    void UpdateB_000f1890(float);
};
extern "C" float(__cdecl* hulk_at_004de948)();
extern void* hulk_at_0040c554[];
class TextSelector_f1b70 {
  public:
    void Destroy_000ebca0(); // FUN_00236d60, __thiscall, this in ecx
};
class MenuSelector_f1b70 : public TextSelector_f1b70 {
  public:
    MenuSelector_f1b70* vfunc_5(signed char flags);
};
extern void* hulk_at_0040c5c4[];
class FEObject_f1ba0 {
  public:
    void Destroy_000e9030(); // FUN_00236d60, __thiscall, this in ecx
};
class MapThing_f1ba0 : public FEObject_f1ba0 {
  public:
    MapThing_f1ba0* vfunc_5(signed char flags);
};
struct Vec3_f1bd0 { float x, y, z; };
struct ArgPair {
    union { int i; float f; unsigned int u; } x;
    union { int i; float f; } y;
};
struct Layout_f1bd0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void GetExtent(ArgPair *out, void *owner);   // slot 15
};
extern "C" void __cdecl FUN_000f69e0(void *, void *);
class Widget_f1bd0 {
public:
    char pad00[0x14];
    Layout_f1bd0 *layout;          // 0x14
    char pad18[0x38];
    int source;              // 0x50
    float scaleX;            // 0x54
    float scaleY;            // 0x58
    char pad5c[0xc0];
    int argA;                // 0x11c
    int argB;                // 0x120
    float argC;              // 0x124
    void FUN_000f1bd0(ArgPair args, float c);
};
extern void* hulk_at_0040c84c[];
class Ref_f1d30 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEContainer_f1d30 {
  public:
    void* vptr;
    void Fin_000eeac0();
};
void Free_0008d330(void*) throw();
struct Sub_f1d30 {
    char c;
};
void __fastcall SubFini(Sub_f1d30*) throw();
void __fastcall SubFini2(Sub_f1d30*) throw();
void __fastcall SubFini3(Sub_f1d30*) throw();
class FEDialog_f1d30 : public FEContainer_f1d30 {
  public:
    char p9a4[2464];
    Ref_f1d30* m9a4;
    FEDialog_f1d30* f(unsigned char fl);
};
extern "C" char DAT_0040c61c[];
extern void* __cdecl alloc_0008d690(unsigned int);
class TextLabel_f1e00 {
  public:
    virtual void f0();
    void initialize_000e2860(int);
    char pad[0x118 - 4];
    volatile int a, b, c, d;
};
class DynamicCaster_f20f0 {
  public:
    virtual void Fna_000f1030(void*);
};
struct HSlider_nv_f2150 {
    void Change2_000f1570();
    void Change6_000f17b0();
};
struct ThisCall_000f1570 {
    void action1570_000f1570();
};
struct ThisCall_000f17b0 {
    void action17b0_000f17b0();
};
class DynamicCaster_f2340 {
  public:
    virtual void Cast_000f0f70(void*);
};
class Inventory {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual int Load(DynamicCaster_f2340*, __int64);
};
extern "C" __int64 __cdecl Lookup(void*);
extern "C" __int64 __cdecl Convert(int);
class DynamicCaster_f2370 {
  public:
    virtual void f0_000f0fa0(void*);
    virtual void f1();
    virtual void f2_000f0fd0(void*);
    virtual int f3();
};
class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(DynamicCaster_f2370*, __int64);
};
class DynamicCaster_f23d0 {
  public:
    virtual void Fnf_000f1000(void*);
};
class Inv {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int use(DynamicCaster_f23d0*, __int64);
};
extern __int64 __cdecl fetch_0027b020(void*);
struct Result_f26e0 {
  public:
    virtual void method0();
};
struct Obj_f26e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Result_f26e0* cast(void* caster, __int64 val);
};
__int64 __cdecl fun_p2_0027b020(int p);
struct DynamicCaster {
  public:
    virtual void f0_0007ce10(void*);
};
struct FEAnimation_f26e0 {
    virtual void bv();
    int a;
    int b;
    FEAnimation_f26e0(int x, int y);
};
struct FETextureAnimation_f26e0 : FEAnimation_f26e0 {
    Result_f26e0* m_c;
    FETextureAnimation_f26e0(int p1, int p2);
};
extern "C" void* __cdecl FUN_0008d690(uint);
struct FEPoseAnimationInvisible_nv_f2740 {
    int make_000f24d0(void*, void*);
};
extern void* Alloc_0008d690(unsigned int);
class Factory_f27a0 {
  public:
    int Create_000f2460(int, int);
};
struct FEParticleAnimation_nv_f2800 {
    int Build_000f2680(int, int, int);
};
struct FETextureAnimation_nv_f2860 {
    int make_000f26e0(void*, void*);
};
struct FEShaderAnimation_nv_f28c0 {
    int make_000f2560(void*, void*);
};
struct FEBillboardAnimation_nv_f2920 {
    int Create_000f25f0(int, int);
};
class Obj_f2d40 {
  public:
    virtual void F();
};
struct DynamicCaster_f2d40 {
    virtual void FnC_000f1000(void*);
};
class Manager_f2d40 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual Obj_f2d40* Create(const DynamicCaster_f2d40&, unsigned long long);
};
extern unsigned long long __cdecl GetArg_0027b020(void*);
class Owner_f2d40 {
    char pad[0x9a4];

  public:
    Obj_f2d40* slots[4];
    void Run(void*);
};
struct Node_f4790 {
    Node_f4790* FUN_000fad90();
    char FUN_000f9ef0();
    void FUN_000fa0a0();
};
struct Item_f4790 {
};
struct Factory_f4790 {
};
struct Message_f4790 {
    virtual void m0();
    virtual unsigned int GetId();
};
} // namespace fn_f5892d97
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned int n);
#endif
namespace fn_f5892d97 {
extern "C" int __cdecl FUN_00266da0(int v);
struct Node {
  public:
    virtual void _m_vf0();
    virtual unsigned vfunc_1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual int count();
    virtual Node* child(int index);
};
struct Slot_f5fa0 {
    int a, b, c, d;
};
struct Script_f5fa0 {
    void FUN_000f9a80();
};
struct Handle_f5fa0 {
    void *first;
    void *second;
};
struct Tail_f5fa0 {
    int f00;
    char pad04[0x0c];
    int f10;
    int f14;
    int f18;
    int f1c;
};
struct Table_f5fa0 {
    Slot_f5fa0 slots[0x80];
    void FUN_000f9d20();
};
} // namespace fn_f5892d97
namespace DollyScript {
class CScriptParser_f5fa0 {
public:
    virtual ~CScriptParser_f5fa0() {
        table.FUN_000f9d20();
    }
    Script_f5fa0 *script;
    int a, b, c;
    unsigned char d, e;
    char pad16[2];
    Handle_f5fa0 handle;
    Table_f5fa0 table;
    Tail_f5fa0 tail;
    CScriptParser_f5fa0 *FUN_000faa10(Script_f5fa0 *script);
    char FUN_000f9e50();
    Node *FUN_000fb110();
    int FUN_000fad90();
};
}
namespace fn_f5892d97 {
struct Obj266 {
    int FUN_00266700();
};
struct Sink_f5fa0 {
    void FUN_00266220(int v);
};
struct Loader_f5fa0 {
    void FUN_00265920(int v, Obj266 **out, int flag);
};
struct Frame_f5fa0 {
    Obj266 *w;
    char parser[0x840];
};
class Runner_f5fa0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64(int a, int b, int c);
    char pad04[0x2105 - 4];
    char name[0x100];
    char active;
    char pad2206[2];
    int count;
    int f220c;
    void FUN_000f5b20(DollyScript::CScriptParser_f5fa0 *p, int a, int b, Node *node);
    void FUN_000f5fa0(const char *src, int arg);
};
struct API {
    int FnB_002843a0(int, int);
};
struct V {
    int a;
    int b;
    int c;
};
struct S_f6370 {
    API* api;
    int b;
    int c;
    int d;
    V Target();
};
extern int __fastcall Fng_002961d0(void*);
struct S_f6420 {
    void* p;
    volatile int a;
    char pad[0x3fc];
    volatile int count;
    int result;
    volatile int last;
    void f();
};
struct Frame_f6460 { Node* node; int index; };
struct Traversal {
 int reserved;
 Frame_f6460 frames[128];
 int depth;
 Node* current;
 int index;
 Node* FUN_000f6460();
};
struct Triple_f6530 { unsigned x,y,z; };
struct Object {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void d(DynamicCaster_f20f0*, void*, void*);
    virtual void _m_vf4();
    virtual void setPair(unsigned a, unsigned b);
    virtual void getPair(unsigned* a, unsigned* b);
    virtual void setFirst(float a);
    virtual float getFirst();
    virtual void setSecond(float a);
    virtual float getSecond();
    char _m_pad_4[0x10];
    Owner_f1570* owner;
    char _m_pad_18[0xb8];
    Triple_f6530 atD0;
    Triple_f6530 atDC;
    Triple_f6530 atE8;
    char _m_pad_f4[0x5c];
    float value;
    int flag;
    char _m_pad_158[0x4];
    float lower;
    float upper;
    char _m_pad_164[0x4];
    int mode;
    float rate;
    char _m_pad_170[0x10];
    Controller_f1570* controller;
    void FUN_000e9e60();
    void update();
    void FUN_00293ac0(Triple_f6530*);
};
} // namespace fn_f5892d97
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f5892d97 {
struct Mat_f6680;
struct V3_f6680 {
    float x, y, z;
    void FUN_0022d180();
};
struct Mat_f6680 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_f6680 *axis, float angle);
};
struct Obj_f6680 {
    char pad0[0xdc];
    V3_f6680 b;
    V3_f6680 a;
};
class Arg_f6850 {
  public:
    virtual void F();
    int FnG_002961d0();
};
class Obj_f6850 {
  public:
    Arg_f6850* mArg;
    volatile int mOne;
    char pad[0x3fc];
    volatile int mIndex;
    int m408;
    int m40c;
    Obj_f6850* Run(Arg_f6850*);
};
class X_f68a0 {
  public:
    virtual void a();
    virtual void b();
};
struct C_f68a0 {
    X_f68a0* p;
    void f();
};
struct Vec3_f69e0 { float x, y, z; };
union FloatBits_f69e0 {
    float f;
    unsigned int u;
};
struct Box_f69e0 {
    Vec3_f69e0 min;
    Vec3_f69e0 max;
};
struct Bounds_f69e0 {
    char pad00[0x14];
    Box_f69e0 box;
};
struct Input_f6a70 {
    char p0[0x10];
    float angle;
    char p14[0xc4];
    float value;
};
struct Camera {
    char p[8];
    float value;
};
class Service_f6a70 {
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
    virtual float Get();
};
struct T_f6ef0 {
    int a[0x22 + 1];
    int f88;
    int pad[1];
    int i[1];
    int X_f6ef0();
    int m[0x100];
};
struct X_f6ef0 {
    int w[0x48];
    X_f6ef0();
};
extern void __cdecl R0_0008d340(void*);
extern void __cdecl R1_0008d330(void*);
extern void __cdecl R2_0008d340(void*);
extern void __cdecl R3_0008d340(void*);
class Item_f6f60 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_f6f60 {
  public:
    void* p0;
    char a[8];
    void* pC;
    char b[8];
    void* p18;
    char c[8];
    Item_f6f60* items[25];
    int count;
    char d[0x90];
    void* p11c;
    void Clear();
};
extern "C" void* __cdecl allocbuf_0008d6d0(int);
extern "C" void __cdecl freebuf(void*);
class Buffer_f6ff0 {
  public:
    void* data;
    int capacity;
    int size;
    void Reserve(int n);
};
class Stream {
public:
    unsigned int FUN_00263fc0();                                    // read position
    unsigned int FUN_00263fb0();                                    // end position
                  // read one element
};
union BufferSlot {
    unsigned short* buffer;
    unsigned short ch;
};
class Thing_f7110 {
  public:
    char pad[0x14];
    int a;
    char pad2[8];
    int b;
};
extern "C" const char* __cdecl FUN_000f7120(int key);
struct KeyEntry {
    unsigned int lo, hi;
};
class KeyTable_f7240 {
public:
    char pad00[0x18];
    KeyEntry *entries;
    char pad1c[4];
    int count;
    int FUN_000f7240(unsigned int lo, unsigned int hi);
};
typedef unsigned short ushort_f7810;
typedef unsigned char uchar_f7810;
class Item_f7850 {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner_f7850 {
  public:
    char pad[0x24];
    Item_f7850* items[25];
    int count;
    void Cleanup();
};
struct Item_f78f0 {
    unsigned int a, b, c, d;
};
typedef unsigned int U32_f7960;
void ReleaseThing_0008d340(U32_f7960);
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
extern void* __cdecl FUN_0008d6d0(int);
extern void __cdecl FUN_000fb690(void*, const short*, int);
void release_0008d340(int);
class Item_f7ce0 {
  public:
    virtual void a();
    virtual void Release();
};
class Obj_f7ce0 {
  public:
    char pad[0x24];
    Item_f7ce0* items[25];
    int count;
    void Clear();
};
class Callback_f7d60 {
  public:
    virtual void v0(void* p);
};
class Metrics_f7d60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    virtual float v8();
    virtual float v9(unsigned short* text);
    virtual void v10();
    virtual void v11();
    virtual float v12();
};
class Layer_f7d60 {
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
    Layer_f7d60* layer;
    void FUN_00293d40(float x, float y, float z);
    void FUN_00293da0(float x, float y, float z);
};
void FUN_000fb690(unsigned short* dst, const unsigned short* src, int max);
class TextBox_f7d60 {
  public:
    char pad[0x24];
    Metrics_f7d60* sub[2];
    void FUN_000f7330(unsigned short* text, int index, float scale, int align, Callback_f7d60* cb);
    void FUN_000f7d60(const unsigned short* text, int index, float scale, int align, int mode, Callback_f7d60* cb);
};
struct Inner_f7fe0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void GetValue(int* out);
};
struct Owner_f7fe0 { char pad[0x24]; Inner_f7fe0* inner; };
struct Slot_f7fe0 { float weight; int a; int b; int value; };
struct Blender_f7fe0 {
    Owner_f7fe0* owner; int current; Slot_f7fe0 slots[8]; int index; float scale;
    Blender_f7fe0* FUN_000f7fe0(Owner_f7fe0* o);
};
class Obj_f83c0 {
  public:
    char pad[0x10];
    int initArg;
    int field14;
    char pad18[8];
    int field20;
};
struct ThisCall_000f79a0 {
};



// 0x000f8280 FUN_000f8280 (305 B): equivalent/0x000f8280.cpp [wrapped: conflict: DAT_004de948]
// sym: ?FUN_000f8280@Gradient@fn_000f8280@@QAEXIII@Z
namespace fn_000f8280 {
// STATUS: equivalent (tools/equiv.py level 3: 18624 inputs, branch coverage 10/10)
// FUN_000f8280 @ 0x000f8280
struct ColorSlot {
    unsigned int color;
    char pad[12];
};

extern float (*DAT_004de948)();

struct Gradient {
    char pad0[0x14];
    ColorSlot slots[7];
    char pad84[4];
    int current;
    void FUN_000f8280(unsigned int colorA, unsigned int colorB, unsigned int ticks);
};

void Gradient::FUN_000f8280(unsigned int colorA, unsigned int colorB, unsigned int ticks)
{
    int a[3];
    int b[3];
    int res[3];

    a[0] = (colorA >> 16) & 0xff;
    a[1] = (colorA >> 8) & 0xff;
    a[2] = colorA & 0xff;
    b[0] = (colorB >> 16) & 0xff;
    b[1] = (colorB >> 8) & 0xff;
    b[2] = colorB & 0xff;

    hulk_freg rate = DAT_004de948();
    if (rate > 1.0f)
        rate = 1.0f;
    else if (rate == 0.0f)
        rate = 0.001f;

    hulk_freg scale = 1.0f / rate;
    hulk_freg half = 0.5f * scale;
    unsigned int period = (unsigned int)(__int64)(int)(__int64)scale;
    unsigned int rem = ticks % period;
    hulk_freg phase = (half - (double)rem) / scale;
    hulk_freg t;
    if (phase > 0.0f)
        t = phase + phase;
    else
        t = phase * -2.0f;

    for (int i = 0; i < 3; i++)
        res[i] = (int)(__int64)((double)a[i] - (double)(a[i] - b[i]) * t);

    slots[current].color = (((0xffffff00u | res[0]) << 8 | res[1]) << 8) | res[2];
}
} // namespace fn_000f8280

namespace fn_f5892d97 {

} // namespace
} // namespace
