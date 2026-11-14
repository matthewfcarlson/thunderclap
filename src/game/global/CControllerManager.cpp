// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000ae9a0..0x000af110 (kind game, layer game, confidence high), dominant class CControllerManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f57ff923 {
#define TREE_TU_END }
namespace fn_f57ff923 {} using namespace fn_f57ff923;
#include "game/global.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
namespace fn_f57ff923 {
struct PadState_ae9f0 {
    int words[41];
};
struct PadSource {
    void FUN_000af0f0(PadState_ae9f0 *out);
};
struct PadList_ae9f0 {
    PadSource *FUN_000af3a0(int index);
};
struct InputManager {
    PadList_ae9f0 *FUN_000862d0();
};
} // namespace fn_f57ff923
struct World {
    char pad0[0x54];
    InputManager *input;
};
namespace fn_f57ff923 {
class CActorManager_aeb20;
typedef unsigned char(__fastcall* Fn_aeb20)(CActorManager_aeb20*);
class Function_aebb0 {
  public:
    virtual void v0();
    virtual void v1();
};
struct Args {
    int a;
    bool b;
};
class CControllerManager_aebb0 {
  public:
    void fn(int, bool);
};
class CActorManager_aec30 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_aec30::*MFn_aec30)(unsigned char);
class Function_aec30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_aecb0;
typedef unsigned char(__fastcall* Fn_aecb0)(CActorManager_aecb0*);
struct Arg_aed50 {
    const char* s;
    unsigned char b;
};
class Actor_aed50 {
  public:
    void invoke(const char*, unsigned char);
};
extern "C" unsigned char ReadFlag_001d04d0(const char*);
class Function_aed70 {
  public:
    Function_aed70(void*, int);
    virtual void v();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* p;
    void* q;
};
class Method1_aed70 : public Function_aed70 {
  public:
    Method1_aed70(void* a, void* c) : Function_aed70(a, 1) {
        p = c;
        y = ReadFlag_001d04d0(((const char*)&DAT_0048e100));
        x = ReadFlag_001d04d0(((const char*)&DAT_0048e0e4));
    }
    virtual void v();
};
class Closure1_aed70 : public Method1_aed70 {
  public:
    Closure1_aed70(void*, void*, void*);
    virtual void v();
    virtual bool v2_001d04c0(int, int);
};
class Actor_aede0 {
  public:
    void fn(unsigned char);
};
extern void* hulk_at_003f6098;
struct Obj_af0d0 {
    void** vf;
    char pad[4];
    struct Ref_af0d0* p;
};
struct Ref_af0d0 {
    virtual void a();
    virtual void b();
};
} // namespace fn_f57ff923
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif


// 0x000ae9a0 FUN_000ae9a0 (45 B): matches/0x000ae9a0.cpp
// sym: ?FUN_000ae9a0@CControllerManager@@QAEXE@Z
void CControllerManager::FUN_000ae9a0(unsigned char v) {
    for (int i = 0; i < 13; i++)
        (*(unsigned char (*)[15])&this->f_0c)[i] = v;
    for (int j = 13; j < 15; j++)
        (*(unsigned char (*)[15])&this->f_0c)[j] = v;
}


// 0x000ae9d0 FUN_000ae9d0 (24 B): matches/0x000ae9d0.cpp
// sym: ?FUN_000ae9d0@CControllerManager@@QAEXHD@Z
void CControllerManager::FUN_000ae9d0(int index, char value) {
    if (index >= 0 && index < 15)
        (*(char (*)[15])&this->f_0c)[index] = value;
}

namespace fn_f57ff923 {

// 0x000ae9f0 FUN_000ae9f0 (123 B): equivalent/0x000ae9f0.cpp
// sym: ?FUN_000ae9f0@fn_f57ff923@@YA_NXZ @cdcb765a3401 @wec6ed3a77e67
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 9/10, incomplete)
// FUN_000ae9f0 @ 0x000ae9f0
bool FUN_000ae9f0() {
    DAT_004dd700->input->FUN_000862d0();
    for (int i = 0; i < 1; i++) {
        PadState_ae9f0 state;
        DAT_004dd700->input->FUN_000862d0()->FUN_000af3a0(i)->FUN_000af0f0(&state);
        if (state.words[0] == 1 || state.words[12] == 1 || state.words[3] == 1 ||
            state.words[18] == 1) {
            DAT_004e222c = 1;
            return true;
        }
    }
    return false;
}

} // namespace fn_f57ff923

