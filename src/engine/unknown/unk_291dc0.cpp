// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00291dc0..0x002926d0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f19264ac {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f19264ac {} using namespace fn_f19264ac;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f19264ac {
extern "C" void* __cdecl FUN_00263ea0(unsigned int size);
} // namespace fn_f19264ac
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f19264ac {
class __declspec(novtable) SimpleChunkHandler_291dc0 {
  public:
    virtual void slot0();
    int f04;
    int id;
    int f0c;
    int f10;
};
class __declspec(novtable) FileLoader_291dc0 {
  public:
    virtual void slot0();
    int f04;
    int f08;
};
class __declspec(novtable) ImageHandler_291dc0 {
  public:
    virtual void slot0();
    char pad[0x14];
    void FUN_002af0c0();
    ImageHandler_291dc0() { FUN_002af0c0(); }
};
namespace content {
class P3DFileHandler : public FileLoader_291dc0 {
  public:
    P3DFileHandler() { f04 = 0; f08 = 0; }
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
}
namespace pure3d {
class PNGHandler : public ImageHandler_291dc0 {
  public:
    PNGHandler() {}
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
};
}
namespace pure3d {
class BMPHandler : public ImageHandler_291dc0 {
  public:
    BMPHandler() {}
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
};
}
namespace pure3d {
class IgnoreLoader : public SimpleChunkHandler_291dc0 {
  public:
    IgnoreLoader() { f04 = 0; id = 0; f0c = 0; f10 = 0; }
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
};
}
struct Raw_291dc0 {
    SimpleChunkHandler_291dc0* FUN_002c29b0();
    SimpleChunkHandler_291dc0* FUN_002c25b0();
    SimpleChunkHandler_291dc0* FUN_0028f280();
    SimpleChunkHandler_291dc0* FUN_002c1b30();
    SimpleChunkHandler_291dc0* FUN_002c1480();
    SimpleChunkHandler_291dc0* FUN_002c1930();
    SimpleChunkHandler_291dc0* FUN_002c14c0();
    SimpleChunkHandler_291dc0* FUN_002c0c40();
    SimpleChunkHandler_291dc0* FUN_002955c0();
    SimpleChunkHandler_291dc0* FUN_002bfa30();
    SimpleChunkHandler_291dc0* FUN_002beca0();
    SimpleChunkHandler_291dc0* FUN_002bc3d0();
    SimpleChunkHandler_291dc0* FUN_0027b980();
    SimpleChunkHandler_291dc0* FUN_002b7d30();
    SimpleChunkHandler_291dc0* FUN_00299410();
    SimpleChunkHandler_291dc0* FUN_002b6150();
    SimpleChunkHandler_291dc0* FUN_002b6870();
    SimpleChunkHandler_291dc0* FUN_002b68c0();
    SimpleChunkHandler_291dc0* FUN_00289e00();
    SimpleChunkHandler_291dc0* FUN_00286520();
    SimpleChunkHandler_291dc0* FUN_002b23a0();
    SimpleChunkHandler_291dc0* FUN_002acc60();
    SimpleChunkHandler_291dc0* FUN_00297150();
    SimpleChunkHandler_291dc0* FUN_002aff60();
    SimpleChunkHandler_291dc0* FUN_002b0f40();
    SimpleChunkHandler_291dc0* FUN_002aff20();
    SimpleChunkHandler_291dc0* FUN_00290740();
};
struct Registry_291dc0 {
    void FUN_00265210(void*, int);
    void FUN_00265240(void*, const char*);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_0027b8f0();
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
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_0028f920 {
    void FUN_0028f920();
};
extern void thunk_FUN_00267090(CCollisionAction*);
typedef unsigned long long U64_2924e0;
void __stdcall FUN_00354ce2(U64_2924e0*);
typedef unsigned long long U64_292500;
void __stdcall FUN_00354cd1(U64_292500*);
extern void* __cdecl thunk_FUN_00267090(void*);
extern "C" void __cdecl FUN_0027b1d0();
struct Context {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setWindow(void*);
};
struct Version {
    int major, minor, build;
    int unused;
    char description[256];
};
struct Device_292560 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void version(Version*);
    virtual void v5();
    virtual void v6();
    virtual Context* create(int);
    virtual void* info(Context*);
};
struct Object {
    char pad[0xe0];
    void* a;
    void* b;
    void* c;
    Object* FUN_0028f800(Device_292560*, Context*, void*);
    void FUN_0028f980();
};
extern "C" void __cdecl FUN_0028fcc0(const char*, ...);
extern void __cdecl FUN_0031ba60(int, int, Device_292560**);
extern "C" void __cdecl FUN_002c3230(Device_292560*);
extern void __cdecl FUN_002c31b0();
} // namespace fn_f19264ac
extern "C" { extern void* DAT_0052c2a8; }
namespace fn_f19264ac {
struct Owner_292560 {
    Object* object;
    Object* FUN_00292560(void*);
};
struct G_292670 {
    void X();
};
struct H {
    void A();
    void B();
};
void thunk_FUN_00267090(H*);
struct T_292670 {
    int value;
    void run(H*);
};
void __fastcall FUN_0027afd0(CEffectStopTrack*);


// 0x00291dc0 FUN_00291dc0 (1377 B): equivalent/0x00291dc0.cpp
// sym: _FUN_00291dc0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 62/62)
// FUN_00291dc0 @ 0x00291dc0
extern "C" void FUN_00291dc0(){
    void* mem = FUN_00263ea0(0xc);
    content::P3DFileHandler* p3d = 0;
    if (mem) p3d = new (mem) content::P3DFileHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(p3d, "p3d");
    mem = FUN_00263ea0(0x18);
    pure3d::PNGHandler* png = 0;
    if (mem) png = new (mem) pure3d::PNGHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(png, "png");
    mem = FUN_00263ea0(0x18);
    pure3d::BMPHandler* bmp = 0;
    if (mem) bmp = new (mem) pure3d::BMPHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(bmp, "bmp");
    SimpleChunkHandler_291dc0* l;
    mem = FUN_00263ea0(0x2c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c29b0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10000);
    mem = FUN_00263ea0(0x1c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c25b0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_0028f280() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x11000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1b30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x2200);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1480() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x13000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1930() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x14000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c14c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x2380);
    mem = FUN_00263ea0(0x1c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c0c40() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19001);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002955c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x22000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002bfa30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x22002);
    mem = FUN_00263ea0(0x24);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002beca0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19005);
    mem = FUN_00263ea0(0x18);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002bc3d0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x17006);
    mem = FUN_00263ea0(0x18);
    l = mem ? ((Raw_291dc0*)mem)->FUN_0027b980() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x23000);
    mem = FUN_00263ea0(0x2c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b7d30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10001);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00299410() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x123000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b6150() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x1001a);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b6870() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10019);
    mem = FUN_00263ea0(0x18);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b68c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10023);
    mem = FUN_00263ea0(0x24);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00289e00() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121000);
    mem = FUN_00263ea0(0x28);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00286520() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121201);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b23a0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121202);
    mem = FUN_00263ea0(0x3c);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002acc60() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x1580c);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00297150() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x120100);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002aff60() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21001);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b0f40() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21002);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_002aff20() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_291dc0*)mem)->FUN_00290740() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x802000a);
    mem = FUN_00263ea0(0x14);
    pure3d::IgnoreLoader* ign = 0;
    if (mem) ign = new (mem) pure3d::IgnoreLoader();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x7000);
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x7001);
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x1001d);
}

} // namespace fn_f19264ac

