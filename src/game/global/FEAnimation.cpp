// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000dff00..0x000e1760 (kind game, layer game, confidence high), dominant class FEAnimation
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9d29c80 {
#define TREE_TU_END }
namespace fn_f9d29c80 {} using namespace fn_f9d29c80;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9d29c80 {
struct V {
    int x, y, z;
};
class Obj {
    char pad[8];
    V value;

  public:
    void Set(const V& v);
};
struct Item_dff70 {
    char pad[0x5c];
    unsigned char flag;
};
struct Container_dff70 {
    char pad[8];
    Item_dff70* slots[32];
    void Clear();
};
} // namespace fn_f9d29c80
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f9d29c80 {
class C_e0000 {
  public:
    void Copy(const char* src);

  private:
    char pad[0x14];
    char buf[0x20];
};
typedef unsigned __int64 U64_e0170;
} // namespace fn_f9d29c80
extern U64_e0170 __cdecl FUN_0027b020(unsigned long);
namespace fn_f9d29c80 {
class Obj_e02d0;
typedef void (Obj_e02d0::*MFn_e02d0)(int, int, int, int);
class Obj_e02d0 {
  public:
    void Dummy();
};
class ParseFunctor {
  public:
    virtual void vfunc_0(int, int);
    Obj_e02d0* mObj;
    MFn_e02d0 mFn;
    int mC;
    int mD;
};
typedef unsigned int U32_e04f0;
typedef unsigned long long U64_e04f0;
U64_e04f0 __cdecl MakeValue_0027b020(U32_e04f0);
class Obj_e0710 {
  public:
    char pad[0x34];
    float f;
    float Get();
};
struct Vec3_e0850 {
    float x, y, z;
};
class Texture {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int a, int b);
};
class Factory_e0850 {
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
    virtual Texture *vfunc_11(const char *name, int flags);
};
} // namespace fn_f9d29c80
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
    virtual int vfunc_30(Texture *tex, int a, int b, int c, int d);
    virtual int vfunc_31(int handle);
};
namespace fn_f9d29c80 {
void __cdecl FUN_000e07c0(int handle, Vec3_e0850 a, Vec3_e0850 b, int color);
struct Vec3_e09b0 { float x, y, z; };
extern int __cdecl FUN_000e0850(Vec3_e09b0 a, Vec3_e09b0 b, Vec3_e09b0 c, Vec3_e09b0 d, unsigned int e, unsigned int f);
struct Vec3_e11a0 { float x, y, z; };
void FUN_000e0e50(Vec3_e11a0 c0, Vec3_e11a0 c1, Vec3_e11a0 c2, Vec3_e11a0 c3, Vec3_e11a0 c4, Vec3_e11a0 c5, Vec3_e11a0 c6, Vec3_e11a0 c7,
                  int a, int b);
class Obj_e1440 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(int, int);
};
class FEThing_e1570 {
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
    virtual void a12(void*);
};
class FEData {
  public:
    char pad[0x4c];
    FEThing_e1570* obj;
};
struct Obj_e1590 {
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
    virtual float f();
};
struct FEAnimation_e1590 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual float a5();
    virtual void a6();
    char pad[8];
};
class ParticleObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void Update(float, int);
};
typedef float(__stdcall* TimeFn)();
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int strncmp(const char*, const char*, unsigned int);
#endif


// 0x000dff00 FUN_000dff00 (24 B): matches/0x000dff00.cpp
// sym: ?Set@Obj@fn_f9d29c80@@QAEXABUV@2@@Z
void Obj::Set(const V& v) {
    value.x = v.x;
    value.y = v.y;
    value.z = v.z;
}


// 0x000dff70 FUN_000dff70 (63 B): matches/0x000dff70.cpp
// sym: ?Clear@Container_dff70@fn_f9d29c80@@QAEXXZ
void Container_dff70::Clear() {
    int count = 8;
    Item_dff70** p = slots + 1;
    do {
        Item_dff70* a = p[-1];
        if (a)
            a->flag = 0;
        Item_dff70* b = p[0];
        if (b)
            b->flag = 0;
        Item_dff70* c = p[1];
        if (c)
            c->flag = 0;
        Item_dff70* d = p[2];
        if (d)
            d->flag = 0;
        p += 4;
        --count;
    } while (count);
}


