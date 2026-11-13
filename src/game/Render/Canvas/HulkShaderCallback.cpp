// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c1460..0x001c49c0 (kind game, layer game, confidence high), dominant class Render::Canvas::HulkShaderCallback
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/Render/Canvas.h"
#include "decls/data/game/global.h"
#include "gen/Render.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ffffca36 {
#define TREE_TU_END }
namespace fn_ffffca36 {} using namespace fn_ffffca36;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_ffffca36 {
const float gZero_1c1580 = 0.0f;
const float gOne_1c1580 = 1.0f;
class Shader_1c1580 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
    virtual void f7(int, int);
};
class Arg_1c1580 {
  public:
    char pad[16];
    Shader_1c1580* shader;
};
class Manager_1c1580 {
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
    virtual void f35(int);
};
extern Manager_1c1580* hulk_at_0052c2a8;
class Other_1c16a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j(void*, int);
};
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};
class X_1c16d0 {
  public:
    char pad[0xcf];
    char mFlag;
    void SetFlag(char c);
};
struct Snd_1c16e0 {
    virtual void v0();
    virtual void Play(int, float, float, unsigned char);
};
struct Vec3_1c17d0 {
    float x, y, z;
    hulk_freg FUN_0022d110() const;
};
struct Collider;
struct Query_1c17d0 {
    int kind;
    int f1, f2, f3, f4, f5;
    unsigned char flag;
};
struct Shape_1c17d0 {
    char pad0[0x20];
    Collider *collider;
};
struct Body_1c17d0 {
    char pad0[0x74];
    Shape_1c17d0 *shape;
};
struct Owner_1c17d0 {
    Body_1c17d0 *FUN_001d72e0();
};
struct Source_1c17d0 {
    char pad0[0xa0];
    Owner_1c17d0 *owner;
    Owner_1c17d0 *FUN_001d72e0();
};
struct Entity {
    char pad0[0x30];
    Vec3_1c17d0 pos;
};
} // namespace fn_ffffca36
class World {
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
    virtual Entity *v14();
};
namespace fn_ffffca36 {
struct Request {
    char pad0[0x1c];
    Source_1c17d0 *source;
};
bool FUN_002f15a0(Vec3_1c17d0 *from, Vec3_1c17d0 *delta, Vec3_1c17d0 *hit, float length, Collider *collider, Query_1c17d0 *query);
struct Probe_1c17d0 {
    char pad0[8];
    World *world;
    char padC[0xf4 - 0xc];
    Vec3_1c17d0 points[2];
    bool FUN_001c17d0(Request *req);
};
struct Vec {
    int x, y, z;
};
class Obj {
  public:
    Obj();
    int a[7];
    char _m_pad_1c[0x40];
    float f;
    float g;
    float h;
    float j;
    char _m_pad_6c[0x1];
    char b;
    char c;
    char d;
    int x;
    int y;
    int z;
    char _m_pad_7c[0x78];
    Vec values[1];
    void Set(int index, const Vec* value);
};
struct R_1c1e90 {
    virtual void A();
    virtual void Rel();
};
struct Sub_1c1e90 {
    void Cleanup_001c27c0();
    char pad[0xb0];
};
struct C_1c1e90 {
    virtual void V();
    R_1c1e90* m4;
    R_1c1e90* m8;
    Sub_1c1e90 sub;
    R_1c1e90* mbc;
    R_1c1e90* mc0;
    R_1c1e90* mc4;
    R_1c1e90* mc8;
    void Shutdown();
};
struct Plane_1c1f30 {
    float a, b, c, d;
};
class Camera {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float fov, float aspect);
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9(int a);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int which, Plane_1c1f30 *out);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(int a);
};
class System_1c1f30 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual float vfunc_16();
};
class CameraState {
public:
    char pad00[8];
    Camera *camera;
    char pad0c[4];
    Plane_1c1f30 left;
    Plane_1c1f30 right;
    Plane_1c1f30 top;
    Plane_1c1f30 bottom;
    Plane_1c1f30 nearP;
    Plane_1c1f30 farP;
    char pad70[0xb0 - 0x70];
    float halfX;
    float halfY;
    float lastFov;
    void FUN_001c1f30(int a, float fov, float aspect, int d, int e);
};
struct Vec_1c20e0 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Input_1c20e0 { float x,y,z,radius; };
struct Matrix { float m[16];  };
struct Object { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual float s8(); virtual void s9(); virtual float s10(); virtual void s11(); virtual void s12(); virtual Matrix* s13(); };
hulk_freg __cdecl FUN_00018a20(float);
struct Target_1c20e0 { char pad[8]; Object* object; char pad2[0xa4]; float horizontalLimit,verticalLimit; int FUN_001c20e0(const Input_1c20e0*); };
struct Sub_1c22f0 {
    void FnA_0029bc80(int);
    void FnB_0029bb60();
};
struct Obj2_1c22f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct Parent_1c22f0 {
    void Done_00294080();
};
class Thing_1c22f0 {
  public:
    void Fn();
    char pad0[4];
    Parent_1c22f0* mParent;
    char pad1[0xb4];
    Sub_1c22f0* mSub;
    int mVal;
    char pad2[12];
    float mF;
    float mG;
};
extern "C" char DAT_004216d4[];
extern "C" void *FUN_0008d690(unsigned int size);
struct HulkShaderCallback {
    hulk_intptr vptr;
    int f04;
    int f08;
    float f0c;
    int f10;
    unsigned int color0;
    unsigned int color1;
};
class Canvas {
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
    virtual void SetCallback(HulkShaderCallback *cb);
    char pad04[12];
    HulkShaderCallback *callback;
};
struct Entry_1c2440 {
    char pad0[8];
    float value;
    float weight;
    float fade;
};
class Owner_1c2440 {
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
    virtual void Refresh();
};
extern "C" void * __stdcall FUN_001c23c0(void *, bool);
struct Ent_1c24d0 {
    char pad0[8];
    float f8;
    float fc;
    float f10;
    int f14;
};
class Obj_1c24d0 {
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
    virtual void Fire();
};
struct Ent_1c2550 {
    char pad[8];
    float a;
    float v;
    float b;
};
class Obj_1c2550 {
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
    virtual void Fire();
};
struct Obj_1c25c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
struct Host_1c25c0 {
    char pad[0xbc];
    int value;
    void target(Obj_1c25c0*, int, int);
};
void __stdcall helper_001c2440(Obj_1c25c0*, int);
class Item_1c2650 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i(int, int);
};
class Mgr_1c2650 {
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
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p(int);
    virtual void q(int);
};
struct Root_1c2650 {
    Mgr_1c2650* m;
};
class Target_1c2650 {
    char pad[0xbc];
    Item_1c2650* member;

  public:
    void helper_001c2440(Item_1c2650*, int);
    void fn(Item_1c2650*, int, int);
};
typedef unsigned int u32_1c26a0;
struct Obj_1c26a0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(u32_1c26a0, u32_1c26a0);
};
void __stdcall FUN_001c2550(Obj_1c26a0*, u32_1c26a0);
struct Owner_1c26a0 {
    char pad[0xbc];
    u32_1c26a0 value;
    void helper_001c2440(Obj_1c26a0*, u32_1c26a0);
    void target(Obj_1c26a0*, u32_1c26a0, u32_1c26a0);
};
class X_1c2760 {
  public:
    int m;
    X_1c2760();
};
struct Entry { uint a,b,c,d; };
struct Target { uint count; Entry entries[1]; void FUN_001c2770(uint n, const Entry *source); };
struct Plane {
  public:
    union { float nx; float x; };
    union { float ny; float y; };
    union { float nz; float z; };
    union { float d; float w; };
};
struct Volume {
    int count;
    Plane planes[1];
    unsigned char FUN_001c2820(const float* point);
};
class Item_1c2870 {
  public:
    char pad[16];
};
class Container_1c2870 {
  public:
    int count;
    Item_1c2870 items[1];
    bool Find(hulk_intptr x);
};
struct V3 {
    float x, y, z;
};
class X {
  public:
    char pad[0x18];
    struct E {
        char c;
        char pad[0x1b];
    };
    union {
        E e[32];
        struct {
            char skip[0x368];
            int v;
        };
    };
    X();
};
struct Entry_1c2c20 {
    int a, b, c;
    bool Check_0022d2b0(const Entry_1c2c20*, unsigned);
};
class Obj_1c2c20 {
    char pad[0x180];

  public:
    unsigned count;
    void Add(const Entry_1c2c20* p);
};
struct Vec3_1c2c90 {
    float x, y, z;
    void Scale(float s) {
        x = x * s;
        y = y * s;
        z = z * s;
    }
};
class PointSet_1c2c90 {
public:
    Vec3_1c2c90 *FUN_001c2c90(Vec3_1c2c90 *out);

    Vec3_1c2c90 points[32];
    unsigned int count;
};
struct Vec3_1c2e70 { float x, y, z; };
struct PointList { Vec3_1c2e70 *begin; Vec3_1c2e70 *end; };
struct Plane_1c2e70 { float a, b, c, d; };
class Hull_1c2e70 {
public:
    unsigned int count;
    Plane_1c2e70 planes[1];

    bool FUN_001c2e70(const PointList *pts);
};
struct Vec3_1c3030 {
    float x, y, z;
    bool FUN_0022d2b0(Vec3_1c3030 *other, float eps);
    void FUN_0022d180();
};
struct Plane_1c3030 {
    float nx, ny, nz;
    float d;
};
union FS_1c3030 {
    float f;
    unsigned int u;
};
struct PointSet_1c3030 {
    Vec3_1c3030 points[32];
    unsigned int count;
    void FUN_001c2c20(Vec3_1c3030 *p);
    Vec3_1c3030 *FUN_001c2c90(Vec3_1c3030 *out);
};
struct Segment_1c3030 {
    Vec3_1c3030 p;
    Vec3_1c3030 q;
    char dropped;
    char pad19[3];
};
extern "C" int __cdecl FUN_001c2940(const void *, const void *, void *, void *);
struct Hull_1c3030 {
    unsigned int count;
    Plane_1c3030 planes[6];
    Vec3_1c3030 *FUN_001c3030(Vec3_1c3030 *out);
};
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_00263ea0(unsigned);
struct MainObject { MainObject* FUN_001c1a40(); };
struct Vec_1c3520 { void FUN_0022b980(); char data[80]; };
struct DirectionalLight_nv_1c3520 {
    pure3d::DirectionalLight* FUN_002a2e70();
    void FUN_002a2ef0(float,float,float);
    void FUN_002a07a0(int);
};
struct LightGroup_nv_1c3520 {
    pure3d::LightGroup* FUN_002a1140(int);
};
struct Target_1c3520 { MainObject* object; char pad[24]; Vec_1c3520 vec; unsigned char flag; char pad2[3]; pure3d::DirectionalLight* effect; pure3d::LightGroup* other; void Run(); };
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_001c1e90 {
    void FUN_001c1e90();
};
extern void thunk_FUN_00267090(CCollisionAction*);
extern "C" void __cdecl FUN_0023f8c0(const char*);
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
struct World_nv_1c35f0 {
    Render::World* FUN_001c9030();
};
struct Small_1c35f0 {
    Small_1c35f0* FUN_001c5f10();
};
struct ObjectManager_nv_1c35f0 {
    Render::ObjectManager* FUN_001c5840();
};
struct Owner_1c35f0;
struct LevelLoader_nv_1c35f0 {
    Render::LevelLoader* FUN_001c8f60(Render::World*, Owner_1c35f0*);
};
struct Item_1c35f0 {
    char pad[12];
    unsigned char active;
    Item_1c35f0* FUN_001c49c0();
};
struct Manager_1c35f0 {
    void FUN_00265210(Render::LevelLoader*, unsigned int);
};
struct Owner_1c35f0 {
    void* context;
    Render::World* engine;
    Small_1c35f0* small;
    Render::ObjectManager* medium;
    char pad10[4];
    Item_1c35f0* item14;
    Item_1c35f0* item18;
    char pad1c[0x52];
    unsigned char initialized;
    void FUN_001c35f0();
};
class H {
  public:
    int check_001c5b00(int);
};
class C_1c3740 {
    char pad[0x0c];
    H* member;

  public:
    void f(hulk_intptr);
};
class Y_1c37f0 {
  public:
    void Fng_001c4450(int, int, int, int);
};
class X_1c37f0 {
    char pad[0x18];
    Y_1c37f0* p;

