// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f76c0..0x001f84d0 (kind game, layer game, confidence high), dominant class CEffectManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f919337e {
#define TREE_TU_END }
namespace fn_f919337e {} using namespace fn_f919337e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace math {
struct Vector_1f76e0 { float x, y, z; };
}
namespace fn_f919337e {
struct CEffectManager_1f76e0 {
    int FUN_001f76e0(const char *, math::Vector_1f76e0);
};
struct EffectArguments {
    const char *name;
    math::Vector_1f76e0 position;
};
struct Function_1f76e0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_00424d4c[];
class Function_1f7720 {
  public:
    Function_1f7720(const char*, int);
};
extern char hulk_at_0048e10c[];
class Method3_1f7720 : public Function_1f7720 {
  public:
    Method3_1f7720(const char*, ScriptMemberFn);
    void* vftable;           // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
};
struct Vector_1f77a0 { float x, y, z; };
class CEffectManager_1f77a0 {
  public:
    int Dummy(const char* name, Vector_1f77a0 a, Vector_1f77a0 b);
};
struct Args_1f77a0 {
    const char* name;
    Vector_1f77a0 a;
    Vector_1f77a0 b;
};
class Function_1f77a0 {
  public:
    virtual void f0();
    virtual void f1();
};
} // namespace fn_f919337e
namespace math {
struct Vector_1f7880 { float x, y, z; };
}
namespace fn_f919337e {
struct CEffectManager_1f7880 { bool effect(int id, math::Vector_1f7880 position); };
struct Arguments { int id; math::Vector_1f7880 position; };
struct Function_1f7880 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
extern "C" char DAT_00424d6c[];
class Method3_1f78c0 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn field1c;  // 0x1c
    void Base_001d0480(const char*, int);
    Method3_1f78c0* Build(const char*, ScriptMemberFn);
};
class CEffectManager_1f7940 {
  public:
    unsigned int Do(char*, float, float);
};
class Function_1f7940 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CEffectManager_1f7940*, void*, unsigned int*);
};
struct Function_1f7af0 {
    virtual void f0();
    virtual void f1();
};
struct Dummy_1f7af0 {
    int x;
};
typedef bool (Dummy_1f7af0::*Fn_1f7af0)(bool);
class CActorManager_1f7df0 {
  public:
    float Get();
};
typedef float (CActorManager_1f7df0::*Fn_1f7df0)();
class CEffectManager_1f7e90 {
  public:
    unsigned int FUN_001f7e90_callback(char*);
};
struct CEffectManager_1f7f20 {
    bool run(bool);
};
} // namespace fn_f919337e
namespace math {
class Vector_1f7fa0 { public: float x, y, z; };
}
namespace fn_f919337e {
void* FUN_0008d690(unsigned int);
} // namespace fn_f919337e
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f919337e {
class CEffectManager_1f7fa0 {};
typedef int (CEffectManager_1f7fa0::*Fn_1f7fa0)(const char*, math::Vector_1f7fa0, math::Vector_1f7fa0);
class Registry_1f7fa0 { public:
    void FUN_001f7fa0(const char* a1, CEffectManager_1f7fa0* a2, Fn_1f7fa0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1f7fa0;
template<> class Closure3_1f7fa0<CEffectManager_1f7fa0, int, const char*, math::Vector_1f7fa0, math::Vector_1f7fa0> : public ScriptFunctionFields { public: virtual void v(); Fn_1f7fa0 fn; CEffectManager_1f7fa0* owner; Closure3_1f7fa0(CEffectManager_1f7fa0* o) { owner = o; } };
class Raw_1f7fa0 { public: void FUN_001f7720(const char*, Fn_1f7fa0); };
class CEffectManager_1f8050 {};
typedef unsigned int (CEffectManager_1f8050::*Fn_1f8050)(char*, float, float);
class Registry_1f8050 { public:
    void FUN_001f8050(const char* a1, CEffectManager_1f8050* a2, Fn_1f8050 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1f8050;
template<> class Closure3_1f8050<CEffectManager_1f8050, unsigned int, char*, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1f8050 fn; CEffectManager_1f8050* owner; Closure3_1f8050(CEffectManager_1f8050* o) { owner = o; } };
class Raw_1f8050 { public: void FUN_001f78c0(const char*, Fn_1f8050); };

} // namespace fn_f919337e

// 0x001f76c0 Method2<CEffectManager,int,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001f76c0.cpp
// sym: ??_G?$Method2@VCEffectManager@@HPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CEffectManager, int, const char *,math::Vector>::~Method2() {}


// 0x001f76e0 Method2<CEffectManager,int,const_char_*,math::Vector>::vfunc_2 (58 B): equivalent/0x001f76e0.cpp
// sym: ?vfunc_2@?$Method2@VCEffectManager@@HPBDVVector@math@@@@UAEXPAX00@Z @bb24390dc870 @w74df6adcba10
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Method2<CEffectManager,int,const_char_*,math::Vector>::vfunc_2 @ 0x001f76e0
template <> void Method2<CEffectManager, int, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f76e0 * manager = (CEffectManager_1f76e0 *)__p0; const EffectArguments * args = (const EffectArguments *)__p1; int * result = (int *)__p2;

    int value = (manager->*(*(int (CEffectManager_1f76e0::**)(const char *, math::Vector_1f76e0))&this->f_1c))(args->name, args->position);
    if (result) *result = value;
}

namespace fn_f919337e {

// 0x001f7720 FUN_001f7720 (89 B): matches/0x001f7720.cpp
// sym: ??0Method3_1f7720@fn_f919337e@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
Method3_1f7720::Method3_1f7720(const char* a, ScriptMemberFn b) : Function_1f7720(a, 3) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00424d4c);
    m1c = b;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(hulk_at_0048e10c);
    f.argTypes[2] = FUN_001d04d0(hulk_at_0048e10c);
}

} // namespace fn_f919337e

