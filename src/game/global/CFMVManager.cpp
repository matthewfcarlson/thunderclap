// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001b7970..0x001b8690 (kind game, layer game, confidence high), dominant class CFMVManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff8e53b8 {
#define TREE_TU_END }
namespace fn_ff8e53b8 {} using namespace fn_ff8e53b8;
#include "game/global.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
struct Gfx {
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void set54(int);
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void set58(int);
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void reset91();
};
namespace fn_ff8e53b8 {
struct Resource_1b7970 {
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void stop();
};
struct Container_1b7970 {
    void FUN_00086400();
};
struct Control_1b7970 {
    void FUN_0008db60(int);
};
struct Manager_1b7970 {
    void FUN_001bf860(int);
};
struct Simulation {
    void FUN_001eb890();
    void FUN_001eb2a0(float, int);
};
struct Provider_1b7970 {
    Simulation* FUN_000862e0();
};
} // namespace fn_ff8e53b8
struct World {
    char pad[0x50];
    Manager_1b7970* manager;
    Provider_1b7970* provider;
};
namespace fn_ff8e53b8 {
void __cdecl thunk_FUN_00267090(void*);
struct Owner_1b7970 {
    char pad0[12];
    Resource_1b7970* resource;
    char pad10[0x108];
    Container_1b7970* container;
    Control_1b7970* control;
    int unknown120;
    void* allocation;
    int state;
    char pad12c[5];
    unsigned char active;
    void FUN_001b7970();
};
class Source_1b7a80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void Finish(int);
    virtual float Get();
};
class Target_1b7a80 {
  public:
    char pad[12];
    Source_1b7a80* source;
    char pad2[0x120];
    unsigned char done;
    float value;
    void Run();
};
class Child_1b7ac0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k(unsigned int);
};
class Owner_1b7ac0 {
  public:
    char pad[0xC];
    Child_1b7ac0* child;
    char pad2[0x120];
    unsigned char flag;
    unsigned int value;
    void target();
};
class CFEManager_1b7b60 {
  public:
    void Call(const char*, int);
};
class Function_1b7b60 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1b7be0;
typedef unsigned char(__fastcall* Fn_1b7be0)(CActorManager_1b7be0*);
} // namespace fn_ff8e53b8
class CFMVManager;
namespace fn_ff8e53b8 {
class Function_1b7c00 : public ScriptFunctionFields {
  public:
    virtual ~Function_1b7c00() throw() {}
    virtual void VFunc1() throw() {}
    virtual void VFunc2() throw() {}
    Function_1b7c00(const char* a, int b); // defined externally (FUN_001d0480)
};
class Method4_1b7c00 : public Function_1b7c00 {
  public:
    ScriptMemberFn m_fn; // 0x1c