// 0x000dffe0 FEDoAction::vfunc_2 (1 B): matches/0x000dffe0.cpp
// sym: ?FUN_000dffe0@fn_f9d29c80@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000dffe0() {}


// 0x000dfff0 FEDoAction::vfunc_3 (1 B): matches/0x000dfff0.cpp
// sym: ?FUN_000dfff0@fn_f9d29c80@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000dfff0() {}


// 0x000e0000 FUN_000e0000 (22 B): matches/0x000e0000.cpp
// sym: ?Copy@C_e0000@fn_f9d29c80@@QAEXPBD@Z
void C_e0000::Copy(const char* src) {
    strncpy(buf, src, 0x20);
}

} // namespace fn_f9d29c80

// 0x000e0020 FEDoAction::vfunc_0 (31 B): matches/0x000e0020.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e0020@@UAEPAV123@E@Z
namespace fn_000e0020 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0040bfa0[];
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
    *(void**)this = hulk_at_0040bfa0;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000e0020


// 0x000e0100 FUN_000e0100 (60 B): matches/0x000e0100.cpp
// sym: ?FUN_000e0100@Obj_e0100@owners@@QAEXXZ
// data: negativeOne = DAT_003f3388
void owners::Obj_e0100::FUN_000e0100() {
    if (a > DAT_003f3388 && b > DAT_003f3388) {
        flag = a <= b ? 1 : 0;
    }
}


// 0x000e0170 FUN_000e0170 (26 B): matches/0x000e0170.cpp
// sym: ?FUN_000e0170@C_e0170@owners@@QAEXK@Z
void owners::C_e0170::FUN_000e0170(unsigned long x) {
    value = FUN_0027b020(x);
}

namespace fn_f9d29c80 {

// 0x000e02d0 FEThingsBase::ParseFunctor::vfunc_0 (29 B): matches/0x000e02d0.cpp
// sym: ?vfunc_0@ParseFunctor@fn_f9d29c80@@UAEXHH@Z
void ParseFunctor::vfunc_0(int a, int b) {
    MFn_e02d0 fn = mFn;
    (mObj->*fn)(a, mC, mD, b);
}

} // namespace fn_f9d29c80

// 0x000e0300 FUN_000e0300 (33 B): matches/0x000e0300.cpp
// sym: ?FUN_000e0300@C_e0300@owners@@QAEXHHH@Z
void owners::C_e0300::FUN_000e0300(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
}


// 0x000e0360 FUN_000e0360 (33 B): matches/0x000e0360.cpp
// sym: ?FUN_000e0360@C_e0360@owners@@QAEXHHH@Z
void owners::C_e0360::FUN_000e0360(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
}


// 0x000e03c0 FUN_000e03c0 (63 B): matches/0x000e03c0.cpp
// sym: ?FUN_000e03c0@Obj_e03c0@owners@@QAEXIIIII@Z
void owners::Obj_e03c0::FUN_000e03c0(unsigned x, unsigned y, unsigned z, unsigned w, unsigned v) {
    a = x;
    b = y;
    flag = 1;
    c = ((z | 0xffffff00) << 8 | w) << 8 | v;
}


// 0x000e0440 FUN_000e0440 (15 B): matches/0x000e0440.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_000e0440@@QAEPAHPAH@Z
namespace fn_000e0440 {
class Obj {
    char pad[0x1850];

  public:
    int value;
    int* Get(int* out);
};
int* Obj::Get(int* out) {
    *out = value;
    return out;
}
} // namespace fn_000e0440

namespace fn_f9d29c80 {

// 0x000e04b0 FEObject::vfunc_4 (1 B): matches/0x000e04b0.cpp
// sym: ?FUN_000e04b0@fn_f9d29c80@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000e04b0() {}


// 0x000e04c0 FEObject::vfunc_5 (1 B): matches/0x000e04c0.cpp
// sym: ?FUN_000e04c0@fn_f9d29c80@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000e04c0() {}

} // namespace fn_f9d29c80

// 0x000e04f0 FUN_000e04f0 (32 B): matches/0x000e04f0.cpp
// sym: ?FUN_000e04f0@Obj_e04f0@owners@@QAEXI@Z
void owners::Obj_e04f0::FUN_000e04f0(hulk_uintptr x) {
    value = MakeValue_0027b020(((U32_e04f0)x));
}

