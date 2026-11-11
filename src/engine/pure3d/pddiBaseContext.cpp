// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0031c290..0x0031ffc0 (kind game, layer engine, confidence high), dominant class pure3d::pddiBaseContext
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/pure3d/scenegraph.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fc049dac {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fc049dac {} using namespace fn_fc049dac;
#include "engine/pure3d.h"
// (x64t2) the context's current states (f_48 view, f_4c render, f_50 lighting, f_54 fog, f_58 stencil) from any view of
// the context, in gen's layout; and byte K (a 32-bit offset) of a state record: its vftable pointer first, then 32-bit
// words, so on 64-bit everything behind the vftable sits 4 bytes further on
#define HULK_CTX_STATE(self, f) (*(char**)&((::pure3d::pddiBaseContext*)(void*)(self))->f)
#define HULK_STATE_AT(p, k) ((char*)(p) + (int)(sizeof(void*) - 4) + (k))

// ---- declarations shared by the functions below
namespace fn_fc049dac {
struct FormatInfo {
 char reserved[16];
 unsigned int type;
 unsigned char direct;
 char pad[3];
 unsigned int redStart, greenStart, blueStart, alphaStart;
 unsigned int redShift, greenShift, blueShift, alphaShift;
 unsigned int redMask, greenMask, blueMask, alphaMask;
};
struct FormatDesc_31c570 {
    int format;
    char pad04[0x10];
    int width;
    int height;
};
struct Surface_31c570 {
    int pitch;
    int bits;
};
struct LevelDesc_31c570 {
    int width;
    int height;
    int bytesPerPixel;
    int depth;
    char pad10[0x38];
    int stride;
    int slicePitch;
    int bits;
};
extern "C" int FUN_0031c180(int format);
extern "C" void __cdecl FUN_0031c290(unsigned int, void *);
struct FormatDesc_31c600 {
    int format;
    char pad04[0xc];
    int width;
    int height;
    int depth;
};
struct Surface_31c600 {
    int pitch;
    int slicePitch;
    int bits;
};
struct LevelDesc_31c600 {
    int width;
    int height;
    int bytesPerPixel;
    int depth;
    char pad10[0x38];
    int stride;
    int slicePitch;
    int bits;
};
extern void* pddiObject_31c780_vftable[];
class pddiObject_31c780 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class pddiRenderContext_31c780 : public pddiObject_31c780 {
  public:
    pddiRenderContext_31c780* vfunc_5(signed char flags);
};
typedef unsigned int U32_31c880;
struct Obj_31c880 {
    char pad[8];
    hulk_uintptr index;
    hulk_uintptr base;
    void Copy(U32_31c880);
};
struct Temp_31c880 {
};
} // namespace fn_fc049dac
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fc049dac {
struct Context_31c8c0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47(); virtual void slot48(); virtual void slot49();
 virtual void slot50(); virtual void slot51(); virtual void slot52(); virtual void slot53();
 virtual void set54(unsigned int); virtual void slot55();
 virtual void set56(unsigned int,unsigned int,unsigned int,unsigned int); virtual void slot57();
 virtual void set58(unsigned int); virtual void slot59();
 virtual void set60(unsigned int); virtual void slot61();
 virtual void set62(unsigned int); virtual void slot63();
 virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67(); virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71(); virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
 virtual void set76(unsigned int);
};
} // namespace fn_fc049dac
namespace pure3d {
struct pddiState_31c8c0 { virtual void vfunc_0(Context_31c8c0*); };
}
namespace fn_fc049dac {
class View_31c940 {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void A(int);
    virtual void x7();
    virtual void B(int);
    virtual void x9();
    virtual void C(int);
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void x20();
    virtual void x21();
    virtual void x22();
    virtual void x23();
    virtual void D(int);
    virtual void xx();
    virtual void E(int, int, int, int);
    virtual void xxx();
    virtual void F(int, int, int, int);
};
class Device_31ca70 {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void f78(unsigned char);
    virtual void f79();
    virtual void f80(int, int, int);
};
class Dev_31cab0 {
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
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void s0(unsigned char);
    virtual void x1();
    virtual void s1(int);
    virtual void x2();
    virtual void s2(int);
    virtual void x3();
    virtual void s3(int);
    virtual void x4();
    virtual void s4(int);
    virtual void x5();
    virtual void s5(int, int, int);
};
extern "C" char DAT_004325f4[];
class pddiRenderContext_31cb20 {
  public:
    hulk_intptr vptr;
    void Init();
    pddiRenderContext_31cb20();
};
extern void FUN_00328260();
extern void thunk_FUN_00267090(CCollisionAction*);
} // namespace fn_fc049dac
namespace pure3d {
struct State {
    int a;
    int value;
};
}
namespace pure3d {
struct S_31d530 {
    char pad[0xc];
    void* value;
};
}
namespace pure3d {
class pddiObject_31d6c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
}
namespace pure3d {
class pddiRenderContext_31d6c0 : public pddiObject_31d6c0 {};
}
namespace pure3d {
struct Block_31d6c0 {
    unsigned long x[16];
};
}
namespace fn_fc049dac {
class ParamValue_31d900 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class pddiBaseContext {
  public:
    void vfunc_35(int);
};
} // namespace fn_fc049dac
namespace pure3d {
struct LightState_31db00 {
 char reserved[0x44];
 float red, green, blue;
 char reserved50[4];
 float average;
 char reserved58[0x20];
 unsigned color;
};
}
namespace pure3d {
struct TextureStage {
    char reserved[0x78];
    unsigned int value;
};
}
namespace fn_fc049dac {
struct Vec3_31dbd0 {
    float x, y, z;
};
struct Light_31dbd0 {
    int unused0;
    Vec3_31dbd0 pos;
    float w;
    char rest[0x7c - 0x14];
};
struct V {
    int x, y, z;
};
} // namespace fn_fc049dac
namespace pure3d {
struct Vec3_31dc90 {
    float x, y, z;
};
}
namespace pure3d {
struct Vec4_31dc90 {
    float x, y, z, w;
};
}
namespace pure3d {
struct LightState_31dc90 {
    char pad00[0x24];
    Vec4_31dc90 direction;
    char pad34[0x7c - 0x34];
};
}
namespace fn_fc049dac {
class pddiRenderContext_31ddf0 {
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
    virtual void f51(int, unsigned*, unsigned*, unsigned*);
};
struct Rec_31ddf0 {
    char pad[0x5c];
    unsigned x, y, z;
    char tail[0x14];
};
} // namespace fn_fc049dac
namespace pure3d {
struct Inner_31e0f0 {
    char pad[0x14];
    int value;
};
}
namespace fn_fc049dac {
class Thing_31e1f0 {
  public:
    virtual void Call(int, int);
};
struct Obj_31e210 {
    virtual void f0();
    virtual void f1(int);
};
typedef unsigned int u32_31e230;
extern void* stackVftable;
class pddiStack_31e330 {
  public:
    void* vptr;
    char pad[8];
    int value;
    void f();
};
struct pddiStack {
    virtual pddiStack* vfunc_0(unsigned char);
    char pad[8];
    void* field_c;
};
extern int stack_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
class Obj_31e490 {
  public:
    Obj_31e490* Get();
};
extern void* g_a_31e500[];
extern void* g_b_31e500[];
} // namespace fn_fc049dac
void operator delete(void*);
namespace fn_fc049dac {
class Ref_31e500 {
  public:
    virtual void F0();
    virtual void Release();
};
class Item_31e500 {
  public:
    virtual ~Item_31e500();
};
class Big_31e500 {
  public:
    void Fin();
};
class pddiRenderContext_31e500 {
  public:
    void* vptr;
    void Fin();
};
class pddiBaseContext_31e500 : public pddiRenderContext_31e500 {
  public:
    char pad[4];
    Ref_31e500* m8;
    Ref_31e500* mc;
    Ref_31e500* m10;
    char pad2[0xc];
    Item_31e500* arr[5];
    Item_31e500* m34;
    Item_31e500* m38;
    Item_31e500* m3c;
    Item_31e500* m40;
    Item_31e500* m44;
    char pad3[0x144 - 0x48];
    Big_31e500* m144;
    void f();
};
class pddiRenderContext_31e5f0 {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
}
namespace fight {
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
}
class pddiBaseContext_31e5f0 : public pddiRenderContext_31e5f0, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
struct Mat_31e930 {
    int m[16];
};
struct Stk {
    int p0, p4;
    int top;
    Mat_31e930* data;
};
class pddiBaseContext_31e930 {
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
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void Upd(int w);
    virtual void f109();
    virtual void f110();
    char pad[0x1c];
    Stk* stk[4];
    void Push(int w, void* a);
};
struct Stack_31e9b0 {
    void* vftable;  // a pddiStack<state> (0x0031ed40...): vftable, capacity, depth, items
    int capacity;
    int top;
    char* data;
};
struct StateBase {
    virtual void Restore(void* ctx);
};
typedef unsigned int u32_31ed10;
void* __cdecl FUN_0008d690(unsigned int);
} // namespace fn_fc049dac
// the five state records of the context's stacks (the states' vftable first): StateA_31f290 a pddiRenderState
// (0x1c bytes on 32-bit), StateB_31f290 a pddiViewState (0x34), StateC a pddiLightingState (0x3ec), StateD a
// pddiFogState (20), StateE a pddiStencilState (36); their constructors 0x0031ee00, 0x0031ed40, 0x0031eef0,
// 0x0031efd0, 0x0031f0a0 build the same layouts
namespace pure3d {
struct StateA_31f290 {
    void* vftable;
    int a4;
    char c8;
    int ac;
    char c10;
    int d14;
    char c18;
    char c19;
    char c1a;
    char c1b;
};
}
namespace pure3d {
struct StateB_31f290 {
    void* vftable;
    char data[0x30];
    void FUN_0031eab0(const StateB_31f290* prev);
};
}
namespace pure3d {
struct StateC {
    void* vftable;
    char data[0x3e8];
    void FUN_0031eb70(const StateC* prev);
};
}
namespace pure3d {
struct StateD {
    void* vftable;
    char c4;
    int a8;
    int ac;
    int a10;
};
}
namespace pure3d {
struct StateE {
    void* vftable;
    char c4;
    int a8;
    int ac;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
};
}
namespace pure3d {
template <class T>
struct StateStack_31f290 {
    void* field_00;  // the vftable (a pddiStack<T>: 0x0031ed40...)
    int field_04;    // the capacity
    int top;
    T* items;
};
}

namespace fn_fc049dac {
// the pddiStack<T> objects (0x0031ed40...0x0031f0a0 construct them): vftable, capacity, depth, items
struct StackA { void* vftable; int capacity; unsigned int index; pure3d::StateB_31f290* data; StackA* FUN_0031ed40(int); };
struct StackB { void* vftable; int capacity; unsigned int index; pure3d::StateA_31f290* data; StackB* FUN_0031ee00(int); };
struct StackC { void* vftable; int capacity; unsigned int index; pure3d::StateC* data; StackC* FUN_0031eef0(int); };
struct StackD { void* vftable; int capacity; unsigned int index; pure3d::StateD* data; StackD* FUN_0031efd0(int); };
struct StackE { void* vftable; int capacity; unsigned int index; pure3d::StateE* data; StackE* FUN_0031f0a0(int); };

// 0x0031c290 FUN_0031c290 (643 B): equivalent/0x0031c290.cpp
// sym: _FUN_0031c290
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 52/54, incomplete)
// FUN_0031c290 @ 0x0031c290
extern "C" void __cdecl FUN_0031c290(unsigned int format, void * out) {
 unsigned int r=0,g=0,b=0,a=0;
 unsigned int index=format-2;
 if(index<=38) switch(index) {
 case 3: case 15: r=0xf800;g=0x7e0;b=0x1f;((FormatInfo *)out)->type=1;break;
 case 0: case 14: a=0x8000;r=0x7c00;g=0x3e0;b=0x1f;((FormatInfo *)out)->type=2;break;
 case 2: case 27: a=0xf000;r=0xf00;g=0xf0;b=0xf;((FormatInfo *)out)->type=4;break;
 case 4: case 28: a=0xff000000;r=0xff0000;g=0xff00;b=0xff;((FormatInfo *)out)->type=6;break;
 case 5: case 16: r=0xff0000;g=0xff00;b=0xff;((FormatInfo *)out)->type=6;break;
 case 1: r=0x7c00;g=0x3e0;b=0x1f;((FormatInfo *)out)->type=3;break;
 case 10: ((FormatInfo *)out)->type=11;break;
 case 12: ((FormatInfo *)out)->type=13;break;
 case 13: ((FormatInfo *)out)->type=15;break;
 case 9: ((FormatInfo *)out)->type=7;break;
 case 38: ((FormatInfo *)out)->type=10;break;
 }
 ((FormatInfo *)out)->redMask=r;((FormatInfo *)out)->greenMask=g;((FormatInfo *)out)->blueMask=b;((FormatInfo *)out)->alphaMask=a;
 unsigned int masks[4];masks[0]=r;masks[1]=g;masks[2]=b;masks[3]=a;
 unsigned int counts[4], starts[4];
 for(int j=0;j<4;++j){counts[j]=0;starts[j]=0;bool found=false;for(unsigned int i=0;i<32;++i){if(masks[j] & (1u<<i)){++counts[j];if(!found){starts[j]=i;found=true;}}}}
 ((FormatInfo *)out)->redShift=24-counts[0];((FormatInfo *)out)->greenShift=16-counts[1];((FormatInfo *)out)->blueShift=8-counts[2];((FormatInfo *)out)->alphaShift=32-counts[3];
 ((FormatInfo *)out)->redStart=starts[0];((FormatInfo *)out)->greenStart=starts[1];((FormatInfo *)out)->blueStart=starts[2];((FormatInfo *)out)->alphaStart=starts[3];
 ((FormatInfo *)out)->direct=(r==0xff0000 && g==0xff00 && b==0xff && a==0xff000000);
}


// 0x0031c570 FUN_0031c570 (134 B): equivalent/0x0031c570.cpp
// sym: _FUN_0031c570
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0031c570 @ 0x0031c570
// Fills a 2D texture-level description from a format descriptor and an optional locked surface.
// equiv-conv: FUN_0031c180 eax
extern "C" void FUN_0031c570(const FormatDesc_31c570 *desc, const Surface_31c570 *surf, LevelDesc_31c570 *out, char flipped)
{
    out->width = desc->width;
    out->height = desc->height;
    out->depth = 1;
    out->bytesPerPixel = FUN_0031c180(desc->format);
    if (surf) {
        int format = desc->format;
        if (flipped && format != 0xc && format != 0xe && format != 0xf) {
            out->bits = (out->height - 1) * surf->pitch + surf->bits;
            out->stride = -surf->pitch;
        } else {
            out->bits = surf->bits;
            out->stride = surf->pitch;
        }
    }
    FUN_0031c290((int)(desc->format), (LevelDesc_31c570 *)out);
}


