// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b8690..0x001bc0c0 (kind game, layer game, confidence high), dominant class CRenderManager
#include "tree_prelude.h"
#include "decls/shader.h"   // (allocsize1)
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
#include "decls/view.h"   // (recs1) pure3d::View
#include "game/script_bind.h"

// ---- declarations shared by the functions below
namespace fn_ff10b020 {
struct View_nv_1b8690 {
    pure3d::View *FUN_00294880();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)
// (recs1) CRenderManager on its record (decls/managers.h; was `int pad0; View* child; int v[4]`)
class Owner_1b8690 : public HulkRenderManager {
public:
    void FUN_001b8690();
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
    void Fn_001c1780(unsigned char);   // (script2) as defined (HulkShaderCallback.cpp)
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
    void Init_0027b0e0(const char* name);
    void Done_0027af50();
};
struct M_1b8dc0 {
    char d[64];
    void Ident_0022b980();
    void Set3_0022bc20(int a, int b, int c);
};
struct S_1b8dc0 {
    unsigned int Run_00283a40(C_1b8dc0* c, M_1b8dc0* m, float f, float a);   // (script2) as defined (CMotionTrail.cpp): a handle
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
    unsigned int FUN_00283a40(Id64_1b8e40* id, Matrix* mat, float a, float b);   // (script2) returns a handle, as defined (CMotionTrail.cpp)
};
Spawner_1b8e40* FUN_0027f250();
struct Vec3_1b8ee0 { float x,y,z; };
struct Reader_1b8ee0 { const char* FUN_003365b0(const char*); void FUN_00336600(const char*,float*,float*,float*); };
struct CRenderManager_nv_1b8ee0 {
    unsigned int FUN_001b8dc0(const char*,Vec3_1b8ee0,Vec3_1b8ee0,float);   // (script2) as defined
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
// sym: ?FUN_001b8690@Owner_1b8690@fn_ff10b020@@QAEXXZ @149975c5bb74 @wadf3177de501 @v605a1710b9be
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001b8690 @ 0x001b8690
void Owner_1b8690::FUN_001b8690()
{
    pure3d::View *c = (pure3d::View *)FUN_0008d690(sizeof(HulkView));   // (recs1) the View record (0x140 on the 32-bit builds)
    if (c)
        c = ((View_nv_1b8690*)(c))->FUN_00294880();
    view = c;
    c->vfunc_0();
    ((owners::A_293e40 *)view)->FUN_00293e40(f8, fc, *(int*)&f10, *(int*)&f14);
    ((HulkView *)view)->clearColour = 0xff000000;
    ((HulkView *)view)->clearMask = 0xffffffff;
    ((owners::C_293e90 *)view)->FUN_00293e90(0xff000000);
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
// sym: ?FUN_001b8770@CB_001b8770@fn_ff10b020@@QAEX_N@Z
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void __stdcall FUN_001b8770(int a)`
struct CB_001b8770 { void FUN_001b8770(bool); };
void CB_001b8770::FUN_001b8770(bool a) {
    R_1b8770* r = (R_1b8770*)FUN_001c3d90();
    r->p->Fn_001c1780(a);
}


// 0x001b8780 FUN_001b8780 (72 B): matches/0x001b8780.cpp
// sym: ?FUN_001b8780@CB_001b8780@fn_ff10b020@@QAEX_N@Z
// (script2) bound as CRenderManager's member (Closure1<CRenderManager,void,bool>): `this` is the object; was
// `void __fastcall target(Obj_1b8780* self, int, unsigned char value)`
struct CB_001b8780 { void FUN_001b8780(bool); };
void CB_001b8780::FUN_001b8780(bool value) {
    Obj_1b8780* self = (Obj_1b8780*)this;
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
// sym: ?FUN_001b88c0@CB_001b88c0@fn_ff10b020@@QAEXMM@Z
// data: zero = DAT_003f32e0
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void __stdcall FUN(float a, float b)`
struct CB_001b88c0 { void FUN_001b88c0(float, float); };
void CB_001b88c0::FUN_001b88c0(float a, float b) {
    if (a <= (*(float*)&DAT_003f32e0) || b <= a)
        return;
    Holder* h = get_001c3d90();
    h->p->run_001c17a0(a, b);
}

} // namespace fn_ff10b020

// 0x001b88f0 FUN_001b88f0 (12 B): matches/0x001b88f0.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b88f0@CB_001b88f0@fn_001b88f0@@QAE_NXZ
namespace fn_001b88f0 {
class Obj_1b88f0 {
  public:
    bool Init_001c3c90();
};
Obj_1b88f0* __cdecl FUN_001c3d90();
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void __cdecl FUN_001b88f0()`
struct CB_001b88f0 { bool FUN_001b88f0(); };
bool CB_001b88f0::FUN_001b88f0() {
    return FUN_001c3d90()->Init_001c3c90();
}
} // namespace fn_001b88f0


// 0x001b8900 FUN_001b8900 (20 B): matches/0x001b8900.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b8900@CB_001b8900@fn_001b8900@@QAEX_N@Z
namespace fn_001b8900 {
// FUN_001c3d90 is the 0-argument singleton getter; param_1 is the method's argument.
typedef unsigned int u32_1b8900;
struct Registry_1b8900 {
    void FUN_001c3ca0(unsigned char);   // (script2) as defined (HulkShaderCallback.cpp)
};
Registry_1b8900* FUN_001c3d90();
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void __stdcall target(u32_1b8900 value)`
struct CB_001b8900 { void FUN_001b8900(bool); };
void CB_001b8900::FUN_001b8900(bool value) {
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
// sym: _FUN_001b8b60 @b74bab14b354 @w27610237eb67 @vbda345c3b253
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
// sym: ?FUN_001b8dc0@CB_001b8dc0@fn_ff10b020@@QAEIPBDUB_1b8dc0@2@UC_1b8dc0@2@M@Z
// (script2) bound as CRenderManager's member (Closure4<CRenderManager,unsigned int,const char*,math::Vector,math::Vector,
// float>; this unused) and called as one by 0x001b8ee0; was `int __stdcall Fn(int a1, B_1b8dc0 b, C_1b8dc0 c, int a8)`
struct CB_001b8dc0 { unsigned int FUN_001b8dc0(const char*, B_1b8dc0, C_1b8dc0, float); };
unsigned int CB_001b8dc0::FUN_001b8dc0(const char* a1, B_1b8dc0 b, C_1b8dc0 c, float a8) {
    S_1b8dc0* s = GetS_0027f250();
    M_1b8dc0 m;
    m.Ident_0022b980();
    ((owners::Target_22be40 *)&m)->FUN_0022be40((const int *)(B_1b8dc0 *)(&b));
    m.Set3_0022bc20(c.x, c.y, c.z);
    c.Init_0027b0e0(a1);
    unsigned int r = s->Run_00283a40(&c, &m, -1.0f, a8);
    c.Done_0027af50();
    return r;
}


// 0x001b8e40 FUN_001b8e40 (119 B): matches/0x001b8e40.cpp
// sym: ?FUN_001b8e40@CB_001b8e40@fn_ff10b020@@QAEIPBDMMM@Z
// FUN_001b8e40 @ 0x001b8e40
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `Spawned* __stdcall FUN_001b8e40(const char* name, float x, float y, float z)`
struct CB_001b8e40 { unsigned int FUN_001b8e40(const char*, float, float, float); };
unsigned int CB_001b8e40::FUN_001b8e40(const char* name, float x, float y, float z) {
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
    unsigned int result = spawner->FUN_00283a40(&u.id, &mat, -1.0f, 1.0f);
    u.id.FUN_0027af50();
    return result;
}

} // namespace fn_ff10b020

// 0x001b8ec0 FUN_001b8ec0 (20 B): matches/0x001b8ec0.cpp [wrapped: conflict: FUN_0027f250]
// sym: ?FUN_001b8ec0@CB_001b8ec0@fn_001b8ec0@@QAEXI@Z
namespace fn_001b8ec0 {
void* FUN_0027f250();
struct Helper_1b8ec0 {
    void* Run_0027ffb0(void*);
};
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void* __stdcall FUN_001b8ec0(void* arg)`
struct CB_001b8ec0 { void FUN_001b8ec0(unsigned int); };
void CB_001b8ec0::FUN_001b8ec0(unsigned int arg) {
    ((Helper_1b8ec0*)FUN_0027f250())->Run_0027ffb0((void*)(hulk_uintptr)arg);
}
} // namespace fn_001b8ec0


// 0x001b8ee0 CRenderManager::vfunc_1 (271 B): equivalent/0x001b8ee0.cpp
// sym: ?vfunc_1@CRenderManager@@UAE_NPAX@Z @f13e26109544 @wb4f2ca012a3c @v130d18b845cc
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
// sym: ?FUN_001b9120@CB_001b9120@fn_001b9120@@QAE_NXZ
namespace fn_001b9120 {
class Obj_1b9120 {
  public:
    void Run();
};
Obj_1b9120* __fastcall FUN_001c3d90();
int __fastcall FUN_001c3cb0(Obj_1b9120*);   // (script2) as defined (HulkShaderCallback.cpp)
// (script2) bound as CRenderManager's member (Closure0<CRenderManager,bool>; this unused); was `void FUN_001b9120()`
struct CB_001b9120 { bool FUN_001b9120(); };
bool CB_001b9120::FUN_001b9120() {
    return *(bool*)&(const int&)FUN_001c3cb0(FUN_001c3d90());   // the low byte (al), as the game returns it
}
} // namespace fn_001b9120


// 0x001b9130 FUN_001b9130 (33 B): matches/0x001b9130.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b9130@CB_001b9130@fn_001b9130@@QAEXM@Z
namespace fn_001b9130 {
// FUN_001c3d90 is the 0-argument singleton getter; the six pushed values are arguments of FUN_001c37a0 (ret 0x18).
struct Registry_1b9130 {
    void FUN_001c37a0(float, int, int, int, int, int);
};
Registry_1b9130* FUN_001c3d90();
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void __stdcall FUN_001b9130(int value)`
struct CB_001b9130 { void FUN_001b9130(float); };
void CB_001b9130::FUN_001b9130(float value) {
    FUN_001c3d90()->FUN_001c37a0(1.0f, 0, 0, 1, *(int*)&value, 0);
}
} // namespace fn_001b9130


// 0x001b9160 FUN_001b9160 (26 B): matches/0x001b9160.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b9160@CB_001b9160@fn_001b9160@@QAEXM@Z
namespace fn_001b9160 {
// FUN_001c3d90 is the 0-argument singleton getter; the four pushed values are arguments of FUN_001c37f0.
struct Registry_1b9160 {
    void FUN_001c37f0(int a, int b, int c, int d);
};
Registry_1b9160* FUN_001c3d90();
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void __stdcall FUN_001b9160(int value)`
struct CB_001b9160 { void FUN_001b9160(float); };
void CB_001b9160::FUN_001b9160(float value) {
    FUN_001c3d90()->FUN_001c37f0(0, 0, 1, *(int*)&value);
}
} // namespace fn_001b9160


// 0x001b9180 FUN_001b9180 (33 B): matches/0x001b9180.cpp [wrapped: conflict: Make]
// sym: ?FUN_001b9180@CB_001b9180@fn_001b9180@@QAEXM@Z
namespace fn_001b9180 {
class Obj {
  public:
    void Init_001c37a0(float, int, int, int, void*, int);
};
extern "C++" __declspec(nothrow) Obj* __stdcall Make_001c3d90();
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `extern "C" void __stdcall FUN_001b9180(void* p)`
struct CB_001b9180 { void FUN_001b9180(float); };
void CB_001b9180::FUN_001b9180(float p) {
    Make_001c3d90()->Init_001c37a0(1.0f, 0, 0, 1, *(void**)&p, 1);
}
} // namespace fn_001b9180

namespace fn_ff10b020 {

// 0x001b91b0 FUN_001b91b0 (26 B): matches/0x001b91b0.cpp
// sym: ?FUN_001b91b0@CB_001b91b0@fn_ff10b020@@QAEXM@Z
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `void __stdcall FUN_001b91b0(int x)`
struct CB_001b91b0 { void FUN_001b91b0(float); };
void CB_001b91b0::FUN_001b91b0(float x) {
    make_001c3d90()->run_001c37f0(0, 0, 1, *(int*)&x);
}


// 0x001b91d0 FUN_001b91d0 (41 B): matches/0x001b91d0.cpp
// sym: ?FUN_001b91d0@CB_001b91d0@fn_ff10b020@@QAE?AUV@2@XZ
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `V* __stdcall FUN(V* out)`
struct CB_001b91d0 { V FUN_001b91d0(); };
V CB_001b91d0::FUN_001b91d0() {
    return *fetch_001c3d90()->get_001c39a0();
}

} // namespace fn_ff10b020

// 0x001b9200 FUN_001b9200 (41 B): matches/0x001b9200.cpp [wrapped: conflict: FUN_001c3d90; target]
// sym: ?FUN_001b9200@CB_001b9200@fn_001b9200@@QAE?AUV@2@XZ
namespace fn_001b9200 {
struct V {
    int a, b, c;
};
class A {
  public:
    V* Get_001c39b0();
};
A* __cdecl FUN_001c3d90();
// (script2) bound as CRenderManager's member (Closure0<CRenderManager,math::Vector>; this unused); was `V __stdcall target()`
struct CB_001b9200 { V FUN_001b9200(); };
V CB_001b9200::FUN_001b9200() {
    return *FUN_001c3d90()->Get_001c39b0();
}
} // namespace fn_001b9200


// 0x001b9230 FUN_001b9230 (41 B): matches/0x001b9230.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001b9230@CB_001b9230@fn_001b9230@@QAE?AUVec@2@XZ
namespace fn_001b9230 {
struct Vec {
    int a, b, c;
};
class Obj {
  public:
    Vec* get_001c39c0();
};
Obj* FUN_001c3d90();
// (script2) bound as CRenderManager's member (Closure0<CRenderManager,math::Vector>; this unused); was `Vec __stdcall target()`
struct CB_001b9230 { Vec FUN_001b9230(); };
Vec CB_001b9230::FUN_001b9230() {
    Obj* o = FUN_001c3d90();
    return *o->get_001c39c0();
}
} // namespace fn_001b9230

namespace fn_ff10b020 {

// 0x001b9260 FUN_001b9260 (41 B): matches/0x001b9260.cpp
// sym: ?FUN_001b9260@CB_001b9260@fn_ff10b020@@QAE?AUVec@2@XZ
// (script2) bound as CRenderManager's member (Closure0<CRenderManager,math::Vector>; this unused); was `Vec __stdcall target()`
struct CB_001b9260 { Vec FUN_001b9260(); };
Vec CB_001b9260::FUN_001b9260() {
    A* a = findA_001c3d90();
    return *((Vec *)((owners::Object_1c39d0 *)a)->FUN_001c39d0());
}


// 0x001b9290 FUN_001b9290 (34 B): matches/0x001b9290.cpp
// sym: ?FUN_001b9290@CB_001b9290@fn_ff10b020@@QAEXHM@Z
// (script2) bound as CRenderManager's member (Closure2<CRenderManager,void,int,float>; this unused); was
// `void __stdcall FUN(hulk_intptr key, int v)`
struct CB_001b9290 { void FUN_001b9290(int, float); };
void CB_001b9290::FUN_001b9290(int key, float v) {
    Root* root = GetRoot_001c3d90();
    Manager* mgr = root->manager;
    Obj* o = mgr->Find_001c7f10(key);
    if (o)
        o->value = *(int*)&v;
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
    void* vftable; void* parts[20];   /* (sweep2) the World's words (HulkWorld): +0x54 is CGame */
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
// sym: ?FUN_001b98e0@CRenderManager_1b98e0@fn_001b98e0@@QAEHMMMMMM@Z @fa6dce19354e @wbf2449e0adb4 @v51f45eb814c6
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
// sym: ?FUN_001b9ab0@CB_001b9ab0@fn_001b9ab0@@QAEXHHH@Z @f3218102b791 @w9aae9f679b58 @vaee2a7372d21
namespace fn_001b9ab0 {
// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 15/18, incomplete)
// FUN_001b9ab0 @ 0x001b9ab0
struct Sink_1b9ab0 {  };
struct Holder_1b9ab0 { Sink_1b9ab0* sink; };
Holder_1b9ab0* FUN_001c3d90();
static int Clamp255(int v) { return v < 0 ? 0 : (v > 255 ? 255 : v); }
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `int __stdcall SetColor(int r, int g, int b)`
struct CB_001b9ab0 { void FUN_001b9ab0(int, int, int); };
void CB_001b9ab0::FUN_001b9ab0(int r, int g, int b) {
    int cr = Clamp255(r);
    int cg = Clamp255(g);
    int cb = Clamp255(b);
    unsigned argb = (((0xffu << 8 | cr) << 8 | cg) << 8) | cb;
    ((owners::C_1c1790 *)(FUN_001c3d90()->sink))->FUN_001c1790((int)argb);
}
} // namespace fn_001b9ab0


// 0x001b9b40 FUN_001b9b40 (138 B): equivalent/0x001b9b40.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001b9b40@CB_001b9b40@fn_001b9b40@@QAEXHHH@Z @9bcaac472bd1 @w0fcd52672cb9 @vb398ebb06cfc
namespace fn_001b9b40 {
// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 15/18, incomplete)
// FUN_001b9b40 @ 0x001b9b40
struct Sink_1b9b40 {  };
struct Holder_1b9b40 { Sink_1b9b40* sink; };
Holder_1b9b40* FUN_001c3d90();
static int Clamp255(int v) { return v < 0 ? 0 : (v > 255 ? 255 : v); }
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `int __stdcall SetColor(int r, int g, int b)`
struct CB_001b9b40 { void FUN_001b9b40(int, int, int); };
void CB_001b9b40::FUN_001b9b40(int r, int g, int b) {
    int cr = Clamp255(r);
    int cg = Clamp255(g);
    int cb = Clamp255(b);
    unsigned argb = (((0xffu << 8 | cr) << 8 | cg) << 8) | cb;
    ((owners::C_1c17c0 *)(FUN_001c3d90()->sink))->FUN_001c17c0((int)argb);
}
} // namespace fn_001b9b40


// 0x001b9c10 Method1<CRenderManager,void,bool>::vfunc_0 (30 B): matches/0x001b9c10.cpp
// sym: ?vfunc_0@Method1_1b9c10@fn_001b9c10@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CRenderManager, void, bool>::~Method1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001b9c10 {
struct Method1_1b9c10 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1b9c10::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001b9c10
// (x64t21) the destructor itself, which other objects' code references:


// 0x001b9c30 Method1<CRenderManager,void,bool>::vfunc_2 (21 B): matches/0x001b9c30.cpp
// sym: ?vfunc_2@Method1_1b9c30@fn_001b9c30@@QAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CRenderManager, void, bool>::vfunc_2`.
namespace fn_001b9c30 {
struct Method1_1b9c30 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1b9c30::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9c30 * obj = (CActorManager_1b9c30 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1b9c30 *)&this->f_1c))(*b);
}
} // namespace fn_001b9c30

namespace fn_ff10b020 {

// 0x001b9c50 FUN_001b9c50 (89 B): matches/0x001b9c50.cpp
// sym: ??0Method3@fn_001b9c50@fn_ff10b020@@QAE@PBDP8Owner_1b9c50@12@AEXXZ@Z
namespace fn_001b9c50 {
// (script1) Method3<class CRenderManager,void,int,int,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00420e24[];   // Method3<class CRenderManager,void,int,int,int>
class Owner_1b9c50 {};
typedef void (Owner_1b9c50::*Fn_1b9c50)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_1b9c50 fn;
    Method3(const char* name, Fn_1b9c50 function);
};
Method3::Method3(const char* name, Fn_1b9c50 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_00420e24;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
}
} // namespace fn_001b9c50

} // namespace fn_ff10b020