namespace fn_f9d29c80 {

// 0x000e0710 FUN_000e0710 (4 B): matches/0x000e0710.cpp
// sym: ?Get@Obj_e0710@fn_f9d29c80@@QAEMXZ
float Obj_e0710::Get() {
    return f;
}

} // namespace fn_f9d29c80

// 0x000e07c0 FUN_000e07c0 (129 B): equivalent/0x000e07c0.cpp [wrapped: macros]
// sym: ?FUN_000e07c0@fn_000e07c0@@YAXPAUState_e07c0@1@IIIIIII@Z @a1c78fe426f4 @wd1d84d1f6c15
namespace fn_000e07c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2966 inputs, branch coverage 0/0; Wine build 600 inputs, 0/0)
// FUN_000e07c0 @ 0x000e07c0
struct Triple_e07c0 { unsigned x,y,z; };
struct State_e07c0 { char pad[8]; Triple_e07c0* position; unsigned reserved; unsigned* value; };
// FUN_0008ef00 is Stream::FUN_0008ef00 (thiscall, no stack arguments). The original passes the state in ecx: `mov ecx,
// esi; call`, then `mov ecx, esi; jmp` (the tail jump leaves this function's frame words on the stack). MSVC mode is
// proven with the register note and the frame words spelled out; the Wine build (clang) calls the member, so the
// state really goes in ecx (wine_conv_check check 9 listed this call).
#if defined(__clang__)
struct Stream_e07c0 { void FUN_0008ef00(); };
#else
// equiv-conv: FUN_0008ef00 ecx
void __cdecl FUN_0008ef00(State_e07c0*, ...);
#endif
// equiv-conv: FUN_000e07c0 esi stack stack stack stack stack stack stack
void __cdecl FUN_000e07c0(State_e07c0* state, unsigned x1, unsigned y1, unsigned z1, unsigned x2, unsigned y2, unsigned z2, unsigned value) {
 Triple_e07c0* p=state->position;
 p->x=x1; p->z=z1; p->y=y1;
 *state->value=value;
 #if defined(__clang__)
 ((Stream_e07c0*)state)->FUN_0008ef00();
 #else
 FUN_0008ef00(state);
 #endif
 p=state->position;
 p->x=x2; p->z=z2; p->y=y2;
 *state->value=value;
 #if defined(__clang__)
 ((Stream_e07c0*)state)->FUN_0008ef00();
 #else
 FUN_0008ef00(state,x1,y1,z1,x1,y1,z1,value);
 #endif
 volatile unsigned barrier=0;
}
} // namespace fn_000e07c0

namespace fn_f9d29c80 {

// 0x000e0850 FUN_000e0850 (342 B): equivalent/0x000e0850.cpp
// sym: ?FUN_000e0850@fn_f9d29c80@@YAHUVec3_e0850@1@000HH@Z @2918b102ef5c @w93789e367f2a
// STATUS: equivalent (tools/equiv.py level 3: 13927 inputs, branch coverage 4/4)
// FUN_000e0850 @ 0x000e0850
// FUN_000e0850 @ 0x000e0850
// FUN_000e0850 @ 0x000e0850
// equiv-conv: FUN_000e07c0 esi stack stack stack
int __cdecl FUN_000e0850(Vec3_e0850 p0, Vec3_e0850 p1, Vec3_e0850 p2, Vec3_e0850 p3, int color, int arg)
{
    if ((*(Texture**)&DAT_004de954) == 0) {
        (*(Texture**)&DAT_004de954) = (*(Factory_e0850**)&DAT_0052c2a0)->vfunc_11("simple", 0);
        (*(Texture**)&DAT_004de954)->vfunc_0();
        (*(Texture**)&DAT_004de954)->vfunc_6(0x444d4c42, 1);
    }

    int handle = DAT_0052c2a8->vfunc_30((*(Texture**)&DAT_004de954), arg, 0x2020, 8, 0);
    if (handle) {
        FUN_000e07c0(handle, p0, p1, color);
        FUN_000e07c0(handle, p1, p3, color);
        FUN_000e07c0(handle, p3, p2, color);
        FUN_000e07c0(handle, p2, p0, color);
    }
    return DAT_0052c2a8->vfunc_31(handle);
}


// 0x000e09b0 FUN_000e09b0 (213 B): equivalent/0x000e09b0.cpp
// sym: _FUN_000e09b0 @d2fdd12c9135 @w3a0cff773ebc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e09b0 @ 0x000e09b0
extern "C" int __cdecl FUN_000e09b0(float x1, float y1, float z1, float x2, float y2, float z2, unsigned int e, unsigned int f)
{
    Vec3_e09b0 a = { x1, y1, 0.0f };
    Vec3_e09b0 b = { x2, y1, 0.0f };
    Vec3_e09b0 c = { x1, y2, 0.0f };
    Vec3_e09b0 d = { x2, y2, 0.0f };
    return FUN_000e0850(a, b, c, d, e, f);
}

} // namespace fn_f9d29c80

