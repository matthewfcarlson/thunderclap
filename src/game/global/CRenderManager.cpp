// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b8690..0x001bc0c0 (kind game, layer game, confidence high), dominant class CRenderManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff10b020 {
#define TREE_TU_END }
namespace fn_ff10b020 {} using namespace fn_ff10b020;
#include "game/global.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
namespace fn_ff10b020 {
struct View_nv_1b8690 {
    pure3d::View *FUN_00294880();
};
extern "C" void *__cdecl FUN_0008d690(unsigned int n);
class Owner_1b8690 {
public:
    void FUN_001b8690();
    int pad0;
    pure3d::View *child;
    int v[4];
};
struct Renderer_1b86f0 {
    void Setup_0023f720(int* out, const char* name);
    unsigned char GetBool_0023f760(const char* name, int a, int b);
    void Finish_0023f740();
};
struct Ctl_1b86f0 {
    void Apply_0008db60(unsigned char v);
};
extern "C" void* __cdecl FUN_001c3d90();
class A_1b8770 {
  public:
    void Fn_001c1780(int);
};
struct R_1b8770 {
    A_1b8770* p;
};
struct Item_1b8780 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d(unsigned char);
};
struct Manager_1b8780 {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual Item_1b8780* get(int);
};
extern Manager_1b8780* hulk_at_0052c2a8;
extern "C" int FUN_00266da0(int);
struct Obj_1b8780 {
    char pad[0x33];
    unsigned char field;
};
class Timer {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual int Get();
};
class CRenderManager_1b8ab0 {
    char pad0[0x18];

