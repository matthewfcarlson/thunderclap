// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028f800..0x0028fbc0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fab9a868 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fab9a868 {} using namespace fn_fab9a868;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fab9a868 {
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
class Device_28f800 {
  public:
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
    virtual int slot5();
    virtual int slot6();
    virtual int slot7();
    virtual int slot8();
    virtual int slot9();
    virtual int slot10();
    virtual int slot11();
    virtual int slot12();
    virtual int slot13();
    virtual int slot14();
    virtual int slot15();
    virtual int slot16();
    virtual int slot17();
    virtual int slot18();
    virtual int slot19();
    virtual int slot20();
    virtual int slot21();
    virtual int slot22();
    virtual int slot23();
    virtual int slot24();
    virtual int slot25();
    virtual int slot26();
    virtual int slot27();
    virtual int slot28();
    virtual int slot29();
    virtual int slot30();
    virtual int slot31();
    virtual int slot32();
    virtual int slot33();
    virtual int slot34();
    virtual int slot35();
    virtual int slot36();
    virtual int slot37();
    virtual int slot38();
    virtual int slot39();
    virtual int slot40();
    virtual int slot41();
    virtual int slot42();
    virtual int slot43();
    virtual int slot44();
    virtual int slot45();
    virtual int slot46();
    virtual int slot47();
    virtual int slot48();
    virtual int slot49();
    virtual int slot50();
    virtual int slot51();
    virtual int slot52();
    virtual int slot53();
    virtual int slot54();
    virtual int slot55();
    virtual int slot56();
    virtual int slot57();
    virtual int slot58(int);
    virtual int slot59();
    virtual int slot60();
    virtual int slot61();
    virtual int slot62();
    virtual int slot63();
    virtual int slot64();
    virtual int slot65();
    virtual int slot66();
    virtual int slot67();
    virtual int slot68();
    virtual int slot69();
    virtual int slot70();
    virtual int slot71();
    virtual int slot72();
    virtual int slot73();
    virtual int slot74();
    virtual int slot75();
    virtual int slot76(int);
    virtual int slot77();
    virtual int slot78();
    virtual int slot79();
    virtual int slot80();
    virtual int slot81();
    virtual int slot82();
    virtual int slot83();
    virtual int slot84();
    virtual int slot85();
    virtual int slot86();
    virtual int slot87();
    virtual int slot88();
    virtual int slot89(int);
};
struct Source_28f800 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(Device_28f800*); };
struct Sink_28f800 { virtual void slot0(); };
struct Mat_28f800 { char data[0x40]; void FUN_0022b980(); };
struct Helper_28f800 { Helper_28f800* FUN_00293bd0(Device_28f800*); };
class Widget_28f800 {
  public:
    Widget_28f800* FUN_0028f800(Source_28f800* src, Sink_28f800* sink, Device_28f800* dev);
    void* f00;
    Helper_28f800* helper;
    void* f08;
    Mat_28f800 m0c;
    Mat_28f800 m4c;
    char pad_8c[0xcc - 0x8c];
    unsigned int color;
    float scale;
    int f_d4;
    int f_d8;
    int f_dc;
    Source_28f800* source;
    Device_28f800* device;
    Sink_28f800* sink;
    int f_ec;
    int f_f0;
    unsigned char f_f4;
};
class Obj_28f920 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_28f920 {
  public:
    char first[4];
    int value;
    char pad[0xd8];
    Obj_28f920* m0;
    Obj_28f920* m1;
    Obj_28f920* m2;
    void cleanup();
};
class A_28f9a0 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6(int);
    virtual void F7();
    virtual void F8(int);
    virtual void F9();
    virtual void F10(int);
    virtual void F11();
    virtual void F12(int);
};
class B_28f9a0 {
  public:
    virtual void G0();
    virtual void G1();
    virtual void G2();
    virtual void G3();
    virtual void G4();
    virtual void G5();
    virtual void G6();
    virtual void G7();
    virtual void G8();
    virtual void G9();
    virtual void G10();
    virtual void G11();
    virtual void G12();
    virtual void G13(int);
};
extern A_28f9a0* gA_28f9a0;
class X_28fa40 {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14(int, void*);
};
class G_28fa40 {
  public:
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
    virtual void y4();
    virtual void y5();
    virtual void y6();
    virtual void y7();
    virtual void y8();
    virtual void y9();
    virtual void y10();
    virtual void y11();
    virtual void y12();
    virtual void y13();
    virtual void y14();
    virtual void y15();
    virtual void y16();
    virtual void y17();
    virtual void y18();
    virtual void y19(void*);
};
struct Holder_28fa40 {
    X_28fa40* x;
};
struct Blk_28fa40 {
    unsigned int d[16];
};
extern G_28fa40* gG_28fa40;
struct Obj_28fa40 {
    char pad0[4];
    Holder_28fa40* h;
    char pad1[4];
    char buf1[64];
    char buf2[64];
    void f(unsigned int* a, unsigned int* b);
};
struct Source {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual int v18(int flag);
};
struct Destination {  };
struct Object {
    char pad0[4];
    Source **source;
    char pad8[0x44];
    char location[0x40];
    Destination destination;
    Destination *FUN_0028faa0();
};
class GlobalThing_28faf0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern GlobalThing_28faf0* gThing_28faf0;
class Other_28faf0 {
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
};
class Target_28faf0 {
  public:
    char pad[0xe8];
    Other_28faf0* other;
    char pad2[8];
    unsigned char flag;
    void run(bool);
};