// 0x001b9cb0 Method3<CRenderManager,void,int,int,int>::vfunc_0 (30 B): matches/0x001b9cb0.cpp
// sym: ?vfunc_0@Method3_1b9cb0@fn_001b9cb0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<CRenderManager, void, int, int, int>::~Method3() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001b9cb0 {
struct Method3_1b9cb0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_1b9cb0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001b9cb0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001b9cd0 Method3<CRenderManager,void,int,int,int>::vfunc_2 (29 B): equivalent/0x001b9cd0.cpp
// sym: ?vfunc_2@Method3_1b9cd0@fn_001b9cd0@@QAEXPAX00@Z @a7a6d240b96d @w2ac42a573389 @v4d6e276ac600
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CRenderManager,void,int,int,int>::vfunc_2 @ 0x001b9cd0
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CRenderManager, void, int, int, int>::vfunc_2`.
namespace fn_001b9cd0 {
struct Method3_1b9cd0 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(int, int, int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_1b9cd0::vfunc_2(void* __p0, void* __p1, void* __p2) { CRenderManager_1b9cd0 * object = (CRenderManager_1b9cd0 *)__p0; const int * args = (const int *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CRenderManager_1b9cd0::**)(int, int, int))&this->f_1c))(args[0], args[1], args[2]);
}
} // namespace fn_001b9cd0


// 0x001b9d40 Method2<CRenderManager,void,float,float>::vfunc_0 (30 B): matches/0x001b9d40.cpp
// sym: ?vfunc_0@Method2_1b9d40@fn_001b9d40@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CRenderManager, void, float, float>::~Method2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001b9d40 {
struct Method2_1b9d40 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1b9d40::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001b9d40
// (x64t21) the destructor itself, which other objects' code references:


// 0x001b9d60 Method2<CRenderManager,void,float,float>::vfunc_2 (23 B): matches/0x001b9d60.cpp
// sym: ?vfunc_2@Method2_1b9d60@fn_001b9d60@@QAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CRenderManager, void, float, float>::vfunc_2`.
namespace fn_001b9d60 {
struct Method2_1b9d60 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(float, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_1b9d60::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1b9d60* m = (CFEManager_1b9d60*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1b9d60::**)(const char *, int))&this->f_1c))(s, x);
}
} // namespace fn_001b9d60