// 0x000aeaa0 CControllerManager::vfunc_0 (31 B): matches/0x000aeaa0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000aeaa0@@UAEPAV123@E@Z
namespace fn_000aeaa0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_00405d64[];
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
    *(void**)this = hulk_at_00405d64;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000aeaa0


// 0x000aeb00 Method0<CControllerManager,bool>::vfunc_0 (30 B): matches/0x000aeb00.cpp
// sym: ??_G?$Method0@VCControllerManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CControllerManager, bool>::~Method0() {}


// 0x000aeb20 Method0<CControllerManager,bool>::vfunc_2 (22 B): matches/0x000aeb20.cpp
// sym: ?vfunc_2@?$Method0@VCControllerManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CControllerManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_aeb20 * obj = (CActorManager_aeb20 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_aeb20 fn = (*(Fn_aeb20 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method0<CControllerManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xaeb00)
#endif


// 0x000aeb90 Method2<CControllerManager,void,int,bool>::vfunc_0 (30 B): matches/0x000aeb90.cpp
// sym: ??_G?$Method2@VCControllerManager@@XH_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CControllerManager, void, int, bool>::~Method2() {}


// 0x000aebb0 Method2<CControllerManager,void,int,bool>::vfunc_2 (25 B): matches/0x000aebb0.cpp
// sym: ?vfunc_2@?$Method2@VCControllerManager@@XH_N@@UAEXPAX00@Z
template <> void Method2<CControllerManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CControllerManager_aebb0 * obj = (CControllerManager_aebb0 *)__p0; Args * args = (Args *)__p1;

    (obj->*(*(void (CControllerManager_aebb0::**)(int, bool))&this->f_1c))(args->a, args->b);
}
#if defined(HULK_PTR64)
template class Method2<CControllerManager, void, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xaeb90)
#endif


// 0x000aec10 Method1<CControllerManager,void,bool>::vfunc_0 (30 B): matches/0x000aec10.cpp
// sym: ??_G?$Method1@VCControllerManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CControllerManager, void, bool>::~Method1() {}


// 0x000aec30 Method1<CControllerManager,void,bool>::vfunc_2 (21 B): matches/0x000aec30.cpp
// sym: ?vfunc_2@?$Method1@VCControllerManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CControllerManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_aec30 * obj = (CActorManager_aec30 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_aec30 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CControllerManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xaec10)
#endif