// 0x0028f800 FUN_0028f800 (273 B): matches/0x0028f800.cpp
// sym: ?FUN_0028f800@Widget_28f800@fn_fab9a868@@QAEPAV12@PAUSource_28f800@2@PAUSink_28f800@2@PAVDevice_28f800@2@@Z
// FUN_0028f800 @ 0x0028f800
Widget_28f800* Widget_28f800::FUN_0028f800(Source_28f800* src, Sink_28f800* snk, Device_28f800* dev) {
    f00 = 0;
    f08 = 0;
    f_dc = 0;
    source = src;
    sink = snk;
    device = dev;
    src->slot0();
    sink->slot0();
    device->slot0();
    src->slot5(device);
    color = 0xff000000;
    scale = 1.0f;
    f_d4 = 0;
    device->slot76(0);
    device->slot58(1);
    m0c.FUN_0022b980();
    m4c.FUN_0022b980();
    void* mem = FUN_0008d690(4);
    helper = mem ? ((Helper_28f800*)mem)->FUN_00293bd0(device) : 0;
    f_d8 = 0;
    color = 0xff000000;
    f_ec = device->slot89(0x102);
    f_f0 = device->slot89(0x106);
    f_f4 = 0;
    return this;
}


// 0x0028f920 FUN_0028f920 (92 B): matches/0x0028f920.cpp
// sym: ?cleanup@Owner_28f920@fn_fab9a868@@QAEXXZ
void Owner_28f920::cleanup() {
    Obj_28f920* p;
    p = m1;
    if (p) {
        m1 = 0;
        p->B();
    }
    p = m2;
    if (p) {
        m2 = 0;
        p->B();
    }
    p = m0;
    if (p) {
        m0 = 0;
        p->B();
    }
    thunk(value);
}


// 0x0028f980 FUN_0028f980 (1 B): matches/0x0028f980.cpp
// sym: ?FUN_0028f980@fn_fab9a868@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0028f980() {}


// 0x0028f990 FUN_0028f990 (1 B): matches/0x0028f990.cpp
// sym: ?FUN_0028f990@fn_fab9a868@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0028f990() {}

} // namespace fn_fab9a868

// 0x0028f9a0 FUN_0028f9a0 (122 B): matches/0x0028f9a0.cpp
// sym: ?FUN_0028f9a0@X_28f9a0@owners@@QAEXXZ
void owners::X_28f9a0::FUN_0028f9a0() {
    ++refs;
    gA_28f9a0->F4();
    if (d) {
        gA_28f9a0->F6(a);
        gA_28f9a0->F8(b);
        gA_28f9a0->F10(c);
        gA_28f9a0->F12(d);
    }
    (**(*(B_28f9a0***)&DAT_0052c2ac)).G13(0);
    flag = 1;
}


// 0x0028fa30 FUN_0028fa30 (6 B): matches/0x0028fa30.cpp
// sym: ?FUN_0028fa30@X_28fa30@owners@@QAEII@Z
hulk_uintptr owners::X_28fa30::FUN_0028fa30(unsigned int arg) {
    return value;
}

namespace fn_fab9a868 {

// 0x0028fa40 FUN_0028fa40 (68 B): matches/0x0028fa40.cpp
// sym: ?f@Obj_28fa40@fn_fab9a868@@QAEXPAI0@Z
void Obj_28fa40::f(unsigned int* a, unsigned int* b) {
    *(Blk_28fa40*)(buf1) = *(Blk_28fa40*)a;
    *(Blk_28fa40*)(buf2) = *(Blk_28fa40*)b;
    Holder_28fa40* hh = h;
    X_28fa40* xx = hh->x;
    xx->x14(0, buf1);
    gG_28fa40->y19(a);
}


// 0x0028faa0 FUN_0028faa0 (37 B): equivalent/0x0028faa0.cpp
// sym: ?FUN_0028faa0@Object@fn_fab9a868@@QAEPAUDestination@2@XZ
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 0/0)
// FUN_0028faa0 @ 0x0028faa0
Destination *Object::FUN_0028faa0() {
    ((owners::Matrix_22ca90 *)&destination)->FUN_0022ca90((const owners::Matrix_22ca90 *)(hulk_uintptr)(int)((*source)->v18(0)), (const owners::Matrix_22ca90 *)location);
    return &destination;
}

} // namespace fn_fab9a868

// 0x0028fad0 FUN_0028fad0 (7 B): matches/0x0028fad0.cpp
// sym: ?FUN_0028fad0@Obj_28fad0@owners@@QAEIXZ
hulk_uintptr owners::Obj_28fad0::FUN_0028fad0() {
    return value;
}

namespace fn_fab9a868 {

// 0x0028faf0 FUN_0028faf0 (44 B): matches/0x0028faf0.cpp
// sym: ?run@Target_28faf0@fn_fab9a868@@QAEX_N@Z
void Target_28faf0::run(bool b) {
    gThing_28faf0->f5();
    flag = 0;
    if (b)
        other->f14();
}


// 0x0028fb20 FUN_0028fb20 (94 B): equivalent/0x0028fb20.cpp
// sym: _FUN_0028fb20
// STATUS: equivalent (tools/equiv.py level 3: 3096 inputs, branch coverage 14/16, incomplete)
// FUN_0028fb20 @ 0x0028fb20
extern "C" void __cdecl FUN_0028fb20(char *destination, const char *path)
{
    int length = 0;
    while (path[length] != '\0')
        ++length;

    int separator = length;
    while (separator >= 0 && path[separator] != '/' && path[separator] != '\\')
        --separator;

    int count = length - separator;
    for (int i = 0; i < count; ++i)
        destination[i] = path[separator + i + 1];
}

} // namespace fn_fab9a868