namespace fn_ff10b020 {

// 0x001b9d80 FUN_001b9d80 (128 B): matches/0x001b9d80.cpp
// sym: ??0Method6@fn_001b9d80@fn_ff10b020@@QAE@PBDP8Owner_1b9d80@12@AEXXZ@Z
namespace fn_001b9d80 {
// (script1) Method6<class CRenderManager,void,float,float,float,float,float,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00420e44[];   // Method6<class CRenderManager,void,float,float,float,float,float,float>
class Owner_1b9d80 {};
typedef void (Owner_1b9d80::*Fn_1b9d80)();
struct Method6 : hulk_script::ScriptFunction {
    Fn_1b9d80 fn;
    Method6(const char* name, Fn_1b9d80 function);
};
Method6::Method6(const char* name, Fn_1b9d80 function) : hulk_script::ScriptFunction(name, 6) {
    vftable = DAT_00420e44;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[4] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[5] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
}
} // namespace fn_001b9d80

} // namespace fn_ff10b020

// 0x001b9e00 Method6<CRenderManager,void,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x001b9e00.cpp
// sym: ?vfunc_0@Method6_1b9e00@fn_001b9e00@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method6<CRenderManager, void, float, float, float, float, float,
// float>::~Method6() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001b9e00 {
struct Method6_1b9e00 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method6_1b9e00::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001b9e00
// (x64t21) the destructor itself, which other objects' code references:


// 0x001b9e20 Method6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 (30 B): matches/0x001b9e20.cpp
// sym: ?vfunc_2@Method6_1b9e20@fn_001b9e20@@QAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method6<CRenderManager, void, float, float, float, float, float, float>::vfunc_2`.
namespace fn_001b9e20 {
struct Method6_1b9e20 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(float, float, float, float, float, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method6_1b9e20::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001b9e40(a, b, c, (*(int *)&this->f_1c));
}
} // namespace fn_001b9e20

namespace fn_ff10b020 {

// 0x001b9e40 FUN_001b9e40 (82 B): equivalent/0x001b9e40.cpp
// sym: ?FUN_001b9e40@fn_ff10b020@@YAXPAXPBUValues@1@HP6AXHHHHHH@Z@Z @76081efbe4fb @w1f3f96e9dee0 @v397d2f4e1c0c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001b9e40 @ 0x001b9e40
void __cdecl FUN_001b9e40(void *context, const Values *values, int unused, Callback callback)
{
    callback(values->values[0], values->values[1], values->values[2], values->values[3], values->values[4], values->values[5]);
}

} // namespace fn_ff10b020

// 0x001b9ee0 Method0<CRenderManager,void>::vfunc_0 (30 B): matches/0x001b9ee0.cpp
// sym: ?vfunc_0@Method0_1b9ee0@fn_001b9ee0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CRenderManager, void>::~Method0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001b9ee0 {
struct Method0_1b9ee0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_1b9ee0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001b9ee0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001b9f00 Method0<CRenderManager,void>::vfunc_2 (12 B): matches/0x001b9f00.cpp
// sym: ?vfunc_2@Method0_1b9f00@fn_001b9f00@@QAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CRenderManager, void>::vfunc_2`.
namespace fn_001b9f00 {
struct Method0_1b9f00 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_1b9f00::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9f00 * a = (CActorManager_1b9f00 *)__p0;

    (a->*(*(void (CActorManager_1b9f00::**)())&this->f_1c))();
}
} // namespace fn_001b9f00


// 0x001b9f50 Method0<CRenderManager,bool>::vfunc_0 (30 B): matches/0x001b9f50.cpp
// sym: ?vfunc_0@Method0_1b9f50@fn_001b9f50@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CRenderManager, bool>::~Method0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001b9f50 {
struct Method0_1b9f50 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_1b9f50::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001b9f50
// (x64t21) the destructor itself, which other objects' code references:


// 0x001b9f70 Method0<CRenderManager,bool>::vfunc_2 (22 B): matches/0x001b9f70.cpp
// sym: ?vfunc_2@Method0_1b9f70@fn_001b9f70@@QAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CRenderManager, bool>::vfunc_2`.
namespace fn_001b9f70 {
struct Method0_1b9f70 : hulk_script::FunctionGenView {
    bool (::CRenderManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_1b9f70::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9f70 * obj = (CActorManager_1b9f70 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_1b9f70 fn = (*(Fn_1b9f70 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
} // namespace fn_001b9f70

namespace fn_ff10b020 {

// 0x001b9f90 FUN_001b9f90 (102 B): matches/0x001b9f90.cpp
// sym: ??0Method4@fn_001b9f90@fn_ff10b020@@QAE@PBDP8Owner_1b9f90@12@AEXXZ@Z
namespace fn_001b9f90 {
// (script1) Method4<class CRenderManager,unsigned int,const char *,float,float,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00420e74[];   // Method4<class CRenderManager,unsigned int,const char *,float,float,float>
class Owner_1b9f90 {};
typedef void (Owner_1b9f90::*Fn_1b9f90)();
struct Method4 : hulk_script::ScriptFunction {
    Fn_1b9f90 fn;
    Method4(const char* name, Fn_1b9f90 function);
};
Method4::Method4(const char* name, Fn_1b9f90 function) : hulk_script::ScriptFunction(name, 4) {
    vftable = DAT_00420e74;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0049b95c);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
}
} // namespace fn_001b9f90

} // namespace fn_ff10b020

// 0x001ba000 Method4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x001ba000.cpp
// sym: ?vfunc_0@Method4_1ba000@fn_001ba000@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method4<CRenderManager, unsigned int, const char *, float, float,
// float>::~Method4() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba000 {
struct Method4_1ba000 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method4_1ba000::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba000
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba020 Method4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_2 (30 B): matches/0x001ba020.cpp
// sym: ?vfunc_2@Method4_1ba020@fn_001ba020@@QAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method4<CRenderManager, unsigned int, const char *, float, float, float>::vfunc_2`.
namespace fn_001ba020 {
struct Method4_1ba020 : hulk_script::FunctionGenView {
    unsigned int (::CRenderManager::*f_1c)(const char *, float, float, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method4_1ba020::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001ba040(a, b, c, (*(int *)&this->f_1c));
}
} // namespace fn_001ba020


// 0x001ba040 FUN_001ba040 (70 B): equivalent/0x001ba040.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001ba040@fn_001ba040@@YAXPAUCaller@1@PAUArgs@1@PAHP821@AEHHHHH@Z@Z @369971183f67 @w490dced5be09 @vd8ef81ed6f8d
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
// sym: ??0Method4@fn_001ba090@fn_ff10b020@@QAE@PBDP8Owner_1ba090@12@AEXXZ@Z
namespace fn_001ba090 {
// (script1) Method4<class CRenderManager,unsigned int,const char *,class math::Vector,class math::Vector,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00420e84[];   // Method4<class CRenderManager,unsigned int,const char *,class math::Vector,class math::Vector,float>
class Owner_1ba090 {};
typedef void (Owner_1ba090::*Fn_1ba090)();
struct Method4 : hulk_script::ScriptFunction {
    Fn_1ba090 fn;
    Method4(const char* name, Fn_1ba090 function);
};
Method4::Method4(const char* name, Fn_1ba090 function) : hulk_script::ScriptFunction(name, 4) {
    vftable = DAT_00420e84;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0049b95c);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
}
} // namespace fn_001ba090

} // namespace fn_ff10b020

// 0x001ba100 Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_0 (30 B): matches/0x001ba100.cpp
// sym: ?vfunc_0@Method4_1ba100@fn_001ba100@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method4<CRenderManager, unsigned int, const char
// *,math::Vector,math::Vector, float>::~Method4() {}` stood for it, whose MSVC `??_G` matched only under /GX. The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba100 {
struct Method4_1ba100 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method4_1ba100::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba100


// 0x001ba120 Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 (110 B): equivalent/0x001ba120.cpp
// sym: ?vfunc_2@Method4_1ba120@fn_001ba120@@QAEXPAX00@Z @e1f85de89946 @w8e30c855c2fa @v0ad73bb6eaad
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001ba120
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method4<CRenderManager, unsigned int, const char *,math::Vector,math::Vector, float>::vfunc_2`.
namespace fn_001ba120 {
struct Method4_1ba120 : hulk_script::FunctionGenView {
    unsigned int (::CRenderManager::*f_1c)(const char *, math::Vector, math::Vector, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method4_1ba120::vfunc_2(void* __p0, void* __p1, void* __p2) { CRenderManager_1ba120 * obj = (CRenderManager_1ba120 *)__p0; Args_1ba120 * args = (Args_1ba120 *)__p1; unsigned int * out = (unsigned int *)__p2;

    CheckFn_1ba120 fn = (*(CheckFn_1ba120 *)&this->f_1c);
    unsigned r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
} // namespace fn_001ba120


// 0x001ba1d0 Method1<CRenderManager,void,unsigned_int>::vfunc_0 (30 B): matches/0x001ba1d0.cpp
// sym: ?vfunc_0@Method1_1ba1d0@fn_001ba1d0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CRenderManager, void, unsigned int>::~Method1() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba1d0 {
struct Method1_1ba1d0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1ba1d0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba1d0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba1f0 Method1<CRenderManager,void,unsigned_int>::vfunc_2 (19 B): matches/0x001ba1f0.cpp
// sym: ?vfunc_2@Method1_1ba1f0@fn_001ba1f0@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CRenderManager, void, unsigned int>::vfunc_2`.
namespace fn_001ba1f0 {
struct Method1_1ba1f0 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(unsigned int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1ba1f0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1ba1f0* d = (Dummy_1ba1f0*)a;
    (d->*(*(void (Dummy_1ba1f0::**)(void *))&this->f_1c))(*b);
}
} // namespace fn_001ba1f0


// 0x001ba250 Method0<CRenderManager,math::Vector>::vfunc_0 (30 B): matches/0x001ba250.cpp
// sym: ?vfunc_0@Vector_1ba250@fn_001ba250@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CRenderManager,math::Vector>::~Method0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba250 {
struct Vector_1ba250 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_1ba250::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba250
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba270 Method0<CRenderManager,math::Vector>::vfunc_2 (69 B): matches/0x001ba270.cpp
// sym: ?vfunc_2@Method0_1ba270@fn_001ba270@@QAEXPAX00@Z
// Same code shape as 0x0008a610 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CRenderManager,math::Vector>::vfunc_2`.
namespace fn_001ba270 {
struct Method0_1ba270 : hulk_script::FunctionGenView {
    math::Vector (::CRenderManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_1ba270::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_1ba270 * mgr = (CGameFlowManager_1ba270 *)__p0; Vector_1ba270 * out = (Vector_1ba270 *)__p2;

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
} // namespace fn_001ba270


// 0x001ba310 Method2<CRenderManager,void,int,float>::vfunc_0 (30 B): matches/0x001ba310.cpp
// sym: ?vfunc_0@Method2_1ba310@fn_001ba310@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CRenderManager, void, int, float>::~Method2() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba310 {
struct Method2_1ba310 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1ba310::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba310
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba330 Method2<CRenderManager,void,int,float>::vfunc_2 (23 B): matches/0x001ba330.cpp
// sym: ?vfunc_2@Method2_1ba330@fn_001ba330@@QAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CRenderManager, void, int, float>::vfunc_2`.
namespace fn_001ba330 {
struct Method2_1ba330 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(int, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_1ba330::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1ba330* m = (CFEManager_1ba330*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1ba330::**)(const char *, int))&this->f_1c))(s, x);
}
} // namespace fn_001ba330


// 0x001ba390 Method1<CRenderManager,void,float>::vfunc_0 (30 B): matches/0x001ba390.cpp
// sym: ?vfunc_0@Method1_1ba390@fn_001ba390@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CRenderManager, void, float>::~Method1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba390 {
struct Method1_1ba390 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1ba390::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba390
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba3b0 Method1<CRenderManager,void,float>::vfunc_2 (19 B): matches/0x001ba3b0.cpp
// sym: ?vfunc_2@Method1_1ba3b0@fn_001ba3b0@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CRenderManager, void, float>::vfunc_2`.
namespace fn_001ba3b0 {
struct Method1_1ba3b0 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1ba3b0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1ba3b0* d = (Dummy_1ba3b0*)a;
    (d->*(*(void (Dummy_1ba3b0::**)(void *))&this->f_1c))(*b);
}
} // namespace fn_001ba3b0


// 0x001ba410 FUN_001ba410 (76 B): matches/0x001ba410.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ba410@@QAE@PBDPAVOwner_1ba410@1@P821@AEXXZ@Z
namespace fn_001ba410 {
// (script1) Closure1<class CRenderManager,void,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00420e14[];   // Method1<class CRenderManager,void,bool>
extern "C" char DAT_00420ed4[];   // Closure1<class CRenderManager,void,bool>
class Owner_1ba410 {};
typedef void (Owner_1ba410::*Fn_1ba410)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ba410 fn;
    Owner_1ba410* owner;
    Closure1(const char* name, Owner_1ba410* object, Fn_1ba410 function);
};
Closure1::Closure1(const char* name, Owner_1ba410* object, Fn_1ba410 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00420e14;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_00420ed4;
    owner = object;
}
} // namespace fn_001ba410