// 0x000e0a90 FUN_000e0a90 (548 B): equivalent/0x000e0a90.cpp [wrapped: conflict: Gfx]
// sym: _FUN_000e0a90 @a00b8cf52dd1 @w07f34d7ac5cd
namespace fn_000e0a90 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000e0a90 @ 0x000e0a90
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

struct Vertices {
    void FUN_0008ef00();
    char pad0[8];
    float *pos;
    char pad1[4];
    unsigned int *color;
};
struct Surface_e0a90 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(unsigned int tag, int flag);
};
struct Gfx {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual Vertices *vfn30(Surface_e0a90 *s, int a, int b, int c, int d);
    virtual void vfn31(Vertices *v);
};


// equiv-conv: FUN_000e0a90 edx stack stack stack stack stack
extern "C" void FUN_000e0a90(int a4, float w, float h, int unused, float d, unsigned int color)
{
    float x0 = w * -0.5f;
    float y1 = h * 0.5f;
    float x1 = w * 0.5f;
    float y0 = h * -0.5f;
    float ix0 = x0 - d;
    float iy1 = y1 + d;
    float ix1 = x1 + d;
    float iy0 = y0 - d;
    float xs[10];
    float ys[10];
    xs[0] = x0;  ys[0] = y1;
    xs[1] = ix0; ys[1] = iy1;
    xs[2] = x1;  ys[2] = y1;
    xs[3] = ix1; ys[3] = iy1;
    xs[4] = x1;  ys[4] = y0;
    xs[5] = ix1; ys[5] = iy0;
    xs[6] = x0;  ys[6] = y0;
    xs[7] = ix0; ys[7] = iy0;
    xs[8] = x0;  ys[8] = y1;
    xs[9] = ix0; ys[9] = iy1;
    Vertices *v = DAT_0052c2a8->vfn30((*(Surface_e0a90**)&DAT_004de954), a4, 0x2020, 10, 0);
    if (v) {
        for (int i = 0; i < 10; i++) {
            float *p = v->pos;
            p[0] = xs[i];
            p[1] = ys[i];
            p[2] = 0.0f;
            unsigned int *c = v->color;
            *c = color;
            v->FUN_0008ef00();
        }
    }
    DAT_0052c2a8->vfn31(v);
}
} // namespace fn_000e0a90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000e0cc0 FUN_000e0cc0 (388 B): equivalent/0x000e0cc0.cpp [wrapped: conflict: Gfx]
// sym: _FUN_000e0cc0 @0710b0ce4e62 @w8dbd62d38ce9
namespace fn_000e0cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_000e0cc0 @ 0x000e0cc0
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

struct Vertices {
    void FUN_0008ef00();
    char pad0[8];
    float *pos;
    char pad1[4];
    unsigned int *color;
};
struct Surface_e0cc0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(unsigned int tag, int flag);
};
struct Factory_e0cc0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual Surface_e0cc0 *vfn11(const char *name, int flag);
};
struct Gfx {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual Vertices *vfn30(Surface_e0cc0 *s, int a, int b, int c, int d);
    virtual void vfn31(Vertices *v);
};


