// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
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
extern void* __cdecl alloc_0008d690(hulk_uintptr);
class TextLabel_f1e00 {
  public:
    virtual void f0();
    void initialize_000e2860(int);
    char pad[0x118 - 4];
    volatile int a, b, c, d;
};
class DynamicCaster_f20f0 {
  public:
    virtual void a();
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
    virtual void Cast();
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
    virtual void f0();
    virtual void f1();
    virtual void f2();
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
    virtual void f();
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
    virtual void f0();
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
extern void* Alloc_0008d690(hulk_uintptr);
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
    virtual void C();
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
extern "C" hulk_intptr __cdecl FUN_000f7120(int key);
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


// 0x000f1570 FUN_000f1570 (224 B): equivalent/0x000f1570.cpp
// sym: ?update@Object@fn_f5892d97@@QAEXXZ @9c91a6770426 @wd8a3bd066334
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000f1570 @ 0x000f1570
void Object::update() {
 if (!mode) { if (rate == 0.0f) value += 1.0f; else value += rate; } else flag = 1;
 float result;
 if (value >= lower && value <= upper) result = value;
 else if (value > upper) result = upper;
 else result = lower;
 value = result;
 if (controller) controller->FUN_000f8b00(result);
 owner->link->iface->slot48(3);
 FUN_000e9e60();
}


// 0x000f1650 FUN_000f1650 (340 B): equivalent/0x000f1650.cpp
// sym: ?FUN_000f1650@Slider_f1650@fn_f5892d97@@QAEXM@Z @7b1f6d44aab9 @wb5d3ea11e385
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 14/16, incomplete)
// FUN_000f1650 @ 0x000f1650
void Slider_f1650::FUN_000f1650(float dt)
{
    state = 1;
    double x = a->b->c->curve->v1(curveArg0, curveArg1);
    double curve = x * x * x * x * x * x * x;
    double k = rate * 0.5f + 0.01f;
    if (k >= 0.0) {
        if (k > 1.0)
            k = 1.0;
    } else {
        k = 0.0;
    }
    double v = value + (hi - lo) * (k * curve) * dt * 0.5f;
    if (v > hi)
        v = hi;
    value = v;
    float w;
    float cur = *(volatile float *)&value;
    if (cur >= lo && cur <= hi)
        w = cur;
    else if (cur > hi)
        w = hi;
    else
        w = lo;
    value = w;
    if (sink)
        sink->FUN_000f8b00(w);
    a->b->c->v48(3);
    FUN_000e9e60();
}

} // namespace fn_f5892d97

// 0x000f17b0 FUN_000f17b0 (216 B): matches/0x000f17b0.cpp [wrapped: conflict: Object]
// sym: ?FUN_000f17b0@Object@fn_000f17b0@@QAEHXZ
namespace fn_000f17b0 {
struct Receiver_f17b0 {
    void FUN_000f8b00(float);
};
struct Renderer_f17b0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(int);
};
struct Link_f17b0 {
    char pad[4];
    Renderer_f17b0* renderer;
};
struct Owner_f17b0 {
    char pad[8];
    Link_f17b0* link;
};
struct Object {
    char pad0[0x14];
    Owner_f17b0* owner;
    char pad1[0x138];
    float value;
    int state;
    char pad2[4];
    float minimum;
    float maximum;
    char pad3[4];
    int active;
    float decrement;
    char pad4[0x10];
    Receiver_f17b0* receiver;
    int FUN_000e9e60();
    int FUN_000f17b0();
};
int Object::FUN_000f17b0() {
    if (!active)
        value -= (decrement == 0.0f ? 1.0f : decrement);
    else
        state = 2;
    float result;
    if (value >= minimum && value <= maximum)
        result = value;
    else if (value > maximum)
        result = maximum;
    else
        result = minimum;
    Receiver_f17b0* r = receiver;
    value = result;
    if (r)
        r->FUN_000f8b00(result);
    owner->link->renderer->slot48(3);
    return FUN_000e9e60();
}
} // namespace fn_000f17b0

namespace fn_f5892d97 {

// 0x000f1890 FUN_000f1890 (336 B): equivalent/0x000f1890.cpp
// sym: ?FUN_000f1890@Slider_f1890@fn_f5892d97@@QAEXM@Z @315980a8c044 @we26f575876e8
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 16/16)
// FUN_000f1890 @ 0x000f1890
void Slider_f1890::FUN_000f1890(float dt)
{
    state = 2;
    hulk_freg x = a->b->c->curve->v1(curveArg0, curveArg1);
    hulk_freg curve = x * x * x * x * x * x * x;
    hulk_freg k = rate * 0.5f + 0.01f;
    if (k >= 0.0f) {
        if (k > 1.0f)
            k = 1.0f;
    } else {
        k = 0.0f;
    }
    hulk_freg v = value - (hi - lo) * (k * curve) * dt * 0.5f;
    if (v < lo)
        v = lo;
    value = v;
    float w;
    if (value >= lo && value <= hi)
        w = value;
    else if (value > hi)
        w = hi;
    else
        w = lo;
    value = w;
    if (sink)
        sink->FUN_000f8b00(w);
    a->b->c->v48(3);
    FUN_000e9e60();
}

} // namespace fn_f5892d97

// 0x000f19e0 HSlider::vfunc_4 (135 B): matches/0x000f19e0.cpp
// sym: ?vfunc_4@HSlider@@UAEXXZ
void HSlider::vfunc_4() {
    if (this->f_154 == 1) {
        if ((*(float *)&this->f_150) < this->f_160) {
            this->f_178 = hulk_at_004de948() + this->f_178;
            float x = hulk_at_004de948();
            ((HSlider_nv_f19e0*)this)->UpdateA_000f1650(x + x);
        }
    } else if (this->f_154 == 2) {
        if ((*(float *)&this->f_150) > this->f_15c) {
            this->f_178 = hulk_at_004de948() + this->f_178;
            float x = hulk_at_004de948();
            ((HSlider_nv_f19e0*)this)->UpdateB_000f1890(x + x);
        }
    }
}


// 0x000f1a70 FUN_000f1a70 (52 B): matches/0x000f1a70.cpp
// sym: ?FUN_000f1a70@Obj_f1a70@owners@@QAEXM@Z
void owners::Obj_f1a70::FUN_000f1a70(float x) {
    if (x >= low && x <= high) {
        value = x;
        update();
    }
}


// 0x000f1ab0 FUN_000f1ab0 (122 B): equivalent/0x000f1ab0.cpp [wrapped: conflict: pure3d::CompositeDrawable; pure3d::Entity]
// sym: ?FUN_000f1ab0@Player_f1ab0@fn_000f1ab0@@QAEXPAVSource_f1ab0@2@@Z @6f9bc00047db @we31098fa9537
namespace fn_000f1ab0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000f1ab0 @ 0x000f1ab0
class Part_f1ab0 {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual float GetLength();
};

struct Anim_f1ab0 {
    char pad0[0x24];
    Part_f1ab0** begin;   // 0x24
    Part_f1ab0** end;     // 0x28
};

namespace pure3d {
class Entity {
public:
    virtual void AddRef();
};
class CompositeDrawable : public Entity {
public:
    char pad04[0x44];
    Anim_f1ab0* anim;               // 0x48
    void FUN_002998d0(int a);
};
}

class Source_f1ab0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual pure3d::Entity* GetEntity();
};

class Player_f1ab0 {
public:
    char pad0[0x190];
    pure3d::CompositeDrawable* drawable;
    char pad194[0x1f4 - 0x194];
    float duration;
    void FUN_000e9e60();
    void FUN_000f1ab0(Source_f1ab0* src);
};

void Player_f1ab0::FUN_000f1ab0(Source_f1ab0* src) {
    drawable = dynamic_cast<pure3d::CompositeDrawable*>(src->GetEntity());
    if (!drawable)
        return;
    drawable->AddRef();
    drawable->FUN_002998d0(0);
    Anim_f1ab0* a = drawable->anim;
    if ((unsigned char)(a->end - a->begin) == 0)
        return;
    Part_f1ab0* first = a->begin[0];
    if (first)
        duration = first->GetLength() - 1.0f;
    FUN_000e9e60();
}
} // namespace fn_000f1ab0


// 0x000f1b30 HSlider::vfunc_2 (30 B): matches/0x000f1b30.cpp
// sym: ??_GHSlider@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
HSlider::~HSlider() {}


// 0x000f1b50 TextSelector::vfunc_2 (30 B): matches/0x000f1b50.cpp
// sym: ??_GTextSelector@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
TextSelector::~TextSelector() {}

namespace fn_f5892d97 {

// 0x000f1b70 MenuSelector::vfunc_2 (36 B): matches/0x000f1b70.cpp
// sym: ?vfunc_5@MenuSelector_f1b70@fn_f5892d97@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
MenuSelector_f1b70* MenuSelector_f1b70::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040c554;
    Destroy_000ebca0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x000f1ba0 MapThing::vfunc_2 (36 B): matches/0x000f1ba0.cpp
// sym: ?vfunc_5@MapThing_f1ba0@fn_f5892d97@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
MapThing_f1ba0* MapThing_f1ba0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040c5c4;
    Destroy_000e9030();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x000f1bd0 FUN_000f1bd0 (142 B): equivalent/0x000f1bd0.cpp
// sym: ?FUN_000f1bd0@Widget_f1bd0@fn_f5892d97@@QAEXUArgPair@2@M@Z @89049d513e8b @w5cb3e31486af
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 2/2)
// FUN_000f1bd0 @ 0x000f1bd0
void Widget_f1bd0::FUN_000f1bd0(ArgPair args, float c) {
    argA = args.x.i;
    argB = args.y.i;
    argC = c;
    union { float f; unsigned int u; } bits;
    bits.f = c;
    args.x.u = bits.u & 0x7fffffff;
    if (args.x.f == 1.5707963705062866f) {
        Vec3_f1bd0 size;
        FUN_000f69e0((void *)(hulk_uintptr)(int)source, (Vec3_f1bd0 *)(&size));
        layout->GetExtent(&args, this);
        scaleX = args.x.f / size.y * 0.9f;
        scaleY = args.y.f / size.x * 0.9f;
    }
}

} // namespace fn_f5892d97

// 0x000f1c60 TextWindow::vfunc_2 (30 B): matches/0x000f1c60.cpp
// sym: ??_GTextWindow@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
TextWindow::~TextWindow() {}


// 0x000f1c80 TextTable::vfunc_2 (72 B): matches/0x000f1c80.cpp [wrapped: conflict: FEControl; TextTable]
// sym: ?vfunc_2@TextTable@fn_000f1c80@@QAEPAV12@E@Z
namespace fn_000f1c80 {
extern "C" char DAT_0040c42c[];
extern "C" char DAT_0040c6a4[];
class Sub_f1c80 {
  public:
    void init_000f7960();
};
class Sub2_f1c80 {
  public:
    void init_000e9030();
};
void thunk_FUN_00267090(void*);
class FEControl {
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
};
class TextTable : public FEControl {
  public:
    TextTable* vfunc_2(unsigned char p);
    char pad[0x495c - 4];
};
TextTable* TextTable::vfunc_2(unsigned char p) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0040c6a4);
    char* q = (char*)this + 0x495c;
    for (int i = 0x200; i != 0; --i) {
        q -= 0x24;
        ((Sub_f1c80*)q)->init_000f7960();
    }
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0040c42c);
    ((Sub2_f1c80*)this)->init_000e9030();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000f1c80


// 0x000f1cd0 ImageSelector::vfunc_2 (30 B): matches/0x000f1cd0.cpp
// sym: ??_GImageSelector@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
ImageSelector::~ImageSelector() {}


// 0x000f1cf0 FEContainer::vfunc_0 (30 B): matches/0x000f1cf0.cpp [wrapped: conflict: CAction]
// sym: ?vfunc_2@FEContainer_f1cf0@fn_000f1cf0@@UAEPAV12@E@Z
namespace fn_000f1cf0 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class FEContainer_f1cf0 : public CAction {
  public:
    FEContainer_f1cf0* vfunc_2(unsigned char);
};
struct ThisCall_000eeac0 {
    void FUN_000eeac0();
};
extern void thunk_FUN_00267090(FEContainer_f1cf0*);
FEContainer_f1cf0* FEContainer_f1cf0::vfunc_2(unsigned char flags) {
    ((ThisCall_000eeac0*)(this))->FUN_000eeac0();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000f1cf0


// 0x000f1d10 FEScreenBase::vfunc_0 (30 B): matches/0x000f1d10.cpp
// sym: ??_GFEScreenBase@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FEScreenBase::~FEScreenBase() {}

namespace fn_f5892d97 {

// 0x000f1d30 FEDialog::vfunc_0 (63 B): matches/0x000f1d30.cpp
// sym: ?f@FEDialog_f1d30@fn_f5892d97@@QAEPAV12@E@Z
FEDialog_f1d30* FEDialog_f1d30::f(unsigned char fl) {
    vptr = hulk_at_0040c84c;
    _ReadWriteBarrier();
    if (m9a4) {
        m9a4->Release();
        m9a4 = 0;
    }
    Fin_000eeac0();
    if (fl & 1)
        Free_0008d330(this);
    return this;
}

} // namespace fn_f5892d97

// 0x000f1d70 FEMenuBase::vfunc_0 (63 B): matches/0x000f1d70.cpp [wrapped: conflict: FEMenuBase; FEScreenBase]
// sym: ?vfunc_0@FEMenuBase@fn_000f1d70@@UAEPAV12@E@Z
namespace fn_000f1d70 {
extern "C" char DAT_0040c924[];
extern "C" void _ReadWriteBarrier();
class Ref_f1d70 {
  public:
    virtual void a();
    virtual void Release();
};
class FEScreenBase {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad();
    virtual void ae();
    virtual void af();
    virtual void ag();
    virtual void ah();
    virtual void ai();
    virtual void aj();
    virtual void ak();
    virtual void al();
    virtual void am();
    virtual void an();
    virtual void ao();
    virtual void ap();
    virtual void aq();
    virtual void ar();
    virtual void as();
    virtual void at();
    virtual void au();
    virtual void av();
    virtual void aw();
    virtual void ax();
    virtual void ay();
    virtual void az();
    virtual void ba();
    virtual void bb();
    virtual void bc();
    virtual void bd();
    virtual void be();
    virtual void bf();
};
class FEMenuBase : public FEScreenBase {
  public:
    char pad[0x98c];
    Ref_f1d70* field;
    virtual FEMenuBase* vfunc_0(unsigned char);
    void helper_000ef400();
};
void thunk_FUN_00267090(FEMenuBase*);
FEMenuBase* FEMenuBase::vfunc_0(unsigned char p) {
    *(void**)this = (void*)((hulk_intptr)DAT_0040c924);
    _ReadWriteBarrier();
    if (field) {
        field->Release();
        field = 0;
    }
    helper_000ef400();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000f1d70


// 0x000f1db0 FEThingsBase::vfunc_52 (75 B): matches/0x000f1db0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?f52@FEThingsBase@fn_000f1db0@@UAEPAUTextButton@2@H@Z
namespace fn_000f1db0 {
extern "C" void _ReadWriteBarrier();
extern "C++" __declspec(nothrow) void* __cdecl Alloc_0008d690(hulk_uintptr) throw();
struct ButtonBase {
    ButtonBase(int) throw();
    virtual void g();
    char pad[0x14c];
};
struct TextButton : public ButtonBase {
    TextButton(int a) throw();
    virtual void g();
    int a, b, c;
    void* operator new(size_t) HULK_NEW_THROW { return Alloc_0008d690(0x160); }
};
TextButton::TextButton(int x) throw() : ButtonBase(x) {
    _ReadWriteBarrier();
    a = -1;
    b = -1;
    c = 0xff000000;
}
class FEThingsBase {
  public:
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual TextButton* f52(int);
};
TextButton* FEThingsBase::f52(int arg) {
    return new TextButton(arg);
}
} // namespace fn_000f1db0


// 0x000f1e00 FEThingsBase::vfunc_56 (79 B): matches/0x000f1e00.cpp
// sym: ?vfunc_56@FEThingsBase@@UAEPAXH@Z
void* FEThingsBase::vfunc_56(int arg) {
    TextLabel_f1e00* p = (TextLabel_f1e00*)alloc_0008d690(0x128);
    if (p) {
        p->initialize_000e2860(arg);
        p->a = 0;
        *(volatile hulk_intptr*)p = ((hulk_intptr)DAT_0040c61c);
        p->b = 0;
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x000f1e50 FUN_000f1e50 (233 B): equivalent/0x000f1e50.cpp [wrapped: conflict: FEThingsBase; FEThingsBase::ParseFunctor]
// sym: ?FUN_000f1e50@Owner_f1e50@fn_000f1e50@@QAEXPAUContext@2@PAX1PAUNode@2@@Z @ac1a862b4806 @w5b6ee4081925
namespace fn_000f1e50 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 6/6)
// FUN_000f1e50 @ 0x000f1e50
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern int DAT_0049dba4; extern int DAT_0049f48c;
struct Context { void FUN_000fa0a0(); float FUN_000fad30(); };
struct Node { virtual void slot0(); virtual unsigned int type(); };
struct Vec3_f1e50 { float x,y,z; };
struct Object { void FUN_000f1bd0(Vec3_f1e50); };
struct FEThingsBase { struct ParseFunctor; };
struct Owner_f1e50 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
 virtual bool parseChildren(Context*, Node*, FEThingsBase::ParseFunctor*);
 virtual bool parseProperty(Context*, void*, void*, Node*);
 void FUN_000f1e50(Context*, void*, void*, Node*);
};
struct FEThingsBase::ParseFunctor {
 virtual void slot0();
 Owner_f1e50* owner;
 void (Owner_f1e50::*method)(Context*, void*, void*, Node*);
 void* arg;
 void* object;
};
void Owner_f1e50::FUN_000f1e50(Context* context, void* arg, void* object, Node* node) {
 Object* typed = (Object*)FUN_00344e74(object,0,&DAT_0049dba4,&DAT_0049f48c,0);
 if(node->type()==0xa137906dU) {
 Vec3_f1e50 v; v.x=0.0f; v.y=0.0f; v.z=context->FUN_000fad30()*0.01745329238474369f;
 typed->FUN_000f1bd0(v);
 } else {
 if(parseProperty(context,arg,object,node)) return;
 FEThingsBase::ParseFunctor f; f.owner=this; f.method=&Owner_f1e50::FUN_000f1e50; f.arg=arg; f.object=object;
 if(!parseChildren(context,node,&f)) context->FUN_000fa0a0();
 }
}
} // namespace fn_000f1e50


// 0x000f1f40 FEThingsBase::vfunc_9 (229 B): equivalent/0x000f1f40.cpp [wrapped: conflict: DAT_004de94c; FEThingsBase]
// sym: ?vfunc_9@FEThingsBase@fn_000f1f40@@UAE_NXZ @104d4c182193 @wb5f69a737bc9
namespace fn_000f1f40 {
// STATUS: equivalent (tools/equiv.py level 3: 2982 inputs, branch coverage 14/14)
// FEThingsBase::vfunc_9 @ 0x000f1f40
extern unsigned int DAT_004de94c;
extern float (__cdecl *DAT_004de948)();
struct Child_f1f40 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
};
struct FEThingsBase {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9();
 virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30();
 char pad[0x1760-4]; Child_f1f40* child; char pad2[0x1830-0x1764]; int state; float amount; float elapsed;
};
bool FEThingsBase::vfunc_9() {
 ++DAT_004de94c;
 if (state == 1 || state == 2) {
 union { float f; unsigned int u; } ratio;
 ratio.f = elapsed / 0.25f;
 ratio.u &= 0x7fffffff;
 if (state == 2) {
 amount = 1.0f - ratio.f;
 if (elapsed >= 0.25f || !child) vfunc_30();
 } else {
 amount = ratio.f;
 if (elapsed >= 0.25f || !child) state = 0;
 }
 }
 float delta = DAT_004de948();
 elapsed = delta + elapsed;
 if (child) { child->slot10(); return true; }
 return false;
}
} // namespace fn_000f1f40

namespace fn_f5892d97 {

// 0x000f20f0 FUN_000f20f0 (35 B): matches/0x000f20f0.cpp
// sym: ?FUN_000f20f0@fn_f5892d97@@YAXPAUObject@1@PAX1@Z
void FUN_000f20f0(Object* obj, void* x, void* y) {
    DynamicCaster_f20f0 caster;
    obj->d(&caster, x, y);
}

} // namespace fn_f5892d97

// 0x000f2150 HSlider::vfunc_10 (129 B): matches/0x000f2150.cpp
// sym: ?vfunc_10@HSlider@@UAEDHH@Z
char HSlider::vfunc_10(int op, int value) {
    switch (op) {
    case 2:
        if (this->f_168) {
            ((HSlider_nv_f2150*)this)->Change2_000f1570();
            this->f_170 = 2;
            this->f_174 = value;
            (*(int *)&this->f_178) = 0;
        }
        return 1;
    case 6:
        if (this->f_168) {
            ((HSlider_nv_f2150*)this)->Change6_000f17b0();
            this->f_174 = value;
            this->f_170 = 6;
            (*(int *)&this->f_178) = 0;
            return 1;
        }
        return 1;
    default:
        return 0;
    }
}


// 0x000f21e0 HSlider::vfunc_12 (59 B): matches/0x000f21e0.cpp
// sym: ?vfunc_12@HSlider@@UAE_NHH@Z
bool HSlider::vfunc_12(int x, int y) {
    switch (x) {
    case 6:
        if (!this->f_168) {
            ((ThisCall_000f17b0*)(this))->action17b0_000f17b0();
            return true;
        }
        return true;
    case 2:
        if (!this->f_168)
            ((ThisCall_000f1570*)(this))->action1570_000f1570();
        return true;
    default:
        return false;
    }
}

namespace fn_f5892d97 {

// 0x000f2340 FUN_000f2340 (42 B): matches/0x000f2340.cpp
// sym: _FUN_000f2340
extern "C" hulk_intptr __cdecl FUN_000f2340(Inventory* inv, void* item) {
    __int64 id = Lookup(item);
    DynamicCaster_f2340 caster;
    return inv->Load(&caster, id);
}


// 0x000f2370 FUN_000f2370 (42 B): matches/0x000f2370.cpp
// sym: _FUN_000f2370
extern "C" hulk_intptr FUN_000f2370(Obj* o, hulk_intptr x) {
    __int64 v = Convert(x);
    DynamicCaster_f2370 c;
    return o->f3(&c, v);
}

} // namespace fn_f5892d97

// 0x000f23a0 FUN_000f23a0 (42 B): matches/0x000f23a0.cpp [wrapped: conflict: Object]
// sym: _FUN_000f23a0
namespace fn_000f23a0 {
typedef unsigned __int64 U64;
struct DynamicCaster_f23a0 {
    virtual void Cast();
};
struct Object {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Load(DynamicCaster_f23a0*, U64);
};
extern U64 hash_0027b020(void*);
extern "C" hulk_intptr FUN_000f23a0(Object* obj, void* name) {
    U64 h = hash_0027b020(name);
    DynamicCaster_f23a0 caster;
    return obj->Load(&caster, h);
}
} // namespace fn_000f23a0

namespace fn_f5892d97 {

// 0x000f23d0 FUN_000f23d0 (42 B): matches/0x000f23d0.cpp
// sym: _FUN_000f23d0
extern "C" hulk_intptr __cdecl FUN_000f23d0(Inv* inv, void* name) {
    __int64 val = fetch_0027b020(name);
    DynamicCaster_f23d0 caster;
    return inv->use(&caster, val);
}

} // namespace fn_f5892d97

// 0x000f2460 FUN_000f2460 (108 B): equivalent/0x000f2460.cpp [wrapped: conflict: FEPoseAnimation; FUN_0027b020; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ??0FEPoseAnimation@fn_000f2460@@QAE@HPBD@Z @31551760319a @w7e223dc28a9a
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_000f2460 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f2460 @ 0x000f2460


namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}
namespace pure3d { class CompositeDrawable; }