// 0x0031c600 FUN_0031c600 (121 B): equivalent/0x0031c600.cpp
// sym: _FUN_0031c600
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0031c600 @ 0x0031c600
// Fills a texture-level description from a format descriptor and an optional locked surface.
// equiv-conv: FUN_0031c180 eax
extern "C" void FUN_0031c600(const FormatDesc_31c600 *desc, const Surface_31c600 *surf, LevelDesc_31c600 *out, char flipped)
{
    out->width = desc->width;
    out->height = desc->height;
    out->depth = desc->depth;
    out->bytesPerPixel = FUN_0031c180(desc->format);
    if (surf) {
        int format = desc->format;
        if (flipped && format != 0xc && format != 0xe && format != 0xf) {
            out->bits = (out->height - 1) * surf->pitch + surf->bits;
            out->stride = -surf->pitch;
        } else {
            out->bits = surf->bits;
            out->stride = surf->pitch;
        }
        out->slicePitch = surf->slicePitch;
    }
    FUN_0031c290((int)(desc->format), (LevelDesc_31c600 *)out);
}


// 0x0031c680 FUN_0031c680 (216 B): equivalent/0x0031c680.cpp
// sym: _FUN_0031c680
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 9/10, incomplete)
// FUN_0031c680 @ 0x0031c680
extern "C" unsigned int* __cdecl FUN_0031c680(unsigned int* output, unsigned int first, unsigned int second, int weight)
{
    if (weight <= 0) { *output = first; return output; }
    if (weight >= 255) { *output = second; return output; }
    unsigned int a = 255 - weight;
    unsigned int b = weight;
    unsigned int result = 0;
    for (unsigned int shift = 0; shift < 32; shift += 8) {
        unsigned int channel = (((first >> shift) & 255) * a + ((second >> shift) & 255) * b) >> 8;
        result |= channel << shift;
    }
    *output = result;
    return output;
}


// 0x0031c780 pure3d::pddiRenderContext::vfunc_3 (36 B): matches/0x0031c780.cpp
// sym: ?vfunc_5@pddiRenderContext_31c780@fn_fc049dac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
pddiRenderContext_31c780* pddiRenderContext_31c780::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_31c780_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fc049dac

// 0x0031c7c0 pure3d::pddiExtension::vfunc_0 (31 B): matches/0x0031c7c0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0031c7c0@@UAEPAV123@E@Z
namespace fn_0031c7c0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031c7c0

namespace fn_fc049dac {

// 0x0031c880 FUN_0031c880 (63 B): matches/0x0031c880.cpp
// sym: ?Copy@Obj_31c880@fn_fc049dac@@QAEXI@Z
void Obj_31c880::Copy(U32_31c880 param) {
    char local[64];
    void* dst = (void*)(index * 64 + base);
    ((owners::Matrix_22ca90 *)(((Temp_31c880*)local)))->FUN_0022ca90((const owners::Matrix_22ca90 *)(hulk_uintptr)(unsigned int)param, (const owners::Matrix_22ca90 *)dst);
    dst = (void*)(index * 64 + base);
    memcpy(dst, local, 64);
}

} // namespace fn_fc049dac

// 0x0031c8c0 pure3d::pddiRenderState::vfunc_0 (121 B): equivalent/0x0031c8c0.cpp
// sym: ?vfunc_0@pddiRenderState@pure3d@@UAEXPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiRenderState::vfunc_0 @ 0x0031c8c0
void pure3d::pddiRenderState::vfunc_0(void* __p0) { Context_31c8c0 * context = (Context_31c8c0 *)__p0;

 context->set54((*(unsigned int *)&this->f_04));
 context->set56((*(unsigned char *)&this->f_18),(*(unsigned char *)&this->f_19),(*(unsigned char *)&this->f_1a),(*(unsigned char *)&this->f_1b));
 context->set58((*(unsigned char *)&this->f_08));
 context->set60((*(unsigned int *)&this->f_0c));
 context->set62((*(unsigned char *)&this->f_10));
 context->set76((*(unsigned int *)&this->f_14));
}


// 0x0031c940 pure3d::pddiViewState::vfunc_0 (103 B): matches/0x0031c940.cpp
// sym: ?vfunc_0@pddiViewState@pure3d@@UAEXPAX@Z
void pure3d::pddiViewState::vfunc_0(void* __p0) { void * p = (void *)__p0;

    View_31c940* v = (View_31c940*)p;
    v->A(this->f_04);
    v->B(this->f_08);
    v->C(this->f_0c);
    v->D(this->f_10);
    v->E(this->f_14, this->f_18, this->f_1c, this->f_20);
    v->F(this->f_24, this->f_28, this->f_2c, this->f_30);
}


// 0x0031c9b0 pure3d::pddiLightingState::vfunc_0 (188 B): equivalent/0x0031c9b0.cpp [wrapped: conflict: pure3d::Light; pure3d::pddiLightingState]
// sym: ?vfunc_0@pddiLightingState@pure3d@fn_0031c9b0@@UAEXPAUContext@23@@Z
namespace fn_0031c9b0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::pddiLightingState::vfunc_0 @ 0x0031c9b0
namespace pure3d {
struct Context {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
 virtual void lighting(unsigned); virtual void s36(); virtual void s37(); virtual void enable(int,unsigned); virtual void s39(); virtual void type(int,unsigned); virtual void s41(); virtual void color(int,unsigned); virtual void s43(); virtual void position(int,void*); virtual void s45(); virtual void direction(int,void*); virtual void s47(); virtual void range(int,unsigned); virtual void s49(); virtual void attenuation(int,unsigned,unsigned,unsigned); virtual void s51(); virtual void cone(int,unsigned,unsigned,unsigned);
};
struct Light {
 char position[32]; char direction[52]; unsigned range; unsigned attenuation0,attenuation1,attenuation2; unsigned cone0,cone1,cone2; unsigned type,color; unsigned char enabled; char padding[3];
};
struct pddiLightingState {
 virtual void vfunc_0(Context*);
 Light lights[8]; unsigned lighting;
};
void pddiLightingState::vfunc_0(Context* context) {
 context->lighting(lighting);
 for(int i=0;i<8;++i) {
  context->enable(i,lights[i].enabled);
  context->type(i,lights[i].type);
  context->color(i,lights[i].color);
  context->direction(i,lights[i].direction);
  context->position(i,lights[i].position);
  context->range(i,lights[i].range);
  context->attenuation(i,lights[i].attenuation0,lights[i].attenuation1,lights[i].attenuation2);
  context->cone(i,lights[i].cone0,lights[i].cone1,lights[i].cone2);
 }
}
}
} // namespace fn_0031c9b0


// 0x0031ca70 pure3d::pddiFogState::vfunc_0 (51 B): matches/0x0031ca70.cpp
// sym: ?vfunc_0@pddiFogState@pure3d@@UAEXPAX@Z
void pure3d::pddiFogState::vfunc_0(void* __p0) { Device_31ca70 * d = (Device_31ca70 *)__p0;

    d->f78(this->f_04);
    d->f80(this->f_08, this->f_0c, this->f_10);
}


// 0x0031cab0 pure3d::pddiStencilState::vfunc_0 (107 B): matches/0x0031cab0.cpp
// sym: ?vfunc_0@pddiStencilState@pure3d@@UAEXPAX@Z
void pure3d::pddiStencilState::vfunc_0(void* __p0) { Dev_31cab0 * dev = (Dev_31cab0 *)__p0;

    dev->s0(this->f_04);
    dev->s1(this->f_08);
    dev->s2(this->f_0c);
    dev->s3(this->f_10);
    dev->s4(this->f_10);
    dev->s5(this->f_18, this->f_1c, this->f_20);
}

namespace fn_fc049dac {

// 0x0031cb20 FUN_0031cb20 (18 B): matches/0x0031cb20.cpp
// sym: ??0pddiRenderContext_31cb20@fn_fc049dac@@QAE@XZ
pddiRenderContext_31cb20::pddiRenderContext_31cb20() {
    Init();
    vptr = ((hulk_intptr)DAT_004325f4);
}


// 0x0031cb40 FUN_0031cb40 (30 B): matches/0x0031cb40.cpp
// sym: ?vfunc_2@CCollisionAction@fn_fc049dac@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_00328260();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fc049dac

// 0x0031cb60 pure3d::pddiBaseContext::vfunc_99 (1859 B): equivalent/0x0031cb60.cpp
// sym: ?vfunc_99@pddiBaseContext@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_99 @ 0x0031cb60
// the default states, written through the context's current-state pointers (f_48 view, f_4c raster, f_50 lighting,
// f_54 fog, f_58 stencil: 0x0031f190 sets them) and the display f_0c; each state starts with its vftable (the layouts
// of the constructors 0x0031ed40, 0x0031ee00, 0x0031eef0, 0x0031efd0, 0x0031f0a0)
namespace fn_0031cb60 {
struct Display_31cb60 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual float v16(); };
struct Vec4_31cb60 { float x,y,z,w; };
struct View { void* vftable; unsigned colour; float depth; int a,b; Vec4_31cb60 viewport; float nearPlane,farPlane,fov,aspect; };
struct Raster { void* vftable; int mode; unsigned char enabled; char pad0[3]; int compare; unsigned char write; char pad1[3]; int other; unsigned char channels[4]; };
struct Light { Vec4_31cb60 colour,position,direction,extra; char untouched[20]; float range,falloff,a,b,c,d,e; int type,mask; unsigned char enabled; char pad[3]; };
struct Lights_31cb60 { void* vftable; Light light[8]; unsigned ambient; };
struct Fog { void* vftable; unsigned char enabled; char pad[3]; int colour; float start,end; };
struct Stencil { void* vftable; unsigned char enabled; char pad[3]; int compare,reference,readMask,writeMask,fail,zfail,pass; };
// the context's vftable as this function calls it (vfunc_102 with an int argument: -1 is pushed as 0xffffffff)
struct Slots_31cb60 {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79(); virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); virtual void vfunc_88(); virtual void vfunc_89(); virtual void vfunc_90(); virtual void vfunc_91(); virtual void vfunc_92(); virtual void vfunc_93(); virtual void vfunc_94(); virtual void vfunc_95(); virtual void vfunc_96(); virtual void vfunc_97(); virtual void vfunc_98(); virtual void vfunc_99(); virtual void vfunc_100(); virtual void vfunc_101(); virtual void vfunc_102(int);
};
} // namespace fn_0031cb60
void pure3d::pddiBaseContext::vfunc_99() {
(*(fn_0031cb60::View**)&f_48)->colour=0xff000000; (*(fn_0031cb60::View**)&f_48)->depth=1.0f; (*(fn_0031cb60::View**)&f_48)->a=0; (*(fn_0031cb60::View**)&f_48)->b=0;
(*(fn_0031cb60::View**)&f_48)->viewport.x=0; (*(fn_0031cb60::View**)&f_48)->viewport.y=0; (*(fn_0031cb60::View**)&f_48)->viewport.z=1; (*(fn_0031cb60::View**)&f_48)->viewport.w=1;
float aspect=((fn_0031cb60::Display_31cb60*)f_0c)->v16(); (*(fn_0031cb60::View**)&f_48)->aspect=aspect; (*(fn_0031cb60::View**)&f_48)->nearPlane=1; (*(fn_0031cb60::View**)&f_48)->farPlane=1000; (*(fn_0031cb60::View**)&f_48)->fov=1.5707963705062866f;
(*(fn_0031cb60::Raster**)&f_4c)->enabled=1; (*(fn_0031cb60::Raster**)&f_4c)->channels[0]=1; (*(fn_0031cb60::Raster**)&f_4c)->channels[1]=1; (*(fn_0031cb60::Raster**)&f_4c)->channels[2]=1; (*(fn_0031cb60::Raster**)&f_4c)->channels[3]=1; (*(fn_0031cb60::Raster**)&f_4c)->mode=1; (*(fn_0031cb60::Raster**)&f_4c)->compare=3; (*(fn_0031cb60::Raster**)&f_4c)->write=1; (*(fn_0031cb60::Raster**)&f_4c)->other=0;
(*(fn_0031cb60::Lights_31cb60**)&f_50)->ambient=0xff101010;
for(int i=0;i<8;++i) { fn_0031cb60::Light& l=(*(fn_0031cb60::Lights_31cb60**)&f_50)->light[i]; l.enabled=0; l.type=0; l.mask=-1; l.colour.x=0; l.colour.y=0; l.colour.z=1; l.colour.w=1; l.position.x=0; l.position.y=0; l.position.z=0; l.position.w=1; l.direction.x=0; l.direction.y=0; l.direction.z=1; l.direction.w=0; l.extra.x=0; l.extra.y=0; l.extra.z=0; l.extra.w=0; l.range=10000000.0f; l.falloff=1; l.a=0; l.b=0; l.c=0; l.d=0; l.e=0; }
(*(fn_0031cb60::Fog**)&f_54)->enabled=0; (*(fn_0031cb60::Fog**)&f_54)->colour=-1; (*(fn_0031cb60::Fog**)&f_54)->start=0; (*(fn_0031cb60::Fog**)&f_54)->end=1000;
(*(fn_0031cb60::Stencil**)&f_58)->enabled=0; (*(fn_0031cb60::Stencil**)&f_58)->compare=1; (*(fn_0031cb60::Stencil**)&f_58)->reference=0; (*(fn_0031cb60::Stencil**)&f_58)->readMask=-1; (*(fn_0031cb60::Stencil**)&f_58)->writeMask=-1; (*(fn_0031cb60::Stencil**)&f_58)->fail=0; (*(fn_0031cb60::Stencil**)&f_58)->zfail=0; (*(fn_0031cb60::Stencil**)&f_58)->pass=0;
((fn_0031cb60::Slots_31cb60*)this)->vfunc_102(-1);
}


// 0x0031d2b0 pure3d::pddiBaseContext::vfunc_102 (78 B): matches/0x0031d2b0.cpp
// sym: ?vfunc_102@pddiBaseContext@pure3d@@UAEXE@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_102(unsigned char flags) {
    if (flags & 2) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_48))->call(this);
    }
    if (flags & 1) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_4c))->call(this);
    }
    if (flags & 4) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_50))->call(this);
    }
    if (flags & 8) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_54))->call(this);
    }
    if (flags & 16) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_58))->call(this);
    }
}


