// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c60f0..0x001c6610 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb68dce8 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb68dce8 {} using namespace fn_fb68dce8;
namespace fn_fb68dce8 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb68dce8 {
extern "C" void* __cdecl alloc(hulk_uintptr);
class CRenderableCharacter_1c60f0 {
  public:
    CRenderableCharacter_1c60f0* Init_001c6050(int, int);
};
class Owner {
  public:
    CRenderableCharacter_1c60f0* Create(int, int);
};
typedef unsigned int U_1c61c0;
struct D {
    U_1c61c0 Fnf_002647e0(U_1c61c0* out, int a, int b, int c);
};
struct C_1c61c0 {
    char pad[0x284];
    D* member;
    U_1c61c0 g();
};
typedef float F_1c61e0;
struct O_1c61e0 {
};
struct C_1c61e0 {
    char pad[0x284];
    O_1c61e0* m;
    F_1c61e0 Run();
};
class B_1c6200 {
  public:
};
class A_1c6200 {
  public:
    char pad[0x284];
    B_1c6200* member;
    void f(void*);
};
struct Mode_1c62f0 { int FUN_000897e0(); };
struct Manager_1c62f0 {  };
} // namespace fn_fb68dce8
struct World { char pad[0x54]; Manager_1c62f0* manager; };
namespace fn_fb68dce8 {
extern "C" int __cdecl FUN_001c62c0(char *, char *);
struct Obj_1c63e0 {
    char pad[0x44];
};
class A_1c64e0 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c64e0 {
  public:
    A_1c64e0* p;
    void run();
};
class A_1c6530 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c6530 {
  public:
    A_1c6530* p;
    void run();
};
struct Inner_1c65a0 {
    void sub_001c2760();
};
struct Obj_1c65a0 {
    char pad[4];
    Obj_1c65a0* target();
};
namespace pure3d {
class NonCopyable_1c65d0 : public ::core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_1c65d0* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_1c65d0*);


// 0x001c60f0 FUN_001c60f0 (63 B): matches/0x001c60f0.cpp
// sym: ?Create@Owner@fn_fb68dce8@@QAEPAVCRenderableCharacter_1c60f0@2@HH@Z
CRenderableCharacter_1c60f0* Owner::Create(int a, int b) {
    CRenderableCharacter_1c60f0* p = (CRenderableCharacter_1c60f0*)alloc(0x18);
    if (p) {
        CRenderableCharacter_1c60f0* q = p->Init_001c6050(a, b);
        if (q) {
            ((owners::Thing_1c5f30 *)this)->FUN_001c5f30((hulk_uintptr)(CRenderableCharacter_1c60f0 *)q);
            return q;
        }
    }
    return 0;
}


// 0x001c61c0 FUN_001c61c0 (28 B): matches/0x001c61c0.cpp
// sym: ?g@C_1c61c0@fn_fb68dce8@@QAEIXZ
// Same code shape as 0x000f95e0 (propagated; names are from that function)
U_1c61c0 C_1c61c0::g() {
    U_1c61c0 local;
    member->Fnf_002647e0(&local, 1, 4, 1);
    return local;
}


// 0x001c61e0 FUN_001c61e0 (28 B): matches/0x001c61e0.cpp
// sym: ?Run@C_1c61e0@fn_fb68dce8@@QAEMXZ
F_1c61e0 C_1c61e0::Run() {
    F_1c61e0 x;
    ((owners::X_2647e0 *)m)->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    return x;
}


// 0x001c6200 FUN_001c6200 (25 B): matches/0x001c6200.cpp
// sym: ?f@A_1c6200@fn_fb68dce8@@QAEXPAX@Z
void A_1c6200::f(void* param) {
    ((owners::X_2647e0 *)member)->FUN_002647e0((hulk_intptr)param, (hulk_intptr)3, 4, (hulk_intptr)1);
}


// 0x001c62c0 FUN_001c62c0 (33 B): matches/0x001c62c0.cpp
// sym: _FUN_001c62c0
extern "C" int FUN_001c62c0(char* a, char* b) {
    int r = 0;
    for (; a < b; ++a)
        r = *a - 0x30 + r * 10;
    return r;
}


// 0x001c62f0 FUN_001c62f0 (184 B): equivalent/0x001c62f0.cpp
// sym: _FUN_001c62f0 @6bb2c820c845 @wdf84f469d52f
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 30/30)
// FUN_001c62f0 @ 0x001c62f0
extern "C" long __cdecl FUN_001c62f0(const char* text, char marker) {
 if (!text) return -1;
 if (((Mode_1c62f0 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->FUN_000897e0()) {
  if (marker != 'R') return -1;
  const char* end = text;
  while (*end) ++end;
  if ((unsigned)(end-text) < 4) return 0;
  end = text;
  while (*end) ++end;
  return atol(end-3);
 }
 const char* p=text;
 while (*p && *p != marker) ++p;
 if (!*p) return -1;
 const char* start=++p;
 if (!*p) return -1;
 while (*p && *p >= '0' && *p <= '9') ++p;
 if (p == start) return -1;
 return ((long)FUN_001c62c0((char *)(const char *)start,(char *)(const char *)p));
}


// 0x001c63e0 FUN_001c63e0 (4 B): matches/0x001c63e0.cpp
// sym: ?FUN_001c63e0@fn_fb68dce8@@YIPAXPAUObj_1c63e0@1@@Z
void* __fastcall FUN_001c63e0(Obj_1c63e0* self) {
    return (char*)self + 0x44;
}


// 0x001c64e0 FUN_001c64e0 (22 B): matches/0x001c64e0.cpp
// sym: ?run@B_1c64e0@fn_fb68dce8@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c64e0::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c6530 FUN_001c6530 (22 B): matches/0x001c6530.cpp
// sym: ?run@B_1c6530@fn_fb68dce8@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c6530::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c65a0 FUN_001c65a0 (15 B): matches/0x001c65a0.cpp
// sym: ?target@Obj_1c65a0@fn_fb68dce8@@QAEPAU12@XZ
Obj_1c65a0* Obj_1c65a0::target() {
    ((Inner_1c65a0*)((char*)this + 4))->sub_001c2760();
    return this;
}


// 0x001c65d0 content::LoadObject::vfunc_2 (31 B): matches/0x001c65d0.cpp
// sym: ?f2@NonCopyable_1c65d0@pure3d@fn_fb68dce8@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_1c65d0* pure3d::NonCopyable_1c65d0::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fb68dce8
