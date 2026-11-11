// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0ab0..0x001f2db0 (kind game, layer game, confidence high), dominant class CSoundSystem
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffeee61e {
#define TREE_TU_END }
namespace fn_ffeee61e {} using namespace fn_ffeee61e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffeee61e {
class CFEManager_1f0ad0 {
  public:
    void Call(const char*, int);
};
class Function_1f0ad0 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_004246cc[];
struct Function_1f0af0 {
    hulk_uintptr vt;
    void Init_001d0480(const char*, int);
};
struct Method3_1f0af0 : Function_1f0af0 {
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
    Method3_1f0af0* Run(const char*, ScriptMemberFn);
};
struct CSoundSystem_1f0b70 {};
struct CallArgs { char* first; char* second; float third; };
class CActorManager_1f0bf0 {
  public:
    void f();
};
extern "C" char DAT_004246ec[];
class Function_1f0c00 {
  public:
    Function_1f0c00(const char*, int);
};
class Method6_1f0c00 : public Function_1f0c00 {
  public:
    void* vftable;           // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn p1c;      // 0x1c
    Method6_1f0c00(const char*, ScriptMemberFn);
};
struct Function_1f0ca0 {
    virtual void f0();
    virtual void f1();
};
void FUN_001f0cc0(const char*, const char*, const char*, int);
class Obj {
  public:
    void method(int, int, int, int, int, int);
};
typedef void (Obj::*Callback)(int, int, int, int, int, int);
class Function_1f0d10 {
  public:
    Function_1f0d10(void* a, int n);
    virtual void* f0_001f0d80(int);
    char pad[12];
};
class Method4_1f0d10 : public Function_1f0d10 {
  public:
    Method4_1f0d10(void* a, hulk_intptr b);
    char m10, m11, m12, m13;
    int pad14;
    char m18;
    char pad19[3];
    int m1c;
};
extern "C" char __cdecl Lookup(const char* s);
struct CSoundSystem_1f0da0 {
};
struct Function_1f0da0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSoundSystem_1f0da0 *, void *, void *);
};
struct Arguments {
    char *first;
    char *second;
    float third;
    float fourth;
};
extern "C" char DAT_0042470c[];
class Method5_1f0dd0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn p1c;      // 0x1c
    void FUN_001d0480(const char*, int);
    Method5_1f0dd0* Init(const char*, ScriptMemberFn);
};
struct Function_1f0e70 {
    virtual void f0();
    virtual void f1();
};
void FUN_001f0e90(const char*, const char*, const char*, int);
extern "C" unsigned char GetValue(const char*);
extern void* hulk_at_0042471c;
class Base_1f0ed0 {
  public:
    void Init_001d0480(void*, int);
};
class Method6_1f0ed0 {
  public:
    Method6_1f0ed0(void* p, hulk_intptr x);
    void* vptr;
    char pad4[12];
    unsigned char m10, m11, m12, m13, m14, m15;
    char pad16[2];
    unsigned char m18;
    char pad19[3];
    int m1c;
};
struct Function_1f0f70 {
    virtual void f0();
    virtual void f1();
};
void FUN_001f0f90(const char*, const char*, const char*, int);
class Dummy_1f1030 {
  public:
    void Call(void*);
};
class Function_1f1050 : public ScriptFunctionFields {
  public:
    Function_1f1050(const char*, int);
    virtual void X();
};
class Method3_1f1050 : public Function_1f1050 {
  public:
    virtual void X();
    ScriptMemberFn m1c;  // 0x1c
    Method3_1f1050(const char* a, ScriptMemberFn c);
};
struct CSoundSystem_1f10d0 {
    void FUN_001f10d0(char *, float, float);
};
struct SoundArguments {
    char *name;
    float first;
    float second;
};
struct Function_1f10d0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CFEManager_1f1160 {
  public:
    void Call(const char*, int);
};
class Function_1f1160 {
  public:
    virtual void f0();
    virtual void f1();
};
class CFEManager_1f11f0 {
  public:
    void Call(const char*, int);
};
class Function_1f11f0 {
  public:
    virtual void f0();
    virtual void f1();
};
extern char DAT_0042476c[];
extern "C" void *__cdecl FUN_00263ed0(int size, int tag);
void *__cdecl FUN_0008d710(int size, int tag);
struct SoundBank_1f1270 {
    hulk_intptr vptr;
    int f04;
    char pad08[0x198 - 8];
    int f198;
    char pad19c[0x4bc - 0x19c];
    int f4bc;
    char pad4c0[0x510 - 0x4c0];
    int f510, f514, f518, f51c;
    char f520;
    char pad521[3];
};
struct SoundEngine {
    SoundEngine *FUN_001f4ba0(SoundBank_1f1270 *bank);
};
class SoundResourceManager;
class SoundResourceManager {
public:
    SoundEngine *engine;
    SoundBank_1f1270 *bank;
    int f08;
    int f0c;
    SoundResourceManager *FUN_001f1270();
};
class B_1f1310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};
class Aux_1f1310 {
  public:
    void Fnf_0027af50();
};
extern void done_0008d330(void*);
class C_1f1310 {
  public:
    void* a;
    B_1f1310* b;
};
struct Child_1f1350 {
    char pad[8];
};
struct Item_1f1350 {
    char pad0[8];
    int a;
    int b;
    int c;
    unsigned char flag;
    char pad15[3];
    Child_1f1350 child;
    float value;
    int pad24;
    void Process_001effc0(int);
};
struct Owner_1f1350 {
    char pad0[12];
    Item_1f1350* items;
    void Run(int);
};
struct Value_1f13b0 {
    unsigned int data[2];
    void FUN_0027af00();
    void FUN_0027af50();
};
struct Key_1f13b0 {
    Value_1f13b0 elements[8];
    char extra[8];
    void FUN_001f0090(void* source);
};
struct Bucket_1f13b0;
extern void* __cdecl FUN_0008d710(unsigned int size, unsigned int kind);
struct Item {
  public:
    void *FUN_001f0150(void *, void *, void *);
    Item *FUN_001f01c0(void *a, void *b, void *c);
    int FUN_001f04e0(void*, void*, unsigned, unsigned);
};
struct Manager {
  public:
    void FUN_001ef260(void *);
    void FUN_001ef260(Item *item);
    void FUN_001ef260(int);
};
class Mgr_1f1600 {
public:
    void FUN_001ef260(void *p);
};
struct CSoundCommand_PlayTunableEvent_nv_1f1600 {
    void *FUN_001f0230(int a, int b, int c, int d, int e, int f);
};
class Mgr_1f1670 {
public:
    void FUN_001ef260(void *p);
};
struct CSoundCommand_SetLoopPitchEvent_nv_1f1670 {
    void *FUN_001f03a0(int a, int b, int c, int d, int e);
};
struct Elem_1f1c80 {
    virtual void Del(int);
    char pad[4];
    Elem_1f1c80* next;
};
struct Item_1f1c80 {
    char pad[0xc];
    Item_1f1c80* next;
    Elem_1f1c80* list;
    void Clean_0027af50();
};
struct Node {
  public:
    union { unsigned int a; Node* first; };
    union { unsigned int b; Item_1f1c80* second; };
    Bucket_1f13b0* owner;
    Node* next;
    Value_1f13b0 value;
    void Run();
};
struct Bucket_1f13b0 { Node* first; };
struct Object {
    Bucket_1f13b0* FUN_001efb80(Key_1f13b0* key);
    void FUN_001f13b0(void* value, void* source);
};
void __cdecl Destroy_0008d330(void*);
class CActorManager_1f1d70 {
  public:
    void Method(const char*, float);
};
struct Pair_1f1d70 {
    const char* s;
    float f;
};
struct CSoundSystem_1f1de0 {
    void FUN_001f1de0(char *, char *, float);
};
struct SoundArgs { char *first; char *second; float volume; };
class CActorManager_1f1e60 {
  public:
    void run();
};
class CSoundSystem_1f1ec0 {
  public:
    void Play(char*, char*, float, float, float, float);
};
struct CSoundSystem_1f1f60 { void FUN_001f1f60(char*, char*, float, float); };
class CSoundSystem_1f1fe0;
typedef void (CSoundSystem_1f1fe0::*SoundMethod)(char*, char*, float, float, float);
class CSoundSystem_1f1fe0 {
  public:
    void dummy();
};
class CSoundSystem_1f2070 {
  public:
    void Play(char*, char*, char*, float, float, float);
};
class CActorManager_1f2120 {
  public:
    void invoke(const char*);
};
class CActorManager_1f2230 {
  public:
    void Method(const char*, float);
};
struct Pair_1f2230 {
    const char* s;
    float f;
};
class CActorManager_1f22d0 {
  public:
    void Method(const char*, float);
};
struct Pair_1f22d0 {
    const char* s;
    float f;
};
class A_1f22f0 {
  public:
    void FnF_001e95c0(float, bool);
};
class B_1f22f0 {
  public:
    void FnG_001f64c0(float, bool);
};
class C_1f22f0 {
  public:
    B_1f22f0* b;
    A_1f22f0* a;
    void FnH_001f1350(float);
    void Run(float, bool);
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_ffeee61e
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_ffeee61e {
class CSoundSystem_1f2390 {};
typedef void (CSoundSystem_1f2390::*Fn_1f2390)(char*, char*, float);
class Registry_1f2390 { public:
    void FUN_001f2390(const char* a1, CSoundSystem_1f2390* a2, Fn_1f2390 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1f2390;
template<> class Closure3_1f2390<CSoundSystem_1f2390, void, char*, char*, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1f2390 fn; CSoundSystem_1f2390* owner; Closure3_1f2390(CSoundSystem_1f2390* o) { owner = o; } };
class Raw_1f2390 { public: void FUN_001f0af0(const char*, Fn_1f2390); };
class CSoundSystem_1f2460 {};
typedef void (CSoundSystem_1f2460::*Fn_1f2460)(char*, char*, float, float, float, float);
class Registry_1f2460 { public:
    void FUN_001f2460(const char* a1, CSoundSystem_1f2460* a2, Fn_1f2460 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_1f2460;
template<> class Closure6_1f2460<CSoundSystem_1f2460, void, char*, char*, float, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1f2460 fn; CSoundSystem_1f2460* owner; Closure6_1f2460(CSoundSystem_1f2460* o) { owner = o; } };
class Raw_1f2460 { public: void FUN_001f0c00(const char*, Fn_1f2460); };
class CSoundSystem_1f24c0 {};
typedef void (CSoundSystem_1f24c0::*Fn_1f24c0)(char*, char*, float, float);
class Registry_1f24c0 { public:
    void FUN_001f24c0(const char* a1, CSoundSystem_1f24c0* a2, Fn_1f24c0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1f24c0;
template<> class Closure4_1f24c0<CSoundSystem_1f24c0, void, char*, char*, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1f24c0 fn; CSoundSystem_1f24c0* owner; Closure4_1f24c0(CSoundSystem_1f24c0* o) { owner = o; } };
class Raw_1f24c0 { public: void FUN_001f0d10(const char*, Fn_1f24c0); };
class CSoundSystem_1f2520 {};
typedef void (CSoundSystem_1f2520::*Fn_1f2520)(char*, char*, float, float, float);
class Registry_1f2520 { public:
    void FUN_001f2520(const char* a1, CSoundSystem_1f2520* a2, Fn_1f2520 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_1f2520;
template<> class Closure5_1f2520<CSoundSystem_1f2520, void, char*, char*, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1f2520 fn; CSoundSystem_1f2520* owner; Closure5_1f2520(CSoundSystem_1f2520* o) { owner = o; } };
class Raw_1f2520 { public: void FUN_001f0dd0(const char*, Fn_1f2520); };
class CSoundSystem_1f2580 {};
typedef void (CSoundSystem_1f2580::*Fn_1f2580)(char*, char*, char*, float, float, float);
class Registry_1f2580 { public:
    void FUN_001f2580(const char* a1, CSoundSystem_1f2580* a2, Fn_1f2580 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_1f2580;
template<> class Closure6_1f2580<CSoundSystem_1f2580, void, char*, char*, char*, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1f2580 fn; CSoundSystem_1f2580* owner; Closure6_1f2580(CSoundSystem_1f2580* o) { owner = o; } };
class Raw_1f2580 { public: void FUN_001f0ed0(const char*, Fn_1f2580); };
class CSoundSystem_1f2630 {};
typedef void (CSoundSystem_1f2630::*Fn_1f2630)(char*, float, float);
class Registry_1f2630 { public:
    void FUN_001f2630(const char* a1, CSoundSystem_1f2630* a2, Fn_1f2630 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1f2630;
template<> class Closure3_1f2630<CSoundSystem_1f2630, void, char*, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1f2630 fn; CSoundSystem_1f2630* owner; Closure3_1f2630(CSoundSystem_1f2630* o) { owner = o; } };
class Raw_1f2630 { public: void FUN_001f1050(const char*, Fn_1f2630); };

} // namespace fn_ffeee61e

// 0x001f0ab0 Method2<CSoundSystem,void,char_*,char_*>::vfunc_0 (30 B): matches/0x001f0ab0.cpp
// sym: ??_G?$Method2@VCSoundSystem@@XPADPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSoundSystem, void, char *, char *>::~Method2() {}


// 0x001f0ad0 Method2<CSoundSystem,void,char_*,char_*>::vfunc_2 (23 B): matches/0x001f0ad0.cpp
// sym: ?vfunc_2@?$Method2@VCSoundSystem@@XPADPAD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSoundSystem, void, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1f0ad0* m = (CFEManager_1f0ad0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1f0ad0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSoundSystem, void, char *, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f0ab0)
#endif

namespace fn_ffeee61e {

// 0x001f0af0 FUN_001f0af0 (89 B): matches/0x001f0af0.cpp
// sym: ?Run@Method3_1f0af0@fn_ffeee61e@@QAEPAU12@PBDP8ScriptBoundClass@@AEXXZ@Z
Method3_1f0af0* Method3_1f0af0::Run(const char* a, ScriptMemberFn b) {
    Init_001d0480(a, 3);
    vt = ((hulk_intptr)DAT_004246cc);
    m1c = b;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_ffeee61e

// 0x001f0b50 Method3<CSoundSystem,void,char_*,char_*,float>::vfunc_0 (30 B): matches/0x001f0b50.cpp
// sym: ??_G?$Method3@VCSoundSystem@@XPADPADM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSoundSystem, void, char *, char *, float>::~Method3() {}


// 0x001f0b70 Method3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 (29 B): equivalent/0x001f0b70.cpp
// sym: ?vfunc_2@?$Method3@VCSoundSystem@@XPADPADM@@UAEXPAX00@Z @a7a6d240b96d @w7a58705a9035
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 @ 0x001f0b70
template <> void Method3<CSoundSystem, void, char *, char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSystem_1f0b70 * object = (CSoundSystem_1f0b70 *)__p0; CallArgs * args = (CallArgs *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CSoundSystem_1f0b70::**)(char *, char *, float))&this->f_1c))(args->first, args->second, args->third);
}
#if defined(HULK_PTR64)
template class Method3<CSoundSystem, void, char *, char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f0b50)
#endif


// 0x001f0bd0 Method0<CSoundSystem,void>::vfunc_0 (30 B): matches/0x001f0bd0.cpp
// sym: ??_G?$Method0@VCSoundSystem@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CSoundSystem, void>::~Method0() {}


// 0x001f0bf0 Method0<CSoundSystem,void>::vfunc_2 (12 B): matches/0x001f0bf0.cpp
// sym: ?vfunc_2@?$Method0@VCSoundSystem@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CSoundSystem, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1f0bf0 * a = (CActorManager_1f0bf0 *)__p0;

    (a->*(*(void (CActorManager_1f0bf0::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CSoundSystem, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f0bd0)
#endif

namespace fn_ffeee61e {

// 0x001f0c00 FUN_001f0c00 (128 B): matches/0x001f0c00.cpp
// sym: ??0Method6_1f0c00@fn_ffeee61e@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
Method6_1f0c00::Method6_1f0c00(const char* a, ScriptMemberFn c) : Function_1f0c00(a, 6) {
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004246ec);
    p1c = c;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_ffeee61e

// 0x001f0c80 Method6<CSoundSystem,void,char_*,char_*,float,float,float,float>::vfunc_0 (30 B): matches/0x001f0c80.cpp
// sym: ??_G?$Method6@VCSoundSystem@@XPADPADMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CSoundSystem, void, char *, char *, float, float, float, float>::~Method6() {}


// 0x001f0ca0 Method6<CSoundSystem,void,char_*,char_*,float,float,float,float>::vfunc_2 (30 B): matches/0x001f0ca0.cpp
// sym: ?vfunc_2@?$Method6@VCSoundSystem@@XPADPADMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CSoundSystem, void, char *, char *, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001f0cc0(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CSoundSystem, void, char *, char *, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f0c80)
#endif

namespace fn_ffeee61e {

// 0x001f0cc0 FUN_001f0cc0 (66 B): matches/0x001f0cc0.cpp
// sym: ?invoke@fn_ffeee61e@@YAXPAVObj@1@PAHHP821@AEXHHHHHH@Z@Z
void invoke(Obj* obj, int* data, int unused, Callback cb) {
    int a = *data++;
    int b = *data++;
    volatile int c = *data++;
    volatile int d = *data++;
    int f = data[1];
    int e = *data;
    (obj->*cb)(a, b, c, d, e, f);
}


// 0x001f0d10 FUN_001f0d10 (102 B): matches/0x001f0d10.cpp
// sym: ??0Method4_1f0d10@fn_ffeee61e@@QAE@PAXH@Z
Method4_1f0d10::Method4_1f0d10(void* a, hulk_intptr b) : Function_1f0d10(a, 4) {
    m1c = b;
    m18 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0049cad8)));
    m11 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0049cad8)));
    m12 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    m13 = Lookup((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_ffeee61e

// 0x001f0d80 Method4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_0 (30 B): matches/0x001f0d80.cpp
// sym: ??_G?$Method4@VCSoundSystem@@XPADPADMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSoundSystem, void, char *, char *, float, float>::~Method4() {}


// 0x001f0da0 Method4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 (40 B): equivalent/0x001f0da0.cpp
// sym: ?vfunc_2@?$Method4@VCSoundSystem@@XPADPADMM@@UAEXPAX00@Z @06f2e20faa8a @wcaf4bfffddb3
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 @ 0x001f0da0
template <> void Method4<CSoundSystem, void, char *, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSystem_1f0da0 * sound = (CSoundSystem_1f0da0 *)__p0; void * args = (void *)__p1; void * unused = (void *)__p2;

    Arguments *a = (Arguments *)args;
    (sound->*(*(void (CSoundSystem_1f0da0::**)(char *, char *, float, float))&this->f_1c))(a->first, a->second, a->third, a->fourth);
}
#if defined(HULK_PTR64)
template class Method4<CSoundSystem, void, char *, char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f0d80)
#endif

namespace fn_ffeee61e {

// 0x001f0dd0 FUN_001f0dd0 (115 B): matches/0x001f0dd0.cpp
// sym: ?Init@Method5_1f0dd0@fn_ffeee61e@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
// FUN_001f0dd0 @ 0x001f0dd0
Method5_1f0dd0* Method5_1f0dd0::Init(const char* arg, ScriptMemberFn value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_0042470c;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_ffeee61e

// 0x001f0e50 Method5<CSoundSystem,void,char_*,char_*,float,float,float>::vfunc_0 (30 B): matches/0x001f0e50.cpp
// sym: ??_G?$Method5@VCSoundSystem@@XPADPADMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CSoundSystem, void, char *, char *, float, float, float>::~Method5() {}


// 0x001f0e70 Method5<CSoundSystem,void,char_*,char_*,float,float,float>::vfunc_2 (30 B): matches/0x001f0e70.cpp
// sym: ?vfunc_2@?$Method5@VCSoundSystem@@XPADPADMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method5<CSoundSystem, void, char *, char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001f0e90(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method5<CSoundSystem, void, char *, char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f0e50)
#endif


// 0x001f0e90 FUN_001f0e90 (50 B): equivalent/0x001f0e90.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001f0e90@fn_001f0e90@@YAXPAUReceiver@1@PAUValues@1@HP821@AEXHHHHH@Z@Z @90a47938d0a5 @w83c856a5e08e
namespace fn_001f0e90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f0e90 @ 0x001f0e90
struct Receiver { void invoke(int a, int b, int c, int d, int e); };
struct Values { int a,b,c,d,e; };
typedef void (Receiver::*Callback)(int,int,int,int,int);
void __cdecl FUN_001f0e90(Receiver *receiver, Values *values, int unused, Callback callback)
{
    (receiver->*callback)(values->a, values->b, values->c, values->d, values->e);
}
} // namespace fn_001f0e90

namespace fn_ffeee61e {

// 0x001f0ed0 FUN_001f0ed0 (128 B): matches/0x001f0ed0.cpp
// sym: ??0Method6_1f0ed0@fn_ffeee61e@@QAE@PAXH@Z
Method6_1f0ed0::Method6_1f0ed0(void* p, hulk_intptr x) {
    ((Base_1f0ed0*)this)->Init_001d0480(p, 6);
    vptr = &hulk_at_0042471c;
    m1c = x;
    m18 = GetValue(((char*)&DAT_0048e100));
    m10 = GetValue(((char*)&DAT_0049cad8));
    m11 = GetValue(((char*)&DAT_0049cad8));
    m12 = GetValue(((char*)&DAT_0049cad8));
    m13 = GetValue(((char*)&DAT_0048e128));
    m14 = GetValue(((char*)&DAT_0048e128));
    m15 = GetValue(((char*)&DAT_0048e128));
}

} // namespace fn_ffeee61e

// 0x001f0f50 Method6<CSoundSystem,void,char_*,char_*,char_*,float,float,float>::vfunc_0 (30 B): matches/0x001f0f50.cpp
// sym: ??_G?$Method6@VCSoundSystem@@XPADPADPADMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CSoundSystem, void, char *, char *, char *, float, float, float>::~Method6() {}


// 0x001f0f70 Method6<CSoundSystem,void,char_*,char_*,char_*,float,float,float>::vfunc_2 (30 B): matches/0x001f0f70.cpp
// sym: ?vfunc_2@?$Method6@VCSoundSystem@@XPADPADPADMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CSoundSystem, void, char *, char *, char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001f0f90(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CSoundSystem, void, char *, char *, char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f0f50)
#endif


// 0x001f0f90 FUN_001f0f90 (59 B): equivalent/0x001f0f90.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001f0f90@fn_001f0f90@@YAXPAUObj@1@PBIIP821@AEXIIIIII@Z@Z @43a5f43fe16b @wcc373d8b34f3
namespace fn_001f0f90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f0f90 @ 0x001f0f90
struct Obj { void invoke(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); };
typedef void (Obj::*Callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_001f0f90(Obj* obj, const unsigned* values, unsigned unused, Callback callback) {
    (obj->*callback)(values[0], values[1], values[2], values[3], values[4], values[5]);
}
} // namespace fn_001f0f90


// 0x001f1010 Method1<CSoundSystem,void,float>::vfunc_0 (30 B): matches/0x001f1010.cpp
// sym: ??_G?$Method1@VCSoundSystem@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundSystem, void, float>::~Method1() {}


// 0x001f1030 Method1<CSoundSystem,void,float>::vfunc_2 (19 B): matches/0x001f1030.cpp
// sym: ?vfunc_2@?$Method1@VCSoundSystem@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSoundSystem, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1f1030* d = (Dummy_1f1030*)a;
    (d->*(*(void (Dummy_1f1030::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundSystem, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f1010)
#endif

namespace fn_ffeee61e {

// 0x001f1050 FUN_001f1050 (89 B): matches/0x001f1050.cpp
// sym: ??0Method3_1f1050@fn_ffeee61e@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
// Function (include/decls/data/script.h): the vftable, then Function's fields.
Method3_1f1050::Method3_1f1050(const char* a, ScriptMemberFn c) : Function_1f1050(a, 3) {
    m1c = c;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0049cad8));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
}

} // namespace fn_ffeee61e

// 0x001f10b0 Method3<CSoundSystem,void,char_*,float,float>::vfunc_0 (30 B): matches/0x001f10b0.cpp
// sym: ??_G?$Method3@VCSoundSystem@@XPADMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSoundSystem, void, char *, float, float>::~Method3() {}


// 0x001f10d0 Method3<CSoundSystem,void,char_*,float,float>::vfunc_2 (29 B): equivalent/0x001f10d0.cpp
// sym: ?vfunc_2@?$Method3@VCSoundSystem@@XPADPADM@@UAEXPAX00@Z @a7a6d240b96d @w7a58705a9035
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CSoundSystem,void,char_*,float,float>::vfunc_2 @ 0x001f10d0
template <> void Method3<CSoundSystem, void, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSystem_1f10d0 * system = (CSoundSystem_1f10d0 *)__p0; SoundArguments * arguments = (SoundArguments *)__p1; void * unused = (void *)__p2;

    (system->*(*(void (CSoundSystem_1f10d0::**)(char *, float, float))&this->f_1c))(arguments->name, arguments->first, arguments->second);
}
#if defined(HULK_PTR64)
template class Method3<CSoundSystem, void, char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f10b0)
#endif


// 0x001f1140 Method2<CSoundSystem,void,float,float>::vfunc_0 (30 B): matches/0x001f1140.cpp
// sym: ??_G?$Method2@VCSoundSystem@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSoundSystem, void, float, float>::~Method2() {}


// 0x001f1160 Method2<CSoundSystem,void,float,float>::vfunc_2 (23 B): matches/0x001f1160.cpp
// sym: ?vfunc_2@?$Method2@VCSoundSystem@@XPADPAD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSoundSystem, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1f1160* m = (CFEManager_1f1160*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1f1160::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSoundSystem, void, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f1140)
#endif


// 0x001f11d0 Method2<CSoundSystem,void,char_*,float>::vfunc_0 (30 B): matches/0x001f11d0.cpp
// sym: ??_G?$Method2@VCSoundSystem@@XPADM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSoundSystem, void, char *, float>::~Method2() {}


// 0x001f11f0 Method2<CSoundSystem,void,char_*,float>::vfunc_2 (23 B): matches/0x001f11f0.cpp
// sym: ?vfunc_2@?$Method2@VCSoundSystem@@XPADPAD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSoundSystem, void, char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1f11f0* m = (CFEManager_1f11f0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1f11f0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSoundSystem, void, char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f11d0)
#endif


// 0x001f1250 CSoundResourceManager::vfunc_2 (31 B): matches/0x001f1250.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f1250@@UAEPAV123@E@Z
namespace fn_001f1250 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FileLoader_1f1250 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public FileLoader_1f1250 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001f1250

namespace fn_ffeee61e {

// 0x001f1270 FUN_001f1270 (153 B): equivalent/0x001f1270.cpp
// sym: ?FUN_001f1270@SoundResourceManager@fn_ffeee61e@@QAEPAV12@XZ @f05344da7020 @wea39432e40d9
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_001f1270 @ 0x001f1270
SoundResourceManager *SoundResourceManager::FUN_001f1270()
{
    SoundBank_1f1270 *b = (SoundBank_1f1270 *)FUN_00263ed0(0x524, 6);
    if (b) {
        b->f04 = 0;
        b->vptr = (hulk_intptr)DAT_0042476c;
        b->f198 = 0;
        b->f4bc = 0;
        b->f510 = 0;
        b->f514 = 0;
        b->f518 = 0;
        b->f51c = 0;
        b->f520 = 0;
    }
    bank = b;
    SoundEngine *e = (SoundEngine *)FUN_0008d710(0x340, 6);
    if (e)
        engine = e->FUN_001f4ba0(bank);
    else
        engine = 0;
    f08 = 0;
    f0c = 0;
    (*(SoundResourceManager**)&DAT_004e370c) = this;
    return this;
}


// 0x001f1310 FUN_001f1310 (60 B): matches/0x001f1310.cpp
// sym: ?target@fn_ffeee61e@@YIXPAVC_1f1310@1@@Z
void __fastcall target(C_1f1310* self) {
    void* p = self->a;
    if (p) {
        ((Aux_1f1310*)((char*)p + 0xa0))->Fnf_0027af50();
        done_0008d330(p);
        self->a = 0;
    }
    if (self->b) {
        self->b->f2(1);
        self->b = 0;
    }
}


// 0x001f1350 FUN_001f1350 (87 B): matches/0x001f1350.cpp
// sym: ?Run@Owner_1f1350@fn_ffeee61e@@QAEXH@Z
void Owner_1f1350::Run(int arg) {
    int i = 0;
    do {
        Item_1f1350* p = (Item_1f1350*)((char*)items + i);
        p->Process_001effc0(arg);
        if (p->flag == 0) {
            p->a = 0;
            p->b = 0;
            p->c = 0;
            p->flag = 0;
            p->value = 100.0f;
            p->pad24 = 0;
            ((owners::Target_27b040 *)&(p->child))->FUN_0027b040((hulk_uintptr)0);
        }
        i += 0x28;
    } while (i < 4000);
}


// 0x001f13b0 FUN_001f13b0 (198 B): equivalent/0x001f13b0.cpp
// sym: ?FUN_001f13b0@Object@fn_ffeee61e@@QAEXPAX0@Z @89f4dc83a813 @wed70a225d761
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 14/14)
// FUN_001f13b0 @ 0x001f13b0
void Object::FUN_001f13b0(void* value, void* source) {
    Key_1f13b0 key;
    key.FUN_001f0090(source);
    Bucket_1f13b0* bucket = FUN_001efb80(&key);
    if (bucket) {
        Node* node = (Node*)FUN_0008d710(24, 6);
        if (node) {
            node->a = 0;
            node->b = 0;
            node->owner = 0;
            node->next = 0;
            node->value.FUN_0027af00();
        }
        ((owners::Target_27b040 *)&(node->value))->FUN_0027b040((hulk_uintptr)value);
        node->next = 0;
        node->owner = bucket;
        Node* tail = bucket->first;
        if (!tail) bucket->first = node;
        else {
            while (tail->next) tail = tail->next;
            tail->next = node;
        }
    }
    for (int i = 7; i >= 0; --i) key.elements[i].FUN_0027af50();
}

} // namespace fn_ffeee61e

// 0x001f1480 FUN_001f1480 (182 B): equivalent/0x001f1480.cpp [wrapped: conflict: Node]
// sym: ?FUN_001f1480@Owner_1f1480@fn_001f1480@@QAEXPAX0M@Z @863527e3beb7 @w510e17cf4f7e
namespace fn_001f1480 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 12/12)
// FUN_001f1480 @ 0x001f1480

struct Part_1f1480 { char data[8]; void FUN_0027af50(); };
struct Key_1f1480 { Part_1f1480 parts[8]; char extra[8]; void FUN_001f0090(void*); };
struct Node;
struct Group_1f1480 { char pad[4]; Node* head; };
struct Node { char pad[8]; Group_1f1480* group; Node* next; unsigned a,b; float weight; unsigned tail; void FUN_0027af00();  };
extern void* __cdecl FUN_0008d710(unsigned,unsigned);
struct Owner_1f1480 { Group_1f1480* FUN_001efb80(Key_1f1480*); void FUN_001f1480(void*,void*,float); };
void Owner_1f1480::FUN_001f1480(void* value, void* key, float weight) {
 Key_1f1480 temporary;
 temporary.FUN_001f0090(key);
 Group_1f1480* group = FUN_001efb80(&temporary);
 if(group) {
  Node* node = (Node*)FUN_0008d710(32,6);
  if(node) {
   node->FUN_0027af00();
   node->group=0; node->next=0; node->a=0; node->b=0; node->weight=100.0f;
  }
  ((owners::Target_27b040 *)node)->FUN_0027b040((hulk_uintptr)value);
  node->weight=weight;
  node->next=0;
  node->group=group;
  Node* last=group->head;
  if(!last) group->head=node;
  else { while(last->next) last=last->next; last->next=node; }
  (*(Node**)&DAT_004e3710)=node;
 }
 for(int i=7;i>=0;--i) temporary.parts[i].FUN_0027af50();
}
} // namespace fn_001f1480

namespace fn_ffeee61e {

// 0x001f1540 FUN_001f1540 (90 B): equivalent/0x001f1540.cpp
// sym: ?FUN_001f1540@fn_ffeee61e@@YGXPAX00@Z @180fe9376142 @w38c60b89b855
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f1540 @ 0x001f1540
void __stdcall FUN_001f1540(void *a, void *b, void *c) {
    if (a && b) {
        Manager *manager = (*(Manager**)&DAT_004e3710);
        if (manager) {
            Item *item = (Item *)FUN_0008d710(0x20, 6);
            if (item)
                manager->FUN_001ef260(item->FUN_001f0150(a, b, c));
            else
                manager->FUN_001ef260(0);
        }
    }
}


// 0x001f15a0 FUN_001f15a0 (90 B): equivalent/0x001f15a0.cpp
// sym: ?FUN_001f15a0@fn_ffeee61e@@YGXPAX00@Z @1d9cc2d9ef5c @w50ad66a5de8b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f15a0 @ 0x001f15a0
void __stdcall FUN_001f15a0(void *a, void *b, void *c) { if (!a || !b) return; Manager *manager = (*(Manager**)&DAT_004e3710); if (!manager) return; Item *item = (Item *)FUN_0008d710(0x20, 6); if (item) item = item->FUN_001f01c0(a, b, c); manager->FUN_001ef260(item); }


// 0x001f1600 FUN_001f1600 (105 B): equivalent/0x001f1600.cpp
// sym: ?FUN_001f1600@fn_ffeee61e@@YGXHHHHHH@Z @9b564625df3c @w040a60ea6b48
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 8/8)
// FUN_001f1600 @ 0x001f1600
void __stdcall FUN_001f1600(int a, int b, int c, int d, int e, int f)
{
    if (a == 0 || b == 0)
        return;
    Mgr_1f1600 *m = (*(Mgr_1f1600**)&DAT_004e3710);
    if (m == 0)
        return;
    CSoundCommand_PlayTunableEvent *j = (CSoundCommand_PlayTunableEvent *)FUN_0008d710(0x28, 6);
    if (j != 0) {
        m->FUN_001ef260(((CSoundCommand_PlayTunableEvent_nv_1f1600*)(((CSoundCommand_PlayTunableEvent*)(j))))->FUN_001f0230(a, b, c, d, e, f));
    } else {
        m->FUN_001ef260(0);
    }
}


// 0x001f1670 FUN_001f1670 (100 B): equivalent/0x001f1670.cpp
// sym: ?FUN_001f1670@fn_ffeee61e@@YGXHHHHH@Z @db0867fa44a1 @wdb9fb240f61b
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 8/8)
// FUN_001f1670 @ 0x001f1670
void __stdcall FUN_001f1670(int a, int b, int c, int d, int e)
{
    if (a == 0 || b == 0)
        return;
    Mgr_1f1670 *m = (*(Mgr_1f1670**)&DAT_004e3710);
    if (m == 0)
        return;
    CSoundCommand_SetLoopPitchEvent *j = (CSoundCommand_SetLoopPitchEvent *)FUN_0008d710(0x28, 6);
    if (j != 0) {
        m->FUN_001ef260(((CSoundCommand_SetLoopPitchEvent_nv_1f1670*)(((CSoundCommand_SetLoopPitchEvent*)(j))))->FUN_001f03a0(a, b, c, d, e));
    } else {
        m->FUN_001ef260(0);
    }
}