// 0x001f7780 Method3<CEffectManager,int,const_char_*,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x001f7780.cpp
// sym: ??_G?$Method3@VCEffectManager@@HPBDVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CEffectManager, int, const char *,math::Vector,math::Vector>::~Method3() {}


// 0x001f77a0 Method3<CEffectManager,int,const_char_*,math::Vector,math::Vector>::vfunc_2 (102 B): equivalent/0x001f77a0.cpp
// sym: ?vfunc_2@?$Method3@VCEffectManager@@HPBDVVector@math@@V23@@@UAEXPAX00@Z @7ff14e27db80 @w2db63ba4069d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CEffectManager,int,const_char_*,math::Vector,math::Vector>::vfunc_2 @ 0x001f77a0
template <> void Method3<CEffectManager, int, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f77a0 * obj = (CEffectManager_1f77a0 *)__p0; Args_1f77a0 * args = (Args_1f77a0 *)__p1; int * result = (int *)__p2;

    int r = (obj->*(*(int (CEffectManager_1f77a0::**)(const char *, Vector_1f77a0, Vector_1f77a0))&this->f_1c))(args->name, args->a, args->b);
    if (result)
        *result = r;
}


// 0x001f7860 Method2<CEffectManager,bool,int,math::Vector>::vfunc_0 (30 B): matches/0x001f7860.cpp
// sym: ??_G?$Method2@VCEffectManager@@_NHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CEffectManager, bool, int,math::Vector>::~Method2() {}


// 0x001f7880 Method2<CEffectManager,bool,int,math::Vector>::vfunc_2 (58 B): equivalent/0x001f7880.cpp
// sym: ?vfunc_2@?$Method2@VCEffectManager@@_NHVVector@math@@@@UAEXPAX00@Z @5070c124e04e @w8cf067245f4c
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Method2<CEffectManager,bool,int,math::Vector>::vfunc_2 @ 0x001f7880
template <> void Method2<CEffectManager, bool, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f7880 * object = (CEffectManager_1f7880 *)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = (object->*(*(bool (CEffectManager_1f7880::**)(int, math::Vector_1f7880))&this->f_1c))(args->id, args->position);
    if (result) *result = value;
}