  public:
    void f(int, int, int, int);
};
struct Other_1c3800 {
    void Fnf_001c4390(int, int, int, int, int);
};
struct Obj_1c3800 {
    char pad[0x14];
    Other_1c3800* value;
    void run(int, int, int, int, int);
};
class Inner_1c3830 {
  public:
    void Fnf_001c16e0(int, int);
};
class Outer_1c3830 {
  public:
    Inner_1c3830* p;
    void g(int, int);
};
class Bc {
  public:
    void run_001c59e0(int);
};
class B0_1c3850 {
  public:
    void run_001c16c0(int);
};
class B4 {
  public:
    void run_001c8590(int);
};
class Bd {
  public:
    void run_001c4620(int);
};
class A_1c3850 {
  public:
    B0_1c3850* p0;
    B4* p4;
    char p8[4];
    Bc* pc;
    char p10[4];
    Bd* p14;
    Bd* p18;
    char pad[0x52];
    unsigned char enabled;
    void go(int x);
};
typedef unsigned int u32_1c3970;
} // namespace fn_ffffca36
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_ffffca36 {
struct X_1c3990 {
    char pad[0x1c];
};
struct X_1c39a0 {
    char pad[0x1c];
};
struct X_1c39b0 {
    char pad[0x2c];
};
extern "C" int __cdecl state_00266da0(int);
extern "C" void __cdecl report(const char*);
class Factory {
  public:
    void* create_001c5900(int, int);
};
class Owner_1c39e0 {
  public:
};
class Scene {
    char p[4];
    Owner_1c39e0* owner;
    char q[4];
    Factory* factory;

  public:
    void make(int, int);
};
extern "C" void* __cdecl Alloc(hulk_intptr);
extern "C" void __cdecl Free(void*);
extern "C" void __cdecl Print_0023f8c0(const char*);
struct Maker_1c3a40 {
    void* Make_001c5960(int, int);
};
struct Store {
};
struct Obj_1c3a40 {
    char pad[4];
    Store* store;
    char pad2[4];
    Maker_1c3a40* maker;
    void Create(int a, int b);
};
class Sub_1c3b20 {
  public:
    int Fn_001c60f0(int, int);
};
class C_1c3b20 {
  public:
    char pad[8];
    Sub_1c3b20* mSub;
    hulk_intptr Forward(hulk_intptr, hulk_intptr);
};
class Helper_1c3b30 {
  public:
    int first_001c5fb0(int);
    void second_001c6000(int);
};
class Obj_1c3b30 {
  public:
    char pad[8];
    Helper_1c3b30* m;
    void target(hulk_intptr);
};
class C_1c3b80;
class D {
  public:
};
class C_1c3b80 {
  public:
    void* pad[3];
    int Get_001c59d0(int);
    void Finish_001c5a20(int);
};
class Obj_1c3b80 {
  public:
    char pad0[4];
    D* m4;
    char pad8[4];
    C_1c3b80* mC;
    void Target(hulk_intptr);
};
class B_1c3bb0 {
  public:
};
class A_1c3bb0 {
  public:
    char pad[12];
    B_1c3bb0* member;
    void* Fnf_001c59d0(int);
};
class C_1c3bb0 {
  public:
    char pad[12];
    A_1c3bb0* member;
    void run(hulk_intptr, int);
};
class Context {
  public:
    int* Lookup_001c59d0(int);
};
class Obj_1c3bd0 {
  public:
    char pad[0x0c];
    Context* mContext;
    hulk_intptr Target(hulk_intptr);
};
class B_1c3c10 {
  public:
    void Method_001c1910(int, int);
};
class A_1c3c10 {
  public:
    B_1c3c10* m;
    void Fn(int, hulk_intptr);
};
class Inner_1c3c20 {
  public:
    char pad[0xcc];
    char flag;
};
class Helper_1c3c20 {
  public:
    void Stop_001c8250();
};
class Obj_1c3c20 {
  public:
    Inner_1c3c20* volatile p;
    Helper_1c3c20* h;
    void Set(char value);
};
class C_1c3c90 {
    char pad[0x6f];

  public:
    unsigned char value;
};
struct A_1c3cb0 {
    char pad[0x14];
    void* m;
};
extern "C" int __fastcall FUN_001c4500(void*);
struct Inner_1c3cc0 {
    void Do_001c1f30(hulk_intptr, int, int, int, int);
};
class X_1c3cc0 {
  public:
    char pad[0x1c];
    int sub;
    char p[0x5c - 0x20];
    int a;
    int b;
    int c;
    int d;
    unsigned char done;
    void f();
};
class A_1c3d20 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c3d20 {
  public:
    A_1c3d20* p;
    void run();
};
class First_1c3dc0 {
  public:
    void Cleanup_001c1e90();
};
class Obj_1c3dc0 {
  public:
    virtual void v0();
    virtual void v1();
};
void thunk_FUN_00267090(First_1c3dc0*);
class Target_1c3dc0 {
  public:
    First_1c3dc0* volatile mFirst;
    char pad[0x6c];
    Obj_1c3dc0* volatile m70;
    Obj_1c3dc0* volatile m74;
    void F();
};
class Engine_1c4010 {
  public:
    void Init_001c1f30(void*, int, int, int, int);
    int Finish_001c1310(int);
};
class Engine_1c4050 {
  public:
    void Init_001c1f30(void*, int, int, int, int);
    int Finish_001c20e0(int);
};
class Obj_1c4090 {
  public:
    virtual void f();
    virtual void g();
};
class Owner_1c4090 {
  public:
    char pad[0x78];
    Obj_1c4090* item;
    void set(Obj_1c4090* p);
};
class A_1c40f0 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c40f0 {
  public:
    A_1c40f0* p;
    void run();
};
class A_1c4140 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c4140 {
  public:
    char pad[0x10];
    A_1c4140* p;
    void clear();
};
class Base_1c4160 {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_1c4160 {
  public:
    char pad[0x10];
    Base_1c4160* member;
    hulk_intptr target(unsigned char flag);
};
void thunk_0008d330(Obj_1c4160*);
struct Manager_1c4230 {
    void FUN_002659a0(unsigned int);
};
void __cdecl thunk_FUN_00267090(void*);
struct Resource_1c4230 {
    virtual void slot0();
    virtual void release();
};
struct Holder_1c4230 {
    char pad[16];
    Resource_1c4230* resource;
};
struct EnginePart {
};
struct Owned_1c4230 {
    virtual void destroy(int);
};
struct Engine_1c4230 {
    char pad0[4];
    Owned_1c4230* first;
    EnginePart* part;
    Owned_1c4230* second;
    char pad10[4];
    Holder_1c4230* holder14;
    Holder_1c4230* holder18;
    char pad1c[0x52];
    unsigned char setup;
    void cleanup();
};
extern const float gZero_1c4500;
class Obj_1c4500 {
    char pad0[0x18];
    float a;
    char pad1[0x0c];
    float b;

  public:
    bool Check();
};
struct Slot_1c4620 {
    char flag;
    char pad1[3];
    float f4;
    int f8;
    int fc;
    void FUN_001c4580(int arg);
    void clear() {
        f8 = 0;
        f4 = 0;
        fc = 0;
        flag = 0;
    }
};
struct Pair_1c4620 {
    char pad0[0x14];
    Slot_1c4620 b;
    Slot_1c4620 a;
    void FUN_001c4620(int arg);
};

} // namespace fn_ffffca36

// 0x001c1460 Render::Canvas::HulkShaderCallback::vfunc_3 (286 B): equivalent/0x001c1460.cpp [wrapped: conflict: Render::Canvas::HulkShaderCallback]
// sym: ?vfunc_3@HulkShaderCallback@Canvas@Render@fn_001c1460@@UAEPAUObject@4@PAU54@@Z @ec4f3d00f728 @w7032402674db
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001c1460 {
// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 16/16)
// Render::Canvas::HulkShaderCallback::vfunc_3 @ 0x001c1460
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

typedef unsigned long U32_1c1460;
struct Color_1c1460 { U32_1c1460 value; void FUN_00011750(U32_1c1460 from, U32_1c1460 to, float amount); };
struct Gfx {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
 virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
 virtual void s32(); virtual void s33(); virtual int count(); virtual void setColor(U32_1c1460); virtual Color_1c1460* getColor(Color_1c1460*); virtual void s37(); virtual void s38(); virtual bool enabled(int); virtual void s40(); virtual void s41(); virtual void setLight(int,U32_1c1460); virtual Color_1c1460* getLight(Color_1c1460*,int);
};
struct Shader { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void setInt(U32_1c1460,int); virtual void setFloat(U32_1c1460,float); };
struct Object { char pad[16]; Shader* shader; };
namespace Render { namespace Canvas {
struct HulkShaderCallback {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual Object* vfunc_3(Object*); virtual void vfunc_4(); virtual void vfunc_5();
 U32_1c1460 refs; float fade; float lighting; float blend; U32_1c1460 blendColor; U32_1c1460 savedColor;
};
Object* HulkShaderCallback::vfunc_3(Object* object) {
 Color_1c1460 color;
 if (blend > 0.0f) {
  U32_1c1460 original = DAT_0052c2a8->getColor(&color)->value;
  savedColor = original;
  color.FUN_00011750(original, blendColor, blend);
  DAT_0052c2a8->setColor(color.value);
  int n = DAT_0052c2a8->count();
  for(int i=0;i<n;++i) {
   if(DAT_0052c2a8->enabled(i)) {
    DAT_0052c2a8->getLight(&color,i);
    color.FUN_00011750(color.value,0xff000000,blend);
    DAT_0052c2a8->setLight(i,color.value);
   }
  }
 }
 if(fade > 0.0f && object) object->shader->setFloat(0x45444146,fade);
 if(lighting < 1.0f && object) object->shader->setInt(0x4153524c,1);
 return object;
}
}}
} // namespace fn_001c1460
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001c1580 Render::Canvas::HulkShaderCallback::vfunc_4 (119 B): matches/0x001c1580.cpp
// sym: ?vfunc_4@HulkShaderCallback@Canvas@Render@@UAEHPAX@Z
hulk_intptr Render::Canvas::HulkShaderCallback::vfunc_4(void* __p0) { Arg_1c1580 * p = (Arg_1c1580 *)__p0;

    hulk_intptr result = (hulk_intptr)p;
    if (this->f_08 > 0.0f && p)
        p->shader->f7(0x45444146, 0);
    if (this->f_10 > 0.0f)
        hulk_at_0052c2a8->f35(this->f_18);
    if (this->f_0c < 1.0f && p)
        p->shader->f6(0x4153524c, 0);
    return result;
}


// 0x001c1600 Render::Canvas::HulkShaderCallback::vfunc_5 (32 B): matches/0x001c1600.cpp
// sym: ?vfunc_5@HulkShaderCallback@Canvas@Render@@UAEHH@Z
int Render::Canvas::HulkShaderCallback::vfunc_5(int param) {
    if (this->f_08 > 0.0f && param == 0)
        param = 1;
    return param;
}


// 0x001c16a0 FUN_001c16a0 (27 B): matches/0x001c16a0.cpp
// sym: ?FUN_001c16a0@Target_1c16a0@owners@@QAEXPAX@Z
void owners::Target_1c16a0::FUN_001c16a0(void* p) {
    if (p)
        ((Other_1c16a0*)p)->j((void*)value, 0);
}

namespace fn_ffffca36 {

// 0x001c16c0 FUN_001c16c0 (3 B): matches/0x001c16c0.cpp
// sym: ?vfunc_7@CAgent@fn_ffffca36@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CAgent::vfunc_7(int a) {
    (void)a;
}


// 0x001c16d0 FUN_001c16d0 (13 B): matches/0x001c16d0.cpp
// sym: ?SetFlag@X_1c16d0@fn_ffffca36@@QAEXD@Z
void X_1c16d0::SetFlag(char c) {
    mFlag = c;
}

} // namespace fn_ffffca36

// 0x001c16e0 FUN_001c16e0 (107 B): matches/0x001c16e0.cpp
// sym: ?FUN_001c16e0@Obj_1c16e0@owners@@QAEXMM@Z
void owners::Obj_1c16e0::FUN_001c16e0(float x, float y) {
    a = x;
    b = y;
    if (x != 0.0f && (*(Snd_1c16e0**)&DAT_004e2318)) {
        (*(Snd_1c16e0**)&DAT_004e2318)->Play(1, x, y, c);
        return;
    }
    (*(Snd_1c16e0**)&DAT_004e2318)->Play(0, x, y, c);
}


// 0x001c1750 FUN_001c1750 (35 B): matches/0x001c1750.cpp
// sym: ?FUN_001c1750@Obj_1c1750@owners@@QAEXPAH0@Z
void owners::Obj_1c1750::FUN_001c1750(int* x, int* y) {
    if (x)
        *x = a;
    if (y)
        *y = b;
}


// 0x001c1780 FUN_001c1780 (13 B): matches/0x001c1780.cpp
// sym: ?FUN_001c1780@Target_1c1780@owners@@QAEXE@Z
void owners::Target_1c1780::FUN_001c1780(unsigned char v) {
    value = v;
}


// 0x001c1790 FUN_001c1790 (13 B): matches/0x001c1790.cpp
// sym: ?FUN_001c1790@C_1c1790@owners@@QAEHH@Z
int owners::C_1c1790::FUN_001c1790(int x) {
    value = x;
    return (int)(value);
}


