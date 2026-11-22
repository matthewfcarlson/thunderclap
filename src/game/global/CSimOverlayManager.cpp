// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d7010..0x000d7890 (kind game, layer game, confidence high), dominant class CSimOverlayManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f34eeb08 {
#define TREE_TU_END }
namespace fn_f34eeb08 {} using namespace fn_f34eeb08;
#include "game/global.h"
#include "game/script_bind.h"

// ---- declarations shared by the functions below
namespace fn_f34eeb08 {
typedef unsigned int uint_d7030;
class Helper_d7030 {
  public:
    void Run_000cae40(uint_d7030 value);
};
class Target_d7030 {
  public:
    char pad0[4];
    void* first;
    Helper_d7030* middle;
    void* third;
    void Run(uint_d7030 value);
};
class CActorManager_d70d0 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_d70d0::*MFn_d70d0)(unsigned char);
class Function_d70d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Dummy_d7150 {
  public:
    void Call(void*);
};
class Function_d71d0 {
  public:
    virtual void f0();
    virtual void f1();
};
class X_d71f0 {
  public:
    void Fna_000d3170(hulk_intptr, int, hulk_intptr);   // (decl1) passes as defined
    unsigned int Fnb_000cae60();
    void Fnc_000cae40(unsigned int);
};
class Y_d71f0 {
  public:
    char pad[4];
    unsigned char x;
    void Fna_000d40e0(hulk_intptr, hulk_intptr, hulk_intptr);   // (decl1) passes as defined
};
class Z {
  public:
    char pad[4];
    unsigned char x;
};
class A_d71f0 {
  public:
    char pad[4];
    Y_d71f0* p4;
    X_d71f0* p8;
    Z* pc;
    void f(hulk_intptr, hulk_intptr, hulk_intptr);
};
class Sub_d7250 {
  public:
    char pad[4];
    unsigned char flag;
};
class Inner_d7250 {
  public:
    unsigned Get_000cae50();
};
class Obj_d7250 {
  public:
    char pad[4];
    Sub_d7250* a;
    Inner_d7250* inner;
    Sub_d7250* b;
    void Run(unsigned bits);
};
struct Child_d72b0 {
    char pad[4];
    char flag;
    unsigned int GetFlags_000cae50();
};
struct Obj_d72b0 {
    char pad[4];
    Child_d72b0* a;
    Child_d72b0* b;
    Child_d72b0* c;
    void Update(unsigned int mask);
};
class Actor_d7380 {
  public:
    void fn(unsigned char);
};
class CActorManager_d7410 {
  public:
    void invoke(const char*);
};
class CActorManager_d7490 {
  public:
    int act();
};

} // namespace fn_f34eeb08

// 0x000d7010 CSimOverlayManager::vfunc_0 (31 B): matches/0x000d7010.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000d7010@@UAEPAV123@E@Z
namespace fn_000d7010 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0040b394[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_0040b394;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}
} // namespace fn_000d7010

namespace fn_f34eeb08 {

// 0x000d7030 FUN_000d7030 (49 B): matches/0x000d7030.cpp
// sym: ?Run@Target_d7030@fn_f34eeb08@@QAEXI@Z
void Target_d7030::Run(uint_d7030 value) {
    middle->Run_000cae40(value);
    *((byte*)first + 4) = (byte)((value >> 7) & 1);
    *((byte*)third + 4) = (byte)((value >> 8) & 1);
}

} // namespace fn_f34eeb08

// 0x000d70b0 Method1<CSimOverlayManager,void,bool>::vfunc_0 (30 B): matches/0x000d70b0.cpp
// sym: ?vfunc_0@Method1_d70b0@fn_000d70b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CSimOverlayManager, void, bool>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d70b0 {
struct Method1_d70b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_d70b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d70b0
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d70d0 Method1<CSimOverlayManager,void,bool>::vfunc_2 (21 B): matches/0x000d70d0.cpp
// sym: ?vfunc_2@Method1_d70d0@fn_000d70d0@@QAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CSimOverlayManager, void, bool>::vfunc_2`.
namespace fn_000d70d0 {
struct Method1_d70d0 : hulk_script::FunctionGenView {
    void (::CSimOverlayManager::*f_1c)(bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
#if defined(HULK_PTR64)
// (nat3) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells, and the
// instantiation's own types (the 32-bit source's propagated (const char*, int) passes them in other registers)
void Method1_d70d0::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Args_ { bool a0; };
    const Args_* a = (const Args_*)__p1;
    (((Obj_*)__p0)->*(*(void (Obj_::**)(bool))&this->f_1c))(a->a0);
}
#else
void Method1_d70d0::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_d70d0 * obj = (CActorManager_d70d0 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_d70d0 *)&this->f_1c))(*b);
}
#endif
} // namespace fn_000d70d0