    Method4_1b7c00(const char* a1, ScriptMemberFn a2);
    virtual void Invoke(float, float, float, float) throw() {}
    virtual ~Method4_1b7c00() throw() {}
};
} // namespace fn_ff8e53b8
extern "C" unsigned char __cdecl FUN_001d04d0(void*);
namespace fn_ff8e53b8 {
class CFMVManager_1b7c90 {
  public:
    void Fn(float, float, float, float);
};
class Function_1b7c90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CFMVManager_1b7c90*, float*, void*);
};
extern void* hulk_at_0041dc6c[];
class Ref_1b7cd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1b7cd0 {
  public:
    void* vptr;
    void Fin();
};
void Free_0008d330(void*) throw();
class CFMVManager_1b7cd0 : public Base_1b7cd0 {
  public:
    char pad[8];
    Ref_1b7cd0* mc;
    CFMVManager_1b7cd0* f0(unsigned char fl);
};
extern "C" int __cdecl GetValue();
class Sub_1b8110 {
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
    virtual void v10(int);
};
class Obj_1b8110 {
  public:
    char pad0[4];
    int value;
    char pad8;
    unsigned char active;
    char padA[2];
    Sub_1b8110* sub;
    char pad10[0x120];
    unsigned char pending;
    char pad131[3];
    int arg;
    void target(int);
};
class Device_1b8160 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void Finish();
    virtual void Stop(int);
    virtual float Get();
};
class Thing_1b8160 {
  public:
    char pad[0xc];
    Device_1b8160* device;
    char pad2[0x120];
    unsigned char done;
    float value;
    void Update();
};
class CActorManager_1b8220 {
  public:
    void Method(const char*, float);
};
struct Pair_1b8220 {
    const char* s;
    float f;
};
class CActorManager_1b82a0;
typedef unsigned char(__fastcall* Fn_1b82a0)(CActorManager_1b82a0*);
class CFMVManager_1b8310 {
  public:
    void Run(float, float, float, float);
};
class Function_1b8310 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const float*, void*);
};
class Inner_1b8350 {
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
    virtual void v10(int);
};
class Thing_1b8350 {
  public:
    char p0[4];
    int value;
    char p8;
    char flag9;
    char pa[2];
    Inner_1b8350* inner;
    char p10[0x104];
    unsigned char b114;
    char p115[0x1b];
    char b130;
    char p131[3];
    int arg134;
    void Helper_001b7f40(int, unsigned char);
    void Run(hulk_intptr, int);
};
extern int getval_00267f80();
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_ff8e53b8
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_ff8e53b8 {
class CFMVManager_1b8490 {};
typedef void (CFMVManager_1b8490::*Fn_1b8490)(float, float, float, float);
class Registry_1b8490 { public:
    void FUN_001b8490(const char* a1, CFMVManager_1b8490* a2, Fn_1b8490 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1b8490;
template<> class Closure4_1b8490<CFMVManager_1b8490, void, float, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_001b82f0(int); Fn_1b8490 fn; CFMVManager_1b8490* owner; Closure4_1b8490(CFMVManager_1b8490* o) { owner = o; } };
class Raw_1b8490 { public: void FUN_001b7c00(const char*, Fn_1b8490); };


// 0x001b7970 FUN_001b7970 (246 B): matches/0x001b7970.cpp
// sym: ?FUN_001b7970@Owner_1b7970@fn_ff8e53b8@@QAEXXZ
void Owner_1b7970::FUN_001b7970() {
    if (!resource)
        return;
    DAT_0052c2a8->reset91();
    DAT_0052c2a8->set54(1);
    DAT_0052c2a8->set58(1);
    (*(unsigned char*)&DAT_004e222c) = 1;
    (*(unsigned char*)&DAT_004e222d) = 1;
    if (resource)
        resource->stop();
    if (resource) {
        Resource_1b7970* old = resource;
        resource = 0;
        old->release();
    }
    Container_1b7970* c = container;
    state = 0;
    c->FUN_00086400();
    if (allocation) {
        thunk_FUN_00267090(allocation);
        allocation = 0;
    }
    allocation = 0;
    DAT_004dd700->manager->FUN_001bf860(1);
    DAT_004dd700->provider->FUN_000862e0()->FUN_001eb890();
    for (int i = 0; i < 10; ++i)
        DAT_004dd700->provider->FUN_000862e0()->FUN_001eb2a0(0.01f, 0);
    Control_1b7970* ctl = control;
    active = 0;
    ctl->FUN_0008db60(0);
}


// 0x001b7a80 FUN_001b7a80 (54 B): matches/0x001b7a80.cpp
// sym: ?Run@Target_1b7a80@fn_ff8e53b8@@QAEXXZ
void Target_1b7a80::Run() {
    if (!done && source != 0) {
        value = source->Get();
        if (source != 0)
            source->Finish(0);
        done = 1;
    }
}


// 0x001b7ac0 FUN_001b7ac0 (41 B): matches/0x001b7ac0.cpp
// sym: ?target@Owner_1b7ac0@fn_ff8e53b8@@QAEXXZ
void Owner_1b7ac0::target() {
    if (flag && child) {
        child->k(value);
        flag = 0;
    }
}

} // namespace fn_ff8e53b8

// 0x001b7b40 Method2<CFMVManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x001b7b40.cpp
// sym: ??_G?$Method2@VCFMVManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CFMVManager, void, const char *, int>::~Method2() {}


// 0x001b7b60 Method2<CFMVManager,void,const_char_*,int>::vfunc_2 (23 B): matches/0x001b7b60.cpp
// sym: ?vfunc_2@?$Method2@VCFMVManager@@XPBDH@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CFMVManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1b7b60* m = (CFEManager_1b7b60*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1b7b60::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CFMVManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b7b40)
#endif


// 0x001b7bc0 Method0<CFMVManager,bool>::vfunc_0 (30 B): matches/0x001b7bc0.cpp
// sym: ??_G?$Method0@VCFMVManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CFMVManager, bool>::~Method0() {}


// 0x001b7be0 Method0<CFMVManager,bool>::vfunc_2 (22 B): matches/0x001b7be0.cpp
// sym: ?vfunc_2@?$Method0@VCFMVManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CFMVManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b7be0 * obj = (CActorManager_1b7be0 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_1b7be0 fn = (*(Fn_1b7be0 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method0<CFMVManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b7bc0)
#endif

namespace fn_ff8e53b8 {

// 0x001b7c00 FUN_001b7c00 (102 B): matches/0x001b7c00.cpp
// sym: ??0Method4_1b7c00@fn_ff8e53b8@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
Method4_1b7c00::Method4_1b7c00(const char* a1, ScriptMemberFn a2) : Function_1b7c00(a1, 4) {
    m_fn = a2;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
}

} // namespace fn_ff8e53b8

// 0x001b7c70 Method4<CFMVManager,void,float,float,float,float>::vfunc_0 (30 B): matches/0x001b7c70.cpp
// sym: ??_G?$Method4@VCFMVManager@@XMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CFMVManager, void, float, float, float, float>::~Method4() {}


// 0x001b7c90 Method4<CFMVManager,void,float,float,float,float>::vfunc_2 (53 B): matches/0x001b7c90.cpp
// sym: ?vfunc_2@?$Method4@VCFMVManager@@XMMMM@@UAEXPAX00@Z
template <> void Method4<CFMVManager, void, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CFMVManager_1b7c90 * obj = (CFMVManager_1b7c90 *)__p0; float * p = (float *)__p1; void * b = (void *)__p2;

    float f0 = *p++;
    float f1 = *p++;
    (obj->*(*(void (CFMVManager_1b7c90::**)(float, float, float, float))&this->f_1c))(f0, f1, p[0], p[1]);
}
#if defined(HULK_PTR64)
template class Method4<CFMVManager, void, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b7c70)
#endif