// 0x001c17a0 FUN_001c17a0 (23 B): matches/0x001c17a0.cpp
// sym: ?FUN_001c17a0@Obj_1c17a0@owners@@QAEXII@Z
void owners::Obj_1c17a0::FUN_001c17a0(unsigned x, unsigned y) {
    a = x;
    b = y;
}


// 0x001c17c0 FUN_001c17c0 (13 B): matches/0x001c17c0.cpp
// sym: ?FUN_001c17c0@C_1c17c0@owners@@QAEHH@Z
int owners::C_1c17c0::FUN_001c17c0(int x) {
    value = x;
    return (int)(value);
}

namespace fn_ffffca36 {

// 0x001c17d0 FUN_001c17d0 (305 B): equivalent/0x001c17d0.cpp
// sym: ?FUN_001c17d0@Probe_1c17d0@fn_ffffca36@@QAE_NPAURequest@2@@Z @ce44057b1d5c @w04c287477a12
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 11/12, incomplete)
// FUN_001c17d0 @ 0x001c17d0
bool Probe_1c17d0::FUN_001c17d0(Request *req)
{
    Vec3_1c17d0 dir;
    Vec3_1c17d0 from;
    Vec3_1c17d0 delta;
    Query_1c17d0 query;

    if (req->source == 0)
        return false;
    Body_1c17d0 *body = (Body_1c17d0 *)((Source_1c17d0 *)req->source)->FUN_001d72e0();
    if (body == 0)
        return false;
    Shape_1c17d0 *shape = body->shape;
    if (shape == 0)
        return false;
    Collider *collider = shape->collider;
    if (collider == 0)
        return false;

    from = world->v14()->pos;
    for (int i = 0; i < 2; i++) {
        dir.x = points[i].x - from.x;
        dir.y = points[i].y - from.y;
        dir.z = points[i].z - from.z;
        delta = dir;
        query.kind = 2;
        query.f1 = 0;
        query.f2 = 0;
        query.f3 = 0;
        query.f4 = 0;
        query.f5 = 0;
        query.flag = 1;
        float length = delta.FUN_0022d110();
        if (FUN_002f15a0(&from, &delta, &dir, length, collider, &query))
            return true;
    }
    return false;
}


// 0x001c1910 FUN_001c1910 (37 B): matches/0x001c1910.cpp
// sym: ?Set@Obj@fn_ffffca36@@QAEXHPBUVec@2@@Z
void Obj::Set(int index, const Vec* value) {
    Vec* p = &values[index];
    p->x = value->x;
    p->y = value->y;
    p->z = value->z;
}


// 0x001c19a0 FUN_001c19a0 (4 B): matches/0x001c19a0.cpp
// sym: ?FUN_001c19a0@fn_ffffca36@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
hulk_intptr __fastcall FUN_001c19a0(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_ffffca36

// 0x001c1a40 FUN_001c1a40 (1101 B): equivalent/0x001c1a40.cpp [wrapped: conflict: Gfx; pure3d::GameDrawableInfo; pure3d::pddiExtFramebufferEffects; pure3d::pddiExtension]
// sym: ?FUN_001c1a40@Hud_1c1a40@fn_001c1a40@@QAEPAV12@XZ @4389c66ade7c @w0dd1f918b4c0
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_001c1a40 {
// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 24/24)
// FUN_001c1a40 @ 0x001c1a40
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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


extern "C" void* FUN_0008d690(unsigned int size);
void* thunk_FUN_0008d690(unsigned int size);

namespace pure3d {
class pddiExtension {
  public:
    virtual void v0();
};
class pddiExtFramebufferEffects : public pddiExtension {
  public:
    virtual void v1();
};
class GameDrawableInfo {
  public:
    virtual void v0_00018b30();
    int field4;
    GameDrawableInfo() { field4 = 0; }
};
}

class Base_1c1a40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(float x);
    virtual void v8();
    virtual void v9(float x);
};
struct Child_1c1a40 : public Base_1c1a40 {
};
struct Owner_1c1a40 : public Base_1c1a40 {
    Owner_1c1a40* FUN_0029bea0(int a, int b);
    void FUN_0029b690(Base_1c1a40* child);
};
struct View_1c1a40 : public Base_1c1a40 {
    char pad[0x2c - 4];
    int field2c;
    View_1c1a40* FUN_00294880();
    void FUN_00294980(Base_1c1a40* other);
};
struct OpaqueTraversal_1c1a40 : public Base_1c1a40 { char pad[0x1c - 4]; char flag; OpaqueTraversal_1c1a40* FUN_002a2d50(int n); };
struct TranslucentTraversal_1c1a40 : public Base_1c1a40 { TranslucentTraversal_1c1a40* FUN_002a2130(int n); };
struct ShadowTraversal_1c1a40 : public Base_1c1a40 { ShadowTraversal_1c1a40* FUN_002a16c0(int n, int m); };
struct LightsChooser_1c1a40 : public Base_1c1a40 { LightsChooser_1c1a40* FUN_0029f600(int a, int b); void FUN_0029f800(Base_1c1a40* o); };
struct LightGroup_1c1a40 : public Base_1c1a40 { LightGroup_1c1a40* FUN_002a1140(int n); };
struct AmbientLight_1c1a40 : public Base_1c1a40 { AmbientLight_1c1a40* FUN_002a1230(); void FUN_002a07a0(unsigned int color); };
struct ObjG : public Base_1c1a40 { ObjG* FUN_00292d70(); };

void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

class Display_1c1a40 {
  public:
    virtual void v0();
};
class Gfx {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual pure3d::pddiExtension* s89(int id);
};

struct Plane_1c1a40 { float a, b, c, d; };

class SubObj_1c1a40 {
  public:
    char pad0[4];
    Plane_1c1a40 planes[6];
    char pad70[0xac - 0x64];
    void FUN_001c2760();
    void FUN_001c2770(int a, int b);
};

class Hud_1c1a40 {
  public:
    int field0;
    View_1c1a40* root;
    ObjG* objG;
    SubObj_1c1a40 sub;
    int fieldb8;
    Owner_1c1a40* owner;
    LightsChooser_1c1a40* objc0;
    LightsChooser_1c1a40* objc4;
    LightGroup_1c1a40* objc8;
    char padcc[3];
    char flagcf;
    int fieldd0;
    int fieldd4;
    char flagd8;
    char flagd9;
    char paddc[2];
    unsigned int colordc;
    char pade0[4];
    float fe4;
    float fe8;
    unsigned int colorec;
    ShadowTraversal_1c1a40* objf0;
    int ff4[6];
    Hud_1c1a40* FUN_001c1a40();
};

Hud_1c1a40* Hud_1c1a40::FUN_001c1a40() {
    field0 = 0;
    sub.FUN_001c2760();
    fieldb8 = 0;
    flagcf = 1;
    fieldd0 = 0;
    fieldd4 = 0;
    flagd8 = 1;
    flagd9 = 1;
    colordc = 0xff808080;
    fe4 = 50.0f;
    fe8 = 650.0f;
    colorec = 0xffcfcfcf;
    sub.FUN_001c2770(6, 0);
    sub.planes[0].a = 0; sub.planes[0].b = 0; sub.planes[0].c = -1.0f; sub.planes[0].d = 0;
    sub.planes[1].a = 0; sub.planes[1].b = 0; sub.planes[1].c = 1.0f; sub.planes[1].d = -1.0f;
    sub.planes[2].a = 0; sub.planes[2].b = -1.0f; sub.planes[2].c = 0; sub.planes[2].d = 0;
    sub.planes[3].a = 0; sub.planes[3].b = 1.0f; sub.planes[3].c = 0; sub.planes[3].d = -1.0f;
    sub.planes[4].a = -1.0f; sub.planes[4].b = 0; sub.planes[4].c = 0; sub.planes[4].d = 0;
    sub.planes[5].a = 1.0f; sub.planes[5].b = 0; sub.planes[5].c = 0; sub.planes[5].d = -1.0f;
    for (int i = 0; i < 6; i++)
        ff4[i] = 0;

    void* mem = thunk_FUN_0008d690(0x38);
    Owner_1c1a40* o = 0;
    if (mem)
        o = ((Owner_1c1a40*)mem)->FUN_0029bea0(3, 0x400);
    owner = o;
    o->v0();

    mem = FUN_0008d690(0x38);
    OpaqueTraversal_1c1a40* a = 0;
    if (mem)
        a = ((OpaqueTraversal_1c1a40*)mem)->FUN_002a2d50(0x400);
    owner->FUN_0029b690(a);
    a->flag = 1;

    mem = FUN_0008d690(0x34);
    TranslucentTraversal_1c1a40* b = 0;
    if (mem)
        b = ((TranslucentTraversal_1c1a40*)mem)->FUN_002a2130(0x400);
    owner->FUN_0029b690(b);

    mem = FUN_0008d690(0x48);
    ShadowTraversal_1c1a40* c = 0;
    if (mem)
        c = ((ShadowTraversal_1c1a40*)mem)->FUN_002a16c0(0x100, (*(int*)&DAT_0042d5fc));
    objf0 = c;
    owner->FUN_0029b690(c);

    mem = thunk_FUN_0008d690(0x58);
    LightsChooser_1c1a40* d = 0;
    if (mem)
        d = ((LightsChooser_1c1a40*)mem)->FUN_0029f600((*(int*)&DAT_0042d5f8), (*(int*)&DAT_0042d5fc));
    objc0 = d;
    d->v0();

    mem = thunk_FUN_0008d690(0x58);
    d = 0;
    if (mem)
        d = ((LightsChooser_1c1a40*)mem)->FUN_0029f600((*(int*)&DAT_0042d5f8), (*(int*)&DAT_0042d5fc));
    objc4 = d;
    d->v0();

    mem = thunk_FUN_0008d690(0x28);
    LightGroup_1c1a40* e = 0;
    if (mem)
        e = ((LightGroup_1c1a40*)mem)->FUN_002a1140(2);
    objc8 = e;
    e->v0();

    mem = thunk_FUN_0008d690(0x58);
    AmbientLight_1c1a40* f = 0;
    if (mem)
        f = ((AmbientLight_1c1a40*)mem)->FUN_002a1230();
    f->v0();
    f->FUN_002a07a0(0xff4b4b4b);
    objc4->FUN_0029f800(f);
    f->v1();

    mem = thunk_FUN_0008d690(0x58);
    f = 0;
    if (mem)
        f = ((AmbientLight_1c1a40*)mem)->FUN_002a1230();
    f->v0();
    f->FUN_002a07a0(0xff4b4b4b);
    objc0->FUN_0029f800(f);
    f->v1();

    mem = FUN_0008d690(0x140);
    View_1c1a40* r = 0;
    if (mem)
        r = ((View_1c1a40*)mem)->FUN_00294880();
    root = r;
    r->v0();

    mem = thunk_FUN_0008d690(0xd0);
    ObjG* g = 0;
    if (mem)
        g = ((ObjG*)mem)->FUN_00292d70();
    objG = g;
    g->v0();
    root->FUN_00294980(objG);
    objG->v7(0.25f);
    objG->v9(200.0f);
    root->field2c = 0;
    (*(pure3d::pddiExtFramebufferEffects**)&DAT_004e2318) = dynamic_cast<pure3d::pddiExtFramebufferEffects*>(DAT_0052c2a8->s89(0x103));

    mem = FUN_0008d690((int)sizeof(pure3d::GameDrawableInfo));
    pure3d::GameDrawableInfo* info = 0;
    if (mem)
        info = new (mem) pure3d::GameDrawableInfo();
    (*(pure3d::GameDrawableInfo**)&DAT_004e2314) = info;
    info->v0_00018b30();
    return this;
}
} // namespace fn_001c1a40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ffffca36 {

// 0x001c1e90 FUN_001c1e90 (151 B): matches/0x001c1e90.cpp
// sym: ?Shutdown@C_1c1e90@fn_ffffca36@@QAEXXZ
void C_1c1e90::Shutdown() {
    if (mbc) {
        mbc->Rel();
        mbc = 0;
    }
    if (mc0) {
        mc0->Rel();
        mc0 = 0;
    }
    if (mc4) {
        mc4->Rel();
        mc4 = 0;
    }
    if (mc8) {
        mc8->Rel();
        mc8 = 0;
    }
    if (m4) {
        m4->Rel();
        m4 = 0;
    }
    if (m8) {
        m8->Rel();
        m8 = 0;
    }
    if ((*(R_1c1e90**)&DAT_004e2314)) {
        (*(R_1c1e90**)&DAT_004e2314)->Rel();
        (*(R_1c1e90**)&DAT_004e2314) = 0;
    }
    sub.Cleanup_001c27c0();
}