// 0x000d7130 Method1<CSimOverlayManager,void,int>::vfunc_0 (30 B): matches/0x000d7130.cpp
// sym: ?vfunc_0@Method1_d7130@fn_000d7130@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CSimOverlayManager, void, int>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d7130 {
struct Method1_d7130 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_d7130::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d7130
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d7150 Method1<CSimOverlayManager,void,int>::vfunc_2 (19 B): matches/0x000d7150.cpp
// sym: ?vfunc_2@Method1_d7150@fn_000d7150@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CSimOverlayManager, void, int>::vfunc_2`.
namespace fn_000d7150 {
struct Method1_d7150 : hulk_script::FunctionGenView {
    void (::CSimOverlayManager::*f_1c)(int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
#if defined(HULK_PTR64)
// (nat3) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells, and the
// instantiation's own types (the 32-bit source's propagated (const char*, int) passes them in other registers)
void Method1_d7150::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Args_ { int a0; };
    const Args_* a = (const Args_*)__p1;
    (((Obj_*)__p0)->*(*(void (Obj_::**)(int))&this->f_1c))(a->a0);
}
#else
void Method1_d7150::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_d7150* d = (Dummy_d7150*)a;
    (d->*(*(void (Dummy_d7150::**)(void *))&this->f_1c))(*b);
}
#endif
} // namespace fn_000d7150


// 0x000d71b0 Method0<CSimOverlayManager,int>::vfunc_0 (30 B): matches/0x000d71b0.cpp
// sym: ?vfunc_0@Method0_d71b0@fn_000d71b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CSimOverlayManager, int>::~Method0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d71b0 {
struct Method0_d71b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_d71b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d71b0
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d71d0 Method0<CSimOverlayManager,int>::vfunc_2 (22 B): matches/0x000d71d0.cpp
// sym: ?vfunc_2@Method0_d71d0@fn_000d71d0@@QAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CSimOverlayManager, int>::vfunc_2`.
namespace fn_000d71d0 {
struct Method0_d71d0 : hulk_script::FunctionGenView {
    int (::CSimOverlayManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_d71d0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)&this->f_1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
} // namespace fn_000d71d0

namespace fn_f34eeb08 {

// 0x000d71f0 FUN_000d71f0 (93 B): matches/0x000d71f0.cpp
// sym: ?f@A_d71f0@fn_f34eeb08@@QAEXHHH@Z
void A_d71f0::f(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    p8->Fna_000d3170(a, b, c);
    p4->Fna_000d40e0(a, b, c);
    unsigned int v = p8->Fnb_000cae60();
    p8->Fnc_000cae40(v);
    p4->x = (unsigned char)((v >> 7) & 1);
    pc->x = (unsigned char)((v >> 8) & 1);
}


// 0x000d7250 FUN_000d7250 (90 B): matches/0x000d7250.cpp
// sym: ?Run@Obj_d7250@fn_f34eeb08@@QAEXI@Z
void Obj_d7250::Run(unsigned bits) {
    unsigned x = inner->Get_000cae50() & ~0x80u;
    if (a)
        x |= 0x80;
    if (b)
        x |= 0x100;
    unsigned result = x | bits;
    ((owners::Target_cae40 *)inner)->FUN_000cae40((int)result);
    a->flag = (result >> 7) & 1;
    b->flag = (result >> 8) & 1;
}


// 0x000d72b0 FUN_000d72b0 (90 B): matches/0x000d72b0.cpp
// sym: ?Update@Obj_d72b0@fn_f34eeb08@@QAEXI@Z
void Obj_d72b0::Update(unsigned int mask) {
    unsigned int flags = b->GetFlags_000cae50();
    unsigned int keep = mask;
    flags &= 0xffffff7f;
    if (a)
        flags |= 0x80;
    if (c)
        flags |= 0x100;
    unsigned int r = flags & ~keep;
    ((owners::Target_cae40 *)b)->FUN_000cae40((int)r);
    a->flag = (char)((r >> 7) & 1);
    c->flag = (char)((r >> 8) & 1);
}

} // namespace fn_f34eeb08

// 0x000d7310 FUN_000d7310 (76 B): matches/0x000d7310.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_000d7310@@QAE@PBDPAVOwner_d7310@1@P821@AEXXZ@Z
namespace fn_000d7310 {
// (script1) Closure1<class CSimOverlayManager,void,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040b39c[];   // Method1<class CSimOverlayManager,void,bool>
extern "C" char DAT_0040b3cc[];   // Closure1<class CSimOverlayManager,void,bool>
class Owner_d7310 {};
typedef void (Owner_d7310::*Fn_d7310)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_d7310 fn;
    Owner_d7310* owner;
    Closure1(const char* name, Owner_d7310* object, Fn_d7310 function);
};
Closure1::Closure1(const char* name, Owner_d7310* object, Fn_d7310 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_0040b39c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_0040b3cc;
    owner = object;
}
} // namespace fn_000d7310