namespace fn_ff8e53b8 {

// 0x001b7cd0 CFMVManager::vfunc_0 (50 B): matches/0x001b7cd0.cpp
// sym: ?f0@CFMVManager_1b7cd0@fn_ff8e53b8@@QAEPAV12@E@Z
CFMVManager_1b7cd0* CFMVManager_1b7cd0::f0(unsigned char fl) {
    vptr = hulk_at_0041dc6c;
    _ReadWriteBarrier();
    Ref_1b7cd0* t = mc;
    if (t) {
        mc = 0;
        t->Release();
    }
    if (fl & 1)
        Free_0008d330(this);
    return this;
}

} // namespace fn_ff8e53b8

// 0x001b7d10 FUN_001b7d10 (560 B): equivalent/0x001b7d10.cpp [wrapped: conflict: World]
// sym: ?FUN_001b7d10@Player_1b7d10@fn_001b7d10@@QAEXPAVPadManager@2@PAVVoices@2@@Z @c6fd6ef5229d @wa1409e3e14b4
namespace fn_001b7d10 {
// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 39/42, incomplete)
// FUN_001b7d10 @ 0x001b7d10
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

class Source_1b7d10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual int vf12();
    virtual void vf13();
    virtual float vf14();
    virtual unsigned int vf15();
};

class Mixer {
public:
    void FUN_001c05d0(float a, float b);
};

struct World {
    char pad0[0x50];
    Mixer *mixer;
};

class Pad_1b7d10 {
public:
    void FUN_000af0f0(unsigned int *out);
};

class PadManager {
public:
    Pad_1b7d10 *FUN_000af3a0(int index);
};

class Voices {
public:
    int pad0[4];
    int count;
    float FUN_000afe60();
    float FUN_000afe70();
    Voices *FUN_000afe40(int index);
    void FUN_000af530(int voice, int slot, float v);
    void FUN_000af650(int voice, int slot, int v);
};

struct Entry_1b7d10 {
    float time;
    float gain0;
    float gain1;
    int pan;
};