// 0x001c1f30 FUN_001c1f30 (420 B): equivalent/0x001c1f30.cpp
// sym: ?FUN_001c1f30@CameraState@fn_ffffca36@@QAEXHMMHH@Z @6f683b707681 @wdd8705ec58d2
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 2/2)
// FUN_001c1f30 @ 0x001c1f30
void CameraState::FUN_001c1f30(int a, float fov, float aspect, int d, int e)
{
    camera->vfunc_21(a);
    camera->vfunc_5(fov, aspect);
    camera->vfunc_7(d);
    camera->vfunc_9(e);
    if (lastFov != fov) {
        double t = tan(fov * 0.5f) * DAT_004c5114;
        float tf = (float)t;
        halfX = (float)atan(t);
        halfY = (float)atan(tf / ((*(System_1c1f30**)&DAT_0052c2a4)->vfunc_16() * aspect));
        lastFov = fov;
    }
    Plane_1c1f30 tmp;
    camera->vfunc_12(1, &tmp);
    left = tmp;
    camera->vfunc_12(2, &tmp);
    right = tmp;
    camera->vfunc_12(8, &tmp);
    top = tmp;
    camera->vfunc_12(4, &tmp);
    bottom = tmp;
    camera->vfunc_12(0x10, &tmp);
    nearP = tmp;
    camera->vfunc_12(0x20, &tmp);
    farP = tmp;
}


// 0x001c20e0 FUN_001c20e0 (295 B): equivalent/0x001c20e0.cpp
// sym: ?FUN_001c20e0@Target_1c20e0@fn_ffffca36@@QAEHPBUInput_1c20e0@2@@Z @9fd0a96c2b1f @w8e13ce649b91
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 8/8)
// FUN_001c20e0 @ 0x001c20e0
int Target_1c20e0::FUN_001c20e0(const Input_1c20e0* input) {
 Matrix matrix=*object->s13(); Vec_1c20e0 position; ((owners::Mat_22c2b0 *)&matrix)->FUN_0022c2b0((float *)(const Input_1c20e0 *)input, (float *)(Vec_1c20e0 *)(&position));
 if (object->s8()>position.z) return false;
 if (object->s10()<position.z) return false;
 Vec_1c20e0 direction=position; direction.y=0.0f;
 float angularRadius=(float)atan(input->radius/sqrt((double)position.x*position.x+(double)position.y*position.y+(double)position.z*position.z));
 direction.FUN_0022d110();
 if (FUN_00018a20(direction.z)+angularRadius>horizontalLimit) return false;
 direction.x=0.0f; direction.y=position.y; direction.z=position.z;
 direction.FUN_0022d110();
 return !(FUN_00018a20(direction.z)+angularRadius>verticalLimit);
}

} // namespace fn_ffffca36

// 0x001c2210 FUN_001c2210 (211 B): equivalent/0x001c2210.cpp [wrapped: conflict: Gfx; Object]
// sym: ?run@Object@fn_001c2210@@QAEHXZ @9f68b3df41b0 @w8030fe27f295
namespace fn_001c2210 {
// STATUS: equivalent (tools/equiv.py level 3: 2977 inputs, branch coverage 6/6)
// FUN_001c2210 @ 0x001c2210
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

struct Gfx {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void enable(int);
};
struct Material_1c2210 { char pad[0x20]; unsigned color; float scale; unsigned zero; unsigned mode; unsigned otherColor; float low, high; char pad2[0x80]; unsigned char enabled; int FUN_00293ef0(); };
struct Helper_1c2210 {  };
struct Object { unsigned count; Material_1c2210* material; char pad[0xd1]; unsigned char enabled; char pad2[2]; unsigned color; char pad3[4]; float a,b; unsigned value; Helper_1c2210* helper; int run(); };
int Object::run() {
 ++count;
 DAT_0052c2a8->enable(1);
 float lo = a < b ? a : b;
 float hi = a < b ? b : a;
 material->otherColor = color;
 material->low = lo;
 material->high = hi;
 material->enabled = enabled;
 material->color = enabled ? color : 0xff000000;
 ((owners::C_2a1340 *)helper)->FUN_002a1340((int)value);
 material->scale = 1.0f;
 material->zero = 0;
 material->mode = 7;
 return material->FUN_00293ef0();
}
} // namespace fn_001c2210
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ffffca36 {

// 0x001c22f0 FUN_001c22f0 (114 B): matches/0x001c22f0.cpp
// sym: ?Fn@Thing_1c22f0@fn_ffffca36@@QAEXXZ
// data: g_obj_1c22f0 = DAT_004e2318, kZero_1c22f0 = DAT_003f32e0
void Thing_1c22f0::Fn() {
    mSub->FnA_0029bc80(mVal);
    mSub->FnB_0029bb60();
    ((pure3d::DisplayList *)mSub)->FUN_0029bba0();
    if ((*(Obj2_1c22f0**)&DAT_004e2318) && mF != DAT_003f32e0) {
        ((owners::Obj_1c16e0 *)this)->FUN_001c16e0(mF, mG);
        (*(Obj2_1c22f0**)&DAT_004e2318)->v2();
    }
    mParent->Done_00294080();
}

} // namespace fn_ffffca36

// 0x001c23a0 Render::Canvas::HulkShaderCallback::vfunc_2 (31 B): matches/0x001c23a0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001c23a0@@UAEPAV123@E@Z
namespace fn_001c23a0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ShaderCallback_1c23a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public ShaderCallback_1c23a0 {
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
} // namespace fn_001c23a0

namespace fn_ffffca36 {

// 0x001c23c0 FUN_001c23c0 (114 B): equivalent/0x001c23c0.cpp
// sym: _FUN_001c23c0@8 @0e563aa58051 @w46a00d2147a6
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_001c23c0 @ 0x001c23c0
extern "C" void *__stdcall FUN_001c23c0(void *canvas, bool create)
{
    if (((Canvas *)canvas)->callback == 0 && create) {
        HulkShaderCallback *cb = (HulkShaderCallback *)FUN_0008d690((int)sizeof(HulkShaderCallback));
        if (cb) {
            cb->f04 = 0;
            cb->vptr = (hulk_intptr)DAT_004216d4;
            cb->f08 = 0;
            cb->f0c = 1.0f;
            cb->f10 = 0;
            cb->color0 = 0xff000000;
            cb->color1 = 0xff000000;
        }
        ((Canvas *)canvas)->SetCallback(cb);
        return (HulkShaderCallback *)cb;
    }
    return (HulkShaderCallback *)(((Canvas *)canvas)->callback);
}


// 0x001c2440 FUN_001c2440 (139 B): equivalent/0x001c2440.cpp
// sym: ?FUN_001c2440@fn_ffffca36@@YG_NPAVOwner_1c2440@1@M@Z @5e3e4058db8c @w993a92cc6fd6
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 12/12)
// FUN_001c2440 @ 0x001c2440
// Update an entry's value; refresh the owner through its virtual slot unless the entry is still active.
bool __stdcall FUN_001c2440(Owner_1c2440* owner, float value)
{
    Entry_1c2440* e = ((Entry_1c2440 *)FUN_001c23c0((Owner_1c2440 *)owner, value != 0.0f));
    if (e) {
        e->value = value;
        if (value > 0.0f || e->fade > 0.0f || e->weight < 1.0f) {
            return value != 0.0f;
        }
    }
    owner->Refresh();
    return value != 0.0f;
}


// 0x001c24d0 FUN_001c24d0 (115 B): matches/0x001c24d0.cpp
// sym: ?F@fn_ffffca36@@YGXPAVObj_1c24d0@1@HM@Z
void __stdcall F(Obj_1c24d0* o, int a, float t) {
    Ent_1c24d0* e = ((Ent_1c24d0 *)FUN_001c23c0((Obj_1c24d0 *)o, t > 0.0f));
    if (e) {
        e->f14 = a;
        e->f10 = t;
        if (e->f8 > 0.0f)
            return;
        if (t > 0.0f)
            return;
        if (e->fc < 1.0f)
            return;
    }
    o->Fire();
}


// 0x001c2550 FUN_001c2550 (108 B): matches/0x001c2550.cpp
// sym: ?Fn@fn_ffffca36@@YGXPAVObj_1c2550@1@M@Z
void __stdcall Fn(Obj_1c2550* o, float x) {
    Ent_1c2550* e = ((Ent_1c2550 *)FUN_001c23c0((Obj_1c2550 *)o, x < 1.0f));
    if (e) {
        e->v = x;
        if (e->a > 0.0f)
            return;
        if (e->b > 0.0f)
            return;
        if (x < 1.0f)
            return;
    }
    o->Fire();
}


// 0x001c25c0 FUN_001c25c0 (47 B): matches/0x001c25c0.cpp
// sym: ?target@Host_1c25c0@fn_ffffca36@@QAEXPAUObj_1c25c0@2@HH@Z
void Host_1c25c0::target(Obj_1c25c0* p, int a, int b) {
    if (p) {
        helper_001c2440(p, b);
        p->f8(value, a);
    }
}


// 0x001c2650 FUN_001c2650 (78 B): matches/0x001c2650.cpp
// sym: ?fn@Target_1c2650@fn_ffffca36@@QAEXPAVItem_1c2650@2@HH@Z
// data: gRoot_1c2650 = DAT_0052c2ac
void Target_1c2650::fn(Item_1c2650* p, int x, int y) {
    if (p) {
        (*(Root_1c2650**)&DAT_0052c2ac)->m->p(0);
        helper_001c2440(p, y);
        p->i((hulk_intptr)member, x);
        (*(Root_1c2650**)&DAT_0052c2ac)->m->q(0);
    }
}


// 0x001c26a0 FUN_001c26a0 (57 B): matches/0x001c26a0.cpp
// sym: ?target@Owner_1c26a0@fn_ffffca36@@QAEXPAUObj_1c26a0@2@II@Z
void Owner_1c26a0::target(Obj_1c26a0* p, u32_1c26a0 a, u32_1c26a0 b) {
    if (p) {
        FUN_001c2550(p, b);
        helper_001c2440(p, a);
        p->v8(value, 0);
    }
}


// 0x001c2760 FUN_001c2760 (9 B): matches/0x001c2760.cpp
// sym: ??0X_1c2760@fn_ffffca36@@QAE@XZ
X_1c2760::X_1c2760() {
    m = 0;
}


// 0x001c2770 FUN_001c2770 (76 B): equivalent/0x001c2770.cpp
// sym: ?FUN_001c2770@Target@fn_ffffca36@@QAEXIPBUEntry@2@@Z @39833de6bc6c @wfe1396dc41a4
// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 6/6)
// FUN_001c2770 @ 0x001c2770
void Target::FUN_001c2770(uint n, const Entry *source)
{
    count = n;
    if (source) {
        for (uint i = 0; i < count; ++i) {
            entries[i].a = source[i].a;
            entries[i].b = source[i].b;
            entries[i].c = source[i].c;
            entries[i].d = source[i].d;
            entries[i].d = source[i].d;
        }
    }
}


// 0x001c27c0 FUN_001c27c0 (1 B): matches/0x001c27c0.cpp
// sym: ?FUN_001c27c0@fn_ffffca36@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001c27c0(void* /*this, unused: callers pass it (unb4)*/) {}

} // namespace fn_ffffca36

// 0x001c27d0 FUN_001c27d0 (73 B): matches/0x001c27d0.cpp
// sym: ?FUN_001c27d0@C_1c27d0@owners@@QAE_NPAM@Z
bool owners::C_1c27d0::FUN_001c27d0(float* p) {
    int i = count - 1;
    if (i >= 0) {
        float* q = data + i * 4 + 1;
        do {
            hulk_freg s = q[0] * p[1] + q[1] * p[2] + q[-1] * p[0];
            if (!(s <= -q[2]))
                return false;
            --i;
            q -= 4;
        } while (i >= 0);
    }
    return true;
}