class Ref_f2460 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Loader_f2460 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2460 *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned int lo, unsigned int hi);
};
struct Id64_f2460 { unsigned int lo; unsigned int hi; };
Id64_f2460 __cdecl FUN_0027b020(const char *name);

// equiv-map: ??0FEBase@@QAE@HPBD@Z = 0x000e13c0
class FEAnimation_f2460 {
public:
    FEAnimation_f2460(int a, const char *name);
    virtual void v0();
    char pad04[8];
    Ref_f2460 *p0c;
    char pad10[0x50];
};

class FEPoseAnimation : public FEAnimation_f2460 {
public:
    Ref_f2460 *p60;
    FEPoseAnimation(int a, const char *name);
    virtual void v0();
};

FEPoseAnimation::FEPoseAnimation(int a, const char *name) : FEAnimation_f2460(a, name)
{
    p60 = 0;
    p0c = 0;
    Loader_f2460 *ld = (*(Loader_f2460**)&DAT_004dd9cc);
    Id64_f2460 id = FUN_0027b020(name);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Ref_f2460 *r = ld->v3(&caster, id.lo, id.hi);
    if (r != 0) {
        p60 = r;
        r->AddRef();
        p0c = p60;
        p60->AddRef();
    }
}
} // namespace fn_000f2460


// 0x000f24d0 FUN_000f24d0 (86 B): matches/0x000f24d0.cpp [wrapped: conflict: FEPoseAnimationInvisible; Inventory]
// sym: ??0FEPoseAnimationInvisible@fn_000f24d0@@QAE@HPBD@Z
namespace fn_000f24d0 {
// data: gInventory = DAT_004dd9cc

class Drawable {
  public:
    virtual void fn();
};
class DynamicCaster_f24d0 {
  public:
    virtual void fn();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Drawable* Find(DynamicCaster_f24d0*, unsigned __int64);
};
extern unsigned __int64 __cdecl Hash_0027b020(const char*);
class FEAnimation_f24d0 {
  public:
    virtual void a();
    char pad[8];
    Drawable* drawable;
    FEAnimation_f24d0(int, const char*);
};
class FEPoseAnimationInvisible : public FEAnimation_f24d0 {
  public:
    virtual void a();
    FEPoseAnimationInvisible(int, const char*);
};
FEPoseAnimationInvisible::FEPoseAnimationInvisible(int a, const char* name) : FEAnimation_f24d0(a, name) {
    Inventory* inv = (*(Inventory**)&DAT_004dd9cc);
    unsigned __int64 h = Hash_0027b020(name);
    Drawable* p = inv->Find(&DynamicCaster_f24d0(), h);
    if (p) {
        p->fn();
        drawable = p;
    }
}
} // namespace fn_000f24d0

namespace fn_f5892d97 {

// 0x000f2530 FEPoseAnimationInvisible::vfunc_3 (1 B): matches/0x000f2530.cpp
// sym: ?FUN_000f2530@fn_f5892d97@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000f2530() {}

} // namespace fn_f5892d97

// 0x000f2540 FEPoseAnimationInvisible::vfunc_0 (30 B): matches/0x000f2540.cpp
// sym: ??_GFEPoseAnimationInvisible@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FEPoseAnimationInvisible::~FEPoseAnimationInvisible() {}


// 0x000f2560 FUN_000f2560 (84 B): matches/0x000f2560.cpp [wrapped: conflict: FEShaderAnimation]
// sym: ??0FEShaderAnimation@fn_000f2560@@QAE@HH@Z
namespace fn_000f2560 {
// data: g_dat_f2560 = DAT_004dd9cc

struct Result_f2560 {
  public:
    virtual void method0();
};

struct Obj_f2560 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Result_f2560* cast(void* caster, __int64 val);
};


__int64 __cdecl fun_p2_0027b020(int p);

struct DynamicCaster {
  public:
    virtual void f0();
};

struct FEAnimation_f2560 {
    virtual void bv();
    int a;
    int b;
    FEAnimation_f2560(int x, int y);
};

struct FEShaderAnimation : FEAnimation_f2560 {
    Result_f2560* m_c;
    FEShaderAnimation(int p1, int p2);
};

FEShaderAnimation::FEShaderAnimation(int p1, int p2) : FEAnimation_f2560(p1, p2) {
    Obj_f2560* obj = (*(Obj_f2560**)&DAT_004dd9cc);
    __int64 v = fun_p2_0027b020(p2);
    m_c = obj->cast(&DynamicCaster(), v);
    if (m_c) {
        m_c->method0();
    }
}
} // namespace fn_000f2560

namespace fn_f5892d97 {

// 0x000f25c0 FEShaderAnimation::vfunc_3 (1 B): matches/0x000f25c0.cpp
// sym: ?FUN_000f25c0@fn_f5892d97@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000f25c0() {}

} // namespace fn_f5892d97

// 0x000f25d0 FEShaderAnimation::vfunc_0 (30 B): matches/0x000f25d0.cpp
// sym: ??_GFEShaderAnimation@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FEShaderAnimation::~FEShaderAnimation() {}


// 0x000f2680 FUN_000f2680 (84 B): matches/0x000f2680.cpp [wrapped: conflict: FEParticleAnimation]
// sym: ??0FEParticleAnimation@fn_000f2680@@QAE@HHH@Z
namespace fn_000f2680 {
// data: gLoader = DAT_004dd9cc

typedef unsigned __int64 U64;
struct FEPoseAnimation_f2680 {
    virtual void v0();
    FEPoseAnimation_f2680(int, int);
    char pad[0x60];
    void* particle;
};
struct Particle {
    virtual void AddRef();
};
struct DynamicCaster_f2680 {
    virtual void cast();
};
struct Loader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Particle* Get(DynamicCaster_f2680*, U64);
    inline Particle* Fetch(U64 id) {
        DynamicCaster_f2680 caster;
        return Get(&caster, id);
    }
};
extern U64 __cdecl Find_0027b020(int);
struct FEParticleAnimation : FEPoseAnimation_f2680 {
    virtual void v0();
    FEParticleAnimation(int a, int b, int c);
};
FEParticleAnimation::FEParticleAnimation(int a, int b, int c) : FEPoseAnimation_f2680(a, b) {
    Loader* l = (*(Loader**)&DAT_004dd9cc);
    U64 id = Find_0027b020(b);
    particle = l->Fetch(id);
    if (particle)
        ((Particle*)particle)->AddRef();
}
} // namespace fn_000f2680

namespace fn_f5892d97 {

// 0x000f26e0 FUN_000f26e0 (84 B): matches/0x000f26e0.cpp
// sym: ??0FETextureAnimation_f26e0@fn_f5892d97@@QAE@HH@Z
// Same code shape as 0x000f2560 (propagated; names are from that function)
// data: g_dat_f26e0 = DAT_004dd9cc
FETextureAnimation_f26e0::FETextureAnimation_f26e0(int p1, int p2) : FEAnimation_f26e0(p1, p2) {
    Obj_f26e0* obj = (*(Obj_f26e0**)&DAT_004dd9cc);
    __int64 v = fun_p2_0027b020(p2);
    m_c = obj->cast(&DynamicCaster(), v);
    if (m_c) {
        m_c->method0();
    }
}

} // namespace fn_f5892d97

// 0x000f2740 FUN_000f2740 (85 B): matches/0x000f2740.cpp
// sym: ?FUN_000f2740@Y_f2740@owners@@QAEHPAX@Z
hulk_intptr owners::Y_f2740::FUN_000f2740(void* p) {
    if (!field)
        return 0;
    FEPoseAnimationInvisible* x = (FEPoseAnimationInvisible*)FUN_0008d690((int)sizeof(FEPoseAnimationInvisible));
    hulk_intptr r = x ? ((FEPoseAnimationInvisible_nv_f2740*)(((FEPoseAnimationInvisible*)(x))))->make_000f24d0(field, p) : 0;
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (r)
                slots[i] = (void*)r;
            return r;
        }
        ++i;
    } while (i < 32);
    return r;
}


// 0x000f27a0 FUN_000f27a0 (85 B): matches/0x000f27a0.cpp
// sym: ?FUN_000f27a0@Holder_f27a0@owners@@QAEHH@Z
hulk_intptr owners::Holder_f27a0::FUN_000f27a0(hulk_intptr arg) {
    if (data == 0)
        return 0;
    Factory_f27a0* obj = (Factory_f27a0*)Alloc_0008d690(100);
    int result;
    if (obj != 0)
        result = obj->Create_000f2460(data, ((int)arg));
    else
        result = 0;
    int i;
    for (i = 0; i < 32; ++i) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
    }
    return result;
}


// 0x000f2800 FUN_000f2800 (94 B): matches/0x000f2800.cpp
// sym: ?FUN_000f2800@Thing_f2800@owners@@QAEHHH@Z
hulk_intptr owners::Thing_f2800::FUN_000f2800(hulk_intptr a, hulk_intptr b) {
    if (ref == 0)
        return 0;
    FEParticleAnimation* p = (FEParticleAnimation*)Alloc_0008d690(0x68);
    int result;
    if (p != 0)
        result = ((FEParticleAnimation_nv_f2800*)(((FEParticleAnimation*)(p))))->Build_000f2680(ref, ((int)a), ((int)b));
    else
        result = 0;
    int i = 0;
    while (i < 32) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
        ++i;
    }
    return result;
}


// 0x000f2860 FUN_000f2860 (85 B): matches/0x000f2860.cpp
// sym: ?FUN_000f2860@Y_f2860@owners@@QAEHPAX@Z
// Same code shape as 0x000f2740 (propagated; names are from that function)
hulk_intptr owners::Y_f2860::FUN_000f2860(void* p) {
    if (!field)
        return 0;
    FETextureAnimation* x = (FETextureAnimation*)FUN_0008d690((int)sizeof(FETextureAnimation));
    hulk_intptr r = x ? ((FETextureAnimation_nv_f2860*)(((FETextureAnimation*)(x))))->make_000f26e0(field, p) : 0;
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (r)
                slots[i] = (void*)r;
            return r;
        }
        ++i;
    } while (i < 32);
    return r;
}


// 0x000f28c0 FUN_000f28c0 (85 B): matches/0x000f28c0.cpp
// sym: ?FUN_000f28c0@Y_f28c0@owners@@QAEHPAX@Z
// Same code shape as 0x000f2740 (propagated; names are from that function)
hulk_intptr owners::Y_f28c0::FUN_000f28c0(void* p) {
    if (!field)
        return 0;
    FEShaderAnimation* x = (FEShaderAnimation*)FUN_0008d690((int)sizeof(FEShaderAnimation));
    hulk_intptr r = x ? ((FEShaderAnimation_nv_f28c0*)(((FEShaderAnimation*)(x))))->make_000f2560(field, p) : 0;
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (r)
                slots[i] = (void*)r;
            return r;
        }
        ++i;
    } while (i < 32);
    return r;
}


// 0x000f2920 FUN_000f2920 (85 B): matches/0x000f2920.cpp
// sym: ?FUN_000f2920@Holder_f2920@owners@@QAEHH@Z
// Same code shape as 0x000f27a0 (propagated; names are from that function)
hulk_intptr owners::Holder_f2920::FUN_000f2920(hulk_intptr arg) {
    if (data == 0)
        return 0;
    FEBillboardAnimation* obj = (FEBillboardAnimation*)Alloc_0008d690(100);
    int result;
    if (obj != 0)
        result = ((FEBillboardAnimation_nv_f2920*)(((FEBillboardAnimation*)(obj))))->Create_000f25f0(data, ((int)arg));
    else
        result = 0;
    int i;
    for (i = 0; i < 32; ++i) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
    }
    return result;
}


// 0x000f2980 VScroll::vfunc_0 (243 B): equivalent/0x000f2980.cpp [wrapped: conflict: FELayout; VScroll; content::LoadInventory]
// sym: ?vfunc_0@VScroll@fn_000f2980@@UAEXXZ @473cee1da133 @w0aa82b242a46
namespace fn_000f2980 {
// STATUS: equivalent (tools/equiv.py level 3: 631 inputs, branch coverage 12/12)
// VScroll::vfunc_0 @ 0x000f2980
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

namespace pure3d { struct DrawableHierarchy; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void vfunc_0(); }; }; }
struct Item_f2980 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual float vfunc_8(); virtual float vfunc_9();
};
struct Entry_f2980 { Item_f2980* item; int unused; float height; int unused2; };
struct Inventory_f2980 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual pure3d::DrawableHierarchy* vfunc_3(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*, unsigned int, unsigned int); };
struct Dimensions { float x,y,z; };
extern "C++" __declspec(nothrow) void __cdecl FUN_000f69e0(void *, void *);
struct FELayout {
 virtual void vfunc_0();
 char pad04[0x2c]; float height; char pad34[0xc];
 Entry_f2980 entries[32]; int count; char pad244[0x10]; float maximum; pure3d::DrawableHierarchy* backdrop; float scaleX,scaleY,scale;
 void FUN_000e23f0();
};
struct VScroll: FELayout { virtual void vfunc_0(); };
void VScroll::vfunc_0() {
 for(int i=0;i<count;++i) { entries[i].item->vfunc_3(); entries[i].height=entries[i].item->vfunc_8(); }
 for(int i=0;i<count;++i) { float w=entries[i].item->vfunc_9(); if(w>maximum) maximum=w; }
 FUN_000e23f0();
 Inventory_f2980* inventory=(*(Inventory_f2980**)&DAT_004dd9cc);
 unsigned __int64 hash=FUN_0027b020("S_backDropShape");
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 backdrop=inventory->vfunc_3(&caster,(unsigned int)hash,(unsigned int)(hash>>32));
 if(backdrop) { Dimensions d; FUN_000f69e0((pure3d :: DrawableHierarchy *)backdrop,(Dimensions *)(&d)); scale=1.0f; scaleX=(maximum/d.x)*1.1f; scaleY=(height/d.z)*1.1f; }
}
} // namespace fn_000f2980
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f2ba0 FEContainer::vfunc_16 (104 B): matches/0x000f2ba0.cpp [wrapped: conflict: FEContainer; content::LoadInventory]
// sym: ?Add@FEContainer@fn_000f2ba0@@UAEXPBD@Z
namespace fn_000f2ba0 {
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

namespace pure3d {
class CompositeDrawable;
}

class Obj_f2ba0 {
  public:
    virtual void AddRef();
};

namespace content {
class LoadInventory {
  public:
    template <class T> class DynamicCaster {
      public:
        virtual T* Cast(void* p);
    };
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual Obj_f2ba0* Find(const DynamicCaster<pure3d::CompositeDrawable>& c, __int64 uid);
};
} // namespace content


class FEContainer {
  public:
    virtual void v0();
    char pad[0x28 - 4];
    Obj_f2ba0* items[8];
    virtual void Add(const char* name);
};

void FEContainer::Add(const char* name) {
    int i = 0;
    Obj_f2ba0** p = items;
    do {
        if (*p == 0) {
            if (i < 8) {
                content::LoadInventory* ld = (*(content::LoadInventory**)&DAT_004dd9cc);
                __int64 uid = FUN_0027b020(name);
                Obj_f2ba0* o = ld->Find(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>(), uid);
                items[i] = o;
                if (o)
                    o->AddRef();
            }
            return;
        }
        i++;
        p++;
    } while (i < 8);
}
} // namespace fn_000f2ba0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f2c10 FUN_000f2c10 (290 B): equivalent/0x000f2c10.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?target@Owner_f2c10@fn_000f2c10@@QAEXPBD@Z @b510838d1557 @w8056225f633f
namespace fn_000f2c10 {
// STATUS: equivalent (tools/equiv.py level 3: 20025 inputs, branch coverage 6/6)
// FUN_000f2c10 @ 0x000f2c10
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

namespace pure3d { class VectorCamera; }
namespace content { namespace LoadInventory { template<class T> class DynamicCaster { public: virtual void* cast(void*); }; } }
struct Inventory_f2c10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void* lookup(content::LoadInventory::DynamicCaster<pure3d::VectorCamera>*, unsigned __int64); };
struct VectorCamera_f2c10 { virtual void init(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void set(float,float); char pad[12]; float angle; char pad2[188]; unsigned position[3]; VectorCamera_f2c10* FUN_002939a0(); };
struct Timer { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual float time(); };
void* __cdecl FUN_00263ea0(unsigned);
extern "C++" __declspec(nothrow) void __cdecl FUN_000f6530(void *, void *);
extern "C" void __cdecl FUN_0009f790(float,float,float*,float*);
struct Owner_f2c10 { char pad[0x98c]; float angle; VectorCamera_f2c10* camera; char pad2[0xd4]; unsigned position[3]; unsigned last; void target(const char*); };
void Owner_f2c10::target(const char* name) {
 Inventory_f2c10* inv=(*(Inventory_f2c10**)&DAT_004dd9cc);
 unsigned __int64 key=FUN_0027b020(name);
 content::LoadInventory::DynamicCaster<pure3d::VectorCamera> caster;
 void* found=inv->lookup(&caster,key);
 if(!found) return;
 if(camera) { camera->release(); camera=0; }
 VectorCamera_f2c10* memory=(VectorCamera_f2c10*)FUN_00263ea0(0xf8);
 camera=memory ? memory->FUN_002939a0() : 0;
 camera->init();
 FUN_000f6530(found,(VectorCamera_f2c10 *)camera);
 angle=camera->angle*57.2957763671875f;
 float t=(*(Timer**)&DAT_0052c2a4)->time();
 float a,b;
 FUN_0009f790(angle,t,&a,&b);
 camera->set(a*0.01745329238474369f,1.0f);
 position[0]=camera->position[0]; position[1]=camera->position[1]; position[2]=camera->position[2]; last=0;
}
} // namespace fn_000f2c10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5892d97 {