// 0x0031d300 pure3d::pddiBaseContext::vfunc_103 (123 B): matches/0x0031d300.cpp
// sym: ?vfunc_103@pddiBaseContext@pure3d@@UAEXXZ
// (x64t2) gen's fields (were literal 32-bit offsets 0xa4..0xb8, 0xc4..0xf8, which land in the matrix on 64-bit)
void pure3d::pddiBaseContext::vfunc_103() {
    *(int*)&f_a4 = 0;
    *(int*)_pad_a8 = 0;
    *(int*)&f_ac = 0;
    *(int*)_pad_b0 = 0;
    *(int*)&f_b4 = 0;
    *(int*)&f_b8 = 0;
    *(int*)&f_c4 = 0;
    *(int*)_pad_c8 = 0;
    *(int*)&f_cc = 0;
    *(int*)&f_d0 = 0;
    ((int*)_pad_d4)[0] = 0;
    ((int*)_pad_d4)[1] = 0;
    ((int*)_pad_d4)[2] = 0;
    ((int*)_pad_d4)[3] = 0;
    ((int*)_pad_d4)[4] = 0;
    ((int*)_pad_d4)[5] = 0;
    ((int*)_pad_d4)[6] = 0;
    ((int*)_pad_d4)[7] = 0;
    ((int*)_pad_d4)[8] = 0;
    ((int*)_pad_d4)[9] = 0;
}


// 0x0031d380 pure3d::pddiBaseContext::vfunc_104 (100 B): equivalent/0x0031d380.cpp
// sym: ?vfunc_104@pddiBaseContext@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// pure3d::pddiBaseContext::vfunc_104 @ 0x0031d380
void pure3d::pddiBaseContext::vfunc_104() {
    if (this->f_b4 > 0.0f)
        this->f_b8 = (this->f_ac + this->f_a4) / this->f_b4;
    else
        this->f_b8 = 0.0f;
    if (this->f_cc > 0.0f)
        this->f_d0 = this->f_c4 / this->f_cc;
    else
        this->f_d0 = 0.0f;
}


// 0x0031d3f0 pure3d::pddiBaseContext::vfunc_105 (113 B): equivalent/0x0031d3f0.cpp [wrapped: conflict: pure3d::pddiBaseContext]
// sym: ?vfunc_105@pddiBaseContext@pure3d@fn_0031d3f0@@QAEXXZ
namespace fn_0031d3f0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_105 @ 0x0031d3f0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif

namespace pure3d {
struct pddiBaseContext {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(const char*, int, int, unsigned int);
char padding[0x9c]; float frameTime;
void vfunc_105();
};
void pddiBaseContext::vfunc_105() {
char text[128];
sprintf(text, "%.2fms (%2.0ffps)", (double)frameTime, (double)(1000.0f / frameTime));
vfunc_33(text, 10, 25, 0xff141414u);
vfunc_33(text, 9, 24, 0xff969696u);
}
}
} // namespace fn_0031d3f0


// 0x0031d470 pure3d::pddiBaseContext::vfunc_4 (67 B): matches/0x0031d470.cpp [wrapped: macros]
// sym: ?vfunc_4@pddiBaseContext@pure3d@fn_0031d470@@UAEXXZ
namespace fn_0031d470 {
namespace pure3d {
class pddiBaseContext {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
#define V(n) virtual void v##n();
    V(5)
    V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
        V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40)
            V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56)
                V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71)
                    V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86)
                        V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100)
                            V(101) V(102) V(103) V(104) V(105) virtual void vfunc_106();
    virtual float vfunc_107();
    char pad[0x10];
    unsigned int f_14;
    int f_18;
    char pad2[0x9c - 0x1c];
    float f_9c;
    float f_a0;
};
void pddiBaseContext::vfunc_4() {
    f_18 = 1;
    ++f_14;
    f_9c = (float)f_14;
    f_a0 = vfunc_107();
    vfunc_106();
}
} // namespace pure3d
} // namespace fn_0031d470
#undef V


// 0x0031d4c0 pure3d::pddiBaseContext::vfunc_5 (40 B): matches/0x0031d4c0.cpp
// sym: ?vfunc_5@pddiBaseContext@pure3d@@UAEXXZ
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_5() {
    if (this->f_148) {
        vfunc_104();
        vfunc_105();
    }
    this->f_18 = 0;
}


// 0x0031d4f0 pure3d::pddiBaseContext::vfunc_6 (13 B): matches/0x0031d4f0.cpp
// sym: ?vfunc_6@pddiBaseContext@pure3d@@UAEXI@Z
void pure3d::pddiBaseContext::vfunc_6(unsigned int value) {
    *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_48, 4) = value;
}


// 0x0031d500 pure3d::pddiBaseContext::vfunc_7 (15 B): matches/0x0031d500.cpp
// sym: ?vfunc_7@pddiBaseContext@pure3d@@UAEPAXH@Z
 // namespace pure3d
void* pure3d::pddiBaseContext::vfunc_7(hulk_intptr __p0) { int * out = (int *)__p0;

    *out = ((State*)HULK_STATE_AT(*(void**)&this->f_48, 0))->value;
    return (void*)(out);
}


// 0x0031d510 pure3d::pddiBaseContext::vfunc_8 (13 B): matches/0x0031d510.cpp
// sym: ?vfunc_8@pddiBaseContext@pure3d@@UAEXPAX@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_8(void* __p0) { void * p = (void *)__p0;

    *(void**)((char*)(*(void * *)&this->f_48) + 8) = p;
}


// 0x0031d520 pure3d::pddiBaseContext::vfunc_9 (7 B): matches/0x0031d520.cpp
// sym: ?vfunc_9@pddiBaseContext@pure3d@@UAEMXZ
 // namespace pure3d
hulk_freg pure3d::pddiBaseContext::vfunc_9() {
    return *(float*)HULK_STATE_AT(*(void**)&this->f_48, 8);
}


// 0x0031d530 pure3d::pddiBaseContext::vfunc_10 (13 B): matches/0x0031d530.cpp
// sym: ?vfunc_10@pddiBaseContext@pure3d@@UAEXPAX@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_10(void* __p0) { void * value = (void *)__p0;

    (*(S_31d530 * *)&this->f_48)->value = value;
}


// 0x0031d540 pure3d::pddiBaseContext::vfunc_11 (7 B): matches/0x0031d540.cpp
// sym: ?vfunc_11@pddiBaseContext@pure3d@@UAEHXZ
 // namespace pure3d
int pure3d::pddiBaseContext::vfunc_11() {
    return *(int*)HULK_STATE_AT(*(void**)&this->f_48, 0xc);
}


// 0x0031d550 pure3d::pddiBaseContext::vfunc_12 (3 B): matches/0x0031d550.cpp
// sym: ?vfunc_12@pddiBaseContext@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::pddiBaseContext::vfunc_12(int a) {
    (void)a;
}


// 0x0031d560 pure3d::pddiBaseContext::vfunc_13 (44 B): matches/0x0031d560.cpp [wrapped: conflict: pure3d::pddiBaseContext]
// sym: ?vfunc_13@pddiBaseContext@pure3d@fn_0031d560@@UAEXH@Z
namespace fn_0031d560 {
namespace pure3d {
struct pddiBaseContext {
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
    virtual void vfunc_13(int);
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
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108(int);
    char pad[0x1c];
    struct Item {
        char x[8];
        int a, b;
    }* items[1];
};
} // namespace pure3d
extern "C" void __fastcall FUN_0022b980(int);
void pure3d::pddiBaseContext::vfunc_13(int index) {
    Item* p = items[index];
    FUN_0022b980(p->a * 64 + p->b);
    f108(index);
}
} // namespace fn_0031d560


// 0x0031d590 pure3d::pddiBaseContext::vfunc_14 (50 B): matches/0x0031d590.cpp [wrapped: macros]
// sym: ?vfunc_14@pddiBaseContext@pure3d@fn_0031d590@@UAEXHPAK@Z
namespace fn_0031d590 {
#define V(n) virtual void f##n();
namespace pure3d {
struct Block {
    unsigned long x[16];
};
struct Entry {
    char a[8];
    unsigned long count;
    unsigned long* data;
};
class pddiBaseContext {
  public:
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12)
        V(13) virtual void vfunc_14(int, unsigned long*);
    V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32)
        V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
            V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65)
                V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80)
                    V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95)
                        V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106)
                            V(107) virtual void f108(int);
    char pad[0x1c];
    Entry* entries[1];
};
void pddiBaseContext::vfunc_14(int n, unsigned long* src) {
    Entry* e = entries[n];
    Block* dst = (Block*)(e->data + e->count * 16);
    *dst = *(Block*)src;
    f108(n);
}
} // namespace pure3d
} // namespace fn_0031d590
#undef V


// 0x0031d5d0 pure3d::pddiBaseContext::vfunc_17 (86 B): matches/0x0031d5d0.cpp [wrapped: conflict: pure3d::pddiBaseContext]
// sym: ?vfunc_17@pddiBaseContext@pure3d@fn_0031d5d0@@UAEXHH@Z
namespace fn_0031d5d0 {
namespace pure3d {
struct Vec_31d5d0 {
    unsigned int x[16];
    void fill(int, hulk_uintptr);
};
struct Item_31d5d0 {
    char a[8];
    hulk_uintptr count;
    hulk_uintptr ptr;
};
class pddiBaseContext {
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
    virtual void vfunc_17(int, int);
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
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108(int);
    char pad[28];
    Item_31d5d0* items[1];
};
} // namespace pure3d
void pure3d::pddiBaseContext::vfunc_17(int i, int p) {
    Vec_31d5d0 t;
    Item_31d5d0* q = items[i];
    hulk_uintptr d = q->count * 64 + q->ptr;
    t.fill(p, d);
    *(Vec_31d5d0*)(q->count * 64 + q->ptr) = t;
    f108(i);
}
} // namespace fn_0031d5d0


// 0x0031d630 pure3d::pddiBaseContext::vfunc_93 (137 B): equivalent/0x0031d630.cpp [wrapped: conflict: pure3d::pddiBaseContext]
// sym: ?vfunc_93@pddiBaseContext@pure3d@fn_0031d630@@UAEXHIII@Z
namespace fn_0031d630 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_93 @ 0x0031d630
struct Matrix {
 unsigned int elements[16];
 void FUN_0022b980();
 void FUN_0022ca90(const Matrix*, const Matrix*);
};
struct MatrixStack_31d630 { char pad[8]; unsigned int index; Matrix* matrices; };
namespace pure3d {
struct pddiBaseContext {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
 virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
 virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
 virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
 virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
 virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
 virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69();
 virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79();
 virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); virtual void vfunc_88(); virtual void vfunc_89();
 virtual void vfunc_90(); virtual void vfunc_91(); virtual void vfunc_92(); virtual void vfunc_93(int, unsigned int, unsigned int, unsigned int); virtual void vfunc_94(); virtual void vfunc_95(); virtual void vfunc_96(); virtual void vfunc_97(); virtual void vfunc_98(); virtual void vfunc_99();
 virtual void vfunc_100(); virtual void vfunc_101(); virtual void vfunc_102(); virtual void vfunc_103(); virtual void vfunc_104(); virtual void vfunc_105(); virtual void vfunc_106(); virtual void vfunc_107(); virtual void vfunc_108(int);
 char padding[28]; MatrixStack_31d630* stacks[1];
};
void pddiBaseContext::vfunc_93(int mode, unsigned int x, unsigned int y, unsigned int z) {
 Matrix scale, result;
 scale.FUN_0022b980();
 MatrixStack_31d630* stack = stacks[mode];
 scale.elements[0] = x;
 scale.elements[5] = y;
 scale.elements[10] = z;
 result.FUN_0022ca90(&scale, &stack->matrices[stack->index]);
 Matrix* destination = &stack->matrices[stack->index];
 for (int i=0; i<16; ++i) destination->elements[i] = result.elements[i];
 vfunc_108(mode);
}
}
} // namespace fn_0031d630


// 0x0031d6c0 pure3d::pddiBaseContext::vfunc_19 (21 B): matches/0x0031d6c0.cpp
// sym: ?vfunc_19@pddiBaseContext@pure3d@@UAEXPAX@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_19(void* __p0) { const Block_31d6c0 * p = (const Block_31d6c0 *)__p0;

    *(Block_31d6c0*)((char*)this + 0x5c) = *p;
}


// 0x0031d6e0 pure3d::pddiBaseContext::vfunc_20 (4 B): matches/0x0031d6e0.cpp
// sym: ?vfunc_20@pddiBaseContext@pure3d@@UAEPAXXZ
 // namespace pure3d
void* pure3d::pddiBaseContext::vfunc_20() {
    return (void*)((pure3d::pddiBaseContext*)((char*)this + 0x5c));
}


// 0x0031d6f0 pure3d::pddiBaseContext::vfunc_24 (21 B): matches/0x0031d6f0.cpp
// sym: ?vfunc_24@pddiBaseContext@pure3d@@UAEXH@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_24(int value) {
    *(int*)HULK_STATE_AT(*(void**)&this->f_48, 0x10) = value;
    vfunc_109();
}


// 0x0031d710 pure3d::pddiBaseContext::vfunc_25 (7 B): matches/0x0031d710.cpp
// sym: ?vfunc_25@pddiBaseContext@pure3d@@UAEIXZ
unsigned int pure3d::pddiBaseContext::vfunc_25() {
    return *(unsigned int*)(*(hulk_uintptr*)((char*)this + 0x48) + 0x10);
}


// 0x0031d720 pure3d::pddiBaseContext::vfunc_26 (44 B): matches/0x0031d720.cpp
// sym: ?vfunc_26@pddiBaseContext@pure3d@@UAEXIIII@Z
void pure3d::pddiBaseContext::vfunc_26(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    unsigned* p = (unsigned*)HULK_STATE_AT(*(void**)&this->f_48, 0x14);
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    vfunc_109();
}


// 0x0031d750 pure3d::pddiBaseContext::vfunc_27 (51 B): matches/0x0031d750.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?vfunc_27@pddiBaseContext@fn_0031d750@@QAEXPAH000@Z
namespace fn_0031d750 {
class pddiBaseContext {
  public:
    struct Data {
        char pad2[0x14];
        int a, b, c, d;
    };
    void vfunc_27(int*, int*, int*, int*);
};
// (x64t2) the view state f_48 through gen's context, its words behind the vftable (HULK_STATE_AT)
void pddiBaseContext::vfunc_27(int* p1, int* p2, int* p3, int* p4) {
    *p1 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_48), 0))->a;
    *p2 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_48), 0))->b;
    *p3 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_48), 0))->c;
    *p4 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_48), 0))->d;
}
} // namespace fn_0031d750


// 0x0031d790 pure3d::pddiBaseContext::vfunc_28 (44 B): matches/0x0031d790.cpp
// sym: ?vfunc_28@pddiBaseContext@pure3d@@UAEXIIII@Z
void pure3d::pddiBaseContext::vfunc_28(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    unsigned* p = (unsigned*)HULK_STATE_AT(*(void**)&this->f_48, 0x24);
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    vfunc_109();
}


