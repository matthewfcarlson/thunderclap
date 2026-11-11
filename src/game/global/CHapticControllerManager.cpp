// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b0060..0x000b0440 (kind game, layer game, confidence high), dominant class CHapticControllerManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8a35d46 {
#define TREE_TU_END }
namespace fn_f8a35d46 {} using namespace fn_f8a35d46;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8a35d46 {
class Obj_b0080 {
  public:
    void af8_000af8e0(int);
    void afaf_000afaf0();
};
class Thing_b0080 {
  public:
    char pad[5];
    unsigned char flag;
    char pad2[2];
    Obj_b0080* ptr;
    void target(int);
};
extern "C" char DAT_00405ea8[];
class Method4_b00b0 {
  public:
    void Init_001d0480(int, int);
    Method4_b00b0(hulk_intptr, hulk_intptr);
};
extern "C" unsigned char __cdecl Read_001d04d0(const char*);
class CHapticControllerManager_b0140 {
  public:
    void Action(int, float, float, float);
};
class Function_b0140 {
  public:
    virtual void F0();
    virtual void F1();
};
class CActorManager_b01d0 {
  public:
    void f();
};
class CActorManager_b0240 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_b0240::*MFn_b0240)(unsigned char);
class Function_b0240 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CHapticControllerManager_b02b0 {
  public:
    void Run(int, float, float, float);
};
class Function_b02b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, int*, void*);
};
class CActorManager_b0340 {
  public:
    void run();
};
class Actor_b03c0 {
  public:
    void fn(unsigned char);
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f8a35d46
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f8a35d46 {
class CHapticControllerManager_b03e0 {};
typedef void (CHapticControllerManager_b03e0::*Fn_b03e0)(int, float, float, float);
class Registry_b03e0 { public:
    void FUN_000b03e0(const char* a1, CHapticControllerManager_b03e0* a2, Fn_b03e0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_b03e0;
template<> class Closure4_b03e0<CHapticControllerManager_b03e0, void, int, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_000b0290(int); Fn_b03e0 fn; CHapticControllerManager_b03e0* owner; Closure4_b03e0(CHapticControllerManager_b03e0* o) { owner = o; } };
class Raw_b03e0 { public: void FUN_000b00b0(const char*, Fn_b03e0); };

} // namespace fn_f8a35d46

// 0x000b0060 CHapticControllerManager::vfunc_0 (31 B): matches/0x000b0060.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000b0060@@UAEPAV123@E@Z
namespace fn_000b0060 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_00405ea0[];
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
    *(void**)this = hulk_at_00405ea0;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000b0060

namespace fn_f8a35d46 {

// 0x000b0080 FUN_000b0080 (48 B): matches/0x000b0080.cpp
// sym: ?target@Thing_b0080@fn_f8a35d46@@QAEXH@Z
void Thing_b0080::target(int arg) {
    if (flag) {
        if (ptr) {
            ptr->af8_000af8e0(arg);
            return;
        }
    } else {
        if (ptr)
            ptr->afaf_000afaf0();
        if (flag)
            FUN_002684c0();
    }
}


// 0x000b00b0 FUN_000b00b0 (102 B): matches/0x000b00b0.cpp
// sym: ??0Method4_b00b0@fn_f8a35d46@@QAE@HH@Z
Method4_b00b0::Method4_b00b0(hulk_intptr a, hulk_intptr b) {
    Init_001d0480(a, 4);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00405ea8);
    *(int*)((char*)this + 0x1c) = b;
    *(char*)((char*)this + 0x18) = Read_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    *(char*)((char*)this + 0x10) = Read_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *(char*)((char*)this + 0x11) = Read_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    *(char*)((char*)this + 0x12) = Read_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    *(char*)((char*)this + 0x13) = Read_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_f8a35d46

// 0x000b0120 Method4<CHapticControllerManager,void,int,float,float,float>::vfunc_0 (30 B): matches/0x000b0120.cpp
// sym: ??_G?$Method4@VCHapticControllerManager@@XHMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CHapticControllerManager, void, int, float, float, float>::~Method4() {}


// 0x000b0140 Method4<CHapticControllerManager,void,int,float,float,float>::vfunc_2 (46 B): matches/0x000b0140.cpp
// sym: ?vfunc_2@?$Method4@VCHapticControllerManager@@XHMMM@@UAEXPAX00@Z
template <> void Method4<CHapticControllerManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CHapticControllerManager_b0140 * obj = (CHapticControllerManager_b0140 *)__p0; void * args = (void *)__p1; void * unused = (void *)__p2;

    char* p = (char*)args;
    int a = *(int*)p;
    p += 4;
    float b = *(float*)p;
    p += 4;
    float c = *(float*)p;
    float d = *(float*)(p + 4);
    (obj->*(*(void (CHapticControllerManager_b0140::**)(int, float, float, float))&this->f_1c))(a, b, c, d);
}
#if defined(HULK_PTR64)
template class Method4<CHapticControllerManager, void, int, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xb0120)
#endif


// 0x000b01b0 Method0<CHapticControllerManager,void>::vfunc_0 (30 B): matches/0x000b01b0.cpp
// sym: ??_G?$Method0@VCHapticControllerManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CHapticControllerManager, void>::~Method0() {}


// 0x000b01d0 Method0<CHapticControllerManager,void>::vfunc_2 (12 B): matches/0x000b01d0.cpp
// sym: ?vfunc_2@?$Method0@VCHapticControllerManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CHapticControllerManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_b01d0 * a = (CActorManager_b01d0 *)__p0;