// 0x000f2d40 FUN_000f2d40 (107 B): matches/0x000f2d40.cpp
// sym: ?Run@Owner_f2d40@fn_f5892d97@@QAEXPAX@Z
// data: gManager_f2d40 = DAT_004dd9cc
void Owner_f2d40::Run(void* p) {
    int i = 0;
    while (i < 4 && slots[i])
        ++i;
    if (i < 4) {
        Manager_f2d40* m = (*(Manager_f2d40**)&DAT_004dd9cc);
        unsigned long long a = GetArg_0027b020(p);
        Obj_f2d40* o = m->Create(DynamicCaster_f2d40(), a);
        slots[i] = o;
        if (o)
            o->F();
    }
}

} // namespace fn_f5892d97

// 0x000f2db0 FUN_000f2db0 (191 B): equivalent/0x000f2db0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?run@Target_f2db0@fn_000f2db0@@QAEXPBD0@Z @fc4f1a46bcb9 @waa04b9fb58c1
namespace fn_000f2db0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_000f2db0 @ 0x000f2db0
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

struct MultiController {
 virtual void Start();
 virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void Mode(int);
};
namespace pure3d { struct MultiController; namespace scenegraph { struct Scenegraph; } }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void * Cast(void *); }; } }
struct Inventory_f2db0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual MultiController *Find(void *, unsigned int, unsigned int); };
extern void __cdecl FUN_000f6410(MultiController *, MultiController *);
struct Target_f2db0 { char pad[0x9b4]; MultiController *controllers[4]; void run(const char *,const char *); };
void Target_f2db0::run(const char *name,const char *scene) {
 int i; for(i=0;i<4;++i) if(!controllers[i]) break;
 if(i==4) return;
 Inventory_f2db0 *inv=(*(Inventory_f2db0**)&DAT_004dd9cc);
 unsigned __int64 key=FUN_0027b020(name);
 content::LoadInventory::DynamicCaster<pure3d::MultiController> caster;
 MultiController *p=inv->Find(&caster,(unsigned)key,(unsigned)(key>>32));
 controllers[i]=p;
 if(!p) return;
 p->Start();
 controllers[i]->Mode(2);
 if(scene) {
 inv=(*(Inventory_f2db0**)&DAT_004dd9cc);
 key=FUN_0027b020(scene);
 content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> caster2;
 p=inv->Find(&caster2,(unsigned)key,(unsigned)(key>>32));
 if(p) FUN_000f6410(controllers[i],p);
 }
}
} // namespace fn_000f2db0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f2ee0 FUN_000f2ee0 (107 B): equivalent/0x000f2ee0.cpp [wrapped: conflict: FUN_0027b020; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?FUN_000f2ee0@Inventory_f2ee0@fn_000f2ee0@@QAEXPBD@Z @e66afebdb0e6 @wf6a8fdbc1add
namespace fn_000f2ee0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000f2ee0 @ 0x000f2ee0

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class LightGroup; }

class Ref_f2ee0 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Loader_f2ee0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2ee0 *v3(content::LoadInventory::DynamicCaster<pure3d::LightGroup> *caster, unsigned int lo, unsigned int hi);
};


struct Id64_f2ee0 {
    unsigned int lo;
    unsigned int hi;
};

Id64_f2ee0 __cdecl FUN_0027b020(const char *name);

class Inventory_f2ee0 {
public:
    char pad0[0x994];
    Ref_f2ee0 *items[4];

    void FUN_000f2ee0(const char *name);
};

void Inventory_f2ee0::FUN_000f2ee0(const char *name)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (items[i] == 0)
            break;
    }
    if (i < 4) {
        Loader_f2ee0 *ld = (*(Loader_f2ee0**)&DAT_004dd9cc);
        Id64_f2ee0 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::LightGroup> caster;
        Ref_f2ee0 *r = ld->v3(&caster, id.lo, id.hi);
        items[i] = r;
        if (r != 0)
            r->AddRef();
    }
}
} // namespace fn_000f2ee0


// 0x000f2f50 FUN_000f2f50 (107 B): equivalent/0x000f2f50.cpp [wrapped: conflict: FUN_0027b020; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?FUN_000f2f50@Inventory_f2f50@fn_000f2f50@@QAEXPBD@Z @ab166e946080 @wce965b1fd594
namespace fn_000f2f50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/8, incomplete)
// FUN_000f2f50 @ 0x000f2f50

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { namespace scenegraph { class Scenegraph; } }

class Ref_f2f50 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Loader_f2f50 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2f50 *v3(content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> *caster, unsigned int lo, unsigned int hi);
};


struct Id64_f2f50 {
    unsigned int lo;
    unsigned int hi;
};

Id64_f2f50 __cdecl FUN_0027b020(const char *name);

class Inventory_f2f50 {
public:
    char pad0[0x9a4];
    Ref_f2f50 *items[1];

    void FUN_000f2f50(const char *name);
};

void Inventory_f2f50::FUN_000f2f50(const char *name)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (items[i] == 0)
            break;
    }
    if (i < 1) {
        Loader_f2f50 *ld = (*(Loader_f2f50**)&DAT_004dd9cc);
        Id64_f2f50 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> caster;
        Ref_f2f50 *r = ld->v3(&caster, id.lo, id.hi);
        items[i] = r;
        if (r != 0)
            r->AddRef();
    }
}
} // namespace fn_000f2f50


// 0x000f2fc0 FEMenuBase::vfunc_53 (63 B): matches/0x000f2fc0.cpp [wrapped: conflict: FEMenuBase]
// sym: ?f53@FEMenuBase@fn_000f2fc0@@UAEXPAI@Z
namespace fn_000f2fc0 {
// data: caster = DAT_004dd9cc

extern "C" char DAT_0040cb2c[];
typedef unsigned int u32_f2fc0;
struct FEMenuBase {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53(u32_f2fc0*);
    virtual void f54(u32_f2fc0);
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
};
struct Caster_f2fc0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual u32_f2fc0 d(const u32_f2fc0&, unsigned long long);
};
extern unsigned long long FUN_0027b020(u32_f2fc0*);
void FEMenuBase::f53(u32_f2fc0* p) {
    Caster_f2fc0* c = (*(Caster_f2fc0**)&DAT_004dd9cc);
    unsigned long long x = FUN_0027b020(p);
    u32_f2fc0 r = c->d(((hulk_intptr)DAT_0040cb2c), x);
    f54(r);
}
} // namespace fn_000f2fc0


// 0x000f3000 FUN_000f3000 (619 B): equivalent/0x000f3000.cpp [wrapped: conflict: FEAnimationHolder; FEThingsBase; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ??0FEThingsBase@fn_000f3000@@QAE@XZ @88b471eaa314 @w5183e8275d88
namespace fn_000f3000 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_000f3000 @ 0x000f3000
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
extern "C" void* memset(void* dst, int c, unsigned int n);
#endif

namespace pure3d {
class DrawableHierarchy;
namespace scenegraph { class Scenegraph; }
}

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void* p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void* p);
};
}
}

void* FUN_0008d690(unsigned int size);

class Scenegraph {
public:
    virtual void addRef();
};

class Inventory_f3000 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Scenegraph* find(content::LoadInventory::DynamicCasterBase* caster, unsigned __int64 key);
};

extern "C++" __declspec(nothrow) void __cdecl FUN_000f69e0(void *, void *);

class FEThingsBase;

struct PoolA {
    PoolA* FUN_000df690();
};

struct PoolB {
    PoolB* FUN_000f8bb0(FEThingsBase* owner);
};

class FEAnimationHolder {
public:
    __forceinline FEAnimationHolder()
    {
        memset(slots, 0, sizeof(slots));
        owner = 0;
    }
    virtual void v0_000e1d70();
    FEThingsBase* owner;
    void* slots[32];
};

class FEThingsBase {
public:
    FEThingsBase();
    virtual void v0();

    PoolA* poolA;                   // 0x4
    PoolB* poolB;                   // 0x8
    int arr0[0x40];                 // 0xc
    int arr1[0x40];                 // 0x10c
    int arr2[0x100];                // 0x20c
    int arr3[0x400];                // 0x60c
    int arr4[0x40];                 // 0x160c
    char f170c;
    char pad170d[0x175c - 0x170d];
    int f175c;
    int f1760;
    char pad1764[4];
    int f1768;
    int f176c;
    int arr5[0x10];                 // 0x1770
    int f17b0;
    int arr6[0x10];                 // 0x17b4
    int f17f4;
    char pad17f8[4];
    int f17fc;
    float f1800;
    int f1804;
    char pad1808[4];
    float f180c;
    float f1810;
    float f1814;
    Scenegraph* cursorGroup;        // 0x1818
    float cursorScale[3];           // 0x181c
    int f1828;
    int f182c;
    int f1830;
    char pad1834[4];
    int f1838;
    char pad183c[0x184c - 0x183c];
    char f184c;
    char pad184d[3];
    unsigned int f1850;
    int f1854[2];                   // 0x1854
    char pad185c[0x1a5c - 0x185c];
    int f1a5c[2];                   // 0x1a5c
    char pad1a64[0x1c64 - 0x1a64];
    int f1c64[2];                   // 0x1c64
    int f1c6c[2];                   // 0x1c6c
    char pad1c74[0x2074 - 0x1c74];
    char f2074;
    char pad2075[3];
    FEAnimationHolder anim;         // 0x2078
    int f2100;
    char f2104;
    char pad2105[0x2205 - 0x2105];
    char f2205;
    char pad2206[2];
    int f2208;
    int f220c;
    int f2210;
    int f2214;
    int f2218;
    int f221c;
    char f2220;
};

FEThingsBase::FEThingsBase()
{
    f184c = 0;
    f2074 = 1;
    f2205 = 0;
    f2208 = 0;
    f220c = 0;
    f1828 = 0;
    memset(arr0, 0, 0x40 * sizeof(int));
    memset(arr1, 0, 0x40 * sizeof(int));
    memset(arr3, 0, 0x400 * sizeof(int));
    memset(arr2, 0, 0x100 * sizeof(int));
    memset(arr4, 0, 0x40 * sizeof(int));
    f170c = 0;
    f175c = 0;
    f1768 = 0;
    f1760 = 0;
    f182c = 0;
    f2218 = 0;
    f221c = 3;
    memset(arr5, 0, 0x10 * sizeof(int));
    f17b0 = -1;
    memset(arr6, 0, 0x10 * sizeof(int));
    f17f4 = -1;

    void* mem = FUN_0008d690(0x800);
    PoolA* a = 0;
    if (mem)
        a = ((PoolA*)mem)->FUN_000df690();
    poolA = a;

    mem = FUN_0008d690(0x204);
    PoolB* b = 0;
    if (mem)
        b = ((PoolB*)mem)->FUN_000f8bb0(this);
    poolB = b;

    f176c = 0;
    f1830 = 0;
    anim.owner = this;
    f2210 = 0;
    f2214 = 0;
    f1c64[0] = 0;
    f1c64[1] = 0;
    f1c6c[0] = 0;
    f1c6c[1] = 0;
    f1a5c[0] = 0;
    f1a5c[1] = 0;
    f1854[0] = 0;
    f1854[1] = 0;
    f180c = 0.25f;
    f1810 = 40.0f;
    f1814 = -200.0f;
    f17fc = 0;
    f1800 = 1.0f;
    f1804 = 0;
    f2100 = 0;

    {
        content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> caster;
        Inventory_f3000* inv = (*(Inventory_f3000**)&DAT_004dd9cc);
        unsigned __int64 key = FUN_0027b020("cursor_group");
        Scenegraph* sg = inv->find(&caster, key);
        cursorGroup = sg;
        if (sg)
            sg->addRef();
    }
    cursorScale[0] = 1.0f;
    cursorScale[1] = 1.0f;
    cursorScale[2] = 1.0f;
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        Inventory_f3000* inv = (*(Inventory_f3000**)&DAT_004dd9cc);
        unsigned __int64 key = FUN_0027b020("cursor_planeShape");
        Scenegraph* shape = inv->find(&caster, key);
        if (shape)
            FUN_000f69e0((Scenegraph *)shape, (float *)cursorScale);
    }
    f184c = 0;
    f2104 = 0;
    f1838 = 0;
    f1850 = 0xff000000;
    DAT_004de94c = 0;
    f2220 = 0;
}
} // namespace fn_000f3000
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f3270 FEThingsBase::vfunc_35 (1734 B): equivalent/0x000f3270.cpp [wrapped: conflict: FEThingsBase; content::LoadInventory::DynamicCaster]
// sym: ?vfunc_35@FEThingsBase@fn_000f3270@@UAE_NPAUReader@2@HPAUDest_f3270@2@PAUKey_f3270@2@@Z @b7fd6f7a4822 @wbeabfc5c5f4c
namespace fn_000f3270 {
// STATUS: equivalent (tools/equiv.py level 3: 3218 inputs, branch coverage 94/94)
// FEThingsBase::vfunc_35 @ 0x000f3270
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

typedef unsigned __int64 u64_f3270;
void *FUN_0008d690(unsigned int size);

namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
namespace pure3d { class CompositeDrawable; }

struct Loaded_f3270 {
    virtual void l0();
};

struct Inventory_f3270 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_f3270 *find(void *caster, u64_f3270 key);
};
Loaded_f3270 *__cdecl FUN_000c0d80(Inventory_f3270 *inv, const char *name);

struct Color_f3270 {
    unsigned int v;
    Color_f3270 *FUN_000115c0(int r, int g, int b, int a);
};

struct Reader {
    const char *FUN_000fad90();
    float FUN_000fad30();
    u64_f3270 FUN_000faeb0();
    char FUN_000f9e90();
    void FUN_000fa0a0();
    int FUN_000fb150();
};

struct Item_f3270 {
    char pad0[0x10];
    unsigned int color;              // 0x10
    float f14;                       // 0x14
    char pad18[4];
    Item_f3270 *FUN_000dee10();
};

struct Sub_f3270 {
    char pad0[0x38];
    float f38;
};

struct Dest_f3270 {
    char pad0[0x14];
    Sub_f3270 *f14;
    unsigned int f18;
    char pad1c[0x30 - 0x1c];
    unsigned char b30;
    char pad31[3];
    float f34;
    int f38;
    unsigned int f3c;
    unsigned char b40;
    char pad41[3];
    unsigned int f44;
    unsigned char b48;
    char pad49[3];
    unsigned int f4c;
    char pad50[0x68 - 0x50];
    unsigned char b68;
    char pad69[3];
    int f6c;
    int f70;
    char pad74[0x90 - 0x74];
    u64_f3270 f90;
    char pad98[0xa4 - 0x98];
    int fa4;
    char pada8[0xc0 - 0xa8];
    int fc0;
    int fc4;
    char padc8[0xd0 - 0xc8];
    int fd0;
    int fd4;

    void FUN_000e2ac0(Item_f3270 *it);
    void FUN_000e9090(Loaded_f3270 *l);
    void FUN_000e9130(Loaded_f3270 *l);
    void FUN_000e9100(Loaded_f3270 *l);
    void FUN_000e04f0(const char *s);
    float *FUN_000e2820(float *tmp);
};

struct Key_f3270 {
    virtual void k0();
    virtual int v1();
};

class FEThingsBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(int a, unsigned int *dstp);
    virtual void v34();
    virtual bool vfunc_35(Reader *r, int unused, Dest_f3270 *dst, Key_f3270 *key);

    int FUN_000e6530(const char *name);
    int FUN_000e7ec0(u64_f3270 id, Reader *r);
    int FUN_000e7f10(u64_f3270 id, Reader *r);
};