// 0x000d7360 Closure1<CSimOverlayManager,void,bool>::vfunc_0 (30 B): matches/0x000d7360.cpp
// sym: ?vfunc_0@Closure1_d7360@fn_000d7360@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CSimOverlayManager, void, bool>::~Closure1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000d7360 {
struct Closure1_d7360 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_d7360::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000d7360
// (x64t21) the destructor itself, which other objects' code references:


// 0x000d7380 Closure1<CSimOverlayManager,void,bool>::vfunc_2 (20 B): matches/0x000d7380.cpp
// sym: ?vfunc_2@Closure1_d7380@fn_000d7380@@QAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CSimOverlayManager, void, bool>::vfunc_2`.
namespace fn_000d7380 {
struct Closure1_d7380 : hulk_script::FunctionGenView {
    void (::CSimOverlayManager::*f_1c)(bool);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_d7380::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_d7380 * *)&this->f_20)->*(*(void (Actor_d7380::**)(unsigned char))&this->f_1c))(*arg);
}
} // namespace fn_000d7380


// 0x000d73a0 FUN_000d73a0 (76 B): matches/0x000d73a0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000d73a0@@QAE@PBDPAVOwner_d73a0@1@P821@AEXXZ@Z
namespace fn_000d73a0 {
// (script1) Closure1<class CSimOverlayManager,void,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040b3ac[];   // Method1<class CSimOverlayManager,void,int>
extern "C" char DAT_0040b3dc[];   // Closure1<class CSimOverlayManager,void,int>
class Owner_d73a0 {};
typedef void (Owner_d73a0::*Fn_d73a0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_d73a0 fn;
    Owner_d73a0* owner;
    Closure1(const char* name, Owner_d73a0* object, Fn_d73a0 function);
};
Closure1::Closure1(const char* name, Owner_d73a0* object, Fn_d73a0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_0040b3ac;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0040b3dc;
    owner = object;
}
} // namespace fn_000d73a0


// 0x000d7410 Closure1<CSimOverlayManager,void,int>::vfunc_2 (18 B): matches/0x000d7410.cpp
// sym: ?vfunc_2@Closure1_d7410@fn_000d7410@@QAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CSimOverlayManager, void, int>::vfunc_2`.
namespace fn_000d7410 {
struct Closure1_d7410 : hulk_script::FunctionGenView {
    void (::CSimOverlayManager::*f_1c)(int);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
#if defined(HULK_PTR64)
// (script2, stop 6) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells
void Closure1_d7410::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Args_ { int a0; };
    const Args_* a = (const Args_*)__p1;
    ((*(Obj_**)&this->f_20)->*(*(void (Obj_::**)(int))&this->f_1c))(a->a0);
}
#else
void Closure1_d7410::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_d7410 * *)&this->f_20)->*(*(void (CActorManager_d7410::**)(const char *))&this->f_1c))(*b);
}
#endif
} // namespace fn_000d7410