extern "C" void FUN_000e0cc0(float w, float h, int unused, unsigned int color, int a4)
{
    if ((*(Surface_e0cc0**)&DAT_004de954) == 0) {
        (*(Surface_e0cc0**)&DAT_004de954) = (*(Factory_e0cc0**)&DAT_0052c2a0)->vfn11("simple", 0);
        (*(Surface_e0cc0**)&DAT_004de954)->vfn0();
        (*(Surface_e0cc0**)&DAT_004de954)->vfn6(0x444d4c42, 1);
    }
    float x0 = w * -0.5f;
    float y1 = h * 0.5f;
    float x1 = w * 0.5f;
    float y0 = h * -0.5f;
    float xs[6];
    float ys[6];
    xs[0] = x0; ys[0] = y0;
    xs[1] = x0; ys[1] = y1;
    xs[2] = x1; ys[2] = y1;
    xs[3] = x0; ys[3] = y0;
    xs[4] = x1; ys[4] = y1;
    xs[5] = x1; ys[5] = y0;
    Vertices *v = DAT_0052c2a8->vfn30((*(Surface_e0cc0**)&DAT_004de954), a4, 0x2020, 6, 0);
    if (v) {
        for (int i = 0; i < 6; i++) {
            float *p = v->pos;
            p[0] = xs[i];
            p[1] = ys[i];
            p[2] = 0.0f;
            unsigned int *c = v->color;
            *c = color;
            v->FUN_0008ef00();
        }
    }
    DAT_0052c2a8->vfn31(v);
}
} // namespace fn_000e0cc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000e0e50 FUN_000e0e50 (838 B): equivalent/0x000e0e50.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_000e0e50@fn_000e0e50@@YAXUVec3_e0e50@1@0000000HH@Z @6b4ad0b0b8af @wcd3948504124
namespace fn_000e0e50 {
// STATUS: equivalent (tools/equiv.py level 3: 8493 inputs, branch coverage 4/4)
// FUN_000e0e50 @ 0x000e0e50
// FUN_000e0e50 @ 0x000e0e50
// FUN_000e0e50 @ 0x000e0e50
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

struct Vec3_e0e50 {
    float x, y, z;
};

class Texture {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int a, int b);
};

class Factory_e0e50 {
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
    virtual Texture *vfunc_11(const char *name, int flags);
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
    virtual int vfunc_30(Texture *tex, int a, int b, int c, int d);
    virtual void vfunc_31(int handle);
};


// equiv-conv: FUN_000e07c0 esi stack stack stack
void __cdecl FUN_000e07c0(int handle, Vec3_e0e50 a, Vec3_e0e50 b, int color);

/* Draws the 12 edges of a box given its 8 corners in debug lines. */
void __cdecl FUN_000e0e50(Vec3_e0e50 c0, Vec3_e0e50 c1, Vec3_e0e50 c2, Vec3_e0e50 c3,
                          Vec3_e0e50 c4, Vec3_e0e50 c5, Vec3_e0e50 c6, Vec3_e0e50 c7, int color, int arg)
{
    if ((*(Texture**)&DAT_004de954) == 0) {
        (*(Texture**)&DAT_004de954) = (*(Factory_e0e50**)&DAT_0052c2a0)->vfunc_11("simple", 0);
        (*(Texture**)&DAT_004de954)->vfunc_0();
        (*(Texture**)&DAT_004de954)->vfunc_6(0x444d4c42, 1);
    }

    int handle = DAT_0052c2a8->vfunc_30((*(Texture**)&DAT_004de954), arg, 0x2020, 0x18, 0);
    if (handle) {
        FUN_000e07c0(handle, c0, c1, color);
        FUN_000e07c0(handle, c1, c3, color);
        FUN_000e07c0(handle, c3, c2, color);
        FUN_000e07c0(handle, c2, c0, color);
        FUN_000e07c0(handle, c4, c5, color);
        FUN_000e07c0(handle, c5, c7, color);
        FUN_000e07c0(handle, c7, c6, color);
        FUN_000e07c0(handle, c6, c4, color);
        FUN_000e07c0(handle, c0, c4, color);
        FUN_000e07c0(handle, c1, c5, color);
        FUN_000e07c0(handle, c2, c6, color);
        FUN_000e07c0(handle, c3, c7, color);
    }
    DAT_0052c2a8->vfunc_31(handle);
}
} // namespace fn_000e0e50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9d29c80 {