// 0x001f16e0 FUN_001f16e0 (95 B): equivalent/0x001f16e0.cpp
// sym: ?FUN_001f16e0@fn_ffeee61e@@YGXPAX0II@Z @f7689a46a6f1 @w1c57d30fa4b6
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f16e0 @ 0x001f16e0
void __stdcall FUN_001f16e0(void* a, void* b, unsigned c, unsigned d) {
    if (a && b) {
        Manager* manager = (*(Manager**)&DAT_004e3710);
        if (manager) {
            Item* item = (Item*)FUN_0008d710(0x20, 6);
            if (item)
                manager->FUN_001ef260(item->FUN_001f04e0(a,b,c,d));
            else
                manager->FUN_001ef260(0);
        }
    }
}

} // namespace fn_ffeee61e

// 0x001f1c30 FUN_001f1c30 (78 B): equivalent/0x001f1c30.cpp [wrapped: conflict: FUN_0008d710]
// sym: ?FUN_001f1c30@fn_001f1c30@@YGXHH@Z @bb1dc08c29dc @w0252feb68f0a
namespace fn_001f1c30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001f1c30 @ 0x001f1c30

struct CSoundCommand_InstallEffect_1f1c30 { int FUN_001f09d0(int, int); }; struct Manager { void FUN_001ef260(int); };  extern CSoundCommand_InstallEffect_1f1c30* __cdecl FUN_0008d710(int,int); void __stdcall FUN_001f1c30(int value, int extra) { if (value != 0) { Manager* manager = (*(Manager**)&DAT_004e3710); if (manager != 0) { CSoundCommand_InstallEffect_1f1c30* item = FUN_0008d710(0x18,6); int result = 0; if (item != 0) result = item->FUN_001f09d0(value,extra); manager->FUN_001ef260(result); } } }
} // namespace fn_001f1c30

