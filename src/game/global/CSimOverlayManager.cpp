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

// ---- declarations shared by the functions below
namespace fn_f34eeb08 {
typedef unsigned int uint_d7030;
class Helper_d7030 {
  public:
    void Run(uint_d7030 value);
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
    void a(int, int, int);
    unsigned int b();
    void c(unsigned int);
};
class Y_d71f0 {
  public:
    char pad[4];
    unsigned char x;
    void a(int, int, int);
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
    unsigned Get();
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
    unsigned int GetFlags();
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
} // namespace fn_000d7010

namespace fn_f34eeb08 {

// 0x000d7030 FUN_000d7030 (49 B): matches/0x000d7030.cpp
// sym: ?Run@Target_d7030@fn_f34eeb08@@QAEXI@Z
void Target_d7030::Run(uint_d7030 value) {
    middle->Run(value);
    *((byte*)first + 4) = (byte)((value >> 7) & 1);
    *((byte*)third + 4) = (byte)((value >> 8) & 1);
}

} // namespace fn_f34eeb08

// 0x000d70b0 Method1<CSimOverlayManager,void,bool>::vfunc_0 (30 B): matches/0x000d70b0.cpp
// sym: ??_G?$Method1@VCSimOverlayManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSimOverlayManager, void, bool>::~Method1() {}


// 0x000d70d0 Method1<CSimOverlayManager,void,bool>::vfunc_2 (21 B): matches/0x000d70d0.cpp
// sym: ?vfunc_2@?$Method1@VCSimOverlayManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CSimOverlayManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_d70d0 * obj = (CActorManager_d70d0 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_d70d0 *)&this->f_1c))(*b);
}


// 0x000d7130 Method1<CSimOverlayManager,void,int>::vfunc_0 (30 B): matches/0x000d7130.cpp
// sym: ??_G?$Method1@VCSimOverlayManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSimOverlayManager, void, int>::~Method1() {}


// 0x000d7150 Method1<CSimOverlayManager,void,int>::vfunc_2 (19 B): matches/0x000d7150.cpp
// sym: ?vfunc_2@?$Method1@VCSimOverlayManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSimOverlayManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_d7150* d = (Dummy_d7150*)a;
    (d->*(*(void (Dummy_d7150::**)(void *))&this->f_1c))(*b);
}


// 0x000d71b0 Method0<CSimOverlayManager,int>::vfunc_0 (30 B): matches/0x000d71b0.cpp
// sym: ??_G?$Method0@VCSimOverlayManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CSimOverlayManager, int>::~Method0() {}


// 0x000d71d0 Method0<CSimOverlayManager,int>::vfunc_2 (22 B): matches/0x000d71d0.cpp
// sym: ?vfunc_2@?$Method0@VCSimOverlayManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CSimOverlayManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}