namespace fn_f919337e {

// 0x001f78c0 FUN_001f78c0 (89 B): matches/0x001f78c0.cpp
// sym: ?Build@Method3_1f78c0@fn_f919337e@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
Method3_1f78c0* Method3_1f78c0::Build(const char* a, ScriptMemberFn b) {
    Base_001d0480(a, 3);
    vtable = ((hulk_intptr)DAT_00424d6c);
    field1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f919337e

// 0x001f7920 Method3<CEffectManager,unsigned_int,char_*,float,float>::vfunc_0 (30 B): matches/0x001f7920.cpp
// sym: ??_G?$Method3@VCEffectManager@@IPADMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CEffectManager, unsigned int, char *, float, float>::~Method3() {}


// 0x001f7940 Method3<CEffectManager,unsigned_int,char_*,float,float>::vfunc_2 (51 B): matches/0x001f7940.cpp
// sym: ?vfunc_2@?$Method3@VCEffectManager@@IPADMM@@UAEXPAX00@Z
template <> void Method3<CEffectManager, unsigned int, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f7940 * obj = (CEffectManager_1f7940 *)__p0; void * args = (void *)__p1; unsigned int * result = (unsigned int *)__p2;

    struct Args {
        char* a;
        float b;
        float c;
    };
    Args* p = (Args*)args;
    unsigned int (CEffectManager_1f7940::*fn)(char*, float, float) = (*(unsigned int (CEffectManager_1f7940::**)(char *, float, float))&this->f_1c);
    char* a = p->a;
    float b = p->b;
    float c = p->c;
    unsigned int r = (obj->*fn)(a, b, c);
    if (result)
        *result = r;
}


// 0x001f79c0 Method0<CEffectManager,float>::vfunc_0 (30 B): matches/0x001f79c0.cpp
// sym: ??_G?$Method0@VCEffectManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CEffectManager, float>::~Method0() {}


// 0x001f79e0 Method0<CEffectManager,float>::vfunc_2 (34 B): matches/0x001f79e0.cpp [wrapped: conflict: Function]
// sym: ?f2@Method0Base_1f79e0@fn_001f79e0@@UAEXPAX0PAM@Z
namespace fn_001f79e0 {
// Same code shape as 0x0002e080 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_1f79e0 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_1f79e0::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
} // namespace fn_001f79e0


// 0x001f7a50 Method1<CEffectManager,unsigned_int,char_*>::vfunc_0 (30 B): matches/0x001f7a50.cpp
// sym: ??_G?$Method1@VCEffectManager@@IPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CEffectManager, unsigned int, char *>::~Method1() {}


// 0x001f7a70 Method1<CEffectManager,unsigned_int,char_*>::vfunc_2 (29 B): matches/0x001f7a70.cpp [wrapped: conflict: Function; Method1]
// sym: ?f2@Method1@fn_001f7a70@@UAEXPAVCEffectManager@2@PAUArg@2@PAI@Z
namespace fn_001f7a70 {
class CEffectManager {
  public:
    unsigned int run(unsigned int);
};
struct Arg {
    unsigned int v;
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    typedef unsigned int (CEffectManager::*Fn)(unsigned int);
    Fn fn;
    virtual void f2(CEffectManager*, Arg*, unsigned int*);
};
inline unsigned int invoke(CEffectManager* obj, Method1::Fn f, unsigned int v) {
    return (obj->*f)(v);
}
void Method1::f2(CEffectManager* obj, Arg* arg, unsigned int* out) {
    Fn f = fn;
    unsigned int value = invoke(obj, f, arg->v);
    if (out)
        *out = value;
}
} // namespace fn_001f7a70


// 0x001f7ad0 Method1<CEffectManager,bool,bool>::vfunc_0 (30 B): matches/0x001f7ad0.cpp
// sym: ??_G?$Method1@VCEffectManager@@_N_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CEffectManager, bool, bool>::~Method1() {}


// 0x001f7af0 Method1<CEffectManager,bool,bool>::vfunc_2 (37 B): matches/0x001f7af0.cpp
// sym: ?vfunc_2@?$Method1@VCEffectManager@@_N_N@@UAEXPAX00@Z
template <> void Method1<CEffectManager, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; bool * b = (bool *)__p1; bool * out = (bool *)__p2;

    Fn_1f7af0 f = (*(Fn_1f7af0 *)&this->f_1c);
    bool bv = *b;
    bool v = (((Dummy_1f7af0*)a)->*f)(bv);
    if (out)
        *out = v;
}


// 0x001f7b20 FUN_001f7b20 (89 B): matches/0x001f7b20.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001f7b20@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001f7b20 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00424d3c[2];
extern void* hulk_at_00424dac[2];
extern void* TAB_48e134;

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h),
// then Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00424d3c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(&TAB_48e134);
    vfptr = (void*)hulk_at_00424dac;
    owner = a2;
}
} // namespace fn_001f7b20


// 0x001f7b80 Closure2<CEffectManager,int,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001f7b80.cpp
// sym: ??_G?$Method2@VCEffectManager@@_NHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CEffectManager, int, const char *,math::Vector>::~Closure2() {}


