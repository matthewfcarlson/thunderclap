// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00291dc0..0x002926d0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
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
namespace fn_f19264ac { extern "C" char DAT_0042cedc[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f19264ac {
extern "C" void* __cdecl FUN_00263ea0(unsigned int size);
} // namespace fn_f19264ac
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f19264ac {
// (x64t7) The handlers this file's 0x00291dc0 builds inline, as the words their inline constructors write and the
// game's vftables stored by address (the local classes' own virtuals were declared only, so natively every slot was
// a stub: the registry run 0x00265240 called P3DFileHandler's slot 0 into one). Natively each is allocated at its
// own size (`sizeof`), the image handlers and the loaders their constructors build at HULK_X2 (compat/ptr.h).
extern "C" char DAT_0042ce00[];   // content::P3DFileHandler's vftable
extern "C" char DAT_0042cd74[];   // pure3d::PNGHandler's
extern "C" char DAT_0042cdbc[];   // pure3d::BMPHandler's
extern "C" char DAT_0042ce14[];   // pure3d::IgnoreLoader's
struct SimpleChunkHandler_291dc0 {
    void* vftable;
    int f04;   // content::LoadObject's reference count
    int id;
    int f0c;
    int f10;
};
namespace content {
struct P3DFileHandler {
    void* vftable;
    int f04;   // content::LoadObject's reference count
    int f08;
    P3DFileHandler() { f04 = 0; vftable = (void*)DAT_0042ce00; f08 = 0; }
};
}
// pure3d::ImageHandler's words (0x002af0c0 constructs them; 0x18 bytes on the 32-bit builds)
struct ImageHandler_291dc0 {
    void* vftable;
    char pad[0x14];
    void FUN_002af0c0();
};
namespace pure3d {
struct PNGHandler : ImageHandler_291dc0 {
    PNGHandler() { FUN_002af0c0(); vftable = (void*)DAT_0042cd74; }
};
struct BMPHandler : ImageHandler_291dc0 {
    BMPHandler() { FUN_002af0c0(); vftable = (void*)DAT_0042cdbc; }
};
struct IgnoreLoader : SimpleChunkHandler_291dc0 {
    IgnoreLoader() { f04 = 0; id = 0; f0c = 0; f10 = 0; vftable = (void*)DAT_0042ce14; }
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
// (x64t3) Pure3D's context: the record is owners::X_28f9a0 (its constructor 0x0028f800 lays it out); a = the device,
// b = the render context, c = the display (were pointers after a 32-bit pad of 0xe0 bytes)
struct Object : owners::X_28f9a0 {
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
// sym: _FUN_00291dc0 @b9b8691bd7f3 @w0f67797644d1
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 62/62)
// FUN_00291dc0 @ 0x00291dc0
extern "C" void FUN_00291dc0(){
    void* mem = FUN_00263ea0(sizeof(content::P3DFileHandler));
    content::P3DFileHandler* p3d = 0;
    if (mem) p3d = new (mem) content::P3DFileHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(p3d, "p3d");
    mem = FUN_00263ea0(HULK_X2(0x18));
    pure3d::PNGHandler* png = 0;
    if (mem) png = new (mem) pure3d::PNGHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(png, "png");
    mem = FUN_00263ea0(HULK_X2(0x18));
    pure3d::BMPHandler* bmp = 0;
    if (mem) bmp = new (mem) pure3d::BMPHandler();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265240(bmp, "bmp");
    SimpleChunkHandler_291dc0* l;
    mem = FUN_00263ea0(HULK_X2(0x2c));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c29b0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10000);
    mem = FUN_00263ea0(HULK_X2(0x1c));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c25b0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19000);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_0028f280() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x11000);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1b30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x2200);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1480() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x13000);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c1930() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x14000);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c14c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x2380);
    mem = FUN_00263ea0(HULK_X2(0x1c));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002c0c40() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19001);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002955c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x22000);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002bfa30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x22002);
    mem = FUN_00263ea0(HULK_X2(0x24));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002beca0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x19005);
    mem = FUN_00263ea0(HULK_X2(0x18));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002bc3d0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x17006);
    mem = FUN_00263ea0(HULK_X2(0x18));
    l = mem ? ((Raw_291dc0*)mem)->FUN_0027b980() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x23000);
    mem = FUN_00263ea0(HULK_X2(0x2c));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b7d30() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10001);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_00299410() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x123000);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b6150() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x1001a);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b6870() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10019);
    mem = FUN_00263ea0(HULK_X2(0x18));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b68c0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x10023);
    mem = FUN_00263ea0(HULK_X2(0x24));
    l = mem ? ((Raw_291dc0*)mem)->FUN_00289e00() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121000);
    mem = FUN_00263ea0(HULK_X2(0x28));
    l = mem ? ((Raw_291dc0*)mem)->FUN_00286520() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121201);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b23a0() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x121202);
    mem = FUN_00263ea0(HULK_X2(0x3c));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002acc60() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x1580c);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_00297150() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x120100);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002aff60() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21001);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002b0f40() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21002);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_002aff20() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x21000);
    mem = FUN_00263ea0(HULK_X2(0x14));
    l = mem ? ((Raw_291dc0*)mem)->FUN_00290740() : 0;
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(l, 0x802000a);
    mem = FUN_00263ea0(sizeof(pure3d::IgnoreLoader));
    pure3d::IgnoreLoader* ign = 0;
    if (mem) ign = new (mem) pure3d::IgnoreLoader();
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x7000);
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x7001);
    (*(Registry_291dc0**)&DAT_00527c58)->FUN_00265210(ign, 0x1001d);
}

} // namespace fn_f19264ac

// 0x00292330 FUN_00292330 (93 B): equivalent/0x00292330.cpp
// sym: ?FUN_00292330@Settings_292330@owners@@QAEXXZ @c71a379c623a @w87e877429857
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
// Pure3D's owner (DAT_0052c2c4 / DAT_0052c2b0 point at it), created once: one pointer, the Pure3D object that
// 0x00292560 creates and stores (x64t5: was allocated as a 4-byte counter, which the pointer store overran natively)
int* FUN_00292410() {
    if ((*(int**)&DAT_0052c2c4) == 0) {
        Owner_292560* p = (Owner_292560*)FUN_0008d690(sizeof(Owner_292560));
        if (p != 0)
            p->object = 0;
        else
            p = 0;
        (*(Owner_292560**)&DAT_0052c2c4) = p;
        (*(Owner_292560**)&DAT_0052c2b0) = p;
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
    HULK_SIZE32(owners::X_28f9a0, 0xf8);   // (x64t3) was a literal 0xf8
    Object* allocated = (Object*)FUN_0008d690((unsigned int)sizeof(owners::X_28f9a0));
    object = allocated ? allocated->FUN_0028f800(device, context, info) : 0;
    object->FUN_0028f980();
    Object* current = object;
    (*(Object**)&DAT_0052c2b4) = current;
    (*(void**)&DAT_0052c2ac) = ((void *)((owners::X_28fa30 *)current)->FUN_0028fa30(0));
    DAT_0052c2a8 = current->context;
    (*(void**)&DAT_0052c2a0) = current->device;
    (*(void**)&DAT_0052c2a4) = current->display;
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
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_0042cedc);
    FUN_0027afd0(self);
}

} // namespace fn_f19264ac