// 0x001ba460 Closure1<CRenderManager,void,bool>::vfunc_0 (30 B): matches/0x001ba460.cpp
// sym: ?vfunc_0@Closure1_1ba460@fn_001ba460@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CRenderManager, void, bool>::~Closure1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba460 {
struct Closure1_1ba460 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ba460::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba460
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba480 Closure1<CRenderManager,void,bool>::vfunc_2 (20 B): matches/0x001ba480.cpp
// sym: ?vfunc_2@Closure1_1ba480@fn_001ba480@@QAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CRenderManager, void, bool>::vfunc_2`.
namespace fn_001ba480 {
struct Closure1_1ba480 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(bool);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_1ba480::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1ba480 * *)&this->f_20)->*(*(void (Actor_1ba480::**)(unsigned char))&this->f_1c))(*arg);
}
} // namespace fn_001ba480


// 0x001ba4d0 Closure3<CRenderManager,void,int,int,int>::vfunc_0 (30 B): matches/0x001ba4d0.cpp
// sym: ?vfunc_0@Closure3_1ba4d0@fn_001ba4d0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure3<CRenderManager, void, int, int,
// int>::~Closure3() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001ba4d0 {
struct Closure3_1ba4d0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure3_1ba4d0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba4d0


// 0x001ba510 FUN_001ba510 (89 B): matches/0x001ba510.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ba510@@QAE@PBDPAVOwner_1ba510@1@P821@AEXXZ@Z
namespace fn_001ba510 {
// (script1) Closure2<class CRenderManager,void,float,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00420e34[];   // Method2<class CRenderManager,void,float,float>
extern "C" char DAT_00420ef4[];   // Closure2<class CRenderManager,void,float,float>
class Owner_1ba510 {};
typedef void (Owner_1ba510::*Fn_1ba510)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ba510 fn;
    Owner_1ba510* owner;
    Closure2(const char* name, Owner_1ba510* object, Fn_1ba510 function);
};
Closure2::Closure2(const char* name, Owner_1ba510* object, Fn_1ba510 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00420e34;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_00420ef4;
    owner = object;
}
} // namespace fn_001ba510
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ba570 Closure2<CRenderManager,void,float,float>::vfunc_0 (30 B): matches/0x001ba570.cpp
// sym: ?vfunc_0@Closure2_1ba570@fn_001ba570@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CRenderManager, void, float, float>::~Closure2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba570 {
struct Closure2_1ba570 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_1ba570::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba570
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba590 Closure2<CRenderManager,void,float,float>::vfunc_2 (22 B): matches/0x001ba590.cpp
// sym: ?vfunc_2@Closure2_1ba590@fn_001ba590@@QAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CRenderManager, void, float, float>::vfunc_2`.
namespace fn_001ba590 {
struct Closure2_1ba590 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(float, float);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_1ba590::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ba590 * p = (Pair_1ba590 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ba590 * *)&this->f_20)->*(*(void (CActorManager_1ba590::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
} // namespace fn_001ba590


// 0x001ba5e0 Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x001ba5e0.cpp
// sym: ?vfunc_0@Closure6_1ba5e0@fn_001ba5e0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure6<CRenderManager, void, float, float, float, float, float,
// float>::~Closure6() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba5e0 {
struct Closure6_1ba5e0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure6_1ba5e0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba5e0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba600 Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 (85 B): equivalent/0x001ba600.cpp
// sym: ?vfunc_2@Closure6_1ba600@fn_001ba600@@QAEXPAX00@Z @d87f9086673d @wf22810fd6db9 @v0a1faee125f8
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 @ 0x001ba600
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure6<CRenderManager, void, float, float, float, float, float, float>::vfunc_2`.
namespace fn_001ba600 {
struct Closure6_1ba600 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(float, float, float, float, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure6_1ba600::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const float * arguments = (const float *)__p1; void * unused2 = (void *)__p2;

    ((*(CRenderManager_1ba600 * *)&this->f_20)->*(*(void (CRenderManager_1ba600::**)(float, float, float, float, float, float))&this->f_1c))(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}
} // namespace fn_001ba600


// 0x001ba6a0 Closure0<CRenderManager,void>::vfunc_0 (30 B): matches/0x001ba6a0.cpp
// sym: ?vfunc_0@Closure0_1ba6a0@fn_001ba6a0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CRenderManager, void>::~Closure0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba6a0 {
struct Closure0_1ba6a0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_1ba6a0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba6a0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba6c0 Closure0<CRenderManager,void>::vfunc_2 (11 B): matches/0x001ba6c0.cpp
// sym: ?vfunc_2@Closure0_1ba6c0@fn_001ba6c0@@QAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CRenderManager, void>::vfunc_2`.
namespace fn_001ba6c0 {
struct Closure0_1ba6c0 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_1ba6c0::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_1ba6c0 * *)&this->f_20)->*(*(void (CActorManager_1ba6c0::**)())&this->f_1c))();
}
} // namespace fn_001ba6c0


// 0x001ba710 Closure0<CRenderManager,bool>::vfunc_0 (30 B): matches/0x001ba710.cpp
// sym: ?vfunc_0@Closure0_1ba710@fn_001ba710@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CRenderManager, bool>::~Closure0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ba710 {
struct Closure0_1ba710 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_1ba710::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ba710
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ba730 Closure0<CRenderManager,bool>::vfunc_2 (23 B): matches/0x001ba730.cpp
// sym: ?vfunc_2@Closure0_1ba730@fn_001ba730@@QAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CRenderManager, bool>::vfunc_2`.
namespace fn_001ba730 {
struct Closure0_1ba730 : hulk_script::FunctionGenView {
    bool (::CRenderManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_1ba730::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_1ba730* o = (*(CActorManager_1ba730 * *)&this->f_20);
    Fn_1ba730 fn = (*(Fn_1ba730 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
} // namespace fn_001ba730


// 0x001ba7a0 Closure4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_2 (75 B): matches/0x001ba7a0.cpp
// sym: ?vfunc_2@Closure4_1ba7a0@fn_001ba7a0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure4<CRenderManager, unsigned int, const char *, float, float, float>::vfunc_2`.
namespace fn_001ba7a0 {
struct Closure4_1ba7a0 : hulk_script::FunctionGenView {
    unsigned int (::CRenderManager::*f_1c)(const char *, float, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure4_1ba7a0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * p = (void *)__p1; void * out = (void *)__p2;

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
} // namespace fn_001ba7a0


// 0x001ba840 Closure4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 (12 B): matches/0x001ba840.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure_1ba840@fn_001ba840@@QAEXPAX00@Z
namespace fn_001ba840 {
// (script2) the Closure's invoke passes its object as the first argument to the Method's invoke at 0x001ba120 (a jmp):
// records, no stand-in vftable; the Method's invoke by its address name, with its record's parameters
struct Method_1ba120 { void FUN_001ba120(void*, void*, void*); };
struct Closure_1ba840 { void* vftable; ScriptFunctionFields fields; ScriptMemberFn fn; void* val; void vfunc_2(void* x, void* a2, void* a3); };
void Closure_1ba840::vfunc_2(void* x, void* a2, void* a3) {
    ((Method_1ba120*)this)->FUN_001ba120(val, a2, a3);
}
} // namespace fn_001ba840


// 0x001ba850 FUN_001ba850 (76 B): matches/0x001ba850.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ba850@@QAE@PBDPAVOwner_1ba850@1@P821@AEXXZ@Z
namespace fn_001ba850 {
// (script1) Closure1<class CRenderManager,void,unsigned int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00420e94[];   // Method1<class CRenderManager,void,unsigned int>
extern "C" char DAT_00420f54[];   // Closure1<class CRenderManager,void,unsigned int>
class Owner_1ba850 {};
typedef void (Owner_1ba850::*Fn_1ba850)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ba850 fn;
    Owner_1ba850* owner;
    Closure1(const char* name, Owner_1ba850* object, Fn_1ba850 function);
};
Closure1::Closure1(const char* name, Owner_1ba850* object, Fn_1ba850 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00420e94;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0049b95c);
    vftable = DAT_00420f54;
    owner = object;
}
} // namespace fn_001ba850
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ba8c0 Closure1<CRenderManager,void,unsigned_int>::vfunc_2 (18 B): matches/0x001ba8c0.cpp
// sym: ?vfunc_2@Closure1_1ba8c0@fn_001ba8c0@@QAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CRenderManager, void, unsigned int>::vfunc_2`.
namespace fn_001ba8c0 {
struct Closure1_1ba8c0 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(unsigned int);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
#if defined(HULK_PTR64)
// (script2, stop 6) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells
void Closure1_1ba8c0::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Args_ { unsigned int a0; };
    const Args_* a = (const Args_*)__p1;
    ((*(Obj_**)&this->f_20)->*(*(void (Obj_::**)(unsigned int))&this->f_1c))(a->a0);
}
#else
void Closure1_1ba8c0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ba8c0 * *)&this->f_20)->*(*(void (CActorManager_1ba8c0::**)(const char *))&this->f_1c))(*b);
}
#endif
} // namespace fn_001ba8c0