// 0x001f7ba0 Closure2<CEffectManager,int,const_char_*,math::Vector>::vfunc_2 (61 B): equivalent/0x001f7ba0.cpp [wrapped: conflict: Arguments; CEffectManager; Closure2]
// sym: ?vfunc_2@Closure2@fn_001f7ba0@@UAEXPAXPAUArguments@2@PAH@Z @69c5af852677 @w0dfc1d6ccf29
namespace fn_001f7ba0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CEffectManager,int,const_char_*,math::Vector>::vfunc_2 @ 0x001f7ba0
namespace math { struct Vector { float x,y,z; }; }
struct CEffectManager { int FUN_001f7ba0(int, math::Vector); };
struct Arguments { int id; math::Vector position; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, Arguments* args, int* result);
    char padding[0x18];
    int (CEffectManager::*method)(int, math::Vector);
    CEffectManager* manager;
};
void Closure2::vfunc_2(void* unused, Arguments* args, int* result) {
    int value = (manager->*method)(args->id, args->position);
    if (result) *result = value;
}
} // namespace fn_001f7ba0


// 0x001f7c10 Closure3<CEffectManager,int,const_char_*,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x001f7c10.cpp
// sym: ??_G?$Method3@VCEffectManager@@IPADMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CEffectManager, int, const char *,math::Vector,math::Vector>::~Closure3() {}


// 0x001f7c30 Closure3<CEffectManager,int,const_char_*,math::Vector,math::Vector>::vfunc_2 (12 B): matches/0x001f7c30.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_001f7c30@@UAEXHHH@Z
namespace fn_001f7c30 {
// Same code shape as 0x0002ff10 (propagated; names are from that function)
class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, int, int);
    char pad[0x18];
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int, int, int);
};
void Closure2::vfunc_2(int x, int a2, int a3) {
    Method2::vfunc_2(val, a2, a3);
}
} // namespace fn_001f7c30


// 0x001f7c40 FUN_001f7c40 (89 B): matches/0x001f7c40.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001f7c40@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001f7c40 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00424d5c[2];
extern void* hulk_at_00424dcc[2];
extern void* TAB_48e134;

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h),
// then Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00424d5c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = LookupFlag_001d04d0(&TAB_48e134);
    vfptr = (void*)hulk_at_00424dcc;
    owner = a2;
}
} // namespace fn_001f7c40


// 0x001f7ca0 Closure2<CEffectManager,bool,int,math::Vector>::vfunc_0 (30 B): matches/0x001f7ca0.cpp
// sym: ??_G?$Method1@VCEffectManager@@_N_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CEffectManager, bool, int,math::Vector>::~Closure2() {}


// 0x001f7cc0 Closure2<CEffectManager,bool,int,math::Vector>::vfunc_2 (61 B): equivalent/0x001f7cc0.cpp [wrapped: conflict: CEffectManager; Closure2; EffectArguments]
// sym: ?vfunc_2@Closure2@fn_001f7cc0@@UAEXPAXPBUEffectArguments@2@PA_N@Z @6c585092a365 @w54271f29a7dd
namespace fn_001f7cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CEffectManager,bool,int,math::Vector>::vfunc_2 @ 0x001f7cc0
namespace math { struct Vector { float x, y, z; }; }
struct CEffectManager { bool FUN_001f7cc0(int value, math::Vector position); };
struct EffectArguments { int value; math::Vector position; };
class Closure2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const EffectArguments *args, bool *result);
    char padding[0x18];
    bool (CEffectManager::*method)(int, math::Vector);
    CEffectManager *manager;
};
void Closure2::vfunc_2(void *unused, const EffectArguments *args, bool *result) {
    bool value = (manager->*method)(args->value, args->position);
    if (result) *result = value;
}
} // namespace fn_001f7cc0


// 0x001f7d50 Closure3<CEffectManager,unsigned_int,char_*,float,float>::vfunc_2 (54 B): equivalent/0x001f7d50.cpp [wrapped: conflict: Arguments; CEffectManager; Closure3]
// sym: ?vfunc_2@Closure3@fn_001f7d50@@UAEIPAXPAUArguments@2@PAI@Z @df53f4d6ac4d @w6fd122bfc109
namespace fn_001f7d50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CEffectManager,unsigned_int,char_*,float,float>::vfunc_2 @ 0x001f7d50
class CEffectManager {
public:
    unsigned int FUN_001f7d50(unsigned int, char *, float);
};
struct Arguments { unsigned int id; char *name; float value; };
class Closure3 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual unsigned int vfunc_2(void *unused, Arguments *arguments, unsigned int *result);
private:
    char padding[0x18];
    unsigned int (CEffectManager::*method)(unsigned int, char *, float);
    CEffectManager *manager;
};
unsigned int Closure3::vfunc_2(void *unused, Arguments *arguments, unsigned int *result)
{
    unsigned int value = (manager->*method)(arguments->id, arguments->name, arguments->value);
    if (result) *result = value;
    return value;
}
} // namespace fn_001f7d50