  public:
    char m18;
    char pad19[3];
    float m1c;
    float m20;
    char pad24[4];
    int m28;
    char pad2c[4];
    char m30;
    void Init();
};
class Service_1b8af0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int Get();
};
class Target_1b8af0 {
  public:
    char pad0[0x18];
    unsigned char initialized;
    char pad1[2];
    float a;
    float b;
    char pad2[4];
    int zero;
    char pad3[4];
    unsigned char flag;
};
struct Obj_1b8b30 {
    char pad[0x18];
    unsigned char active;
    float value;
    char pad2[0x10];
    unsigned char other;
};
struct B_1b8dc0 {
    int x, y, z;
};
struct C_1b8dc0 {
    int x, y, z;
    void Init_0027b0e0(int a);
    void Done_0027af50();
};
struct M_1b8dc0 {
    char d[64];
    void Ident_0022b980();
    void Set3_0022bc20(int a, int b, int c);
};
struct S_1b8dc0 {
    int Run_00283a40(C_1b8dc0* c, M_1b8dc0* m, float f, int a);
};
S_1b8dc0* GetS_0027f250();
struct V3_1b8e40 { float x, y, z; };
struct Id64_1b8e40 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af50();
    Id64_1b8e40* FUN_0027b0e0(const char* name);
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
struct Spawned;
struct Spawner_1b8e40 {
    Spawned* FUN_00283a40(Id64_1b8e40* id, Matrix* mat, float a, float b);
};
Spawner_1b8e40* FUN_0027f250();
struct Vec3_1b8ee0 { float x,y,z; };
struct Reader_1b8ee0 { const char* FUN_003365b0(const char*); void FUN_00336600(const char*,float*,float*,float*); };
struct CRenderManager_nv_1b8ee0 {
    void FUN_001b8dc0(const char*,Vec3_1b8ee0,Vec3_1b8ee0,float);
};
class pddiObject_1b8ff0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_1b8ff0 : public pddiObject_1b8ff0 {};
class pddiBaseShader_1b8ff0 : public pddiShader_1b8ff0 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_1b8ff0 : public pddiBaseShader_1b8ff0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class CDHGameObjectCreator_1b9000 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual const char* f3(void*);
};
class DataHandlerObjectCreator {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual const char* g3(void*);
};
struct Part_1b90b0 {
    unsigned Get_000d6f50();
    void Set_000d7030(unsigned);
};
struct Engine_1b90b0 {
    void Stop_000361c0(int);
};
struct Sub_1b90b0 {
    char pad[0x124];
    Engine_1b90b0* p;
};
struct Global_1b90b0 {
    char pad[0x20];
    Sub_1b90b0* sub;
    char pad2[0x3c - 0x24];
    Part_1b90b0* part;
};
extern Global_1b90b0* hulk_at_004dd700;
struct Item_1b90b0 {
    void Act_001c3810(int, float, int, int);
};
Item_1b90b0* __stdcall Make_001c3d90();
class Obj {
  public:
    char _m_pad_0[0x5c];
    int value;
    void run_001c37f0(int, int, int, int);
};
Obj* __stdcall make_001c3d90();
struct V {
    int a, b, c;
};
class A {
  public:
    void run_001c17a0(float, float);
    V* get_001c39a0();
};
struct Holder {
    A* p;
};
Holder* __cdecl get_001c3d90();
A* __cdecl fetch_001c3d90();
struct Vec {
    int x, y, z;
};
A* __cdecl findA_001c3d90();
struct Manager {
    Obj* Find_001c7f10(int);
};
struct Root {
    char pad[4];
    Manager* manager;
};
Root* __stdcall GetRoot_001c3d90();
class CActorManager_1b9c30 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1b9c30::*MFn_1b9c30)(unsigned char);
class Function_1b9c30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_00420e24[];
class Function_1b9c50 {
  public:
    void Init_001d0480(const char*, int);
};
class Method3_1b9c50 : public Function_1b9c50 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    ScriptMemberFn member1c;
    Method3_1b9c50(const char* p, ScriptMemberFn x);
};
struct CRenderManager_1b9cd0 { };
struct Function_1b9cd0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CFEManager_1b9d60 {
  public:
    void Call(const char*, int);
};
class Function_1b9d60 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_00420e44[];
extern char Helper_001d04d0(const char*);
class Function_1b9d80 {
  public:
    void Init_001d0480(int, int);
};
class Method6_1b9d80 : public Function_1b9d80 {
  public:
    hulk_intptr v;
    char p[12];
    char a[9];
    char p2[3];
    int field;
    Method6_1b9d80(hulk_intptr, hulk_intptr);
};
struct Function_1b9e20 {
    virtual void f0();
    virtual void f1();
};
void FUN_001b9e40(const char*, const char*, const char*, int);
struct Values { int values[6]; };
typedef void (__cdecl *Callback)(int, int, int, int, int, int);
class CActorManager_1b9f00 {
  public:
    void f();
};
class CActorManager_1b9f70;
typedef unsigned char(__fastcall* Fn_1b9f70)(CActorManager_1b9f70*);
extern "C" char DAT_00420e74[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, unsigned int);
};
class Method4_1b9f90 : public FUN_001d0480 {
  public:
    Method4_1b9f90(const char*, ScriptMemberFn);
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn field1c;
};
struct Function_1ba020 {
    virtual void f0();
    virtual void f1();
};
void FUN_001ba040(const char*, const char*, const char*, int);
extern "C" char DAT_00420e84[];
extern "C" char DAT_0048e10c[];
struct Method4_1ba090 {
    hulk_intptr v;
    ScriptFunctionFields f;
    ScriptMemberFn p1c;
    void Init_001d0480(const char*, int);
    Method4_1ba090(const char*, ScriptMemberFn);
};
struct Vec_1ba120 {
    unsigned x, y, z;
};
struct Args_1ba120 {
    const char *name;
    Vec_1ba120 from;
    Vec_1ba120 to;
    unsigned radius;
};
class CRenderManager_1ba120 {
  public:
    unsigned Check(const char *name, Vec_1ba120 from, Vec_1ba120 to, unsigned radius);
};
typedef unsigned (CRenderManager_1ba120::*CheckFn_1ba120)(const char *, Vec_1ba120, Vec_1ba120, unsigned);
class Function_1ba120 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Dummy_1ba1f0 {
  public:
    void Call(void*);
};
struct Vector_1ba270 {
    int x, y, z;
};
class CGameFlowManager_1ba270 {
  public:
    virtual Vector_1ba270* Get(Vector_1ba270*);
};
typedef Vector_1ba270* (CGameFlowManager_1ba270::*Fn_1ba270)(Vector_1ba270*);
class CFEManager_1ba330 {
  public:
    void Call(const char*, int);
};
class Function_1ba330 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_1ba3b0 {
  public:
    void Call(void*);
};
class Actor_1ba480 {
  public:
    void fn(unsigned char);
};
class CActorManager_1ba590 {
  public:
    void Method(const char*, float);
};
struct Pair_1ba590 {
    const char* s;
    float f;
};
struct CRenderManager_1ba600 {
    void FUN_001ba600(float, float, float, float, float, float);
};
struct Function_1ba600 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class CActorManager_1ba6c0 {
  public:
    void run();
};
class CActorManager_1ba730;
typedef unsigned char(__fastcall* Fn_1ba730)(CActorManager_1ba730*);
struct CRenderManager_1ba7a0 {
    unsigned int run(unsigned int, const char*, float, float);
};
class CActorManager_1ba8c0 {
  public:
    void invoke(const char*);
};
} // namespace fn_ff10b020
namespace math {
struct Vector_1ba940 { float x,y,z; };
}
namespace fn_ff10b020 {
struct CRenderManager_1ba940 {};
struct Function_1ba940 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, int, math::Vector_1ba940 *); };
class CActorManager_1baa00 {
  public:
    void Method(const char*, float);
};
struct Pair_1baa00 {
    const char* s;
    float f;
};
class CActorManager_1baa90 {
  public:
    void invoke(const char*);
};
} // namespace fn_ff10b020
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_ff10b020 {
class CRenderManager_1bb580 {};
typedef void (CRenderManager_1bb580::*Fn_1bb580)(int, int, int);
class Registry_1bb580 { public:
    void FUN_001bb580(const char* a1, CRenderManager_1bb580* a2, Fn_1bb580 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1bb580;
template<> class Closure3_1bb580<CRenderManager_1bb580, void, int, int, int> : public ScriptFunctionFields { public: virtual void* Fnv_001ba4d0(int); Fn_1bb580 fn; CRenderManager_1bb580* owner; Closure3_1bb580(CRenderManager_1bb580* o) { owner = o; } };
class Raw_1bb580 { public: void FUN_001b9c50(const char*, Fn_1bb580); };
class CRenderManager_1bb630 {};
typedef void (CRenderManager_1bb630::*Fn_1bb630)(float, float, float, float, float, float);
class Registry_1bb630 { public:
    void FUN_001bb630(const char* a1, CRenderManager_1bb630* a2, Fn_1bb630 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_1bb630;
template<> class Closure6_1bb630<CRenderManager_1bb630, void, float, float, float, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_001ba5e0(int); Fn_1bb630 fn; CRenderManager_1bb630* owner; Closure6_1bb630(CRenderManager_1bb630* o) { owner = o; } };
class Raw_1bb630 { public: void FUN_001b9d80(const char*, Fn_1bb630); };
} // namespace fn_ff10b020
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_ff10b020 {
struct Info_1bb690 {};
char GetFlag_001d04d0(Info_1bb690*) throw();
struct Function_1bb690 {
    Function_1bb690(void* h, int z) throw();
    virtual void Run();
    char pad[0x14];
};
struct Method0_1bb690 : Function_1bb690 {
    char f;
    int a;
    int b;
    Method0_1bb690(void* h, int y, int x) throw() : Function_1bb690(h, 0) {
        a = y;
        f = GetFlag_001d04d0(((Info_1bb690*)&DAT_0048e100));
        b = x;
    }
};
struct Closure0_1bb690 : Method0_1bb690 {
    virtual void Run();
    Closure0_1bb690(void* h, int y, int x) throw() : Method0_1bb690(h, y, x) {}
};
struct Owner_1bb690 {
    void Make(void* h, int x, int y);
};
class CRenderManager_1bb770 {};
typedef unsigned int (CRenderManager_1bb770::*Fn_1bb770)(const char*, float, float, float);
class Registry_1bb770 { public:
    void FUN_001bb770(const char* a1, CRenderManager_1bb770* a2, Fn_1bb770 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1bb770;
template<> class Closure4_1bb770<CRenderManager_1bb770, unsigned int, const char*, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1bb770 fn; CRenderManager_1bb770* owner; Closure4_1bb770(CRenderManager_1bb770* o) { owner = o; } };
class Raw_1bb770 { public: void FUN_001b9f90(const char*, Fn_1bb770); };
} // namespace fn_ff10b020
namespace math {
class Vector_1bb7d0 { public: float x, y, z; };
}
namespace fn_ff10b020 {
class CRenderManager_1bb7d0 {};
typedef unsigned int (CRenderManager_1bb7d0::*Fn_1bb7d0)(const char*, math::Vector_1bb7d0, math::Vector_1bb7d0, float);
class Registry_1bb7d0 { public:
    void FUN_001bb7d0(const char* a1, CRenderManager_1bb7d0* a2, Fn_1bb7d0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1bb7d0;
template<> class Closure4_1bb7d0<CRenderManager_1bb7d0, unsigned int, const char*, math::Vector_1bb7d0, math::Vector_1bb7d0, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1bb7d0 fn; CRenderManager_1bb7d0* owner; Closure4_1bb7d0(CRenderManager_1bb7d0* o) { owner = o; } };
class Raw_1bb7d0 { public: void FUN_001ba090(const char*, Fn_1bb7d0); };


// 0x001b8690 FUN_001b8690 (96 B): equivalent/0x001b8690.cpp
// sym: ?FUN_001b8690@Owner_1b8690@fn_ff10b020@@QAEXXZ @149975c5bb74 @wadf3177de501
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001b8690 @ 0x001b8690
void Owner_1b8690::FUN_001b8690()
{
    pure3d::View *c = (pure3d::View *)FUN_0008d690(0x140);
    if (c)
        c = ((View_nv_1b8690*)(c))->FUN_00294880();
    child = c;
    c->vfunc_0();
    ((owners::A_293e40 *)(((View_nv_1b8690*)(child))))->FUN_00293e40(v[0], v[1], v[2], v[3]);
    (*(unsigned int *)&child->f_20) = 0xff000000;
    (*(unsigned int *)&child->f_2c) = 0xffffffff;
    ((owners::C_293e90 *)(((View_nv_1b8690*)(child))))->FUN_00293e90(0xff000000);
}


// 0x001b86f0 FUN_001b86f0 (86 B): matches/0x001b86f0.cpp
// sym: _FUN_001b86f0@4
// data: gCurrentVsync = DAT_004c4680, gFlag_1b86f0 = DAT_004c4684, gRenderer = DAT_004dd6e8
extern "C" void __stdcall FUN_001b86f0(Ctl_1b86f0* ctl) {
    (*(Renderer_1b86f0**)&DAT_004dd6e8)->Setup_0023f720(((int*)&DAT_004c4684), "Rendering");
    unsigned char value = (*(Renderer_1b86f0**)&DAT_004dd6e8)->GetBool_0023f760("Lock to VSync", 0x60, 1);
    if (value != DAT_004c4680) {
        DAT_004c4680 = value;
        ctl->Apply_0008db60(value);
    }
    (*(Renderer_1b86f0**)&DAT_004dd6e8)->Finish_0023f740();
}


// 0x001b8750 FUN_001b8750 (1 B): matches/0x001b8750.cpp
// sym: _FUN_001b8750
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_001b8750() {}


// 0x001b8770 FUN_001b8770 (12 B): matches/0x001b8770.cpp
// sym: ?FUN_001b8770@fn_ff10b020@@YGXH@Z
void __stdcall FUN_001b8770(int a) {
    R_1b8770* r = (R_1b8770*)FUN_001c3d90();
    r->p->Fn_001c1780(a);
}


// 0x001b8780 FUN_001b8780 (72 B): matches/0x001b8780.cpp
// sym: ?target@fn_ff10b020@@YIXPAUObj_1b8780@1@HE@Z
void __fastcall target(Obj_1b8780* self, int, unsigned char value) {
    Item_1b8780* p = hulk_at_0052c2a8->get(0x103);
    self->field = value;
    if (p) {
        int q = FUN_00266da0(0);
        p->d(value);
        FUN_00266da0(q);
    }
}

} // namespace fn_ff10b020

// 0x001b87d0 FUN_001b87d0 (24 B): matches/0x001b87d0.cpp
// sym: ?FUN_001b87d0@CRenderManager@@QAEXHHH@Z
void CRenderManager::FUN_001b87d0(int x, int y, int z) {
    this->f_34 = x;
    this->f_38 = y;
    this->f_3c = z;
}


// 0x001b87f0 FUN_001b87f0 (24 B): matches/0x001b87f0.cpp
// sym: ?FUN_001b87f0@CRenderManager@@QAEXHHH@Z
void CRenderManager::FUN_001b87f0(int x, int y, int z) {
    this->f_40 = x;
    this->f_44 = y;
    this->f_48 = z;
}


// 0x001b8810 FUN_001b8810 (4 B): matches/0x001b8810.cpp
// sym: ?FUN_001b8810@Obj_1b8810@owners@@QAEEXZ
unsigned char owners::Obj_1b8810::FUN_001b8810() {
    return field;
}


// 0x001b8820 FUN_001b8820 (30 B): matches/0x001b8820.cpp
// sym: ?FUN_001b8820@C_1b8820@owners@@QAEXPAH00@Z
void owners::C_1b8820::FUN_001b8820(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}


// 0x001b8840 FUN_001b8840 (30 B): matches/0x001b8840.cpp
// sym: ?FUN_001b8840@C_1b8840@owners@@QAEXPAH00@Z
void owners::C_1b8840::FUN_001b8840(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}


// 0x001b8860 FUN_001b8860 (57 B): matches/0x001b8860.cpp
// sym: ?FUN_001b8860@C_1b8860@owners@@QAEXPAH00000@Z
void owners::C_1b8860::FUN_001b8860(int* p1, int* p2, int* p3, int* p4, int* p5, int* p6) {
    *p1 = a;
    *p2 = b;
    *p3 = c;
    *p4 = d;
    *p5 = e;
    *p6 = f;
}

namespace fn_ff10b020 {

// 0x001b88c0 FUN_001b88c0 (47 B): matches/0x001b88c0.cpp
// sym: ?FUN@fn_ff10b020@@YGXMM@Z
// data: zero = DAT_003f32e0
void __stdcall FUN(float a, float b) {
    if (a <= (*(float*)&DAT_003f32e0) || b <= a)
        return;
    Holder* h = get_001c3d90();
    h->p->run_001c17a0(a, b);
}

} // namespace fn_ff10b020

// 0x001b88f0 FUN_001b88f0 (12 B): matches/0x001b88f0.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b88f0@fn_001b88f0@@YAXXZ
namespace fn_001b88f0 {
class Obj_1b88f0 {
  public:
    void Init_001c3c90();
};
Obj_1b88f0* __cdecl FUN_001c3d90();
void __cdecl FUN_001b88f0() {
    FUN_001c3d90()->Init_001c3c90();
}
} // namespace fn_001b88f0


// 0x001b8900 FUN_001b8900 (20 B): matches/0x001b8900.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?target@fn_001b8900@@YGXI@Z
namespace fn_001b8900 {
// FUN_001c3d90 is the 0-argument singleton getter; param_1 is the method's argument.
typedef unsigned int u32_1b8900;
struct Registry_1b8900 {
    void FUN_001c3ca0(u32_1b8900);
};
Registry_1b8900* FUN_001c3d90();
void __stdcall target(u32_1b8900 value) {
    FUN_001c3d90()->FUN_001c3ca0(value);
}
} // namespace fn_001b8900

namespace fn_ff10b020 {

// 0x001b8970 FUN_001b8970 (75 B): matches/0x001b8970.cpp
// sym: _FUN_001b8970
extern "C" int FUN_001b8970(short* p, int limit) {
    int i = 0;
    bool pending = false;
    int lines = 1;
    while (*p != 0) {
        if (pending) {
            if (*p == 0x20) {
                i = 0;
                pending = false;
                *p = 10;
                ++lines;
            }
        } else if (i > limit) {
            pending = true;
        } else {
            ++i;
        }
        ++p;
    }
    return lines;
}


// 0x001b8ab0 FUN_001b8ab0 (47 B): matches/0x001b8ab0.cpp
// sym: ?Init@CRenderManager_1b8ab0@fn_ff10b020@@QAEXXZ
// data: gTimer = DAT_0052c2a4
void CRenderManager_1b8ab0::Init() {
    m30 = 1;
    m18 = 1;
    int t = (*(Timer**)&DAT_0052c2a4)->Get();
    m28 = 0;
    m20 = (float)t;
    m1c = (float)t;
}

} // namespace fn_ff10b020

// 0x001b8ae0 FUN_001b8ae0 (5 B): matches/0x001b8ae0.cpp
// sym: ?FUN_001b8ae0@A_1b8ae0@owners@@QAEXXZ
void owners::A_1b8ae0::FUN_001b8ae0() {
    x = 0;
}

namespace fn_ff10b020 {

// 0x001b8af0 FUN_001b8af0 (54 B): matches/0x001b8af0.cpp
// sym: ?FUN_001b8af0@fn_ff10b020@@YIXPAVTarget_1b8af0@1@@Z
// data: g_service = DAT_0052c2a4
void __fastcall FUN_001b8af0(Target_1b8af0* self) {
    if (!self->initialized) {
        self->flag = 0;
        self->initialized = 1;
        int n = (*(Service_1b8af0**)&DAT_0052c2a4)->Get();
        self->zero = 0;
        self->b = (float)n;
        self->a = (float)n;
    }
}


// 0x001b8b30 FUN_001b8b30 (35 B): matches/0x001b8b30.cpp
// sym: ?FUN_001b8b30@fn_ff10b020@@YIEPAUObj_1b8b30@1@@Z
// data: threshold_1b8b30 = DAT_004203b0
unsigned char __fastcall FUN_001b8b30(Obj_1b8b30* p) {
    if (p->active != 0 && p->value < DAT_004203b0) {
        p->active = 0;
        p->other = 0;
    }
    return p->active;
}

} // namespace fn_ff10b020

// 0x001b8b60 FUN_001b8b60 (605 B): equivalent/0x001b8b60.cpp [wrapped: macros]
// sym: _FUN_001b8b60 @b74bab14b354 @w27610237eb67
namespace fn_001b8b60 {
// STATUS: equivalent (tools/equiv.py level 3: 3092 inputs, branch coverage 46/46)
// FUN_001b8b60 @ 0x001b8b60

#define MATCH(key,n,value) { unsigned i; for(i=0;i<n;++i) if(text[i]!=key[i]) break; if(i==n) return value; }
extern "C" const char* __cdecl FUN_001b8b60(const char* text) {
 MATCH(DAT_0040b914,27,DAT_00420dc4)
 MATCH(DAT_003ffce8,18,DAT_00420d90)
 MATCH(DAT_00420d74,25,DAT_00420d28)
 MATCH(DAT_00420d08,25,DAT_00420c98)
 MATCH(DAT_00420c80,23,DAT_00420c28)
 MATCH(DAT_00420c0c,24,DAT_00420b90)
 MATCH(DAT_00420b78,24,DAT_00420b20)
 MATCH(DAT_00420b00,25,DAT_00420aa8)
 MATCH(DAT_00420a84,31,DAT_00420a58)
 MATCH(DAT_00420a38,31,DAT_00420a0c)
 MATCH(DAT_004209ec,31,DAT_004209c0)
 MATCH(DAT_004209a0,31,DAT_00420974)
 MATCH(DAT_00420954,31,((const char*)&DAT_004208a8))
 MATCH(DAT_00420884,31,((const char*)&DAT_003f335c))
 MATCH(DAT_00420864,32,DAT_00420810)
 MATCH(DAT_004207ec,32,DAT_00420798)
 MATCH(DAT_00420774,32,DAT_00420720)
 MATCH(DAT_004206fc,32,DAT_004206a8)
 MATCH(DAT_00420674,52,DAT_00420628)
 MATCH(DAT_004205f0,51,DAT_00420590)
 MATCH(DAT_00420578,19,((const char*)&DAT_00420520))
 MATCH(DAT_004204fc,29,DAT_00420478)
 MATCH(DAT_0042045c,28,((const char*)&DAT_004203b8))
 return ((const char*)&DAT_003f335c);
}
} // namespace fn_001b8b60
#undef MATCH

namespace fn_ff10b020 {

// 0x001b8dc0 FUN_001b8dc0 (119 B): matches/0x001b8dc0.cpp
// sym: ?Fn@fn_ff10b020@@YGHHUB_1b8dc0@1@UC_1b8dc0@1@H@Z
int __stdcall Fn(int a1, B_1b8dc0 b, C_1b8dc0 c, int a8) {
    S_1b8dc0* s = GetS_0027f250();
    M_1b8dc0 m;
    m.Ident_0022b980();
    ((owners::Target_22be40 *)&m)->FUN_0022be40((const int *)(B_1b8dc0 *)(&b));
    m.Set3_0022bc20(c.x, c.y, c.z);
    c.Init_0027b0e0(a1);
    int r = s->Run_00283a40(&c, &m, -1.0f, a8);
    c.Done_0027af50();
    return r;
}


// 0x001b8e40 FUN_001b8e40 (119 B): matches/0x001b8e40.cpp
// sym: ?FUN_001b8e40@fn_ff10b020@@YGPAUSpawned@1@PBDMMM@Z
// FUN_001b8e40 @ 0x001b8e40
Spawned* __stdcall FUN_001b8e40(const char* name, float x, float y, float z) {
    Spawner_1b8e40* spawner = FUN_0027f250();
    union {
        V3_1b8e40 pos;
        Id64_1b8e40 id;
    } u;
    Matrix mat;
    mat.FUN_0022b980();
    u.pos.x = x;
    u.pos.y = y;
    u.pos.z = z;
    ((owners::Target_22be40 *)&mat)->FUN_0022be40((const int *)(const V3_1b8e40 *)(&u.pos));
    u.id.FUN_0027b0e0(name);
    Spawned* result = spawner->FUN_00283a40(&u.id, &mat, -1.0f, 1.0f);
    u.id.FUN_0027af50();
    return result;
}

} // namespace fn_ff10b020

// 0x001b8ec0 FUN_001b8ec0 (20 B): matches/0x001b8ec0.cpp [wrapped: conflict: FUN_0027f250]
// sym: ?FUN_001b8ec0@fn_001b8ec0@@YGPAXPAX@Z
namespace fn_001b8ec0 {
void* FUN_0027f250();
struct Helper_1b8ec0 {
    void* Run_0027ffb0(void*);
};
void* __stdcall FUN_001b8ec0(void* arg) {
    return ((Helper_1b8ec0*)FUN_0027f250())->Run_0027ffb0(arg);
}
} // namespace fn_001b8ec0


// 0x001b8ee0 CRenderManager::vfunc_1 (271 B): equivalent/0x001b8ee0.cpp
// sym: ?vfunc_1@CRenderManager@@UAE_NPAX@Z @f13e26109544 @wb4f2ca012a3c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CRenderManager::vfunc_1 @ 0x001b8ee0
bool CRenderManager::vfunc_1(void* __p0) { Reader_1b8ee0 * reader = (Reader_1b8ee0 *)__p0;

 Reader_1b8ee0* source=reader;
 const char* name=source->FUN_003365b0("Name");
 struct Scratch {float tz,rx,ry,tx,ty,sx,sz,sy;} s;
 source->FUN_00336600("translate",&s.tx,&s.ty,&s.tz);
 source->FUN_00336600("rotate",&s.rx,&s.ry,reinterpret_cast<float*>(&reader));
 source->FUN_00336600("scale",&s.sx,&s.sy,&s.sz);
 Vec3_1b8ee0 t,r;
 t.x=s.tx; t.y=s.ty; t.z=-s.tz;
 r.x=s.rx*-0.01745329238474369f;
 r.y=s.ry*-0.01745329238474369f;
 r.z=*reinterpret_cast<float*>(&reader)*0.01745329238474369f;
 ((CRenderManager_nv_1b8ee0*)this)->FUN_001b8dc0(name,t,r,s.sx);
 return true;
}


// 0x001b8ff0 CRenderManager::vfunc_2 (6 B): matches/0x001b8ff0.cpp
// sym: ?vfunc_2@CRenderManager@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int CRenderManager::vfunc_2() {
    return 1;
}


// 0x001b9000 CRenderManager::vfunc_3 (20 B): matches/0x001b9000.cpp
// sym: ?vfunc_3@CRenderManager@@UAEPAXPAX@Z
void* CRenderManager::vfunc_3(void* __p0) { void * p = (void *)__p0;

    return (void*)((const char*)((p != 0) - 1 & ((hulk_intptr)((char*)&DAT_00420dd8))));
}


// 0x001b9020 FUN_001b9020 (139 B): matches/0x001b9020.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b9020@CRenderManager_1b9020@fn_001b9020@@QAEXXZ
namespace fn_001b9020 {
// FUN_001b9020 @ 0x001b9020
// Screen/menu activation: bring up the HUD handles, flag the UI as active and reset the player's counter once.
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

class Cursor_1b9020 {
public:
    int FUN_000d6f50();
    void FUN_000d7030(int mode);
};

class Widget_1b9020 {
public:
    void FUN_000afe80();
};

class Fader_1b9020 {
public:
    void FUN_001c3800(float scale, int a, int b, int c, int d);
};

class Panel_1b9020 {
public:
    Widget_1b9020* FUN_00086330();
};

class Player_1b9020 {
public:
    char pad0[0x1e58];
    int counter;
    void FUN_000361c0(int flag);
};

class PlayerHolder_1b9020 {
public:
    char pad0[0x124];
    Player_1b9020* player;
};

class World {
public:
    char pad0[0x20];
    PlayerHolder_1b9020* holder;
    char pad24[0x3c - 0x24];
    Cursor_1b9020* cursor;
    char pad40[0x54 - 0x40];
    Panel_1b9020* panel;
};


Fader_1b9020* __cdecl FUN_001c3d90();

class CRenderManager_1b9020 {
public:
    char pad0[0x24];
    int cursorId;
    char pad28[0x32 - 0x28];
    char started;

    void FUN_001b9020();
};

void CRenderManager_1b9020::FUN_001b9020()
{
    cursorId = DAT_004dd700->cursor->FUN_000d6f50();
    DAT_004dd700->cursor->FUN_000d7030(0x100);
    DAT_004dd700->panel->FUN_00086330()->FUN_000afe80();
    FUN_001c3d90()->FUN_001c3800(0.28f, 0, 0, 0, 0);
    DAT_004e222c = 1;
    Player_1b9020* player = DAT_004dd700->holder->player;
    if (player) {
        player->counter = 0;
        if (!started) {
            player->FUN_000361c0(1);
            started = 1;
        }
    }
}
} // namespace fn_001b9020
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b90b0 FUN_001b90b0 (97 B): matches/0x001b90b0.cpp
// sym: ?FUN_001b90b0@CRenderManager@@QAEXXZ
void CRenderManager::FUN_001b90b0() {
    unsigned x = hulk_at_004dd700->part->Get_000d6f50();
    hulk_at_004dd700->part->Set_000d7030((*(unsigned int *)&this->f_24) | x);
    Make_001c3d90()->Act_001c3810(1, 0.5f, 0, 0);
    Engine_1b90b0* e = hulk_at_004dd700->sub->p;
    if (e && this->f_32) {
        this->f_32 = 0;
        e->Stop_000361c0(0);
    }
}


// 0x001b9120 FUN_001b9120 (12 B): matches/0x001b9120.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b9120@fn_001b9120@@YAXXZ
namespace fn_001b9120 {
class Obj_1b9120 {
  public:
    void Run();
};
Obj_1b9120* __fastcall FUN_001c3d90();
void __fastcall FUN_001c3cb0(Obj_1b9120*);
void FUN_001b9120() {
    FUN_001c3cb0(FUN_001c3d90());
}
} // namespace fn_001b9120


// 0x001b9130 FUN_001b9130 (33 B): matches/0x001b9130.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b9130@fn_001b9130@@YGXH@Z
namespace fn_001b9130 {
// FUN_001c3d90 is the 0-argument singleton getter; the six pushed values are arguments of FUN_001c37a0 (ret 0x18).
struct Registry_1b9130 {
    void FUN_001c37a0(float, int, int, int, int, int);
};
Registry_1b9130* FUN_001c3d90();
void __stdcall FUN_001b9130(int value) {
    FUN_001c3d90()->FUN_001c37a0(1.0f, 0, 0, 1, value, 0);
}
} // namespace fn_001b9130


// 0x001b9160 FUN_001b9160 (26 B): matches/0x001b9160.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b9160@fn_001b9160@@YGXH@Z
namespace fn_001b9160 {
// FUN_001c3d90 is the 0-argument singleton getter; the four pushed values are arguments of FUN_001c37f0.
struct Registry_1b9160 {
    void FUN_001c37f0(int a, int b, int c, int d);
};
Registry_1b9160* FUN_001c3d90();
void __stdcall FUN_001b9160(int value) {
    FUN_001c3d90()->FUN_001c37f0(0, 0, 1, value);
}
} // namespace fn_001b9160


// 0x001b9180 FUN_001b9180 (33 B): matches/0x001b9180.cpp [wrapped: conflict: Make]
// sym: _FUN_001b9180@4
namespace fn_001b9180 {
class Obj {
  public:
    void Init_001c37a0(float, int, int, int, void*, int);
};
extern "C++" __declspec(nothrow) Obj* __stdcall Make_001c3d90();
extern "C" void __stdcall FUN_001b9180(void* p) {
    Make_001c3d90()->Init_001c37a0(1.0f, 0, 0, 1, p, 1);
}
} // namespace fn_001b9180

namespace fn_ff10b020 {

// 0x001b91b0 FUN_001b91b0 (26 B): matches/0x001b91b0.cpp
// sym: ?FUN_001b91b0@fn_ff10b020@@YGXH@Z
void __stdcall FUN_001b91b0(int x) {
    make_001c3d90()->run_001c37f0(0, 0, 1, x);
}


// 0x001b91d0 FUN_001b91d0 (41 B): matches/0x001b91d0.cpp
// sym: ?FUN@fn_ff10b020@@YGPAUV@1@PAU21@@Z
V* __stdcall FUN(V* out) {
    *out = *fetch_001c3d90()->get_001c39a0();
    return out;
}

} // namespace fn_ff10b020

// 0x001b9200 FUN_001b9200 (41 B): matches/0x001b9200.cpp [wrapped: conflict: FUN_001c3d90; target]
// sym: ?target@fn_001b9200@@YG?AUV@1@XZ
namespace fn_001b9200 {
struct V {
    int a, b, c;
};
class A {
  public:
    V* Get_001c39b0();
};
A* __cdecl FUN_001c3d90();
V __stdcall target() {
    return *FUN_001c3d90()->Get_001c39b0();
}
} // namespace fn_001b9200


// 0x001b9230 FUN_001b9230 (41 B): matches/0x001b9230.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?target@fn_001b9230@@YG?AUVec@1@XZ
namespace fn_001b9230 {
struct Vec {
    int a, b, c;
};
class Obj {
  public:
    Vec* get_001c39c0();
};
Obj* FUN_001c3d90();
Vec __stdcall target() {
    Obj* o = FUN_001c3d90();
    return *o->get_001c39c0();
}
} // namespace fn_001b9230

namespace fn_ff10b020 {

// 0x001b9260 FUN_001b9260 (41 B): matches/0x001b9260.cpp
// sym: ?target@fn_ff10b020@@YG?AUVec@1@XZ
Vec __stdcall target() {
    A* a = findA_001c3d90();
    return *((Vec *)((owners::Object_1c39d0 *)a)->FUN_001c39d0());
}


// 0x001b9290 FUN_001b9290 (34 B): matches/0x001b9290.cpp
// sym: ?FUN@fn_ff10b020@@YGXHH@Z
void __stdcall FUN(hulk_intptr key, int v) {
    Root* root = GetRoot_001c3d90();
    Manager* mgr = root->manager;
    Obj* o = mgr->Find_001c7f10(key);
    if (o)
        o->value = v;
}

} // namespace fn_ff10b020

// 0x001b92c0 FUN_001b92c0 (20 B): matches/0x001b92c0.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?target@fn_001b92c0@@YGXI@Z
namespace fn_001b92c0 {
// Same code shape as 0x001b8900. FUN_001c3d90 is the 0-argument singleton getter; param_1 is the method's argument.
typedef unsigned int u32_1b92c0;
struct Registry_1b92c0 {
    void FUN_001c4090(u32_1b92c0);
};
Registry_1b92c0* FUN_001c3d90();
void __stdcall target(u32_1b92c0 value) {
    FUN_001c3d90()->FUN_001c4090(value);
}
} // namespace fn_001b92c0


// 0x001b93a0 FUN_001b93a0 (1341 B): equivalent/0x001b93a0.cpp [wrapped: conflict: FUN_001c3d90; World]
// sym: ?FUN_001b93a0@Frontend_1b93a0@fn_001b93a0@@QAEXPAUFrame_1b93a0@2@PAUScene_1b93a0@2@PAVMenu_1b93a0@2@PAVOverlays_1b93a0@2@HH@Z @bf8ad8ab4db2 @wd3c7ebca4f7c
namespace fn_001b93a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3080 inputs, branch coverage 83/96, incomplete)
// FUN_001b93a0 @ 0x001b93a0
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

struct Vec3_1b93a0 {
    float x, y, z;
};

class Node {
public:
    char FUN_00059a50(Vec3_1b93a0 *out);
};

class Region_1b93a0 {
public:
    char FUN_001c8790(Vec3_1b93a0 *pos);
};

class Tracker_1b93a0 {
public:
    Vec3_1b93a0 *FUN_001c39d0();
    char pad0[4];
    Region_1b93a0 *region;
};

class Display_1b93a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int v);
    virtual void vf4(float x, float y, float z, float scale, unsigned int color);
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(int v);
    virtual void vf8(float a, unsigned int colorA, float b, float c, unsigned int colorB, float d,
                     float e, float f);
    virtual void vf9();
};

class Gfx {
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
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
    virtual void v85(int v);
    virtual char v86();
    virtual void v87();
    virtual void v88();
    virtual Display_1b93a0 *v89(int v);
};

class Probe_1b93a0 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

class Settings_1b93a0 {
public:
    char FUN_0023f760(const char *name, int a, int b);
    char FUN_0023f770(const char *name, int a);
};

class Input_1b93a0 {
public:
    char FUN_00092940(int button);
};

class Pad_1b93a0 {
public:
    Input_1b93a0 *FUN_00086340();
};

struct World {
    char pad0[0x54];
    Pad_1b93a0 *pad;
};

class Stats_1b93a0 {
public:
    void FUN_0028f9a0();
    void FUN_0028faf0(int v);
};

struct Body_1b93a0 {
    char pad0[0x10];
    Node *node;
};

struct Controller_1b93a0 {
    char pad0[0x124];
    Body_1b93a0 *body;
};

struct Frame_1b93a0 {
    int type;
};

class Camera {
public:
    void FUN_001bc720();
};

class Fader_1b93a0 {
public:
    void FUN_001bf8b0();
};

struct Scene_1b93a0 {
    char pad0[0x20];
    Controller_1b93a0 *controller;
    char pad1[0x40 - 0x24];
    Camera *camera;
    char pad2[0x50 - 0x44];
    Fader_1b93a0 *fader;
};

class Menu_1b93a0 {
public:
    void FUN_000bdd60();
};

class Overlays_1b93a0 {
public:
    void FUN_000d6c70();
};


Tracker_1b93a0 *FUN_001c3d90();
unsigned int FUN_00267f00();

class Frontend_1b93a0 {
public:
    void FUN_001b93a0(Frame_1b93a0 *frame, Scene_1b93a0 *scene, Menu_1b93a0 *menu, Overlays_1b93a0 *overlays, int a4, int a5);

    char pad0[0x31];
    char skip;
};

void Frontend_1b93a0::FUN_001b93a0(Frame_1b93a0 *frame, Scene_1b93a0 *scene, Menu_1b93a0 *menu, Overlays_1b93a0 *overlays, int a4, int a5)
{
    if (skip)
        return;
    unsigned int startTick = 0;
    if ((*(char*)&DAT_004dd8e4))
        startTick = FUN_00267f00();
    (*(Probe_1b93a0**)&DAT_0052c2a4)->v14();
    if ((*(Settings_1b93a0**)&DAT_004dd6e8)->FUN_0023f770("PDDI stats", 0x70)) {
        DAT_0052c2a8->v85(DAT_0052c2a8->v86() == 0);
    }
    (*(Stats_1b93a0**)&DAT_0052c2b4)->FUN_0028f9a0();
    if (frame->type == 4 || frame->type == 6) {
        Vec3_1b93a0 pos = *FUN_001c3d90()->FUN_001c39d0();
        if (!FUN_001c3d90()->region->FUN_001c8790(&pos)) {
            Controller_1b93a0 *c = scene->controller;
            if (c->body != 0) {
                if (c->body->node->FUN_00059a50(&pos))
                    FUN_001c3d90()->region->FUN_001c8790(&pos);
            }
        }
        scene->camera->FUN_001bc720();
        if (!DAT_004e2240)
            DAT_004e2240 = 1;
        Display_1b93a0 *d = DAT_0052c2a8->v89(0x103);
        Input_1b93a0 *input = DAT_004dd700->pad->FUN_00086340();
        if (input->FUN_00092940(0xe)) {
            d->vf4(-100.0f, 0.0f, 0.0f, 0.5f, 0xffffd490u);
            d->vf3(1);
        } else if (input->FUN_00092940(0xd)) {
            d->vf4(-100.0f, 0.0f, 0.0f, 0.5f, 0xffffffffu);
            d->vf3(1);
        } else {
            d->vf5();
        }
        if ((*(char*)&DAT_004c3be8)) {
            if (DAT_004e2250) {
                DAT_004e2244 = 0;
                DAT_004e2248 = 0;
                DAT_004e224c = 0;
                (*(float*)&DAT_004c3bd8) = 0.5f;
                DAT_004c3bdc = 0xff;
                DAT_004c3be0 = 0xff;
                DAT_004c3be4 = 0xff;
                DAT_004e2250 = 0;
            }
            d->vf3((unsigned char)(*(char*)&DAT_004e2241));
            int b = DAT_004c3be4 < 0 ? 0 : (DAT_004c3be4 > 255 ? 255 : DAT_004c3be4);
            int g = DAT_004c3be0 < 0 ? 0 : (DAT_004c3be0 > 255 ? 255 : DAT_004c3be0);
            int rr = DAT_004c3bdc < 0 ? 0 : (DAT_004c3bdc > 255 ? 255 : DAT_004c3bdc);
            unsigned int color = (((((unsigned int)rr | 0xffffff00u) << 8) | g) << 8) | b;
            d->vf4(DAT_004e2244, DAT_004e2248, DAT_004e224c, (*(float*)&DAT_004c3bd8), color);
            d->vf3((unsigned char)(*(char*)&DAT_004e2241));
            (*(char*)&DAT_004c3be8) = 0;
        }
        d->vf6();
        if (DAT_004e2264) {
            if ((*(char*)&DAT_004e2265)) {
                DAT_004e2254 = 0;
                DAT_004c3bf0 = 0xff;
                DAT_004c3bf4 = 0xff;
                DAT_004c3bf8 = 0xff;
                DAT_004e2258 = 0;
                DAT_004c3bfc = 0x80;
                DAT_004c3c00 = 0x80;
                DAT_004c3c04 = 0x80;
                DAT_004e225c = 0;
                DAT_004e2260 = 0;
                (*(float*)&DAT_004c3c08) = 0.5f;
                (*(char*)&DAT_004e2265) = 0;
            }
            int e = DAT_004c3c04 < 0 ? 0 : (DAT_004c3c04 > 255 ? 255 : DAT_004c3c04);
            int f = DAT_004c3c00 < 0 ? 0 : (DAT_004c3c00 > 255 ? 255 : DAT_004c3c00);
            int h = DAT_004c3bfc < 0 ? 0 : (DAT_004c3bfc > 255 ? 255 : DAT_004c3bfc);
            unsigned int colorB = (((((unsigned int)h | 0xffffff00u) << 8) | f) << 8) | e;
            int k = DAT_004c3bf8 < 0 ? 0 : (DAT_004c3bf8 > 255 ? 255 : DAT_004c3bf8);
            int m = DAT_004c3bf4 < 0 ? 0 : (DAT_004c3bf4 > 255 ? 255 : DAT_004c3bf4);
            int n = DAT_004c3bf0 < 0 ? 0 : (DAT_004c3bf0 > 255 ? 255 : DAT_004c3bf0);
            unsigned int colorA = (((((unsigned int)n | 0xffffff00u) << 8) | m) << 8) | k;
            d->vf8(DAT_004e2254, colorA, (*(float*)&DAT_004c3c0c), DAT_004e2258, colorB, DAT_004e225c,
                   DAT_004e2260, (*(float*)&DAT_004c3c08));
            d->vf7((unsigned char)(*(char*)&DAT_004e2251));
            DAT_004e2264 = 0;
        }
        d->vf9();
        scene->fader->FUN_001bf8b0();
    }
    if (frame->type == 4) {
        if ((*(Settings_1b93a0**)&DAT_004dd6e8)->FUN_0023f760("Render Overlays", 0x23, 1))
            overlays->FUN_000d6c70();
    }
    if ((*(Settings_1b93a0**)&DAT_004dd6e8)->FUN_0023f760("Render Frontend", 0x40, 1))
        menu->FUN_000bdd60();
    if ((*(char*)&DAT_004dd8e4)) {
        unsigned int now = FUN_00267f00();
        if ((*(char*)&DAT_004dd8e4))
            (*(float*)&DAT_004dd91c) = (float)(now - startTick) * 1e-06f;
    }
    (*(Stats_1b93a0**)&DAT_0052c2b4)->FUN_0028faf0(0);
}
} // namespace fn_001b93a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b98e0 FUN_001b98e0 (463 B): equivalent/0x001b98e0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001b98e0@CRenderManager_1b98e0@fn_001b98e0@@QAEHMMMMMM@Z @fa6dce19354e @wbf2449e0adb4
namespace fn_001b98e0 {
// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 32/38, incomplete)
// FUN_001b98e0 @ 0x001b98e0
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

class Target_1b98e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int v8(float a0, int color2, float a1, float a2, int color1, float a3, float a4, float a5);
};