namespace fn_ffeee61e {

// 0x001f1c80 FUN_001f1c80 (111 B): matches/0x001f1c80.cpp
// sym: ?Run@Node@fn_ffeee61e@@QAEXXZ
void Node::Run() {
    Node* n = first;
    while (n) {
        Node* q = n;
        n = q->next;
        q->Run();
        Destroy_0008d330(q);
    }
    Item_1f1c80* x = second;
    while (x) {
        Item_1f1c80* q = x;
        x = x->next;
        Elem_1f1c80* a = q->list;
        while (a) {
            Elem_1f1c80* z = a;
            a = z->next;
            z->Del(1);
        }
        q->Clean_0027af50();
        Destroy_0008d330(q);
    }
    ((Item_1f1c80*)((char*)this + 0x10))->Clean_0027af50();
}

} // namespace fn_ffeee61e

// 0x001f1cf0 FUN_001f1cf0 (89 B): matches/0x001f1cf0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001f1cf0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001f1cf0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_004246bc[2];
extern void* hulk_at_00424780[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
extern "C++" __declspec(nothrow) char __cdecl FUN_001d04d0(const void* tbl);

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
    vfptr = (void*)hulk_at_004246bc;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0049cad8));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0049cad8));
    vfptr = (void*)hulk_at_00424780;
    owner = a2;
}
} // namespace fn_001f1cf0