// 0x000e11a0 FUN_000e11a0 (445 B): equivalent/0x000e11a0.cpp
// sym: ?FUN_000e11a0@fn_f9d29c80@@YAXUVec3_e11a0@1@HH@Z @db6c46893536 @wfca4b8d11cfb
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000e11a0 @ 0x000e11a0
void FUN_000e11a0(Vec3_e11a0 extent, int a, int b)
{
    float hx = extent.x * 0.5f;
    float hy = extent.y * 0.5f;
    float hz = extent.z * 0.5f;
    Vec3_e11a0 c0 = { -hx,  hy, -hz };
    Vec3_e11a0 c1 = {  hx,  hy, -hz };
    Vec3_e11a0 c2 = { -hx, -hy, -hz };
    Vec3_e11a0 c3 = {  hx, -hy, -hz };
    Vec3_e11a0 c4 = { -hx,  hy,  hz };
    Vec3_e11a0 c5 = {  hx,  hy,  hz };
    Vec3_e11a0 c6 = { -hx, -hy,  hz };
    Vec3_e11a0 c7 = {  hx, -hy,  hz };
    FUN_000e0e50(c0, c1, c2, c3, c4, c5, c6, c7, a, b);
}

} // namespace fn_f9d29c80

// 0x000e1360 IValueChangedSender::vfunc_0 (40 B): matches/0x000e1360.cpp [wrapped: conflict: IValueChangedSender]
// sym: ?vfunc_0@IValueChangedSender@fn_000e1360@@UAEXXZ
namespace fn_000e1360 {
class IValueChangedSender;
class Listener {
  public:
    virtual void f();
    virtual void Changed(IValueChangedSender*);
};
class IValueChangedSender {
  public:
    virtual void vfunc_0();
    Listener* listeners[4];
};
void IValueChangedSender::vfunc_0() {
    for (int i = 0; i < 4; ++i) {
        if (listeners[i])
            listeners[i]->Changed(this);
    }
}
} // namespace fn_000e1360


// 0x000e13c0 FUN_000e13c0 (120 B): equivalent/0x000e13c0.cpp [wrapped: conflict: FEAnimation]
// sym: ??0FEAnimation@fn_000e13c0@@QAE@HPBD@Z @48df339f5b5c @w16d80406fbaa
namespace fn_000e13c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_000e13c0 @ 0x000e13c0
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);

class FEAnimation {
public:
    virtual void* v0_000f1160(char);
    char* name;
    int f08;
    int f0c;
    int f10;
    Matrix matrix;
    float scale;
    int f58;
    char f5c;
    FEAnimation(int arg, const char* text);
};

FEAnimation::FEAnimation(int arg, const char* text) {
    name = 0;
    f08 = arg;
    scale = 1.0f;
    f10 = 0;
    matrix.FUN_0022b980();
    f58 = 0;
    if (text != 0) {
        unsigned int len = 0;
        while (text[len] != 0)
            len++;
        len++;
        char* copy = (char*)FUN_0008d6d0(len);
        name = copy;
        const char* src = text;
        char c;
        do {
            c = *src++;
            *copy++ = c;
        } while (c != 0);
    }
    f0c = 0;
    f5c = 0;
}
} // namespace fn_000e13c0


// 0x000e1440 FEAnimation::vfunc_4 (21 B): matches/0x000e1440.cpp
// sym: ?vfunc_4@FEAnimation@@UAEXH@Z
void FEAnimation::vfunc_4(hulk_intptr ) {
    if ((*(Obj_e1440 * *)&this->f_0c))
        (*(Obj_e1440 * *)&this->f_0c)->g(0, 0);
}


// 0x000e1460 FEAnimation::vfunc_5 (7 B): matches/0x000e1460.cpp
// sym: ?vfunc_5@FEAnimation@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg FEAnimation::vfunc_5() {
    return DAT_003f32e0;
}

namespace fn_f9d29c80 {

// 0x000e1470 FEAnimation::vfunc_6 (4 B): matches/0x000e1470.cpp
// sym: ?FUN_000e1470@fn_f9d29c80@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_000e1470(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_f9d29c80

// 0x000e1480 FEAnimation::vfunc_1 (40 B): matches/0x000e1480.cpp [wrapped: conflict: FEAnimation]
// sym: ?vfunc_1@FEAnimation@fn_000e1480@@UAEXPAVAnimTarget@2@@Z
namespace fn_000e1480 {
class AnimTarget {
    char pad[0x38];

  public:
    int state;
};
class FEAnimation {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(AnimTarget* p);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();