// 0x001ba940 Closure0<CRenderManager,math::Vector>::vfunc_2 (63 B): equivalent/0x001ba940.cpp
// sym: ?vfunc_2@Closure0_1ba940@fn_001ba940@@QAEXPAX00@Z @5b5ca72bc2e3 @w5e2fdc9f34f2 @v227269bca736
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CRenderManager,math::Vector>::vfunc_2 @ 0x001ba940
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CRenderManager,math::Vector>::vfunc_2`.
namespace fn_001ba940 {
struct Closure0_1ba940 : hulk_script::FunctionGenView {
    math::Vector (::CRenderManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_1ba940::vfunc_2(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; math::Vector_1ba940 * result = (math::Vector_1ba940 *)__p2;

    math::Vector_1ba940 value = ((*(CRenderManager_1ba940 * *)&this->f_20)->*(*(math::Vector_1ba940 (CRenderManager_1ba940::**)())&this->f_1c))();
    if (result) *result = value;
}
} // namespace fn_001ba940


// 0x001ba980 FUN_001ba980 (89 B): matches/0x001ba980.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ba980@@QAE@PBDPAVOwner_1ba980@1@P821@AEXXZ@Z
namespace fn_001ba980 {
// (script1) Closure2<class CRenderManager,void,int,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00420eb4[];   // Method2<class CRenderManager,void,int,float>
extern "C" char DAT_00420f74[];   // Closure2<class CRenderManager,void,int,float>
class Owner_1ba980 {};
typedef void (Owner_1ba980::*Fn_1ba980)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ba980 fn;
    Owner_1ba980* owner;
    Closure2(const char* name, Owner_1ba980* object, Fn_1ba980 function);
};
Closure2::Closure2(const char* name, Owner_1ba980* object, Fn_1ba980 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00420eb4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_00420f74;
    owner = object;
}
} // namespace fn_001ba980
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001baa00 Closure2<CRenderManager,void,int,float>::vfunc_2 (22 B): matches/0x001baa00.cpp
// sym: ?vfunc_2@Closure2_1baa00@fn_001baa00@@QAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CRenderManager, void, int, float>::vfunc_2`.
namespace fn_001baa00 {
struct Closure2_1baa00 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(float, float);   // (script2) the instantiation this code-identical block shares (its HEAD pin)
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_1baa00::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1baa00 * p = (Pair_1baa00 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1baa00 * *)&this->f_20)->*(*(void (CActorManager_1baa00::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
} // namespace fn_001baa00


// 0x001baa20 FUN_001baa20 (76 B): matches/0x001baa20.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001baa20@@QAE@PBDPAVOwner_1baa20@1@P821@AEXXZ@Z
namespace fn_001baa20 {
// (script1) Closure1<class CRenderManager,void,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00420ec4[];   // Method1<class CRenderManager,void,float>
extern "C" char DAT_00420f84[];   // Closure1<class CRenderManager,void,float>
class Owner_1baa20 {};
typedef void (Owner_1baa20::*Fn_1baa20)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1baa20 fn;
    Owner_1baa20* owner;
    Closure1(const char* name, Owner_1baa20* object, Fn_1baa20 function);
};
Closure1::Closure1(const char* name, Owner_1baa20* object, Fn_1baa20 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00420ec4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_00420f84;
    owner = object;
}
} // namespace fn_001baa20


// 0x001baa90 Closure1<CRenderManager,void,float>::vfunc_2 (18 B): matches/0x001baa90.cpp
// sym: ?vfunc_2@Closure1_1baa90@fn_001baa90@@QAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CRenderManager, void, float>::vfunc_2`.
namespace fn_001baa90 {
struct Closure1_1baa90 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(float);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_1baa90::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1baa90 * *)&this->f_20)->*(*(void (CActorManager_1baa90::**)(const char *))&this->f_1c))(*b);
}
} // namespace fn_001baa90