// 0x001f1d50 Closure2<CSoundSystem,void,char_*,char_*>::vfunc_0 (30 B): matches/0x001f1d50.cpp
// sym: ??_G?$Method6@VCSoundSystem@@XPADPADPADMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSoundSystem, void, char *, char *>::~Closure2() {}


// 0x001f1d70 Closure2<CSoundSystem,void,char_*,char_*>::vfunc_2 (22 B): matches/0x001f1d70.cpp
// sym: ?vfunc_2@?$Closure2@VCSoundSystem@@XPADPAD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSoundSystem, void, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1f1d70 * p = (Pair_1f1d70 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1f1d70 * *)&this->f_20)->*(*(void (CActorManager_1f1d70::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CSoundSystem, void, char *, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f1d50)
#endif


// 0x001f1dc0 Closure3<CSoundSystem,void,char_*,char_*,float>::vfunc_0 (30 B): matches/0x001f1dc0.cpp
// sym: ??_G?$Method3@VCSoundSystem@@XPADMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CSoundSystem, void, char *, char *, float>::~Closure3() {}


// 0x001f1de0 Closure3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 (28 B): equivalent/0x001f1de0.cpp
// sym: ?vfunc_2@?$Closure3@VCSoundSystem@@XPADPADM@@UAEXPAX00@Z @737c210bc5da @wc1b59fcf3196
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 @ 0x001f1de0
template <> void Closure3<CSoundSystem, void, char *, char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { SoundArgs * args = (SoundArgs *)__p1;

    ((*(CSoundSystem_1f1de0 * *)&this->f_20)->*(*(void (CSoundSystem_1f1de0::**)(char *, char *, float))&this->f_1c))(args->first, args->second, args->volume);
}
#if defined(HULK_PTR64)
template class Closure3<CSoundSystem, void, char *, char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f1dc0)
#endif