bool FEThingsBase::vfunc_35(Reader *r, int unused, Dest_f3270 *dst, Key_f3270 *key)
{
    int hash = key->v1();
    switch (hash) {
    case 0x9af45bd7: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fc4 = h;
        return true;
    }
    case 0xd3cd5a63: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fc0 = h;
        return true;
    }
    case 0xd3f62292: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fd0 = h;
        dst->fd4 = h;
        return true;
    }
    case 0xda695544: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fc0 = h;
        dst->fc4 = h;
        return true;
    }
    case 0xe5160039: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fd0 = h;
        return true;
    }
    case 0xee4f9831: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fd4 = h;
        return true;
    }
    case 0x8b025b6b: {
        u64_f3270 id = r->FUN_000faeb0();
        if ((unsigned int)id != 0xa6dce4eb)
            return false;
        void *mem = FUN_0008d690((int)sizeof(Item_f3270));
        Item_f3270 *it = 0;
        if (mem != 0)
            it = ((Item_f3270 *)mem)->FUN_000dee10();
        if (r->FUN_000f9e90())
            it->f14 = r->FUN_000fad30();
        unsigned int col = it->color;
        if (r->FUN_000f9e90()) {
            int cr = (int)r->FUN_000fad30();
            int cg = (int)r->FUN_000fad30();
            int cb = (int)r->FUN_000fad30();
            col = (col & 0xff000000) | (((cr & 0xff) << 8 | (cg & 0xff)) << 8) | (cb & 0xff);
            if (r->FUN_000f9e90()) {
                int ca = (int)r->FUN_000fad30();
                col = (col & 0xffffff) | (ca << 24);
            }
        }
        it->color = col;
        dst->FUN_000e2ac0(it);
        return true;
    }
    case 0xb660a5ef:
        dst->fa4 = (int)r->FUN_000fad30();
        return true;
    case 0xd208ebe9: {
        int cr = (int)r->FUN_000fad30();
        int cg = (int)r->FUN_000fad30();
        int cb = (int)r->FUN_000fad30();
        int ca = 0xff;
        if (r->FUN_000f9e90())
            ca = (int)r->FUN_000fad30();
        Color_f3270 c;
        dst->b48 = 1;
        dst->f4c = c.FUN_000115c0(cr, cg, cb, ca)->v;
        return true;
    }
    case 0x158c2674: {
        int cr = (int)r->FUN_000fad30();
        int cg = (int)r->FUN_000fad30();
        int cb = (int)r->FUN_000fad30();
        int ca = 0xff;
        if (r->FUN_000f9e90())
            ca = (int)r->FUN_000fad30();
        Color_f3270 c;
        dst->f3c = c.FUN_000115c0(cr, cg, cb, ca)->v;
        return true;
    }
    case 0x58a3e29a: {
        int cr = (int)r->FUN_000fad30();
        int cg = (int)r->FUN_000fad30();
        int cb = (int)r->FUN_000fad30();
        int ca = 0xff;
        if (r->FUN_000f9e90())
            ca = (int)r->FUN_000fad30();
        dst->b40 = 1;
        dst->f44 = (((ca << 8 | cr) << 8 | cg) << 8) | cb;
        return true;
    }
    case 0xf7d14590: {
        const char *nm = r->FUN_000fad90();
        Inventory_f3270 *inv = (*(Inventory_f3270**)&DAT_004dd9cc);
        u64_f3270 key2 = FUN_0027b020(nm);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
        Loaded_f3270 *l = inv->find(&caster, key2);
        dst->FUN_000e9090(l);
        return true;
    }
    case 0x116152a5:
        dst->f70 = FUN_000e7f10(r->FUN_000faeb0(), r);
        return true;
    case 0xdaf00033:
        dst->f6c = FUN_000e7ec0(r->FUN_000faeb0(), r);
        return true;
    case 0x09a7e15a:
        dst->FUN_000e9130(FUN_000c0d80((*(Inventory_f3270**)&DAT_004dd9cc), r->FUN_000fad90()));
        return true;
    case 0x18688526:
        return true;
    case 0x2d848685:
        dst->FUN_000e04f0(r->FUN_000fad90());
        return true;
    case 0x3cbe40fa:
        dst->f90 = r->FUN_000faeb0();
        return true;
    case 0x42ba2ee5: {
        unsigned int *p = &dst->f18;
        v33(r->FUN_000fb150(), p);
        int v = 0;
        if (r->FUN_000f9e90())
            v = (int)r->FUN_000fad30();
        *p = v;
        dst->fa4 = v;
        return true;
    }
    case 0x47329b05: {
        dst->FUN_000e9100(FUN_000c0d80((*(Inventory_f3270**)&DAT_004dd9cc), r->FUN_000fad90()));
        if (r->FUN_000f9e90()) {
            if (r->FUN_000fad30() != 0.0f) {
                dst->b68 = 1;
                return true;
            }
        }
        dst->b68 = 0;
        return true;
    }
    case 0x47c943ae: {
        float v = r->FUN_000fad30();
        if (!(v > 0.0f) && v == v) {
            float tmp;
            v = *dst->FUN_000e2820(&tmp);
        }
        dst->f34 = v;
        dst->b30 = 1;
        dst->f38 = -1;
        return true;
    }
    case 0xe897502e:
        dst->f14->f38 = r->FUN_000fad30();
        return true;
    }
    return false;
}
} // namespace fn_000f3270
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f3940 FUN_000f3940 (467 B): equivalent/0x000f3940.cpp [wrapped: conflict: FEControl; FEThingsBase; TextWindow; content::LoadInventory::DynamicCaster (+2)]
// sym: ?FUN_000f3940@FEThingsBase@fn_000f3940@@QAEXPAUToken_f3940@2@PAVParser_f3940@2@PAVFEControl@2@PAVNode@2@@Z @e51d38063214 @we87b1e7fdd7f
namespace fn_000f3940 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 24/24)
// FUN_000f3940 @ 0x000f3940
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


class Entity {
public:
    virtual void AddRef();
    virtual void Release();
};

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d {
class CompositeDrawable {
public:
    virtual void d0();
};
}

class Registry_f3940 {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual Entity *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

class FEControl {
public:
    virtual void c0();
};

class TextWindow : public FEControl {
public:
    char pad04[0x154 - 4];
    Entity *drawableA;        // 0x154
    Entity *drawableB;        // 0x158
    char pad15c[0x97c - 0x15c];
    float scale;              // 0x97c
    void FUN_000e3b70(Entity *e);
};

struct Token_f3940 {
    const char *FUN_000fad90();
    float FUN_000fad30();
    void FUN_000fa0a0();
};

class Parser_f3940 {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual Entity *p29(const char *name, int flags);
};

class Node {
public:
    virtual void n0();
    virtual unsigned int tag();
};

class FEThingsBase {
public:
    class ParseFunctor;
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
    virtual int v34(Token_f3940 *a0, Node *a3, ParseFunctor *fn);
    virtual int v35(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
    virtual int v36(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
    class ParseFunctor {
    public:
        virtual void call();
        FEThingsBase *owner;
        void (FEThingsBase::*fn)(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
        Parser_f3940 *a1;
        FEControl *a2;
        ParseFunctor(FEThingsBase *o, void (FEThingsBase::*f)(Token_f3940 *, Parser_f3940 *, FEControl *, Node *), Parser_f3940 *p1, FEControl *p2)
            : owner(o), fn(f), a1(p1), a2(p2) {}
    };
    void FUN_000f3940(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
};

void FEThingsBase::FUN_000f3940(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3)
{
    TextWindow *win = dynamic_cast<TextWindow *>(a2);
    switch (a3->tag()) {
    case 0xcc74e7a7: {
        const char *nameA = a0->FUN_000fad90();
        Registry_f3940 *reg = (*(Registry_f3940**)&DAT_004dd9cc);
        unsigned __int64 idA = FUN_0027b020(nameA);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> casterA;
        Entity *e = reg->lookup(&casterA, idA);
        if (e)
            e->AddRef();
        if (win->drawableA)
            win->drawableA->Release();
        win->drawableA = e;
        const char *nameB = a0->FUN_000fad90();
        reg = (*(Registry_f3940**)&DAT_004dd9cc);
        unsigned __int64 idB = FUN_0027b020(nameB);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> casterB;
        e = reg->lookup(&casterB, idB);
        if (e)
            e->AddRef();
        if (win->drawableB)
            win->drawableB->Release();
        win->drawableB = e;
        return;
    }
    case 0x493f336b:
        win->scale = a0->FUN_000fad30();
        return;
    case 0x65ba5b03: {
        const char *s = a0->FUN_000fad90();
        const char *p = s;
        while (*p++ != 0) {
        }
        if (p - s - 1 != 0)
            win->FUN_000e3b70(a1->p29(s, 0));
        return;
    }
    default:
        break;
    }
    if ((char)v35(a0, a1, a2, a3))
        return;
    if ((char)v36(a0, a1, a2, a3))
        return;
    ParseFunctor fn(this, &FEThingsBase::FUN_000f3940, a1, a2);
    if ((char)v34(a0, a3, &fn))
        return;
    a0->FUN_000fa0a0();
}
} // namespace fn_000f3940
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f3b20 FUN_000f3b20 (657 B): equivalent/0x000f3b20.cpp [wrapped: conflict: FEThingsBase; content::LoadInventory::DynamicCaster; pure3d::CompositeDrawable]
// sym: ?FUN_000f3b20@FEThingsBase@fn_000f3b20@@QAEXTParamArg_f3b20@2@PAVLoader_f3b20@2@PAXPAVArgs_f3b20@2@@Z @20bb47896868 @w9d52a56e9673
namespace fn_000f3b20 {
// STATUS: equivalent (tools/equiv.py level 3: 3049 inputs, branch coverage 36/38, incomplete)
// FUN_000f3b20 @ 0x000f3b20
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


extern char DAT_0049f4f0[];
extern char DAT_004a1274[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

namespace pure3d {
class CompositeDrawable {
public:
    virtual void v0();
};
}

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Vec3_f3b20 {
    float x, y, z;
};

union ParamArg_f3b20 {
    class Param *p;
    char raw[4];
};

class Obj_f3b20 {
public:
    void FUN_000e9090(pure3d::CompositeDrawable *d);
    void FUN_000f1bd0(Vec3_f3b20 v);
};

class Sink_f3b20 {
public:
    char pad0[0x154];
    Obj_f3b20 *objA;
    Obj_f3b20 *objB;
    char pad1[0x4970 - 0x15c];
    float values[8];
    void FUN_000e3de0(Obj_f3b20 *o);
};

class Param {
public:
    float FUN_000fad30();
    char *FUN_000fad90();
    void FUN_000fa0a0();
    char FUN_000f9e90();
};

class Args_f3b20 {
public:
    virtual void v0();
    virtual int GetType();
};

class Loader_f3b20 {
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
    virtual Obj_f3b20 *v29(const char *name, int flag);
};

class Inventory_f3b20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual pure3d::CompositeDrawable *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned __int64 key);
};


class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(int, int, int, int);
        hulk_intptr mC;
        hulk_intptr mD;
    };

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
    virtual char v34(Param *p, Args_f3b20 *a, ParseFunctor *f);
    virtual char v35(Param *p, Loader_f3b20 *c, void *d, Args_f3b20 *a);
    virtual char v36(Param *p, Loader_f3b20 *c, void *d, Args_f3b20 *a);

    void FUN_000f3940(int a, int b, int c, int d);
    void FUN_000f3b20(ParamArg_f3b20 arg, Loader_f3b20 *c, void *d, Args_f3b20 *args);
};

void FEThingsBase::FUN_000f3b20(ParamArg_f3b20 arg, Loader_f3b20 *c, void *d, Args_f3b20 *args)
{
    Param *param = arg.p;
    Sink_f3b20 *sink = (Sink_f3b20 *)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_004a1274, 0);
    int type = args->GetType();
    if (type == 0xcc74e7a7) {
        Param *p = param;
        const char *s = p->FUN_000fad90();
        Inventory_f3b20 *inv = (*(Inventory_f3b20**)&DAT_004dd9cc);
        unsigned __int64 key = FUN_0027b020(s);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster = new (&arg) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
        pure3d::CompositeDrawable *drawable = inv->v3(caster, key);
        if (!drawable)
            return;
        const char *name = p->FUN_000fad90();
        const char *q = name;
        while (*q++)
            ;
        hulk_intptr len = q - (name + 1);
        if (len != 0) {
            sink->objA = c->v29(name, 0);
            if (sink->objA)
                sink->objA->FUN_000e9090(drawable);
            Vec3_f3b20 rot;
            rot.x = 0.0f;
            rot.y = 0.0f;
            rot.z = -1.57079637f;
            sink->objA->FUN_000f1bd0(rot);
        }
        name = p->FUN_000fad90();
        q = name;
        while (*q++)
            ;
        len = q - (name + 1);
        if (len == 0)
            return;
        sink->objB = c->v29(name, 0);
        if (sink->objB)
            sink->objB->FUN_000e9090(drawable);
        Vec3_f3b20 rot2;
        rot2.x = 0.0f;
        rot2.y = 0.0f;
        rot2.z = 1.57079637f;
        sink->objB->FUN_000f1bd0(rot2);
        return;
    }
    if (type == 0x36fbe7be) {
        int i = 0;
        if (!param->FUN_000f9e90())
            return;
        float *p = sink->values;
        do {
            float v = param->FUN_000fad30();
            if (i >= 0 && i < 8)
                *p = v;
            i++;
            p++;
        } while (param->FUN_000f9e90());
        return;
    }
    if (type == 0x65ba5b03) {
        const char *name = param->FUN_000fad90();
        const char *q = name;
        while (*q++)
            ;
        hulk_intptr len = q - (name + 1);
        if (len == 0)
            return;
        sink->FUN_000e3de0(c->v29(name, 0));
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f3940;
    f.mC = (hulk_intptr)c;
    f.mD = (hulk_intptr)d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
} // namespace fn_000f3b20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f3dc0 FUN_000f3dc0 (309 B): equivalent/0x000f3dc0.cpp [wrapped: conflict: FEThingsBase; Param]
// sym: ?FUN_000f3dc0@FEThingsBase@fn_000f3dc0@@QAEXPAVParam@2@HPAXPAVArgs@2@@Z @c0ab32f2dee0 @w480753e6770e
namespace fn_000f3dc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000f3dc0 @ 0x000f3dc0
extern char DAT_0049f4f0[];
extern char DAT_0049f454[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

class Param {
public:
    float FUN_000fad30();
    hulk_intptr FUN_000fad90();
    void FUN_000fa0a0();
};

class Args {
public:
    virtual void v0();
    virtual int GetType();
};

class Sink {
public:
    char pad0[0x294];
    int slotA;
    int slotB;
    void FUN_000e4060(int v);
};

class Base {
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(int, int, int, int);
        hulk_intptr mC;
        hulk_intptr mD;
    };

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
    virtual char v34(Param *p, Args *a, ParseFunctor *f);
    virtual char v35(Param *p, int x, void *y, Args *a);
    virtual char v36(Param *p, int x, void *y, Args *a);

    void FUN_000f3940(int a, int b, int c, int d);
    void FUN_000f3dc0(Param *param, hulk_intptr c, void *d, Args *args);
};

void FEThingsBase::FUN_000f3dc0(Param *param, hulk_intptr c, void *d, Args *args)
{
    Sink *sink = (Sink *)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_0049f454, 0);
    int type = args->GetType();
    if (type == 0xe037766f) {
        int n = (int)param->FUN_000fad30();
        if (n > 0 && n < 8)
            sink->slotA = n;
        return;
    }
    if (type == 0xe10f2442) {
        sink->FUN_000e4060(param->FUN_000fad90());
        return;
    }
    if (type == 0x745453ad) {
        int n = (int)param->FUN_000fad30();
        if (n > 0 && n < 8)
            sink->slotB = n;
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f3940;
    f.mC = c;
    f.mD = (hulk_intptr)d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
} // namespace fn_000f3dc0


// 0x000f3f00 FUN_000f3f00 (946 B): equivalent/0x000f3f00.cpp [wrapped: conflict: FEThingsBase; Param]
// sym: ?FUN_000f3f00@FEThingsBase@fn_000f3f00@@QAEXPAVParam@2@PAVSource_f3f00@2@PAXPAVArgs_f3f00@2@@Z @a58014cf98f3 @wb68f5befd211
namespace fn_000f3f00 {
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 44/44)
// FUN_000f3f00 @ 0x000f3f00

extern char DAT_0049f4f0[];
extern char DAT_0049f4d8[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
int __cdecl FUN_000c0d80(int a, int b);

class Param {
public:
    float FUN_000fad30();
    hulk_intptr FUN_000fad90();
    int FUN_000faeb0();
    char FUN_000f9e90();
    void FUN_000fa0a0();
};

class Args_f3f00 {
public:
    virtual void v0();
    virtual int GetType();
};

struct Vec3_f3f00 {
    float x, y, z;
};

class Source_f3f00 {
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
    virtual void GetVec3(int key, Vec3_f3f00* out);
    virtual void v49();
    virtual void GetFloat(int key, float* out);
};

struct Color_f3f00 {
    int value;
    Color_f3f00* FUN_000115c0(int r, int g, int b, int a);
};

struct Box_f3f00 {
    float f0, f4, f8, fc, f10, f14;
};

struct Frame3 {
    char pad00[0x14];
    Box_f3f00 box;
};

class Sink_f3f00 {
public:
    char pad00[0x150];
    float f150;
    char pad154[4];
    int f158;
    float f15c;
    float f160;
    float f164;
    int f168;
    float f16c;
    char pad170[0x184 - 0x170];
    Vec3_f3f00 vec184;
    Frame3* frame;
    char pad194[0x1ec - 0x194];
    int color;
    float f1f0;
    float f1f4;
    void FUN_000e2d60(int v);
    void FUN_000f1ab0(int v);
    void FUN_000f2a80(int v);
    void FUN_000f2b10(int v);
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase* mObj;
        void (FEThingsBase::*mFn)(Param* param, Source_f3f00* c, void* d, Args_f3f00* args);
        Source_f3f00* mC;
        void* mD;
    };

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
    virtual char v34(Param* p, Args_f3f00* a, ParseFunctor* f);
    virtual char v35(Param* p, Source_f3f00* c, void* d, Args_f3f00* a);
    virtual char v36(Param* p, Source_f3f00* c, void* d, Args_f3f00* a);

    void FUN_000f3f00(Param* param, Source_f3f00* c, void* d, Args_f3f00* args);
};

struct Frame_f3f00 {
    Vec3_f3f00 pos;
    float scale;
    int pad10[2];
    FEThingsBase::ParseFunctor f;
    Box_f3f00 box;
};

void FEThingsBase::FUN_000f3f00(Param* param, Source_f3f00* c, void* d, Args_f3f00* args)
{
    Frame_f3f00 fr;
    Sink_f3f00* sink = (Sink_f3f00*)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_0049f4d8, 0);
    int type = args->GetType();
    switch (type) {
    case 0xe10f2442:
        sink->FUN_000e2d60(param->FUN_000fad90());
        return;
    case 0xdd11a66e:
        sink->f16c = param->FUN_000fad30();
        return;
    case 0x8ebfb676: {
        int r = (int)param->FUN_000fad30();
        int g = (int)param->FUN_000fad30();
        int b = (int)param->FUN_000fad30();
        int a = 0xff;
        if (param->FUN_000f9e90())
            a = (int)param->FUN_000fad30();
        Color_f3f00 col;
        sink->color = col.FUN_000115c0(r, g, b, a)->value;
        return;
    }
    case 0x1babae77: {
        int v = param->FUN_000faeb0();
        if (v == 0x4ac3733b)
            sink->f158 = 2;
        else if (v == 0x5bd62f2d)
            sink->f158 = 1;
        else
            param->FUN_000fa0a0();
        return;
    }
    case 0x1f4ee86f: {
        float v = param->FUN_000fad30();
        sink->f164 = v;
        sink->f150 = v;
        return;
    }
    case 0x20a10713: {
        sink->FUN_000f1ab0(FUN_000c0d80((*(hulk_intptr*)&DAT_004dd9cc), param->FUN_000fad90()));
        if (param->FUN_000f9e90())
            sink->f1f4 = param->FUN_000fad30();
        return;
    }
    case 0x28a00121:
        sink->f168 = (int)param->FUN_000fad30();
        return;
    case 0x358b91b6:
        sink->f160 = param->FUN_000fad30();
        return;
    case 0x2c1d867d:
        sink->FUN_000f2a80(param->FUN_000fad90());
        return;
    case 0x359393a8:
        sink->f15c = param->FUN_000fad30();
        return;
    case 0x3818d345:
        sink->FUN_000f2b10(param->FUN_000fad90());
        return;
    case 0x65ba5b03: {
        int key = param->FUN_000fad90();
        c->GetVec3(key, &fr.pos);
        sink->vec184 = fr.pos;
        c->GetFloat(key, &fr.scale);
        fr.box = sink->frame->box;
        sink->f1f0 = fr.scale / (fr.box.fc - fr.box.f0);
        return;
    }
    }

    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    fr.f.mObj = this;
    fr.f.mFn = &FEThingsBase::FUN_000f3f00;
    fr.f.mC = c;
    fr.f.mD = d;
    if (v34(param, args, &fr.f))
        return;
    param->FUN_000fa0a0();
}
} // namespace fn_000f3f00


// 0x000f42c0 FUN_000f42c0 (1222 B): equivalent/0x000f42c0.cpp [wrapped: conflict: FEThingsBase; FUN_0027b020; Param; content::LoadInventory::DynamicCaster (+1)]
// sym: ?FUN_000f42c0@FEThingsBase@fn_000f42c0@@QAEXPAVParam@2@PAVFactory_f42c0@2@TSlot3@2@PAVArgs_f42c0@2@@Z @2da7871022a5 @w88f37fa71da4
namespace fn_000f42c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3113 inputs, branch coverage 72/72)
// FUN_000f42c0 @ 0x000f42c0

struct Pair64 {
    unsigned int lo, hi;
};
Pair64 __cdecl FUN_0027b020(const char *s);

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class CompositeDrawable; }

struct Color_f42c0 {
    int value;
    Color_f42c0 *FUN_000115c0(int r, int g, int b, int a);
};

class Reg_f42c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned int lo, unsigned int hi);
};
int __cdecl FUN_000c0d80(Reg_f42c0 *g, const char *s);

struct ParseState {
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const char *name, void *node, char flag);
};

class Param {
public:
    float FUN_000fad30();
    const char *FUN_000fad90();
    int FUN_000faeb0();
    char FUN_000f9e90();
    void FUN_000fa0a0();
    class Child_f42c0 *FUN_000fb150();
};