// 0x00292330 FUN_00292330 (93 B): equivalent/0x00292330.cpp
// sym: ?FUN_00292330@Settings_292330@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00292330 @ 0x00292330
void owners::Settings_292330::FUN_00292330() {
    width = 640;
    height = 480;
    depth = 32;
    format = 7;
    mode = 2;
    flags = 17;
    reserved = 0;
    option0 = 0;
    option1 = 1;
    option2 = 0;
    primaryCapacity = 0x80000;
    secondaryCapacity = 0x8000;
    tertiaryCapacity = 0x4000;
    count = 8;
    option3 = 0;
    option4 = 0;
}

namespace fn_f19264ac {

// 0x00292410 FUN_00292410 (54 B): matches/0x00292410.cpp
// sym: ?FUN_00292410@fn_f19264ac@@YAPAHXZ
// The platform's start-up counter (DAT_0052c2c4 / DAT_0052c2b0 point at one heap word), created once.
int* FUN_00292410() {
    if ((*(int**)&DAT_0052c2c4) == 0) {
        int* p = (int*)FUN_0008d690(4);
        if (p != 0)
            *p = 0;
        else
            p = 0;
        (*(int**)&DAT_0052c2c4) = p;
        (*(int**)&DAT_0052c2b0) = p;
        FUN_0027b8f0();
    }
    return (*(int**)&DAT_0052c2c4);
}


// 0x00292470 FUN_00292470 (30 B): matches/0x00292470.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f19264ac@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_0028f920*)(this))->FUN_0028f920();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x002924e0 FUN_002924e0 (23 B): matches/0x002924e0.cpp
// sym: ?FUN_002924e0@fn_f19264ac@@YA_KXZ
U64_2924e0 __cdecl FUN_002924e0(void) {
    U64_2924e0 value;
    FUN_00354ce2(&value);
    return value;
}


// 0x00292500 FUN_00292500 (23 B): matches/0x00292500.cpp
// sym: ?FUN_00292500@fn_f19264ac@@YA_KXZ
// Same code shape as 0x002924e0 (propagated; names are from that function)
U64_292500 __cdecl FUN_00292500(void) {
    U64_292500 value;
    FUN_00354cd1(&value);
    return value;
}


// 0x00292530 FUN_00292530 (34 B): matches/0x00292530.cpp
// sym: ?FUN_00292530@fn_f19264ac@@YAXXZ
// data: g_obj = DAT_0052c2c4
void FUN_00292530() {
    FUN_0027b1d0();
    if ((*(void**)&DAT_0052c2c4)) {
        thunk_FUN_00267090((*(void**)&DAT_0052c2c4));
    }
    (*(void**)&DAT_0052c2c4) = 0;
}


// 0x00292560 FUN_00292560 (262 B): matches/0x00292560.cpp
// sym: ?FUN_00292560@Owner_292560@fn_f19264ac@@QAEPAUObject@2@PAX@Z
Object* Owner_292560::FUN_00292560(void* window) {
    Device_292560* device;
    Version version;
    FUN_0028fcc0("Pure3D v%s, released %s\n", "3.19.Hairclub", "2-November-2004");
    FUN_0031ba60(18, 11, &device);
    FUN_002c3230(device);
    Context* context = device->create(0);
    context->setWindow(window);
    void* info = device->info(context);
    device->version(&version);
    FUN_0028fcc0("Context created: PDDI v%d.%d (build %d), '%s'\n", version.major, version.minor,
                 version.build, version.description);
    Object* allocated = (Object*)FUN_0008d690(0xf8);
    object = allocated ? allocated->FUN_0028f800(device, context, info) : 0;
    object->FUN_0028f980();
    Object* current = object;
    (*(Object**)&DAT_0052c2b4) = current;
    (*(void**)&DAT_0052c2ac) = ((void *)((owners::X_28fa30 *)current)->FUN_0028fa30(0));
    DAT_0052c2a8 = current->b;
    (*(void**)&DAT_0052c2a0) = current->a;
    (*(void**)&DAT_0052c2a4) = current->c;
    FUN_002c31b0();
    return object;
}


// 0x00292670 FUN_00292670 (51 B): matches/0x00292670.cpp
// sym: ?run@T_292670@fn_f19264ac@@QAEXPAUH@2@@Z
void T_292670::run(H* arg) {
    ((G_292670*)this)->X();
    arg->A();
    if (arg) {
        arg->B();
        thunk_FUN_00267090(arg);
    }
    *(int*)this = 0;
}


// 0x002926c0 FUN_002926c0 (11 B): matches/0x002926c0.cpp
// sym: @FUN_002926c0@4
// Same code shape as 0x00060920 (propagated; names are from that function)
extern "C" void __fastcall FUN_002926c0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_0027afd0(self);
}

} // namespace fn_f19264ac