// 0x001f1e40 Closure0<CSoundSystem,void>::vfunc_0 (30 B): matches/0x001f1e40.cpp
// sym: ??_G?$Method2@VCSoundSystem@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CSoundSystem, void>::~Closure0() {}


// 0x001f1e60 Closure0<CSoundSystem,void>::vfunc_2 (11 B): matches/0x001f1e60.cpp
// sym: ?vfunc_2@?$Closure0@VCSoundSystem@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CSoundSystem, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_1f1e60 * *)&this->f_20)->*(*(void (CActorManager_1f1e60::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<CSoundSystem, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f1e40)
#endif


// 0x001f1ea0 Closure6<CSoundSystem,void,char_*,char_*,float,float,float,float>::vfunc_0 (30 B): matches/0x001f1ea0.cpp
// sym: ??_G?$Method2@VCSoundSystem@@XPADM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CSoundSystem, void, char *, char *, float, float, float, float>::~Closure6() {}


// 0x001f1ec0 Closure6<CSoundSystem,void,char_*,char_*,float,float,float,float>::vfunc_2 (71 B): matches/0x001f1ec0.cpp
// sym: ?vfunc_2@?$Closure6@VCSoundSystem@@XPADPADMMMM@@UAEXPAX00@Z
template <> void Closure6<CSoundSystem, void, char *, char *, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void ** a = (void **)__p1;

    char* x = (char*)*a++;
    char* y = (char*)*a++;
    float z = *(float*)a++;
    float w = *(float*)a++;
    float v = *(float*)a++;
    float u = *(float*)a++;
    ((*(CSoundSystem_1f1ec0 * *)&this->f_20)->*(*(void (CSoundSystem_1f1ec0::**)(char *, char *, float, float, float, float))&this->f_1c))(x, y, z, w, v, u);
}
#if defined(HULK_PTR64)
template class Closure6<CSoundSystem, void, char *, char *, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f1ea0)
#endif