class Gfx {
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
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
    virtual Target_1b98e0 *v89(int id);
};


static int clamp255(int v)
{
    if (v < 0)
        return 0;
    if (v > 255)
        return 255;
    return v;
}

class CRenderManager_1b98e0 {
public:
    char pad00[0x34];
    int r1;     // 0x34
    int g1;     // 0x38
    int b1;     // 0x3c
    int r2;     // 0x40
    int g2;     // 0x44
    int b2;     // 0x48
    float p0;   // 0x4c
    float p1;   // 0x50
    float p2;   // 0x54
    float p3;   // 0x58
    float p4;   // 0x5c
    float p5;   // 0x60
    int FUN_001b98e0(float a0, float a1, float a2, float a3, float a4, float a5);
};

int CRenderManager_1b98e0::FUN_001b98e0(float a0, float a1, float a2, float a3, float a4, float a5)
{
    p0 = a0;
    p1 = a1;
    p2 = a2;
    p3 = a3;
    p4 = a4;
    p5 = a5;
    Target_1b98e0 *t = DAT_0052c2a8->v89(0x103);
    if (t == 0)
        return 0;
    DAT_004e2254 = a0;
    DAT_004c3bf0 = r1;
    DAT_004c3bf4 = g1;
    DAT_004e2258 = a2;
    DAT_004c3bf8 = b1;
    DAT_004c3bfc = r2;
    DAT_004c3c00 = g2;
    DAT_004c3c04 = b2;
    DAT_004e225c = a3;
    DAT_004e2260 = a4;
    (*(float*)&DAT_004c3c08) = a5;
    int color1 = (0xff << 24) | (clamp255(r2) << 16) | (clamp255(g2) << 8) | clamp255(b2);
    int color2 = (0xff << 24) | (clamp255(r1) << 16) | (clamp255(g1) << 8) | clamp255(b1);
    return t->v8(a0, color2, a1, a2, color1, a3, a4, a5);
}
} // namespace fn_001b98e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b9ab0 FUN_001b9ab0 (138 B): equivalent/0x001b9ab0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?SetColor@fn_001b9ab0@@YGHHHH@Z @f3218102b791 @wfba4f0ad0b5d
namespace fn_001b9ab0 {
// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 15/18, incomplete)
// FUN_001b9ab0 @ 0x001b9ab0
struct Sink_1b9ab0 {  };
struct Holder_1b9ab0 { Sink_1b9ab0* sink; };
Holder_1b9ab0* FUN_001c3d90();
static int Clamp255(int v) { return v < 0 ? 0 : (v > 255 ? 255 : v); }
int __stdcall SetColor(int r, int g, int b) {
    int cr = Clamp255(r);
    int cg = Clamp255(g);
    int cb = Clamp255(b);
    unsigned argb = (((0xffu << 8 | cr) << 8 | cg) << 8) | cb;
    return ((owners::C_1c1790 *)(FUN_001c3d90()->sink))->FUN_001c1790((int)argb);
}
} // namespace fn_001b9ab0