// 0x0031d7c0 pure3d::pddiBaseContext::vfunc_29 (51 B): matches/0x0031d7c0.cpp
// sym: ?vfunc_29@pddiBaseContext@pure3d@@UAEXPAX000@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_29(void* __p0, void* __p1, void* __p2, void* __p3) { unsigned int * a = (unsigned int *)__p0; unsigned int * b = (unsigned int *)__p1; unsigned int * c = (unsigned int *)__p2; unsigned int * d = (unsigned int *)__p3;

    *a = *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_48, 0x24);
    *b = *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_48, 0x28);
    *c = *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_48, 0x2c);
    *d = *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_48, 0x30);
}


// 0x0031d800 pure3d::pddiBaseContext::vfunc_30 (5 B): matches/0x0031d800.cpp
// sym: ?vfunc_30@pddiBaseContext@pure3d@@UAEHHHHHH@Z
// Same code shape as 0x00272bf0 (propagated; names are from that function)
int pure3d::pddiBaseContext::vfunc_30(hulk_intptr , int , int , int , int ) {
    return 0;
}


// 0x0031d810 pure3d::pddiBaseContext::vfunc_31 (3 B): matches/0x0031d810.cpp
// sym: ?vfunc_31@pddiBaseContext@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::pddiBaseContext::vfunc_31(int a) {
    (void)a;
}


// 0x0031d820 pure3d::pddiBaseContext::vfunc_32 (3 B): matches/0x0031d820.cpp
// sym: ?vfunc_32@pddiBaseContext@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::pddiBaseContext::vfunc_32(hulk_intptr a, hulk_intptr b) {}


// 0x0031d830 pure3d::pddiBaseContext::vfunc_33 (201 B): equivalent/0x0031d830.cpp [wrapped: conflict: pure3d::pddiBaseContext]
// sym: ?vfunc_33@pddiBaseContext@pure3d@fn_0031d830@@UAEXIIII@Z
namespace fn_0031d830 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_33 @ 0x0031d830
struct Matrix { float elements[16]; void FUN_0022b980(); };
struct Renderer_31d830 { void FUN_00328270(unsigned a, unsigned b, unsigned c, float scale, unsigned d); };
struct State_31d830 { char pad[0x24]; float values[4]; };
namespace pure3d {
struct pddiBaseContext {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(unsigned); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(unsigned); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(unsigned); virtual unsigned vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(unsigned,unsigned,unsigned,unsigned);
char pad04[0x44]; State_31d830* state; char pad4c[0xf8]; Renderer_31d830* renderer; char pad148; unsigned char active;
};
void pddiBaseContext::vfunc_33(unsigned a,unsigned b,unsigned c,unsigned d) {
active=1;
unsigned previous=vfunc_25();
State_31d830* savedState=state;
float saved[4];
saved[0]=savedState->values[0]; saved[1]=savedState->values[1]; saved[2]=savedState->values[2]; saved[3]=savedState->values[3];
savedState->values[0]=saved[0]*0.5f; savedState->values[1]=saved[0];
vfunc_24(2);
Matrix matrix; matrix.FUN_0022b980();
vfunc_21(0);
renderer->FUN_00328270(a,b,c,saved[0]*0.75f,d);
vfunc_16(0);
savedState->values[0]=saved[0]; savedState->values[1]=saved[1]; savedState->values[2]=saved[2]; savedState->values[3]=saved[3];
vfunc_24(previous);
active=0;
}
}
} // namespace fn_0031d830


// 0x0031d900 pure3d::pddiBaseContext::vfunc_34 (6 B): matches/0x0031d900.cpp
// sym: ?vfunc_34@pddiBaseContext@pure3d@@UAEHXZ
// Same code shape as 0x00234f10 (propagated; names are from that function)
int pure3d::pddiBaseContext::vfunc_34() {
    return 8;
}

namespace fn_fc049dac {

// 0x0031d910 pure3d::pddiBaseContext::vfunc_35 (16 B): matches/0x0031d910.cpp
// sym: ?vfunc_35@pddiBaseContext@fn_fc049dac@@QAEXH@Z
// (x64t2) the lighting state f_50 through gen's context, its ambient word behind the vftable and the 8 lights
void pddiBaseContext::vfunc_35(int value) {
    *(int*)HULK_STATE_AT(HULK_CTX_STATE(this, f_50), 0x3e4) = value;
}

} // namespace fn_fc049dac

// 0x0031d920 pure3d::pddiBaseContext::vfunc_36 (18 B): matches/0x0031d920.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?vfunc_36@pddiBaseContext@fn_0031d920@@UAEPAHPAH@Z
namespace fn_0031d920 {
class pddiBaseContext {
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
    virtual int* vfunc_36(int* out);
    char pad[0x50 - 4];
    void* mObj;
};

int* pddiBaseContext::vfunc_36(int* out) {
    *out = *(int*)((char*)mObj + 0x3e4);
    return out;
}
} // namespace fn_0031d920


// 0x0031d940 pure3d::pddiBaseContext::vfunc_37 (255 B): equivalent/0x0031d940.cpp [wrapped: macros]
// sym: ?vfunc_37@pddiBaseContext@pure3d@fn_0031d940@@UAEXHPBULightInput@23@I@Z
namespace fn_0031d940 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_37 @ 0x0031d940
namespace pure3d {
struct LightInput { unsigned char enabled; char pad[3]; unsigned type; unsigned color; unsigned position[3]; unsigned direction[3]; unsigned parameters[6]; unsigned last; };
struct LightState { unsigned position[4]; char gap0[16]; unsigned direction[4]; char gap1[16]; float red,green,blue; unsigned gap2; float average; unsigned last; unsigned parameters[6]; unsigned type,color; unsigned char enabled; char pad[3]; };
struct LightTable { unsigned header; LightState lights[8]; };
struct pddiBaseContext {
#define V(n) virtual void vfunc_##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
virtual void vfunc_37(int index, const LightInput* input, unsigned flags);
V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
virtual void vfunc_110(int index, unsigned flags);
char padding[0x4c]; LightTable* table;
};
void pddiBaseContext::vfunc_37(int index, const LightInput* input, unsigned flags) {
if(index >= 8) return;
LightState& s = table->lights[index];
s.enabled=input->enabled; s.type=input->type; s.color=input->color;
s.red=float((s.color>>16)&255); s.green=float((s.color>>8)&255); s.blue=float(s.color&255);
s.average=float((((s.color>>16)&255)+((s.color>>8)&255)+(s.color&255))/3);
s.position[0]=input->position[0]; s.position[1]=input->position[1]; s.position[2]=input->position[2]; s.position[3]=0x3f800000;
s.direction[0]=input->direction[0]; s.direction[1]=input->direction[1]; s.direction[2]=input->direction[2]; s.direction[3]=0;
s.parameters[0]=input->parameters[0]; s.parameters[1]=input->parameters[1]; s.parameters[2]=input->parameters[2]; s.parameters[3]=input->parameters[3]; s.parameters[4]=input->parameters[4]; s.parameters[5]=input->parameters[5]; s.last=input->last;
vfunc_110(index,flags);
}
}
} // namespace fn_0031d940
#undef V


// 0x0031da40 pure3d::pddiBaseContext::vfunc_38 (52 B): matches/0x0031da40.cpp
// sym: ?vfunc_38@pddiBaseContext@pure3d@@UAEXHH@Z
void pure3d::pddiBaseContext::vfunc_38(int i, int v) {
    if (i < 8) {
        *(u8*)HULK_STATE_AT(*(void**)&this->f_50, (i + 1) * 0x7c) = (u8)v;
        vfunc_110(i, 0);
    }
}


// 0x0031da80 pure3d::pddiBaseContext::vfunc_39 (27 B): matches/0x0031da80.cpp
// sym: ?vfunc_39@pddiBaseContext@pure3d@@UAEEI@Z
unsigned char pure3d::pddiBaseContext::vfunc_39(unsigned int param) {
    if ((int)param < 8)
        return *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_50, (param + 1) * 0x7c);
    return 0;
}


// 0x0031daa0 pure3d::pddiBaseContext::vfunc_40 (52 B): matches/0x0031daa0.cpp
// sym: ?vfunc_40@pddiBaseContext@pure3d@@UAEXHH@Z
void pure3d::pddiBaseContext::vfunc_40(int i, int v) {
    if (i < 8) {
        ((int*)HULK_STATE_AT(*(void**)&this->f_50, i * 0x7c + 0x74))[0] = v;
        vfunc_110(i, 0);
    }
}


// 0x0031dae0 pure3d::pddiBaseContext::vfunc_41 (27 B): matches/0x0031dae0.cpp
// sym: ?vfunc_41@pddiBaseContext@pure3d@@UAEHH@Z
int pure3d::pddiBaseContext::vfunc_41(int x) {
    if (x < 8)
        return *(int*)HULK_STATE_AT(*(void**)&this->f_50, x * 0x7c + 0x74);
    return 0;
}


// 0x0031db00 pure3d::pddiBaseContext::vfunc_42 (156 B): equivalent/0x0031db00.cpp
// sym: ?vfunc_42@pddiBaseContext@pure3d@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_42 @ 0x0031db00
void pure3d::pddiBaseContext::vfunc_42(int index, int __p1) { unsigned int color = (unsigned int)__p1;

 if (index < 8) {
 ((LightState_31db00*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index].color = color;
 int red = (color >> 16) & 255;
 int green = (color >> 8) & 255;
 int blue = color & 255;
 ((LightState_31db00*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index].red = (float)red;
 ((LightState_31db00*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index].green = (float)green;
 ((LightState_31db00*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index].blue = (float)blue;
 ((LightState_31db00*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index].average = (float)((red + green + blue) / 3);
 vfunc_110(index, 0);
 }
}


// 0x0031dba0 pure3d::pddiBaseContext::vfunc_43 (41 B): equivalent/0x0031dba0.cpp
// sym: ?vfunc_43@pddiBaseContext@pure3d@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19889 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_43 @ 0x0031dba0
void pure3d::pddiBaseContext::vfunc_43(hulk_intptr __p0, int index) { unsigned int * result = (unsigned int *)__p0;

    if (index < 8)
        *result = ((TextureStage*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index].value;
    else
        *result = 0;
}


// 0x0031dbd0 pure3d::pddiBaseContext::vfunc_44 (114 B): equivalent/0x0031dbd0.cpp
// sym: ?vfunc_44@pddiBaseContext@pure3d@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_44 @ 0x0031dbd0
// Sets the position of light `index` (0..7) in the context's light table and re-applies the light.
void pure3d::pddiBaseContext::vfunc_44(int index, hulk_intptr __p1) { const Vec3_31dbd0 * pos = (const Vec3_31dbd0 *)__p1;

    if (index < 8) {
        Vec3_31dbd0 p = *pos;
        Light_31dbd0 *l = &((Light_31dbd0*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index];
        l->pos = p;
        l->w = 1.0f;
        vfunc_110(index, 1);
    }
}


// 0x0031dc50 pure3d::pddiBaseContext::vfunc_45 (61 B): matches/0x0031dc50.cpp
// sym: ?vfunc_45@pddiBaseContext@pure3d@@UAEXHPAX@Z
void pure3d::pddiBaseContext::vfunc_45(int index, void* __p1) { V * out = (V *)__p1;

    if (index < 8) {
        char* p = HULK_STATE_AT(*(void**)&this->f_50, index * 0x7c + 4);
        int a = *(int*)p;
        V* q = out;
        q->x = a;
        q->y = *(int*)(p + 4);
        q->z = *(int*)(p + 8);
    } else {
        out->z = 0;
        out->y = 0;
        out->x = 0;
    }
}


// 0x0031dc90 pure3d::pddiBaseContext::vfunc_46 (114 B): matches/0x0031dc90.cpp
// sym: ?vfunc_46@pddiBaseContext@pure3d@@UAEXHH@Z
// pure3d::pddiBaseContext::vfunc_46 @ 0x0031dc90
void pure3d::pddiBaseContext::vfunc_46(int index, hulk_intptr __p1) { const Vec3_31dc90 * direction = (const Vec3_31dc90 *)__p1;

    if (index < 8) {
        Vec4_31dc90 v;
        v.x = direction->x;
        v.y = direction->y;
        v.z = direction->z;
        v.w = 0.0f;
        ((LightState_31dc90*)HULK_STATE_AT(*(void**)&this->f_50, 0))[index].direction = v;
        vfunc_110(index, 1);
    }
}


// 0x0031dd10 pure3d::pddiBaseContext::vfunc_47 (61 B): matches/0x0031dd10.cpp
// sym: ?vfunc_47@pddiBaseContext@pure3d@@UAEXHPAX@Z
void pure3d::pddiBaseContext::vfunc_47(int i, void* __p1) { unsigned int * out = (unsigned int *)__p1;

    if (i < 8) {
        unsigned int* p = (unsigned int*)HULK_STATE_AT(*(void**)&this->f_50, i * 0x7c + 0x24);
        out[0] = p[0];
        out[1] = p[1];
        out[2] = p[2];
    } else {
        out[2] = 0;
        out[1] = 0;
        out[0] = 0;
    }
}


// 0x0031dd50 pure3d::pddiBaseContext::vfunc_48 (50 B): matches/0x0031dd50.cpp
// sym: ?vfunc_48@pddiBaseContext@pure3d@@UAEXHM@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_48(int index, float value) {
    if (index < 8) {
        int i = index;
        char* p = HULK_STATE_AT(*(void**)&this->f_50, 0);
        *(float*)(p + i * 0x7c + 0x58) = value;
        vfunc_110(index, 0);
    }
}


// 0x0031dd90 pure3d::pddiBaseContext::vfunc_49 (31 B): matches/0x0031dd90.cpp
// sym: ?vfunc_49@pddiBaseContext@pure3d@@UAEMH@Z
 // namespace pure3d
hulk_freg pure3d::pddiBaseContext::vfunc_49(int index) {
    if (index < 8)
        return *(float*)HULK_STATE_AT(*(void**)&this->f_50, index * 0x7c + 0x58);
    return 0.0f;
}


// 0x0031ddb0 pure3d::pddiBaseContext::vfunc_50 (63 B): matches/0x0031ddb0.cpp
// sym: ?vfunc_50@pddiBaseContext@pure3d@@UAEXHMMM@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_50(int i, float a, float b, float c) {
    if (i < 8) {
        *(float*)HULK_STATE_AT(*(void**)&this->f_50, i * 0x7c + 0x5c) = a;
        *(float*)HULK_STATE_AT(*(void**)&this->f_50, i * 0x7c + 0x60) = b;
        *(float*)HULK_STATE_AT(*(void**)&this->f_50, i * 0x7c + 0x64) = c;
        vfunc_110(i, 0);
    }
}


// 0x0031ddf0 pure3d::pddiBaseContext::vfunc_51 (89 B): matches/0x0031ddf0.cpp
// sym: ?vfunc_51@pddiBaseContext@pure3d@@UAEXHPAX00@Z
void pure3d::pddiBaseContext::vfunc_51(int i, void* __p1, void* __p2, void* __p3) { unsigned int * a = (unsigned int *)__p1; unsigned int * b = (unsigned int *)__p2; unsigned int * c = (unsigned int *)__p3;

    if (i < 8) {
        *a = ((Rec_31ddf0*)HULK_STATE_AT(*(void**)&this->f_50, 0))[i].x;
        *b = ((Rec_31ddf0*)HULK_STATE_AT(*(void**)&this->f_50, 0))[i].y;
        *c = ((Rec_31ddf0*)HULK_STATE_AT(*(void**)&this->f_50, 0))[i].z;
    } else {
        *c = 0;
        *b = 0;
        *a = 0;
    }
}


// 0x0031de50 pure3d::pddiBaseContext::vfunc_52 (63 B): matches/0x0031de50.cpp [wrapped: macros]
// sym: ?f52@pddiBaseContext@fn_0031de50@@UAEXHMMM@Z
namespace fn_0031de50 {
class pddiBaseContext {
  public:
#define V(n) virtual void f##n();
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
                V(51) virtual void f52(int, float, float, float);
    V(53)
    V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70)
        V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
            V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102)
                V(103) V(104) V(105) V(106) V(107) V(108) V(109) virtual void f110(int, int);
#undef V
};
// (x64t2) the lighting state f_50 through gen's context (HULK_STATE_AT: its words behind the vftable)
void pddiBaseContext::f52(int i, float a, float b, float c) {
    if (i < 8) {
        ((float*)HULK_STATE_AT(HULK_CTX_STATE(this, f_50), i * 0x7c + 0x68))[0] = a;
        ((float*)HULK_STATE_AT(HULK_CTX_STATE(this, f_50), i * 0x7c + 0x68))[1] = b;
        ((float*)HULK_STATE_AT(HULK_CTX_STATE(this, f_50), i * 0x7c + 0x68))[2] = c;
        f110(i, 0);
    }
}
} // namespace fn_0031de50
#undef V


// 0x0031de90 pure3d::pddiBaseContext::vfunc_53 (89 B): matches/0x0031de90.cpp [wrapped: conflict: pddiBaseContext]
// sym: ?vfunc_53@pddiBaseContext@fn_0031de90@@QAEXHPAH00@Z
namespace fn_0031de90 {
class pddiRenderContext {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
};
class pddiBaseContext : public pddiRenderContext {
  public:
    struct Entry {
        char b[0x68];
        int x, y, z;
        char rest[8];
    };
    void vfunc_53(int, int*, int*, int*);
};
// (x64t2) the lighting state f_50 through gen's context, its lights behind the vftable (HULK_STATE_AT)
void pddiBaseContext::vfunc_53(int n, int* a, int* b, int* c) {
    if (n < 8) {
        *a = ((Entry*)HULK_STATE_AT(HULK_CTX_STATE(this, f_50), 0))[n].x;
        *b = ((Entry*)HULK_STATE_AT(HULK_CTX_STATE(this, f_50), 0))[n].y;
        *c = ((Entry*)HULK_STATE_AT(HULK_CTX_STATE(this, f_50), 0))[n].z;
    } else {
        *c = 0;
        *b = 0;
        *a = 0;
    }
}
} // namespace fn_0031de90


// 0x0031def0 pure3d::pddiBaseContext::vfunc_54 (13 B): matches/0x0031def0.cpp
// sym: ?vfunc_54@pddiBaseContext@pure3d@@UAEXH@Z
void pure3d::pddiBaseContext::vfunc_54(int x) {
    *(int*)HULK_STATE_AT(*(void**)&this->f_4c, 4) = x;
}


// 0x0031df00 pure3d::pddiBaseContext::vfunc_55 (7 B): matches/0x0031df00.cpp
// sym: ?vfunc_55@pddiBaseContext@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::pddiBaseContext::vfunc_55() {
    return *(unsigned int*)(*(hulk_uintptr*)((char*)this + 0x4c) + 4);
}


// 0x0031df10 pure3d::pddiBaseContext::vfunc_56 (43 B): matches/0x0031df10.cpp
// sym: ?vfunc_56@pddiBaseContext@pure3d@@UAEXDDDD@Z
void pure3d::pddiBaseContext::vfunc_56(char __p0, char __p1, char __p2, char __p3) { unsigned char a = (unsigned char)__p0; unsigned char b = (unsigned char)__p1; unsigned char c = (unsigned char)__p2; unsigned char d = (unsigned char)__p3;

    *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_4c, 0x18) = a;
    *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_4c, 0x19) = b;
    *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_4c, 0x1a) = c;
    *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_4c, 0x1b) = d;
}