// 0x001f1f60 Closure4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 (39 B): equivalent/0x001f1f60.cpp
// sym: ?vfunc_2@?$Closure4@VCSoundSystem@@XPADPADMM@@UAEXPAX00@Z @35da6a76506a @wda143db70d1f
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 @ 0x001f1f60
template <> void Closure4<CSoundSystem, void, char *, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * args = (Arguments *)__p1;

    ((*(CSoundSystem_1f1f60 * *)&this->f_20)->*(*(void (CSoundSystem_1f1f60::**)(char *, char *, float, float))&this->f_1c))(args->first, args->second, args->third, args->fourth);
}


// 0x001f1fe0 Closure5<CSoundSystem,void,char_*,char_*,float,float,float>::vfunc_2 (55 B): matches/0x001f1fe0.cpp
// sym: ?vfunc_2@?$Closure5@VCSoundSystem@@XPADPADMMM@@UAEXPAX00@Z
template <> void Closure5<CSoundSystem, void, char *, char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned int * args = (unsigned int *)__p1;

    char* first = (char*)*(hulk_uintptr*)args;
    char* second = (char*)*++args;
    float third = *(float*)++args;
    float fourth = *(float*)++args;
    float fifth = *(float*)++args;
    ((*(CSoundSystem_1f1fe0 * *)&this->f_20)->*(*(SoundMethod *)&this->f_1c))(first, second, third, fourth, fifth);
}


// 0x001f2070 Closure6<CSoundSystem,void,char_*,char_*,char_*,float,float,float>::vfunc_2 (64 B): matches/0x001f2070.cpp
// sym: ?vfunc_2@?$Closure6@VCSoundSystem@@XPADPADPADMMM@@UAEXPAX00@Z
template <> void Closure6<CSoundSystem, void, char *, char *, char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned int * x = (unsigned int *)__p1;

    char* a = (char*)*x++;
    char* b = (char*)*x++;
    char* c = (char*)*x++;
    float d = *(float*)x++;
    float e = *(float*)x++;
    float f = *(float*)x++;
    ((*(CSoundSystem_1f2070 * *)&this->f_20)->*(*(void (CSoundSystem_1f2070::**)(char *, char *, char *, float, float, float))&this->f_1c))(a, b, c, d, e, f);
}


// 0x001f20b0 FUN_001f20b0 (76 B): matches/0x001f20b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001f20b0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001f20b0 {
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

typedef unsigned char byte;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1f20b0 : public Base {
  public:
    virtual void Invoke();
    ScriptMemberFn obj;  // 0x1c
    Closure1_1f20b0(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_1f20b0 {
  public:
    virtual void Invoke();
    void* extra;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* p, void* q, ScriptMemberFn r) : Closure1_1f20b0(p, r) {
    extra = q;
}
Closure1_1f20b0::Closure1_1f20b0(const char* p, ScriptMemberFn q) : Base(p) {
    obj = q;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
} // namespace fn_001f20b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001f2120 Closure1<CSoundSystem,void,float>::vfunc_2 (18 B): matches/0x001f2120.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundSystem@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSoundSystem, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1f2120 * *)&this->f_20)->*(*(void (CActorManager_1f2120::**)(const char *))&this->f_1c))(*b);
}


// 0x001f21b0 FUN_001f21b0 (89 B): matches/0x001f21b0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001f21b0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001f21b0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
extern void* hulk_at_0042474c[2];
extern void* hulk_at_00424810[2];
extern void* hulk_at_0048e100;
extern void* hulk_at_0048e128;
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
    vfptr = (void*)hulk_at_0042474c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(&hulk_at_0048e100);
    f.argTypes[0] = LookupFlag_001d04d0(&hulk_at_0048e128);
    f.argTypes[1] = LookupFlag_001d04d0(&TAB_48e134);
    vfptr = (void*)hulk_at_00424810;
    owner = a2;
}
} // namespace fn_001f21b0


// 0x001f2230 Closure2<CSoundSystem,void,float,float>::vfunc_2 (22 B): matches/0x001f2230.cpp
// sym: ?vfunc_2@?$Closure2@VCSoundSystem@@XPADPAD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSoundSystem, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1f2230 * p = (Pair_1f2230 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1f2230 * *)&this->f_20)->*(*(void (CActorManager_1f2230::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x001f2250 FUN_001f2250 (89 B): matches/0x001f2250.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001f2250@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001f2250 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_0042475c[2];
extern void* hulk_at_00424820[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
extern "C++" __declspec(nothrow) char __cdecl FUN_001d04d0(const void* tbl);

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
    vfptr = (void*)hulk_at_0042475c;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0049cad8));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_00424820;
    owner = a2;
}
} // namespace fn_001f2250


// 0x001f22d0 Closure2<CSoundSystem,void,char_*,float>::vfunc_2 (22 B): matches/0x001f22d0.cpp
// sym: ?vfunc_2@?$Closure2@VCSoundSystem@@XPADPAD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSoundSystem, void, char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1f22d0 * p = (Pair_1f22d0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1f22d0 * *)&this->f_20)->*(*(void (CActorManager_1f22d0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}

namespace fn_ffeee61e {

// 0x001f22f0 FUN_001f22f0 (66 B): matches/0x001f22f0.cpp
// sym: ?Run@C_1f22f0@fn_ffeee61e@@QAEXM_N@Z
void C_1f22f0::Run(float x, bool flag) {
    a->FnF_001e95c0(x, flag);
    b->FnG_001f64c0(x, flag);
    if (flag)
        FnH_001f1350(x);
    (*(float*)&DAT_004e3714) += x;
}


// 0x001f2390 FUN_001f2390 (83 B): equivalent/0x001f2390.cpp
// sym: ?FUN_001f2390@Registry_1f2390@fn_ffeee61e@@QAEXPBDPAVCSoundSystem_1f2390@2@P832@AEXPAD2M@Z@Z @ef7d2a3c098b @wc86dd37b32b3
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f2390 @ 0x001f2390
// FUN_001f2390 @ 0x001f2390  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f2390::FUN_001f2390(const char* a1, CSoundSystem_1f2390* a2, Fn_1f2390 a3) {
    typedef Closure3_1f2390<CSoundSystem_1f2390, void, char*, char*, float> Alloc_1f2390;
    HULK_SIZE32(Alloc_1f2390, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f2390));
    void* x = 0;
    if (m) {
        ((Raw_1f2390*)m)->FUN_001f0af0(a1, a3);
        x = new (m) Closure3_1f2390<CSoundSystem_1f2390, void, char*, char*, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_ffeee61e

// 0x001f23f0 FUN_001f23f0 (109 B): equivalent/0x001f23f0.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_001f23f0@Registry_1f23f0@fn_001f23f0@@QAEXPBDPAVCSoundSystem@2@P832@AEXXZ@Z @0be8ad4e75cf @w937c3889a41d
namespace fn_001f23f0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001f23f0 @ 0x001f23f0
// FUN_001f23f0 @ 0x001f23f0  (generated by work/closure/gen.py)
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


class CSoundSystem { public: float FUN_dummy(); };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_1f23f0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1f23f0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1f23f0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1f23f0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1f23f0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001f23f0(const char* name, CSoundSystem* owner, void (CSoundSystem::*fn)());
};