// 0x000aecb0 Closure0<CControllerManager,bool>::vfunc_2 (23 B): matches/0x000aecb0.cpp
// sym: ?vfunc_2@?$Closure0@VCControllerManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CControllerManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_aecb0* o = (*(CActorManager_aecb0 * *)&this->f_20);
    Fn_aecb0 fn = (*(Fn_aecb0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}


// 0x000aecd0 FUN_000aecd0 (89 B): matches/0x000aecd0.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_000aecd0@@QAE@PBDPAVOwner_aecd0@1@P821@AEXH_N@Z@Z
namespace fn_000aecd0 {
// data: str1_aecd0 = DAT_0048e100, str2 = DAT_0048e134, str3 = DAT_0048e0e4

extern "C++" __declspec(nothrow) unsigned char FUN_001d04d0(const char*);
// Closure2<Owner, void, int, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_aecd0 {};
typedef void (Owner_aecd0::*Fn_aecd0)(int, bool);
class Function_aecd0 : public ScriptFunctionFields {
  public:
    Function_aecd0(const char*, int);
    virtual void f();
    Fn_aecd0 val;
    Owner_aecd0* other;
};
class Method2 : public Function_aecd0 {
  public:
    Method2(const char* p, Fn_aecd0 n) : Function_aecd0(p, 2) {
        val = n;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
        argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure2 : public Method2 {
  public:
    Closure2(const char* p, Owner_aecd0* m, Fn_aecd0 n);
    virtual void f();
};
Closure2::Closure2(const char* p, Owner_aecd0* m, Fn_aecd0 n) : Method2(p, n) {
    other = m;
}
} // namespace fn_000aecd0


// 0x000aed50 Closure2<CControllerManager,void,int,bool>::vfunc_2 (24 B): matches/0x000aed50.cpp
// sym: ?vfunc_2@?$Closure2@VCControllerManager@@XH_N@@UAEXPAX00@Z
// Same code shape as 0x0002ec60 (propagated; names are from that function)
template <> void Closure2<CControllerManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_aed50 * p = (Arg_aed50 *)__p1;

    ((*(Actor_aed50 * *)&this->f_20)->*(*(void (Actor_aed50::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}

namespace fn_f57ff923 {

// 0x000aed70 FUN_000aed70 (76 B): matches/0x000aed70.cpp
// sym: ??0Closure1_aed70@fn_f57ff923@@QAE@PAX00@Z
Closure1_aed70::Closure1_aed70(void* a, void* b, void* c) : Method1_aed70(a, c) {
    q = b;
}

} // namespace fn_f57ff923

// 0x000aede0 Closure1<CControllerManager,void,bool>::vfunc_2 (20 B): matches/0x000aede0.cpp
// sym: ?vfunc_2@?$Closure1@VCControllerManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CControllerManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_aede0 * *)&this->f_20)->*(*(void (Actor_aede0::**)(unsigned char))&this->f_1c))(*arg);
}


// 0x000aee00 FUN_000aee00 (109 B): equivalent/0x000aee00.cpp [wrapped: conflict: CControllerManager; Closure0; Method0]
// sym: ?FUN_000aee00@Registry_aee00@fn_000aee00@@QAEXPBDPAVCControllerManager@2@P832@AE_NXZ@Z @b9bcefdcdbd9 @wed97cb6dea9d
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_000aee00 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000aee00 @ 0x000aee00
// FUN_000aee00 @ 0x000aee00  (generated by work/closure/gen.py)
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


class CControllerManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_aee00 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_aee00(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_aee00 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_aee00(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_aee00 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000aee00(const char* name, CControllerManager* owner, bool (CControllerManager::*fn)());
};

void Registry_aee00::FUN_000aee00(const char* name, CControllerManager* owner, bool (CControllerManager::*fn)()) {
    typedef Closure0<CControllerManager, bool> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CControllerManager, bool>));
    Closure0<CControllerManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CControllerManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000aee00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000aef10 FUN_000aef10 (440 B): equivalent/0x000aef10.cpp [wrapped: conflict: CControllerManager; Closure0; Closure1; Closure2 (+4)]
// sym: ??0CControllerManager@fn_000aef10@@QAE@XZ @0cb353bcc559 @w60240028f6b1
namespace fn_000aef10 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_000aef10 @ 0x000aef10
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
extern "C" void FUN_000af480();

// Function (include/decls/data/script.h): its fields; Method<N> adds the member-function pointer, Closure<N> the object.
class Function : public ScriptFunctionFields {
public:
    Function(const char* name, int count) throw();
    virtual void vf0();
    virtual bool vf1_001d04c0(int, int);
    static void* operator new(hulk_uintptr size) { return FUN_0008d690((unsigned int)size); }
};

template <class T, class R> class Method0 : public Function {
public:
    R (T::*fn)();
    Method0(const char* name, R (T::*f)()) : Function(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char**)&DAT_0048e0e4));
    }
};

template <class T, class R, class A, class B> class Method2 : public Function {
public:
    void (T::*fn)(int, bool);
    Method2(const char* name, void (T::*f)(int, bool)) : Function(name, 2) {
        fn = f;
        retType = FUN_001d04d0(((const char**)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char**)&DAT_0048e134));
        argTypes[1] = FUN_001d04d0(((const char**)&DAT_0048e0e4));
    }
};

template <class T, class R, class A> class Method1 : public Function {
public:
    void (T::*fn)(bool);
    Method1(const char* name, void (T::*f)(bool)) : Function(name, 1) {
        fn = f;
        retType = FUN_001d04d0(((const char**)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char**)&DAT_0048e0e4));
    }
};