class Child_f42c0 {
public:
    virtual void v0();
    virtual int GetHash();
};

class Args_f42c0 {
public:
    virtual void v0();
    virtual int GetType();
};

struct Made_f42c0 {
    char pad0[0x74];
    char f74;
};

class Factory_f42c0 {
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
    virtual Made_f42c0 *v29(const char *name, int z);
};

class Target_f42c0 {
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
    virtual void v19(ParseState *st, int flag, void *p);
    virtual void v20();
    virtual void v21();
    virtual void v22(float f);
    virtual void v23(float f);
    virtual void v24(float f);
    char pad04[0x1d5c - 4];
    int f1d5c;
    char pad1d60[0x1d98 - 0x1d60];
    Made_f42c0 *f1d98;
    char pad1d9c[0x1da4 - 0x1d9c];
    int f1da4;
    void FUN_000ebda0(int v);
    void FUN_000ebdd0(int v);
    void FUN_000e2f80(const char *s);
    void FUN_000e3770(Made_f42c0 *m);
};

union Slot3 {
    Target_f42c0 *d;
    char flag;
    int w;
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, Factory_f42c0 *, Slot3, Args_f42c0 *);
        Factory_f42c0 *mC;
        Target_f42c0 *mD;
    };

    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void v33(Child_f42c0 *c, ParseState *st);
    virtual char v34(Param *p, Args_f42c0 *a, ParseFunctor *f);
    virtual char v35(Param *p, Factory_f42c0 *c, Target_f42c0 *d, Args_f42c0 *a);
    virtual char v36(Param *p, Factory_f42c0 *c, Target_f42c0 *d, Args_f42c0 *a);
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void *v44();

    void FUN_000f42c0(Param *p, Factory_f42c0 *c, Slot3 d3, Args_f42c0 *args);
};



struct Frame_f42c0 {
    int pad10;
    char raw[0x24];
};

static __forceinline int StrLen(const char *s)
{
    const char *e = s;
    while (*e++ != 0) {
    }
    return (int)(e - s) - 1;
}

void FEThingsBase::FUN_000f42c0(Param *p, Factory_f42c0 *c, Slot3 d3, Args_f42c0 *args)
{
    Frame_f42c0 fr;
    Target_f42c0 *d = d3.d;
    int type = args->GetType();
    switch (type) {
    case 0xbd69b501: {
        float f = p->FUN_000fad30();
        if (f >= 0.0f)
            d->v23(f);
        return;
    }
    case 0xde237f67: {
        float f = p->FUN_000fad30();
        if (f >= 0.0f)
            d->v24(f);
        return;
    }
    case 0x493f336b: {
        float f = p->FUN_000fad30();
        if (f >= 0.0f)
            d->v22(f);
        return;
    }
    case 0x8ebfb676: {
        int r = (int)p->FUN_000fad30();
        int g = (int)p->FUN_000fad30();
        int b = (int)p->FUN_000fad30();
        int a = 0xff;
        if (p->FUN_000f9e90())
            a = (int)p->FUN_000fad30();
        Color_f42c0 col;
        d->f1da4 = col.FUN_000115c0(r, g, b, a)->value;
        return;
    }
    case 0xcc74e7a7: {
        d->FUN_000ebda0(FUN_000c0d80((*(Reg_f42c0**)&DAT_004dd9cc), p->FUN_000fad90()));
        d->FUN_000ebdd0(FUN_000c0d80((*(Reg_f42c0**)&DAT_004dd9cc), p->FUN_000fad90()));
        return;
    }
    case 0xe10f2442:
        d->FUN_000e2f80(p->FUN_000fad90());
        return;
    case 0x091ece77: {
        const char *name = p->FUN_000fad90();
        if (StrLen(name) != 0) {
            d->f1d98 = c->v29(name, 0);
            if (d->f1d98 != 0)
                d->f1d98->f74 = 0;
        }
        if (!p->FUN_000f9e90())
            return;
        do {
            (*(ParseState *)fr.raw).FUN_000f7930();
            (*(ParseState *)fr.raw).FUN_000f8500("", v44(), 1);
            const char *tag = p->FUN_000fad90();
            Reg_f42c0 *g = (*(Reg_f42c0**)&DAT_004dd9cc);
            Pair64 h = FUN_0027b020(tag);
            content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster =
                new ((void *)&d3) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
            void *obj = g->v3(caster, h.lo, h.hi);
            d->v19((ParseState *)fr.raw, 0, obj);
            (*(ParseState *)fr.raw).FUN_000f7960();
        } while (p->FUN_000f9e90());
        return;
    }
    case 0x65ba5b03: {
        const char *name = p->FUN_000fad90();
        if (StrLen(name) == 0)
            return;
        d->FUN_000e3770(c->v29(name, 0));
        return;
    }
    case 0x1babae77: {
        int v = p->FUN_000faeb0();
        if (v == 0x3e33165a)
            d->f1d5c = 1;
        else if (v == 0x56a6a191)
            d->f1d5c = 2;
        else if (v == 0x612213a0)
            d->f1d5c = 0;
        else
            p->FUN_000fa0a0();
        return;
    }
    case 0x76744a71: {
        const char *name = p->FUN_000fad90();
        if (StrLen(name) != 0) {
            d->f1d98 = c->v29(name, 0);
            if (d->f1d98 != 0)
                d->f1d98->f74 = 0;
        }
        d3.flag = 0;
        Child_f42c0 *ch = p->FUN_000fb150();
        while (ch != 0) {
            if (ch->GetHash() == 0x1f4ee86f) {
                d3.flag = 1;
            } else {
                (*(ParseState *)fr.raw).FUN_000f7930();
                v33(ch, (ParseState *)fr.raw);
                d->v19((ParseState *)fr.raw, d3.w, 0);
                d3.flag = 0;
                (*(ParseState *)fr.raw).FUN_000f7960();
            }
            ch = p->FUN_000fb150();
        }
        return;
    }
    }

    if (v35(p, c, d, args))
        return;
    if (v36(p, c, d, args))
        return;
    ParseFunctor *f = new (fr.raw) ParseFunctor;
    f->mObj = this;
    f->mFn = &FEThingsBase::FUN_000f42c0;
    f->mC = c;
    f->mD = d;
    if (v34(p, args, f))
        return;
    p->FUN_000fa0a0();
}
} // namespace fn_000f42c0


// 0x000f4790 FEThingsBase::vfunc_39 (460 B): equivalent/0x000f4790.cpp
// sym: ?vfunc_39@FEThingsBase@@UAEDHHH@Z @a914baae71fe @w2cb7949e9cd1
// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 26/26)
// FEThingsBase::vfunc_39 @ 0x000f4790
char FEThingsBase::vfunc_39(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { Node_f4790 * node = (Node_f4790 *)__p0; Factory_f4790 * factory = (Factory_f4790 *)__p1; Message_f4790 * msg = (Message_f4790 *)__p2;

    Item_f4790* item;
    Node_f4790* first;
    switch (msg->GetId()) {
    case 0xceaa8e00:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Y_f28c0 *)factory)->FUN_000f28c0((Node_f4790 *)first));
        break;
    case 0xa6210435:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Y_f2740 *)factory)->FUN_000f2740((Node_f4790 *)first));
        break;
    case 0xa5b54458:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Y_f2860 *)factory)->FUN_000f2860((Node_f4790 *)first));
        break;
    case 0x103db79c:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Holder_f27a0 *)factory)->FUN_000f27a0((hulk_intptr)(Node_f4790 *)first));
        break;
    case 0x1ed3ea80:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Holder_f2920 *)factory)->FUN_000f2920((hulk_intptr)(Node_f4790 *)first));
        break;
    case 0x2d7a823f: {
        first = node->FUN_000fad90();
        Node_f4790* second = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Thing_f2800 *)factory)->FUN_000f2800((hulk_intptr)(Node_f4790 *)first, (hulk_intptr)(Node_f4790 *)second));
        break;
    }
    default:
        return 0;
    }
    vfunc_38(node, item);
    return 1;
}


// 0x000f4960 FUN_000f4960 (1317 B): equivalent/0x000f4960.cpp [wrapped: macros]
// sym: ?FUN_000f4960@FEThingsBase@fn_000f4960@@QAEXPAVTok@2@HPAVObj_f4960@2@PAVKey_f4960@2@@Z @5ad4780781f0 @we905cc3efaf2
namespace fn_000f4960 {
// STATUS: equivalent (tools/equiv.py level 3: 3121 inputs, branch coverage 84/84)
// FUN_000f4960 @ 0x000f4960

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int memcmp(const void *a, const void *b, unsigned int n);
#endif

#pragma intrinsic(memcmp)
#if defined(__clang__)
static inline int hulk_memcmp(const void *pa, const void *pb, unsigned int n) { const unsigned char *a = (const unsigned char *)pa, *b = (const unsigned char *)pb; for (; n; --n, ++a, ++b) if (*a != *b) return *a < *b ? -1 : 1; return 0; }
#define memcmp hulk_memcmp
#endif

class Tok {
public:
    float FUN_000fad30();
    const char *FUN_000fad90();
    bool FUN_000f9e90();
    int FUN_000faeb0();
    void FUN_000fa0a0();
    bool FUN_000f9ef0();
    void FUN_000f9f30();
    bool FUN_000f9e50();
    int FUN_000fb110();
    void FUN_000f9fb0();
};

class Key_f4960 {
public:
    virtual void v0();
    virtual int v1();
};

class NewObj_f4960;

class Obj_f4960 {
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
    virtual void v16(const char *s);
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
    virtual void v34();
    virtual int v35();
    char pad8c[0xa80 - 4];
    float fa80;
    float fa84;
    float fa88;
    float fa8c;
    float fa90;
    float fa94;
    char pada98[0xbc0 - 0xa98];
    bool bbc0;
    bool bbc1;
    bool bbc2;
    void FUN_000e5510(const char *s);
    void FUN_000f2db0(const char *a, const char *b);
    void FUN_000e55b0(int a, int b, int c);
    void FUN_000f2c10(const char *s);
    void FUN_000f2ee0(const char *s);
    void FUN_000e5570(float a, float b, int c, int d, int e);
    void FUN_000e5540(const char *s);
    void FUN_000f2d40(const char *s);
    void FUN_000e55e0(NewObj_f4960 *n);
};

class NewObj_f4960 {
public:
    char pad0[0xab8];
    bool bab8;
    void FUN_000e4610(char *p);
};

class FEThingsBase;
typedef void (FEThingsBase::*ParseFn)(Tok *, int, Obj_f4960 *, Key_f4960 *);

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        ParseFunctor(FEThingsBase *o, ParseFn f, Obj_f4960 *obj)
        {
            owner = o;
            fn = f;
            zero = 0;
            target = obj;
        }
        virtual void run();
        FEThingsBase *owner;
        ParseFn fn;
        int zero;
        Obj_f4960 *target;
    };

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
    virtual bool v34(Tok *p, Key_f4960 *key, ParseFunctor *pf);
    virtual void v35();
    virtual void v36();
    virtual bool v37(Tok *p, Obj_f4960 *obj, Key_f4960 *key);
    virtual void v38();
    virtual bool v39(Tok *p, void *slot, Key_f4960 *key);
    char pad9c[0x2105 - 4];
    char f2105[0x2210 - 0x2105];
    bool (__cdecl *cb)(void *ud, FEThingsBase *self, Obj_f4960 *obj, Tok *p, Key_f4960 *key);
    void *ud;
    NewObj_f4960 *FUN_000efca0(const char *s, int v);
    void FUN_000f0950(Tok *p, int z, NewObj_f4960 *n, int x);
    void FUN_000f4960(Tok *p, int a1, Obj_f4960 *obj, Key_f4960 *key);
};

void FEThingsBase::FUN_000f4960(Tok *p, int a1, Obj_f4960 *obj, Key_f4960 *key)
{
    int hash = key->v1();
    switch (hash) {
    case 0xfa50b2bf:
        obj->fa88 = p->FUN_000fad30();
        return;
    case 0xaf1f50f1:
        obj->fa84 = p->FUN_000fad30();
        return;
    case 0x9c04d41f: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        obj->FUN_000e5510(s);
        return;
    }
    case 0x887d4b38:
        obj->v16(p->FUN_000fad90());
        return;
    case 0x92a5fe03:
        obj->fa80 = p->FUN_000fad30();
        return;
    case 0xa375e9df:
        obj->fa94 = p->FUN_000fad30();
        return;
    case 0xc4710df4:
        obj->bbc1 = (p->FUN_000faeb0() == 0x4dae9aac);
        return;
    case 0xb37063b4: {
        const char *a = p->FUN_000fad90();
        if (p->FUN_000f9e90())
            obj->FUN_000f2db0(a, p->FUN_000fad90());
        else
            obj->FUN_000f2db0(a, 0);
        return;
    }
    case 0xd208ebe9: {
        int a = (int)p->FUN_000fad30();
        int b = (int)p->FUN_000fad30();
        int c = (int)p->FUN_000fad30();
        obj->FUN_000e55b0(a, b, c);
        return;
    }
    case 0xed3e3b75:
        obj->fa8c = p->FUN_000fad30();
        return;
    case 0x16082730: {
        const char *s = p->FUN_000fad90();
        NewObj_f4960 *n = FUN_000efca0(s, obj->v35());
        n->FUN_000e4610(f2105);
        if (p->FUN_000f9e90()) {
            const char *t = p->FUN_000fad90();
            if (memcmp(t, "hide", 5) == 0)
                n->bab8 = false;
        }
        obj->FUN_000e55e0(n);
        if (!p->FUN_000f9ef0())
            p->FUN_000fa0a0();
        p->FUN_000f9f30();
        while (p->FUN_000f9e50())
            FUN_000f0950(p, 0, n, p->FUN_000fb110());
        p->FUN_000f9fb0();
        return;
    }
    case 0x03cab25b:
        obj->fa90 = p->FUN_000fad30();
        return;
    case 0x16b6f665:
        obj->FUN_000f2c10(p->FUN_000fad90());
        return;
    case 0x2040515c:
        obj->FUN_000f2ee0(p->FUN_000fad90());
        return;
    case 0x329543ac: {
        float f1 = p->FUN_000fad30();
        float f2 = p->FUN_000fad30();
        int a = (int)p->FUN_000fad30();
        int b = (int)p->FUN_000fad30();
        int c = (int)p->FUN_000fad30();
        obj->FUN_000e5570(f1, f2, a, b, c);
        return;
    }
    case 0x425c8bd6: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        obj->FUN_000e5540(s);
        return;
    }
    case 0x35c3a495:
        obj->FUN_000f2d40(p->FUN_000fad90());
        return;
    case 0x6969d81b:
        obj->bbc2 = (p->FUN_000faeb0() == 0x4dae9aac);
        return;
    case 0x6b6e3c3a:
        obj->bbc0 = (p->FUN_000faeb0() == 0x4dae9aac);
        return;
    default:
        break;
    }

    if (v39(p, &((char *)obj)[0x9dc], key))
        return;
    if (v37(p, obj, key))
        return;
    ParseFunctor pf(this, &FEThingsBase::FUN_000f4960, obj);
    if (v34(p, key, &pf))
        return;
    if (cb) {
        if (cb(ud, this, obj, p, key))
            return;
    }
    p->FUN_000fa0a0();
}
} // namespace fn_000f4960
#undef memcmp


// 0x000f4e90 FUN_000f4e90 (514 B): matches/0x000f4e90.cpp [wrapped: conflict: FEThingsBase; Param]
// sym: ?FUN_000f4e90@FEThingsBase@fn_000f4e90@@QAEXPAVParam@2@HPAVTarget_f4e90@2@PAVArgs_f4e90@2@@Z
namespace fn_000f4e90 {
// FUN_000f4e90 @ 0x000f4e90
class Param {
public:
    hulk_intptr FUN_000fad90();
    void FUN_000fa0a0();
};

class Args_f4e90 {
public:
    virtual void v0();
    virtual int GetType();
};

class Target_f4e90 {
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
    virtual void SetA(int v);
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
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int GetA(int v);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual int GetB(int v);
    char pad04[0x988];
    int field98c;
    int field990;
    int field994;
    int field998;
    int field99c;
    int field9a0;
    void FUN_000f2f50(int v);
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, int, Target_f4e90 *, Args_f4e90 *);
        hulk_intptr mC;
        Target_f4e90 *mD;
    };

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
    virtual char v34(Param *p, Args_f4e90 *a, ParseFunctor *f);
    virtual void v35();
    virtual void v36();
    virtual char v37(Param *p, Target_f4e90 *t, Args_f4e90 *a);
    char pad[0x2210 - 4];
    char (*callback)(int ctx, FEThingsBase *self, int zero, Param *p, Args_f4e90 *a);
    int callbackCtx;

    void FUN_000f4e90(Param *p, int unused, Target_f4e90 *t, Args_f4e90 *a);
};

void FEThingsBase::FUN_000f4e90(Param *p, int unused, Target_f4e90 *t, Args_f4e90 *a)
{
    switch (a->GetType()) {
    case 0xf98f68f8:
        {
        int v = p->FUN_000fad90();
        t->field994 = t->GetA(v);
    }
        return;
    case 0xf98f68f9:
        {
        int v = p->FUN_000fad90();
        t->field990 = t->GetA(v);
    }
        return;
    case 0x9f92b475:
        {
        int v = p->FUN_000fad90();
        t->field98c = t->GetA(v);
    }
        return;
    case 0x9f77dd3b:
        {
        int v = p->FUN_000fad90();
        t->field998 = t->GetB(v);
    }
        return;
    case 0xe016e44e:
        {
        int v = p->FUN_000fad90();
        t->field9a0 = t->GetB(v);
    }
        return;
    case 0x5b01c46b:
        {
        int v = p->FUN_000fad90();
        t->field99c = t->GetB(v);
    }
        return;
    case 0x887d4b38:
        t->SetA(p->FUN_000fad90());
        return;
    case 0x35c3a495:
        t->FUN_000f2f50(p->FUN_000fad90());
        return;
    }
    if (v37(p, t, a))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f4e90;
    f.mC = 0;
    f.mD = t;
    if (v34(p, a, &f))
        return;
    if (callback) {
        if (callback(callbackCtx, this, 0, p, a))
            return;
    }
    p->FUN_000fa0a0();
}
} // namespace fn_000f4e90


// 0x000f50a0 FUN_000f50a0 (135 B): equivalent/0x000f50a0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?FUN_000f50a0@Slots_f50a0@fn_000f50a0@@QAEXPBD@Z @0ad6a44a570b @wb94338e4f605
namespace fn_000f50a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000f50a0 @ 0x000f50a0
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

namespace pure3d { class Scenegraph; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual T *Cast(void *);
};
}
}
typedef unsigned __int64 Key_f50a0;

struct Controller_f50a0 {
    virtual void AddRef();
};

class Inventory_f50a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Controller_f50a0 *Find(void *caster, Key_f50a0 key);
};

class Slots_f50a0 {
public:
    char pad00[0x1a5c];
    Controller_f50a0 *controllers[2];
    char names[2][0x100];
    char pad_names[0x2105 - 0x1a5c - 8 - 0x200];
    char defaultName[1];
    void FUN_000f50a0(const char *assetName);
};

// Loads the named controller into the first free slot and remembers the default name next to it.
void Slots_f50a0::FUN_000f50a0(const char *assetName)
{
    int i;
    for (i = 0; i < 2; ++i) {
        if (!controllers[i])
            break;
    }
    if (i >= 2)
        return;
    Inventory_f50a0 *inv = (*(Inventory_f50a0**)&DAT_004dd9cc);
    Key_f50a0 key = FUN_0027b020(assetName);
    content::LoadInventory::DynamicCaster<pure3d::Scenegraph> caster;
    Controller_f50a0 *c = inv->Find(&caster, key);
    controllers[i] = c;
    if (!c)
        return;
    c->AddRef();
    char *dst = names[i];
    const char *src = defaultName;
    char ch;
    do {
        ch = *src++;
        *dst++ = ch;
    } while (ch);
}
} // namespace fn_000f50a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f5130 FUN_000f5130 (209 B): equivalent/0x000f5130.cpp [wrapped: conflict: content::LoadInventory; pure3d::MultiController]
// sym: ?Run@Object@fn_000f5130@@QAEXPBD0@Z @b6bb860987ac @wd162c491b314
namespace fn_000f5130 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000f5130 @ 0x000f5130
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