namespace fn_ffffca36 {

// 0x001c2820 FUN_001c2820 (74 B): matches/0x001c2820.cpp
// sym: ?FUN_001c2820@Volume@fn_ffffca36@@QAEEPBM@Z
unsigned char Volume::FUN_001c2820(const float* point) {
    for (int i = count - 1; i >= 0; --i) {
        const Plane& p = planes[i];
        hulk_freg dot = p.x * point[0] + p.z * point[2];
        dot += p.y * point[1];
        if (!(dot <= point[3] - p.w))
            return 0;
    }
    return 1;
}


// 0x001c2870 FUN_001c2870 (57 B): matches/0x001c2870.cpp
// sym: ?Find@Container_1c2870@fn_ffffca36@@QAE_NH@Z
bool Container_1c2870::Find(hulk_intptr x) {
    int i = count;
    while (--i >= 0) {
        if (!((owners::Plane_22e080 *)&(items[i]))->FUN_0022e080((const float *)(hulk_uintptr)(int)x))
            return false;
    }
    return true;
}


// 0x001c2940 FUN_001c2940 (553 B): equivalent/0x001c2940.cpp
// sym: _FUN_001c2940 @d449a1494c18 @w69a32d519ffd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 19/20, incomplete)
// FUN_001c2940 @ 0x001c2940
// Intersection line of two planes: dir = a.n x b.n, point = a point on both planes with
// the dominant component of dir set to 0. Returns 1 when the planes are (nearly) parallel.
//
// The x87 runs at 53-bit precision here, so the values the original keeps on the FPU stack
// are written as doubles. Values it stores to a float slot and reloads are volatile floats
// (MSVC would otherwise drop the rounding).
extern "C" int __cdecl FUN_001c2940(const void * a_, const void * b_, void *point, void *dir)
{
    const Plane * a = (const Plane *)a_;
    const Plane * b = (const Plane *)b_;
    volatile float cx = b->nz * a->ny - b->ny * a->nz;
    double cy = (double)b->nx * a->nz - (double)b->nz * a->nx;
    volatile float cz = b->ny * a->nx - b->nx * a->ny;

    volatile float ax = (cx >= 0.0f) ? cx : -cx;
    volatile float ay = (cy >= 0.0) ? (float)cy : (float)-cy;
    float az = (cz >= 0.0f) ? cz : -cz;

    if ((ay + az) + ax < 0.01f)
        return 1;

    int axis;
    if (ax > ay)
        axis = (ax > az) ? 0 : 2;
    else
        axis = (ay > az) ? 1 : 2;

    // k1 = -dot(a.n * -a.d, a.n), k2 = -dot(b.n * -b.d, b.n)
    double nA = -a->d;
    double pAx = nA * a->nx;
    double pAy = nA * a->ny;
    double pAz = nA * a->nz;
    double nB = -b->d;
    volatile float pbx = (float)(nB * b->nx);
    volatile float pby = (float)(nB * b->ny);
    volatile float pbz = (float)(nB * b->nz);
    double k1 = -((pAx * a->nx + pAz * a->nz) + pAy * a->ny);
    double k2 = -(((double)pbz * b->nz + (double)pby * b->ny) + (double)pbx * b->nx);

    volatile float px;
    volatile float py;
    double pz;
    if (axis == 0) {
        double inv = 1.0 / cx;
        px = 0.0f;
        py = (float)((k2 * a->nz - k1 * b->nz) * inv);
        pz = (k1 * b->ny - k2 * a->ny) * inv;
    } else if (axis == 1) {
        double inv = 1.0 / cy;
        py = 0.0f;
        px = (float)((k1 * b->nz - k2 * a->nz) * inv);
        pz = (k2 * a->nx - k1 * b->nx) * inv;
    } else {
        double inv = 1.0 / cz;
        px = (float)((k2 * a->ny - k1 * b->ny) * inv);
        py = (float)((k1 * b->nx - k2 * a->nx) * inv);
        pz = 0.0;
    }

    ((V3 *)point)->x = px;
    ((V3 *)point)->z = (float)pz;
    ((V3 *)point)->y = py;
    ((V3 *)dir)->x = cx;
    ((V3 *)dir)->z = cz;
    ((V3 *)dir)->y = (float)cy;
    return 0;
}


// 0x001c2b80 FUN_001c2b80 (37 B): matches/0x001c2b80.cpp
// sym: ??0X@fn_ffffca36@@QAE@XZ
X::X() {
    for (int i = 0; i < 32; i++)
        e[i].c = 0;
    v = 0;
}


// 0x001c2c20 FUN_001c2c20 (98 B): matches/0x001c2c20.cpp
// sym: ?Add@Obj_1c2c20@fn_ffffca36@@QAEXPBUEntry_1c2c20@2@@Z
void Obj_1c2c20::Add(const Entry_1c2c20* p) {
    for (unsigned i = 0; i < count; ++i) {
        if (((Entry_1c2c20*)this + i)->Check_0022d2b0(p, 0x3727c5ac))
            return;
    }
    Entry_1c2c20* dst = (Entry_1c2c20*)this + count;
    ++count;
    *dst = *p;
}


// 0x001c2c90 FUN_001c2c90 (322 B): equivalent/0x001c2c90.cpp
// sym: ?FUN_001c2c90@PointSet_1c2c90@fn_ffffca36@@QAEPAUVec3_1c2c90@2@PAU32@@Z @a3c9d3a60772 @w0bae8e25d08e
// STATUS: equivalent (tools/equiv.py level 3: 982 inputs, branch coverage 11/12; --wine 623 inputs)
// FUN_001c2c90 @ 0x001c2c90
Vec3_1c2c90 *PointSet_1c2c90::FUN_001c2c90(Vec3_1c2c90 *out)
{
    // The original unrolls by four. x stays in an x87 register (53-bit) across iterations and is stored only after the
    // second and third add; y is stored after the third and fourth; z after each group (see the rounding points below).
    hulk_freg sx = 0.0f;
    volatile float sy = 0.0f;   // volatile: a store/reload (the rounding point) under both compilers
    volatile float sz = 0.0f;
    unsigned int i = 0;
    if (count != 0) {
        if ((int)count >= 4) {
            unsigned int groups = ((count - 4) >> 2) + 1;
            do {
                const Vec3_1c2c90 *p = &points[i];
                hulk_freg x1 = sx + p[0].x;
                volatile float x2 = (float)(x1 + p[1].x);
                volatile float x3 = x2 + p[2].x;
                sx = x3 + p[3].x;
                hulk_freg y1 = sy + p[0].y;
                hulk_freg y2 = y1 + p[1].y;
                volatile float y3 = (float)(y2 + p[2].y);
                sy = y3 + p[3].y;
                volatile float z1 = sz + p[0].z;
                volatile float z3 = (float)((z1 + p[1].z) + p[2].z);
                sz = z3 + p[3].z;
                i += 4;
            } while (--groups);
        }
        for (; i < count; i++) {
            sx = sx + points[i].x;
            sy = sy + points[i].y;
            sz = sz + points[i].z;
        }
        // volatile: the original rounds the reciprocal to float before scaling
        volatile float inv = 1.0f / (float)count;
        out->x = sx * inv;
        out->y = inv * sy;
        out->z = inv * sz;
        return out;
    }
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    return out;
}

} // namespace fn_ffffca36

// 0x001c2e10 FUN_001c2e10 (27 B): equivalent/0x001c2e10.cpp [wrapped: conflict: Object]
// sym: ?FUN_001c2e10@Object@fn_001c2e10@@QAEPAU12@PAUInput@2@@Z @e7a2f1495de2 @we3f6ce800688
namespace fn_001c2e10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c2e10 @ 0x001c2e10
struct Input { int value; int next; };
struct Object {
    int value;
    void FUN_001c2770(int value, int* next);
    Object* FUN_001c2e10(Input* input);
};
Object* Object::FUN_001c2e10(Input* input) {
    value = 0;
    FUN_001c2770(input->value, &input->next);
    return this;
}
} // namespace fn_001c2e10

namespace fn_ffffca36 {

// 0x001c2e70 FUN_001c2e70 (446 B): equivalent/0x001c2e70.cpp
// sym: ?FUN_001c2e70@Hull_1c2e70@fn_ffffca36@@QAE_NPBUPointList@2@@Z @2299f5c9422a @w9fc36f3a57d5
// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 26/34, incomplete)
// FUN_001c2e70 @ 0x001c2e70
bool Hull_1c2e70::FUN_001c2e70(const PointList *pts)
{
    const Vec3_1c2e70 *p = pts->begin;
    hulk_intptr n = pts->end - pts->begin;
    unsigned int total = count;
    for (unsigned int i = 0; i < total; i++) {
        const Plane_1c2e70 *pl = &planes[i];
        bool all = true;
        int j = 0;
        for (; j + 4 <= n; j += 4) {
            const Vec3_1c2e70 *q = &p[j];
            all &= !((q[0].x * pl->a + q[0].z * pl->c) + q[0].y * pl->b <= -pl->d);
            all &= !((q[1].z * pl->c + q[1].x * pl->a) + q[1].y * pl->b <= -pl->d);
            all &= !((q[2].z * pl->c + q[2].y * pl->b) + q[2].x * pl->a <= -pl->d);
            all &= !((q[3].z * pl->c + q[3].y * pl->b) + q[3].x * pl->a <= -pl->d);
        }
        for (; j < n; j++) {
            const Vec3_1c2e70 *q = &p[j];
            all &= !((q->z * pl->c + q->y * pl->b) + q->x * pl->a <= -pl->d);
        }
        if (all)
            return false;
    }
    return true;
}


// 0x001c3030 FUN_001c3030 (1064 B): equivalent/0x001c3030.cpp
// sym: ?FUN_001c3030@Hull_1c3030@fn_ffffca36@@QAEPAUVec3_1c3030@2@PAU32@@Z @8d920eac29bd @wb3e4f1f68cb4
// STATUS: equivalent (tools/equiv.py level 3: 2726 inputs, branch coverage 47/50, incomplete)
// FUN_001c3030 @ 0x001c3030
// Clips every pairwise plane-intersection line against all planes, then returns the centroid of the surviving
// segment end points.
Vec3_1c3030 *Hull_1c3030::FUN_001c3030(Vec3_1c3030 *out)
{
    struct Frame {
        Vec3_1c3030 dir;                    // 0x00
        char pad0c[0x2c - 0x0c];
        Vec3_1c3030 pt;                     // 0x2c
        char pad38[0x60 - 0x38];
        Segment_1c3030 segs[32];            // 0x60
        unsigned int segCount;       // 0x3e0
        PointSet_1c3030 set;                // 0x3e4
    } f;

    for (int k = 0; k < 32; k++)
        f.segs[k].dropped = 0;
    f.segCount = 0;
    f.set.count = 0;

    unsigned int n = count > 6 ? 6 : count;
    unsigned int a;
    unsigned int b;
    for (a = 0; a < n; a++) {
        for (b = a + 1; b < n; b++) {
            if (FUN_001c2940((Plane_1c3030 *)(&planes[a]), (Plane_1c3030 *)(&planes[b]), (Vec3_1c3030 *)(&f.pt), (Vec3_1c3030 *)(&f.dir)) != 0)
                continue;
            f.dir.x = f.dir.x * 10000.0f;
            f.dir.y = f.dir.y * 10000.0f;
            f.dir.z = f.dir.z * 10000.0f;
            Vec3_1c3030 far1;
            far1.x = f.pt.x + f.dir.x;
            far1.y = f.pt.y + f.dir.y;
            far1.z = f.pt.z + f.dir.z;
            f.pt.x = f.pt.x - f.dir.x;
            f.pt.y = f.pt.y - f.dir.y;
            f.pt.z = f.pt.z - f.dir.z;
            if (f.segCount < 32) {
                f.segs[f.segCount].p = f.pt;
                f.segs[f.segCount].q = far1;
                f.segCount++;
            }
        }
    }

    unsigned int s;
    for (s = 0; s < f.segCount; s++) {
        Segment_1c3030 *seg = &f.segs[s];
        int clipped = 0;
        if (n != 0) {
            unsigned int j;
            for (j = 0; j < n; j++) {
                Plane_1c3030 *pl = &planes[j];
                float inP = ((seg->p.z * pl->nz + seg->p.y * pl->ny) + pl->nx * seg->p.x) <= -pl->d ? 1.0f : 0.0f;
                float inQ = ((seg->q.z * pl->nz + seg->q.y * pl->ny) + pl->nx * seg->q.x) <= -pl->d ? 1.0f : 0.0f;
                Vec3_1c3030 *outer;
                if (inP == 0.0f) {
                    if (inQ == 0.0f)
                        continue;
                    outer = &seg->p;
                } else {
                    if (inQ != 0.0f)
                        continue;
                    outer = &seg->q;
                }
                Vec3_1c3030 *inner = outer->FUN_0022d2b0(&seg->p, 1e-5f) ? &seg->q : &seg->p;
                f.dir.x = inner->x - outer->x;
                f.dir.y = inner->y - outer->y;
                f.dir.z = inner->z - outer->z;
                f.dir.FUN_0022d180();
                double den = (f.dir.y * pl->ny + f.dir.x * pl->nx) + f.dir.z * pl->nz;
                FS_1c3030 ad;
                ad.f = (float)den;
                ad.u &= 0x7fffffff;
                double num = -pl->d - ((pl->nz * outer->z + pl->ny * outer->y) + outer->x * pl->nx);
                double t = num / den;
                if (!(ad.f <= 1e-5f) && !(t < 0.0f)) {
                    clipped++;
                    float yy = (float)(f.dir.y * t);
                    float zz = (float)(f.dir.z * t);
                    outer->x = (float)(f.dir.x * t + outer->x);
                    outer->y = yy + outer->y;
                    outer->z = zz + outer->z;
                }
            }
        }
        if (clipped < 2)
            seg->dropped = 1;
    }

    for (s = 0; s < f.segCount; s++) {
        if (f.segs[s].dropped == 0) {
            f.set.FUN_001c2c20(&f.segs[s].p);
            f.set.FUN_001c2c20(&f.segs[s].q);
        }
    }
    f.set.FUN_001c2c90(out);
    return out;
}


// 0x001c34c0 FUN_001c34c0 (68 B): matches/0x001c34c0.cpp
// sym: ??0Obj@fn_ffffca36@@QAE@XZ
Obj::Obj() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    f = 1.3f;
    g = 1.0f;
    h = 1.0f;
    j = 1000.0f;
    b = 0;
    c = 0;
    d = 0;
    x = 0;
    y = 0;
    z = 0;
}