// 0x001b9b40 FUN_001b9b40 (138 B): equivalent/0x001b9b40.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?SetColor@fn_001b9b40@@YGHHHH@Z @9bcaac472bd1 @w77075f907605
namespace fn_001b9b40 {
// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 15/18, incomplete)
// FUN_001b9b40 @ 0x001b9b40
struct Sink_1b9b40 {  };
struct Holder_1b9b40 { Sink_1b9b40* sink; };
Holder_1b9b40* FUN_001c3d90();
static int Clamp255(int v) { return v < 0 ? 0 : (v > 255 ? 255 : v); }
int __stdcall SetColor(int r, int g, int b) {
    int cr = Clamp255(r);
    int cg = Clamp255(g);
    int cb = Clamp255(b);
    unsigned argb = (((0xffu << 8 | cr) << 8 | cg) << 8) | cb;
    return ((owners::C_1c17c0 *)(FUN_001c3d90()->sink))->FUN_001c17c0((int)argb);
}
} // namespace fn_001b9b40


// 0x001b9c10 Method1<CRenderManager,void,bool>::vfunc_0 (30 B): matches/0x001b9c10.cpp
// sym: ??_G?$Method1@VCRenderManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CRenderManager, void, bool>::~Method1() {}


// 0x001b9c30 Method1<CRenderManager,void,bool>::vfunc_2 (21 B): matches/0x001b9c30.cpp
// sym: ?vfunc_2@?$Method1@VCRenderManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CRenderManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9c30 * obj = (CActorManager_1b9c30 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1b9c30 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CRenderManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b9c10)
#endif