struct EntryList_1b7d10 {
    int count;
    Entry_1b7d10 entries[1];
};

struct Status_1b7d10 {
    int pad0;
    int state;
};


extern "C" void FUN_00333ef0();
unsigned int FUN_00267f80();

class Player_1b7d10 {
public:
    void FUN_001b7d10(PadManager *pads, Voices *voices);
    void FUN_001b7970();

    char pad0[4];
    unsigned int deadline;
    char done;
    char restart;
    char pad1[2];
    Source_1b7d10 *source;
    char pad2[0x124 - 0x10];
    EntryList_1b7d10 *list;
    Status_1b7d10 *status;
};

void Player_1b7d10::FUN_001b7d10(PadManager *pads, Voices *voices)
{
    if (source == 0 || done)
        return;
    if (source->vf12() == 0) {
        FUN_00333ef0();
        FUN_001b7970();
        return;
    }
    if (status->state == -1) {
        FUN_001b7970();
        return;
    }
    float f = source->vf14();
    unsigned int n = source->vf15();
    DAT_004dd700->mixer->FUN_001c05d0((float)n, f);
    if (FUN_00267f80() >= deadline && status->state == -2 && pads != 0) {
        unsigned int pad[41];
        pads->FUN_000af3a0(0)->FUN_000af0f0(pad);
        if (pad[0] == 1 || pad[12] == 1 || pad[3] == 1 || pad[18] == 1) {
            status->state = 10;
            restart = 1;
        }
    }
    if (list == 0)
        return;
    if (voices == 0)
        return;
    for (int i = 0; i < list->count; i++) {
        Entry_1b7d10 *e = &list->entries[i];
        if (!(e->time > 0.0f))
            continue;
        int pos = source->vf15();
        if (pos < (int)(source->vf14() * e->time))
            continue;
        Voices *v = voices->FUN_000afe40(0);
        if (v == 0)
            continue;
        for (int s = 0; s < v->count; s++) {
            v->FUN_000af530(s, 0, voices->FUN_000afe60() * (e->gain0 * 0.01f));
            v->FUN_000af530(s, 1, voices->FUN_000afe70() * (e->gain1 * 0.01f));
            v->FUN_000af650(s, 0, e->pan);
            v->FUN_000af650(s, 1, e->pan);
        }
        e->time = -1.0f;
    }
}
} // namespace fn_001b7d10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff8e53b8 {

// 0x001b8110 FUN_001b8110 (78 B): matches/0x001b8110.cpp
// sym: ?target@Obj_1b8110@fn_ff8e53b8@@QAEXH@Z
// data: gFlag_1b8110 = DAT_004e222c
void Obj_1b8110::target(int x) {
    if (sub) {
        active = 0;
        sub->v8();
        value = GetValue() + x;
        (*(unsigned char*)&DAT_004e222c) = 1;
        if (pending && sub) {
            sub->v10(arg);
            pending = 0;
        }
    }
}


// 0x001b8160 FUN_001b8160 (63 B): matches/0x001b8160.cpp
// sym: ?Update@Thing_1b8160@fn_ff8e53b8@@QAEXXZ
void Thing_1b8160::Update() {
    if (device) {
        if (!done) {
            value = device->Get();
            if (device)
                device->Stop(0);
            done = 1;
        }
        device->Finish();
    }
}

} // namespace fn_ff8e53b8

// 0x001b81a0 FUN_001b81a0 (89 B): matches/0x001b81a0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001b81a0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001b81a0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_0041dc74[2];
extern void* hulk_at_0041dcc4[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_0041dc74;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_0041dcc4;
    owner = a2;
}
} // namespace fn_001b81a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b8200 Closure2<CFMVManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x001b8200.cpp
// sym: ??_GMethod4_1b7c00@fn_ff8e53b8@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CFMVManager, void, const char *, int>::~Closure2() {}