  private:
    char pad[0xc];
    AnimTarget* target;
};
void FEAnimation::vfunc_1(AnimTarget* p) {
    AnimTarget* t = target;
    if (t) {
        if (t->state == 2) {
            t->state = 1;
        }
    }
    target = p;
}
} // namespace fn_000e1480


// 0x000e14b0 FEAnimation::vfunc_2 (88 B): equivalent/0x000e14b0.cpp [wrapped: conflict: DAT_004de948; FEAnimation]
// sym: ?vfunc_2@FEAnimation@fn_000e14b0@@UAEXXZ @1423e7b2e209 @w4a54b6c850c0
namespace fn_000e14b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 10/10)
// FEAnimation::vfunc_2 @ 0x000e14b0
class FETarget {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void SetTime(float t, int flags);
};

struct FEParent {
    char pad[0x38];
    int state;
};

extern float (__cdecl *DAT_004de948)();

class FEAnimation {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    char pad4[8];
    FETarget* target;       // 0x0c
    FEParent* parent;       // 0x10
    char pad14[0x44];
    int reverse;            // 0x58
    bool started;           // 0x5c
};

void FEAnimation::vfunc_2()
{
    if (started)
        return;
    started = true;
    if (parent && parent->state == 2 && target) {
        target->SetTime(DAT_004de948() * ((reverse == 0) * 2 - 1) * 1000.0f, 0);
    }
}
} // namespace fn_000e14b0


// 0x000e1510 FEPoseAnimation::vfunc_3 (94 B): equivalent/0x000e1510.cpp [wrapped: conflict: FEAnimation; FEPoseAnimation]
// sym: ?vfunc_3@FEPoseAnimation@fn_000e1510@@UAEXXZ @740e4911c0bc @we2e61f6f5485
namespace fn_000e1510 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 2/2)
// FEPoseAnimation::vfunc_3 @ 0x000e1510

struct Renderer {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14();
 virtual void slot15(int); virtual void slot16(int); virtual void slot17(int, void*);
};
struct PoseObject {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(int,int);
};
struct Manager { Renderer* renderer; void FUN_00293da0(int,int,int); };
struct FEAnimation { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); };
struct FEPoseAnimation : FEAnimation {
 char pad[0x14-4]; char pose[0x40]; int value; char pad2[8]; PoseObject* object;
 void vfunc_3();
};
void FEPoseAnimation::vfunc_3() {
 (*(Manager**)&DAT_0052c2ac)->renderer->slot15(0);
 (*(Manager**)&DAT_0052c2ac)->renderer->slot17(0,pose);
 int v=value;
 (*(Manager**)&DAT_0052c2ac)->FUN_00293da0(v,v,v);
 if (object) object->slot8(0,0);
 (*(Manager**)&DAT_0052c2ac)->renderer->slot16(0);
}
} // namespace fn_000e1510


// 0x000e1570 FEPoseAnimation::vfunc_4 (18 B): matches/0x000e1570.cpp
// sym: ?vfunc_4@FEPoseAnimation@@UAEXH@Z
void FEPoseAnimation::vfunc_4(hulk_intptr __p0) { void * arg = (void *)__p0;

    FEThing_e1570* p = (*(FEData * *)&this->f_0c)->obj;
    if (p)
        p->a12(arg);
}


// 0x000e1590 FEPoseAnimation::vfunc_5 (24 B): matches/0x000e1590.cpp
// sym: ?vfunc_5@FEPoseAnimation@@UAEMXZ
hulk_freg FEPoseAnimation::vfunc_5() {
    char* base = (char*)this;
    Obj_e1590* p = *(Obj_e1590**)(base + 0x0c);
    Obj_e1590* m = *(Obj_e1590**)((char*)p + 0x4c);
    float r = (*(volatile float*)&DAT_003f32e0);
    if (m)
        return m->f();
    return r;
}


// 0x000e15b0 FEParticleAnimation::vfunc_3 (94 B): equivalent/0x000e15b0.cpp [wrapped: conflict: FEParticleAnimation]
// sym: ?vfunc_3@FEParticleAnimation@fn_000e15b0@@UAEXXZ @cde66b40003e @wc626af3f84b2
namespace fn_000e15b0 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 2/2)
// FEParticleAnimation::vfunc_3 @ 0x000e15b0