template <class T, class R> class Closure0 : public Method0<T, R> {
public:
    T* target;
    Closure0(const char* name, R (T::*f)(), T* t) throw() : Method0<T, R>(name, f) { target = t; }
};
template <class T, class R, class A, class B> class Closure2 : public Method2<T, R, A, B> {
public:
    T* target;
    Closure2(const char* name, void (T::*f)(int, bool), T* t) throw() : Method2<T, R, A, B>(name, f) { target = t; }
};
template <class T, class R, class A> class Closure1 : public Method1<T, R, A> {
public:
    T* target;
    Closure1(const char* name, void (T::*f)(bool), T* t) throw() : Method1<T, R, A>(name, f) { target = t; }
};

class DeviceManager_aef10 {
public:
    DeviceManager_aef10(int flags) throw();
    char pad[0x170];
    virtual void vf0();
    void FUN_000adc00(int);
};
class Registry_aef10 {
public:
    void FUN_001d3b70(const char* name, Function* fn);
};
extern "C" Registry_aef10* __cdecl FUN_001d4c90();

class CControllerManager {
public:
    CControllerManager();
    virtual void* vf0_000aeaa0(char);
    DeviceManager_aef10* devices;
    int field8;
    int fieldC;
    int field10;
    int field14;
    char b18;
    char flags[9];
    bool FUN_000ae9f0();
    void FUN_000ae9d0(int, bool);
    void FUN_000ae9a0(bool);
};
HULK_MGR_SAME(CControllerManager, HulkControllerManager);   // (x64t9-mgr) include/decls/managers.h

CControllerManager::CControllerManager() {
    field8 = 1;
    devices = new DeviceManager_aef10(0);
    devices->vf0();
    devices->FUN_000adc00(field8);
    fieldC = 0;
    field10 = 0;
    field14 = 0;
    b18 = 0;
    flags[0] = 0;
    flags[1] = 0;
    FUN_000af480();
    for (int i = 2; i < 9; i++)
        flags[i] = 0;
    typedef Closure0<CControllerManager, bool> Closure0_t;
    typedef Closure2<CControllerManager, void, int, bool> Closure2_t;
    typedef Closure1<CControllerManager, void, bool> Closure1_t;
    HULK_SIZE32(Closure0_t, 0x24);
    HULK_SIZE32(Closure2_t, 0x24);
    HULK_SIZE32(Closure1_t, 0x24);
    Registry_aef10* reg = FUN_001d4c90();
    reg->FUN_001d3b70("ctrl_IsButtonPressed",
        new Closure0<CControllerManager, bool>("ctrl_IsButtonPressed", &CControllerManager::FUN_000ae9f0, this));
    reg->FUN_001d3b70("ctrl_SetButtonLock",
        new Closure2<CControllerManager, void, int, bool>("ctrl_SetButtonLock", &CControllerManager::FUN_000ae9d0, this));
    reg->FUN_001d3b70("ctrl_SetButtonLockAll",
        new Closure1<CControllerManager, void, bool>("ctrl_SetButtonLockAll", &CControllerManager::FUN_000ae9a0, this));
}
} // namespace fn_000aef10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f57ff923 {

// 0x000af0d0 FUN_000af0d0 (25 B): matches/0x000af0d0.cpp
// sym: ?target@fn_f57ff923@@YIXPAUObj_af0d0@1@@Z
void __fastcall target(Obj_af0d0* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&hulk_at_003f6098;
}

} // namespace fn_f57ff923

// 0x000af0f0 FUN_000af0f0 (21 B): matches/0x000af0f0.cpp
// sym: ?FUN_000af0f0@C_af0f0@owners@@QAEXPAX@Z
void owners::C_af0f0::FUN_000af0f0(void* p) {
    memcpy(p, this->data, 0xa4);
}