    (a->*(*(void (CActorManager_b01d0::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CHapticControllerManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xb01b0)
#endif


// 0x000b0220 Method1<CHapticControllerManager,void,bool>::vfunc_0 (30 B): matches/0x000b0220.cpp
// sym: ??_G?$Method1@VCHapticControllerManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CHapticControllerManager, void, bool>::~Method1() {}


// 0x000b0240 Method1<CHapticControllerManager,void,bool>::vfunc_2 (21 B): matches/0x000b0240.cpp
// sym: ?vfunc_2@?$Method1@VCHapticControllerManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CHapticControllerManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_b0240 * obj = (CActorManager_b0240 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_b0240 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CHapticControllerManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xb0220)
#endif


// 0x000b02b0 Closure4<CHapticControllerManager,void,int,float,float,float>::vfunc_2 (45 B): matches/0x000b02b0.cpp
// sym: ?vfunc_2@?$Closure4@VCHapticControllerManager@@XHMMM@@UAEXPAX00@Z
template <> void Closure4<CHapticControllerManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * args = (int *)__p1;

    int a = *args;
    float b = *(float*)++args;
    args++;
    float c = *(float*)args;
    float d = *(float*)(args + 1);
    ((*(CHapticControllerManager_b02b0 * *)&this->f_20)->*(*(void (CHapticControllerManager_b02b0::**)(int, float, float, float))&this->f_1c))(a, b, c, d);
}


// 0x000b0340 Closure0<CHapticControllerManager,void>::vfunc_2 (11 B): matches/0x000b0340.cpp
// sym: ?vfunc_2@?$Closure0@VCHapticControllerManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CHapticControllerManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_b0340 * *)&this->f_20)->*(*(void (CActorManager_b0340::**)())&this->f_1c))();
}


// 0x000b0350 FUN_000b0350 (76 B): matches/0x000b0350.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000b0350@@QAE@PBDPAVOwner_b0350@1@P821@AEX_N@Z@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000b0350 {
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

// Closure1<Owner, void, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_b0350 {};
typedef void (Owner_b0350::*Fn_b0350)(bool);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_b0350 : public CtorV_001d0480 {
  public:
    Function_b0350(const char* n) : CtorV_001d0480(n, 1) { }
};
class Method1 : public Function_b0350 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    Fn_b0350 arg;
    Method1(const char* n, Fn_b0350 v) : Function_b0350(n) {
        arg = v;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    Owner_b0350* extra;
    Closure1(const char* n, Owner_b0350* v, Fn_b0350 z);
};
Closure1::Closure1(const char* n, Owner_b0350* v, Fn_b0350 z) : Method1(n, z) {
    extra = v;
}
} // namespace fn_000b0350
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000b03c0 Closure1<CHapticControllerManager,void,bool>::vfunc_2 (20 B): matches/0x000b03c0.cpp
// sym: ?vfunc_2@?$Closure1@VCHapticControllerManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CHapticControllerManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_b03c0 * *)&this->f_20)->*(*(void (Actor_b03c0::**)(unsigned char))&this->f_1c))(*arg);
}

namespace fn_f8a35d46 {

// 0x000b03e0 FUN_000b03e0 (83 B): equivalent/0x000b03e0.cpp
// sym: ?FUN_000b03e0@Registry_b03e0@fn_f8a35d46@@QAEXPBDPAVCHapticControllerManager_b03e0@2@P832@AEXHMMM@Z@Z @de143ea57304 @wbbab26ac619d
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000b03e0 @ 0x000b03e0
// FUN_000b03e0 @ 0x000b03e0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_b03e0::FUN_000b03e0(const char* a1, CHapticControllerManager_b03e0* a2, Fn_b03e0 a3) {
    typedef Closure4_b03e0<CHapticControllerManager_b03e0, void, int, float, float, float> Alloc_b03e0;
    HULK_SIZE32(Alloc_b03e0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_b03e0));
    void* x = 0;
    if (m) {
        ((Raw_b03e0*)m)->FUN_000b00b0(a1, a3);
        x = new (m) Closure4_b03e0<CHapticControllerManager_b03e0, void, int, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f8a35d46