// 0x001c3520 FUN_001c3520 (172 B): equivalent/0x001c3520.cpp
// sym: ?Run@Target_1c3520@fn_ffffca36@@QAEXXZ @203d769584a1 @w90aa87cb6c4b
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 6/6)
// FUN_001c3520 @ 0x001c3520
void Target_1c3520::Run() {
 int old = FUN_00266da0(15);
 MainObject* p = (MainObject*)FUN_0008d690(0x10c);
 object = p ? p->FUN_001c1a40() : 0;
 vec.FUN_0022b980();
 flag = 0;
 pure3d::DirectionalLight* e = (pure3d::DirectionalLight*)FUN_00263ea0(0x68);
 effect = e ? ((DirectionalLight_nv_1c3520*)(((pure3d::DirectionalLight*)(e))))->FUN_002a2e70() : 0;
 effect->vfunc_0();
 ((DirectionalLight_nv_1c3520*)(((pure3d::DirectionalLight*)(effect))))->FUN_002a2ef0(1.0f,-1.0f,1.0f);
 ((DirectionalLight_nv_1c3520*)(((pure3d::DirectionalLight*)(effect))))->FUN_002a07a0(-1);
 pure3d::LightGroup* o = (pure3d::LightGroup*)FUN_00263ea0(0x28);
 other = o ? ((LightGroup_nv_1c3520*)(((pure3d::LightGroup*)(o))))->FUN_002a1140(0) : 0;
 other->vfunc_0();
 FUN_00266da0(old);
}


// 0x001c35d0 FUN_001c35d0 (30 B): matches/0x001c35d0.cpp
// sym: ?vfunc_2@CCollisionAction@fn_ffffca36@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_001c1e90*)(this))->FUN_001c1e90();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001c35f0 FUN_001c35f0 (280 B): matches/0x001c35f0.cpp
// sym: ?FUN_001c35f0@Owner_1c35f0@fn_ffffca36@@QAEXXZ
void Owner_1c35f0::FUN_001c35f0() {
    int previous = FUN_00266da0(15);
    if (initialized) {
        FUN_0023f8c0("Render engine already setup, setup aborted.\n");
        FUN_00266da0(previous);
        return;
    }
    FUN_0023f8c0("Starting render engine setup...\n");
    Render::World* e = (Render::World*)FUN_0008d690(0x768);
    engine = e ? ((World_nv_1c35f0*)(((Render::World*)(e))))->FUN_001c9030() : 0;
    Small_1c35f0* s = (Small_1c35f0*)FUN_0008d690(0x10);
    small = s ? s->FUN_001c5f10() : 0;
    Render::ObjectManager* m = (Render::ObjectManager*)FUN_0008d690(0x250);
    medium = m ? ((ObjectManager_nv_1c35f0*)(((Render::ObjectManager*)(m))))->FUN_001c5840() : 0;
    Render::LevelLoader* r = (Render::LevelLoader*)thunk_FUN_0008d690(0x20);
    r = r ? ((LevelLoader_nv_1c35f0*)(((Render::LevelLoader*)(r))))->FUN_001c8f60(engine, (Owner_1c35f0*)context) : 0;
    (*(Manager_1c35f0**)&DAT_00527c58)->FUN_00265210(r, 0x60000700);
    FUN_0023f8c0("Render engine setup complete\n");
    Item_1c35f0* i = (Item_1c35f0*)FUN_0008d690(0x38);
    item18 = i ? i->FUN_001c49c0() : 0;
    i = (Item_1c35f0*)FUN_0008d690(0x38);
    item14 = i ? i->FUN_001c49c0() : 0;
    item14->active = 1;
    initialized = 1;
    FUN_00266da0(previous);
}

} // namespace fn_ffffca36

// 0x001c3710 FUN_001c3710 (30 B): matches/0x001c3710.cpp [wrapped: same definition as 0x001c35d0 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_001c3710@@UAEPAV12@E@Z
namespace fn_001c3710 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_001c1e90 {
    void FUN_001c5f20();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_001c1e90*)(this))->FUN_001c5f20();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001c3710

namespace fn_ffffca36 {

// 0x001c3740 FUN_001c3740 (35 B): matches/0x001c3740.cpp
// sym: ?f@C_1c3740@fn_ffffca36@@QAEXH@Z
void C_1c3740::f(hulk_intptr x) {
    if (member->check_001c5b00(x))
        ((owners::Obj_1c5b10 *)member)->FUN_001c5b10((unsigned int)x);
}

} // namespace fn_ffffca36

// 0x001c3770 FUN_001c3770 (10 B): matches/0x001c3770.cpp
// sym: ?FUN_001c3770@Thing_1c3770@owners@@QAEXH@Z
// Same code shape as 0x00083d20 (propagated; names are from that function)
void owners::Thing_1c3770::FUN_001c3770(hulk_intptr x) {
    value = ((int)x);
}


// 0x001c37a0 FUN_001c37a0 (68 B): equivalent/0x001c37a0.cpp [wrapped: conflict: Obj]
// sym: ?FUN_001c37a0@Obj@fn_001c37a0@@QAEXIIIIID@Z @d201b3b04639 @wd7bf1fa102be
namespace fn_001c37a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 2/2)
// FUN_001c37a0 @ 0x001c37a0
struct Buffer { unsigned x,y,z; void FUN_001c4390(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e); }; struct Obj { char pad[0x18]; Buffer* buffer; void FUN_001c37a0(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,char enabled); }; void Obj::FUN_001c37a0(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,char enabled) { unsigned value=enabled ? 255 : 0; buffer->x=value; buffer->y=value; buffer->z=value; buffer->FUN_001c4390(a,b,c,d,e); }
} // namespace fn_001c37a0

namespace fn_ffffca36 {

// 0x001c37f0 FUN_001c37f0 (8 B): matches/0x001c37f0.cpp
// sym: ?f@X_1c37f0@fn_ffffca36@@QAEXHHHH@Z
void X_1c37f0::f(int a0, int a1, int a2, int a3) {
    p->Fng_001c4450(a0, a1, a2, a3);
}


// 0x001c3800 FUN_001c3800 (15 B): matches/0x001c3800.cpp
// sym: ?run@Obj_1c3800@fn_ffffca36@@QAEXHHHHH@Z
void Obj_1c3800::run(int a, int b, int c, int d, int e) {
    if (value)
        value->Fnf_001c4390(a, b, c, d, e);
}

} // namespace fn_ffffca36

// 0x001c3810 FUN_001c3810 (15 B): matches/0x001c3810.cpp
// sym: ?FUN_001c3810@C_1c3810@owners@@QAEXHHHH@Z
void owners::C_1c3810::FUN_001c3810(int a, int b, int c, int d) {
    owners::C_1c3810* q = p;
    if (q)
        q->helper(a, b, c, d);
}

namespace fn_ffffca36 {

// 0x001c3830 FUN_001c3830 (7 B): matches/0x001c3830.cpp
// sym: ?g@Outer_1c3830@fn_ffffca36@@QAEXHH@Z
void Outer_1c3830::g(int a0, int a1) {
    p->Fnf_001c16e0(a0, a1);
}


// 0x001c3850 FUN_001c3850 (64 B): matches/0x001c3850.cpp
// sym: ?go@A_1c3850@fn_ffffca36@@QAEXH@Z
void A_1c3850::go(int x) {
    if (enabled) {
        pc->run_001c59e0(x);
        p0->run_001c16c0(x);
        p4->run_001c8590(x);
        p18->run_001c4620(x);
        p14->run_001c4620(x);
    }
}

} // namespace fn_ffffca36

// 0x001c38b0 FUN_001c38b0 (53 B): matches/0x001c38b0.cpp
// sym: ?FUN_001c38b0@Obj_1c38b0@owners@@QAEXMM@Z
void owners::Obj_1c38b0::FUN_001c38b0(float a, float b) {
    if (x != a || y != b) {
        x = a;
        y = b;
        dirty = 0;
    }
}


// 0x001c38f0 FUN_001c38f0 (21 B): matches/0x001c38f0.cpp
// sym: ?FUN_001c38f0@Thing_1c38f0@owners@@QAEXPAH0@Z
void owners::Thing_1c38f0::FUN_001c38f0(int* x, int* y) {
    *x = a;
    *y = b;
}


// 0x001c3910 FUN_001c3910 (53 B): matches/0x001c3910.cpp
// sym: ?FUN_001c3910@Obj_1c3910@owners@@QAEXMM@Z
void owners::Obj_1c3910::FUN_001c3910(float x, float y) {
    if (a != x || b != y) {
        a = x;
        b = y;
        dirty = 0;
    }
}


// 0x001c3950 FUN_001c3950 (21 B): matches/0x001c3950.cpp
// sym: ?FUN_001c3950@Thing_1c3950@owners@@QAEXPAH0@Z
void owners::Thing_1c3950::FUN_001c3950(int* x, int* y) {
    *x = a;
    *y = b;
}


// 0x001c3970 FUN_001c3970 (27 B): matches/0x001c3970.cpp
// sym: ?FUN_001c3970@Obj_1c3970@owners@@QAEXPAI@Z
void owners::Obj_1c3970::FUN_001c3970(u32_1c3970* src) {
    memcpy(data, src, 64);
    flag = 0;
}

namespace fn_ffffca36 {

// 0x001c3990 FUN_001c3990 (4 B): matches/0x001c3990.cpp
// sym: ?target@fn_ffffca36@@YIPAXPAUX_1c3990@1@@Z
void* __fastcall target(X_1c3990* p) {
    return p->pad + 0x1c;
}


// 0x001c39a0 FUN_001c39a0 (4 B): matches/0x001c39a0.cpp
// sym: ?target@fn_ffffca36@@YIPAXPAUX_1c3990@1@@Z
// Same code shape as 0x001c3990 (propagated; names are from that function)
void* __fastcall target(X_1c39a0* p) {
    return p->pad + 0x1c;
}


// 0x001c39b0 FUN_001c39b0 (4 B): matches/0x001c39b0.cpp
// sym: ?FUN_001c39b0@fn_ffffca36@@YIPAUX_1c39b0@1@PAU21@@Z
X_1c39b0* __fastcall FUN_001c39b0(X_1c39b0* self) {
    return (X_1c39b0*)((char*)self + 0x2c);
}


// 0x001c39c0 FUN_001c39c0 (4 B): matches/0x001c39c0.cpp
// sym: ?FUN@fn_ffffca36@@YIPAHPAXH@Z
int* __fastcall FUN(void* p, int) {
    return (int*)((char*)p + 0x3c);
}

} // namespace fn_ffffca36

// 0x001c39d0 FUN_001c39d0 (4 B): matches/0x001c39d0.cpp
// sym: ?FUN_001c39d0@Object_1c39d0@owners@@QAEPAXXZ
void* owners::Object_1c39d0::FUN_001c39d0() {
    return (char*)this + 0x4c;
}

