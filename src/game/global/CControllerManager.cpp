// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
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
#include "game/script_bind.h"

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
    void* vftable; void* parts[20];   /* (sweep2) the World's words (HulkWorld): +0x54 is CGame */
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
// sym: ?FUN_000ae9f0@fn_f57ff923@@YA_NXZ @cdcb765a3401 @wec6ed3a77e67 @v757151dabdc9
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
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_00405d64;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}
} // namespace fn_000aeaa0


// 0x000aeb00 Method0<CControllerManager,bool>::vfunc_0 (30 B): matches/0x000aeb00.cpp
// sym: ?vfunc_0@Method0_aeb00@fn_000aeb00@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CControllerManager, bool>::~Method0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000aeb00 {
struct Method0_aeb00 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_aeb00::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000aeb00
// (x64t21) the destructor itself, which other objects' code references:


// 0x000aeb20 Method0<CControllerManager,bool>::vfunc_2 (22 B): matches/0x000aeb20.cpp
// sym: ?vfunc_2@Method0_aeb20@fn_000aeb20@@QAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CControllerManager, bool>::vfunc_2`.
namespace fn_000aeb20 {
struct Method0_aeb20 : hulk_script::FunctionGenView {
    bool (::CControllerManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_aeb20::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_aeb20 * obj = (CActorManager_aeb20 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_aeb20 fn = (*(Fn_aeb20 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
} // namespace fn_000aeb20


// 0x000aeb90 Method2<CControllerManager,void,int,bool>::vfunc_0 (30 B): matches/0x000aeb90.cpp
// sym: ?vfunc_0@Method2_aeb90@fn_000aeb90@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CControllerManager, void, int, bool>::~Method2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000aeb90 {
struct Method2_aeb90 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_aeb90::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000aeb90
// (x64t21) the destructor itself, which other objects' code references:


// 0x000aebb0 Method2<CControllerManager,void,int,bool>::vfunc_2 (25 B): matches/0x000aebb0.cpp
// sym: ?vfunc_2@Method2_aebb0@fn_000aebb0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CControllerManager, void, int, bool>::vfunc_2`.
namespace fn_000aebb0 {
struct Method2_aebb0 : hulk_script::FunctionGenView {
    void (::CControllerManager::*f_1c)(int, bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_aebb0::vfunc_2(void* __p0, void* __p1, void* __p2) { CControllerManager_aebb0 * obj = (CControllerManager_aebb0 *)__p0; Args * args = (Args *)__p1;

    (obj->*(*(void (CControllerManager_aebb0::**)(int, bool))&this->f_1c))(args->a, args->b);
}
} // namespace fn_000aebb0


// 0x000aec10 Method1<CControllerManager,void,bool>::vfunc_0 (30 B): matches/0x000aec10.cpp
// sym: ?vfunc_0@Method1_aec10@fn_000aec10@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CControllerManager, void, bool>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000aec10 {
struct Method1_aec10 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_aec10::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000aec10
// (x64t21) the destructor itself, which other objects' code references:


// 0x000aec30 Method1<CControllerManager,void,bool>::vfunc_2 (21 B): matches/0x000aec30.cpp
// sym: ?vfunc_2@Method1_aec30@fn_000aec30@@QAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CControllerManager, void, bool>::vfunc_2`.
namespace fn_000aec30 {
struct Method1_aec30 : hulk_script::FunctionGenView {
    void (::CControllerManager::*f_1c)(bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_aec30::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_aec30 * obj = (CActorManager_aec30 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_aec30 *)&this->f_1c))(*b);
}
} // namespace fn_000aec30


// 0x000aecb0 Closure0<CControllerManager,bool>::vfunc_2 (23 B): matches/0x000aecb0.cpp
// sym: ?vfunc_2@Closure0_aecb0@fn_000aecb0@@QAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CControllerManager, bool>::vfunc_2`.
namespace fn_000aecb0 {
struct Closure0_aecb0 : hulk_script::FunctionGenView {
    bool (::CControllerManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_aecb0::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_aecb0* o = (*(CActorManager_aecb0 * *)&this->f_20);
    Fn_aecb0 fn = (*(Fn_aecb0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
} // namespace fn_000aecb0


// 0x000aecd0 FUN_000aecd0 (89 B): matches/0x000aecd0.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_000aecd0@@QAE@PBDPAVOwner_aecd0@1@P821@AEXXZ@Z
namespace fn_000aecd0 {
// (script1) Closure2<class CControllerManager,void,int,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00405d7c[];   // Method2<class CControllerManager,void,int,bool>
extern "C" char DAT_00405dac[];   // Closure2<class CControllerManager,void,int,bool>
class Owner_aecd0 {};
typedef void (Owner_aecd0::*Fn_aecd0)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_aecd0 fn;
    Owner_aecd0* owner;
    Closure2(const char* name, Owner_aecd0* object, Fn_aecd0 function);
};
Closure2::Closure2(const char* name, Owner_aecd0* object, Fn_aecd0 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00405d7c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_00405dac;
    owner = object;
}
} // namespace fn_000aecd0


// 0x000aed50 Closure2<CControllerManager,void,int,bool>::vfunc_2 (24 B): matches/0x000aed50.cpp
// sym: ?vfunc_2@Closure2_aed50@fn_000aed50@@QAEXPAX00@Z
// Same code shape as 0x0002ec60 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CControllerManager, void, int, bool>::vfunc_2`.
namespace fn_000aed50 {
struct Closure2_aed50 : hulk_script::FunctionGenView {
    void (::CControllerManager::*f_1c)(int, bool);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
#if defined(HULK_PTR64)
// (script2, stop 6) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells
void Closure2_aed50::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Args_ { int a0; bool a1; };
    const Args_* a = (const Args_*)__p1;
    ((*(Obj_**)&this->f_20)->*(*(void (Obj_::**)(int, bool))&this->f_1c))(a->a0, a->a1);
}
#else
void Closure2_aed50::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_aed50 * p = (Arg_aed50 *)__p1;

    ((*(Actor_aed50 * *)&this->f_20)->*(*(void (Actor_aed50::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
#endif
} // namespace fn_000aed50

namespace fn_f57ff923 {

// 0x000aed70 FUN_000aed70 (76 B): matches/0x000aed70.cpp
// sym: ??0Closure1@fn_000aed70@fn_f57ff923@@QAE@PBDPAVOwner_aed70@12@P8312@AEXXZ@Z
namespace fn_000aed70 {
// (script1) Closure1<class CControllerManager,void,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00405d8c[];   // Method1<class CControllerManager,void,bool>
extern "C" char DAT_00405dbc[];   // Closure1<class CControllerManager,void,bool>
class Owner_aed70 {};
typedef void (Owner_aed70::*Fn_aed70)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_aed70 fn;
    Owner_aed70* owner;
    Closure1(const char* name, Owner_aed70* object, Fn_aed70 function);
};
Closure1::Closure1(const char* name, Owner_aed70* object, Fn_aed70 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00405d8c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_00405dbc;
    owner = object;
}
} // namespace fn_000aed70

} // namespace fn_f57ff923

// 0x000aede0 Closure1<CControllerManager,void,bool>::vfunc_2 (20 B): matches/0x000aede0.cpp
// sym: ?vfunc_2@Closure1_aede0@fn_000aede0@@QAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CControllerManager, void, bool>::vfunc_2`.
namespace fn_000aede0 {
struct Closure1_aede0 : hulk_script::FunctionGenView {
    void (::CControllerManager::*f_1c)(bool);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_aede0::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_aede0 * *)&this->f_20)->*(*(void (Actor_aede0::**)(unsigned char))&this->f_1c))(*arg);
}
} // namespace fn_000aede0


// 0x000aee00 FUN_000aee00 (109 B): matches/0x000aee00.cpp [wrapped: conflict: CControllerManager; Closure0; Method0]
// sym: ?FUN_000aee00@Registry_aee00@fn_000aee00@@QAEXPBDPAVOwner_aee00@2@P832@AEXXZ@Z
namespace fn_000aee00 {
// (script1) ScriptHandler's registration of a Closure0<class CControllerManager,bool>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00405d6c[];   // Method0<class CControllerManager,bool>
extern "C" char DAT_00405d9c[];   // Closure0<class CControllerManager,bool>
class Owner_aee00 {};
typedef void (Owner_aee00::*Fn_aee00)();
struct Closure_aee00 : hulk_script::ScriptFunction {
    Fn_aee00 fn;
    Owner_aee00* owner;
    Closure_aee00(const char* name, Owner_aee00* object, Fn_aee00 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00405d6c;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
        vftable = DAT_00405d9c;
        owner = object;
    }
};
struct Registry_aee00 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_000aee00(const char* name, Owner_aee00* object, Fn_aee00 function);
};
void Registry_aee00::FUN_000aee00(const char* name, Owner_aee00* object, Fn_aee00 function) {
    Closure_aee00* c = new Closure_aee00(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_000aee00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000aef10 FUN_000aef10 (440 B): equivalent/0x000aef10.cpp [wrapped: conflict: CControllerManager; Closure0; Closure1; Closure2 (+4)]
// sym: ??0CControllerManager@fn_000aef10@@QAE@XZ @432e71c77be0 @w05b59c228988 @vd6e3daa53173
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

// (script1) the bound functions are include/game/script_bind.h's records; the game's vftables by address
extern "C" char DAT_00405d6c[];   // Method0<CControllerManager,bool>
extern "C" char DAT_00405d7c[];   // Method2<CControllerManager,void,int,bool>
extern "C" char DAT_00405d8c[];   // Method1<CControllerManager,void,bool>
extern "C" char DAT_00405d9c[];   // Closure0<CControllerManager,bool>
extern "C" char DAT_00405dac[];   // Closure2<CControllerManager,void,int,bool>
extern "C" char DAT_00405dbc[];   // Closure1<CControllerManager,void,bool>
// CController (CController.cpp, decls/managers.h HulkController): its constructor called by its own address name
class DeviceManager_aef10 {
public:
    DeviceManager_aef10* FUN_000ae4b0(int flags);
    virtual void vf0();
    void FUN_000adc00(int);
};
class Registry_aef10 {
public:
    void FUN_001d3b70(const char* name, void* fn);
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
    void FUN_000ae9d0(int, char);        // (script1) as defined; bound below as the Lua function's (int, bool)
    void FUN_000ae9a0(unsigned char);    // (script1) as defined; bound below as (bool)
};
HULK_MGR_SAME(CControllerManager, HulkControllerManager);   // (x64t9-mgr) include/decls/managers.h

CControllerManager::CControllerManager() {
    field8 = 1;
    DeviceManager_aef10* d = (DeviceManager_aef10*)FUN_0008d690(sizeof(HulkController));
    devices = d ? d->FUN_000ae4b0(0) : 0;
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
    typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod0<CControllerManager, bool>, CControllerManager> Closure0_t;
    typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod2<CControllerManager, void, int, bool>, CControllerManager>
        Closure2_t;
    typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod1<CControllerManager, void, bool>, CControllerManager> Closure1_t;
    HULK_SIZE32(Closure0_t, 0x24);
    HULK_SIZE32(Closure2_t, 0x24);
    HULK_SIZE32(Closure1_t, 0x24);
    Registry_aef10* reg = FUN_001d4c90();
    reg->FUN_001d3b70("ctrl_IsButtonPressed",
        new Closure0_t("ctrl_IsButtonPressed", this, &CControllerManager::FUN_000ae9f0, DAT_00405d6c, DAT_00405d9c));
    reg->FUN_001d3b70("ctrl_SetButtonLock",
        new Closure2_t("ctrl_SetButtonLock", this,
                       reinterpret_cast<void (CControllerManager::*)(int, bool)>(&CControllerManager::FUN_000ae9d0),
                       DAT_00405d7c, DAT_00405dac));
    reg->FUN_001d3b70("ctrl_SetButtonLockAll",
        new Closure1_t("ctrl_SetButtonLockAll", this,
                       reinterpret_cast<void (CControllerManager::*)(bool)>(&CControllerManager::FUN_000ae9a0),
                       DAT_00405d8c, DAT_00405dbc));
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