void Registry_1f23f0::FUN_001f23f0(const char* name, CSoundSystem* owner, void (CSoundSystem::*fn)()) {
    typedef Closure0<CSoundSystem, void> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CSoundSystem, void>));
    Closure0<CSoundSystem, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CSoundSystem, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001f23f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ffeee61e {

// 0x001f2460 FUN_001f2460 (83 B): equivalent/0x001f2460.cpp
// sym: ?FUN_001f2460@Registry_1f2460@fn_ffeee61e@@QAEXPBDPAVCSoundSystem_1f2460@2@P832@AEXPAD2MMMM@Z@Z @feb9f6d4dd51 @wf87fa5080564
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f2460 @ 0x001f2460
// FUN_001f2460 @ 0x001f2460  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f2460::FUN_001f2460(const char* a1, CSoundSystem_1f2460* a2, Fn_1f2460 a3) {
    typedef Closure6_1f2460<CSoundSystem_1f2460, void, char*, char*, float, float, float, float> Alloc_1f2460;
    HULK_SIZE32(Alloc_1f2460, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f2460));
    void* x = 0;
    if (m) {
        ((Raw_1f2460*)m)->FUN_001f0c00(a1, a3);
        x = new (m) Closure6_1f2460<CSoundSystem_1f2460, void, char*, char*, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001f24c0 FUN_001f24c0 (83 B): equivalent/0x001f24c0.cpp
// sym: ?FUN_001f24c0@Registry_1f24c0@fn_ffeee61e@@QAEXPBDPAVCSoundSystem_1f24c0@2@P832@AEXPAD2MM@Z@Z @5bb90e9caa92 @wa4f36cf196d0
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f24c0 @ 0x001f24c0
// FUN_001f24c0 @ 0x001f24c0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f24c0::FUN_001f24c0(const char* a1, CSoundSystem_1f24c0* a2, Fn_1f24c0 a3) {
    typedef Closure4_1f24c0<CSoundSystem_1f24c0, void, char*, char*, float, float> Alloc_1f24c0;
    HULK_SIZE32(Alloc_1f24c0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f24c0));
    void* x = 0;
    if (m) {
        ((Raw_1f24c0*)m)->FUN_001f0d10(a1, a3);
        x = new (m) Closure4_1f24c0<CSoundSystem_1f24c0, void, char*, char*, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001f2520 FUN_001f2520 (83 B): equivalent/0x001f2520.cpp
// sym: ?FUN_001f2520@Registry_1f2520@fn_ffeee61e@@QAEXPBDPAVCSoundSystem_1f2520@2@P832@AEXPAD2MMM@Z@Z @5f6f93f6a887 @w3ec6a10d6bf3
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f2520 @ 0x001f2520
// FUN_001f2520 @ 0x001f2520  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f2520::FUN_001f2520(const char* a1, CSoundSystem_1f2520* a2, Fn_1f2520 a3) {
    typedef Closure5_1f2520<CSoundSystem_1f2520, void, char*, char*, float, float, float> Alloc_1f2520;
    HULK_SIZE32(Alloc_1f2520, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f2520));
    void* x = 0;
    if (m) {
        ((Raw_1f2520*)m)->FUN_001f0dd0(a1, a3);
        x = new (m) Closure5_1f2520<CSoundSystem_1f2520, void, char*, char*, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001f2580 FUN_001f2580 (83 B): equivalent/0x001f2580.cpp
// sym: ?FUN_001f2580@Registry_1f2580@fn_ffeee61e@@QAEXPBDPAVCSoundSystem_1f2580@2@P832@AEXPAD22MMM@Z@Z @4553117a7b10 @w179b3cc137d1
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f2580 @ 0x001f2580
// FUN_001f2580 @ 0x001f2580  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f2580::FUN_001f2580(const char* a1, CSoundSystem_1f2580* a2, Fn_1f2580 a3) {
    typedef Closure6_1f2580<CSoundSystem_1f2580, void, char*, char*, char*, float, float, float> Alloc_1f2580;
    HULK_SIZE32(Alloc_1f2580, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f2580));
    void* x = 0;
    if (m) {
        ((Raw_1f2580*)m)->FUN_001f0ed0(a1, a3);
        x = new (m) Closure6_1f2580<CSoundSystem_1f2580, void, char*, char*, char*, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001f2630 FUN_001f2630 (83 B): equivalent/0x001f2630.cpp
// sym: ?FUN_001f2630@Registry_1f2630@fn_ffeee61e@@QAEXPBDPAVCSoundSystem_1f2630@2@P832@AEXPADMM@Z@Z @3b2aaf4ea8c8 @w601e1b1d07bf
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f2630 @ 0x001f2630
// FUN_001f2630 @ 0x001f2630  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f2630::FUN_001f2630(const char* a1, CSoundSystem_1f2630* a2, Fn_1f2630 a3) {
    typedef Closure3_1f2630<CSoundSystem_1f2630, void, char*, float, float> Alloc_1f2630;
    HULK_SIZE32(Alloc_1f2630, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f2630));
    void* x = 0;
    if (m) {
        ((Raw_1f2630*)m)->FUN_001f1050(a1, a3);
        x = new (m) Closure3_1f2630<CSoundSystem_1f2630, void, char*, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_ffeee61e

// 0x001f2730 FUN_001f2730 (1217 B): equivalent/0x001f2730.cpp [wrapped: conflict: CSoundSystem; Closure1; Function; Method1]
// sym: ?FUN_001f2730@CSoundSystem@fn_001f2730@@QAEXXZ @1be8cbe57ef8 @w30db4fcbc35e
namespace fn_001f2730 {
// STATUS: equivalent (tools/equiv.py level 3: 455 inputs, branch coverage 38/38)
// FUN_001f2730 @ 0x001f2730
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



extern "C" void *__cdecl FUN_0008d690(unsigned int size);

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char *get() { return ((const char*)&DAT_0048e100); } };
template <> struct TypeName<float> { static const char *get() { return ((const char*)&DAT_0048e128); } };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) Function : public ScriptFunctionFields {
public:
    virtual void f0();
    virtual void f1();
    void FUN_001d0480(const char *name, int arity);
    Function() {}
    __forceinline Function(const char *name, int arity) { FUN_001d0480(name, arity); }
};