namespace fn_ffffca36 {

// 0x001c39e0 FUN_001c39e0 (88 B): matches/0x001c39e0.cpp
// sym: ?make@Scene@fn_ffffca36@@QAEXHH@Z
void Scene::make(int a, int b) {
    int old = state_00266da0(15);
    void* o = factory->create_001c5900(a, b);
    if (o)
        ((owners::Bag_1c8810 *)owner)->FUN_001c8810((hulk_intptr)o);
    else
        report("Object creation failed!\n");
    state_00266da0(old);
}


// 0x001c3a40 FUN_001c3a40 (88 B): matches/0x001c3a40.cpp
// sym: ?Create@Obj_1c3a40@fn_ffffca36@@QAEXHH@Z
void Obj_1c3a40::Create(int a, int b) {
    void* p = Alloc(15);
    void* q = maker->Make_001c5960(a, b);
    if (q)
        ((owners::Bag_1c8810 *)store)->FUN_001c8810((hulk_intptr)q);
    else
        Print_0023f8c0("Object creation failed!\n");
    Free(p);
}


// 0x001c3b20 FUN_001c3b20 (8 B): matches/0x001c3b20.cpp
// sym: ?Forward@C_1c3b20@fn_ffffca36@@QAEHHH@Z
hulk_intptr C_1c3b20::Forward(hulk_intptr a0, hulk_intptr a1) {
    return mSub->Fn_001c60f0(a0, a1);
}


// 0x001c3b30 FUN_001c3b30 (33 B): matches/0x001c3b30.cpp
// sym: ?target@Obj_1c3b30@fn_ffffca36@@QAEXH@Z
void Obj_1c3b30::target(hulk_intptr param) {
    int r = m->first_001c5fb0(param);
    if (r)
        m->second_001c6000(r);
}


// 0x001c3b80 FUN_001c3b80 (44 B): matches/0x001c3b80.cpp
// sym: ?Target@Obj_1c3b80@fn_ffffca36@@QAEXH@Z
void Obj_1c3b80::Target(hulk_intptr arg) {
    int x = mC->Get_001c59d0(arg);
    if (x) {
        ((owners::C_1c8860 *)m4)->FUN_001c8860(x);
        mC->Finish_001c5a20(arg);
    }
}


// 0x001c3bb0 FUN_001c3bb0 (32 B): matches/0x001c3bb0.cpp
// sym: ?run@C_1c3bb0@fn_ffffca36@@QAEXHH@Z
void C_1c3bb0::run(hulk_intptr a, int b) {
    B_1c3bb0* p = (B_1c3bb0*)member->Fnf_001c59d0(a);
    if (p)
        ((owners::X_1c4d60 *)p)->FUN_001c4d60((unsigned int *)(hulk_uintptr)(int)b);
}


// 0x001c3bd0 FUN_001c3bd0 (28 B): matches/0x001c3bd0.cpp
// sym: ?Target@Obj_1c3bd0@fn_ffffca36@@QAEHH@Z
hulk_intptr Obj_1c3bd0::Target(hulk_intptr arg) {
    int* p = mContext->Lookup_001c59d0(arg);
    if (p)
        return (hulk_intptr)p + 0x30;
    return 0;
}


// 0x001c3c10 FUN_001c3c10 (7 B): matches/0x001c3c10.cpp
// sym: ?Fn@A_1c3c10@fn_ffffca36@@QAEXHH@Z
void A_1c3c10::Fn(int a0, hulk_intptr a1) {
    m->Method_001c1910(a0, a1);
}


// 0x001c3c20 FUN_001c3c20 (61 B): matches/0x001c3c20.cpp
// sym: ?Set@Obj_1c3c20@fn_ffffca36@@QAEXD@Z
void Obj_1c3c20::Set(char value) {
    if (p->flag) {
        if (value == 0)
            h->Stop_001c8250();
        p->flag = value;
    } else {
        p->flag = value;
    }
}


// 0x001c3c90 FUN_001c3c90 (4 B): matches/0x001c3c90.cpp
// sym: ?target@fn_ffffca36@@YIEPAVC_1c3c90@1@@Z
unsigned char __fastcall target(C_1c3c90* self) {
    return self->value;
}

} // namespace fn_ffffca36

// 0x001c3ca0 FUN_001c3ca0 (10 B): matches/0x001c3ca0.cpp
// sym: ?FUN_001c3ca0@C_1c3ca0@owners@@QAEXE@Z
void owners::C_1c3ca0::FUN_001c3ca0(unsigned char x) {
    value = x;
}

namespace fn_ffffca36 {

// 0x001c3cb0 FUN_001c3cb0 (8 B): matches/0x001c3cb0.cpp
// sym: @FUN_001c3cb0@4
extern "C" int __fastcall FUN_001c3cb0(A_1c3cb0* self) {
    return FUN_001c4500(self->m);
}


// 0x001c3cc0 FUN_001c3cc0 (36 B): matches/0x001c3cc0.cpp
// sym: ?f@X_1c3cc0@fn_ffffca36@@QAEXXZ
void X_1c3cc0::f() {
    ((Inner_1c3cc0*)*(hulk_intptr*)this)->Do_001c1f30((hulk_intptr)((char*)this + 0x1c), a, b, c, d);
    done = 1;
}


// 0x001c3d20 FUN_001c3d20 (22 B): matches/0x001c3d20.cpp
// sym: ?run@B_1c3d20@fn_ffffca36@@QAEXXZ
void B_1c3d20::run() {
    if (p)
        p->g();
    p = 0;
}

} // namespace fn_ffffca36

// 0x001c3d90 FUN_001c3d90 (44 B): matches/0x001c3d90.cpp [wrapped: conflict: Obj]
// sym: _FUN_001c3d90
void* operator new(size_t);
namespace fn_001c3d90 {
/* size_t: tree_prelude.h */

class Obj {
  public:
    Obj* Init_001c34c0() throw();
    char pad[0x7c];
};
// (dg1) the singleton's pointer is the game's item DAT_004e231c (records.h: pointer-sized), not a local stand-in that
// only the Wine link bound to it by address (the replay hooks read the item)
extern "C" Obj* FUN_001c3d90() {
    if (!(*(Obj**)&DAT_004e231c)) {
        Obj* p = (Obj*)operator new(sizeof(Obj));
        if (p) {
            (*(Obj**)&DAT_004e231c) = p->Init_001c34c0();
            return (*(Obj**)&DAT_004e231c);
        }
        (*(Obj**)&DAT_004e231c) = 0;
    }
    return (*(Obj**)&DAT_004e231c);
}
} // namespace fn_001c3d90

namespace fn_ffffca36 {

// 0x001c3dc0 FUN_001c3dc0 (73 B): matches/0x001c3dc0.cpp
// sym: ?F@Target_1c3dc0@fn_ffffca36@@QAEXXZ
void Target_1c3dc0::F() {
    First_1c3dc0* p = mFirst;
    if (p) {
        p->Cleanup_001c1e90();
        thunk_FUN_00267090(p);
    }
    mFirst = 0;
    Obj_1c3dc0* a = m70;
    if (a) {
        a->v1();
        m70 = 0;
    }
    Obj_1c3dc0* b = m74;
    if (b) {
        b->v1();
        m74 = 0;
    }
}

} // namespace fn_ffffca36

// 0x001c3e10 FUN_001c3e10 (439 B): equivalent/0x001c3e10.cpp [wrapped: conflict: DAT_004dd6ec; DAT_004dd700; World]
// sym: ?FUN_001c3e10@DebugRender@fn_001c3e10@@QAEXXZ @c2f3b5ce30e3 @w94fbefd405b2
namespace fn_001c3e10 {
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 28/28)
// FUN_001c3e10 @ 0x001c3e10

struct Console_1c3e10 {
    void FUN_0023f730(const char *section);
    void FUN_0023f740();
    char FUN_0023f770(const char *label, int key);
    void FUN_0023f8f0();
};

struct Target_1c3e10 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void SetColor(unsigned int color, int flag);
};

struct DebugView {
};

struct Hub_1c3e10 {
    char pad0[8];
    struct Sink_1c3e10 *sink;
    char pad0c[4];
    DebugView *debug;
};

struct Sink_1c3e10 {
    void FUN_00099310();
};

struct Level_1c3e10 {
    char pad0[0x59c];
    int id;
};

struct World {
    int *FUN_00086270();
};

struct Gpu {
    void FUN_0027ff40(int a, int b);
};

struct Part_1c3e10 {
    void FUN_001c46a0();
};

struct Frame_1c3e10 {
    char pad0[0x10];
    struct Target_1c3e10 *target;
};

struct Viewport;

struct Renderer_1c3e10 {
    char pad0[0xbc];
    int fBc;
    int fC0;
    void FUN_001c1f30(void *a, int b, int c, int d, int e);
    void FUN_001c2210();
    void FUN_001c13c0();
    void FUN_001c1330(int v);
    void FUN_001c2650(void *a, int b, int c);
    void FUN_001c1340();
    void FUN_001c13d0();
    void FUN_001c1400();
    void FUN_001c1410();
    void FUN_001c22f0();
};

struct Linker {
    void FUN_001c88f0(Renderer_1c3e10 *r);
};

struct Child_1c3e10 {
    virtual void v0();
};


#define DAT_004dd6ec (*(World * *)&::DAT_004dd6ec)


#define DAT_004dd700 (*(Hub_1c3e10 * *)&::DAT_004dd700)


extern "C" Gpu *__cdecl FUN_0027f250();
extern "C" void __cdecl FUN_002fa5b0(int v);

class DebugRender {
public:
    Renderer_1c3e10 *renderer;
    Linker *linker;
    char pad08[8];
    Child_1c3e10 *child;
    Part_1c3e10 *partA;
    Part_1c3e10 *partB;
    char area[0x40];
    int f5c;
    int f60;
    int f64;
    int f68;
    char ready;
    char pad6d[2];
    char noOverlay;
    char pad70[8];
    void *extra;

    void FUN_001c3e10();
};

