// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0031b760..0x0031c290 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dDevice
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "decls/data/records.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f2bbfa1e {
#define TREE_TU_END }
namespace fn_f2bbfa1e {} using namespace fn_f2bbfa1e;
namespace fn_f2bbfa1e {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_f2bbfa1e { extern "C" char DAT_004324a8[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_f2bbfa1e { extern "C" char DAT_0043253c[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f2bbfa1e {
extern void* pddiObject_31b760_vftable[];
class pddiObject_31b760 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class pddiDevice_31b760 : public pddiObject_31b760 {
  public:
    pddiDevice_31b760* vfunc_5(signed char flags);
};
class d3dDevice_31b790 {
  public:
    d3dDevice_31b790();
};
extern int device_vftable;
class pddiDevice_31b790 {
  public:
    d3dDevice_31b790 base;
    pddiDevice_31b790();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct d3dDisplay_31b830 {
    void* vftable;
    int field4, field8;
    int d3d;        // +0x0c the D3D object (0x0031ba00 keeps it at d3dDevice +0x10)
    void* field_10; // (x64t5) the device and the capture texture (field498) are pointers (gen/pure3d.h d3dDisplay)
    char pad14[0x58 - 0x14];
    char caps[0x434 - 0x58];
    unsigned char b434, b435, b436, b437;
    int field438;
    char mode[0x34];
    int field470, field474, field478, field47c, field480;
    float scaleX, scaleY, scaleZ;
    char pad490[8];
    void* field498;
    d3dDisplay_31b830* FUN_0031b520(int d3d);
};
struct Result_31b860 {
    void FUN_00320d30();
};
struct d3dContext_nv_31b860 {
    Result_31b860* FUN_00324e00(void*, pure3d::d3dDevice*);
};
extern pure3d::d3dContext* __cdecl FUN_0008d690(int);
struct Params_31b8a0 { int a,b,c,d,e,f,g,h; unsigned char extended; };
struct d3dTexture_31b8a0 {
 virtual void slot0();
 virtual void slot1();
 virtual int slot2();
 virtual void slot3(int);
 d3dTexture_31b8a0* FUN_00326b40(void*);
 bool FUN_003265f0(int,int,int,int,int,int,int,int);
 bool FUN_00326330(int,int,int,int,int,int,int);
};
struct Params_31b960 {
    int p0, p1, p2, p3, p4, p5, p6, p7;
};
void* Alloc(hulk_uintptr n);
} // namespace fn_f2bbfa1e
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_f2bbfa1e {
class Impl_31b960 {
  public:
    Impl_31b960(int ctx);
    void Setup(int a, int b, int c, int d, int e, int f);
    virtual void v0();
    virtual void v1();
    virtual int v2();
    virtual void v3(int del);
};
class pddiObject_31b9d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiDevice_31b9d0 : public pddiObject_31b9d0 {
  public:
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
};
extern "C" void* FUN_00327c70(void*, const char*, int);   // (x64t3) the shader factory lookup (pddiBaseShader.cpp)
extern "C" char DAT_004324e4[];
typedef unsigned int u32_31ba00;
struct d3dDevice_31ba00 {
    hulk_uintptr vftable;
    char pad4[8];
    u32_31ba00 fieldC;
    u32_31ba00 field10;
    d3dDevice_31ba00* FUN_0031ba00(hulk_uintptr d3d);  // the D3D object (Direct3D_Object, pointer-sized); kept in a 32-bit word for now
};
struct d3dDevice_nv_31ba00 {
    void FUN_0031bac0();
};
extern "C" void FUN_00328130();
extern "C" hulk_uintptr __stdcall FUN_0037d240(int);
struct d3dDevice_31ba60 {
    hulk_uintptr vftable;
    char pad4[8];
    unsigned int fieldC;
    unsigned int field10;
    d3dDevice_31ba60* FUN_0031ba00(hulk_uintptr d3d);
};
class pddiObject {
  public:
    pddiObject();
    virtual ~pddiObject();
    int a;
    int b;
};
extern void* IRefCount_vftable_31bae0;
class IRefCount_31baf0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
extern "C" char DAT_00432578[];
extern void __stdcall ReleaseResource(void*);
// pure3d::d3dPrimStream (0x0031bfa0 constructs it): the views below keep one layout, the record's pointers as pointers
// (x64t2): +4 stride, +8..+0x14 the vertex component pointers, +0x24 0x100 bytes of pending vertices, +0x124 the
// context, +0x12c the vertex buffers, +0x130 the current one, +0x150 the input, +0x154 / +0x158 the resources
class d3dPrimStream {
  public:
    hulk_intptr vtable;
    int stride;
    char* components[4];
    int f18, f1c, f20;
    char pending[0x100];
    void* owner;
    int f128;
    void** resources;
};
struct Resource_31bd30 { char pad[16]; unsigned divisor; };
struct Input_31bd30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual bool v22(); virtual void v23(); virtual void v24();
 void FUN_00327d20(unsigned);
};
struct Manager_31bd30 { Resource_31bd30* FUN_00321da0(unsigned*,unsigned,unsigned,unsigned); void FUN_00324270(Input_31bd30*); };
struct Target_31bd30 {
 virtual void v0(unsigned);
 int p04; char* p08[4]; unsigned count; unsigned zero; unsigned value;
 char p24[0x100]; Manager_31bd30* manager;
 int p128; void** p12c; void* p130; char p134[4]; unsigned kindValue; unsigned kind; unsigned flags; unsigned unknown144; unsigned mode; unsigned lowFlags; Input_31bd30* input; Resource_31bd30* existing; Resource_31bd30* resource; unsigned extra;
 void FUN_0031bd30(unsigned,unsigned,Input_31bd30*,unsigned,unsigned);
};
class A_31bf50 {
  public:
    virtual void f();
    virtual void g();
};
extern "C" int __cdecl FUN_00356734(char*, const char*, ...);
namespace XAPILIB {
void __stdcall OutputDebugStringA(const char*);
}


// 0x0031b760 pure3d::pddiDevice::vfunc_3 (36 B): matches/0x0031b760.cpp
// sym: ?vfunc_5@pddiDevice_31b760@fn_f2bbfa1e@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
pddiDevice_31b760* pddiDevice_31b760::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_004324a8);
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x0031b790 FUN_0031b790 (18 B): matches/0x0031b790.cpp
// sym: ??0pddiDevice_31b790@fn_f2bbfa1e@@QAE@XZ
pddiDevice_31b790::pddiDevice_31b790() {
    *(hulk_intptr*)this = (hulk_intptr)((int*)DAT_004324a8);
}


} // namespace fn_f2bbfa1e

// 0x0031b7d0 pure3d::d3dDevice::vfunc_4 (61 B): matches/0x0031b7d0.cpp
// sym: ?vfunc_4@d3dDevice@pure3d@@UAEXPAX@Z
// (x64t3) the device's own slot 4 (fills the caller's version record: 18, 11, build 56, "XBox Console"); was a free
// __stdcall function of the version pointer, which on 64-bit took the device itself (this) as the record and
// overwrote its vftable (the start-up's crash in 0x0028f800). The object is unused, so the 32-bit code is the same.
void pure3d::d3dDevice::vfunc_4(void* v) {
    char* p = (char*)v;
    unsigned int* q = (unsigned int*)p;
    q[3] = 10;
    q[0] = 18;
    q[1] = 11;
    q[2] = 56;
    const char* s = "XBox Console";
    char* d = p + 16;
    char c;
    do {
        c = *s;
        *(d - (int)0) = c;
        d++;
        s++;
    } while (c != 0);
}

// 0x0031b810 pure3d::d3dDevice::vfunc_5 (10 B): matches/0x0031b810.cpp
// sym: ?vfunc_5@d3dDevice@pure3d@@UAEXPAX@Z
// Same code shape as 0x00098e20 (propagated; names are from that function)
// (x64t3) the current render context (tContext's constructor 0x0028f800 passes it): a pointer, was `int`
void pure3d::d3dDevice::vfunc_5(void* x) {
    this->f_0c = (hulk_intptr)x;
}


// 0x0031b820 pure3d::d3dDevice::vfunc_6 (4 B): matches/0x0031b820.cpp
// sym: ?vfunc_6@d3dDevice@pure3d@@UAEIXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
unsigned int pure3d::d3dDevice::vfunc_6() {
    return (*(unsigned int *)&this->f_0c);
}


// 0x0031b830 pure3d::d3dDevice::vfunc_7 (41 B): matches/0x0031b830.cpp
// sym: ?vfunc_7@d3dDevice@pure3d@@UAEPAXH@Z
// pddiDevice::newDisplay: a d3dDisplay on the game's heap, built from this device's D3D object; the display or 0.
void* pure3d::d3dDevice::vfunc_7(int arg) {
    HULK_SIZE32(d3dDisplay_31b830, 0x49c);
    d3dDisplay_31b830* result = (d3dDisplay_31b830*)FUN_0008d690((unsigned int)sizeof(d3dDisplay_31b830));
    if (result)
        return result->FUN_0031b520((int)this->f_10);   // (x64t3) gen's f_10 (was a 32-bit offset)
    return 0;
}


// 0x0031b860 pure3d::d3dDevice::vfunc_8 (63 B): matches/0x0031b860.cpp
// sym: ?vfunc_8@d3dDevice@pure3d@@UAEPAXPAX@Z
// The d3dContext (gen pure3d::d3dContext): 0x00324e00 builds it on the device, 0x00320d30 finishes it.
void* pure3d::d3dDevice::vfunc_8(void* __p0) { void * p = (void *)__p0;

    pure3d::d3dContext* m = FUN_0008d690((int)sizeof(pure3d::d3dContext));
    Result_31b860* r;
    if (m)
        r = ((d3dContext_nv_31b860*)(((pure3d::d3dContext*)(m))))->FUN_00324e00(p, this);
    else
        r = 0;
    r->FUN_00320d30();
    return (void*)(r);
}


// 0x0031b8a0 pure3d::d3dDevice::vfunc_9 (184 B): equivalent/0x0031b8a0.cpp
// sym: ?vfunc_9@d3dDevice@pure3d@@UAEPAXH@Z @6b2d49eca792 @w403135b613cc
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 6/6)
// pure3d::d3dDevice::vfunc_9 @ 0x0031b8a0
void* pure3d::d3dDevice::vfunc_9(hulk_intptr __p0) { Params_31b8a0 * p = (Params_31b8a0 *)__p0;

 d3dTexture_31b8a0* s = (d3dTexture_31b8a0*)FUN_0008d690(0xf8);
 if(s) s=s->FUN_00326b40((*(void * *)&this->f_0c));
 bool ok;
 if(p->extended) ok=s->FUN_003265f0(p->a,p->b,p->c,p->d,p->e,p->f,p->g,p->h);
 else ok=s->FUN_00326330(p->a,p->b,p->d,p->e,p->f,p->g,p->h);
 if(!ok) { this->f_08=s->slot2(); s->slot3(1); return (void*)(0); }
 return (void*)(s);
}


// 0x0031b960 pure3d::d3dDevice::vfunc_10 (105 B): matches/0x0031b960.cpp
// sym: ?vfunc_10@d3dDevice@pure3d@@UAEPAXPAX@Z
void* pure3d::d3dDevice::vfunc_10(void* __p0) { Params_31b960 * p = (Params_31b960 *)__p0;

    void* m = Alloc(0x40);
    Impl_31b960* o;
    if (m)
        o = new (m) Impl_31b960(this->f_0c);
    else
        o = 0;
    o->Setup(p->p0, p->p1, 0, p->p4, p->p5, p->p7);
    this->f_08 = o->v2();
    if (this->f_08 != 1) {
        o->v3(1);
        return (void*)(0);
    }
    return (void*)(o);
}


// 0x0031b9d0 pure3d::d3dDevice::vfunc_11 (22 B): matches/0x0031b9d0.cpp
// sym: ?vfunc_11@d3dDevice@pure3d@@UAEPAXPBDH@Z
// (x64t3) pddiDevice::NewShader(name, ...): the factory's shader for the current context (gen's slot was `void (int,
// int)`; Pure3D's context keeps the result: 0x0028edb0)
void* pure3d::d3dDevice::vfunc_11(const char* a, int ) {
    return FUN_00327c70((void*)this->f_0c, a, 0);
}


// 0x0031b9f0 pure3d::d3dDevice::vfunc_12 (3 B): matches/0x0031b9f0.cpp
// sym: ?vfunc_12@d3dDevice@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::d3dDevice::vfunc_12(int a, int b) {}

namespace fn_f2bbfa1e {

// 0x0031ba00 FUN_0031ba00 (39 B): matches/0x0031ba00.cpp
// sym: ?FUN_0031ba00@d3dDevice_31ba00@fn_f2bbfa1e@@QAEPAU12@I@Z
d3dDevice_31ba00* d3dDevice_31ba00::FUN_0031ba00(hulk_uintptr d3d) {
    ((d3dDevice_nv_31ba00*)(((pure3d::d3dDevice*)(this))))->FUN_0031bac0();
    vftable = ((hulk_intptr)DAT_004324e4);
    // (x64t3) gen d3dDevice's words (the view's 32-bit offsets put them 4 bytes short of gen's on 64-bit)
    ((pure3d::d3dDevice*)this)->f_10 = (hulk_intptr)d3d;
    ((pure3d::d3dDevice*)this)->f_0c = 0;
    FUN_00328130();
    return this;
}

} // namespace fn_f2bbfa1e

// 0x0031ba30 pure3d::d3dDevice::vfunc_3 (46 B): matches/0x0031ba30.cpp [wrapped: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?f3@d3dDevice_31ba30@fn_0031ba30@@UAEPAV12@E@Z
namespace fn_0031ba30 {

extern "C" char DAT_004324a8[];
typedef unsigned char u8_31ba30;
extern "C++" void __fastcall FUN_0031bae0(void*);
extern "C++" void __cdecl thunk_FUN_00267090(void*);  // the heap's free through its `jmp` thunk
class d3dDevice_31ba30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dDevice_31ba30* f3(u8_31ba30);
};
d3dDevice_31ba30* d3dDevice_31ba30::f3(u8_31ba30 param) {
    *(void* volatile*)&DAT_005554a4 = 0;  // the device slot (a pointer word: config/data-ptrs.json)
    *(void**)this = (void*)((hulk_intptr)DAT_004324a8);
    FUN_0031bae0((void*)(this));
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031ba30

namespace fn_f2bbfa1e {

// 0x0031ba60 FUN_0031ba60 (93 B): matches/0x0031ba60.cpp
// sym: ?FUN_0031ba60@fn_f2bbfa1e@@YAHHHPAPAUd3dDevice_31ba60@1@@Z
// The pddi driver's device probe: (18, 11) is the Xbox D3D device. The wrapper is created once and kept in the slot
// DAT_005554a4 (a pointer word: config/data-ptrs.json); it is returned through `out`, a pointer.
int FUN_0031ba60(int a, int b, d3dDevice_31ba60** out) {
    if (a == 0x12 && b == 0xb) {
        d3dDevice_31ba60* value = *(d3dDevice_31ba60**)&DAT_005554a4;
        if (!value) {
            HULK_SIZE32(pure3d::d3dDevice, 0x14);   // (x64t3) gen's record (the view was 8 bytes short on 64-bit)
            d3dDevice_31ba60* p = (d3dDevice_31ba60*)FUN_0008d690((unsigned int)sizeof(pure3d::d3dDevice));
            if (p)
                value = p->FUN_0031ba00(FUN_0037d240(0));
            else
                value = 0;
            *(d3dDevice_31ba60**)&DAT_005554a4 = value;
        }
        *out = value;
        return 1;
    }
    *out = 0;
    return 100;
}


// 0x0031bac0 FUN_0031bac0 (23 B): matches/0x0031bac0.cpp
// sym: ??0pddiObject@fn_f2bbfa1e@@QAE@XZ
pddiObject::pddiObject() : a(0), b(1) {}


// 0x0031bae0 FUN_0031bae0 (7 B): matches/0x0031bae0.cpp
// sym: @FUN_0031bae0@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_0031bae0(void* self) {
    *(void**)self = ((void**)DAT_0043253c);
}

} // namespace fn_f2bbfa1e

// 0x0031baf0 pure3d::pddiObject::vfunc_0 (4 B): matches/0x0031baf0.cpp
// sym: ?vfunc_0@pddiObject@pure3d@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void pure3d::pddiObject::vfunc_0() {
    ++this->f_04;
}


// 0x0031bb00 pure3d::pddiObject::vfunc_1 (20 B): matches/0x0031bb00.cpp [wrapped: conflict: pddiObject]
// sym: ?vfunc_1@pddiObject@fn_0031bb00@@UAEXXZ
namespace fn_0031bb00 {
class pddiObject {
  public:
    virtual void f0();
    virtual void vfunc_1();
    virtual void f2();
    virtual void vfunc_3(int);
    int mRefCount;
};
void pddiObject::vfunc_1() {
    if (--mRefCount < 1)
        vfunc_3(1);
}
} // namespace fn_0031bb00

namespace fn_f2bbfa1e {

// 0x0031bb20 pure3d::pddiObject::vfunc_2 (4 B): matches/0x0031bb20.cpp
// sym: ?FUN_0031bb20@fn_f2bbfa1e@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_0031bb20(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_f2bbfa1e

// 0x0031bb30 pure3d::pddiObject::vfunc_3 (31 B): matches/0x0031bb30.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0031bb30@@UAEPAV123@E@Z
namespace fn_0031bb30 {
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
    *(void**)this = (void**)DAT_0043253c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0031bb30

namespace fn_f2bbfa1e {

// 0x0031bc30 FUN_0031bc30 (49 B): equivalent/0x0031bc30.cpp
// sym: _FUN_0031bc30 @e1b4964ddefb @wa62ba6ee471f
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 7/7)
// FUN_0031bc30 @ 0x0031bc30
// FUN_0031bc30 @ 0x0031bc30
// equiv-conv: FUN_0031bc30 eax ecx
extern "C" int FUN_0031bc30(int mode, int value) {
    switch (mode) {
    case 0: return value / 3;
    case 1: return value - 2;
    case 2: return value / 2;
    case 3: return value - 1;
    case 4: return value;
    default: return 0;
    }
}


// 0x0031bcc0 FUN_0031bcc0 (20 B): matches/0x0031bcc0.cpp
// sym: _FUN_0031bcc0
// Same code shape as 0x00232d70 (propagated; names are from that function)
// data: g0_31bcc0 = DAT_004d3678, g1_31bcc0 = DAT_004d367c
extern "C" void FUN_0031bcc0(int a, int b) {
    DAT_004d3678 = a;
    DAT_004d367c = b;
}


// 0x0031bcf0 FUN_0031bcf0 (64 B): matches/0x0031bcf0.cpp
// sym: @FUN_0031bcf0@4
// data: gCount_31bcf0 = DAT_004d367c
extern "C" void __fastcall FUN_0031bcf0(d3dPrimStream* self) {
    self->vtable = ((hulk_intptr)DAT_00432578);
    int i = 0;
    if (DAT_004d367c > 0) {
        do {
            ReleaseResource(self->resources[i]);
            ++i;
        } while (i < DAT_004d367c);
    }
    FreeArray(self->resources);
}


// 0x0031bd30 FUN_0031bd30 (267 B): equivalent/0x0031bd30.cpp
// sym: ?FUN_0031bd30@Target_31bd30@fn_f2bbfa1e@@QAEXIIPAUInput_31bd30@2@II@Z @ee0545e5d147 @w69d2a40168c0
// STATUS: equivalent (tools/equiv.py level 3: 25 inputs, branch coverage 10/10)
// FUN_0031bd30 @ 0x0031bd30
void Target_31bd30::FUN_0031bd30(unsigned k,unsigned f,Input_31bd30* obj,unsigned e,unsigned arg) {
 extra=e;
 Resource_31bd30* r=existing;
 if (!r) r=manager->FUN_00321da0(((unsigned*)&DAT_003f335c),k,f,0);
 resource=r;
 if(obj->v22()) obj->v24();
 if(flags & 0x80) manager->FUN_00324270(obj);
 if(f & 0x20) mode=1; else if(f & 0x4000) mode=(f>>15)&7; else mode=0;
 lowFlags=f&15;
 int q=(int)((*(unsigned*)&DAT_004d3678)/resource->divisor);
 count=(q/6)*6;
 kindValue=((unsigned*)&DAT_004d3650)[k]; kind=k; flags=f; value=((unsigned*)&DAT_004d3664)[k]; zero=0; input=obj;
 obj->FUN_00327d20(arg);
 v0(0);
}

} // namespace fn_f2bbfa1e

// 0x0031be40 pure3d::d3dPrimStream::vfunc_0 (263 B): equivalent/0x0031be40.cpp [wrapped: conflict: pure3d::d3dBasePrimStream; pure3d::d3dPrimStream]
// sym: ?vfunc_0@d3dPrimStream@pure3d@fn_0031be40@@UAEX_N@Z @9ae99402937e @w76280ecf5ba6
namespace fn_0031be40 {
// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 14/14)
// pure3d::d3dPrimStream::vfunc_0 @ 0x0031be40
typedef unsigned long DWORD;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif

namespace D3D8 {
char* __stdcall D3DVertexBuffer_Lock2(void*, DWORD);
}
struct ShaderInfo_31be40 {
    char pad[8];
    DWORD flags;
};
extern "C++" void __cdecl FUN_0031c230(int);
namespace pure3d {
class d3dBasePrimStream {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class d3dPrimStream : public d3dBasePrimStream {
  public:
    int stride;
    char* posPtr;
    char* normalPtr;
    char* colorPtr;
    char* uvPtr;
    char pad18[4];
    int vertCount;
    int pendingCount;
    char pending[0x100];
    void* owner;
    int f128;
    void** buffers;
    void* vbuf;
    char locked;
    char pad135[3];
    int f138, f13c, f140, f144;
    int colorCount;
    int uvCount;
    void* input;
    void* existing;
    ShaderInfo_31be40* shader;
    int total;
    virtual void vfunc_0(bool copyPending);
    virtual void vfunc_1();
};
}
void pure3d::d3dPrimStream::vfunc_0(bool copyPending) {
    char* p = D3D8::D3DVertexBuffer_Lock2(vbuf, 0);
    FUN_0031c230(0);
    locked = 1;
    if (copyPending && pendingCount > 0) {
        memcpy(p, pending, stride * pendingCount);
        p += stride * pendingCount;
        vertCount = pendingCount;
        total += pendingCount;
    } else {
        vertCount = 0;
    }
    posPtr = p;
    stride = 0xc;
    p += 0xc;
    DWORD flags = shader->flags;
    if (flags & 0x10) {
        normalPtr = p;
        stride = 0x18;
        p += 0xc;
    } else {
        normalPtr = 0;
    }
    flags = shader->flags;
    if (flags & 0x20) {
        colorPtr = p;
        stride += 4;
        p += 4;
    } else if ((flags & 0x4000) && colorCount > 0) {
        colorPtr = p;
        stride += colorCount * 4;
        p += colorCount * 4;
    } else {
        colorPtr = 0;
    }
    if (uvCount != 0) {
        uvPtr = p;
        stride += uvCount * 8;
    } else {
        uvPtr = 0;
    }
}
} // namespace fn_0031be40

namespace fn_f2bbfa1e {

// 0x0031bf50 FUN_0031bf50 (5 B): matches/0x0031bf50.cpp
// sym: ?FUN_0031bf50@fn_f2bbfa1e@@YIXPAVA_31bf50@1@@Z
// Same code shape as 0x00263e90 (propagated; names are from that function)
void __fastcall FUN_0031bf50(A_31bf50* p) {
    p->g();
}

} // namespace fn_f2bbfa1e

// 0x0031bfa0 FUN_0031bfa0 (221 B): matches/0x0031bfa0.cpp [wrapped: conflict: FUN_0008d690; pure3d::d3dPrimStream]
// sym: ??0d3dPrimStream@pure3d@fn_0031bfa0@@QAE@PAUOwner_31bfa0@2@@Z
namespace fn_0031bfa0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0031bfa0 @ 0x0031bfa0

namespace D3D8 {
void* __stdcall D3DDevice_CreateVertexBuffer2(int);
}
extern void* __cdecl FUN_0008d690(int);
extern "C++" void __cdecl FUN_0031c230(int);
// (x64t2) the display (a d3dDisplay: vftable, then words) and the context in gen's d3dContext layout (its display f_154)
struct OwnerInner {
    void* vftable;
    int f04, f08, f0c;
    int value;
};
struct Owner_31bfa0 {
    void* vftable;
    char base[sizeof(::pure3d::pddiBaseContext) - sizeof(void*)];
    int f14c;
    void* f150;
    OwnerInner* inner;
};
namespace pure3d {
class d3dPrimStream {
  public:
    d3dPrimStream(Owner_31bfa0* owner);
    void* vftable;   // stored by address (a local class's own vftable would be the 64-bit link's stub)
    int f4;
    char *f8, *fc, *f10, *f14;
    char pad18[4];
    int f1c;
    char pad20[0x124 - 0x20];
    Owner_31bfa0* owner;
    int f128;
    void** buffers;
    void* current;
    char f134;
    char pad135[3];
    int f138, f13c;
    int f140;
    int f144;
    int f148, f14c;
    void* f150;
    void* f154;
};
d3dPrimStream::d3dPrimStream(Owner_31bfa0* o) {
    vftable = DAT_00432578;
    owner = o;
    f128 = 0;
    f134 = 0;
    f1c = 0;
    f4 = 0;
    f8 = 0;
    fc = 0;
    f10 = 0;
    f14 = 0;
    f154 = 0;
    f128 = o->inner->value;
    f144 = 0;
    buffers = (void**)FUN_0008d690(DAT_004d367c * (int)sizeof(void*));
    for (int i = 0; i < DAT_004d367c; i++) {
        void** slot = &buffers[i];
        void* vb = D3D8::D3DDevice_CreateVertexBuffer2(DAT_004d3678);
        *slot = vb;
        FUN_0031c230((vb != 0) - 1 & 0x8007000e);
    }
    current = buffers[f144];
    f140 = 0;
}
} // namespace pure3d
} // namespace fn_0031bfa0


// 0x0031c080 pure3d::d3dPrimStream::vfunc_1 (248 B): equivalent/0x0031c080.cpp [wrapped: conflict: pure3d::d3dBasePrimStream; pure3d::d3dPrimStream]
// sym: ?vfunc_1@d3dPrimStream@pure3d@fn_0031c080@@UAEXXZ @22c18fe3aa93 @w644f40509d79
namespace fn_0031c080 {
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 14/14)
// pure3d::d3dPrimStream::vfunc_1 @ 0x0031c080

typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetVertexShader(DWORD);
void __stdcall D3DDevice_SetStreamSource(DWORD, void*, DWORD);
void __stdcall D3DDevice_DrawVertices(DWORD, DWORD, DWORD);
}
struct ShaderInfo_31c080 {
    char pad[0x14];
    DWORD handle;
};
struct PrimTypeInfo {
    int mul;
    int add;
};
// equiv-conv: FUN_0031bc30 eax ecx
extern "C++" int FUN_0031bc30(int shapeKind, int count);
extern "C++" void __cdecl FUN_0031c230(int);
namespace pure3d {
class d3dBasePrimStream {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class d3dPrimStream : public d3dBasePrimStream {
  public:
    DWORD stride;
    char* components[4];
    char pad18[4];
    int vertCount;
    int pendingCount;
    char pendingVerts[0x100];
    void* owner;
    int f128;
    void** buffers;
    void* curBuffer;
    char flag134;
    char pad135[0x138 - 0x134 - 1];
    int primType;
    int shapeKind;
    char pad140[0x144 - 0x140];
    int bufIndex;
    int colorCount, uvCount;
    void* input;
    void* existing;
    ShaderInfo_31c080* shader;
    int pending;
    virtual void vfunc_0();
    virtual void vfunc_1();
};
}
void pure3d::d3dPrimStream::vfunc_1() {
    if (flag134)
        flag134 = 0;
    if (vertCount > 0 && !(primType == 6 && vertCount <= 2) && !(primType == 4 && vertCount <= 1)) {
        D3D8::D3DDevice_SetVertexShader(shader->handle);
        D3D8::D3DDevice_SetStreamSource(0, curBuffer, stride);
        int prim = primType;
        int n = FUN_0031bc30(shapeKind, vertCount);
        D3D8::D3DDevice_DrawVertices(prim, 0, n * ((PrimTypeInfo*)&DAT_003f3260)[prim].mul + ((PrimTypeInfo*)&DAT_003f3260)[prim].add);
        FUN_0031c230(0);
        bufIndex++;
        if (bufIndex == DAT_004d367c)
            bufIndex = 0;
        curBuffer = buffers[bufIndex];
        int cnt = vertCount;
        vertCount = 0;
        pending -= cnt;
        return;
    }
    pending -= vertCount;
    vertCount = 0;
}
} // namespace fn_0031c080

namespace fn_f2bbfa1e {

// 0x0031c180 FUN_0031c180 (43 B): equivalent/0x0031c180.cpp
// sym: _FUN_0031c180 @da19b0721b1a @wa169a1ee46c5
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 6/6)
// FUN_0031c180 @ 0x0031c180
// equiv-conv: FUN_0031c180 eax
extern "C" unsigned int FUN_0031c180(unsigned int value) {
    switch (value) {
    case 2: case 3: case 4: case 5:
    case 0x10: case 0x11: case 0x1d: case 0x28:
        return 0x10;
    case 6: case 7: case 0x12: case 0x1e:
        return 0x20;
    case 0xb:
        return 8;
    default:
        return 0;
    }
}


// 0x0031c230 FUN_0031c230 (85 B): matches/0x0031c230.cpp
// sym: _FUN_0031c230
extern "C" void __cdecl FUN_0031c230(int code) {
    char buffer[512];
    if (code != 0) {
        FUN_00356734(buffer, DAT_0043259c, code & 0xffff, (code >> 16) & 0x1fff, (code >> 31) & 1);
        XAPILIB::OutputDebugStringA(buffer);
        XAPILIB::OutputDebugStringA(DAT_00422518);
    }
}

} // namespace fn_f2bbfa1e