class CSoundSystem {
public:
    void FUN_001eef00();
    void FUN_001f13b0();
    void FUN_001f1480(char *, char *, float);
    void FUN_001f1540(char *, char *, float);
    void FUN_001f15a0(char *, char *, float);
    void FUN_001f1600(char *, char *, float, float, float, float);
    void FUN_001f1670(char *, char *, float, float, float);
    void FUN_001f16e0(char *, char *, float, float);
    void FUN_001f1740(char *, char *, float, float);
    void FUN_001f17f0(char *, char *, char *, float, float, float);
    void FUN_001f18b0(char *, char *, float, float, float);
    void FUN_001f1970(char *, char *, float);
    void FUN_001f1a20(char *, char *, float);
    void FUN_001f1ad0(char *, char *, float);
    void FUN_001f1b80(char *, char *, float);
    void FUN_001efca0(float);
    void FUN_001efd00(float);
    void FUN_001efd60(char *, float, float);
    void FUN_001efdc0();
    void FUN_001f1c30();
    void FUN_001f2730();
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

// Methods whose constructors were out of line
class __declspec(novtable) Method3A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float);
    __forceinline Method3A(const char *name, Fn f) : Function() { FUN_001f0af0(name, f); }
    void FUN_001f0af0(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method3B : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, float, float);
    __forceinline Method3B(const char *name, Fn f) : Function() { FUN_001f1050(name, f); }
    void FUN_001f1050(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method4A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float, float);
    __forceinline Method4A(const char *name, Fn f) : Function() { FUN_001f0d10(name, f); }
    void FUN_001f0d10(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method5A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float, float, float);
    __forceinline Method5A(const char *name, Fn f) : Function() { FUN_001f0dd0(name, f); }
    void FUN_001f0dd0(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method6A : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, float, float, float, float);
    __forceinline Method6A(const char *name, Fn f) : Function() { FUN_001f0c00(name, f); }
    void FUN_001f0c00(const char *name, Fn f);
    Fn fn;
};
class __declspec(novtable) Method6B : public Function {
public:
    typedef void (CSoundSystem::*Fn)(char *, char *, char *, float, float, float);
    __forceinline Method6B(const char *name, Fn f) : Function() { FUN_001f0ed0(name, f); }
    void FUN_001f0ed0(const char *name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Closure3;
template <class T, class R, class A, class B, class C, class D>
class Closure4;
template <class T, class R, class A, class B, class C, class D, class E>
class Closure5;
template <class T, class R, class A, class B, class C, class D, class E, class F>
class Closure6;

template <>
class Closure3<CSoundSystem, void, char *, char *, float> : public Method3A {
public:
    __forceinline Closure3(const char *name, CSoundSystem *o, Fn f) : Method3A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure3<CSoundSystem, void, char *, float, float> : public Method3B {
public:
    __forceinline Closure3(const char *name, CSoundSystem *o, Fn f) : Method3B(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure4<CSoundSystem, void, char *, char *, float, float> : public Method4A {
public:
    __forceinline Closure4(const char *name, CSoundSystem *o, Fn f) : Method4A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure5<CSoundSystem, void, char *, char *, float, float, float> : public Method5A {
public:
    __forceinline Closure5(const char *name, CSoundSystem *o, Fn f) : Method5A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure6<CSoundSystem, void, char *, char *, float, float, float, float> : public Method6A {
public:
    __forceinline Closure6(const char *name, CSoundSystem *o, Fn f) : Method6A(name, f), owner(o) {}
    CSoundSystem *owner;
};
template <>
class Closure6<CSoundSystem, void, char *, char *, char *, float, float, float> : public Method6B {
public:
    __forceinline Closure6(const char *name, CSoundSystem *o, Fn f) : Method6B(name, f), owner(o) {}
    CSoundSystem *owner;
};

// closures whose constructors were out of line too
struct Closure2_1f2730 {
    Closure2_1f2730 *FUN_001f1cf0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
struct ClosureDefaultMix {
    ClosureDefaultMix *FUN_001f21b0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
struct ClosureInstallEffect {
    ClosureInstallEffect *FUN_001f2250(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};

struct Registry_1f2730 {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001f23f0(const char *name, CSoundSystem *owner, void (CSoundSystem::*fn)());
};
extern "C" Registry_1f2730 *FUN_001d4c90();

void CSoundSystem::FUN_001f2730()
{
    Registry_1f2730 *reg = FUN_001d4c90();
    void *mem;

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    Closure2_1f2730 *obj = 0;
    if (mem)
        obj = ((Closure2_1f2730 *)mem)->FUN_001f1cf0("snd_CreateObject", this, &CSoundSystem::FUN_001f13b0);
    reg->FUN_001d3b70("snd_CreateObject", obj);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *trig = 0;
    if (mem)
        trig = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_CreateTrigger", this, &CSoundSystem::FUN_001f1480);
    reg->FUN_001d3b70("snd_CreateTrigger", trig);

    reg->FUN_001f23f0("snd_StopAllTriggers", this, &CSoundSystem::FUN_001eef00);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *seq = 0;
    if (mem)
        seq = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlaySequenceEvent", this, &CSoundSystem::FUN_001f1540);
    reg->FUN_001d3b70("snd_AddCommand_PlaySequenceEvent", seq);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *intr = 0;
    if (mem)
        intr = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayInterruptEvent", this, &CSoundSystem::FUN_001f15a0);
    reg->FUN_001d3b70("snd_AddCommand_PlayInterruptEvent", intr);

    { typedef Closure6<CSoundSystem, void, char *, char *, float, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure6<CSoundSystem, void, char *, char *, float, float, float, float>));
    Closure6<CSoundSystem, void, char *, char *, float, float, float, float> *tun = 0;
    if (mem)
        tun = new (mem) Closure6<CSoundSystem, void, char *, char *, float, float, float, float>("snd_AddCommand_PlayTunableEvent", this, &CSoundSystem::FUN_001f1600);
    reg->FUN_001d3b70("snd_AddCommand_PlayTunableEvent", tun);

    { typedef Closure4<CSoundSystem, void, char *, char *, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure4<CSoundSystem, void, char *, char *, float, float>));
    Closure4<CSoundSystem, void, char *, char *, float, float> *stoptun = 0;
    if (mem)
        stoptun = new (mem) Closure4<CSoundSystem, void, char *, char *, float, float>("snd_AddCommand_StopTunableEvent", this, &CSoundSystem::FUN_001f16e0);
    reg->FUN_001d3b70("snd_AddCommand_StopTunableEvent", stoptun);

    { typedef Closure5<CSoundSystem, void, char *, char *, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure5<CSoundSystem, void, char *, char *, float, float, float>));
    Closure5<CSoundSystem, void, char *, char *, float, float, float> *pitch = 0;
    if (mem)
        pitch = new (mem) Closure5<CSoundSystem, void, char *, char *, float, float, float>("snd_AddCommand_SetLoopPitchEvent", this, &CSoundSystem::FUN_001f1670);
    reg->FUN_001d3b70("snd_AddCommand_SetLoopPitchEvent", pitch);

    { typedef Closure4<CSoundSystem, void, char *, char *, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure4<CSoundSystem, void, char *, char *, float, float>));
    Closure4<CSoundSystem, void, char *, char *, float, float> *dlg = 0;
    if (mem)
        dlg = new (mem) Closure4<CSoundSystem, void, char *, char *, float, float>("snd_AddCommand_PlayDialogueEvent", this, &CSoundSystem::FUN_001f1740);
    reg->FUN_001d3b70("snd_AddCommand_PlayDialogueEvent", dlg);

    { typedef Closure6<CSoundSystem, void, char *, char *, char *, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure6<CSoundSystem, void, char *, char *, char *, float, float, float>));
    Closure6<CSoundSystem, void, char *, char *, char *, float, float, float> *mdlg = 0;
    if (mem)
        mdlg = new (mem) Closure6<CSoundSystem, void, char *, char *, char *, float, float, float>("snd_AddCommand_PlayMissionDialogueEvent", this, &CSoundSystem::FUN_001f17f0);
    reg->FUN_001d3b70("snd_AddCommand_PlayMissionDialogueEvent", mdlg);

    { typedef Closure5<CSoundSystem, void, char *, char *, float, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure5<CSoundSystem, void, char *, char *, float, float, float>));
    Closure5<CSoundSystem, void, char *, char *, float, float, float> *fdlg = 0;
    if (mem)
        fdlg = new (mem) Closure5<CSoundSystem, void, char *, char *, float, float, float>("snd_AddCommand_PlayFightDialogueEvent", this, &CSoundSystem::FUN_001f18b0);
    reg->FUN_001d3b70("snd_AddCommand_PlayFightDialogueEvent", fdlg);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *music = 0;
    if (mem)
        music = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayMusicEvent", this, &CSoundSystem::FUN_001f1970);
    reg->FUN_001d3b70("snd_AddCommand_PlayMusicEvent", music);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *amb = 0;
    if (mem)
        amb = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlayAmbienceEvent", this, &CSoundSystem::FUN_001f1a20);
    reg->FUN_001d3b70("snd_AddCommand_PlayAmbienceEvent", amb);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *sfx = 0;
    if (mem)
        sfx = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_PlaySFXEvent", this, &CSoundSystem::FUN_001f1ad0);
    reg->FUN_001d3b70("snd_AddCommand_PlaySFXEvent", sfx);

    { typedef Closure3<CSoundSystem, void, char *, char *, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, char *, float>));
    Closure3<CSoundSystem, void, char *, char *, float> *cue = 0;
    if (mem)
        cue = new (mem) Closure3<CSoundSystem, void, char *, char *, float>("snd_AddCommand_CueNISEvent", this, &CSoundSystem::FUN_001f1b80);
    reg->FUN_001d3b70("snd_AddCommand_CueNISEvent", cue);

    { typedef Closure1<CSoundSystem, void, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundSystem, void, float>));
    Closure1<CSoundSystem, void, float> *play = 0;
    if (mem)
        play = new (mem) Closure1<CSoundSystem, void, float>("snd_AddCommand_PlayCuedNISEvent", this, &CSoundSystem::FUN_001efca0);
    reg->FUN_001d3b70("snd_AddCommand_PlayCuedNISEvent", play);

    { typedef Closure1<CSoundSystem, void, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundSystem, void, float>));
    Closure1<CSoundSystem, void, float> *stop = 0;
    if (mem)
        stop = new (mem) Closure1<CSoundSystem, void, float>("snd_AddCommand_StopNISEvent", this, &CSoundSystem::FUN_001efd00);
    reg->FUN_001d3b70("snd_AddCommand_StopNISEvent", stop);

    { typedef Closure3<CSoundSystem, void, char *, float, float> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure3<CSoundSystem, void, char *, float, float>));
    Closure3<CSoundSystem, void, char *, float, float> *mixer = 0;
    if (mem)
        mixer = new (mem) Closure3<CSoundSystem, void, char *, float, float>("snd_AddCommand_InstallMixer", this, &CSoundSystem::FUN_001efd60);
    reg->FUN_001d3b70("snd_AddCommand_InstallMixer", mixer);

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    ClosureDefaultMix *mix = 0;
    if (mem)
        mix = ((ClosureDefaultMix *)mem)->FUN_001f21b0("snd_AddCommand_ReturnToDefaultMix", this, &CSoundSystem::FUN_001efdc0);
    reg->FUN_001d3b70("snd_AddCommand_ReturnToDefaultMix", mix);

    { HULK_SIZE32(ScriptClosureView, 0x24); }
    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    ClosureInstallEffect *fx = 0;
    if (mem)
        fx = ((ClosureInstallEffect *)mem)->FUN_001f2250("snd_AddCommand_InstallEffect", this, &CSoundSystem::FUN_001f1c30);
    reg->FUN_001d3b70("snd_AddCommand_InstallEffect", fx);
}
} // namespace fn_001f2730
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