// 0x0031df40 pure3d::pddiBaseContext::vfunc_57 (51 B): matches/0x0031df40.cpp [wrapped: conflict: pddiBaseContext]
// sym: ?vfunc_57@pddiBaseContext@fn_0031df40@@QAEXPAE000@Z
namespace fn_0031df40 {
typedef unsigned char u8_31df40;
struct pddiBaseContext {
    struct Data {
        char pad2[0x18];
        u8_31df40 a, b, c, d;
    };
    void vfunc_57(u8_31df40*, u8_31df40*, u8_31df40*, u8_31df40*);
};
// (x64t2) the render state f_4c through gen's context (HULK_STATE_AT: its words behind the vftable)
void pddiBaseContext::vfunc_57(u8_31df40* p1, u8_31df40* p2, u8_31df40* p3, u8_31df40* p4) {
    *p1 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_4c), 0))->a;
    *p2 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_4c), 0))->b;
    *p3 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_4c), 0))->c;
    *p4 = ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_4c), 0))->d;
}
} // namespace fn_0031df40


// 0x0031df80 pure3d::pddiBaseContext::vfunc_58 (13 B): matches/0x0031df80.cpp [wrapped: macros]
// sym: ?vfunc_58@pddiBaseContext@fn_0031df80@@QAEXE@Z
namespace fn_0031df80 {
class pddiBaseContext {
  public:
#define V(n) virtual void a##n();
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
                V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67)
                    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82)
                        V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96)
                            V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108)
                                V(109) V(110)
    void vfunc_58(unsigned char);
};
// (x64t2) the render state f_4c through gen's context (HULK_STATE_AT: its words behind the vftable)
void pddiBaseContext::vfunc_58(unsigned char x) {
    *(unsigned char*)HULK_STATE_AT(HULK_CTX_STATE(this, f_4c), 8) = x;
}
} // namespace fn_0031df80
#undef V


// 0x0031df90 pure3d::pddiBaseContext::vfunc_59 (7 B): matches/0x0031df90.cpp
// sym: ?vfunc_59@pddiBaseContext@pure3d@@UAEEXZ
unsigned char pure3d::pddiBaseContext::vfunc_59() {
    return *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_4c, 8);
}


// 0x0031dfa0 pure3d::pddiBaseContext::vfunc_60 (13 B): matches/0x0031dfa0.cpp
// sym: ?vfunc_60@pddiBaseContext@pure3d@@UAEXH@Z
void pure3d::pddiBaseContext::vfunc_60(int x) {
    *(int*)HULK_STATE_AT(*(void**)&this->f_4c, 0xc) = x;
}


// 0x0031dfb0 pure3d::pddiBaseContext::vfunc_61 (7 B): matches/0x0031dfb0.cpp
// sym: ?vfunc_61@pddiBaseContext@pure3d@@UAEIXZ
unsigned int pure3d::pddiBaseContext::vfunc_61() {
    return *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_4c, 0xc);
}


// 0x0031dfc0 pure3d::pddiBaseContext::vfunc_62 (13 B): matches/0x0031dfc0.cpp [wrapped: conflict: pddiBaseContext]
// sym: ?vfunc_62@pddiBaseContext@fn_0031dfc0@@UAEXE@Z
namespace fn_0031dfc0 {
class pddiBaseContext {

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
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void vfunc_62(unsigned char);
};
// (x64t2) the render state f_4c through gen's context (HULK_STATE_AT: its words behind the vftable)
void pddiBaseContext::vfunc_62(unsigned char x) {
    *(unsigned char*)HULK_STATE_AT(HULK_CTX_STATE(this, f_4c), 0x10) = x;
}
} // namespace fn_0031dfc0


// 0x0031dfd0 pure3d::pddiBaseContext::vfunc_63 (7 B): matches/0x0031dfd0.cpp
// sym: ?vfunc_63@pddiBaseContext@pure3d@@UAEEXZ
unsigned char pure3d::pddiBaseContext::vfunc_63() {
    return *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_4c, 0x10);
}


// 0x0031dfe0 pure3d::pddiBaseContext::vfunc_64 (13 B): matches/0x0031dfe0.cpp
// sym: ?vfunc_64@pddiBaseContext@pure3d@@UAEXH@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_64(int __p0) { unsigned char value = (unsigned char)__p0;

    *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_58, 4) = value;
}


// 0x0031dff0 pure3d::pddiBaseContext::vfunc_65 (7 B): matches/0x0031dff0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?vfunc_65@pddiBaseContext@fn_0031dff0@@QAEEXZ
namespace fn_0031dff0 {
class pddiBaseContext {
  public:
    unsigned char vfunc_65();
};
// (x64t2) the stencil state f_58 through gen's context (HULK_STATE_AT: its words behind the vftable)
unsigned char pddiBaseContext::vfunc_65() {
    return *(unsigned char*)HULK_STATE_AT(HULK_CTX_STATE(this, f_58), 4);
}
} // namespace fn_0031dff0


// 0x0031e000 pure3d::pddiBaseContext::vfunc_66 (13 B): matches/0x0031e000.cpp
// sym: ?vfunc_66@pddiBaseContext@pure3d@@UAEXH@Z
void pure3d::pddiBaseContext::vfunc_66(int __p0) { unsigned int x = (unsigned int)__p0;

    *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_58, 8) = x;
}


// 0x0031e010 pure3d::pddiBaseContext::vfunc_67 (7 B): matches/0x0031e010.cpp
// sym: ?vfunc_67@pddiBaseContext@pure3d@@UAEHXZ
int pure3d::pddiBaseContext::vfunc_67() {
    return *(int*)HULK_STATE_AT(*(void**)&this->f_58, 8);
}


// 0x0031e020 pure3d::pddiBaseContext::vfunc_68 (13 B): matches/0x0031e020.cpp [wrapped: conflict: pddiBaseContext]
// sym: ?vfunc_68@pddiBaseContext@fn_0031e020@@QAEXH@Z
namespace fn_0031e020 {
class pddiBaseContext {
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
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    void vfunc_68(int);
};
// (x64t2) the stencil state f_58 through gen's context (HULK_STATE_AT: its words behind the vftable)
void pddiBaseContext::vfunc_68(int value) {
    *(int*)HULK_STATE_AT(HULK_CTX_STATE(this, f_58), 0xc) = value;
}
} // namespace fn_0031e020


// 0x0031e030 pure3d::pddiBaseContext::vfunc_69 (7 B): matches/0x0031e030.cpp
// sym: ?vfunc_69@pddiBaseContext@pure3d@@UAEHXZ
 // namespace pure3d
int pure3d::pddiBaseContext::vfunc_69() {
    return *(int*)HULK_STATE_AT(*(void**)&this->f_58, 0xc);
}


// 0x0031e040 pure3d::pddiBaseContext::vfunc_70 (13 B): matches/0x0031e040.cpp
// sym: ?vfunc_70@pddiBaseContext@pure3d@@UAEXH@Z
void pure3d::pddiBaseContext::vfunc_70(int x) {
    *(int*)HULK_STATE_AT(*(void**)&this->f_58, 0x10) = x;
}


// 0x0031e050 pure3d::pddiBaseContext::vfunc_71 (7 B): matches/0x0031e050.cpp
// sym: ?vfunc_71@pddiBaseContext@pure3d@@UAEHXZ
int pure3d::pddiBaseContext::vfunc_71() {
    return *(int*)(*(hulk_intptr*)((char*)this + 0x58) + 0x10);
}


// 0x0031e060 pure3d::pddiBaseContext::vfunc_72 (13 B): matches/0x0031e060.cpp
// sym: ?vfunc_72@pddiBaseContext@pure3d@@UAEXH@Z
void pure3d::pddiBaseContext::vfunc_72(int value) {
    *(int*)HULK_STATE_AT(*(void**)&this->f_58, 0x14) = value;
}


// 0x0031e070 pure3d::pddiBaseContext::vfunc_73 (7 B): matches/0x0031e070.cpp
// sym: ?vfunc_73@pddiBaseContext@pure3d@@UAEHXZ
int pure3d::pddiBaseContext::vfunc_73() {
    return *(int*)HULK_STATE_AT(*(void**)&this->f_58, 0x14);
}


// 0x0031e080 pure3d::pddiBaseContext::vfunc_74 (33 B): matches/0x0031e080.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?vfunc_74@pddiBaseContext@fn_0031e080@@UAEXHHH@Z
namespace fn_0031e080 {
class pddiBaseContext {
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
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void vfunc_74(int, int, int);
    struct State {
        char pad[0x18];
        int a, b, c;
    };
};
// (x64t2) the stencil state f_58 through gen's context (HULK_STATE_AT: its words behind the vftable)
void pddiBaseContext::vfunc_74(int a, int b, int c) {
    ((State*)HULK_STATE_AT(HULK_CTX_STATE(this, f_58), 0))->a = a;
    ((State*)HULK_STATE_AT(HULK_CTX_STATE(this, f_58), 0))->b = b;
    ((State*)HULK_STATE_AT(HULK_CTX_STATE(this, f_58), 0))->c = c;
}
} // namespace fn_0031e080


// 0x0031e0b0 pure3d::pddiBaseContext::vfunc_75 (39 B): matches/0x0031e0b0.cpp
// sym: ?vfunc_75@pddiBaseContext@pure3d@@UAEXPAX00@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_75(void* __p0, void* __p1, void* __p2) { unsigned int * a = (unsigned int *)__p0; unsigned int * b = (unsigned int *)__p1; unsigned int * c = (unsigned int *)__p2;

    *a = *(unsigned*)HULK_STATE_AT(*(void**)&this->f_58, 0x18);
    *b = *(unsigned*)HULK_STATE_AT(*(void**)&this->f_58, 0x1c);
    *c = *(unsigned*)HULK_STATE_AT(*(void**)&this->f_58, 0x20);
}


// 0x0031e0e0 pure3d::pddiBaseContext::vfunc_76 (13 B): matches/0x0031e0e0.cpp
// sym: ?vfunc_76@pddiBaseContext@pure3d@@UAEXK@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_76(unsigned long x) {
    *(unsigned long*)HULK_STATE_AT(*(void**)&this->f_4c, 0x14) = x;
}