// 0x001f7df0 Closure0<CEffectManager,float>::vfunc_2 (35 B): matches/0x001f7df0.cpp
// sym: ?vfunc_2@?$Closure0@VCEffectManager@@M@@UAEXPAX00@Z
// Same code shape as 0x0002fe60 (propagated; names are from that function)
template <> void Closure0<CEffectManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_1f7df0* m = (*(CActorManager_1f7df0 * *)&this->f_20);
    Fn_1f7df0 fn = (*(Fn_1f7df0 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}


// 0x001f7e20 FUN_001f7e20 (76 B): matches/0x001f7e20.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001f7e20@@QAE@PADII@Z
namespace fn_001f7e20 {
// data: name1 = DAT_0049b95c, name2 = DAT_0049cad8

extern unsigned char __cdecl find_001d04d0(char*);
class Function_1f7e20 {
  public:
    Function_1f7e20(char*, int);
    virtual void f();
};
class Method1 : public Function_1f7e20 {
  public:
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    unsigned int x;
    Method1(char* p, unsigned int n) : Function_1f7e20(p, 1) {
        x = n;
        b = find_001d04d0(((char*)&DAT_0049b95c));
        a = find_001d04d0(((char*)&DAT_0049cad8));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    unsigned int y;
    Closure1(char* p, unsigned int n, unsigned int m);
    virtual void f();
};
Closure1::Closure1(char* p, unsigned int n, unsigned int m) : Method1(p, m) {
    y = n;
}
} // namespace fn_001f7e20


// 0x001f7e90 Closure1<CEffectManager,unsigned_int,char_*>::vfunc_2 (30 B): matches/0x001f7e90.cpp
// sym: ?vfunc_2@?$Closure1@VCEffectManager@@IPAD@@UAEXPAX00@Z
template <> void Closure1<CEffectManager, unsigned int, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { char ** argument = (char **)__p1; unsigned int * result = (unsigned int *)__p2;

    CEffectManager_1f7e90* m = (*(CEffectManager_1f7e90 * *)&this->f_20);
    unsigned int (CEffectManager_1f7e90::*fn)(char*) = (*(unsigned int (CEffectManager_1f7e90::**)(char *))&this->f_1c);
    unsigned int value = (m->*fn)(*argument);
    if (result)
        *result = value;
}


// 0x001f7eb0 FUN_001f7eb0 (76 B): matches/0x001f7eb0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001f7eb0@@QAE@HHH@Z
namespace fn_001f7eb0 {
// data: gValue = DAT_0048e0e4

extern "C++" __declspec(nothrow) unsigned char getFlag_001d04d0(void*);
class Function_1f7eb0 {
  public:
    Function_1f7eb0(int, int);
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    int y;
};
class Method1 : public Function_1f7eb0 {
  public:
    Method1(int p, int q) : Function_1f7eb0(p, 1) {
        x = q;
        b = getFlag_001d04d0(((int*)&DAT_0048e0e4));
        a = getFlag_001d04d0(((int*)&DAT_0048e0e4));
    }
    virtual void fn();
};
class Closure1 : public Method1 {
  public:
    Closure1(int p, int q, int r);
    virtual void fn();
};
Closure1::Closure1(int p, int q, int r) : Method1(p, r) {
    y = q;
}
} // namespace fn_001f7eb0


// 0x001f7f20 Closure1<CEffectManager,bool,bool>::vfunc_2 (38 B): matches/0x001f7f20.cpp
// sym: ?vfunc_2@?$Closure1@VCEffectManager@@_N_N@@UAEXPAX00@Z
template <> void Closure1<CEffectManager, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; bool * arg = (bool *)__p1; bool * out = (bool *)__p2;

    CEffectManager_1f7f20* o = (*(CEffectManager_1f7f20 * *)&this->f_20);
    bool b = *arg;
    bool (CEffectManager_1f7f20::*f)(bool) = (*(bool (CEffectManager_1f7f20::**)(bool))&this->f_1c);
    bool value = (o->*f)(b);
    if (out)
        *out = value;
}

namespace fn_f919337e {

// 0x001f7fa0 FUN_001f7fa0 (83 B): equivalent/0x001f7fa0.cpp
// sym: ?FUN_001f7fa0@Registry_1f7fa0@fn_f919337e@@QAEXPBDPAVCEffectManager_1f7fa0@2@P832@AEH0VVector_1f7fa0@math@@2@Z@Z @0858e1e010ba @wf8b6059f2ce7
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f7fa0 @ 0x001f7fa0
// FUN_001f7fa0 @ 0x001f7fa0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f7fa0::FUN_001f7fa0(const char* a1, CEffectManager_1f7fa0* a2, Fn_1f7fa0 a3) {
    typedef Closure3_1f7fa0<CEffectManager_1f7fa0, int, const char*, math::Vector_1f7fa0, math::Vector_1f7fa0> Alloc_1f7fa0;
    HULK_SIZE32(Alloc_1f7fa0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f7fa0));
    void* x = 0;
    if (m) {
        ((Raw_1f7fa0*)m)->FUN_001f7720(a1, a3);
        x = new (m) Closure3_1f7fa0<CEffectManager_1f7fa0, int, const char*, math::Vector_1f7fa0, math::Vector_1f7fa0>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f919337e

// 0x001f8000 FUN_001f8000 (70 B): matches/0x001f8000.cpp [wrapped: conflict: FUN_0008d690]
// sym: ?FUN_001f8000@Registry_1f8000@fn_001f8000@@QAEXPBDPAVOwner@2@P832@AE_NHVVector_1f8000@math@2@@Z@Z
namespace fn_001f8000 {
void* FUN_0008d690(unsigned int) throw();
namespace math { class Vector_1f8000 { public: float x, y, z; }; }
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef bool (Owner::*Fn_1f8000)(int, math::Vector_1f8000);
class Closure2_1f8000 : public ScriptClosureView {
  public:
    static void* operator new(hulk_uintptr n) throw() { return FUN_0008d690((unsigned int)n); }
    Closure2_1f8000(const char*, Owner*, Fn_1f8000) throw();
};
class Registry_1f8000 {
  public:
    void FUN_001f8000(const char* a1, Owner* a2, Fn_1f8000 a3);
};
void Registry_1f8000::FUN_001f8000(const char* a1, Owner* a2, Fn_1f8000 a3) {
    HULK_SIZE32(Closure2_1f8000, 0x24);
    Closure2_1f8000* e = new Closure2_1f8000(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(Closure2_1f8000 *)e);
}
} // namespace fn_001f8000

namespace fn_f919337e {

// 0x001f8050 FUN_001f8050 (83 B): equivalent/0x001f8050.cpp
// sym: ?FUN_001f8050@Registry_1f8050@fn_f919337e@@QAEXPBDPAVCEffectManager_1f8050@2@P832@AEIPADMM@Z@Z @b1e64d2555ad @wbd95c126b78c
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f8050 @ 0x001f8050
// FUN_001f8050 @ 0x001f8050  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f8050::FUN_001f8050(const char* a1, CEffectManager_1f8050* a2, Fn_1f8050 a3) {
    typedef Closure3_1f8050<CEffectManager_1f8050, unsigned int, char*, float, float> Alloc_1f8050;
    HULK_SIZE32(Alloc_1f8050, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f8050));
    void* x = 0;
    if (m) {
        ((Raw_1f8050*)m)->FUN_001f78c0(a1, a3);
        x = new (m) Closure3_1f8050<CEffectManager_1f8050, unsigned int, char*, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f919337e

// 0x001f80b0 FUN_001f80b0 (109 B): equivalent/0x001f80b0.cpp [wrapped: conflict: CEffectManager; Closure0; Method0]
// sym: ?FUN_001f80b0@Registry_1f80b0@fn_001f80b0@@QAEXPBDPAVCEffectManager@2@P832@AEMXZ@Z @ce4cd83c9d05 @w3266886c35f8
namespace fn_001f80b0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001f80b0 @ 0x001f80b0
// FUN_001f80b0 @ 0x001f80b0  (generated by work/closure/gen.py)
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

extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int size);


class CEffectManager { public: float FUN_dummy(); };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_1f80b0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1f80b0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1f80b0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1f80b0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1f80b0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001f80b0(const char* name, CEffectManager* owner, float (CEffectManager::*fn)());
};

void Registry_1f80b0::FUN_001f80b0(const char* name, CEffectManager* owner, float (CEffectManager::*fn)()) {
    typedef Closure0<CEffectManager, float> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CEffectManager, float>));
    Closure0<CEffectManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CEffectManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001f80b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001f81c0 FUN_001f81c0 (776 B): equivalent/0x001f81c0.cpp [wrapped: conflict: CEffectManager; Closure1; Function; Function2 (+2)]