// 0x000d7490 Closure0<CSimOverlayManager,int>::vfunc_2 (23 B): matches/0x000d7490.cpp
// sym: ?vfunc_2@Closure0_d7490@fn_000d7490@@QAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CSimOverlayManager, int>::vfunc_2`.
namespace fn_000d7490 {
struct Closure0_d7490 : hulk_script::FunctionGenView {
    int (::CSimOverlayManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_d7490::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_d7490* obj = (*(CActorManager_d7490 * *)&this->f_20);
    int (CActorManager_d7490::*fn)() = (*(int (CActorManager_d7490::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
} // namespace fn_000d7490


// 0x000d7550 FUN_000d7550 (109 B): matches/0x000d7550.cpp [wrapped: conflict: CSimOverlayManager; Closure0; Method0]
// sym: ?FUN_000d7550@Registry_d7550@fn_000d7550@@QAEXPBDPAVOwner_d7550@2@P832@AEXXZ@Z
namespace fn_000d7550 {
// (script1) ScriptHandler's registration of a Closure0<class CSimOverlayManager,int>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_0040b3bc[];   // Method0<class CSimOverlayManager,int>
extern "C" char DAT_0040b3ec[];   // Closure0<class CSimOverlayManager,int>
class Owner_d7550 {};
typedef void (Owner_d7550::*Fn_d7550)();
struct Closure_d7550 : hulk_script::ScriptFunction {
    Fn_d7550 fn;
    Owner_d7550* owner;
    Closure_d7550(const char* name, Owner_d7550* object, Fn_d7550 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_0040b3bc;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
        vftable = DAT_0040b3ec;
        owner = object;
    }
};
struct Registry_d7550 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_000d7550(const char* name, Owner_d7550* object, Fn_d7550 function);
};
void Registry_d7550::FUN_000d7550(const char* name, Owner_d7550* object, Fn_d7550 function) {
    Closure_d7550* c = new Closure_d7550(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_000d7550
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d75c0 FUN_000d75c0 (707 B): matches/0x000d75c0.cpp [wrapped: conflict: CSimOverlayManager; Closure1; FUN_001d04d0; Method1]
// sym: ??0CSimOverlayManager@fn_000d75c0@@QAE@XZ
void *operator new(hulk_uintptr) throw();
namespace fn_000d75c0 {
// FUN_000d75c0 @ 0x000d75c0


char FUN_001d04d0(const void *) throw();

struct MessageOverlay_d75c0 {
    char pad[0x810];
    MessageOverlay_d75c0 *FUN_000d6640();
};
struct HUDOverlay_d75c0 {
    char pad[0x510];
    HUDOverlay_d75c0 *FUN_000d1720();
};
// CSimOverlayManager and the members it binds to Lua (their types are the game's Closure1<CSimOverlayManager, ...>
// instantiations); the class is complete before any pointer to its members is formed, so the pointer is one code
// pointer on every build (docs/native-build.md sh2).
class CSimOverlayManager {
public:
    CSimOverlayManager();
    virtual void* v0_000d7010(char);
    MessageOverlay_d75c0 *panel;
    HUDOverlay_d75c0 *overlays;
    int f0c;
    void FUN_000d6fb0(bool);  // hud_ShowOverlays
    void FUN_000d6f80(bool);  // hud_ShowHUD
    void FUN_000d6f90(bool);  // hud_ShowMessages
    void FUN_000d7250(int);   // hud_Show
    void FUN_000d72b0(int);   // hud_Hide
    void FUN_000d7030(int);   // hud_SetVisibility
    int FUN_000d6f50();       // hud_GetVisibility
};
// Function's fields (include/decls/data/script.h) after the vftable; Method1 keeps the bound member-function pointer.
class Base_d75c0 : public ScriptFunctionFields {
public:
    virtual void v();
    Base_d75c0(const char *, int) throw();
};
template <class C, class R, class A>
class Method1 : public Base_d75c0 {
public:
    R (C::*f)(A);
    Method1(const char *n, R (C::*x)(A), const void *r, const void *a) : Base_d75c0(n, 1)
    {
        f = x;
        retType = FUN_001d04d0(r);
        argTypes[0] = FUN_001d04d0(a);
    }
    virtual void v();
};
template <class C, class R, class A>
class Closure1 : public Method1<C, R, A> {
public:
    C *owner;
    Closure1(const char *n, C *o, R (C::*f)(A), const void *r, const void *a) : Method1<C, R, A>(n, f, r, a)
    {
        owner = o;
    }
    virtual void v();
};
struct Registry_d75c0 {
    void FUN_001d3b70(const char *name, void *obj);
    void FUN_000d7550(const char *name, CSimOverlayManager *mgr, int (CSimOverlayManager::*fn)());
};
extern "C" Registry_d75c0 *FUN_001d4c90();
CSimOverlayManager::CSimOverlayManager()
{
    MessageOverlay_d75c0 *p = new MessageOverlay_d75c0;
    panel = p ? p->FUN_000d6640() : 0;
    HUDOverlay_d75c0 *o = new HUDOverlay_d75c0;
    overlays = o ? o->FUN_000d1720() : 0;
    f0c = 0;
    Registry_d75c0 *r = FUN_001d4c90();
    if (r) {
        r->FUN_001d3b70("hud_ShowOverlays", new Closure1<CSimOverlayManager, void, bool>("hud_ShowOverlays", this, &CSimOverlayManager::FUN_000d6fb0, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_ShowHUD", new Closure1<CSimOverlayManager, void, bool>("hud_ShowHUD", this, &CSimOverlayManager::FUN_000d6f80, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_ShowMessages", new Closure1<CSimOverlayManager, void, bool>("hud_ShowMessages", this, &CSimOverlayManager::FUN_000d6f90, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_Show", new Closure1<CSimOverlayManager, void, int>("hud_Show", this, &CSimOverlayManager::FUN_000d7250, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_001d3b70("hud_Hide", new Closure1<CSimOverlayManager, void, int>("hud_Hide", this, &CSimOverlayManager::FUN_000d72b0, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_001d3b70("hud_SetVisibility", new Closure1<CSimOverlayManager, void, int>("hud_SetVisibility", this, &CSimOverlayManager::FUN_000d7030, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_000d7550("hud_GetVisibility", this, &CSimOverlayManager::FUN_000d6f50);
    }
}
} // namespace fn_000d75c0