// 0x0031e0f0 pure3d::pddiBaseContext::vfunc_77 (7 B): matches/0x0031e0f0.cpp
// sym: ?vfunc_77@pddiBaseContext@pure3d@@UAEHXZ
 // namespace pure3d
int pure3d::pddiBaseContext::vfunc_77() {
    return ((Inner_31e0f0*)HULK_STATE_AT(*(void**)&this->f_4c, 0))->value;
}


// 0x0031e100 pure3d::pddiBaseContext::vfunc_78 (13 B): matches/0x0031e100.cpp
// sym: ?vfunc_78@pddiBaseContext@pure3d@@UAEXI@Z
void pure3d::pddiBaseContext::vfunc_78(unsigned int __p0) { unsigned char value = (unsigned char)__p0;

    *(unsigned char*)HULK_STATE_AT(*(void**)&this->f_54, 4) = value;
}


// 0x0031e110 pure3d::pddiBaseContext::vfunc_79 (7 B): matches/0x0031e110.cpp
// sym: ?vfunc_79@pddiBaseContext@pure3d@@UAE_NXZ
bool pure3d::pddiBaseContext::vfunc_79() {
    return *((bool*)HULK_STATE_AT(*(void**)&this->f_54, 4));
}


// 0x0031e120 pure3d::pddiBaseContext::vfunc_80 (33 B): matches/0x0031e120.cpp [wrapped: conflict: pddiBaseContext]
// sym: ?vfunc_80@pddiBaseContext@fn_0031e120@@QAEXHHH@Z
namespace fn_0031e120 {
class pddiRenderContext {
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
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
};
class pddiBaseContext : public pddiRenderContext {
  public:
    struct Data {
        char pad[8];
        int a, b, c;
    };
    void vfunc_80(int, int, int);
};
// (x64t2) the fog state f_54 through gen's context (HULK_STATE_AT: its words behind the vftable)
void pddiBaseContext::vfunc_80(int a, int b, int c) {
    ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_54), 0))->b = b;
    ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_54), 0))->c = c;
    ((Data*)HULK_STATE_AT(HULK_CTX_STATE(this, f_54), 0))->a = a;
}
} // namespace fn_0031e120


// 0x0031e150 pure3d::pddiBaseContext::vfunc_81 (39 B): matches/0x0031e150.cpp
// sym: ?vfunc_81@pddiBaseContext@pure3d@@UAEXPAX00@Z
void pure3d::pddiBaseContext::vfunc_81(void* __p0, void* __p1, void* __p2) { unsigned int * a = (unsigned int *)__p0; unsigned int * b = (unsigned int *)__p1; unsigned int * c = (unsigned int *)__p2;

    *a = *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_54, 8);
    *b = *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_54, 12);
    *c = *(unsigned int*)HULK_STATE_AT(*(void**)&this->f_54, 16);
}


// 0x0031e180 pure3d::pddiBaseContext::vfunc_82 (19 B): matches/0x0031e180.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?vfunc_82@pddiBaseContext@fn_0031e180@@UAEHH@Z
namespace fn_0031e180 {
class pddiBaseContext {
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
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual int vfunc_82(int index);
    char pad[0x9c - 4];
    float values[1];
};

int pddiBaseContext::vfunc_82(int index) {
    return (int)(__int64)values[index];
}
} // namespace fn_0031e180


// 0x0031e1a0 pure3d::pddiBaseContext::vfunc_83 (14 B): matches/0x0031e1a0.cpp
// sym: ?vfunc_83@pddiBaseContext@pure3d@@UAEMH@Z
 // namespace pure3d
hulk_freg pure3d::pddiBaseContext::vfunc_83(int i) {
    return (*(float (*)[1])&this->f_9c)[i];
}


// 0x0031e1b0 pure3d::pddiBaseContext::vfunc_85 (13 B): matches/0x0031e1b0.cpp
// sym: ?vfunc_85@pddiBaseContext@pure3d@@UAEXE@Z
 // namespace pure3d
void pure3d::pddiBaseContext::vfunc_85(unsigned char x) {
    this->f_148 = x;
}


// 0x0031e1c0 pure3d::pddiBaseContext::vfunc_86 (7 B): matches/0x0031e1c0.cpp
// sym: ?vfunc_86@pddiBaseContext@pure3d@@UAEEXZ
 // namespace pure3d
unsigned char pure3d::pddiBaseContext::vfunc_86() {
    return (*(char (*)[324])&this->f_04)[0x148 - 4];
}

namespace fn_fc049dac {

// 0x0031e1f0 FUN_0031e1f0 (25 B): matches/0x0031e1f0.cpp
// sym: _FUN_0031e1f0
// data: gThing_31e1f0 = DAT_005554ac
extern "C" void FUN_0031e1f0(int a, int b) {
    if ((*(Thing_31e1f0**)&DAT_005554ac))
        (*(Thing_31e1f0**)&DAT_005554ac)->Call(a, b);
}


// 0x0031e210 FUN_0031e210 (21 B): matches/0x0031e210.cpp
// sym: _FUN_0031e210
extern "C" void FUN_0031e210(hulk_intptr x) {
    if ((*(Obj_31e210**)&DAT_005554ac))
        (*(Obj_31e210**)&DAT_005554ac)->f1(x);
}

} // namespace fn_fc049dac

// 0x0031e230 pure3d::pddiDevice::vfunc_13 (12 B): matches/0x0031e230.cpp
// sym: ?vfunc_13@pddiDevice@pure3d@@UAEXH@Z
// data: g_value_31e230 = DAT_005554a8
void pure3d::pddiDevice::vfunc_13(int __p0) { u32_31e230 value = (u32_31e230)__p0;

    (*(u32_31e230*)&DAT_005554a8) = value;
}

// 0x0031e2d0 switchD_00321eb8::default (24 B): not yet verified

// 0x0031e2f0 pure3d::pddiBaseContext::vfunc_90 (14 B): matches/0x0031e2f0.cpp
// sym: ?vfunc_90@pddiBaseContext@pure3d@@UAE_NH@Z
 // namespace pure3d
bool pure3d::pddiBaseContext::vfunc_90(int p) {
    bool r = (p == 0x100);
    return r;
}

namespace fn_fc049dac {

// 0x0031e330 FUN_0031e330 (17 B): matches/0x0031e330.cpp
// sym: ?f@pddiStack_31e330@fn_fc049dac@@QAEXXZ
void pddiStack_31e330::f() {
    int x = value;
    vptr = &stackVftable;
    thunk(x);
}


// 0x0031e440 pure3d::pddiStack<math::Matrix>::vfunc_0 (44 B): matches/0x0031e440.cpp
// sym: ?vfunc_0@pddiStack@fn_fc049dac@@UAEPAU12@E@Z
pddiStack* pddiStack::vfunc_0(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&stack_vftable;
    thunk_FUN_00267090(field_c);
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x0031e490 FUN_0031e490 (3 B): matches/0x0031e490.cpp
// sym: ?Get@Obj_31e490@fn_fc049dac@@QAEPAV12@XZ
Obj_31e490* Obj_31e490::Get() {
    return this;
}


// 0x0031e500 FUN_0031e500 (160 B): matches/0x0031e500.cpp
// sym: ?f@pddiBaseContext_31e500@fn_fc049dac@@QAEXXZ
void pddiBaseContext_31e500::f() {
    Ref_31e500* a = m10;
    vptr = g_a_31e500;
    a->Release();
    mc->Release();
    for (int i = 0; i < 5; i++)
        if (arr[i])
            delete arr[i];
    if (m34)
        delete m34;
    if (m38)
        delete m38;
    if (m3c)
        delete m3c;
    if (m40)
        delete m40;
    if (m44)
        delete m44;
    Big_31e500* p = m144;
    if (p) {
        p->Fin();
        operator delete(p);
    }
    vptr = g_b_31e500;
    Fin();
}

} // namespace fn_fc049dac

// 0x0031e5a0 pure3d::pddiBaseContext::vfunc_94 (3 B): matches/0x0031e5a0.cpp
// sym: ?vfunc_94@pddiBaseContext@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::pddiBaseContext::vfunc_94(int a) {
    (void)a;
}


// 0x0031e5b0 pure3d::pddiBaseContext::vfunc_95 (3 B): matches/0x0031e5b0.cpp
// sym: ?vfunc_95@pddiBaseContext@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::pddiBaseContext::vfunc_95(int a) {
    (void)a;
}


// 0x0031e5c0 pure3d::pddiBaseContext::vfunc_96 (3 B): matches/0x0031e5c0.cpp
// sym: ?vfunc_96@pddiBaseContext@pure3d@@UAEXII@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::pddiBaseContext::vfunc_96(unsigned int __p0, unsigned int __p1) { int a = (int)__p0; int b = (int)__p1;
}


// 0x0031e5d0 pure3d::pddiBaseContext::vfunc_97 (3 B): matches/0x0031e5d0.cpp
// sym: ?vfunc_97@pddiBaseContext@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::pddiBaseContext::vfunc_97(int a, int b) {}

namespace fn_fc049dac {

// 0x0031e5e0 pure3d::pddiBaseContext::vfunc_91 (1 B): matches/0x0031e5e0.cpp
// sym: ?FUN_0031e5e0@fn_fc049dac@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0031e5e0() {}


// 0x0031e5f0 pure3d::pddiBaseContext::vfunc_92 (5 B): matches/0x0031e5f0.cpp
// sym: ?vfunc_0@pddiBaseContext_31e5f0@fn_fc049dac@@UAEHH@Z
// Same code shape as 0x00049c80 (propagated; names are from that function)
int pddiBaseContext_31e5f0::vfunc_0(int) {
    return 0;
}

} // namespace fn_fc049dac

// 0x0031e600 pure3d::pddiBaseContext::vfunc_98 (5 B): matches/0x0031e600.cpp
// sym: ?vfunc_98@pddiBaseContext@pure3d@@UAEHPAXH@Z
// Same code shape as 0x0026fe10 (propagated; names are from that function)
 // namespace core
int pure3d::pddiBaseContext::vfunc_98(void* __p0, int ) {
    return 0;
}


// 0x0031e610 pure3d::pddiBaseContext::vfunc_100 (509 B): equivalent/0x0031e610.cpp [wrapped: conflict: pure3d::pddiBaseContext; pure3d::pddiMatrixStack; pure3d::pddiStack]
// sym: ?vfunc_100@pddiBaseContext@pure3d@fn_0031e610@@QAEXXZ
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_0031e610 {
// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 20/20)
// pure3d::pddiBaseContext::vfunc_100 @ 0x0031e610
void* __cdecl FUN_0008d690(unsigned int);

namespace math { struct Matrix { char data[64]; void FUN_0022b980(); }; }
// (x64t2) the stacks' vftables stored by address (a local class's own vftable would be the 64-bit link's stub) and the
// stacks kept in gen's pddiBaseContext (f_20..f_30)
extern "C" char DAT_004327b0[];  // pure3d::pddiStack<math::Matrix>
extern "C" char DAT_004327c0[];  // pure3d::pddiMatrixStack
namespace pure3d {
template<class T> struct pddiStack { void* vftable; int capacity; int top; T* data; };
struct pddiMatrixStack : pddiStack<math::Matrix> { };
struct pddiBaseContext { void vfunc_100(); };
void pddiBaseContext::vfunc_100() {
 ::pure3d::pddiBaseContext* g=(::pure3d::pddiBaseContext*)this;
 for(int s=0;s<5;++s) {
  void* memory=FUN_0008d690((int)sizeof(pddiStack<math::Matrix>));
  pddiMatrixStack* stack=0;
  if(memory) {
   pddiStack<math::Matrix>* base=(pddiStack<math::Matrix>*)memory;
   base->vftable=DAT_004327b0;
   math::Matrix* data=(math::Matrix*)FUN_0008d690(s==0?2048:128);
   base->data=data; base->top=0; base->capacity=s==0?32:2;
   stack=(pddiMatrixStack*)memory;
   stack->vftable=DAT_004327c0;
   int i=0;
   do { stack->data[i].FUN_0022b980(); ++i; } while(i<stack->capacity);
  }
  (&g->f_20)[s]=stack;
 }
}
}
} // namespace fn_0031e610


// 0x0031e810 pure3d::pddiBaseContext::vfunc_15 (43 B): equivalent/0x0031e810.cpp [wrapped: conflict: pure3d::pddiBaseContext]
// sym: ?vfunc_15@pddiBaseContext@pure3d@fn_0031e810@@UAEXH@Z
namespace fn_0031e810 {
// STATUS: equivalent (tools/equiv.py level 3: 2936 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_15 @ 0x0031e810
namespace pure3d {
struct MatrixEntry { char pad[8]; int index; unsigned char* data; };
class pddiBaseContext {
public:
  virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
  virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
  virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
  virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
  virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
  virtual void vfunc_15(int slot);
  char pad[0x1c]; MatrixEntry* entries[1];
};
void pddiBaseContext::vfunc_15(int slot) {
  MatrixEntry* entry = entries[slot];
  int next = entry->index + 1;
  unsigned char* destination = entry->data + next * 64;
  entry->index = next;
  unsigned int* dst = (unsigned int*)destination;
  unsigned int* src = (unsigned int*)(destination - 64);
  for (int i = 0; i < 16; ++i) dst[i] = src[i];
}
}
} // namespace fn_0031e810


// 0x0031e840 pure3d::pddiBaseContext::vfunc_16 (23 B): matches/0x0031e840.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?vfunc_16@pddiBaseContext@fn_0031e840@@UAEXH@Z
namespace fn_0031e840 {
class pddiBaseContext {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void vfunc_16(int);
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual void a64();
    virtual void a65();
    virtual void a66();
    virtual void a67();
    virtual void a68();
    virtual void a69();
    virtual void a70();
    virtual void a71();
    virtual void a72();
    virtual void a73();
    virtual void a74();
    virtual void a75();
    virtual void a76();
    virtual void a77();
    virtual void a78();
    virtual void a79();
    virtual void a80();
    virtual void a81();
    virtual void a82();
    virtual void a83();
    virtual void a84();
    virtual void a85();
    virtual void a86();
    virtual void a87();
    virtual void a88();
    virtual void a89();
    virtual void a90();
    virtual void a91();
    virtual void a92();
    virtual void a93();
    virtual void a94();
    virtual void a95();
    virtual void a96();
    virtual void a97();
    virtual void a98();
    virtual void a99();
    virtual void a100();
    virtual void a101();
    virtual void a102();
    virtual void a103();
    virtual void a104();
    virtual void a105();
    virtual void a106();
    virtual void a107();
    virtual void tail(int);
    int pad[7];
    int* arr[1];
};
void pddiBaseContext::vfunc_16(int i) {
    --arr[i][2];
    tail(i);
}
} // namespace fn_0031e840