struct RenderInterface {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(int); virtual void vfunc_16(int); virtual void vfunc_17(int, void*);
};
struct Particle {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(int, int);
};
struct Holder {
    RenderInterface* renderer;
    void FUN_00293da0(int, int, int);
};
class FEParticleAnimation {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    char pad04[0x10];
    char pose[0x40];
    int particleValue;
    char pad58[0xc];
    Particle* particle;
};
void FEParticleAnimation::vfunc_3() {
    (*(Holder**)&DAT_0052c2ac)->renderer->vfunc_15(0);
    (*(Holder**)&DAT_0052c2ac)->renderer->vfunc_17(0, pose);
    int value = particleValue;
    (*(Holder**)&DAT_0052c2ac)->FUN_00293da0(value, value, value);
    if (particle) particle->vfunc_8(0, 0);
    (*(Holder**)&DAT_0052c2ac)->renderer->vfunc_16(0);
}
} // namespace fn_000e15b0


// 0x000e1610 FEParticleAnimation::vfunc_2 (40 B): matches/0x000e1610.cpp [wrapped: conflict: FEParticleAnimation]
// sym: ?vfunc_2@FEParticleAnimation@fn_000e1610@@UAEXXZ
namespace fn_000e1610 {
// data: GetTime = DAT_004de948

extern "C" {
typedef float(__stdcall* TimeFn)();
}
class Part {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetTime(float, int);
};
class FEParticleAnimation {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[0x60];
    Part* particle;
};
void FEParticleAnimation::vfunc_2() {
    if (particle)
        particle->SetTime((*(TimeFn*)&DAT_004de948)() * 1000.0f, 0);
}
} // namespace fn_000e1610


// 0x000e1650 FEParticleSystem::vfunc_4 (4 B): matches/0x000e1650.cpp
// sym: ?vfunc_4@FEParticleSystem@@UAEHXZ
// Same code shape as 0x00086290 (propagated; names are from that function)
int FEParticleSystem::vfunc_4() {
    return this->f_24;
}


// 0x000e1660 FEParticleSystem::vfunc_1 (10 B): matches/0x000e1660.cpp
// sym: ?vfunc_1@FEParticleSystem@@UAEXPAX@Z
void FEParticleSystem::vfunc_1(void* __p0) { void * value = (void *)__p0;

    (*(void * *)&this->f_2c) = value;
}


// 0x000e1670 FEParticleSystem::vfunc_2 (43 B): matches/0x000e1670.cpp
// sym: ?vfunc_2@FEParticleSystem@@UAEXXZ
// data: g_timeFn = DAT_004de948
void FEParticleSystem::vfunc_2() {
    if ((*(int *)&this->f_2c)) {
        (*(ParticleObject * *)&this->f_28)->Update((*(TimeFn*)&DAT_004de948)() * 1000.0f, 0);
    }
}


// 0x000e16a0 FEParticleSystem::vfunc_3 (94 B): equivalent/0x000e16a0.cpp [wrapped: conflict: FEParticleSystem]
// sym: ?vfunc_3@FEParticleSystem@fn_000e16a0@@UAEXXZ @000bb7d0e743 @wc682a080e6fe
namespace fn_000e16a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 2/2)
// FEParticleSystem::vfunc_3 @ 0x000e16a0

struct Renderer { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(int); virtual void v16(int); virtual void v17(int, void*); }; struct Particle { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(int,int); }; struct Manager { Renderer* renderer; void FUN_00293da0(int,int,int); };  struct FEParticleSystem { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); char pad04[0x24]; Particle* particle; char pad2c[4]; char data30[0x40]; int value70; }; void FEParticleSystem::vfunc_3() { (*(Manager**)&DAT_0052c2ac)->renderer->v15(0); (*(Manager**)&DAT_0052c2ac)->renderer->v17(0,data30); int value=value70; (*(Manager**)&DAT_0052c2ac)->FUN_00293da0(value,value,value); if (particle) particle->v8(0,0); (*(Manager**)&DAT_0052c2ac)->renderer->v16(0); }
} // namespace fn_000e16a0


// 0x000e1700 FEDoAction::vfunc_4 (74 B): matches/0x000e1700.cpp
// sym: ?vfunc_4@FEDoAction@@UAE_NHHHH@Z
bool FEDoAction::vfunc_4(int a, hulk_intptr b, int c, int d) {
    if (a == this->f_04 && this->f_08 == c && this->f_0c == d) {
        if ((*(char (*)[32])&this->f_14)[0] == 0)
            return true;
        char* p = (char*)(b + 0x1734);
        if (p != 0 && strncmp(p, (*(char (*)[32])&this->f_14), 0x20) == 0)
            return true;
    }
    return false;
}