namespace fn_ff10b020 {

// 0x001b9c50 FUN_001b9c50 (89 B): matches/0x001b9c50.cpp
// sym: ??0Method3_1b9c50@fn_ff10b020@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
Method3_1b9c50::Method3_1b9c50(const char* p, ScriptMemberFn x) {
    Init_001d0480(p, 3);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00420e24);
    member1c = x;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}

} // namespace fn_ff10b020

// 0x001b9cb0 Method3<CRenderManager,void,int,int,int>::vfunc_0 (30 B): matches/0x001b9cb0.cpp
// sym: ??_G?$Method3@VCRenderManager@@XHHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CRenderManager, void, int, int, int>::~Method3() {}


// 0x001b9cd0 Method3<CRenderManager,void,int,int,int>::vfunc_2 (29 B): equivalent/0x001b9cd0.cpp
// sym: ?vfunc_2@?$Method3@VCRenderManager@@XHHH@@UAEXPAX00@Z @a7a6d240b96d @w2ac42a573389
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CRenderManager,void,int,int,int>::vfunc_2 @ 0x001b9cd0
template <> void Method3<CRenderManager, void, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CRenderManager_1b9cd0 * object = (CRenderManager_1b9cd0 *)__p0; const int * args = (const int *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CRenderManager_1b9cd0::**)(int, int, int))&this->f_1c))(args[0], args[1], args[2]);
}
#if defined(HULK_PTR64)
template class Method3<CRenderManager, void, int, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b9cb0)
#endif


// 0x001b9d40 Method2<CRenderManager,void,float,float>::vfunc_0 (30 B): matches/0x001b9d40.cpp
// sym: ??_G?$Method2@VCRenderManager@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CRenderManager, void, float, float>::~Method2() {}


// 0x001b9d60 Method2<CRenderManager,void,float,float>::vfunc_2 (23 B): matches/0x001b9d60.cpp
// sym: ?vfunc_2@?$Method2@VCRenderManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CRenderManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1b9d60* m = (CFEManager_1b9d60*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1b9d60::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CRenderManager, void, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b9d40)
#endif

namespace fn_ff10b020 {

// 0x001b9d80 FUN_001b9d80 (128 B): matches/0x001b9d80.cpp
// sym: ??0Method6_1b9d80@fn_ff10b020@@QAE@HH@Z
Method6_1b9d80::Method6_1b9d80(hulk_intptr x, hulk_intptr y) {
    Init_001d0480(x, 6);
    v = ((hulk_intptr)DAT_00420e44);
    field = y;
    a[8] = Helper_001d04d0(((const char*)&DAT_0048e100));
    a[0] = Helper_001d04d0(((const char*)&DAT_0048e128));
    a[1] = Helper_001d04d0(((const char*)&DAT_0048e128));
    a[2] = Helper_001d04d0(((const char*)&DAT_0048e128));
    a[3] = Helper_001d04d0(((const char*)&DAT_0048e128));
    a[4] = Helper_001d04d0(((const char*)&DAT_0048e128));
    a[5] = Helper_001d04d0(((const char*)&DAT_0048e128));
}

} // namespace fn_ff10b020

// 0x001b9e00 Method6<CRenderManager,void,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x001b9e00.cpp
// sym: ??_G?$Method6@VCRenderManager@@XMMMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CRenderManager, void, float, float, float, float, float, float>::~Method6() {}


// 0x001b9e20 Method6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 (30 B): matches/0x001b9e20.cpp
// sym: ?vfunc_2@?$Method6@VCRenderManager@@XMMMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CRenderManager, void, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001b9e40(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CRenderManager, void, float, float, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b9e00)
#endif

namespace fn_ff10b020 {

// 0x001b9e40 FUN_001b9e40 (82 B): equivalent/0x001b9e40.cpp
// sym: ?FUN_001b9e40@fn_ff10b020@@YAXPAXPBUValues@1@HP6AXHHHHHH@Z@Z @76081efbe4fb @w1f3f96e9dee0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001b9e40 @ 0x001b9e40
void __cdecl FUN_001b9e40(void *context, const Values *values, int unused, Callback callback)
{
    callback(values->values[0], values->values[1], values->values[2], values->values[3], values->values[4], values->values[5]);
}

} // namespace fn_ff10b020

// 0x001b9ee0 Method0<CRenderManager,void>::vfunc_0 (30 B): matches/0x001b9ee0.cpp
// sym: ??_G?$Method0@VCRenderManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CRenderManager, void>::~Method0() {}