// 0x0031e860 pure3d::pddiBaseContext::vfunc_18 (22 B): matches/0x0031e860.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?vfunc_18@pddiBaseContext@fn_0031e860@@UAEHH@Z
namespace fn_0031e860 {
struct Item_31e860 {
    int a;
    int b;
    int c;
    int d;
};
class pddiBaseContext {
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
    virtual int vfunc_18(int);
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
    char pad[0x1c];
    Item_31e860* items[1];
};
int pddiBaseContext::vfunc_18(int index) {
    Item_31e860* p = items[index];
    return p->c * 64 + p->d;
}
} // namespace fn_0031e860


// 0x0031e880 pure3d::pddiBaseContext::vfunc_21 (78 B): equivalent/0x0031e880.cpp [wrapped: conflict: pure3d::pddiBaseContext]
// sym: ?vfunc_21@pddiBaseContext@pure3d@fn_0031e880@@UAEXH@Z
namespace fn_0031e880 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_21 @ 0x0031e880
struct Matrix { unsigned int words[16]; void FUN_0022b980(); };
struct MatrixStack_31e880 { char pad[8]; unsigned int depth; Matrix* matrices; };
namespace pure3d {
struct pddiBaseContext {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(int index);
virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79(); virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); virtual void vfunc_88(); virtual void vfunc_89(); virtual void vfunc_90(); virtual void vfunc_91(); virtual void vfunc_92(); virtual void vfunc_93(); virtual void vfunc_94(); virtual void vfunc_95(); virtual void vfunc_96(); virtual void vfunc_97(); virtual void vfunc_98(); virtual void vfunc_99(); virtual void vfunc_100(); virtual void vfunc_101(); virtual void vfunc_102(); virtual void vfunc_103(); virtual void vfunc_104(); virtual void vfunc_105(); virtual void vfunc_106(); virtual void vfunc_107(); virtual void vfunc_108(int index);
char pad[28]; MatrixStack_31e880* stacks[1];
};
void pddiBaseContext::vfunc_21(int index) {
MatrixStack_31e880* stack = stacks[index];
++stack->depth;
Matrix* destination = &stack->matrices[stack->depth];
unsigned int* source = (destination - 1)->words;
for (int i=0;i<16;++i) destination->words[i]=source[i];
stack = stacks[index];
stack->matrices[stack->depth].FUN_0022b980();
vfunc_108(index);
}
}
} // namespace fn_0031e880


// 0x0031e8d0 pure3d::pddiBaseContext::vfunc_22 (82 B): equivalent/0x0031e8d0.cpp [wrapped: macros]
// sym: ?vfunc_22@pddiBaseContext@pure3d@fn_0031e8d0@@UAEXHPBUMatrix@23@@Z
namespace fn_0031e8d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_22 @ 0x0031e8d0
namespace pure3d {
struct Matrix { unsigned int words[16]; };
struct MatrixStack { char pad[8]; unsigned int index; Matrix* data; };
struct pddiBaseContext {
#define V(n) virtual void vfunc_##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21)
virtual void vfunc_22(int which, const Matrix* matrix);
V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
virtual void vfunc_108(int which);
char pad[28]; MatrixStack* stacks[4];
};
void pddiBaseContext::vfunc_22(int which, const Matrix* matrix) {
 MatrixStack* stack = stacks[which];
 unsigned int index = ++stack->index;
 unsigned int* destination = stack->data[index].words;
 const unsigned int* source = destination - 16;
 for (int i=0; i<16; ++i) destination[i] = source[i];
 stack = stacks[which];
 destination = stack->data[stack->index].words;
 for (int j=0; j<16; ++j) destination[j] = matrix->words[j];
 vfunc_108(which);
}
}
} // namespace fn_0031e8d0
#undef V

namespace fn_fc049dac {

// 0x0031e930 pure3d::pddiBaseContext::vfunc_23 (118 B): matches/0x0031e930.cpp
// sym: ?Push@pddiBaseContext_31e930@fn_fc049dac@@QAEXHPAX@Z
void pddiBaseContext_31e930::Push(int w, void* a) {
    Stk* s = stk[w];
    s->top++;
    s->data[s->top] = s->data[s->top - 1];
    s = stk[w];
    Mat_31e930 local;
    ((owners::Matrix_22ca90 *)&local)->FUN_0022ca90((const owners::Matrix_22ca90 *)a, (const owners::Matrix_22ca90 *)(Mat_31e930 *)(&s->data[s->top]));
    s->data[s->top] = local;
    Upd(w);
}

} // namespace fn_fc049dac

// 0x0031e9b0 pure3d::pddiBaseContext::vfunc_88 (183 B): matches/0x0031e9b0.cpp
// sym: ?vfunc_88@pddiBaseContext@pure3d@@UAEXE@Z
void pure3d::pddiBaseContext::vfunc_88(unsigned char mask) {
    if (mask & 1) {
        (*(Stack_31e9b0 * *)&this->f_38)->top--;
        (*(StateBase * *)&this->f_4c) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_38)->data + (*(Stack_31e9b0 * *)&this->f_38)->top * (int)sizeof(StateA_31f290));
        (*(StateBase * *)&this->f_4c)->Restore(this);
    }
    if (mask & 2) {
        (*(Stack_31e9b0 * *)&this->f_34)->top--;
        (*(StateBase * *)&this->f_48) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_34)->data + (*(Stack_31e9b0 * *)&this->f_34)->top * (int)sizeof(StateB_31f290));
        (*(StateBase * *)&this->f_48)->Restore(this);
    }
    if (mask & 4) {
        (*(Stack_31e9b0 * *)&this->f_3c)->top--;
        (*(StateBase * *)&this->f_50) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_3c)->data + (*(Stack_31e9b0 * *)&this->f_3c)->top * (int)sizeof(StateC));
        (*(StateBase * *)&this->f_50)->Restore(this);
    }
    if (mask & 8) {
        (*(Stack_31e9b0 * *)&this->f_40)->top--;
        (*(StateBase * *)&this->f_54) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_40)->data + (*(Stack_31e9b0 * *)&this->f_40)->top * (int)sizeof(StateD));
        (*(StateBase * *)&this->f_54)->Restore(this);
    }
    if (mask & 0x10) {
        (*(Stack_31e9b0 * *)&this->f_44)->top--;
        (*(StateBase * *)&this->f_58) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_44)->data + (*(Stack_31e9b0 * *)&this->f_44)->top * (int)sizeof(StateE));
        (*(StateBase * *)&this->f_58)->Restore(this);
    }
}


// 0x0031ea80 pure3d::pddiExtMemRegistration::vfunc_0 (31 B): matches/0x0031ea80.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0031ea80@@UAEPAV123@E@Z
namespace fn_0031ea80 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtension_31ea80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtension_31ea80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031ea80


// 0x0031eab0 FUN_0031eab0 (93 B): matches/0x0031eab0.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4C_31eab0@fn_0031eab0@@QAEAAV01@ABV01@@Z
namespace fn_0031eab0 {
struct Four_31eab0 {
    int x_31eab0, y, z, w;
};
class C_31eab0 {
  public:
    void* v;   // the vftable (a pddiViewState: the assignment copies the fields after it)
    int a, b, c, d;
    Four_31eab0 e;
    Four_31eab0 f;
    C_31eab0& operator=(const C_31eab0&);
};
C_31eab0& C_31eab0::operator=(const C_31eab0& x_31eab0) {
    a = x_31eab0.a;
    b = x_31eab0.b;
    c = x_31eab0.c;
    d = x_31eab0.d;
    e = x_31eab0.e;
    f = x_31eab0.f;
    return *this;
}
} // namespace fn_0031eab0


// 0x0031eb70 FUN_0031eb70 (183 B): matches/0x0031eb70.cpp
// sym: ?FUN_0031eb70@Obj_31eb70@owners@@QAEXPBU12@@Z
void owners::Obj_31eb70::FUN_0031eb70(const owners::Obj_31eb70* s) {
    for (int i = 0; i < 8; i++)
        memcpy(block[i], s->block[i], 0x7c);
    tail[0] = s->tail[0];
    tail[1] = s->tail[1];
}


// 0x0031ecc0 pure3d::pddiMatrixStack::vfunc_0 (30 B): matches/0x0031ecc0.cpp
// sym: ??_GpddiMatrixStack@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::pddiMatrixStack::~pddiMatrixStack() {}


// 0x0031ece0 pure3d::pddiBaseContext::vfunc_3 (30 B): matches/0x0031ece0.cpp
// sym: ??_GpddiBaseContext@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::pddiBaseContext::~pddiBaseContext() {}


// 0x0031ed10 pure3d::_pddiExtMemRegistration::vfunc_1 (12 B): matches/0x0031ed10.cpp
// sym: ?vfunc_1@_pddiExtMemRegistration@pure3d@@UAEXH@Z
// Same code shape as 0x0031e230 (propagated; names are from that function)
// data: g_value_31ed10 = DAT_005554ac
void pure3d::_pddiExtMemRegistration::vfunc_1(int __p0) { u32_31ed10 value = (u32_31ed10)__p0;

    (*(u32_31ed10*)&DAT_005554ac) = value;
}


// 0x0031ed20 pure3d::_pddiExtMemRegistration::vfunc_0 (31 B): matches/0x0031ed20.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0031ed20@@UAEPAV123@E@Z
namespace fn_0031ed20 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtMemRegistration_31ed20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtMemRegistration_31ed20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031ed20


// 0x0031ed40 FUN_0031ed40 (102 B): equivalent/0x0031ed40.cpp [wrapped: conflict: pure3d::pddiStack; pure3d::pddiViewState]
// sym: ??0?$pddiStack@UpddiViewState@pure3d@fn_0031ed40@@@pure3d@fn_0031ed40@@QAE@H@Z
namespace fn_0031ed40 {
// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 6/6)
// FUN_0031ed40 @ 0x0031ed40
void* __cdecl FUN_0008d690(unsigned int size);
// the vftables, stored by address (a local class's own vftable would be the 64-bit link's stub)
extern "C" char DAT_00432998[];  // pure3d::pddiViewState
extern "C" char DAT_004329cc[];  // pure3d::pddiStack<pure3d::pddiViewState>

namespace pure3d {
struct pddiViewState {
    void* vftable;
    char data[0x30];
    pddiViewState() { vftable = DAT_00432998; }
};
template<class T> struct pddiStack {
    void* vftable;
    int capacity;
    int depth;
    T* items;
    pddiStack(int count);
};
template<> pddiStack<pddiViewState>::pddiStack(int count) {
    HULK_SIZE32(pddiViewState, 0x34);
    vftable = DAT_004329cc;
    pddiViewState* storage = (pddiViewState*)FUN_0008d690((unsigned int)count * sizeof(pddiViewState));
    if (storage && (int)((unsigned int)count - 1) >= 0) {
        unsigned int remaining = (unsigned int)count;
        pddiViewState* current = storage;
        do {
            new (current) pddiViewState;
            ++current;
        } while (--remaining);
    }
    capacity = count;
    items = storage;
    depth = 0;
}
}
} // namespace fn_0031ed40