namespace fn_f34eeb08 {

// 0x000d71f0 FUN_000d71f0 (93 B): matches/0x000d71f0.cpp
// sym: ?f@A_d71f0@fn_f34eeb08@@QAEXHHH@Z
void A_d71f0::f(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    p8->a(a, b, c);
    p4->a(a, b, c);
    unsigned int v = p8->b();
    p8->c(v);
    p4->x = (unsigned char)((v >> 7) & 1);
    pc->x = (unsigned char)((v >> 8) & 1);
}


// 0x000d7250 FUN_000d7250 (90 B): matches/0x000d7250.cpp
// sym: ?Run@Obj_d7250@fn_f34eeb08@@QAEXI@Z
void Obj_d7250::Run(unsigned bits) {
    unsigned x = inner->Get() & ~0x80u;
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
    unsigned int flags = b->GetFlags();
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
// sym: ??0Closure1@fn_000d7310@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_000d7310 {
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

typedef unsigned char byte;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) byte __cdecl GetFlag(void*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_d7310 : public Base {
  public:
    virtual void Fn();
    ScriptMemberFn obj;
    Closure1_d7310(const char* p, ScriptMemberFn c);
};
class Closure1 : public Closure1_d7310 {
  public:
    virtual void Fn();
    void* extra;
    Closure1(const char* p, void* e, ScriptMemberFn c);
};
Closure1_d7310::Closure1_d7310(const char* p, ScriptMemberFn c) : Base(p) {
    obj = c;
    retType = GetFlag(((int*)&DAT_0048e100));
    argTypes[0] = GetFlag(((int*)&DAT_0048e0e4));
}
Closure1::Closure1(const char* p, void* e, ScriptMemberFn c) : Closure1_d7310(p, c), extra(e) {}
} // namespace fn_000d7310


// 0x000d7360 Closure1<CSimOverlayManager,void,bool>::vfunc_0 (30 B): matches/0x000d7360.cpp
// sym: ??_G?$Method1@VCSimOverlayManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSimOverlayManager, void, bool>::~Closure1() {}


// 0x000d7380 Closure1<CSimOverlayManager,void,bool>::vfunc_2 (20 B): matches/0x000d7380.cpp
// sym: ?vfunc_2@?$Closure1@VCSimOverlayManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CSimOverlayManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_d7380 * *)&this->f_20)->*(*(void (Actor_d7380::**)(unsigned char))&this->f_1c))(*arg);
}


// 0x000d73a0 FUN_000d73a0 (76 B): matches/0x000d73a0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000d73a0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_000d73a0 {
// data: keyA = DAT_0048e100, keyB = DAT_0048e134
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char __cdecl lookup(const char*);
class Function_d73a0 : public CtorV_001d0480 {
  public:
    Function_d73a0(const char* a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Function_d73a0 {
  public:
    virtual void run();
    ScriptMemberFn value;
    Method1(const char* a, ScriptMemberFn c) : Function_d73a0(a) {
        value = c;
        retType = lookup(((const char*)&DAT_0048e100));
        argTypes[0] = lookup(((const char*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void run();
    void* other;
    Closure1(const char* a, void* b, ScriptMemberFn c);
};
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c), other(b) {}
} // namespace fn_000d73a0


// 0x000d7410 Closure1<CSimOverlayManager,void,int>::vfunc_2 (18 B): matches/0x000d7410.cpp
// sym: ?vfunc_2@?$Closure1@VCSimOverlayManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSimOverlayManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_d7410 * *)&this->f_20)->*(*(void (CActorManager_d7410::**)(const char *))&this->f_1c))(*b);
}


// 0x000d7490 Closure0<CSimOverlayManager,int>::vfunc_2 (23 B): matches/0x000d7490.cpp
// sym: ?vfunc_2@?$Closure0@VCSimOverlayManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CSimOverlayManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_d7490* obj = (*(CActorManager_d7490 * *)&this->f_20);
    int (CActorManager_d7490::*fn)() = (*(int (CActorManager_d7490::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}


// 0x000d7550 FUN_000d7550 (109 B): equivalent/0x000d7550.cpp [wrapped: conflict: CSimOverlayManager; Closure0; Method0]
// sym: ?FUN_000d7550@Registry_d7550@fn_000d7550@@QAEXPBDPAVCSimOverlayManager@2@P832@AEHXZ@Z
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000d7550 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000d7550 @ 0x000d7550
// FUN_000d7550 @ 0x000d7550  (generated by work/closure/gen.py)
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CSimOverlayManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_d7550 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_d7550(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_d7550 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_d7550(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_d7550 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000d7550(const char* name, CSimOverlayManager* owner, int (CSimOverlayManager::*fn)());
};

void Registry_d7550::FUN_000d7550(const char* name, CSimOverlayManager* owner, int (CSimOverlayManager::*fn)()) {
    typedef Closure0<CSimOverlayManager, int> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CSimOverlayManager, int>));
    Closure0<CSimOverlayManager, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<CSimOverlayManager, int>(name, owner, fn);
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
    virtual void v0();
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