void DebugRender::FUN_001c3e10()
{
    (*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f730("Rendering");
    if (!ready) {
        renderer->FUN_001c1f30(area, f5c, f60, f64, f68);
        ready = 1;
    }
    renderer->FUN_001c2210();
    renderer->FUN_001c13c0();
    linker->FUN_001c88f0(renderer);
    if (extra != 0) {
        renderer->FUN_001c1330(renderer->fC0);
        renderer->FUN_001c2650(extra, 0, 0);
    }
    if (!noOverlay)
        renderer->FUN_001c1340();
    if (*DAT_004dd6ec->FUN_00086270() != 6) {
        int v = renderer->fBc;
        Gpu *gpu = FUN_0027f250();
        gpu->FUN_0027ff40(v, 0);
    }
    renderer->FUN_001c1340();
    DAT_004dd700->sink->FUN_00099310();
    renderer->FUN_001c13d0();
    renderer->FUN_001c1400();
    partB->FUN_001c46a0();
    partA->FUN_001c46a0();
    (*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f740();
    if ((*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f770("Toggle Collision Volumes", 0x76))
        (*(char*)&DAT_004e2321) = !(*(char*)&DAT_004e2321);
    if ((*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f770("Toggle Collision Meshes", 0x6d))
        DAT_004e2320 = !DAT_004e2320;
    if ((*(char*)&DAT_004e2321))
        FUN_002fa5b0((*(hulk_intptr*)&DAT_00554c14));
    if (DAT_004e2320 && DAT_004dd6ec) {
        Level_1c3e10 *level = ((Level_1c3e10 *)((owners::Target_862a0 *)DAT_004dd6ec)->FUN_000862a0());
        if (level) {
            int id = level->id;
            Frame_1c3e10 *f = (Frame_1c3e10 *)((hulk_intptr)((owners::C_1b4420 *)(DAT_004dd700->debug))->FUN_001b4420(id));
            if (f)
                f->target->SetColor(0xff000000, 0);
        }
    }
    (*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f8f0();
    renderer->FUN_001c1410();
    renderer->FUN_001c22f0();
    if (child)
        child->v0();
}
} // namespace fn_001c3e10
#undef DAT_004dd6ec
#undef DAT_004dd700


// 0x001c3fd0 FUN_001c3fd0 (49 B): matches/0x001c3fd0.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_001c3fd0@@YIHPAVObj_1c3fd0@1@@Z
namespace fn_001c3fd0 {
struct Core_1c3fd0 {
    void Init_001c1f30(void*, int, int, int, int);
    int Finish_001c12c0();
};
class Obj_1c3fd0 {
  public:
    Core_1c3fd0* core;
    char pad[0x18];
    int field1;
    char pad2[0x3c];
    int field5c;
    int field60;
    int field64;
    int field68;
    unsigned char flag6c;
};
hulk_intptr __fastcall Target(Obj_1c3fd0* self) {
    if (!self->flag6c) {
        self->core->Init_001c1f30(&self->field1, self->field5c, self->field60, self->field64, self->field68);
        self->flag6c = 1;
    }
    return self->core->Finish_001c12c0();
}
} // namespace fn_001c3fd0


// 0x001c4010 FUN_001c4010 (57 B): matches/0x001c4010.cpp
// sym: ?FUN_001c4010@Thing_1c4010@owners@@QAEHH@Z
int owners::Thing_1c4010::FUN_001c4010(hulk_intptr x) {
    if (!done) {
        (*(Engine_1c4010**)pad)->Init_001c1f30(pad + 0x1c, a, b, c, d);
        done = 1;
    }
    return (*(Engine_1c4010**)pad)->Finish_001c1310(((int)x));
}


// 0x001c4050 FUN_001c4050 (57 B): matches/0x001c4050.cpp
// sym: ?FUN_001c4050@Thing_1c4050@owners@@QAEHH@Z
// Same code shape as 0x001c4010 (propagated; names are from that function)
int owners::Thing_1c4050::FUN_001c4050(hulk_intptr x) {
    if (!done) {
        (*(Engine_1c4050**)pad)->Init_001c1f30(pad + 0x1c, a, b, c, d);
        done = 1;
    }
    return (*(Engine_1c4050**)pad)->Finish_001c20e0(((int)x));
}

namespace fn_ffffca36 {

// 0x001c4090 FUN_001c4090 (38 B): matches/0x001c4090.cpp
// sym: ?set@Owner_1c4090@fn_ffffca36@@QAEXPAVObj_1c4090@2@@Z
void Owner_1c4090::set(Obj_1c4090* p) {
    if (p)
        p->f();
    if (item)
        item->g();
    item = p;
}


// 0x001c40f0 FUN_001c40f0 (22 B): matches/0x001c40f0.cpp
// sym: ?run@B_1c40f0@fn_ffffca36@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c40f0::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c4140 FUN_001c4140 (24 B): matches/0x001c4140.cpp
// sym: ?clear@B_1c4140@fn_ffffca36@@QAEXXZ
void B_1c4140::clear() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c4160 FUN_001c4160 (44 B): matches/0x001c4160.cpp
// sym: ?target@Obj_1c4160@fn_ffffca36@@QAEHE@Z
hulk_intptr Obj_1c4160::target(unsigned char flag) {
    if (member)
        member->f1();
    member = 0;
    if (flag & 1)
        thunk_0008d330(this);
    return (hulk_intptr)this;
}

} // namespace fn_ffffca36

// 0x001c4190 FUN_001c4190 (148 B): equivalent/0x001c4190.cpp [wrapped: conflict: World; content::LoadInventory::DynamicCaster]
// sym: ?FUN_001c4190@Loader_1c4190@fn_001c4190@@QAEXPAUKey_1c4190@2@@Z @6b7ef8b416f3 @w6a207342e476
namespace fn_001c4190 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001c4190 @ 0x001c4190
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

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d { class DrawableHierarchy; }

struct Key_1c4190 {
    unsigned int lo;
    unsigned int hi;
};

class Res_1c4190 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Inventory_1c4190;
struct Holder44_1c4190 {
    Inventory_1c4190 *FUN_00203d70();
};

class Inventory_1c4190 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res_1c4190 *get(void *caster, unsigned int lo, unsigned int hi);
};

struct Holder_1c4190 {
    Holder44_1c4190 *FUN_000862a0();
};

struct World {
    char pad0[0x54];
    Holder_1c4190 *holder;
};

struct Entry_1c4190;

struct Registry_1c4190 {
    void FUN_001c5ae0(Entry_1c4190 *e);
};

struct Entry_1c4190 {
    char pad0[0xc];
    Res_1c4190 *res;
    Entry_1c4190 *FUN_001c5cf0(Key_1c4190 *key, Res_1c4190 *r);
};

extern "C++" __declspec(nothrow) int __cdecl FUN_00266da0(hulk_intptr mode);
extern "C" void *__cdecl FUN_0008d690(unsigned int size);

class Loader_1c4190 {
public:
    char pad0[0xc];
    Registry_1c4190 *registry;
    void FUN_001c4190(Key_1c4190 *key);
};

void Loader_1c4190::FUN_001c4190(Key_1c4190 *key)
{
    int saved = FUN_00266da0(0xf);
    Inventory_1c4190 *inv = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
    Res_1c4190 *res = inv->get(&caster, key->lo, key->hi);
    if (res) {
        Entry_1c4190 *e = (Entry_1c4190 *)FUN_0008d690((int)sizeof(Entry_1c4190));
        if (e)
            e = e->FUN_001c5cf0(key, res);
        if (e->res)
            e->res->Release();
        e->res = 0;
        registry->FUN_001c5ae0(e);
    }
    FUN_00266da0(saved);
}
} // namespace fn_001c4190
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ffffca36 {

// 0x001c4230 FUN_001c4230 (205 B): matches/0x001c4230.cpp
// sym: ?cleanup@Engine_1c4230@fn_ffffca36@@QAEXXZ
void Engine_1c4230::cleanup() {
    (*(Manager_1c4230**)&DAT_00527c58)->FUN_002659a0(0x60000700);
    if (!setup) {
        FUN_0023f8c0("Render engine not yet setup, cleanup aborted.");
        return;
    }
    FUN_0023f8c0("Render engine shutting down.\n");
    Holder_1c4230* h = holder18;
    if (h) {
        Resource_1c4230* r = h->resource;
        if (r)
            r->release();
        h->resource = 0;
        thunk_FUN_00267090(h);
    }
    h = holder14;
    holder18 = 0;
    if (h) {
        Resource_1c4230* r = h->resource;
        if (r)
            r->release();
        h->resource = 0;
        thunk_FUN_00267090(h);
    }
    EnginePart* p = part;
    holder14 = 0;
    if (p) {
        ((owners::Target_1c5f20 *)p)->FUN_001c5f20();
        thunk_FUN_00267090(p);
    }
    Owned_1c4230* o = second;
    part = 0;
    if (o)
        o->destroy(1);
    o = first;
    second = 0;
    if (o)
        o->destroy(1);
    first = 0;
    FUN_0023f8c0("Render engine cleanup done.\n");
    setup = 0;
}

} // namespace fn_ffffca36

// 0x001c4390 FUN_001c4390 (180 B): equivalent/0x001c4390.cpp
// sym: ?FUN_001c4390@State_1c4390@owners@@QAEXMEMEM@Z @92613c07395f @wc52c34970355
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c4390 @ 0x001c4390
void owners::State_1c4390::FUN_001c4390(float target, unsigned char secondEnabled, float secondDuration, unsigned char firstEnabled, float firstDuration) {
 float duration = firstEnabled ? firstDuration : 0.0f;
 if (duration == 0.0f) {
  firstTarget = 1.0f;
  firstValue = 1.0f;
  firstRate = 0.0f;
  firstActive = 0;
 } else {
  firstActive = 1;
  firstTarget = 1.0f;
  firstRate = (1.0f - firstValue) / duration;
 }
 duration = secondEnabled ? secondDuration : 0.0f;
 if (duration == 0.0f) {
  secondTarget = target;
  secondValue = target;
  secondRate = 0.0f;
  secondActive = 0;
 } else {
  secondActive = 1;
  secondTarget = target;
  secondRate = (target - secondValue) / duration;
 }
 dirty = 1;
}


// 0x001c4450 FUN_001c4450 (171 B): equivalent/0x001c4450.cpp
// sym: ?FUN_001c4450@Transition_1c4450@owners@@QAEXEMEM@Z @b33c4fe7382c @wf6bf9cadf490
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c4450 @ 0x001c4450
void owners::Transition_1c4450::FUN_001c4450(unsigned char first, float firstTime, unsigned char second, float secondTime) {
 float duration = second ? secondTime : 0.0f;
 float target = second ? 0.0f : 1.0f;
 target1 = target;
 if (duration == 0.0f) {
  current1 = target;
  rate1 = 0.0f;
  active1 = 0;
 } else {
  active1 = 1;
  rate1 = (target - current1) / duration;
 }
 duration = first ? firstTime : 0.0f;
 target = first ? 0.0f : current2;
 target2 = target;
 if (duration == 0.0f) {
  current2 = target;
  rate2 = 0.0f;
  active2 = 0;
 } else {
  active2 = 1;
  rate2 = (target - current2) / duration;
 }
}

namespace fn_ffffca36 {

// 0x001c4500 FUN_001c4500 (45 B): matches/0x001c4500.cpp
// sym: ?Check@Obj_1c4500@fn_ffffca36@@QAE_NXZ
bool Obj_1c4500::Check() {
    return b != 0.0f && a != 0.0f;
}

} // namespace fn_ffffca36

// 0x001c4580 FUN_001c4580 (150 B): matches/0x001c4580.cpp
// sym: ?FUN_001c4580@Slider_1c4580@owners@@QAEXM@Z
// FUN_001c4580 @ 0x001c4580
// Moves toward the target; stops once the position has passed it.
void owners::Slider_1c4580::FUN_001c4580(float dt)
{
    position += dt * rate;
    float diff = position - target;
    float diffSign = diff < 0.0f ? -1.0f : (diff > 0.0f ? 1.0f : 0.0f);
    float rateSign = rate < 0.0f ? -1.0f : (rate > 0.0f ? 1.0f : 0.0f);
    if (diffSign == rateSign) {
        position = target;
        active = false;
        rate = 0.0f;
    }
}

namespace fn_ffffca36 {

// 0x001c4620 FUN_001c4620 (115 B): equivalent/0x001c4620.cpp
// sym: ?FUN_001c4620@Pair_1c4620@fn_ffffca36@@QAEXH@Z @5c0471a234b1 @wb3b19f93abb7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001c4620 @ 0x001c4620
void Pair_1c4620::FUN_001c4620(int arg)
{
    if (a.flag || b.flag) {
        a.FUN_001c4580(arg);
        b.FUN_001c4580(arg);
        if (!a.flag && !b.flag && (a.f4 == 0.0f || b.f4 == 0.0f)) {
            a.clear();
            b.clear();
        }
    }
}

} // namespace fn_ffffca36

// 0x001c46a0 FUN_001c46a0 (747 B): equivalent/0x001c46a0.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_001c46a0@Bar@fn_001c46a0@@QAEXXZ @a53f15d510d2 @wc26f55ded0ce
namespace fn_001c46a0 {
// STATUS: equivalent (tools/equiv.py level 3: 19783 inputs, branch coverage 12/12)
// FUN_001c46a0 @ 0x001c46a0
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

struct Vertex_1c46a0 {
    char pad0[8];
    float *pos;
    char padc[4];
    unsigned int *color;
    void FUN_0008ef00();
};

struct Surface_1c46a0 {
    char pad0[0x10];
    void *handle;
};

class Device_1c46a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual int Height();
    virtual int Width();
};

class Gfx {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void SetMode(int mode);
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual Vertex_1c46a0 *Begin(void *handle, int a, int b, int c, int d);
    virtual void End(Vertex_1c46a0 *v);
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53();
    virtual void SetA(int v);
    virtual void v55(); virtual void v56(); virtual void v57();
    virtual void SetB(int v);
};

class Stage_1c46a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int S13(int v);
    virtual void v14();
    virtual int S15(int v);
    virtual int S16(int v);
};

extern "C" void __cdecl FUN_000b3c80(int flag);

class Bar {
public:
    int r;
    int g;
    int b;
    char flag0c;
    char pad0d[3];
    Surface_1c46a0 *surface;
    char flag14;
    char pad15[3];
    float alpha;
    char pad1c[8];
    char flag24;
    char pad25[3];
    float fraction;
    char pad2c[8];
    char flag34;

    void FUN_001c46a0();
};

void Bar::FUN_001c46a0()
{
    if (fraction != 0.0f && alpha != 0.0f) {
        hulk_freg width = (float)(*(Device_1c46a0**)&DAT_0052c2a4)->Width();
        float height = (float)(*(Device_1c46a0**)&DAT_0052c2a4)->Height();
        hulk_freg frac = fraction;
        hulk_freg half = height * 0.5f;
        DAT_0052c2a8->SetMode(2);
        DAT_0052c2a8->SetA(0);
        DAT_0052c2a8->SetB(0);
        (*(*(Stage_1c46a0***)&DAT_0052c2ac))->S15(0);
        (*(*(Stage_1c46a0***)&DAT_0052c2ac))->S13(0);

        unsigned int color = (int)(alpha * 255.0f);
        color = (((color << 8) | r) << 8 | g) << 8 | b;

        Vertex_1c46a0 *v = DAT_0052c2a8->Begin(surface->handle, 1, 0x2020, 4, 0);
        float split = frac * half;
        v->color[0] = color;
        v->pos[0] = 0.0f;
        v->pos[1] = split;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        v->color[0] = color;
        v->pos[0] = 0.0f;
        v->pos[1] = 0.0f;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        v->color[0] = color;
        v->pos[0] = width;
        v->pos[1] = split;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        v->color[0] = color;
        v->pos[0] = width;
        v->pos[1] = 0.0f;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        DAT_0052c2a8->End(v);

        Vertex_1c46a0 *w = DAT_0052c2a8->Begin(surface->handle, 1, 0x2020, 4, 0);
        hulk_freg rest = height - split;
        w->color[0] = color;
        w->pos[0] = 0.0f;
        w->pos[1] = rest;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        w->color[0] = color;
        w->pos[0] = width;
        w->pos[1] = rest;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        w->color[0] = color;
        w->pos[0] = 0.0f;
        w->pos[1] = height;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        w->color[0] = color;
        w->pos[0] = width;
        w->pos[1] = height;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        DAT_0052c2a8->End(w);

        (*(*(Stage_1c46a0***)&DAT_0052c2ac))->S16(0);
        DAT_0052c2a8->SetMode(0);
        DAT_0052c2a8->SetA(1);
        DAT_0052c2a8->SetB(1);
        return;
    }
    if (flag24 || flag14 || !flag34 || !flag0c)
        return;
    FUN_000b3c80(1);
    flag34 = 0;
}
} // namespace fn_001c46a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