namespace fn_ff10b020 {

// 0x001bb580 FUN_001bb580 (83 B): equivalent/0x001bb580.cpp
// sym: ?FUN_001bb580@Registry_1bb580@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb580@2@P832@AEXHHH@Z@Z @3484b9884c61 @wbaec67eed9c5 @v30d2331d16a8
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
// sym: ?FUN_001bb630@Registry_1bb630@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb630@2@P832@AEXMMMMMM@Z@Z @189ca8c953e3 @w6fbd9681608b @v1ed64156c36f
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

// 0x001bb700 FUN_001bb700 (109 B): matches/0x001bb700.cpp [wrapped: conflict: CRenderManager; Closure0; Method0]
// sym: ?FUN_001bb700@Registry_1bb700@fn_001bb700@@QAEXPBDPAVOwner_1bb700@2@P832@AEXXZ@Z
namespace fn_001bb700 {
// (script1) ScriptHandler's registration of a Closure0<class CRenderManager,bool>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00420e64[];   // Method0<class CRenderManager,bool>
extern "C" char DAT_00420f24[];   // Closure0<class CRenderManager,bool>
class Owner_1bb700 {};
typedef void (Owner_1bb700::*Fn_1bb700)();
struct Closure_1bb700 : hulk_script::ScriptFunction {
    Fn_1bb700 fn;
    Owner_1bb700* owner;
    Closure_1bb700(const char* name, Owner_1bb700* object, Fn_1bb700 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00420e64;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
        vftable = DAT_00420f24;
        owner = object;
    }
};
struct Registry_1bb700 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_001bb700(const char* name, Owner_1bb700* object, Fn_1bb700 function);
};
void Registry_1bb700::FUN_001bb700(const char* name, Owner_1bb700* object, Fn_1bb700 function) {
    Closure_1bb700* c = new Closure_1bb700(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_001bb700
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff10b020 {

// 0x001bb770 FUN_001bb770 (83 B): equivalent/0x001bb770.cpp
// sym: ?FUN_001bb770@Registry_1bb770@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb770@2@P832@AEI0MMM@Z@Z @a90f6d8111ac @w6d0983fff29b @v672b99bd8f76
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
// sym: ?FUN_001bb7d0@Registry_1bb7d0@fn_ff10b020@@QAEXPBDPAVCRenderManager_1bb7d0@2@P832@AEI0VVector_1bb7d0@math@@2M@Z@Z @2287d82bd815 @wc87d3d62ebac @v3ab33fe76249
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

// 0x001bb880 FUN_001bb880 (109 B): matches/0x001bb880.cpp [wrapped: conflict: CRenderManager; Closure0; DAT_0048e10c; Method0]
// sym: ?FUN_001bb880@Registry_1bb880@fn_001bb880@@QAEXPBDPAVOwner_1bb880@2@P832@AEXXZ@Z
namespace fn_001bb880 {
// (script1) ScriptHandler's registration of a Closure0<class CRenderManager,class math::Vector>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00420ea4[];   // Method0<class CRenderManager,class math::Vector>
extern "C" char DAT_00420f64[];   // Closure0<class CRenderManager,class math::Vector>
class Owner_1bb880 {};
typedef void (Owner_1bb880::*Fn_1bb880)();
struct Closure_1bb880 : hulk_script::ScriptFunction {
    Fn_1bb880 fn;
    Owner_1bb880* owner;
    Closure_1bb880(const char* name, Owner_1bb880* object, Fn_1bb880 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00420ea4;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
        vftable = DAT_00420f64;
        owner = object;
    }
};
struct Registry_1bb880 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_001bb880(const char* name, Owner_1bb880* object, Fn_1bb880 function);
};
void Registry_1bb880::FUN_001bb880(const char* name, Owner_1bb880* object, Fn_1bb880 function) {
    Closure_1bb880* c = new Closure_1bb880(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_001bb880
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bb990 FUN_001bb990 (1676 B): equivalent/0x001bb990.cpp [wrapped: conflict: CRenderManager; Closure1; Closure3; Closure4 (+6)]
// sym: ??0CRenderManager@fn_001bb990@@QAE@XZ @16ff379d94d9 @wb96e5264ca53 @v15b68b28bc9b
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

extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)
void* FUN_00263ea0(unsigned size);


template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void* get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<float> { static const void* get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<unsigned int> { static const void* get() { return ((char*)&DAT_0049b95c); } };

// Function's fields (include/decls/data/script.h) after the vftable.
// (script1) records (include/game/script_bind.h): the game's vftables by address, per instantiation (VftOf), no
// stand-in vftable.
template <class X> struct VftOf;
class MethodBase_1bb990 : public hulk_script::ScriptVftable, public ScriptFunctionFields {
  public:
    void FUN_001d0480(const char*, int);
    MethodBase_1bb990() {}
    MethodBase_1bb990(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_1bb990 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) throw() : MethodBase_1bb990(name, 1) {
        vftable = VftOf<Method1>::get();
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char* name, T* o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f) {
        this->vftable = VftOf<Closure1>::get();
        owner = o;
    }
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
    Closure3(const char* name, T* o, typename Method3<T, R, A, B, C>::Fn f) throw() : Method3<T, R, A, B, C>(name, f) {
        this->vftable = VftOf<Closure3>::get();
        owner = o;
    }
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
        throw() : Method6<T, R, A, B, C, D, E, F>(name, f) {
        this->vftable = VftOf<Closure6>::get();
        owner = o;
    }
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
    math::Vector FUN_001b91d0();
    math::Vector FUN_001b9200();
    math::Vector FUN_001b9230();
    math::Vector FUN_001b9260();
    void FUN_001b9290(int, float);

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
    Closure4(const char* name, T* o, typename Method4<T, R, A, B, C, D>::Fn f) throw() : Method4<T, R, A, B, C, D>(name, f) {
        this->vftable = VftOf<Closure4>::get();
        owner = o;
    }
    T* owner;
};

extern "C" char DAT_00420e14[], DAT_00420ed4[];   // Method1 / Closure1<CRenderManager,void,bool>
extern "C" char DAT_00420e94[], DAT_00420f54[];   // Method1 / Closure1<CRenderManager,void,unsigned int>
extern "C" char DAT_00420ec4[], DAT_00420f84[];   // Method1 / Closure1<CRenderManager,void,float>
extern "C" char DAT_00420ee4[];   // Closure3<CRenderManager,void,int,int,int>
extern "C" char DAT_00420f04[];   // Closure6<CRenderManager,void,float,float,float,float,float,float>
extern "C" char DAT_00420f34[];   // Closure4<CRenderManager,unsigned int,const char*,float,float,float>
extern "C" char DAT_00420f44[];   // Closure4<CRenderManager,unsigned int,const char*,math::Vector,math::Vector,float>
template <> struct VftOf<Method1<CRenderManager, void, bool> > { static void* get() { return DAT_00420e14; } };
template <> struct VftOf<Closure1<CRenderManager, void, bool> > { static void* get() { return DAT_00420ed4; } };
template <> struct VftOf<Method1<CRenderManager, void, unsigned int> > { static void* get() { return DAT_00420e94; } };
template <> struct VftOf<Closure1<CRenderManager, void, unsigned int> > { static void* get() { return DAT_00420f54; } };
template <> struct VftOf<Method1<CRenderManager, void, float> > { static void* get() { return DAT_00420ec4; } };
template <> struct VftOf<Closure1<CRenderManager, void, float> > { static void* get() { return DAT_00420f84; } };
template <> struct VftOf<Closure3<CRenderManager, void, int, int, int> > { static void* get() { return DAT_00420ee4; } };
template <> struct VftOf<Closure6<CRenderManager, void, float, float, float, float, float, float> > { static void* get() { return DAT_00420f04; } };
template <> struct VftOf<Closure4<CRenderManager, unsigned int, const char*, float, float, float> > { static void* get() { return DAT_00420f34; } };
template <> struct VftOf<Closure4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float> > { static void* get() { return DAT_00420f44; } };
// Closure2 / Closure1 built by their out-of-line initializers (matches/0x001ba510.cpp, 0x001ba980.cpp): allocated as
// ScriptClosureView.
struct Closure2_1bb990 {
    Closure2_1bb990* FUN_001ba510(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(float, float));
};
struct ClosureShaderLight {
    ClosureShaderLight* FUN_001ba980(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(int, float));
};

struct Registry_1bb990 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_001bb690(const char* name, CRenderManager* owner, void (CRenderManager::*fn)());
    void FUN_001bb700(const char* name, CRenderManager* owner, bool (CRenderManager::*fn)());
    void FUN_001bb880(const char* name, CRenderManager* owner, math::Vector (CRenderManager::*fn)());
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

    Shader_1bb990* ov = (Shader_1bb990*)FUN_00263ea0(sizeof(HulkShader));   // (allocsize1) the shader's record (decls/shader.h)
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
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003feefc;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}
} // namespace fn_001bc020