// 0x0031edb0 pure3d::pddiStack<pure3d::pddiViewState>::vfunc_0 (44 B): matches/0x0031edb0.cpp [wrapped: same definition as 0x0031e440 in this TU]
// sym: ?vfunc_0@pddiStack@fn_0031edb0@@UAEPAU12@E@Z
namespace fn_0031edb0 {
// Same code shape as 0x0031e440 (propagated; names are from that function)
struct pddiStack {
    virtual pddiStack* vfunc_0(unsigned char);
    char pad[8];
    void* field_c;
};
extern int stack_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
pddiStack* pddiStack::vfunc_0(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&stack_vftable;
    thunk_FUN_00267090(field_c);
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031edb0


// 0x0031ee00 FUN_0031ee00 (102 B): matches/0x0031ee00.cpp [wrapped: conflict: pure3d::pddiRenderState; pure3d::pddiStack]
// sym: ??0?$pddiStack@VpddiRenderState@pure3d@fn_0031ee00@@@pure3d@fn_0031ee00@@QAE@H@Z
namespace fn_0031ee00 {
// the vftables, stored by address (a local class's own vftable would be the 64-bit link's stub)
extern "C" char DAT_004329a0[];  // pure3d::pddiRenderState
extern "C" char DAT_004329d4[];  // pure3d::pddiStack<pure3d::pddiRenderState>
namespace pure3d {
class pddiRenderState {
  public:
    pddiRenderState() { vftable = DAT_004329a0; }
    void* vftable;
    char p[0x18];
};
template <class T> class pddiStack {
  public:
    void* vftable;
    int n;
    int top;
    T* arr;
    pddiStack(int cnt);
};
void* FUN_0008d690(int sz);
template <class T> pddiStack<T>::pddiStack(int cnt) {
    HULK_SIZE32(T, 0x1c);
    vftable = DAT_004329d4;
    T* a = (T*)FUN_0008d690(cnt * (int)sizeof(T));
    T* b;
    if (a) {
        T* q = a;
        for (int i = cnt - 1; i >= 0; i--) {
            ((pddiRenderState*)q)->pddiRenderState::pddiRenderState();
            q++;
        }
        b = a;
    } else
        b = 0;
    n = cnt;
    arr = b;
    top = 0;
}
template pddiStack<pddiRenderState>::pddiStack(int);
} // namespace pure3d
} // namespace fn_0031ee00


// 0x0031ee70 pure3d::pddiStack<pure3d::pddiRenderState>::vfunc_0 (44 B): matches/0x0031ee70.cpp [wrapped: same definition as 0x0031e440 in this TU]
// sym: ?vfunc_0@pddiStack@fn_0031ee70@@UAEPAU12@E@Z
namespace fn_0031ee70 {
// Same code shape as 0x0031e440 (propagated; names are from that function)
struct pddiStack {
    virtual pddiStack* vfunc_0(unsigned char);
    char pad[8];
    void* field_c;
};
extern int stack_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
pddiStack* pddiStack::vfunc_0(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&stack_vftable;
    thunk_FUN_00267090(field_c);
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031ee70


// 0x0031eef0 FUN_0031eef0 (116 B): equivalent/0x0031eef0.cpp [wrapped: conflict: pure3d::pddiLightingState; pure3d::pddiStack]
// sym: ??0?$pddiStack@VpddiLightingState@pure3d@fn_0031eef0@@@pure3d@fn_0031eef0@@QAE@H@Z
namespace fn_0031eef0 {
// STATUS: equivalent (tools/equiv.py level 3: 2752 inputs, branch coverage 6/6; --wine 590 inputs)
// FUN_0031eef0 @ 0x0031eef0
void* __cdecl FUN_0008d690(unsigned int size);
void __stdcall FUN_00011520(void* array, unsigned int elementSize, int count, void* ctor);
// a light's constructor (0x0031e490, returns the light; thiscall: the element is the first argument), which the
// vector-constructor helper 0x00011520 calls on each of a lighting state's 8 lights
void* __fastcall FUN_0031e490(void* light);
// the vftables, stored by address (a local class's own vftable would be the 64-bit link's stub)
extern "C" char DAT_004329a8[];  // pure3d::pddiLightingState
extern "C" char DAT_004329dc[];  // pure3d::pddiStack<pure3d::pddiLightingState>


namespace pure3d {
class pddiLightingState {
public:
    void* vftable;
    char lights[0x3e0];
    char tail[8];
    pddiLightingState() { vftable = DAT_004329a8; FUN_00011520(lights, 0x7c, 8, (void*)&FUN_0031e490); }
};
template<class T> class pddiStack {
public:
    void* vftable;
    int capacity;
    int depth;
    T* items;
    pddiStack(int count);
};
template<> pddiStack<pddiLightingState>::pddiStack(int count)
{
    HULK_SIZE32(pddiLightingState, 0x3ec);
    vftable = DAT_004329dc;
    pddiLightingState* storage = (pddiLightingState*)FUN_0008d690((unsigned int)count * sizeof(pddiLightingState));
    if (storage && (int)((unsigned int)count - 1) >= 0) {
        unsigned int remaining = (unsigned int)count;
        pddiLightingState* current = storage;
        do {
            new (current) pddiLightingState;
            ++current;
        } while (--remaining);
    }
    capacity = count;
    items = storage;
    depth = 0;
}
}
} // namespace fn_0031eef0


// 0x0031ef70 pure3d::pddiStack<pure3d::pddiLightingState>::vfunc_0 (44 B): matches/0x0031ef70.cpp [wrapped: same definition as 0x0031e440 in this TU]
// sym: ?vfunc_0@pddiStack@fn_0031ef70@@UAEPAU12@E@Z
namespace fn_0031ef70 {
// Same code shape as 0x0031e440 (propagated; names are from that function)
struct pddiStack {
    virtual pddiStack* vfunc_0(unsigned char);
    char pad[8];
    void* field_c;
};
extern int stack_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
pddiStack* pddiStack::vfunc_0(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&stack_vftable;
    thunk_FUN_00267090(field_c);
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031ef70


// 0x0031efd0 FUN_0031efd0 (102 B): equivalent/0x0031efd0.cpp [wrapped: conflict: pure3d::pddiFogState; pure3d::pddiStack]
// sym: ??0?$pddiStack@VpddiFogState@pure3d@fn_0031efd0@@@pure3d@fn_0031efd0@@QAE@H@Z
namespace fn_0031efd0 {
// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 6/6)
// FUN_0031efd0 @ 0x0031efd0
void* __cdecl FUN_0008d690(unsigned int size);
// the vftables, stored by address (a local class's own vftable would be the 64-bit link's stub)
extern "C" char DAT_004329b0[];  // pure3d::pddiFogState
extern "C" char DAT_004329e4[];  // pure3d::pddiStack<pure3d::pddiFogState>

namespace pure3d {
class pddiFogState {
public:
 void* vftable;
 char data[16];
 pddiFogState() { vftable = DAT_004329b0; }
};
template<class T> class pddiStack {
public:
 void* vftable;
 int capacity;
 int count;
 T* entries;
 pddiStack(int n);
};
template<> pddiStack<pddiFogState>::pddiStack(int n) {
 HULK_SIZE32(pddiFogState, 20);
 vftable = DAT_004329e4;
 pddiFogState* memory = (pddiFogState*)::FUN_0008d690((unsigned int)n * sizeof(pddiFogState));
 if (memory && (int)((unsigned int)n - 1u) >= 0) {
  unsigned int remaining = (unsigned int)n;
  pddiFogState* item = memory;
  do {
   new (item) pddiFogState;
   ++item;
  } while (--remaining);
 }
 capacity = n;
 entries = memory;
 count = 0;
}
}
} // namespace fn_0031efd0


// 0x0031f040 pure3d::pddiStack<pure3d::pddiFogState>::vfunc_0 (44 B): matches/0x0031f040.cpp [wrapped: same definition as 0x0031e440 in this TU]
// sym: ?vfunc_0@pddiStack@fn_0031f040@@UAEPAU12@E@Z
namespace fn_0031f040 {
// Same code shape as 0x0031e440 (propagated; names are from that function)
struct pddiStack {
    virtual pddiStack* vfunc_0(unsigned char);
    char pad[8];
    void* field_c;
};
extern int stack_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
pddiStack* pddiStack::vfunc_0(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&stack_vftable;
    thunk_FUN_00267090(field_c);
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031f040


// 0x0031f0a0 FUN_0031f0a0 (102 B): equivalent/0x0031f0a0.cpp [wrapped: conflict: pure3d::pddiStack; pure3d::pddiStencilState]
// sym: ??0?$pddiStack@VpddiStencilState@pure3d@fn_0031f0a0@@@pure3d@fn_0031f0a0@@QAE@H@Z
namespace fn_0031f0a0 {
// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 6/6)
// FUN_0031f0a0 @ 0x0031f0a0
void* __cdecl FUN_0008d690(unsigned int bytes);
// the vftables, stored by address (a local class's own vftable would be the 64-bit link's stub)
extern "C" char DAT_004329b8[];  // pure3d::pddiStencilState
extern "C" char DAT_004329ec[];  // pure3d::pddiStack<pure3d::pddiStencilState>
namespace pure3d {
class pddiStencilState {
public:
 void* vftable;
 char data[32];
 pddiStencilState() { vftable = DAT_004329b8; }
};
template<class T> class pddiStack {
public:
 void* vftable;
 int count;
 int top;
 T* entries;
 pddiStack(int n);
};
}
template<> pure3d::pddiStack<pure3d::pddiStencilState>::pddiStack(int n) {
 HULK_SIZE32(pddiStencilState, 36);
 vftable = DAT_004329ec;
 pddiStencilState* p = (pddiStencilState*)FUN_0008d690((unsigned int)n * sizeof(pddiStencilState));
 if (p && (int)((unsigned int)n-1)>=0) {
  unsigned int i=0;
  do { p[i].pddiStencilState::pddiStencilState(); ++i; } while (i!=(unsigned int)n);
 }
 count=n;
 entries=p;
 top=0;
}
} // namespace fn_0031f0a0


// 0x0031f110 pure3d::pddiStack<pure3d::pddiStencilState>::vfunc_0 (44 B): matches/0x0031f110.cpp [wrapped: same definition as 0x0031e440 in this TU]
// sym: ?vfunc_0@pddiStack@fn_0031f110@@UAEPAU12@E@Z
namespace fn_0031f110 {
// Same code shape as 0x0031e440 (propagated; names are from that function)
struct pddiStack {
    virtual pddiStack* vfunc_0(unsigned char);
    char pad[8];
    void* field_c;
};
extern int stack_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
pddiStack* pddiStack::vfunc_0(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&stack_vftable;
    thunk_FUN_00267090(field_c);
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031f110


// 0x0031f190 pure3d::pddiBaseContext::vfunc_101 (248 B): equivalent/0x0031f190.cpp
// sym: ?vfunc_101@pddiBaseContext@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::pddiBaseContext::vfunc_101 @ 0x0031f190
void pure3d::pddiBaseContext::vfunc_101() {
 HULK_SIZE32(StateB_31f290, 0x34); HULK_SIZE32(StateA_31f290, 0x1c); HULK_SIZE32(StateC, 0x3ec);
 HULK_SIZE32(StateD, 20); HULK_SIZE32(StateE, 36);
 StackA* aa = (StackA*)FUN_0008d690((int)sizeof(StackA)); if(aa) aa = aa->FUN_0031ed40(4); (*(StackA * *)&this->f_34) = aa; (*(StateB_31f290 * *)&this->f_48) = aa->data + aa->index;
 StackB* bb = (StackB*)FUN_0008d690((int)sizeof(StackB)); if(bb) bb = bb->FUN_0031ee00(4); (*(StackB * *)&this->f_38) = bb; (*(StateA_31f290 * *)&this->f_4c) = bb->data + bb->index;
 StackC* cc = (StackC*)FUN_0008d690((int)sizeof(StackC)); if(cc) cc = cc->FUN_0031eef0(4); (*(StackC * *)&this->f_3c) = cc; (*(StateC * *)&this->f_50) = cc->data + cc->index;
 StackD* dd = (StackD*)FUN_0008d690((int)sizeof(StackD)); if(dd) dd = dd->FUN_0031efd0(4); (*(StackD * *)&this->f_40) = dd; (*(StateD * *)&this->f_54) = dd->data + dd->index;
 StackE* ee = (StackE*)FUN_0008d690((int)sizeof(StackE)); if(ee) ee = ee->FUN_0031f0a0(4); (*(StackE * *)&this->f_44) = ee; (*(StateE * *)&this->f_58) = ee->data + ee->index;
}


// 0x0031f290 pure3d::pddiBaseContext::vfunc_87 (373 B): equivalent/0x0031f290.cpp
// sym: ?vfunc_87@pddiBaseContext@pure3d@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::pddiBaseContext::vfunc_87 @ 0x0031f290
void pure3d::pddiBaseContext::vfunc_87(int __p0) { unsigned char flags = (unsigned char)__p0;

    if (flags & 1) {
        (*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->top++;
        StateA_31f290* cur = &(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->items[(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->top];
        const StateA_31f290* prev = cur - 1;
        cur->a4 = prev->a4;
        cur->c8 = prev->c8;
        cur->ac = prev->ac;
        cur->c10 = prev->c10;
        cur->d14 = prev->d14;
        cur->c18 = prev->c18;
        cur->c19 = prev->c19;
        cur->c1a = prev->c1a;
        cur->c1b = prev->c1b;
        (*(StateA_31f290 * *)&this->f_4c) = &(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->items[(*(StateStack_31f290<StateA_31f290> * *)&this->f_38)->top];
    }
    if (flags & 2) {
        (*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->top++;
        StateB_31f290* cur = &(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->items[(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->top];
        cur->FUN_0031eab0(cur - 1);
        (*(StateB_31f290 * *)&this->f_48) = &(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->items[(*(StateStack_31f290<StateB_31f290> * *)&this->f_34)->top];
    }
    if (flags & 4) {
        (*(StateStack_31f290<StateC> * *)&this->f_3c)->top++;
        StateC* cur = &(*(StateStack_31f290<StateC> * *)&this->f_3c)->items[(*(StateStack_31f290<StateC> * *)&this->f_3c)->top];
        cur->FUN_0031eb70(cur - 1);
        (*(StateC * *)&this->f_50) = &(*(StateStack_31f290<StateC> * *)&this->f_3c)->items[(*(StateStack_31f290<StateC> * *)&this->f_3c)->top];
    }
    if (flags & 8) {
        (*(StateStack_31f290<StateD> * *)&this->f_40)->top++;
        StateD* cur = &(*(StateStack_31f290<StateD> * *)&this->f_40)->items[(*(StateStack_31f290<StateD> * *)&this->f_40)->top];
        const StateD* prev = cur - 1;
        cur->c4 = prev->c4;
        cur->a8 = prev->a8;
        cur->ac = prev->ac;
        cur->a10 = prev->a10;
        (*(StateD * *)&this->f_54) = &(*(StateStack_31f290<StateD> * *)&this->f_40)->items[(*(StateStack_31f290<StateD> * *)&this->f_40)->top];
    }
    if (flags & 0x10) {
        (*(StateStack_31f290<StateE> * *)&this->f_44)->top++;
        StateE* cur = &(*(StateStack_31f290<StateE> * *)&this->f_44)->items[(*(StateStack_31f290<StateE> * *)&this->f_44)->top];
        const StateE* prev = cur - 1;
        cur->c4 = prev->c4;
        cur->a8 = prev->a8;
        cur->ac = prev->ac;
        cur->a10 = prev->a10;
        cur->a14 = prev->a14;
        cur->a18 = prev->a18;
        cur->a1c = prev->a1c;
        cur->a20 = prev->a20;
        (*(StateE * *)&this->f_58) = &(*(StateStack_31f290<StateE> * *)&this->f_44)->items[(*(StateStack_31f290<StateE> * *)&this->f_44)->top];
    }
}


// 0x0031f410 FUN_0031f410 (239 B): equivalent/0x0031f410.cpp [wrapped: conflict: FUN_0008d690; pure3d::pddiBaseContext]
// sym: ??0pddiBaseContext@pure3d@fn_0031f410@@QAE@PAURef_31f410@2@0@Z
namespace fn_0031f410 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 2/2; --wine 609 inputs)
// FUN_0031f410 @ 0x0031f410
// (x64t2) the constructor writes gen's pure3d::pddiBaseContext (one layout for the context on 64-bit too): the display
// f_0c, the device f_10, the stack pointers f_14..f_58 cleared, the identity matrix at +0x5c, f_bc / f_c0, the 12 words
// at +0xfc, the helper f_144 and the flags f_148 / +0x149; the vftable stored by address (DAT_004327cc)
struct Ref_31f410 { virtual void retain(); };
struct Matrix { unsigned data[16]; };
struct Helper_31f410 { Helper_31f410* FUN_00328250(::pure3d::pddiBaseContext*); };
extern Helper_31f410* __cdecl FUN_0008d690(unsigned);
extern "C" char DAT_004327cc[];  // pure3d::pddiBaseContext
struct FUN_0031bac0 { FUN_0031bac0(); };  // pure3d::pddiObject's constructor (0x0031bac0)
namespace pure3d {
struct pddiBaseContext : FUN_0031bac0 {
// the stack set-up (0x0031e610 vfunc_100, 0x0031f190 vfunc_101) and the reset (0x0031d300 vfunc_103), called directly;
// named by address so that the native link binds them to their definitions
void FUN_0031e610(); void FUN_0031f190(); void FUN_0031d300();
pddiBaseContext(Ref_31f410*,Ref_31f410*);
};
pddiBaseContext::pddiBaseContext(Ref_31f410* a,Ref_31f410* b) {
::pure3d::pddiBaseContext* g=(::pure3d::pddiBaseContext*)this;
g->f_0c=0;*(void**)this=DAT_004327cc;g->f_10=0;*(Matrix*)g->_pad_5c=(*(Matrix*)&DAT_004c9f38);
g->f_144=0;g->f_148=0;(&g->f_148)[1]=0;
g->f_0c=a;a->retain();g->f_10=b;b->retain();
unsigned* z=(unsigned*)&g->f_14;
for(int j=0;j<(int)(((char*)&g->f_58+sizeof(g->f_58)-(char*)&g->f_14)/4);++j) z[j]=0;
FUN_0031e610();FUN_0031f190();
Helper_31f410* h=FUN_0008d690(4);g->f_144=h?h->FUN_00328250(g):0;
g->f_bc=0;g->f_c0=0;unsigned* v=(unsigned*)(g->_pad_d4+0x28);for(int k=0;k<12;++k) v[k]=0;
FUN_0031d300();
}
}
} // namespace fn_0031f410