// 0x001b9f00 Method0<CRenderManager,void>::vfunc_2 (12 B): matches/0x001b9f00.cpp
// sym: ?vfunc_2@?$Method0@VCRenderManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CRenderManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9f00 * a = (CActorManager_1b9f00 *)__p0;

    (a->*(*(void (CActorManager_1b9f00::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CRenderManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b9ee0)
#endif


// 0x001b9f50 Method0<CRenderManager,bool>::vfunc_0 (30 B): matches/0x001b9f50.cpp
// sym: ??_G?$Method0@VCRenderManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CRenderManager, bool>::~Method0() {}


// 0x001b9f70 Method0<CRenderManager,bool>::vfunc_2 (22 B): matches/0x001b9f70.cpp
// sym: ?vfunc_2@?$Method0@VCRenderManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CRenderManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9f70 * obj = (CActorManager_1b9f70 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_1b9f70 fn = (*(Fn_1b9f70 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method0<CRenderManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b9f50)
#endif

namespace fn_ff10b020 {

// 0x001b9f90 FUN_001b9f90 (102 B): matches/0x001b9f90.cpp
// sym: ??0Method4_1b9f90@fn_ff10b020@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
Method4_1b9f90::Method4_1b9f90(const char* a, ScriptMemberFn b) : FUN_001d0480(a, 4) {
    vptr = ((hulk_intptr)DAT_00420e74);
    field1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_ff10b020

// 0x001ba000 Method4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x001ba000.cpp
// sym: ??_G?$Method4@VCRenderManager@@IPBDMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CRenderManager, unsigned int, const char *, float, float, float>::~Method4() {}


// 0x001ba020 Method4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_2 (30 B): matches/0x001ba020.cpp
// sym: ?vfunc_2@?$Method4@VCRenderManager@@IPBDMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method4<CRenderManager, unsigned int, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001ba040(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method4<CRenderManager, unsigned int, const char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba000)
#endif


// 0x001ba040 FUN_001ba040 (70 B): equivalent/0x001ba040.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001ba040@fn_001ba040@@YAXPAUCaller@1@PAUArgs@1@PAHP821@AEHHHHH@Z@Z @369971183f67 @w490dced5be09
namespace fn_001ba040 {
// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_001ba040 @ 0x001ba040
struct Caller { int FUN_001ba040_call(int a, int b, int c, int d); }; 
struct Args { int a; int b; int c; int d; };
typedef int (Caller::*Callback)(int,int,int,int);
void __cdecl FUN_001ba040(Caller* caller, Args* args, int* result, Callback callback) {
    int value = (caller->*callback)(args->a, args->b, args->c, args->d);
    if (result != 0) *result = value;
}
} // namespace fn_001ba040

namespace fn_ff10b020 {

// 0x001ba090 FUN_001ba090 (102 B): matches/0x001ba090.cpp
// sym: ??0Method4_1ba090@fn_ff10b020@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
Method4_1ba090::Method4_1ba090(const char* x, ScriptMemberFn y) {
    Init_001d0480(x, 4);
    v = ((hulk_intptr)DAT_00420e84);
    p1c = y;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_ff10b020

// 0x001ba100 Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_0 (30 B): matches/0x001ba100.cpp
// sym: ??_G?$Method4@VCRenderManager@@IPBDVVector@math@@V23@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CRenderManager, unsigned int, const char *,math::Vector,math::Vector, float>::~Method4() {}


// 0x001ba120 Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 (110 B): equivalent/0x001ba120.cpp
// sym: ?vfunc_2@?$Method4@VCRenderManager@@IPBDVVector@math@@V23@M@@UAEXPAX00@Z @e1f85de89946 @w8e30c855c2fa
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001ba120
template <> void Method4<CRenderManager, unsigned int, const char *,math::Vector,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CRenderManager_1ba120 * obj = (CRenderManager_1ba120 *)__p0; Args_1ba120 * args = (Args_1ba120 *)__p1; unsigned int * out = (unsigned int *)__p2;

    CheckFn_1ba120 fn = (*(CheckFn_1ba120 *)&this->f_1c);
    unsigned r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method4<CRenderManager, unsigned int, const char *,math::Vector,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba100)
#endif


// 0x001ba1d0 Method1<CRenderManager,void,unsigned_int>::vfunc_0 (30 B): matches/0x001ba1d0.cpp
// sym: ??_G?$Method1@VCRenderManager@@XI@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CRenderManager, void, unsigned int>::~Method1() {}


// 0x001ba1f0 Method1<CRenderManager,void,unsigned_int>::vfunc_2 (19 B): matches/0x001ba1f0.cpp
// sym: ?vfunc_2@?$Method1@VCRenderManager@@XI@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CRenderManager, void, unsigned int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1ba1f0* d = (Dummy_1ba1f0*)a;
    (d->*(*(void (Dummy_1ba1f0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CRenderManager, void, unsigned int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba1d0)
#endif


// 0x001ba250 Method0<CRenderManager,math::Vector>::vfunc_0 (30 B): matches/0x001ba250.cpp
// sym: ??_G?$Method0@VCRenderManager@@VVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CRenderManager,math::Vector>::~Method0() {}


// 0x001ba270 Method0<CRenderManager,math::Vector>::vfunc_2 (69 B): matches/0x001ba270.cpp
// sym: ?vfunc_2@?$Method0@VCRenderManager@@VVector@math@@@@UAEXPAX00@Z
// Same code shape as 0x0008a610 (propagated; names are from that function)
template <> void Method0<CRenderManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_1ba270 * mgr = (CGameFlowManager_1ba270 *)__p0; Vector_1ba270 * out = (Vector_1ba270 *)__p2;

    Fn_1ba270 fn = (*(Fn_1ba270 *)&this->f_1c);
    Vector_1ba270 temp;
    volatile Vector_1ba270 r;
    Vector_1ba270* p = (mgr->*fn)(&temp);
    r.x = p->x;
    r.y = p->y;
    r.z = p->z;
    if (out) {
        out->x = r.x;
        out->y = r.y;
        out->z = r.z;
    }
}
#if defined(HULK_PTR64)
template class Method0<CRenderManager,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba250)
#endif


// 0x001ba310 Method2<CRenderManager,void,int,float>::vfunc_0 (30 B): matches/0x001ba310.cpp
// sym: ??_G?$Method2@VCRenderManager@@XHM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CRenderManager, void, int, float>::~Method2() {}


// 0x001ba330 Method2<CRenderManager,void,int,float>::vfunc_2 (23 B): matches/0x001ba330.cpp
// sym: ?vfunc_2@?$Method2@VCRenderManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CRenderManager, void, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1ba330* m = (CFEManager_1ba330*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1ba330::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CRenderManager, void, int, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba310)
#endif


// 0x001ba390 Method1<CRenderManager,void,float>::vfunc_0 (30 B): matches/0x001ba390.cpp
// sym: ??_G?$Method1@VCRenderManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CRenderManager, void, float>::~Method1() {}


// 0x001ba3b0 Method1<CRenderManager,void,float>::vfunc_2 (19 B): matches/0x001ba3b0.cpp
// sym: ?vfunc_2@?$Method1@VCRenderManager@@XI@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CRenderManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1ba3b0* d = (Dummy_1ba3b0*)a;
    (d->*(*(void (Dummy_1ba3b0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CRenderManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba390)
#endif


// 0x001ba410 FUN_001ba410 (76 B): matches/0x001ba410.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ba410@@QAE@HHH@Z
namespace fn_001ba410 {

extern "C++" __declspec(nothrow) unsigned char probe_001d04d0(const char*);
class Function_1ba410 {
  public:
    Function_1ba410(int, int);
    virtual void f();
    char pad[0x1c - 4];
};
class Method1 : public Function_1ba410 {
  public:
    int x;
    Method1(int a, int c) : Function_1ba410(a, 1), x(c) {
        *((unsigned char*)this + 0x18) = probe_001d04d0(((const char*)&DAT_0048e100));
        *((unsigned char*)this + 0x10) = probe_001d04d0(((const char*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    int y;
    Closure1(int a, int b, int c);
    virtual void f();
};
Closure1::Closure1(int a, int b, int c) : Method1(a, c), y(b) {}
} // namespace fn_001ba410


// 0x001ba460 Closure1<CRenderManager,void,bool>::vfunc_0 (30 B): matches/0x001ba460.cpp
// sym: ??_G?$Method0@VCRenderManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CRenderManager, void, bool>::~Closure1() {}


// 0x001ba480 Closure1<CRenderManager,void,bool>::vfunc_2 (20 B): matches/0x001ba480.cpp
// sym: ?vfunc_2@?$Closure1@VCRenderManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CRenderManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1ba480 * *)&this->f_20)->*(*(void (Actor_1ba480::**)(unsigned char))&this->f_1c))(*arg);
}
#if defined(HULK_PTR64)
template class Closure1<CRenderManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba460)
#endif


// 0x001ba4d0 Closure3<CRenderManager,void,int,int,int>::vfunc_0 (30 B): matches/0x001ba4d0.cpp
// sym: ??_G?$Method4@VCRenderManager@@IPBDVVector@math@@V23@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CRenderManager, void, int, int, int>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CRenderManager, void, int, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba4d0)
#endif


// 0x001ba510 FUN_001ba510 (89 B): matches/0x001ba510.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ba510@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ba510 {
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

extern void* hulk_at_00420e34[2];
extern void* hulk_at_00420ef4[2];
extern void* hulk_at_0048e100;
extern void* hulk_at_0048e128;
extern void* TAB_48e134;

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
    vfptr = (void*)hulk_at_00420e34;
    fn = a3;
    f.retType = FUN_001d04d0(&hulk_at_0048e100);
    f.argTypes[0] = FUN_001d04d0(&hulk_at_0048e128);
    f.argTypes[1] = FUN_001d04d0(&TAB_48e134);
    vfptr = (void*)hulk_at_00420ef4;
    owner = a2;
}
} // namespace fn_001ba510
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ba570 Closure2<CRenderManager,void,float,float>::vfunc_0 (30 B): matches/0x001ba570.cpp
// sym: ??_G?$Method1@VCRenderManager@@XI@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CRenderManager, void, float, float>::~Closure2() {}


// 0x001ba590 Closure2<CRenderManager,void,float,float>::vfunc_2 (22 B): matches/0x001ba590.cpp
// sym: ?vfunc_2@?$Closure2@VCRenderManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CRenderManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ba590 * p = (Pair_1ba590 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ba590 * *)&this->f_20)->*(*(void (CActorManager_1ba590::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CRenderManager, void, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba570)
#endif


// 0x001ba5e0 Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x001ba5e0.cpp
// sym: ??_G?$Method0@VCRenderManager@@VVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CRenderManager, void, float, float, float, float, float, float>::~Closure6() {}


// 0x001ba600 Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 (85 B): equivalent/0x001ba600.cpp
// sym: ?vfunc_2@?$Closure6@VCRenderManager@@XMMMMMM@@UAEXPAX00@Z @d87f9086673d @wf22810fd6db9
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 @ 0x001ba600
template <> void Closure6<CRenderManager, void, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const float * arguments = (const float *)__p1; void * unused2 = (void *)__p2;

    ((*(CRenderManager_1ba600 * *)&this->f_20)->*(*(void (CRenderManager_1ba600::**)(float, float, float, float, float, float))&this->f_1c))(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}
#if defined(HULK_PTR64)
template class Closure6<CRenderManager, void, float, float, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba5e0)
#endif


// 0x001ba6a0 Closure0<CRenderManager,void>::vfunc_0 (30 B): matches/0x001ba6a0.cpp
// sym: ??_G?$Method2@VCRenderManager@@XHM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CRenderManager, void>::~Closure0() {}


// 0x001ba6c0 Closure0<CRenderManager,void>::vfunc_2 (11 B): matches/0x001ba6c0.cpp
// sym: ?vfunc_2@?$Closure0@VCRenderManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CRenderManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_1ba6c0 * *)&this->f_20)->*(*(void (CActorManager_1ba6c0::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<CRenderManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba6a0)
#endif


// 0x001ba710 Closure0<CRenderManager,bool>::vfunc_0 (30 B): matches/0x001ba710.cpp
// sym: ??_G?$Method1@VCRenderManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CRenderManager, bool>::~Closure0() {}


// 0x001ba730 Closure0<CRenderManager,bool>::vfunc_2 (23 B): matches/0x001ba730.cpp
// sym: ?vfunc_2@?$Closure0@VCRenderManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CRenderManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_1ba730* o = (*(CActorManager_1ba730 * *)&this->f_20);
    Fn_1ba730 fn = (*(Fn_1ba730 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
#if defined(HULK_PTR64)
template class Closure0<CRenderManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ba710)
#endif


// 0x001ba7a0 Closure4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_2 (75 B): matches/0x001ba7a0.cpp
// sym: ?vfunc_2@?$Closure4@VCRenderManager@@IPBDMMM@@UAEXPAX00@Z
template <> void Closure4<CRenderManager, unsigned int, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * p = (void *)__p1; void * out = (void *)__p2;

    CRenderManager_1ba7a0* o = (*(CRenderManager_1ba7a0 * *)&this->f_20);
    unsigned int (CRenderManager_1ba7a0::*fn)(unsigned int, const char*, float, float) = (*(unsigned int (CRenderManager_1ba7a0::**)(unsigned int, const char *, float, float))&this->f_1c);
    unsigned int* a = (unsigned int*)p;
    unsigned int id = *a++;
    const char* volatile name = (const char*)*a++;
    float first = *(float*)a++;
    float second = *(float*)a++;
    unsigned int value = (o->*fn)(id, name, first, second);
    if (out)
        *(unsigned int*)out = value;
}


// 0x001ba840 Closure4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 (12 B): matches/0x001ba840.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_001ba840@@UAEXHHH@Z
namespace fn_001ba840 {
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
} // namespace fn_001ba840


// 0x001ba850 FUN_001ba850 (76 B): matches/0x001ba850.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ba850@@QAE@PBDPAVCRenderManager@1@P8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ba850 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class CRenderManager;
extern const char g1[], hulk_at_0049b95c[];
class Function_1ba850 : public ScriptFunctionFields {
  public:
    Function_1ba850(const char*, int);
    virtual void f();
};
class Method1 : public Function_1ba850 {
  public:
    virtual void f();
    ScriptMemberFn fn;
    Method1(const char* p, ScriptMemberFn m) : Function_1ba850(p, 1) {
        fn = m;
        retType = FUN_001d04d0(g1);
        argTypes[0] = FUN_001d04d0(hulk_at_0049b95c);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    CRenderManager* owner;
    Closure1(const char*, CRenderManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* p, CRenderManager* q, ScriptMemberFn m) : Method1(p, m) {
    owner = q;
}
} // namespace fn_001ba850
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ba8c0 Closure1<CRenderManager,void,unsigned_int>::vfunc_2 (18 B): matches/0x001ba8c0.cpp
// sym: ?vfunc_2@?$Closure1@VCRenderManager@@XI@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CRenderManager, void, unsigned int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ba8c0 * *)&this->f_20)->*(*(void (CActorManager_1ba8c0::**)(const char *))&this->f_1c))(*b);
}


// 0x001ba940 Closure0<CRenderManager,math::Vector>::vfunc_2 (63 B): equivalent/0x001ba940.cpp
// sym: ?vfunc_2@?$Closure0@VCRenderManager@@VVector@math@@@@UAEXPAX00@Z @5b5ca72bc2e3 @w5e2fdc9f34f2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CRenderManager,math::Vector>::vfunc_2 @ 0x001ba940
template <> void Closure0<CRenderManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; math::Vector_1ba940 * result = (math::Vector_1ba940 *)__p2;

    math::Vector_1ba940 value = ((*(CRenderManager_1ba940 * *)&this->f_20)->*(*(math::Vector_1ba940 (CRenderManager_1ba940::**)())&this->f_1c))();
    if (result) *result = value;
}


// 0x001ba980 FUN_001ba980 (89 B): matches/0x001ba980.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ba980@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ba980 {
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


extern void* hulk_at_00420eb4[2];
extern void* hulk_at_00420f74[2];

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
    vfptr = (void*)hulk_at_00420eb4;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_00420f74;
    owner = a2;
}
} // namespace fn_001ba980
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001baa00 Closure2<CRenderManager,void,int,float>::vfunc_2 (22 B): matches/0x001baa00.cpp
// sym: ?vfunc_2@?$Closure2@VCRenderManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CRenderManager, void, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1baa00 * p = (Pair_1baa00 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1baa00 * *)&this->f_20)->*(*(void (CActorManager_1baa00::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x001baa20 FUN_001baa20 (76 B): matches/0x001baa20.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001baa20@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001baa20 {
// data: key1 = DAT_0048e100, key2 = DAT_0048e128
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char __cdecl query_001d04d0(const void*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* name) : CtorV_001d0480(name, 1) { }
};
class Closure1_1baa20 : public Base {
  public:
    virtual void f();
    ScriptMemberFn fn;
    Closure1_1baa20(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_1baa20 {
  public:
    virtual void f();
    void* owner;
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1_1baa20::Closure1_1baa20(const char* name, ScriptMemberFn m) : Base(name) {
    fn = m;
    retType = query_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = query_001d04d0(((char*)&DAT_0048e128));
}
Closure1::Closure1(const char* name, void* obj, ScriptMemberFn m) : Closure1_1baa20(name, m) {
    owner = obj;
}
} // namespace fn_001baa20


// 0x001baa90 Closure1<CRenderManager,void,float>::vfunc_2 (18 B): matches/0x001baa90.cpp
// sym: ?vfunc_2@?$Closure1@VCRenderManager@@XI@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CRenderManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1baa90 * *)&this->f_20)->*(*(void (CActorManager_1baa90::**)(const char *))&this->f_1c))(*b);
}

namespace fn_ff10b020 {

// 0x001bb580 FUN_001bb580 (83 B): equivalent/0x001bb580.cpp
// sym: ?FUN_001bb580@Registry_1bb580@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb580@2@P832@AEXHHH@Z@Z @3484b9884c61 @wbaec67eed9c5
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001bb580 @ 0x001bb580
// FUN_001bb580 @ 0x001bb580  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1bb580::FUN_001bb580(const char* a1, CRenderManager_1bb580* a2, Fn_1bb580 a3) {
    typedef Closure3_1bb580<CRenderManager_1bb580, void, int, int, int> Alloc_1bb580;
    HULK_SIZE32(Alloc_1bb580, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1bb580));
    void* x = 0;
    if (m) {
        ((Raw_1bb580*)m)->FUN_001b9c50(a1, a3);
        x = new (m) Closure3_1bb580<CRenderManager_1bb580, void, int, int, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001bb630 FUN_001bb630 (83 B): equivalent/0x001bb630.cpp
// sym: ?FUN_001bb630@Registry_1bb630@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb630@2@P832@AEXMMMMMM@Z@Z @189ca8c953e3 @w6fbd9681608b
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001bb630 @ 0x001bb630
// FUN_001bb630 @ 0x001bb630  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1bb630::FUN_001bb630(const char* a1, CRenderManager_1bb630* a2, Fn_1bb630 a3) {
    typedef Closure6_1bb630<CRenderManager_1bb630, void, float, float, float, float, float, float> Alloc_1bb630;
    HULK_SIZE32(Alloc_1bb630, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1bb630));
    void* x = 0;
    if (m) {
        ((Raw_1bb630*)m)->FUN_001b9d80(a1, a3);
        x = new (m) Closure6_1bb630<CRenderManager_1bb630, void, float, float, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001bb690 FUN_001bb690 (109 B): matches/0x001bb690.cpp
// sym: ?Make@Owner_1bb690@fn_ff10b020@@QAEXPAXHH@Z
// data: gInfo = DAT_0048e100
void Owner_1bb690::Make(void* h, int x, int y) {
    Closure0_1bb690* c = new Closure0_1bb690(h, y, x);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)h, (hulk_intptr)(Method0_1bb690 *)c);
}

} // namespace fn_ff10b020

// 0x001bb700 FUN_001bb700 (109 B): equivalent/0x001bb700.cpp [wrapped: conflict: CRenderManager; Closure0; Method0]
// sym: ?FUN_001bb700@Registry_1bb700@fn_001bb700@@QAEXPBDPAVCRenderManager@2@P832@AE_NXZ@Z @fad7dd55f967 @we0d540f022ca
namespace fn_001bb700 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001bb700 @ 0x001bb700
// FUN_001bb700 @ 0x001bb700  (generated by work/closure/gen.py)
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


class CRenderManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1bb700 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1bb700(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1bb700 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1bb700(name, 0) {
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

struct Registry_1bb700 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001bb700(const char* name, CRenderManager* owner, bool (CRenderManager::*fn)());
};

void Registry_1bb700::FUN_001bb700(const char* name, CRenderManager* owner, bool (CRenderManager::*fn)()) {
    typedef Closure0<CRenderManager, bool> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CRenderManager, bool>));
    Closure0<CRenderManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CRenderManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001bb700
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff10b020 {

// 0x001bb770 FUN_001bb770 (83 B): equivalent/0x001bb770.cpp
// sym: ?FUN_001bb770@Registry_1bb770@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb770@2@P832@AEI0MMM@Z@Z @a90f6d8111ac @w6d0983fff29b
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001bb770 @ 0x001bb770
// FUN_001bb770 @ 0x001bb770  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1bb770::FUN_001bb770(const char* a1, CRenderManager_1bb770* a2, Fn_1bb770 a3) {
    typedef Closure4_1bb770<CRenderManager_1bb770, unsigned int, const char*, float, float, float> Alloc_1bb770;
    HULK_SIZE32(Alloc_1bb770, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1bb770));
    void* x = 0;
    if (m) {
        ((Raw_1bb770*)m)->FUN_001b9f90(a1, a3);
        x = new (m) Closure4_1bb770<CRenderManager_1bb770, unsigned int, const char*, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001bb7d0 FUN_001bb7d0 (83 B): equivalent/0x001bb7d0.cpp
// sym: ?FUN_001bb7d0@Registry_1bb7d0@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb7d0@2@P832@AEI0VVector_1bb7d0@math@@2M@Z@Z @2287d82bd815 @wc87d3d62ebac
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001bb7d0 @ 0x001bb7d0
// FUN_001bb7d0 @ 0x001bb7d0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1bb7d0::FUN_001bb7d0(const char* a1, CRenderManager_1bb7d0* a2, Fn_1bb7d0 a3) {
    typedef Closure4_1bb7d0<CRenderManager_1bb7d0, unsigned int, const char*, math::Vector_1bb7d0, math::Vector_1bb7d0, float> Alloc_1bb7d0;
    HULK_SIZE32(Alloc_1bb7d0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1bb7d0));
    void* x = 0;
    if (m) {
        ((Raw_1bb7d0*)m)->FUN_001ba090(a1, a3);
        x = new (m) Closure4_1bb7d0<CRenderManager_1bb7d0, unsigned int, const char*, math::Vector_1bb7d0, math::Vector_1bb7d0, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_ff10b020

// 0x001bb880 FUN_001bb880 (109 B): equivalent/0x001bb880.cpp [wrapped: conflict: CRenderManager; Closure0; DAT_0048e10c; Method0]
// sym: ?FUN_001bb880@Registry_1bb880@fn_001bb880@@QAEXPBDPAVCRenderManager@2@P832@AE?AVVector@math@2@XZ@Z @5c3697fb9fee @wf5d6c74ba2e6
namespace fn_001bb880 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001bb880 @ 0x001bb880
// FUN_001bb880 @ 0x001bb880  (generated by work/closure/gen.py)
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
extern "C++" { extern const char DAT_0048e10c[]; }


class CRenderManager { public: float FUN_dummy(); };
namespace math {
class Vector { public: float FUN_dummy(); };
}

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1bb880 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1bb880(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1bb880 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1bb880(name, 0) {
        fn = f;
        retType = FUN_001d04d0(DAT_0048e10c);
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1bb880 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001bb880(const char* name, CRenderManager* owner, math::Vector (CRenderManager::*fn)());
};

void Registry_1bb880::FUN_001bb880(const char* name, CRenderManager* owner, math::Vector (CRenderManager::*fn)()) {
    typedef Closure0<CRenderManager, math::Vector> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CRenderManager, math::Vector>));
    Closure0<CRenderManager, math::Vector>* c = 0;
    if (mem)
        c = new (mem) Closure0<CRenderManager, math::Vector>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001bb880
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bb990 FUN_001bb990 (1676 B): equivalent/0x001bb990.cpp [wrapped: conflict: CRenderManager; Closure1; Closure3; Closure4 (+6)]
// sym: ??0CRenderManager@fn_001bb990@@QAE@XZ @ea2fcbb88dc9 @w84a4ea37ad9d
namespace fn_001bb990 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 36/36)
// FUN_001bb990 @ 0x001bb990
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

namespace math {
class Vector {
  public:
    float x, y, z;
};
}

class CRenderManager;
class ControlObj {
  public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(int tag, int flag);
};
class Shader_1bb990 {
  public:
    Shader_1bb990* FUN_0028edb0();
    virtual void vfn0();
    char pad[0x10 - 4];
    ControlObj* control;
    char pad2[0x20 - 0x14];
};

extern "C" void* FUN_0008d690(unsigned size);
void* FUN_00263ea0(unsigned size);


template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void* get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<float> { static const void* get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<unsigned int> { static const void* get() { return ((char*)&DAT_0049b95c); } };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1bb990 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_1bb990() {}
    MethodBase_1bb990(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_1bb990 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) : MethodBase_1bb990(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char* name, T* o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T* owner;
};

// Methods whose base constructors are out of line.
template <class T, class R, class A, class B, class C>
class __declspec(novtable) Method3 : public MethodBase_1bb990 {
  public:
    typedef R (T::*Fn)(A, B, C);
    Method3(const char* name, Fn f) : MethodBase_1bb990() { FUN_001b9c50(name, f); }
    void FUN_001b9c50(const char* name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Closure3 : public Method3<T, R, A, B, C> {
  public:
    Closure3(const char* name, T* o, typename Method3<T, R, A, B, C>::Fn f) : Method3<T, R, A, B, C>(name, f), owner(o) {}
    T* owner;
};

template <class T, class R, class A, class B, class C, class D, class E, class F>
class __declspec(novtable) Method6 : public MethodBase_1bb990 {
  public:
    typedef R (T::*Fn)(A, B, C, D, E, F);
    Method6(const char* name, Fn f) : MethodBase_1bb990() { FUN_001b9d80(name, f); }
    void FUN_001b9d80(const char* name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D, class E, class F>
class Closure6 : public Method6<T, R, A, B, C, D, E, F> {
  public:
    Closure6(const char* name, T* o, typename Method6<T, R, A, B, C, D, E, F>::Fn f)
        : Method6<T, R, A, B, C, D, E, F>(name, f), owner(o) {}
    T* owner;
};

template <class T, class R, class A, class B, class C, class D>
class Method4;

class CRenderManager {
  public:
    CRenderManager();
    virtual void* vfn0_001bc020(char);

    void FUN_001b8770(bool);
    void FUN_001b8780(bool);
    void FUN_001b8900(bool);
    void FUN_001b9ab0(int, int, int);
    void FUN_001b9b40(int, int, int);
    void FUN_001b87d0(int, int, int);
    void FUN_001b87f0(int, int, int);
    void FUN_001b88c0(float, float);
    void FUN_001b98e0(float, float, float, float, float, float);
    void FUN_001b8ab0();
    bool FUN_001b8b30();
    unsigned int FUN_001b8e40(const char*, float, float, float);
    unsigned int FUN_001b8dc0(const char*, math::Vector, math::Vector, float);
    void FUN_001b8ec0(unsigned int);
    void FUN_001b9020();
    void FUN_001b90b0();
    bool FUN_001b9120();
    bool FUN_001b88f0();
    void FUN_001b9130(float);
    void FUN_001b9160(float);
    void FUN_001b9180(float);
    void FUN_001b91b0(float);
    void FUN_001b91d0(math::Vector*);
    void FUN_001b9200(math::Vector*);
    void FUN_001b9230(math::Vector*);
    void FUN_001b9260(math::Vector*);
    void FUN_001b9290(int);

    void* f4;                   // the view 0x001b8690 creates
    int f8, fc;
    float f10, f14;
    char f18;
    char pad19[3];
    int f1c, f20, f24, f28;
    Shader_1bb990* overlay;     // 0x2c
    char flags30[4];
    int f34, f38, f3c;
    int f40, f44, f48, f4c;
    float f50;
    int f54, f58, f5c, f60;
};
HULK_MGR_SAME(CRenderManager, HulkRenderManager);   // (x64t9-mgr) include/decls/managers.h

template <>
class __declspec(novtable) Method4<CRenderManager, unsigned int, const char*, float, float, float> : public MethodBase_1bb990 {
  public:
    typedef unsigned int (CRenderManager::*Fn)(const char*, float, float, float);
    Method4(const char* name, Fn f) : MethodBase_1bb990() { FUN_001b9f90(name, f); }
    void FUN_001b9f90(const char* name, Fn f);
    Fn fn;
};

template <>
class __declspec(novtable) Method4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float> : public MethodBase_1bb990 {
  public:
    typedef unsigned int (CRenderManager::*Fn)(const char*, math::Vector, math::Vector, float);
    Method4(const char* name, Fn f) : MethodBase_1bb990() { FUN_001ba090(name, f); }
    void FUN_001ba090(const char* name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D>
class Closure4 : public Method4<T, R, A, B, C, D> {
  public:
    Closure4(const char* name, T* o, typename Method4<T, R, A, B, C, D>::Fn f) : Method4<T, R, A, B, C, D>(name, f), owner(o) {}
    T* owner;
};

// Closure2 / Closure1 built by their out-of-line initializers (matches/0x001ba510.cpp, 0x001ba980.cpp): allocated as
// ScriptClosureView.
struct Closure2_1bb990 {
    Closure2_1bb990* FUN_001ba510(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(float, float));
};
struct ClosureShaderLight {
    ClosureShaderLight* FUN_001ba980(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(int));
};

struct Registry_1bb990 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_001bb690(const char* name, CRenderManager* owner, void (CRenderManager::*fn)());
    void FUN_001bb700(const char* name, CRenderManager* owner, bool (CRenderManager::*fn)());
    void FUN_001bb880(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(math::Vector*));
};
extern "C" Registry_1bb990* FUN_001d4c90();
void FUN_001c3d90();

CRenderManager::CRenderManager()
{
    f34 = 0xff;
    f38 = 0xff;
    f3c = 0xff;
    f4 = 0;
    f8 = 0;
    fc = 0;
    f10 = 1.0f;
    f14 = 1.0f;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f28 = 0;
    overlay = 0;
    flags30[0] = 0;
    flags30[1] = 0;
    flags30[2] = 0;
    flags30[3] = 0;
    f40 = 0x80;
    f44 = 0x80;
    f48 = 0x80;
    f4c = 0;
    f50 = 1.0f;
    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;

    Registry_1bb990* reg = FUN_001d4c90();
    typedef Closure1<CRenderManager, void, bool> Closure_0;
    HULK_SIZE32(Closure_0, 0x24);
    typedef Closure3<CRenderManager, void, int, int, int> Closure_1;
    HULK_SIZE32(Closure_1, 0x24);
    typedef Closure6<CRenderManager, void, float, float, float, float, float, float> Closure_2;
    HULK_SIZE32(Closure_2, 0x24);
    typedef Closure4<CRenderManager, unsigned int, const char*, float, float, float> Closure_3;
    HULK_SIZE32(Closure_3, 0x24);
    typedef Closure4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float> Closure_4;
    HULK_SIZE32(Closure_4, 0x24);
    typedef Closure1<CRenderManager, void, unsigned int> Closure_5;
    HULK_SIZE32(Closure_5, 0x24);
    typedef Closure1<CRenderManager, void, float> Closure_6;
    HULK_SIZE32(Closure_6, 0x24);
    HULK_SIZE32(ScriptClosureView, 0x24);
    void* mem;

    mem = FUN_0008d690((int)sizeof(Closure_0));
    Closure1<CRenderManager, void, bool>* enableFog = 0;
    if (mem)
        enableFog = new (mem) Closure1<CRenderManager, void, bool>("rm_EnableFog", this, &CRenderManager::FUN_001b8770);
    reg->FUN_001d3b70("rm_EnableFog", enableFog);

    mem = FUN_0008d690((int)sizeof(Closure_1));
    Closure3<CRenderManager, void, int, int, int>* fogColour = 0;
    if (mem)
        fogColour = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetFogColour", this, &CRenderManager::FUN_001b9ab0);
    reg->FUN_001d3b70("rm_SetFogColour", fogColour);

    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    Closure2_1bb990* fogPlanes = 0;
    if (mem)
        fogPlanes = ((Closure2_1bb990*)mem)->FUN_001ba510("rm_SetFogPlanes", this, &CRenderManager::FUN_001b88c0);
    reg->FUN_001d3b70("rm_SetFogPlanes", fogPlanes);

    mem = FUN_0008d690((int)sizeof(Closure_1));
    Closure3<CRenderManager, void, int, int, int>* shadowColour = 0;
    if (mem)
        shadowColour = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetShadowColour", this, &CRenderManager::FUN_001b9b40);
    reg->FUN_001d3b70("rm_SetShadowColour", shadowColour);

    mem = FUN_0008d690((int)sizeof(Closure_0));
    Closure1<CRenderManager, void, bool>* enableBloom = 0;
    if (mem)
        enableBloom = new (mem) Closure1<CRenderManager, void, bool>("rm_EnableBloom", this, &CRenderManager::FUN_001b8780);
    reg->FUN_001d3b70("rm_EnableBloom", enableBloom);

    mem = FUN_0008d690((int)sizeof(Closure_1));
    Closure3<CRenderManager, void, int, int, int>* bloomColour = 0;
    if (mem)
        bloomColour = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetBloomColour", this, &CRenderManager::FUN_001b87d0);
    reg->FUN_001d3b70("rm_SetBloomColour", bloomColour);

    mem = FUN_0008d690((int)sizeof(Closure_1));
    Closure3<CRenderManager, void, int, int, int>* bloomWeights = 0;
    if (mem)
        bloomWeights = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetBloomWeights", this, &CRenderManager::FUN_001b87f0);
    reg->FUN_001d3b70("rm_SetBloomWeights", bloomWeights);

    mem = FUN_0008d690((int)sizeof(Closure_2));
    Closure6<CRenderManager, void, float, float, float, float, float, float>* bloomParams = 0;
    if (mem)
        bloomParams = new (mem) Closure6<CRenderManager, void, float, float, float, float, float, float>("rm_SetBloomParameters", this, &CRenderManager::FUN_001b98e0);
    reg->FUN_001d3b70("rm_SetBloomParameters", bloomParams);

    reg->FUN_001bb690("rm_DoCredits", this, &CRenderManager::FUN_001b8ab0);
    reg->FUN_001bb700("rm_IsCredits", this, &CRenderManager::FUN_001b8b30);

    mem = FUN_0008d690((int)sizeof(Closure_3));
    Closure4<CRenderManager, unsigned int, const char*, float, float, float>* addEffect = 0;
    if (mem)
        addEffect = new (mem) Closure4<CRenderManager, unsigned int, const char*, float, float, float>("rm_AddAnEffect", this, &CRenderManager::FUN_001b8e40);
    reg->FUN_001d3b70("rm_AddAnEffect", addEffect);

    mem = FUN_0008d690((int)sizeof(Closure_4));
    Closure4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float>* addEffectEx = 0;
    if (mem)
        addEffectEx = new (mem) Closure4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float>("rm_AddAnEffectEx", this, &CRenderManager::FUN_001b8dc0);
    reg->FUN_001d3b70("rm_AddAnEffectEx", addEffectEx);

    mem = FUN_0008d690((int)sizeof(Closure_5));
    Closure1<CRenderManager, void, unsigned int>* removeEffect = 0;
    if (mem)
        removeEffect = new (mem) Closure1<CRenderManager, void, unsigned int>("rm_RemoveAnEffect", this, &CRenderManager::FUN_001b8ec0);
    reg->FUN_001d3b70("rm_RemoveAnEffect", removeEffect);

    reg->FUN_001bb880("rm_GetCameraRight", this, &CRenderManager::FUN_001b91d0);
    reg->FUN_001bb880("rm_GetCameraUp", this, &CRenderManager::FUN_001b9200);
    reg->FUN_001bb880("rm_GetCameraHeading", this, &CRenderManager::FUN_001b9230);
    reg->FUN_001bb880("rm_GetCameraPosition", this, &CRenderManager::FUN_001b9260);

    mem = FUN_0008d690((int)sizeof(ScriptClosureView));
    ClosureShaderLight* shaderLight = 0;
    if (mem)
        shaderLight = ((ClosureShaderLight*)mem)->FUN_001ba980("rm_SetBuildingShaderLight", this, &CRenderManager::FUN_001b9290);
    reg->FUN_001d3b70("rm_SetBuildingShaderLight", shaderLight);

    reg->FUN_001bb700("rm_GetDrawEffectsWithWorld", this, &CRenderManager::FUN_001b88f0);

    mem = FUN_0008d690((int)sizeof(Closure_0));
    Closure1<CRenderManager, void, bool>* drawEffects = 0;
    if (mem)
        drawEffects = new (mem) Closure1<CRenderManager, void, bool>("rm_SetDrawEffectsWithWorld", this, &CRenderManager::FUN_001b8900);
    reg->FUN_001d3b70("rm_SetDrawEffectsWithWorld", drawEffects);

    reg->FUN_001bb690("nism_LetterBoxOn", this, &CRenderManager::FUN_001b9020);
    reg->FUN_001bb690("nism_LetterBoxOff", this, &CRenderManager::FUN_001b90b0);

    mem = FUN_0008d690((int)sizeof(Closure_6));
    Closure1<CRenderManager, void, float>* fadeToBlack = 0;
    if (mem)
        fadeToBlack = new (mem) Closure1<CRenderManager, void, float>("nism_FadeToBlack", this, &CRenderManager::FUN_001b9130);
    reg->FUN_001d3b70("nism_FadeToBlack", fadeToBlack);

    mem = FUN_0008d690((int)sizeof(Closure_6));
    Closure1<CRenderManager, void, float>* fadeFromBlack = 0;
    if (mem)
        fadeFromBlack = new (mem) Closure1<CRenderManager, void, float>("nism_FadeFromBlack", this, &CRenderManager::FUN_001b9160);
    reg->FUN_001d3b70("nism_FadeFromBlack", fadeFromBlack);

    mem = FUN_0008d690((int)sizeof(Closure_6));
    Closure1<CRenderManager, void, float>* fadeToWhite = 0;
    if (mem)
        fadeToWhite = new (mem) Closure1<CRenderManager, void, float>("nism_FadeToWhite", this, &CRenderManager::FUN_001b9180);
    reg->FUN_001d3b70("nism_FadeToWhite", fadeToWhite);

    mem = FUN_0008d690((int)sizeof(Closure_6));
    Closure1<CRenderManager, void, float>* fadeFromWhite = 0;
    if (mem)
        fadeFromWhite = new (mem) Closure1<CRenderManager, void, float>("nism_FadeFromWhite", this, &CRenderManager::FUN_001b91b0);
    reg->FUN_001d3b70("nism_FadeFromWhite", fadeFromWhite);

    reg->FUN_001bb700("nism_IsLetterBoxOn", this, &CRenderManager::FUN_001b9120);

    FUN_001c3d90();

    Shader_1bb990* ov = (Shader_1bb990*)FUN_00263ea0(0x20);
    if (ov)
        ov = ov->FUN_0028edb0();
    overlay = ov;
    ov->vfn0();
    overlay->control->vfn6(0x444d4c42, 1);
}
} // namespace fn_001bb990
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bc020 CRenderManager::vfunc_0 (31 B): matches/0x001bc020.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001bc020@@UAEPAV123@E@Z
namespace fn_001bc020 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CDHGameObjectCreator_1bc020 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003feefc[];
namespace pure3d {
class NonCopyable : public CDHGameObjectCreator_1bc020 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003feefc;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001bc020