// sym: ?FUN_001f81c0@CEffectManager@fn_001f81c0@@QAEXXZ @ec6b6e1e6640 @w4c1669df197d
namespace fn_001f81c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001f81c0 @ 0x001f81c0
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



void *FUN_0008d690(unsigned int size);

namespace math {
class Vector {
public:
    float x, y, z;
};
}

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char *get() { return ((const char*)&DAT_0048e100); } };
template <> struct TypeName<float> { static const char *get() { return ((const char*)&DAT_0048e128); } };
template <> struct TypeName<bool> { static const char *get() { return ((const char*)&DAT_0048e0e4); } };
template <> struct TypeName<unsigned int> { static const char *get() { return ((const char*)&DAT_0049b95c); } };
template <> struct TypeName<char *> { static const char *get() { return ((const char*)&DAT_0049cad8); } };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) Function : public ScriptFunctionFields {
public:
    virtual void f0();
    virtual void f1();
    void FUN_001d0480(const char *name, int arity);
    Function() {}
    __forceinline Function(const char *name, int arity) { FUN_001d0480(name, arity); }
};

class CEffectManager {
public:
    int FUN_001f7200(const char *name, math::Vector pos);
    int FUN_001f7280(int id, math::Vector pos);
    int FUN_001f7150(const char *name, math::Vector pos, math::Vector dir);
    unsigned int FUN_001f6f30(char *name, float a, float b);
    unsigned int FUN_001f6fc0(const char *name);
    unsigned int FUN_001f6e60(char *name);
    bool FUN_001f6ff0(bool on);
    bool FUN_001f7080(bool on);
    bool FUN_001f7110(bool on);
    void FUN_001f81c0();
};