// 0x001b8220 Closure2<CFMVManager,void,const_char_*,int>::vfunc_2 (22 B): matches/0x001b8220.cpp
// sym: ?vfunc_2@?$Closure2@VCFMVManager@@XPBDH@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CFMVManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1b8220 * p = (Pair_1b8220 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1b8220 * *)&this->f_20)->*(*(void (CActorManager_1b8220::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x001b82a0 Closure0<CFMVManager,bool>::vfunc_2 (23 B): matches/0x001b82a0.cpp
// sym: ?vfunc_2@?$Closure0@VCFMVManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CFMVManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_1b82a0* o = (*(CActorManager_1b82a0 * *)&this->f_20);
    Fn_1b82a0 fn = (*(Fn_1b82a0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}


// 0x001b8310 Closure4<CFMVManager,void,float,float,float,float>::vfunc_2 (52 B): matches/0x001b8310.cpp
// sym: ?vfunc_2@?$Closure4@VCFMVManager@@XMMMM@@UAEXPAX00@Z
template <> void Closure4<CFMVManager, void, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const float * p = (const float *)__p1; void * b = (void *)__p2;

    volatile int x = *(int*)p++;
    volatile int y = *(int*)p++;
    ((*(CFMVManager_1b8310 * *)&this->f_20)->*(*(void (CFMVManager_1b8310::**)(float, float, float, float))&this->f_1c))(*(float*)&x, *(float*)&y, *p, *(p + 1));
}

namespace fn_ff8e53b8 {

// 0x001b8350 FUN_001b8350 (99 B): matches/0x001b8350.cpp
// sym: ?Run@Thing_1b8350@fn_ff8e53b8@@QAEXHH@Z
// data: gflag = DAT_004e222c
void Thing_1b8350::Run(hulk_intptr a, int b) {
    Helper_001b7f40(a, b114);
    if (inner) {
        flag9 = 0;
        inner->v8();
        value = getval_00267f80() + b;
        (*(unsigned char*)&DAT_004e222c) = 1;
        if (b130 && inner) {
            inner->v10(arg134);
            b130 = 0;
        }
    }
}

} // namespace fn_ff8e53b8

// 0x001b83c0 FUN_001b83c0 (14 B): matches/0x001b83c0.cpp
// sym: ?FUN_001b83c0@Object_1b83c0@owners@@QAEXXZ
void owners::Object_1b83c0::FUN_001b83c0() {
    FUN_001b8350(data, value);
}


// 0x001b8420 FUN_001b8420 (109 B): equivalent/0x001b8420.cpp [wrapped: conflict: CFMVManager; Closure0; Method0]
// sym: ?FUN_001b8420@Registry_1b8420@fn_001b8420@@QAEXPBDPAVCFMVManager@2@P832@AE_NXZ@Z @b03f50219b52 @w3445b509cae0
namespace fn_001b8420 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001b8420 @ 0x001b8420
// FUN_001b8420 @ 0x001b8420  (generated by work/closure/gen.py)
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


class CFMVManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1b8420 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1b8420(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1b8420 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1b8420(name, 0) {
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

struct Registry_1b8420 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001b8420(const char* name, CFMVManager* owner, bool (CFMVManager::*fn)());
};

void Registry_1b8420::FUN_001b8420(const char* name, CFMVManager* owner, bool (CFMVManager::*fn)()) {
    typedef Closure0<CFMVManager, bool> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CFMVManager, bool>));
    Closure0<CFMVManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CFMVManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001b8420
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff8e53b8 {

// 0x001b8490 FUN_001b8490 (83 B): equivalent/0x001b8490.cpp
// sym: ?FUN_001b8490@Registry_1b8490@fn_ff8e53b8@@QAEXPBDPAVCFMVManager_1b8490@2@P832@AEXMMMM@Z@Z @d1f25a823008 @w927d2fe360be
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001b8490 @ 0x001b8490
// FUN_001b8490 @ 0x001b8490  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1b8490::FUN_001b8490(const char* a1, CFMVManager_1b8490* a2, Fn_1b8490 a3) {
    typedef Closure4_1b8490<CFMVManager_1b8490, void, float, float, float, float> Alloc_1b8490;
    HULK_SIZE32(Alloc_1b8490, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1b8490));
    void* x = 0;
    if (m) {
        ((Raw_1b8490*)m)->FUN_001b7c00(a1, a3);
        x = new (m) Closure4_1b8490<CFMVManager_1b8490, void, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_ff8e53b8

// 0x001b84f0 FUN_001b84f0 (298 B): equivalent/0x001b84f0.cpp [wrapped: conflict: CFMVManager; Closure2; Closure4; Method4]
// sym: ??0CFMVManager@fn_001b84f0@@QAE@XZ @62e6686c1612 @wd76bd3d618ef
namespace fn_001b84f0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_001b84f0 @ 0x001b84f0
class CFMVManager;

struct HeapObj {
    static void* operator new(size_t size) HULK_NEW_THROW;
};

class MethodBase_1b84f0 : public HeapObj {
  public:
    virtual void* m0_001b82f0(int);
    char pad_04[0x1c - 4];
};

template <class T, class R, class A, class B, class C, class D>
class Method4 : public MethodBase_1b84f0 {
  public:
    typedef R (T::*Fn)(A, B, C, D);
    Method4(const char* name, Fn fn) throw();
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D>
class Closure4 : public Method4<T, R, A, B, C, D> {
  public:
    typedef R (T::*Fn)(A, B, C, D);
    Closure4(const char* name, T* owner, Fn f) throw() : Method4<T, R, A, B, C, D>(name, f), owner(owner) {}
    T* owner;
};

struct Closure2 {
    Closure2* FUN_001b81a0(const char* name, CFMVManager* owner, void (CFMVManager::*fn)(const char*, int));
};

struct Registry_1b84f0 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_001b8420(const char* name, CFMVManager* owner, bool (CFMVManager::*fn)());
};

class CFMVManager {
  public:
    CFMVManager();
    virtual void* v0_001b7cd0(char);
    int field_04;
    char field_08;
    char field_09;
    void* field_0c;             // (x64t9-mgr) the movie object; 0x118 its state, 0x11c ... 0x12c the managers
    int field_10;               // 0x001b7260 stores and the rumble buffer (0x001b7290)
    char field_14;
    char pad_15[0x114 - 0x15];
    char field_114;
    char pad_115[3];
    void* field_118;
    void* field_11c;
    void* pad_120;
    void* field_124;
    int field_128;
    void* field_12c;
    char field_130;
    char field_131;
    char pad_132[2];
    int field_134;

    void FUN_001b7960(const char*, int);
    bool FUN_001b7910();
    void FUN_001b7290(float, float, float, float);
    bool FUN_001b6f00();
};
HULK_MGR_SAME(CFMVManager, HulkFMVManager);   // include/decls/managers.h

extern "C" Registry_1b84f0* FUN_001d4c90();
extern "C" void* FUN_0008d690(unsigned size);

CFMVManager::CFMVManager() {
    field_04 = 0;
    field_08 = 0;
    field_09 = 0;
    field_0c = 0;
    field_10 = 0x7d0;
    field_114 = 1;
    field_118 = 0;
    field_11c = 0;
    field_124 = 0;
    field_128 = 0;
    field_12c = 0;
    field_130 = 0;
    field_131 = 0;
    field_134 = 0;

    Registry_1b84f0* reg = FUN_001d4c90();

    Closure2* playMovie = (Closure2*)FUN_0008d690(0x24);
    if (playMovie != 0)
        playMovie = playMovie->FUN_001b81a0("fmvm_PlayMovie", this, &CFMVManager::FUN_001b7960);
    reg->FUN_001d3b70("fmvm_PlayMovie", playMovie);

    Closure2* playMovieAudio = (Closure2*)FUN_0008d690(0x24);
    if (playMovieAudio != 0)
        playMovieAudio = playMovieAudio->FUN_001b81a0("fmvm_PlayMovieWithAudio", this, &CFMVManager::FUN_001b7960);
    reg->FUN_001d3b70("fmvm_PlayMovieWithAudio", playMovieAudio);

    reg->FUN_001b8420("fmvm_IsPlaying", this, &CFMVManager::FUN_001b7910);

    Closure4<CFMVManager, void, float, float, float, float>* rumble =
        new Closure4<CFMVManager, void, float, float, float, float>("fmvm_SetRumbleEvent", this, &CFMVManager::FUN_001b7290);
    reg->FUN_001d3b70("fmvm_SetRumbleEvent", rumble);

    reg->FUN_001b8420("fmvm_GetUserSkippedLastTime", this, &CFMVManager::FUN_001b6f00);
    field_14 = 0;
}
} // namespace fn_001b84f0