namespace pure3d { struct MultiController { virtual void Activate(); }; struct Scenegraph; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual T* Cast(void*); }; }; }
typedef unsigned __int64 Key_f5130;
struct Inventory_f5130 { virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual pure3d::MultiController* Find(void*, Key_f5130); };
void __cdecl FUN_000f6410(pure3d::MultiController*, void*);
struct Object { char pad[0x1c64]; pure3d::MultiController* controllers[2]; char gap[8]; char names[2][256]; char gap2[0x2105-0x1e74]; char name[1]; void Run(const char*, const char*); };
void Object::Run(const char* a, const char* b) {
 int i; for(i=0;i<2;++i) if(!controllers[i]) break;
 if(i==2) return;
 Inventory_f5130* inv=(*(Inventory_f5130**)&DAT_004dd9cc);
 Key_f5130 key=FUN_0027b020(a);
 content::LoadInventory::DynamicCaster<pure3d::MultiController> caster;
 pure3d::MultiController* c=inv->Find(&caster,key);
 controllers[i]=c;
 if(!c) return;
 c->Activate();
 if(b) {
 inv=(*(Inventory_f5130**)&DAT_004dd9cc);
 key=FUN_0027b020(b);
 content::LoadInventory::DynamicCaster<pure3d::Scenegraph> sceneCaster;
 void* scene=inv->Find(&sceneCaster,key);
 if(!scene) return;
 FUN_000f6410(controllers[i],scene);
 }
 char* dst=names[i]; const char* src=name;
 do { *dst=*src; ++dst; } while(*src++);
}
} // namespace fn_000f5130
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f5210 FUN_000f5210 (135 B): equivalent/0x000f5210.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?FUN_000f5210@Slots_f5210@fn_000f5210@@QAEXPBD@Z @30ac8738adb5 @w3a468dd83d31
namespace fn_000f5210 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000f5210 @ 0x000f5210
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

namespace pure3d { class CompositeDrawable; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual T *Cast(void *);
};
}
}
typedef unsigned __int64 Key_f5210;

struct Controller_f5210 {
    virtual void AddRef();
};

class Inventory_f5210 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Controller_f5210 *Find(void *caster, Key_f5210 key);
};

class Slots_f5210 {
public:
    char pad00[0x1c6c];
    Controller_f5210 *controllers[2];
    char gap[0x200];
    char names[2][0x100];
    char pad_names[0x2105 - 0x1c6c - 8 - 0x200 - 0x200];
    char defaultName[1];
    void FUN_000f5210(const char *assetName);
};

// Loads the named controller into the first free slot and remembers the default name next to it.
void Slots_f5210::FUN_000f5210(const char *assetName)
{
    int i;
    for (i = 0; i < 2; ++i) {
        if (!controllers[i])
            break;
    }
    if (i >= 2)
        return;
    Inventory_f5210 *inv = (*(Inventory_f5210**)&DAT_004dd9cc);
    Key_f5210 key = FUN_0027b020(assetName);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Controller_f5210 *c = inv->Find(&caster, key);
    controllers[i] = c;
    if (!c)
        return;
    c->AddRef();
    char *dst = names[i];
    const char *src = defaultName;
    char ch;
    do {
        ch = *src++;
        *dst++ = ch;
    } while (ch);
}
} // namespace fn_000f5210
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f52a0 FUN_000f52a0 (135 B): equivalent/0x000f52a0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?FUN_000f52a0@Slots_f52a0@fn_000f52a0@@QAEXPBD@Z @cf963a2f6511 @wa3992379acff
namespace fn_000f52a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_000f52a0 @ 0x000f52a0
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

namespace pure3d { class LightGroup; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual T *Cast(void *);
};
}
}
typedef unsigned __int64 Key_f52a0;

struct Controller_f52a0 {
    virtual void AddRef();
};

class Inventory_f52a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Controller_f52a0 *Find(void *caster, Key_f52a0 key);
};

class Slots_f52a0 {
public:
    char pad00[0x1854];
    Controller_f52a0 *controllers[2];
    char names[2][0x100];
    char pad_names[0x2105 - 0x1854 - 8 - 0x200];
    char defaultName[1];
    void FUN_000f52a0(const char *assetName);
};

// Loads the named controller into the first free slot and remembers the default name next to it.
void Slots_f52a0::FUN_000f52a0(const char *assetName)
{
    int i;
    for (i = 0; i < 2; ++i) {
        if (!controllers[i])
            break;
    }
    if (i >= 2)
        return;
    Inventory_f52a0 *inv = (*(Inventory_f52a0**)&DAT_004dd9cc);
    Key_f52a0 key = FUN_0027b020(assetName);
    content::LoadInventory::DynamicCaster<pure3d::LightGroup> caster;
    Controller_f52a0 *c = inv->Find(&caster, key);
    controllers[i] = c;
    if (!c)
        return;
    c->AddRef();
    char *dst = names[i];
    const char *src = defaultName;
    char ch;
    do {
        ch = *src++;
        *dst++ = ch;
    } while (ch);
}
} // namespace fn_000f52a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f5330 FEThingsBase::vfunc_37 (2020 B): equivalent/0x000f5330.cpp [wrapped: conflict: FEThingsBase; Param]
// sym: ?v37@FEThingsBase@fn_000f5330@@UAEDPAVParam@2@PAVFactory_f5330@2@PAVArgs_f5330@2@@Z @1752d366becc @wfea459d0013d
namespace fn_000f5330 {
// STATUS: equivalent (tools/equiv.py level 3: 3136 inputs, branch coverage 134/134)
// FEThingsBase::vfunc_37 @ 0x000f5330

class Item_f5330 {
public:
    virtual int v0();
    virtual int type();
};


class Node {
public:
    char pad0[0x6c];
    int f6c;
    int f70;
    char pad74[0x1d84 - 0x74];
    char b1d84;
    void FUN_000e0170(int v);
    void FUN_000e3750(Node *v);
};

class Args_f5330 {
public:
    virtual int v0();
    virtual int type();
};

class Param {
public:
    hulk_intptr FUN_000fad90();
    char FUN_000f9ef0();
    void FUN_000f9f30();
    char FUN_000f9e50();
    Item_f5330 *FUN_000fb110();
    void FUN_000f9fb0();
    void FUN_000fa0a0();
    char FUN_000f9e90();
};

class Factory_f5330 {
public:
    virtual Node *v0(int a, int b);
    virtual Node *v1(int a, int b);
    virtual Node *v2(int a, int b);
    virtual Node *v3(int a, int b);
    virtual Node *v4(int a, int b);
    virtual Node *v5(int a, int b);
    virtual Node *v6(int a, int b);
    virtual Node *v7(int a, int b);
    virtual Node *v8(int a, int b);
    virtual Node *v9(int a, int b);
    virtual Node *v10(int a, int b);
    virtual Node *v11(int a, int b);
    virtual Node *v12(int a, int b);
    virtual Node *v13(int a, int b);
    virtual Node *v14(int a, int b);
    virtual Node *v15(int a, int b);
    virtual Node *v16(int a, int b);
    virtual Node *v17(int a, int b);
    virtual Node *v18(int a, int b);
    virtual Node *v19(int a, int b);
    virtual Node *v20(int a, int b);
    virtual Node *v21(int a, int b);
    virtual Node *v22(int a);
    virtual Node *v23(int a, int b);
    virtual Node *v24(int a, int b);
    virtual Node *v25(int a, int b);
    virtual Node *v26(int a, int b);
    virtual Node *v27(int a, int b);
    virtual Node *v28(int a, int b);
    virtual Node *v29(int a, int b);
    virtual Node *v30(int a, int b);
    virtual Node *v31(int a, int b);
    virtual Node *v32(int a, int b);
    virtual Node *v33(int a, int b);
    virtual Node *v34(int a, int b);
    virtual Node *v35(int a, int b);
    virtual Node *v36(int a, int b);
    virtual Node *v37(int a, int b);
    virtual Node *v38(int a, int b);
    virtual Node *v39(int a, int b);
    virtual Node *v40(int a, int b);
    virtual Node *v41(int a, int b);
    virtual Node *v42(int a, int b);
    virtual Node *v43(int a, int b);
    virtual Node *v44(int a, int b);
};

class FEThingsBase {
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
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual char v37(Param *a0, Factory_f5330 *a1, Args_f5330 *a2);
    virtual void v38();
    virtual void v39();
    char pad04[0x1804 - 4];
    int f1804;
    int f1808;