template <class R, class A, class B>
class Function2 : public Function {
public:
    typedef R (*Fn)(A, B);
    __forceinline Function2(const char *name, Fn f) : Function(name, 2) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
        argTypes[1] = FUN_001d04d0(TypeName<B>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Method1 : public Function {
public:
    typedef R (T::*Fn)(A);
    __forceinline Method1(const char *name, Fn f) : Function(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
public:
    __forceinline Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

// Method3 instances whose constructors were not inlined
class __declspec(novtable) Method3Oriented : public Function {
public:
    typedef int (CEffectManager::*Fn)(const char *, math::Vector, math::Vector);
    __forceinline Method3Oriented(const char *name, Fn f) : Function() { FUN_001f7720(name, f); }
    void FUN_001f7720(const char *name, Fn f);
    Fn fn;
};

class __declspec(novtable) Method3Decal : public Function {
public:
    typedef unsigned int (CEffectManager::*Fn)(char *, float, float);
    __forceinline Method3Decal(const char *name, Fn f) : Function() { FUN_001f78c0(name, f); }
    void FUN_001f78c0(const char *name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Closure3;

template <>
class Closure3<CEffectManager, int, const char *, math::Vector, math::Vector> : public Method3Oriented {
public:
    __forceinline Closure3(const char *name, CEffectManager *o, Fn f) : Method3Oriented(name, f), owner(o) {}
    CEffectManager *owner;
};

template <>
class Closure3<CEffectManager, unsigned int, char *, float, float> : public Method3Decal {
public:
    __forceinline Closure3(const char *name, CEffectManager *o, Fn f) : Method3Decal(name, f), owner(o) {}
    CEffectManager *owner;
};

// closures whose constructors were out of line too
struct ClosureWorld {
    ClosureWorld *FUN_001f7b20(const char *name, CEffectManager *owner,
                               int (CEffectManager::*fn)(const char *, math::Vector));
};

struct Closure2_1f81c0 {
    Closure2_1f81c0 *FUN_001f7c40(const char *name, CEffectManager *owner,
                                int (CEffectManager::*fn)(int, math::Vector));
};

extern "C" void thunk_FUN_001b8750();
extern "C" void FUN_001f7120(float, float);

struct Registry_1f81c0 {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001e12b0(const char *name, void (*fn)());
    void FUN_001f80b0(const char *name, CEffectManager *owner,
                      unsigned int (CEffectManager::*fn)(const char *));
};
extern "C" Registry_1f81c0 *FUN_001d4c90();

void CEffectManager::FUN_001f81c0()
{
    Registry_1f81c0 *reg = FUN_001d4c90();
    reg->FUN_001e12b0("SetXBoxGamma", thunk_FUN_001b8750);

    { typedef Function2<void, float, float> Sized; HULK_SIZE32(Sized, 0x20); }
    void *mem = FUN_0008d690((int)sizeof(Function2<void, float, float>));
    Function2<void, float, float> *blur = 0;
    if (mem)
        blur = new (mem) Function2<void, float, float>("em_SetMotionBlur", FUN_001f7120);
    reg->FUN_001d3b70("em_SetMotionBlur", blur);

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    ClosureWorld *world = 0;
    if (mem)
        world = ((ClosureWorld *)mem)->FUN_001f7b20("em_AddWorldEffect", this, &CEffectManager::FUN_001f7200);
    reg->FUN_001d3b70("em_AddWorldEffect", world);

    { typedef Closure3<CEffectManager, int, const char *, math::Vector, math::Vector> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CEffectManager, int, const char *, math::Vector, math::Vector>));
    Closure3<CEffectManager, int, const char *, math::Vector, math::Vector> *oriented = 0;
    if (mem)
        oriented = new (mem) Closure3<CEffectManager, int, const char *, math::Vector, math::Vector>(
            "em_AddWorldEffectOriented", this, &CEffectManager::FUN_001f7150);
    reg->FUN_001d3b70("em_AddWorldEffectOriented", oriented);

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    Closure2_1f81c0 *setpos = 0;
    if (mem)
        setpos = ((Closure2_1f81c0 *)mem)->FUN_001f7c40("em_SetPositionWorldEffect", this, &CEffectManager::FUN_001f7280);
    reg->FUN_001d3b70("em_SetPositionWorldEffect", setpos);

    { typedef Closure3<CEffectManager, unsigned int, char *, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CEffectManager, unsigned int, char *, float, float>));
    Closure3<CEffectManager, unsigned int, char *, float, float> *decal = 0;
    if (mem)
        decal = new (mem) Closure3<CEffectManager, unsigned int, char *, float, float>(
            "CDQ_AddDecal", this, &CEffectManager::FUN_001f6f30);
    reg->FUN_001d3b70("CDQ_AddDecal", decal);

    reg->FUN_001f80b0("CDQ_Nearest", this, &CEffectManager::FUN_001f6fc0);

    { typedef Closure1<CEffectManager, unsigned int, char *> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CEffectManager, unsigned int, char *>));
    Closure1<CEffectManager, unsigned int, char *> *addps = 0;
    if (mem)
        addps = new (mem) Closure1<CEffectManager, unsigned int, char *>("CPS_AddPS", this, &CEffectManager::FUN_001f6e60);
    reg->FUN_001d3b70("CPS_AddPS", addps);

    { typedef Closure1<CEffectManager, bool, bool> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CEffectManager, bool, bool>));
    Closure1<CEffectManager, bool, bool> *rain = 0;
    if (mem)
        rain = new (mem) Closure1<CEffectManager, bool, bool>("em_EnableRain", this, &CEffectManager::FUN_001f6ff0);
    reg->FUN_001d3b70("em_EnableRain", rain);

    { typedef Closure1<CEffectManager, bool, bool> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CEffectManager, bool, bool>));
    Closure1<CEffectManager, bool, bool> *dust = 0;
    if (mem)
        dust = new (mem) Closure1<CEffectManager, bool, bool>("em_EnableDust", this, &CEffectManager::FUN_001f7080);
    reg->FUN_001d3b70("em_EnableDust", dust);

    { typedef Closure1<CEffectManager, bool, bool> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CEffectManager, bool, bool>));
    Closure1<CEffectManager, bool, bool> *debris = 0;
    if (mem)
        debris = new (mem) Closure1<CEffectManager, bool, bool>("em_EnableDebris", this, &CEffectManager::FUN_001f7110);
    reg->FUN_001d3b70("em_EnableDebris", debris);
}
} // namespace fn_001f81c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

