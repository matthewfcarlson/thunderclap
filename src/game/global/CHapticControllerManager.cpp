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
#include "game/script_bind.h"

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
// sym: ??0Method4@fn_000b00b0@fn_f8a35d46@@QAE@PBDP8Owner_b00b0@12@AEXXZ@Z
namespace fn_000b00b0 {
// (script1) Method4<class CHapticControllerManager,void,int,float,float,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00405ea8[];   // Method4<class CHapticControllerManager,void,int,float,float,float>
class Owner_b00b0 {};
typedef void (Owner_b00b0::*Fn_b00b0)();
struct Method4 : hulk_script::ScriptFunction {
    Fn_b00b0 fn;
    Method4(const char* name, Fn_b00b0 function);
};
Method4::Method4(const char* name, Fn_b00b0 function) : hulk_script::ScriptFunction(name, 4) {
    vftable = DAT_00405ea8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
}
} // namespace fn_000b00b0

} // namespace fn_f8a35d46

// 0x000b0120 Method4<CHapticControllerManager,void,int,float,float,float>::vfunc_0 (30 B): matches/0x000b0120.cpp
// sym: ?vfunc_0@Method4_b0120@fn_000b0120@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method4<CHapticControllerManager, void, int, float, float,
// float>::~Method4() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000b0120 {
struct Method4_b0120 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method4_b0120::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000b0120
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method0_b01b0@fn_000b01b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CHapticControllerManager, void>::~Method0() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000b01b0 {
struct Method0_b01b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_b01b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000b01b0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method1_b0220@fn_000b0220@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CHapticControllerManager, void, bool>::~Method1() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000b0220 {
struct Method1_b0220 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_b0220::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000b0220
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure1@fn_000b0350@@QAE@PBDPAVOwner_b0350@1@P821@AEXXZ@Z
namespace fn_000b0350 {
// (script1) Closure1<class CHapticControllerManager,void,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00405ec8[];   // Method1<class CHapticControllerManager,void,bool>
extern "C" char DAT_00405ef8[];   // Closure1<class CHapticControllerManager,void,bool>
class Owner_b0350 {};
typedef void (Owner_b0350::*Fn_b0350)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_b0350 fn;
    Owner_b0350* owner;
    Closure1(const char* name, Owner_b0350* object, Fn_b0350 function);
};
Closure1::Closure1(const char* name, Owner_b0350* object, Fn_b0350 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00405ec8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_00405ef8;
    owner = object;
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
// sym: ?FUN_000b03e0@Registry_b03e0@fn_f8a35d46@@QAEXPBDPAVCHapticControllerManager_b03e0@2@P832@AEXHMMM@Z@Z @de143ea57304 @wbbab26ac619d @v8a199768dccf
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