    void FUN_000eff20(Param *a, Factory_f5330 *b, int z, int k);
    void FUN_000e7ad0(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000e7930(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000f3940(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000f3f00(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000e7770(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000f3dc0(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000f3b20(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000f42c0(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
    void FUN_000f1e50(Param *p, Factory_f5330 *f, Node *n, Item_f5330 *i);
};

char FEThingsBase::v37(Param *a0, Factory_f5330 *a1, Args_f5330 *a2)
{
    Node *n;
    int t;

    switch (a2->type()) {
    case 0x9b3b78da:
        FUN_000eff20(a0, a1, 0, 0xb);
        return 1;
    case (int)0xccbb2461:
        FUN_000eff20(a0, a1, 0, 6);
        return 1;
    case (int)0xdf91462a:
        FUN_000eff20(a0, a1, 0, 8);
        return 1;
    case 0x11a78a91:
        FUN_000eff20(a0, a1, 0, 0xc);
        return 1;
    case 0x16b5f73c:
        FUN_000eff20(a0, a1, 0, 5);
        return 1;
    case 0x33873914:
        FUN_000eff20(a0, a1, 0, 0xa);
        return 1;
    case 0x2627546a:
        FUN_000eff20(a0, a1, 0, 7);
        return 1;
    case 0x4c8fab99:
        FUN_000eff20(a0, a1, 0, 0xd);
        return 1;
    case 0x5c000339:
        FUN_000eff20(a0, a1, 0, 9);
        return 1;
    case (int)0x80f230c2: {
        t = a0->FUN_000fad90();
        n = a1->v22(t);
        if (!a0->FUN_000f9ef0())
            a0->FUN_000fa0a0();
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50()) {
            if (a0->FUN_000fb110()->type() == 0x2d848685)
                n->FUN_000e0170(a0->FUN_000fad90());
            else
                a0->FUN_000fa0a0();
        }
        a0->FUN_000f9fb0();
        return 1;
    }
    case (int)0x9f62170f:
        t = a0->FUN_000fad90();
        n = a1->v32(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000e7ad0(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case (int)0xf801065b:
        t = a0->FUN_000fad90();
        n = a1->v31(t, 0);
        if (a0->FUN_000f9e90()) {
            const char *s = (const char *)a0->FUN_000fad90();
            const char *lit = "wrap";
            int i;
            for (i = 0; i < 5; i++) {
                if (s[i] != lit[i])
                    break;
            }
            if (i == 5)
                n->b1d84 = 1;
        }
        n->FUN_000e3750(a1->v29(t, 0));
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000e7930(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case (int)0xf71ffd40: {
        int x;
        t = a0->FUN_000fad90();
        if (a0->FUN_000f9e90())
            x = a0->FUN_000fad90();
        else
            x = 0;
        n = a1->v26(t, x);
        if (x == 0) {
            n->f6c = f1804;
            n->f70 = f1808;
        }
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3940(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    }
    case 0x028a7c50: {
        int x;
        t = a0->FUN_000fad90();
        if (a0->FUN_000f9e90())
            x = a0->FUN_000fad90();
        else
            x = 0;
        n = a1->v33(t, x);
        if (x == 0) {
            n->f6c = f1804;
            n->f70 = f1808;
        }
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3f00(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    }
    case 0x46fd849c: {
        int x;
        t = a0->FUN_000fad90();
        if (a0->FUN_000f9e90())
            x = a0->FUN_000fad90();
        else
            x = 0;
        n = a1->v25(t, x);
        if (x == 0) {
            n->f6c = f1804;
            n->f70 = f1808;
        }
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000e7770(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    }
    case 0x4a9bc1d7:
        t = a0->FUN_000fad90();
        n = a1->v28(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3dc0(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case 0x56b9eee7:
        t = a0->FUN_000fad90();
        n = a1->v27(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f3b20(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case 0x5e3b266f:
        t = a0->FUN_000fad90();
        n = a1->v30(t, 0);
        if (a0->FUN_000f9e90()) {
            const char *s = (const char *)a0->FUN_000fad90();
            const char *lit = "wrap";
            int i;
            for (i = 0; i < 5; i++) {
                if (s[i] != lit[i])
                    break;
            }
            if (i == 5)
                n->b1d84 = 1;
        }
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f42c0(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    case 0x7615e4bd:
        t = a0->FUN_000fad90();
        n = a1->v29(t, 0);
        n->f6c = f1804;
        n->f70 = f1808;
        if (!a0->FUN_000f9ef0())
            return 1;
        a0->FUN_000f9f30();
        while (a0->FUN_000f9e50())
            FUN_000f1e50(a0, a1, n, a0->FUN_000fb110());
        a0->FUN_000f9fb0();
        return 1;
    default:
        return 0;
    }
}
} // namespace fn_000f5330


// 0x000f5b20 FUN_000f5b20 (1141 B): equivalent/0x000f5b20.cpp [wrapped: conflict: FEThingsBase; Param]
// sym: ?FUN_000f5b20@FEThingsBase@fn_000f5b20@@QAEXTParamSlot@2@PAVSource@2@PAXPAVArgs_f5b20@2@@Z @890aa2c02809 @wa88c7ce069d6
namespace fn_000f5b20 {
// STATUS: equivalent (tools/equiv.py level 3: 20044 inputs, branch coverage 70/70)
// FUN_000f5b20 @ 0x000f5b20
class Param {
public:
    float FUN_000fad30();
    hulk_intptr FUN_000fad90();
    int FUN_000faeb0();
    char FUN_000f9e90();
    char FUN_000f9ef0();
    char FUN_000f9e50();
    int FUN_000fb110();
    void FUN_000f9f30();
    void FUN_000f9fb0();
    void FUN_000fa0a0();
};

union ParamSlot {
    Param *p;
    float f;
};

class Args_f5b20 {
public:
    virtual void v0();
    virtual int GetType();
};

class Source;

struct Node {
    char pad[0x858];
    char name[1];
    void FUN_000e4610(const char *s);
    void FUN_000f8970(int t);
    void FUN_001bded0(int t);
};

struct Holder_f5b20 {
    void FUN_000f8df0(int name, float f, int v);
    void FUN_000f8e70(int name, int iv, int v);
};

extern "C" int __cdecl FUN_0034483c();

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(ParamSlot param, Source *c, void *d, Args_f5b20 *args);
        Source *mC;
        void *mD;
    };

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
    virtual char v34(Param *p, Args_f5b20 *a, ParseFunctor *f);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual char v39(Param *p, char *buf, Args_f5b20 *a);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Node *v44();
    virtual Node *v45();

    int field4;
    Holder_f5b20 *field8;
    char pad0c[0x1828 - 0xc];
    int field1828;
    char pad182c[0x2078 - 0x182c];
    char buf2078[0x2104 - 0x2078];
    char flag2104;
    char str2105[1];

    Node *FUN_000efca0(int t, int f);
    Node *FUN_000e6620(int t);
    Node *FUN_000e66f0(int t);
    Node *FUN_000e67b0(int t);
    void FUN_000e8180(Param *p, int zero, Node *n, int x);
    void FUN_000f4960(Param *p, int zero, Node *n, int x);
    void FUN_000f4e90(Param *p, int zero, Node *n, int x);
    void FUN_000e7f60(Param *p, int zero, Node *n, int x);
    void FUN_000f5130(int t, int v);
    void FUN_000f50a0(int t);
    void FUN_000f52a0(int t);

    void FUN_000f5b20(ParamSlot slot, Source *c, void *d, Args_f5b20 *args);
};

struct ParseFrame {
    FEThingsBase::ParseFunctor f;
};

void FEThingsBase::FUN_000f5b20(ParamSlot slot, Source *c, void *d, Args_f5b20 *args)
{
    Param *param = slot.p;
    ParseFrame fr;
    Node *n;
    switch (args->GetType()) {
    case 0x16082730:
        {
            int t = param->FUN_000fad90();
            n = FUN_000efca0(t, field1828);
        }
        n->FUN_000e4610(str2105);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000e8180(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    case 0x1126cb0c: {
        int t = param->FUN_000fad90();
        v44()->FUN_000f8970(t);
        v45()->FUN_001bded0(t);
        return;
    }
    case (int)0xb37063b4: {
        int t = param->FUN_000fad90();
        if (param->FUN_000f9e90())
            FUN_000f5130(t, param->FUN_000fad90());
        else
            FUN_000f5130(t, 0);
        return;
    }
    case 0x169d3c55:
        n = FUN_000e6620(param->FUN_000fad90());
        n->FUN_000e4610(str2105);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000f4960(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    case 0x2040515c:
        FUN_000f52a0(param->FUN_000fad90());
        return;
    case 0x35c3a495:
        FUN_000f50a0(param->FUN_000fad90());
        return;
    case 0x535a4bed: {
        n = FUN_000e66f0(param->FUN_000fad90());
        const char *s = str2105;
        char *dst = n->name;
        char ch;
        do {
            ch = *s++;
            *dst++ = ch;
        } while (ch);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000f4e90(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    }
    case 0x5d3387b7:
        n = FUN_000e67b0(param->FUN_000fad90());
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000e7f60(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    case 0x62deec48:
        return;
    case 0x69fb0023: {
        int name = param->FUN_000fad90();
        slot.f = param->FUN_000fad30();
        if (param->FUN_000f9e90())
        {
            int tmp1 = param->FUN_000fad90();
            field8->FUN_000f8df0(name, slot.f, tmp1);
        }
        else
            field8->FUN_000f8df0(name, slot.f, 0);
        return;
    }
    case 0x6b6e3c3a: {
        int h = param->FUN_000faeb0();
        if (h == 0x4dae9aac) {
            flag2104 = 1;
            return;
        }
        if (h == (int)0xa3c653f9) {
            flag2104 = 0;
            return;
        }
        param->FUN_000fa0a0();
        return;
    }
    case 0x739453ea: {
        int name = param->FUN_000fad90();
        slot.f = param->FUN_000fad30();
        int v = 0;
        if (param->FUN_000f9e90())
            v = param->FUN_000fad90();
        field8->FUN_000f8e70(name, (int)slot.f, v);
        return;
    }
    }
    if (v39(param, buf2078, args))
        return;
    fr.f.mObj = this;
    fr.f.mFn = &FEThingsBase::FUN_000f5b20;
    fr.f.mC = 0;
    fr.f.mD = 0;
    if (v34(param, args, &fr.f))
        return;
    param->FUN_000fa0a0();
}
} // namespace fn_000f5b20

namespace fn_f5892d97 {

// 0x000f5fa0 FUN_000f5fa0 (418 B): equivalent/0x000f5fa0.cpp
// sym: ?FUN_000f5fa0@Runner_f5fa0@fn_f5892d97@@QAEXPBDH@Z @b89e983e4945 @w92b1e1af17c3
// STATUS: equivalent (tools/equiv.py level 3: 12579 inputs, branch coverage 20/20)
// FUN_000f5fa0 @ 0x000f5fa0
void Runner_f5fa0::FUN_000f5fa0(const char *src, int arg)
{
    Frame_f5fa0 f;
    if (!active)
        f220c = arg;
    DollyScript::CScriptParser_f5fa0 *p = (DollyScript::CScriptParser_f5fa0 *)f.parser;
    for (Slot_f5fa0 *slot = p->table.slots; slot != p->table.slots + 0x80; slot++) {
        slot->a = 0;
        slot->b = 0;
        slot->c = 0;
    }
    p->tail.f10 = 0;
    p->tail.f00 = 0;
    p->tail.f14 = 0;
    p->tail.f18 = 0;
    strncpy(name, src, 0x100);
    int old = FUN_00266da0(10);
    Script_f5fa0 *script = ((Script_f5fa0 *)((owners::Inventory_fb240 *)&(p->handle))->FUN_000fb240((void *)name));
    FUN_00266da0(old);
    p->FUN_000faa10(script);
    if (active) {
        if (p->FUN_000f9e50()) {
            do {
                Node *node = p->FUN_000fb110();
                FUN_000f5b20(p, 0, 0, node);
            } while (p->FUN_000f9e50());
        }
    } else {
        if (p->FUN_000f9e50()) {
            do {
                Node *node = p->FUN_000fb110();
                if (node->vfunc_1() == 0x62deec48) {
                    int v = p->FUN_000fad90();
                    f.w = 0;
                    (*(Loader_f5fa0**)&DAT_00527c58)->FUN_00265920(v, &f.w, 0);
                    // MSVC evaluates the argument before loading the sink
                    int sinkArg = f.w->FUN_00266700();
                    (*(Sink_f5fa0**)&DAT_004dd9cc)->FUN_00266220(sinkArg);
                    count++;
                }
            } while (p->FUN_000f9e50());
        }
    }
    if (script) {
        script->FUN_000f9a80();
        FUN_0008d330(script);
    }
    if (active) {
        vfunc_6();
        active = 0;
    } else {
        vfunc_64(0, 0, 0);
    }
    p->DollyScript::CScriptParser_f5fa0::~CScriptParser_f5fa0();
}


// 0x000f61e0 FUN_000f61e0 (1 B): matches/0x000f61e0.cpp
// sym: _FUN_000f61e0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_000f61e0() {}


// 0x000f6370 FUN_000f6370 (78 B): matches/0x000f6370.cpp
// sym: ?Target@S_f6370@fn_f5892d97@@QAE?AUV@2@XZ
V S_f6370::Target() {
    V local;
    ((owners::C_284820 *)api)->FUN_00284820((hulk_intptr)0);
    ((owners::Obj_2848b0 *)api)->FUN_002848b0((hulk_intptr)(api->FnB_002843a0(c, d)), 0, (int*)&local);
    return local;
}

} // namespace fn_f5892d97

// 0x000f63c0 FUN_000f63c0 (71 B): equivalent/0x000f63c0.cpp [wrapped: conflict: Object]
// sym: ?FUN_000f63c0@Object@fn_000f63c0@@QAEXPAI@Z @8ec3ede7b3f3 @wa9500be99d9e
namespace fn_000f63c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000f63c0 @ 0x000f63c0
struct Device {
    int FUN_002843a0(int first, int second);
    void FUN_00284860(int result, int zero, void *out);
};
struct Object {
    Device *device;
    int unknown4;
    int first;
    int second;
    void FUN_000f63c0(unsigned int *out);
};
void Object::FUN_000f63c0(unsigned int *out) {
    unsigned int values[16];
    ((owners::C_284820 *)device)->FUN_00284820((hulk_intptr)0);
    int result = device->FUN_002843a0(first, second);
    device->FUN_00284860(result, 0, values);
    for (int i = 0; i < 16; ++i) out[i] = values[i];
}
} // namespace fn_000f63c0

namespace fn_f5892d97 {

// 0x000f6410 FUN_000f6410 (1 B): matches/0x000f6410.cpp
// sym: ?FUN_000f6410@fn_f5892d97@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000f6410() {}


// 0x000f6420 FUN_000f6420 (53 B): matches/0x000f6420.cpp
// sym: ?f@S_f6420@fn_f5892d97@@QAEXXZ
// Same code shape as 0x000c5b40 (propagated; names are from that function)
void S_f6420::f() {
    if (p) {
        count = 0;
        a = 0;
        *(int*)((char*)this + count * 8 + 8) = 0;
        result = Fng_002961d0(p);
        last = 0;
    }
}


// 0x000f6460 FUN_000f6460 (183 B): equivalent/0x000f6460.cpp
// sym: ?FUN_000f6460@Traversal@fn_f5892d97@@QAEPAUNode@2@XZ @8413a0eb1c8f @wc7d2bf925812
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000f6460 @ 0x000f6460
Node* Traversal::FUN_000f6460() {
 while (current) {
  int count = current->count();
  if (index < count) {
   ++depth;
   if (depth >= 128) return 0;
   frames[depth].node = current;
   frames[depth].index = index;
   Node* result = current->child(index);
   current = result;
   index = 0;
   return result;
  }
  int oldDepth = depth;
  current = frames[oldDepth].node;
  int oldIndex = frames[oldDepth].index;
  index = oldIndex;
  depth = oldDepth - 1;
  index = oldIndex + 1;
 }
 return current;
}


// 0x000f6530 FUN_000f6530 (217 B): equivalent/0x000f6530.cpp
// sym: _FUN_000f6530 @d48e95a602be @w04dfd3db271d
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000f6530 @ 0x000f6530
extern "C" void __cdecl FUN_000f6530(void * source, void * dest) {
 ((Object *)dest)->setFirst(((Object *)source)->getFirst());
 ((Object *)dest)->setSecond(((Object *)source)->getSecond());
 struct Frame { unsigned a, b; Triple_f6530 t; } f;   // (the original's slot order)
 ((Object *)source)->getPair(&f.a,&f.b);
 ((Object *)dest)->setPair(f.a,f.b);
 f.t=((Object *)source)->atDC;
 ((owners::C_293a90 *)(((Object *)dest)))->FUN_00293a90((int *)(Triple_f6530 *)(&f.t));
 f.t=((Object *)source)->atE8;
 ((Object *)dest)->FUN_00293ac0(&f.t);
 f.t=((Object *)source)->atD0;
 ((owners::C_293af0 *)(((Object *)dest)))->FUN_00293af0((int *)(Triple_f6530 *)(&f.t));
}


// 0x000f6610 FUN_000f6610 (70 B): matches/0x000f6610.cpp
// sym: _FUN_000f6610
extern "C" char* __cdecl FUN_000f6610(const char* s) {
    if (s) {
        hulk_uintptr n = strlen(s) + 1;
        char* d = (char*)malloc(n);
        if (!d)
            return 0;
        memcpy(d, s, n);
        return d;
    }
    return 0;
}


// 0x000f6660 FUN_000f6660 (30 B): matches/0x000f6660.cpp
// sym: _FUN_000f6660
extern "C" int FUN_000f6660(int a, int b) {
    if (a >= 0)
        return a % b;
    return b - (-a % b);
}


// 0x000f6680 FUN_000f6680 (449 B): equivalent/0x000f6680.cpp
// sym: ?FUN_000f6680@fn_f5892d97@@YAXPAUObj_f6680@1@MM@Z @5b22d85cdb30 @wc11204bd9d3d
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// FUN_000f6680 @ 0x000f6680
void FUN_000f6680(Obj_f6680 *p, float angle, float k)
{
    struct Frame {
        V3_f6680 a;
        V3_f6680 b;
        V3_f6680 c;
        Mat_f6680 m;
    } f;
    f.a = p->a;
    f.b = p->b;
    f.c.x = p->b.x;
    f.c.y = p->b.y;
    f.c.z = p->b.z;

    hulk_freg cx = f.c.y * f.a.z - f.c.z * f.a.y;
    hulk_freg cy = f.c.z * f.a.x - f.a.z * f.c.x;
    hulk_freg cz = f.a.y * f.c.x - f.c.y * f.a.x;
    f.c.x = cx;
    f.c.y = cy;
    f.c.z = cz;

    double la = sqrt(f.a.y * f.a.y + f.a.z * f.a.z + f.a.x * f.a.x);
    double dot = f.b.z * f.a.z + f.b.y * f.a.y + f.b.x * f.a.x;
    hulk_freg lb = sqrt(f.b.z * f.b.z + f.b.y * f.b.y + f.b.x * f.b.x);
    hulk_freg r = FUN_00018a20((float)(dot / la * lb));
    f.b.FUN_0022d180();

    if ((k < 0.0f && r > 0.196349546f) || (k > 0.0f && r < 2.94524312f)) {
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&f.c, k);
        ((owners::Obj_22d260 *)&(f.b))->FUN_0022d260((owners::Obj_22d260 *)(const Mat_f6680 *)(&f.m));
    }
    f.m.FUN_0022b980();
    f.m.FUN_0022baf0(&f.a, -angle);
    ((owners::Obj_22d260 *)&(f.b))->FUN_0022d260((owners::Obj_22d260 *)(const Mat_f6680 *)(&f.m));
    ((owners::C_293a90 *)p)->FUN_00293a90((int *)(const V3_f6680 *)(&f.b));
}


// 0x000f6850 FUN_000f6850 (69 B): matches/0x000f6850.cpp
// sym: ?Run@Obj_f6850@fn_f5892d97@@QAEPAV12@PAVArg_f6850@2@@Z
// Same code shape as 0x000c6a20 (propagated; names are from that function)
Obj_f6850* Obj_f6850::Run(Arg_f6850* arg) {
    mArg = arg;
    if (arg) {
        arg->F();
        if (mArg) {
            mIndex = 0;
            mOne = 0;
            ((int*)this)[mIndex * 2 + 2] = 0;
            m408 = mArg->FnG_002961d0();
            m40c = 0;
        }
    }
    return this;
}


// 0x000f68a0 FUN_000f68a0 (22 B): matches/0x000f68a0.cpp
// sym: ?f@C_f68a0@fn_f5892d97@@QAEXXZ
// Same code shape as 0x00045820 (propagated; names are from that function)
void C_f68a0::f() {
    if (p) {
        p->b();
        p = 0;
    }
}


// 0x000f69e0 FUN_000f69e0 (134 B): matches/0x000f69e0.cpp
// sym: _FUN_000f69e0
// FUN_000f69e0 @ 0x000f69e0
// Extent of the bounds: |max - min| per component.
extern "C" void __cdecl FUN_000f69e0(void *bounds, void *out)
{
    Box_f69e0 b = ((Bounds_f69e0 *)bounds)->box;
    FloatBits_f69e0 d;
    d.f = b.max.x - b.min.x;
    d.u &= 0x7fffffff;
    ((Vec3_f69e0 *)out)->x = d.f;
    d.f = b.max.y - b.min.y;
    d.u &= 0x7fffffff;
    ((Vec3_f69e0 *)out)->y = d.f;
    d.f = b.max.z - b.min.z;
    d.u &= 0x7fffffff;
    ((Vec3_f69e0 *)out)->z = d.f;
}


// 0x000f6a70 FUN_000f6a70 (116 B): matches/0x000f6a70.cpp
// sym: ?Calc@fn_f5892d97@@YAMPAUInput_f6a70@1@PAUCamera@1@PAX@Z
// data: gService = DAT_0052c2a4
hulk_freg __cdecl Calc(Input_f6a70* a, Camera* b, void* c) {
    if (!a || !c)
        return 1.0f;
    float pad[4];
    float d = a->value;
    pad[3] = d;
    pad[0] = a->angle;
    hulk_freg y = (*(Service_f6a70**)&DAT_0052c2a4)->Get();
    float z = b->value - pad[3];
    int bits = *(int*)&z;
    bits &= 0x7fffffff;
    z = *(float*)&bits;
    hulk_freg r = tan(pad[0] * 0.5f) / y;
    r = r * z;
    r = r + r;
    return r * 9.5238094e-05f;
}

} // namespace fn_f5892d97

// 0x000f6af0 FUN_000f6af0 (85 B): equivalent/0x000f6af0.cpp [wrapped: conflict: Inventory; content::LoadInventory; pure3d::CompositeDrawable]
// sym: _FUN_000f6af0 @d6d2ccc3e4a1 @wd779b1dddc03
namespace fn_000f6af0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f6af0 @ 0x000f6af0

typedef unsigned __int64 U64;
struct Drawable { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual int slot11(); };
namespace pure3d { struct CompositeDrawable {}; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void slot0(); }; }; }
typedef content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> Caster;
struct Inventory { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Drawable* slot3(Caster*, unsigned, unsigned); };
struct InventoryTable { void* slot0; void* slot1; void* slot2; Drawable* (__fastcall *slot3)(Inventory*, int, Caster*, unsigned, unsigned); };
extern "C++" __declspec(nothrow) U64 __cdecl FUN_002672f0(int, int, int);
extern U64 __cdecl FUN_0027b020(int);
struct Result { int value; int unused; unsigned low; unsigned high; };
extern "C" void __cdecl FUN_000f6af0(int name, int aux, Result* result) {
    Inventory* inventory = (*(Inventory**)&DAT_004dd9cc);
    InventoryTable* table = *(InventoryTable**)inventory;
    Caster caster;
    U64 id = FUN_002672f0(name, 0, 0);
    Drawable* drawable = table->slot3(inventory, 0, &caster, (unsigned)id, (unsigned)(id >> 32));
    result->value = drawable->slot11();
    U64 other = FUN_0027b020(aux);
    result->low = (unsigned)other;
    result->high = (unsigned)(other >> 32);
}
} // namespace fn_000f6af0


// 0x000f6b50 FUN_000f6b50 (125 B): equivalent/0x000f6b50.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: _FUN_000f6b50 @9db34dbdd1fa @w30341d90192d
namespace fn_000f6b50 {
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 0/0)
// FUN_000f6b50 @ 0x000f6b50
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

typedef unsigned __int64 Key_f6b50;

namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
namespace pure3d { class CompositeDrawable_f6b50; }

struct Frag;

struct Sub_f6b50 {
    Frag* FUN_002843a0(Key_f6b50 key);
};

struct Loaded_f6b50 {
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
    virtual void l8();
    virtual void l9();
    virtual void l10();
    virtual Sub_f6b50* l11();
};

struct Inventory_f6b50 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_f6b50* find(void* caster, Key_f6b50 key);
};

extern "C" void FUN_000f6b50(const char* nameA, const char* nameB, int value)
{
    Inventory_f6b50* inv = (*(Inventory_f6b50**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_f6b50> caster;
    Loaded_f6b50* loaded = inv->find(&caster, FUN_002672f0(nameA, 0, 0));
    loaded->l0();
    Sub_f6b50* sub = loaded->l11();
    Frag* frag = sub->FUN_002843a0(FUN_002672f0(nameB, 0, 0));
    ((owners::Obj_2848b0 *)(loaded->l11()))->FUN_002848b0((hulk_intptr)(Frag *)frag, 0, (int *)(hulk_uintptr)(int)value);
    loaded->l1();
}
} // namespace fn_000f6b50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f6bd0 FUN_000f6bd0 (219 B): equivalent/0x000f6bd0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: _FUN_000f6bd0 @2f7504affbed @w517552af2f06
namespace fn_000f6bd0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000f6bd0 @ 0x000f6bd0
// Look up a drawable in the inventory by name, find the entry named `joint` in its table
// and hand the entry's value to FUN_000f69e0.
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



extern "C++" __declspec(nothrow) void __cdecl FUN_000f69e0(void *, void *);

namespace pure3d { class CompositeDrawable; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Entry_f6bd0 {
    int pad0;
    int key;                        // 4
    int value;                      // 8
};

struct Table_f6bd0 {
    char pad[0x3c];
    Entry_f6bd0 *begin;                   // 0x3c
    Entry_f6bd0 *end;                     // 0x40

    unsigned char size() const { return (unsigned char)(end - begin); }
    Entry_f6bd0 &at(unsigned char i) const { return begin[i]; }
};

struct Finder_f6bd0 {
    unsigned int FUN_0027b200(int lo, int hi);
};

struct Info_f6bd0 {
    char pad[8];
    Finder_f6bd0 *finder;                 // 8
};

class Loaded_f6bd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual Info_f6bd0 *GetInfo();        // slot 11
    char pad04[0x44 - 4];
    Table_f6bd0 *table;                   // 0x44
};

class Inventory_f6bd0 {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_f6bd0 *find(void *caster, unsigned __int64 key);   // slot 3
};

extern "C" void FUN_000f6bd0(const char *name, const char *joint, int arg)
{
    struct Frame {
        int result;
        int caster;
    } fr;
    fr.result = 0;
    new (&fr.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>();
    Inventory_f6bd0 *inv = (*(Inventory_f6bd0**)&DAT_004dd9cc);
    Loaded_f6bd0 *loaded = inv->find(&fr.caster, FUN_002672f0(name, 0, 0));
    loaded->v0();
    Finder_f6bd0 *finder = loaded->GetInfo()->finder;
    unsigned __int64 key = FUN_0027b020(joint);
    unsigned int id = finder->FUN_0027b200((int)key, (int)(key >> 32));
    Table_f6bd0 *t = loaded->table;
    for (int i = 0; i < t->size(); i++) {
        if (t->at(i).key == (int)id) {
            fr.result = t->at(i).value;
            break;
        }
    }
    FUN_000f69e0((void *)(hulk_uintptr)(int)(fr.result), (void *)(hulk_uintptr)(int)arg);
    loaded->v1();
}
} // namespace fn_000f6bd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000f6e90 FUN_000f6e90 (43 B): matches/0x000f6e90.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4S_f6e90@fn_000f6e90@@QAEAAU01@ABU01@@Z
namespace fn_000f6e90 {
struct S_f6e90 {
    unsigned int a[6];
    S_f6e90& operator=(const S_f6e90& src);
};
S_f6e90& S_f6e90::operator=(const S_f6e90& src) {
    a[0] = src.a[0];
    a[1] = src.a[1];
    a[2] = src.a[2];
    a[3] = src.a[3];
    a[4] = src.a[4];
    a[5] = src.a[5];
    return *this;
}
} // namespace fn_000f6e90

namespace fn_f5892d97 {

// 0x000f6ef0 FUN_000f6ef0 (103 B): matches/0x000f6ef0.cpp
// sym: ??0X_f6ef0@fn_f5892d97@@QAE@XZ
// data: g_one_f6ef0 = DAT_004a1734
X_f6ef0::X_f6ef0() {
    int one = DAT_004a1734;
    w[0x22] = 0;
    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    w[3] = 0;
    w[0x47] = 0;
    w[4] = 0;
    w[6] = 0;
    w[7] = 0;
    w[8] = 0;
    w[5] = 0;
    *(char*)&w[0x23] = 0;
    w[0x43] = 0;
    *(char*)&w[0x44] = 0;
    w[0x45] = 0;
    w[0x46] = one;
    w[9] = 0;
    w[10] = 0;
    w[11] = 0;
    w[12] = 0;
    w[13] = 0;
    w[14] = 0;
    w[15] = 0;
    w[16] = 0;
}


// 0x000f6f60 FUN_000f6f60 (121 B): matches/0x000f6f60.cpp
// sym: ?Clear@Owner_f6f60@fn_f5892d97@@QAEXXZ
void Owner_f6f60::Clear() {
    if (p0)
        R0_0008d340(p0);
    if (p11c)
        R1_0008d330(p11c);
    if (pC)
        R2_0008d340(pC);
    if (p18)
        R3_0008d340(p18);
    for (int i = 0; i < count; ++i) {
        Item_f6f60* q = items[i];
        if (q) {
            q->B();
            items[i] = 0;
        }
    }
}

} // namespace fn_f5892d97

// 0x000f6fe0 FUN_000f6fe0 (13 B): matches/0x000f6fe0.cpp
// sym: ?FUN_000f6fe0@C_f6fe0@owners@@QAEXH@Z
void owners::C_f6fe0::FUN_000f6fe0(int x) {
    value = x;
}

namespace fn_f5892d97 {

// 0x000f6ff0 FUN_000f6ff0 (83 B): matches/0x000f6ff0.cpp
// sym: ?Reserve@Buffer_f6ff0@fn_f5892d97@@QAEXH@Z
void Buffer_f6ff0::Reserve(int n) {
    if (n > capacity) {
        void* old = data;
        void* fresh = allocbuf_0008d6d0(n * 2);
        data = fresh;
        if (old) {
            memcpy(fresh, old, size * 2);
            freebuf(old);
        }
        capacity = n;
    }
}

} // namespace fn_f5892d97

// 0x000f7050 FUN_000f7050 (13 B): matches/0x000f7050.cpp
// sym: ?FUN_000f7050@C_f7050@owners@@QAEXH@Z
void owners::C_f7050::FUN_000f7050(hulk_intptr value) {
    field = ((int)value);
}

namespace fn_f5892d97 {

// 0x000f7080 FUN_000f7080 (139 B): equivalent/0x000f7080.cpp
// sym: ?FUN_000f7080@fn_f5892d97@@YGPAGTBufferSlot@1@HPAVStream@1@@Z @86139628d5d0 @wce7355370a19
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// FUN_000f7080 @ 0x000f7080
// Read one line of UTF-16 text (up to and including '\n') from a stream into a buffer of `count` characters.
// Returns the buffer, or null when nothing was read.
unsigned short* __stdcall FUN_000f7080(BufferSlot slot, int count, Stream* stream)
{
    unsigned short* buffer = slot.buffer;
    int n = 0;
    if (count > 0) {
        do {
            unsigned int pos = stream->FUN_00263fc0();
            if (pos >= stream->FUN_00263fb0()) {
                break;
            }
            ((owners::X_2647e0 *)stream)->FUN_002647e0((hulk_intptr)(&slot.ch), (hulk_intptr)1, 2, (hulk_intptr)1);
            unsigned short c = slot.ch;
            buffer[n++] = c;
            if (c == 0xa) {
                break;
            }
        } while (n < count);
    }
    if (n < count) {
        buffer[n] = 0;
    } else {
        buffer[count - 1] = 0;
    }
    return n > 0 ? buffer : 0;
}


// 0x000f7110 FUN_000f7110 (9 B): matches/0x000f7110.cpp
// sym: ?FUN_000f7110@fn_f5892d97@@YIXPAVThing_f7110@1@@Z
void __fastcall FUN_000f7110(Thing_f7110* self) {
    self->a = 0;
    self->b = 0;
}


// 0x000f7120 FUN_000f7120 (32 B): matches/0x000f7120.cpp
// sym: _FUN_000f7120
hulk_intptr __cdecl FUN_000f7120(int key) {
    int i = 0;
    do {
        if (((int*)&DAT_0040cc74)[i * 2] == key) {
            return ((int*)&DAT_0040cc78)[i * 2];
        }
        i = i + 1;
    } while (i < 6);
    return 0;
}

} // namespace fn_f5892d97

// 0x000f7220 FUN_000f7220 (27 B): matches/0x000f7220.cpp
// sym: ?FUN_000f7220@C_f7220@owners@@QAEHH@Z
hulk_intptr owners::C_f7220::FUN_000f7220(hulk_intptr index) {
    if (((int)index) < 0 || ((int)index) > max)
        return 0;
    return items[((int)index)];
}

namespace fn_f5892d97 {

// 0x000f7240 FUN_000f7240 (117 B): matches/0x000f7240.cpp
// sym: ?FUN_000f7240@KeyTable_f7240@fn_f5892d97@@QAEHII@Z
// FUN_000f7240 @ 0x000f7240
// Finds a key in the table, preferring the platform-hashed variant ("_XBOX") over the plain key.
int KeyTable_f7240::FUN_000f7240(unsigned int lo, unsigned int hi)
{
    union {
        unsigned __int64 q;
        unsigned int w[2];
    } platform;
    int found = -1;
    platform.q = FUN_002672f0("_XBOX", lo, hi);
    int n = count;
    for (int i = 0; i < n; i++) {
        unsigned int elo = entries[i].lo;
        unsigned int ehi = entries[i].hi;
        if (platform.w[0] == elo && platform.w[1] == ehi)
            return i;
        if (lo == elo && hi == ehi)
            found = i;
    }
    return found;
}

} // namespace fn_f5892d97

// 0x000f72c0 FUN_000f72c0 (17 B): matches/0x000f72c0.cpp
// sym: ?FUN_000f72c0@Obj_f72c0@owners@@QAE_KH@Z
unsigned long long owners::Obj_f72c0::FUN_000f72c0(int index) {
    return ((unsigned long long*)data)[index];
}

namespace fn_f5892d97 {

// 0x000f72e0 FUN_000f72e0 (77 B): equivalent/0x000f72e0.cpp
// sym: _FUN_000f72e0 @52c1a53f22b5 @w992d2ac7eaae
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000f72e0 @ 0x000f72e0
// equiv-conv: FUN_000f72e0 eax ebx
extern "C" unsigned short *FUN_000f72e0(unsigned short *text, const char *pattern)
{
    while (*text != 0) {
        const char *candidate = pattern;
        const unsigned short *wide = text;
        while (*candidate != 0 && *wide != 0 && (int)(signed char)*candidate == (unsigned int)*wide) {
            ++candidate;
            ++wide;
        }
        if (*candidate == 0)
            return text;
        ++text;
    }
    return 0;
}


// 0x000f76c0 FUN_000f76c0 (85 B): matches/0x000f76c0.cpp
// sym: ?FUN_000f76c0@fn_f5892d97@@YGHPAF@Z
int __stdcall FUN_000f76c0(short* p) {
    short* q = p;
    if (*q == 0)
        return 0;
    do {
        q++;
    } while (*q != 0);
    if (q == p)
        return 0;
    q--;
    while (q >= p && (*q == 10 || *q == 13)) {
        *q = 0;
        q--;
    }
    return (int)((char*)q - (char*)p + 2) >> 1;
}


// 0x000f7790 FUN_000f7790 (119 B): equivalent/0x000f7790.cpp
// sym: ?FUN_000f7790@fn_f5892d97@@YGHPAG@Z @c1dc1af921b8 @web95929f6ec3
// STATUS: equivalent (tools/equiv.py level 3: 316 inputs, branch coverage 14/14)
// FUN_000f7790 @ 0x000f7790
// Unescapes \b \n \s (zero width space) in place, returns the new length.
int __stdcall FUN_000f7790(unsigned short* text) {
    unsigned short* dst = text;
    unsigned short* src = text;
    int count = 0;
    if (*src != 0) {
        do {
            unsigned short c = *src;
            if (c == '\\') {
                src++;
                c = *src;
                if (c == 0) {
                    *dst++ = '\\';
                    count++;
                    break;
                }
                if (c == 'b')
                    c = 8;
                else if (c == 'n')
                    c = 10;
                else if (c == 's')
                    c = 0x200b;
            }
            *dst++ = c;
            src++;
            count++;
        } while (*src != 0);
    }
    *dst = 0;
    return count;
}


// 0x000f7810 FUN_000f7810 (42 B): matches/0x000f7810.cpp
// sym: _FUN_000f7810
extern "C" void FUN_000f7810(const ushort_f7810* src, uchar_f7810* dst) {
    if (*src != 0) {
        do {
            *dst = (uchar_f7810)*src;
            ++src;
            ++dst;
        } while (*src != 0);
    }
    *dst = 0;
}


// 0x000f7850 FUN_000f7850 (55 B): matches/0x000f7850.cpp
// sym: ?Cleanup@Owner_f7850@fn_f5892d97@@QAEXXZ
void Owner_f7850::Cleanup() {
    int i = 0;
    if (count > 0) {
        Item_f7850** p = items;
        do {
            if (*p != 0) {
                (*p)->Release();
                *p = 0;
            }
            ++i;
            ++p;
        } while (i < count);
    }
}


// 0x000f78e0 FUN_000f78e0 (1 B): matches/0x000f78e0.cpp
// sym: _FUN_000f78e0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_000f78e0() {}

} // namespace fn_f5892d97

// 0x000f78f0 FUN_000f78f0 (50 B): matches/0x000f78f0.cpp
// sym: ?FUN_000f78f0@X_f78f0@owners@@QAEXXZ
void owners::X_f78f0::FUN_000f78f0() {
    if (count < 7) {
        Item_f78f0* p = (Item_f78f0*)((char*)this + count * 16);
        Item_f78f0* q = (Item_f78f0*)((char*)p + 16);
        *q = *p;
        ++count;
    }
}


// 0x000f7930 FUN_000f7930 (46 B): equivalent/0x000f7930.cpp
// sym: ?FUN_000f7930@State_f7930@owners@@QAEPAU12@XZ @6a2de3ac06c9 @w7e2d34cb2a08
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000f7930 @ 0x000f7930
owners::State_f7930* owners::State_f7930::FUN_000f7930() {
    scale = (*(float*)&DAT_004a1734);
    field10 = 0;
    field14 = -1;
    value = 0;
    flag = false;
    fieldC = 0;
    field20 = -1;
    amount = 20.0f;
    flag18 = false;
    return this;
}


// 0x000f7960 FUN_000f7960 (51 B): matches/0x000f7960.cpp
// sym: ?FUN_000f7960@Thing_f7960@owners@@QAEXXZ
void owners::Thing_f7960::FUN_000f7960() {
    if (mFirst) {
        ReleaseThing_0008d340(mFirst);
        mFirst = 0;
    }
    if (mSecond) {
        ReleaseThing_0008d340(mSecond);
        mSecond = 0;
    }
}


// 0x000f79a0 FUN_000f79a0 (101 B): matches/0x000f79a0.cpp
// sym: ?FUN_000f79a0@Obj_f79a0@owners@@QAEXPBFH@Z
void owners::Obj_f79a0::FUN_000f79a0(const short* text, hulk_intptr unused) {
    mState = -1;
    if (mData != 0) {
        thunk_FUN_00267090((hulk_intptr)mData);
        mData = 0;
    }
    if (text != 0) {
        int n = 0;
        while (text[n] != 0)
            ++n;
        mData = FUN_0008d6d0(n * 2 + 2);
        if (mData == 0)
            return;
        FUN_000fb690(mData, text, n + 1);
    }
    mOther = -1;
}


// 0x000f7a10 FUN_000f7a10 (62 B): matches/0x000f7a10.cpp
// sym: ?FUN_000f7a10@Obj_f7a10@owners@@QAEXHH@Z
void owners::Obj_f7a10::FUN_000f7a10(hulk_intptr value, int unused) {
    if (m10) {
        release_0008d340(m10);
        m10 = 0;
        m14 = ((int)value);
        m20 = -1;
    } else {
        m14 = ((int)value);
        m20 = -1;
    }
}

namespace fn_f5892d97 {

// 0x000f7ce0 FUN_000f7ce0 (71 B): matches/0x000f7ce0.cpp
// sym: ?Clear@Obj_f7ce0@fn_f5892d97@@QAEXXZ
void Obj_f7ce0::Clear() {
    int i = 0;
    if (count > 0) {
        Item_f7ce0** p = items;
        do {
            if (*p) {
                (*p)->Release();
                *p = 0;
            }
            *p = 0;
            ++i;
            ++p;
        } while (i < count);
    }
    count = 0;
}


// 0x000f7d60 FUN_000f7d60 (502 B): equivalent/0x000f7d60.cpp
// sym: ?FUN_000f7d60@TextBox_f7d60@fn_f5892d97@@QAEXPBGHMHHPAVCallback_f7d60@2@@Z @0530ad078c73 @w4151bc8fe8a6
// STATUS: equivalent (tools/equiv.py level 3: 3052 inputs, branch coverage 20/20)
// FUN_000f7d60 @ 0x000f7d60
void TextBox_f7d60::FUN_000f7d60(const unsigned short* text, int index, float scale, int align, int mode, Callback_f7d60* cb) {
    if (text == 0 || *text == 0)
        return;
    FUN_000fb690(((unsigned short*)&DAT_004de9b0), text, 0x1000);
    (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
    volatile float scaled = 14.0f * scale;
    volatile float ratio = scaled / sub[0]->v7();
    volatile float diff = ratio - 1.0f;
    float mag = diff;
    if (mag < 0.0f)
        mag = -mag;
    if (!(mag <= 1e-05f))
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(ratio, ratio, 1.0f);
    Metrics_f7d60* m = sub[index];
    volatile float top = m->v7();
    volatile float f = top - m->v8();
    if (mode == 1) {
        f = f - sub[index]->v7();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, f, 0.0f);
    } else if (mode == 2) {
        Metrics_f7d60* o = sub[index];
        volatile float t = o->v9(((unsigned short*)&DAT_004de9b0)) * 0.5f + f;
        f = t - o->v7();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, f, 0.0f);
    } else if (mode == 3) {
        Metrics_f7d60* o = sub[index];
        volatile float t = o->v9(((unsigned short*)&DAT_004de9b0)) + f;
        f = t - o->v7();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, f, 0.0f);
    }
    unsigned short* line = ((unsigned short*)&DAT_004de9b0);
    for (;;) {
        bool last = false;
        unsigned short* p = line;
        if (*p == 0) {
            last = true;
        } else {
            for (;;) {
                if (*p == 10) {
                    *p = 0;
                    break;
                }
                p++;
                if (*p == 0) {
                    last = true;
                    break;
                }
            }
        }
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        FUN_000f7330(line, index, scale, align, cb);
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
        if (last)
            break;
        line = p + 1;
        Metrics_f7d60* o = sub[index];
        volatile float t = -o->v7();
        float y = t - o->v12();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, y, 0.0f);
    }
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
}


// 0x000f7fe0 FUN_000f7fe0 (143 B): equivalent/0x000f7fe0.cpp
// sym: ?FUN_000f7fe0@Blender_f7fe0@fn_f5892d97@@QAEPAU12@PAUOwner_f7fe0@2@@Z @09a84d839c4a @w78c06bd306c0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000f7fe0 @ 0x000f7fe0
Blender_f7fe0* Blender_f7fe0::FUN_000f7fe0(Owner_f7fe0* o) {
    int v;
    index = 0;
    owner = o;
    slots[index].weight = 1.0f;
    slots[index].a = 0;
    slots[index].b = 1;
    int i = index;
    if (owner->inner) owner->inner->GetValue(&v); else v = -1;
    slots[i].value = v;
    current = v;
    scale = (*(float*)&DAT_004a1734);
    return this;
}

} // namespace fn_f5892d97

// 0x000f80e0 FUN_000f80e0 (202 B): equivalent/0x000f80e0.cpp [wrapped: conflict: Object]
// sym: ?FUN_000f80e0@Object@fn_000f80e0@@QAEXHHH@Z @f1ff3429580c @w2da91ace4333
namespace fn_000f80e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_000f80e0 @ 0x000f80e0
struct State_f80e0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void Get(int*); virtual void Set(int);
};
struct Context {
 char pad[0x24]; State_f80e0* states[61];
 int mode;
};
struct Entry_f80e0 { int a,b,c,state; };
struct Object {
 Context* context;
 int unused;
 Entry_f80e0 entries[8];
 int index;
 int mode;
 void FUN_000f80e0(hulk_intptr a,int slot,int c);
};
void Object::FUN_000f80e0(hulk_intptr a,int slot,int c) {
 int oldState;
 if(context->states[slot]) context->states[slot]->Get(&oldState); else oldState=-1;
 int newState=entries[index].state;
 if(context->states[slot]) context->states[slot]->Set(newState);
 int oldMode=context->mode;
 context->mode=mode;
 ((owners::Printer_f7f60 *)context)->FUN_000f7f60(a, slot, entries[index].a, entries[index].b, entries[index].c, c);
 if(context->states[slot]) context->states[slot]->Set(oldState);
 context->mode=oldMode;
}
} // namespace fn_000f80e0


// 0x000f81b0 FUN_000f81b0 (202 B): equivalent/0x000f81b0.cpp [wrapped: conflict: Context]
// sym: ?target@Context@fn_000f81b0@@QAEIIII@Z @78f4dbea0da1 @wb04273eaae3a
namespace fn_000f81b0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_000f81b0 @ 0x000f81b0
struct Slot_f81b0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13();
 virtual void getValue(unsigned* value);
 virtual void setValue(unsigned value);
};
struct Owner_f81b0 {
 char pad[0x24];
 Slot_f81b0* slots[61];
 unsigned state;
 void FUN_000f7d60(unsigned a, unsigned index, unsigned x, unsigned y, unsigned z, unsigned b);
};
struct Row_f81b0 { unsigned x,y,z,value; };
struct Context {
 Owner_f81b0* owner;
 unsigned unused;
 Row_f81b0 rows[8];
 unsigned current;
 unsigned state;
 unsigned target(unsigned a, unsigned index, unsigned b);
};
unsigned Context::target(unsigned a, unsigned index, unsigned b) {
 unsigned slotIndex = index;
 Slot_f81b0* slot = owner->slots[slotIndex];
 if(slot) slot->getValue(&index); else index = 0xffffffff;
 unsigned value = rows[current].value;
 slot = owner->slots[slotIndex];
 if(slot) slot->setValue(value);
 unsigned savedState = owner->state;
 owner->state = state;
 owner->FUN_000f7d60(a, slotIndex, rows[current].x, rows[current].y, rows[current].z, b);
 slot = owner->slots[slotIndex];
 if(slot) slot->setValue(index);
 owner->state = savedState;
 return savedState;
}
} // namespace fn_000f81b0


// 0x000f8280 FUN_000f8280 (305 B): equivalent/0x000f8280.cpp [wrapped: conflict: DAT_004de948]
// sym: ?FUN_000f8280@Gradient@fn_000f8280@@QAEXIII@Z @e9bb0aad436f @wf65f1fac93c6
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

// 0x000f83c0 FUN_000f83c0 (43 B): matches/0x000f83c0.cpp
// sym: ?Copy@fn_f5892d97@@YIPAVObj_f83c0@1@PAV21@PAX0@Z
Obj_f83c0* __fastcall Copy(Obj_f83c0* self, void*, Obj_f83c0* src) {
    ((owners::Obj_f79a0 *)(((ThisCall_000f79a0*)(self))))->FUN_000f79a0((const short *)(hulk_uintptr)(int)(src->initArg), (hulk_intptr)0);
    self->field14 = src->field14;
    *(int*)self = *(int*)src;
    self->field20 = -1;
    return self;
}

} // namespace fn_f5892d97

// 0x000f83f0 FUN_000f83f0 (269 B): equivalent/0x000f83f0.cpp [wrapped: conflict: Context; Object]
// sym: ?target@Object@fn_000f83f0@@QAEPAXPAUContext@2@PAUParameters_f83f0@2@@Z @524c631d59b9 @w3bb685576642
namespace fn_000f83f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000f83f0 @ 0x000f83f0
struct RateProvider { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); };
struct Context { char pad0[12]; void** entries; int maxIndex; char pad14[16]; RateProvider* providers[58]; int version; };
struct Frame_f83f0 { float unused0, unused1, scale, unused3; };
struct Parameters_f83f0 { Frame_f83f0 frames[8]; char pad80[8]; int frameIndex; };
void __cdecl FUN_0008d340(void*);
extern "C" unsigned int __cdecl FUN_00294b80(void*);
void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void __cdecl FUN_000fb830(void*, unsigned int, void*, float, RateProvider*);
struct Object { int providerIndex; char pad4[8]; void* cache; void* source; int sourceIndex; unsigned char enabled; char pad19[3]; float value; int version; void* target(Context*, Parameters_f83f0*); };
void* Object::target(Context* context, Parameters_f83f0* parameters) {
 void* input = source;
 if (!input) {
  if (sourceIndex < 0 || sourceIndex > context->maxIndex) return 0;
  input = context->entries[sourceIndex];
  if (!input) return 0;
 }
 if (!enabled) return input;
 int currentVersion = context->version;
 if (version != -1 && version == currentVersion) return cache;
 float rate = context->providers[0]->slot7();
 float factor = value / ((14.0f / rate) * parameters->frames[parameters->frameIndex].scale);
 if (cache) { FUN_0008d340(cache); cache = 0; }
 unsigned int length = FUN_00294b80(input);
 unsigned int size = (length + 5 - (int)((double)length * -0.2f)) * 2;
 cache = FUN_0008d6d0(size);
 if (!cache) return 0;
 FUN_000fb830(cache, size, input, factor, context->providers[providerIndex]);
 version = currentVersion;
 return cache;
}
} // namespace fn_000f83f0

