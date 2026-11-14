// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x002b87d0..0x002bd430 (kind game, layer engine, confidence high), dominant class pure3d::BillboardQuad
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fff84c72 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fff84c72 {} using namespace fn_fff84c72;
namespace fn_fff84c72 { extern "C" char DAT_0042e724[], DAT_0042e7d4[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_fff84c72 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fff84c72 {
struct Mat4_2b8840 {
    float m[16];
};
struct Range_2b8840 {
    float lo;
    float hi;
};
struct Vec3_2b8840 {
    float x, y, z;
    bool FUN_0022d2b0(Vec3_2b8840 *other, float eps);
    void FUN_0022d180();
};
struct Mat4_2b8b30 {
    float m[16];
};
struct Range_2b8b30 {
    float lo;
    float hi;
};
struct Vec3_2b8b30 {
    float x, y, z;
    bool FUN_0022d2b0(Vec3_2b8b30 *other, float eps);
    void FUN_0022d180();
};
struct Mat4_2b8f60;
struct Vec3_2b8f60 {
    float x, y, z;
};
struct Mat4_2b8f60 {
    float m[16];
};
class Box_2b8f60 {
public:
    char pad00[0x80];
    float halfX;
    float halfY;
    float depth;
    void FUN_002b8f60(Vec3_2b8f60* corners, Mat4_2b8f60* local, Mat4_2b8f60* world, hulk_intptr unused, float scale);
};
struct V3_2b90e0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Node {
    char pad0[0x30];
    V3_2b90e0 pos;
};
struct Quad_2b90e0 {
    V3_2b90e0 corner[4];
};
class Billboard_2b90e0 {
public:
    char pad0[0x80];
    float halfWidth;
    float halfHeight;
    float pull;
    unsigned char fixedSize;
    void FUN_002b90e0(Quad_2b90e0 *out, Node *from, Matrix *m, Node *target, float size);
};
struct Vec3_2b9230 { float x,y,z; };
struct Object { char pad[0x30]; Vec3_2b9230 position; };
struct Matrix {
  public:
    float m[16];
    void FUN_0022b980();
    void FUN_0022ccf0(Vec3_2b9230*);
};
struct Owner_2b9230 { char pad[0x40]; Matrix matrix; int FUN_002b8f60(void*, Matrix*, void*, Object*, void*); int target(void*, Object*, void*, Object*, void*); };
struct RandomState_2b93f0 {
 unsigned int first;
 unsigned int second;
};
class ParamValue_2b95b0 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class ParamValue_2b9640 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
extern "C" char DAT_0042e764[];
struct Alloc_2b9660 {
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
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    void init_002a4e40(pure3d::BillboardObject*);
};
class RenderObjectLoader_2b96a0 {
  public:
    RenderObjectLoader_2b96a0();
    virtual void A();
};
class BillboardQuadGroupLoader : public RenderObjectLoader_2b96a0 {
  public:
    BillboardQuadGroupLoader();
    virtual void A();
};
class Base_2b96d0 {
  public:
    Base_2b96d0();
    virtual void F();
    int x;
};
class OldBillboardQuadGroupLoader : public Base_2b96d0 {
  public:
    OldBillboardQuadGroupLoader();
    virtual void F();
};
extern void* hulk_at_0042e724[];
class Entity_2b98a0 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class BillboardQuad_2b98a0 : public Entity_2b98a0 {
  public:
    BillboardQuad_2b98a0* vfunc_5(signed char flags);
};
struct Mat4_2b98d0 {
    float m[16];
    void FUN_0022b980();
};
struct Vec3_2b98d0 {
    float x, y, z;
    void FUN_0022d180();
};
hulk_freg FUN_00018a20(float x);
class Box_2b98d0 {
public:
    void FUN_002b8f60(Mat4_2b98d0 *a, Mat4_2b98d0 *b, Mat4_2b98d0 *c, Mat4_2b98d0 *d, float scale);
    void FUN_002b98d0(Mat4_2b98d0 *a, Mat4_2b98d0 *c, Mat4_2b98d0 *b, Mat4_2b98d0 *d, float scale);
};
extern void* BillboardQuad_2b9cb0_vftable[];
class BillboardQuad_2b9cb0 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class BillboardCutOffQuad_2b9cb0 : public BillboardQuad_2b9cb0 {
  public:
    BillboardCutOffQuad_2b9cb0* vfunc_5(signed char flags);
};
struct Mat4_2b9ce0 {
    float m[16];
};
struct V3_2b9ce0 {
    float x, y, z;
};
extern "C" void __cdecl FUN_002b8840(float *, float *, int, void *, void *, void *, void *);
extern "C" void __cdecl FUN_002b8b30(float *, float *, int, void *, void *, void *, void *);
extern "C" void __cdecl FUN_002b8e20(float *, int, float *, float);
class BillboardCutOffQuad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad04[0x38 - 4];
    char enabled;            // after pad
    char pad39[0xc8 - 0x39];
    unsigned f_c8;
    unsigned f_cc;
    unsigned f_d0;
    float f_d4[2];
    float f_dc[2];
    float f_e4[2];
    float f_ec[2];
    float f_f4;
    float f_f8;
    float f_fc;
    float f_100;
    float f_104;

    void FUN_002b9ce0(float *outA, float *outB, Mat4_2b9ce0 *from, Mat4_2b9ce0 *to);
};
class Ref_2b9ee0 {
  public:
    virtual void F0();
    virtual void F1();
};
struct Entry { char pad[8]; int first; int second; };
struct Target { char pad[0x8c]; Entry **begin; Entry **end; Entry *FUN_002ba1a0(int first, int second); };
struct Vec3_2ba220 {
    float x, y, z;
};
struct Mesh_2ba220 {
    char pad00[8];
    Vec3_2ba220 *verts;
    char pad0c[4];
    unsigned int *colors;
    void FUN_0008ef00();
};
class Layer_2ba220 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
};
class Obj_2ba220 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int a);
    virtual int v4(int a);
};
class ObjQuery {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};
} // namespace fn_fff84c72
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
    virtual Mesh_2ba220* v30(Handle* h, int a, int b, int count, int c);
    virtual void v31(Mesh_2ba220* m);
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
    virtual void v56(int a, int b, int c, int d);
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62(int f);
    virtual unsigned char v63();
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
    virtual Obj_2ba220* v89(int id);
};
namespace fn_fff84c72 {
class Xform_2ba220 {
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
    virtual void v23(Vec3_2ba220 *in, Vec3_2ba220 *out);
};
struct Scene_2ba220 {
    char pad00[0x18];
    Xform_2ba220 *xf;
    void FUN_002940d0(const Vec3_2ba220 *in, Vec3_2ba220 *out);
    void FUN_00294670(Vec3_2ba220 v, Vec3_2ba220 *p);
};
struct Display_2ba220 {
    Layer_2ba220 *layer;
};
struct Camera {
    char pad00[8];
    Scene_2ba220 *scene;
    Matrix *FUN_0028faa0();
};
extern "C" int __cdecl FUN_0034483c();
class BillboardQuadGroup {
public:
    char pad00[0x70];
    Vec3_2ba220 pos70;
    hulk_freg FUN_002ba220();
};
extern void* hulk_at_0042e764[];
class DrawableContainer_2ba810 {
  public:
    void Destroy_002a4ff0(); // FUN_00236d60, __thiscall, this in ecx
};
class BillboardObject_2ba810 : public DrawableContainer_2ba810 {
  public:
    BillboardObject_2ba810* vfunc_5(signed char flags);
};
struct V {
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
    virtual void f16(int);
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23(int, void*);
};
struct Inner_2ba840 {
    V* v;
    char pad[0x7c];
    unsigned int x;
};
struct Obj_2ba840 {
    Inner_2ba840* p;
};
struct BillboardObject_nv_2ba840 {
    void helper_002a41e0(unsigned int, unsigned int);
};
extern V** hulk_at_0052c2ac;
extern void* hulk_at_0042e7b4[];
class RenderObjectLoader_2ba8a0 {
  public:
    void Destroy_002a3e90(); // FUN_00236d60, __thiscall, this in ecx
};
class BillboardQuadGroupLoader_2ba8a0 : public RenderObjectLoader_2ba8a0 {
  public:
    BillboardQuadGroupLoader_2ba8a0* vfunc_5(signed char flags);
};
struct NameHolder_2ba8d0 {
    char pad[8];
};
struct Sub40_2ba8d0 {
    char pad[0x40];
    void FUN_0022ba20(const void *q);
};
struct Obj_2ba8d0 {
    char pad0[8];
    NameHolder_2ba8d0 nameHolder;      // 0x08
    char pad10[0x3c - 0x10];
    int f3c;
    Sub40_2ba8d0 f40;
    float f80;
    float f84;
    int f88;
    bool b8c;
    char pad8d[3];
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    union {
        int fa8;
        float fa8f;
    };
    int fac;
    union {
        int fb0;
        float fb0f;
    };
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    unsigned int fc4;
    int fc8;
    int fcc;
    int fd0;
    float fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0;
    int ff4, ff8, ffc, f100, f104, f108;
};
struct BillboardCutOffQuad_2ba8d0 : Obj_2ba8d0 {
    BillboardCutOffQuad_2ba8d0 *FUN_002b9520();
};
struct BillboardQuad_2ba8d0 : Obj_2ba8d0 {
    BillboardQuad_2ba8d0 *FUN_002b8e80();
};
extern "C" int __cdecl FUN_002b87d0(int v);
extern "C" int __cdecl FUN_002b8800(int v);
struct Frame_2ba8d0 {
    char pad0[3];
    char flag;          // 0x03
    int t1a4;           // 0x04
    int t1a0;           // 0x08
    int t19c;           // 0x0c
    int t198;           // 0x10
    int t194;           // 0x14
    int t190;           // 0x18
    int t18c;           // 0x1c
    int t188;           // 0x20
    int t184;           // 0x24
    int t180;           // 0x28
    int t17c;           // 0x2c
    int t178;           // 0x30
    int t174;           // 0x34
    int t170;           // 0x38
    int t16c;           // 0x3c
    int t168;           // 0x40
    int t164;           // 0x44
    int t160;           // 0x48
    int t15c;           // 0x4c
    int t158;           // 0x50
    int t154;           // 0x54
    int t150;           // 0x58
    int t14c;           // 0x5c
    int t148;           // 0x60
    int t144;           // 0x64
    int t140;           // 0x68
    int t13c;           // 0x6c
    int t138;           // 0x70
    int t134;           // 0x74
    int t130;           // 0x78
    int t12c;           // 0x7c
    int t128;           // 0x80
    int t124;           // 0x84
    int t120;           // 0x88
    int t11c[3];        // 0x8c
    int q110[4];        // 0x98
    char name[0x100];   // 0xa8
};
extern void* hulk_at_0042e7d4[];
extern void* hulk_at_003f6098[];
class Ref_2bb050 {
  public:
    virtual void F0();
    virtual void Release();
};
class BillboardObjectLoader_2bb050 {
  public:
    void* vptr;
    char pad[0x10];
    Ref_2bb050* m14;
    ~BillboardObjectLoader_2bb050();
};
extern void* hulk_at_0042e7c4[];
class RenderObjectLoader_2bb080 {
  public:
    void Destroy_002a3e90(); // FUN_00236d60, __thiscall, this in ecx
};
class OldBillboardQuadGroupLoader_2bb080 : public RenderObjectLoader_2bb080 {
  public:
    OldBillboardQuadGroupLoader_2bb080* vfunc_5(signed char flags);
};
struct Name {
    char data[8];
};
struct Xform {
    void FUN_0022ba20(float *quat);
};
struct Base {
    char pad0[8];
    Name name;
    char pad10[0x3c - 0x10];
    int v3c;
    Xform xf;
    char pad40[0x80 - 0x40 - sizeof(Xform)];
    float f80;
    float f84;
    int i88;
    bool b8c;
    char pad8d[3];
    int i90;
    char pad94[4];
    int m98[8];
    int b8[2];
    char padc0[8];
    int ic8;
    int icc;
    Base *FUN_002b8e80();
};
struct BillboardCutOffQuad_2bb0b0 : public Base {
    char padd0[4];
    int d4;
    int d8;
    int dc;
    int e0;
    int e4;
    int e8;
    int ec;
    int f0;
    char padf4[0x110 - 0xf4];
    BillboardCutOffQuad_2bb0b0 *FUN_002b9520();
};
union FI {
    float f;
    int i;
};
struct Frame {
    char pad0[3];
    bool flag;
    FI f4;
    FI f8;
    char pad0c[3];
    unsigned char len;
    int v16;
    float v20;
    int v24;
    int v28;
    int v32;
    unsigned int type;
    float v40;
    int id44;
    int v48;
    float pos[3];
    float quat[4];
    int w80[2];
    int m88[8];
    int dummy120[4];
    char name[256];
};
extern void* hulk_at_0042e7f0[];
class Ref_2bb5c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_2bb5c0 {
  public:
    void* vptr;
};
class OldBillboardObjectLoader_2bb5c0 : public SimpleChunkHandler_2bb5c0 {
  public:
    char pad[0x10];
    Ref_2bb5c0* m;
    ~OldBillboardObjectLoader_2bb5c0();
};
extern void* g_vftable_2bc430[];
} // namespace fn_fff84c72
void operator delete(void*);
namespace fn_fff84c72 {
class Ref_2bc430 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_2bc430 {
  public:
    void* vptr;
};
class BillboardObjectLoader_2bc430 : public SimpleChunkHandler_2bc430 {
  public:
    char pad[0x10];
    Ref_2bc430* m14;
    BillboardObjectLoader_2bc430* f2(unsigned char flags);
};
extern "C" char DAT_0042e7f0[];
class SimpleChunkHandler_2bc4d0 {
  public:
    virtual void A();
    virtual void B();
};
class OldBillboardObjectLoader : public SimpleChunkHandler_2bc4d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual OldBillboardObjectLoader* v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x14 - sizeof(SimpleChunkHandler_2bc4d0)];
    SimpleChunkHandler_2bc4d0* volatile mRef;
};
extern void __cdecl thunk_00263f30(OldBillboardObjectLoader*);
extern "C" void* FUN_0008d6d0(unsigned int);
extern "C" int * __cdecl FUN_002bb600(int *, int, const int *);
extern void* hulk_at_0042e80c[];
class Ref_2bc5d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2bc5d0 {
  public:
    void* vptr;
    void Fin_002a50a0();
};
class BillboardQuadGroup_2bc5d0 : public DrawablePrimitive_2bc5d0 {
  public:
    char pad[0x80];
    Ref_2bc5d0* m84;
    char pad2[4];
    Ref_2bc5d0** b;
    Ref_2bc5d0** e;
    ~BillboardQuadGroup_2bc5d0();
};
extern void* hulk_at_0042e840[];
class BillboardQuadGroup_2bc760 {
  public:
    void Destroy_002bc5d0(); // FUN_00236d60, __thiscall, this in ecx
};
class BillboardCutOffQuadGroup_2bc760 : public BillboardQuadGroup_2bc760 {
  public:
    BillboardCutOffQuadGroup_2bc760* vfunc_5(signed char flags);
};
} // namespace fn_fff84c72
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_fff84c72 {
struct Vec3_2bc790 {
    float x, y, z;
};
} // namespace fn_fff84c72
namespace pure3d {
class Shader_2bc790;
}
namespace content {
struct LoadInventory_2bc790 {
    template <class T>
    class DynamicCaster {
    public:
        virtual void *v0() { return 0; }
    };
};
}
namespace fn_fff84c72 {
class Stream_2bc790 {
public:
};
class Reader_2bc790 {
public:
    char pad00[0x284];
    Stream_2bc790 *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
class NameHolder_2bc790 {
public:
    char pad00[8];
};
class Child_2bc790 {
public:
    virtual void v0();
    virtual void v1();
};
class ChildList_2bc790 {
public:
    Child_2bc790 **begin;
    char pad04[8];
};
class Mat4_2bc790 {
public:
    float m[16];
    void FUN_0022ba20(const float *q);
};
class BillboardCutOffQuadGroup_2bc790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void *shader);
    char pad04[4];
    NameHolder_2bc790 name;
    char pad10[4];
    Vec3_2bc790 v14;
    Vec3_2bc790 v20;
    Vec3_2bc790 v2c;
    int i38;
    char pad3c[0x40 - 0x3c];
    Mat4_2bc790 mat40;
    char pad80[0x88 - 0x80];
    char b88;
    char b89;
    char b8a;
    char pad8b[1];
    ChildList_2bc790 list;
    int f98;
    int f9c;
    int fa0;
    float fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0;
    int fc4, fc8;
    char padcc[4];
    BillboardCutOffQuadGroup_2bc790 *FUN_002bc580();
    BillboardCutOffQuadGroup_2bc790 *FUN_002bc660();
};
struct Shader_nv_2bc790 {
    ::pure3d::Shader *FUN_0028edf0(const char *what, int flag);
};
class Factory_2bc790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ::pure3d::Shader *v3(content::LoadInventory_2bc790::DynamicCaster<pure3d::Shader_2bc790> *caster, unsigned __int64 id);
};
struct Parent_2bc790 {
    char pad00[8];
    NameHolder_2bc790 name;
    char pad10[0x40 - 0x10];
    float f40;
    char pad44[4];
    void *p48;
};
void *FUN_00263ea0(unsigned int size);
extern "C" void FUN_0028fcc0(const char *fmt, ...);
struct Frame_2bc790 {
    unsigned char pad10[3];
    unsigned char len;               // S+0x13 (byte count, then the type flag)
    int count;                       // 0x14
    int idx;                         // 0x18
    int slot1c;                      // 0x1c
    void *self;                      // 0x20
    float f;                         // 0x24
    unsigned int tag2;               // 0x28
    float c4;                        // 0x2c
    float c1;                        // 0x30
    float c0;                        // 0x34
    float c3;                        // 0x38
    float d1;                        // 0x3c
    float d2;                        // 0x40
    unsigned int e4;                 // 0x44
    float d3;                        // 0x48
    unsigned int e3;                 // 0x4c
    float c2;                        // 0x50
    unsigned int tag1;               // 0x54
    unsigned int e2;                 // 0x58
    float junkA;                     // 0x5c
    int junk2;                       // 0x60
    float j3;                        // 0x64
    float j4;                        // 0x68
    float j5;                        // 0x6c
    Vec3_2bc790 pos;                        // 0x70
    float q4[4];                     // 0x7c
    unsigned int name1[64];          // 0x8c
    unsigned int name2[64];          // 0x18c
};
class Group_2bc790 {
public:
    void FUN_002a46d0(void *a, BillboardCutOffQuadGroup_2bc790 *q);
    Child_2bc790 *FUN_002ba8d0(Reader_2bc790 *r, Factory_2bc790 *factory);
    void FUN_002a4b00(void *a, Reader_2bc790 *r, Factory_2bc790 *factory);
    void FUN_002bc790(Parent_2bc790 *parent, Reader_2bc790 *r, Factory_2bc790 *factory);
};
struct Chunk_2bceb0 {
    int Id_00266c30();
};
extern int g_vt_2bceb0;
struct BO {
    void InitBase_002a4e10(int);
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
    virtual void Init();
    int a;
    int b;
    int c;
    char pad[0x48];
    float f;
};
struct Helper_2bceb0 {
    void Fill_002bc790(BO*, Chunk_2bceb0*, hulk_intptr);
};
} // namespace fn_fff84c72
void* operator new(size_t);
namespace fn_fff84c72 {
struct Vec3_2bcf30 {
    float x, y, z;
};
} // namespace fn_fff84c72
namespace pure3d {
class Shader_2bcf30;
}
namespace content {
struct LoadInventory_2bcf30 {
    template <class T>
    class DynamicCaster {
    public:
        virtual void *v0() { return 0; }
    };
};
}
namespace fn_fff84c72 {
class Stream_2bcf30 {
public:
};
class Reader_2bcf30 {
public:
    char pad00[0x284];
    Stream_2bcf30 *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
class NameHolder_2bcf30 {
public:
    char pad00[8];
};
class Child_2bcf30 {
public:
    virtual void v0();
    virtual void v1();
};
class ChildList_2bcf30 {
public:
    Child_2bcf30 **begin;
    char pad04[8];
};
class Quad_2bcf30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void *shader);
    char pad04[4];
    NameHolder_2bcf30 name;
    char pad10[4];
    Vec3_2bcf30 v14;
    Vec3_2bcf30 v20;
    Vec3_2bcf30 v2c;
    int i38;
    char pad3c[0x88 - 0x3c];
    char b88;
    char b89;
    char b8a;
    char pad8b[1];
    ChildList_2bcf30 list;
    Quad_2bcf30 *FUN_002bc580();
};
struct Shader_nv_2bcf30 {
    ::pure3d::Shader *FUN_0028edf0(const char *what, int flag);
};
class Factory_2bcf30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ::pure3d::Shader *v3(content::LoadInventory_2bcf30::DynamicCaster<pure3d::Shader_2bcf30> *caster, unsigned __int64 id);
};
struct Parent_2bcf30 {
    char pad00[8];
    NameHolder_2bcf30 name;
    char pad10[0x40 - 0x10];
    float f40;
    char pad44[4];
    void *p48;
};
struct Frame_2bcf30 {
    unsigned char pad10[3];
    unsigned char len;
    int count;
    unsigned char pad18[3];
    unsigned char flag3;
    int slot1c;
    int idx;
    float f;
    void *self;
    int junk;
    unsigned int name1[64];
    unsigned int name2[64];
};
class Group_2bcf30 {
public:
    void FUN_002a46d0(void *a, Quad_2bcf30 *q);
    Child_2bcf30 *FUN_002bb0b0(Reader_2bcf30 *r, Factory_2bcf30 *factory);
    void FUN_002a4b00(void *a, Reader_2bcf30 *r, Factory_2bcf30 *factory);
    void FUN_002bcf30(Parent_2bcf30 *parent, Reader_2bcf30 *r, Factory_2bcf30 *factory);
};
struct Stream {
  public:
    char _m_pad_0[0x284];
    Reader *reader;
    int FUN_002647e0(void *buf, int count, int size, int flag);
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
struct Reader {
  public:
    char _m_pad_0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};


// 0x002b87d0 FUN_002b87d0 (47 B): matches/0x002b87d0.cpp
// sym: _FUN_002b87d0
extern "C" int FUN_002b87d0(int x) {
    if (x != 0x48544f42) {
        if (x != 0x54524556) {
            return (x == 0x545a5248) ? 2 : 0;
        }
        return 1;
    }
    return 3;
}


// 0x002b8800 FUN_002b8800 (47 B): matches/0x002b8800.cpp
// sym: _FUN_002b8800
// Same code shape as 0x002b87d0 (propagated; names are from that function)
extern "C" int FUN_002b8800(int x) {
    if (x != 0x48544f42) {
        if (x != 0x54524556) {
            return (x == 0x545a5248) ? 2 : 0;
        }
        return 1;
    }
    return 3;
}


// 0x002b8840 FUN_002b8840 (748 B): equivalent/0x002b8840.cpp
// sym: _FUN_002b8840 @2067ba308e2a @wfca07bb150bc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002b8840 @ 0x002b8840
// Cone falloff of the two local axes (bits 0 and 1 of flags) relative to the direction `axis`.
extern "C" void FUN_002b8840(float *out1, float *out2, int flags, void *range1, void *range2, void *m, void * axis_)
{
    Vec3_2b8840 * axis = (Vec3_2b8840 *)axis_;
    *out1 = 1.0f;
    *out2 = 1.0f;
    if (flags == 0)
        return;

    struct Frame { Vec3_2b8840 v; Vec3_2b8840 w; Vec3_2b8840 u; Vec3_2b8840 x; float pad[12]; } fr;
    Vec3_2b8840 &v = fr.v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    ((owners::Obj_22d260 *)&v)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b8840 *)(((Mat4_2b8840 *)m)));
    if (axis->FUN_0022d2b0(&v, 1e-5f))
        return;

    double dot = (double)v.y * axis->y + (double)v.x * axis->x + (double)v.z * axis->z;
    double len2 = (double)v.z * v.z + (double)v.y * v.y + (double)v.x * v.x;
    double k = dot / len2;
    Vec3_2b8840 &w = fr.w;
    w.x = (float)(v.x * k);
    w.y = (float)(v.y * k);
    w.z = (float)(v.z * k);

    for (int i = 0; i < 2; i++) {
        if (!(flags & (1 << i)))
            continue;

        Vec3_2b8840 &u = fr.u;
        u.x = (float)i;
        u.y = (float)(1 - i);
        u.z = 0.0f;
        ((owners::Obj_22d260 *)&u)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b8840 *)(((Mat4_2b8840 *)m)));

        double dotU = (double)u.y * axis->y + (double)u.x * axis->x + (double)u.z * axis->z;
        double lenU = (double)u.z * u.z + (double)u.y * u.y + (double)u.x * u.x;
        double kU = dotU / lenU;
        Vec3_2b8840 &x = fr.x;
        float y1 = (float)(u.y * kU);
        float z1 = (float)(u.z * kU);
        x.x = (float)(u.x * kU + w.x);
        x.y = y1 + w.y;
        x.z = z1 + w.z;
        x.FUN_0022d180();

        double t = (double)x.z * v.z + (double)x.y * v.y + (double)x.x * v.x;
        float tf = (float)t;
        Range_2b8840 *range = i == 0 ? ((Range_2b8840 *)range1) : ((Range_2b8840 *)range2);
        float *out = i == 0 ? out1 : out2;
        if (t > range->lo)
            *out = 1.0f;
        else if (!(tf > range->hi))
            *out = 0.0f;
        else
            *out = 1.0f - (tf - range->lo) / (range->hi - range->lo);
    }
}


// 0x002b8b30 FUN_002b8b30 (748 B): equivalent/0x002b8b30.cpp
// sym: _FUN_002b8b30 @2067ba308e2a @wfca07bb150bc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002b8b30 @ 0x002b8b30
// Cone falloff of the two local axes (bits 0 and 1 of flags) relative to the direction `axis`.
extern "C" void FUN_002b8b30(float *out1, float *out2, int flags, void *range1, void *range2, void *m, void * axis_)
{
    Vec3_2b8b30 * axis = (Vec3_2b8b30 *)axis_;
    *out1 = 1.0f;
    *out2 = 1.0f;
    if (flags == 0)
        return;

    struct Frame { Vec3_2b8b30 v; Vec3_2b8b30 w; Vec3_2b8b30 u; Vec3_2b8b30 x; float pad[12]; } fr;
    Vec3_2b8b30 &v = fr.v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    ((owners::Obj_22d260 *)&v)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b8b30 *)(((Mat4_2b8b30 *)m)));
    if (axis->FUN_0022d2b0(&v, 1e-5f))
        return;

    double dot = (double)v.y * axis->y + (double)v.x * axis->x + (double)v.z * axis->z;
    double len2 = (double)v.z * v.z + (double)v.y * v.y + (double)v.x * v.x;
    double k = dot / len2;
    Vec3_2b8b30 &w = fr.w;
    w.x = (float)(v.x * k);
    w.y = (float)(v.y * k);
    w.z = (float)(v.z * k);

    for (int i = 0; i < 2; i++) {
        if (!(flags & (1 << i)))
            continue;

        Vec3_2b8b30 &u = fr.u;
        u.x = (float)i;
        u.y = (float)(1 - i);
        u.z = 0.0f;
        ((owners::Obj_22d260 *)&u)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b8b30 *)(((Mat4_2b8b30 *)m)));

        double dotU = (double)u.y * axis->y + (double)u.x * axis->x + (double)u.z * axis->z;
        double lenU = (double)u.z * u.z + (double)u.y * u.y + (double)u.x * u.x;
        double kU = dotU / lenU;
        Vec3_2b8b30 &x = fr.x;
        float y1 = (float)(u.y * kU);
        float z1 = (float)(u.z * kU);
        x.x = (float)(u.x * kU + w.x);
        x.y = y1 + w.y;
        x.z = z1 + w.z;
        x.FUN_0022d180();

        double t = (double)x.z * v.z + (double)x.y * v.y + (double)x.x * v.x;
        float tf = (float)t;
        Range_2b8b30 *range = i == 0 ? ((Range_2b8b30 *)range1) : ((Range_2b8b30 *)range2);
        float *out = i == 0 ? out1 : out2;
        if (t > range->lo)
            *out = 1.0f;
        else if (!(tf > range->hi))
            *out = 0.0f;
        else
            *out = 1.0f - (tf - range->lo) / (range->hi - range->lo);
    }
}


// 0x002b8e20 FUN_002b8e20 (84 B): matches/0x002b8e20.cpp
// sym: _FUN_002b8e20
// data: oneThird = DAT_003f32dc
extern "C" void FUN_002b8e20(float* out, int mode, float* range, float value) {
    *out = 1.0f;
    if (mode == 1) {
        if (value < range[0]) {
            *out = 1.0f;
            return;
        }
        if (value < range[1]) {
            *out = DAT_003f32dc - (value - range[0]) / (range[1] - range[0]);
            return;
        }
        *out = 0.0f;
    }
}

} // namespace fn_fff84c72

// 0x002b8e80 FUN_002b8e80 (190 B): equivalent/0x002b8e80.cpp [wrapped: conflict: pure3d::BillboardQuad]
// sym: ??0BillboardQuad@pure3d@fn_002b8e80@@QAE@XZ @328879a40d12 @w4752937cca92
namespace fn_002b8e80 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b8e80 @ 0x002b8e80
struct Matrix { char data[64]; void FUN_0022b980(); };
struct Entity_2b8e80 {
 virtual void slot0();
 int reserved04,reserved08,reserved0c;
 int x10,x14,x18,x1c,x20,x24,x28,x2c,x30,x34;
 Entity_2b8e80();
};
namespace pure3d {
struct BillboardQuad : Entity_2b8e80 {
 bool enabled; char pad39[3]; int index;
 Matrix matrix;
 float scaleX,scaleY; int zero88; bool flag; char pad8d[3]; int mode,zero94;
 float a98,a9c,aa0,aa4,aa8,aac,ab0,ab4,ab8,abc;
 int c0,c4;
 virtual void slot0();
 BillboardQuad();
};
BillboardQuad::BillboardQuad() {
 enabled=true; index=-1;
 scaleX=1.0f; scaleY=1.0f; zero88=0; flag=true; mode=1; zero94=0; c0=0; c4=0;
 matrix.FUN_0022b980();
 a98=0.0f; a9c=0.0f; aa0=0.0f; aa4=1.0f; aa8=1.0f; aac=1.0f; ab0=1.0f; ab4=0.0f; ab8=0.0f; abc=0.0f;
 x1c=0; x20=0; x24=0; x10=0; x14=0; x18=0; x28=0; x2c=0; x30=0; x34=0;
}
}
} // namespace fn_002b8e80

namespace fn_fff84c72 {

// 0x002b8f50 pure3d::BillboardQuad::vfunc_6 (3 B): matches/0x002b8f50.cpp
// sym: ?FUN_002b8f50@fn_fff84c72@@YGXPAX000@Z
// Same code shape as 0x0023f7b0 (propagated; names are from that function)
void __stdcall FUN_002b8f50(void*, void*, void*, void*) {}


// 0x002b8f60 FUN_002b8f60 (378 B): equivalent/0x002b8f60.cpp
// sym: ?FUN_002b8f60@Box_2b8f60@fn_fff84c72@@QAEXPAUVec3_2b8f60@2@PAUMat4_2b8f60@2@1HM@Z @9f2681a73bf8 @w3ca302899429
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002b8f60 @ 0x002b8f60
void Box_2b8f60::FUN_002b8f60(Vec3_2b8f60* corners, Mat4_2b8f60* local, Mat4_2b8f60* world, hulk_intptr unused, float scale)
{
    float x = scale * halfX;
    float y = scale * halfY;
    corners[0].x = -x;
    corners[0].y = -y;
    corners[0].z = 0.0f;
    corners[1].x = x;
    corners[1].y = -y;
    corners[1].z = 0.0f;
    corners[2].x = x;
    corners[2].y = y;
    corners[2].z = 0.0f;
    corners[3].x = -x;
    corners[3].y = y;
    corners[3].z = 0.0f;
    for (int i = 0; i < 4; i++)
        ((owners::Obj_22d210 *)&(corners[i]))->FUN_0022d210((owners::Obj_22d210 *)(Mat4_2b8f60 *)local);
    if (depth != 0.0f) {
        Vec3_2b8f60 u;
        u.x = 0.0f;
        u.y = 0.0f;
        u.z = -depth;
        ((owners::Obj_22d260 *)&u)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b8f60 *)local);
        for (int i = 0; i < 4; i++) {
            corners[i].x += u.x;
            corners[i].y += u.y;
            corners[i].z += u.z;
        }
    }
    for (int i = 0; i < 4; i++)
        ((owners::Obj_22d210 *)&(corners[i]))->FUN_0022d210((owners::Obj_22d210 *)(Mat4_2b8f60 *)world);
}


// 0x002b90e0 FUN_002b90e0 (336 B): equivalent/0x002b90e0.cpp
// sym: ?FUN_002b90e0@Billboard_2b90e0@fn_fff84c72@@QAEXPAUQuad_2b90e0@2@PAUNode@2@PAUMatrix@2@1M@Z @72e0a6bc6169 @wb3e28368691b
// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 4/4)
// FUN_002b90e0 @ 0x002b90e0
void Billboard_2b90e0::FUN_002b90e0(Quad_2b90e0 *out, Node *from, Matrix *m, Node *target, float size)
{
    V3_2b90e0 goal = target->pos;
    V3_2b90e0 p = from->pos;
    if (pull != 0.0f) {
        V3_2b90e0 d;
        d.x = goal.x - p.x;
        d.y = goal.y - p.y;
        d.z = goal.z - p.z;
        d.FUN_0022d110();
        d.x = d.x * pull;
        volatile float dy = d.y * pull;
        volatile float dz = d.z * pull;
        p.x = d.x + p.x;
        p.y = dy + p.y;
        p.z = dz + p.z;
    }
    ((owners::Obj_22d210 *)&p)->FUN_0022d210((owners::Obj_22d210 *)(Matrix *)m);
    double w = size * halfWidth;
    double h = size * halfHeight;
    if (!fixedSize) {
        w = w * p.z;
        h = h * p.z;
    }
    out->corner[0].x = p.x - w;
    out->corner[0].y = p.y - h;
    out->corner[0].z = p.z;
    out->corner[1].x = p.x + w;
    out->corner[1].y = p.y - h;
    out->corner[1].z = p.z;
    out->corner[2].x = p.x + w;
    out->corner[2].y = p.y + h;
    out->corner[2].z = p.z;
    out->corner[3].x = p.x - w;
    out->corner[3].y = p.y + h;
    out->corner[3].z = p.z;
}


// 0x002b9230 FUN_002b9230 (209 B): equivalent/0x002b9230.cpp
// sym: ?target@Owner_2b9230@fn_fff84c72@@QAEHPAXPAUObject@2@010@Z @5cabfcc4a23c @wbb31567a5838
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b9230 @ 0x002b9230
int Owner_2b9230::target(void* a, Object* b, void* c, Object* d, void* e) {
 Vec3_2b9230 first=b->position;
 Vec3_2b9230 second=d->position;
 Vec3_2b9230 delta; delta.x=first.x-second.x; delta.y=first.y-second.y; delta.z=first.z-second.z;
 Matrix translation; translation.FUN_0022b980(); translation.FUN_0022ccf0(&delta);
 Matrix result; ((owners::Matrix_22ca90 *)&result)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&matrix), (const owners::Matrix_22ca90 *)(Matrix *)(&translation)); ((owners::Target_22be40 *)&result)->FUN_0022be40((const int *)(Vec3_2b9230 *)(&first));
 return FUN_002b8f60(a,&result,c,d,e);
}

} // namespace fn_fff84c72

// 0x002b9310 FUN_002b9310 (209 B): matches/0x002b9310.cpp [wrapped: conflict: Object]
// sym: ?target@Owner_2b9310@fn_002b9310@@QAEHHPAUObject@2@H0H@Z
namespace fn_002b9310 {
struct Vector {
    float x, y, z;
};
struct Object {
    char pad[0x30];
    Vector position;
};
struct Matrix {
    float data[16];
    void FUN_0022b980();
    void FUN_0022cc90(Vector*);
};
struct Owner_2b9310 {
    char pad[0x40];
    Matrix transform;
    int FUN_002b8f60(int, Matrix*, int, Object*, int);
    int target(int, Object*, int, Object*, int);
};
int Owner_2b9310::target(int a, Object* from, int c, Object* to, int e) {
    Vector endpoint = to->position;
    Vector origin = from->position;
    Vector delta;
    delta.x = origin.x - endpoint.x;
    delta.y = origin.y - endpoint.y;
    delta.z = origin.z - endpoint.z;
    Matrix translation;
    translation.FUN_0022b980();
    translation.FUN_0022cc90(&delta);
    Matrix result;
    ((owners::Matrix_22ca90 *)&result)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&transform), (const owners::Matrix_22ca90 *)(Matrix *)(&translation));
    ((owners::Target_22be40 *)&result)->FUN_0022be40((const int *)(Vector *)(&origin));
    return FUN_002b8f60(a, &result, c, to, e);
}
} // namespace fn_002b9310


// 0x002b93f0 FUN_002b93f0 (211 B): equivalent/0x002b93f0.cpp
// sym: ?FUN_002b93f0@Object_2b93f0@owners@@QAEXPAMPAIIE@Z @cccba7f18008 @w7dfde95b5f2b
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_002b93f0 @ 0x002b93f0
void owners::Object_2b93f0::FUN_002b93f0(float* result, unsigned int* value, unsigned int input, unsigned char randomize) {
 if (randomize == 1) {
  if (!(DAT_00554bc0 & 1)) {
   DAT_00554bc0 |= 1;
   ((owners::Random_22aba0 *)&((*(RandomState_2b93f0*)&DAT_00554bb8)))->FUN_0022aba0(0);
  }
  unsigned int bound = limit;
  unsigned int first = ((*(RandomState_2b93f0*)&DAT_00554bb8).first & 0xffff) * 0x9069u + ((*(RandomState_2b93f0*)&DAT_00554bb8).first >> 16);
  unsigned int second = ((*(RandomState_2b93f0*)&DAT_00554bb8).second & 0xffff) * 0x4650u + ((*(RandomState_2b93f0*)&DAT_00554bb8).second >> 16);
  (*(RandomState_2b93f0*)&DAT_00554bb8).second = second;
  (*(RandomState_2b93f0*)&DAT_00554bb8).first = first;
  *value = (unsigned short)(((first << 16) + (second & 0xffff)) % (bound + 1));
 } else {
  *value = input;
 }
 *result = (float)((1.0 / (double)limit) * (double)*value);
}


// 0x002b9520 FUN_002b9520 (127 B): matches/0x002b9520.cpp [wrapped: conflict: pure3d::BillboardCutOffQuad]
// sym: ??0BillboardCutOffQuad@pure3d@fn_002b9520@@QAE@XZ
namespace fn_002b9520 {
// FUN_002b9520 @ 0x002b9520
// equiv-map: ??0QuadBase@@QAE@XZ = 0x002b8e80

class BillboardQuad_2b9520 {
public:
    BillboardQuad_2b9520() throw();
    virtual void vfunc_0();
    char pad04[0xc8 - 4];
};

namespace pure3d {
class BillboardCutOffQuad : public BillboardQuad_2b9520 {
public:
    int f_c8, f_cc, f_d0, f_d4, f_d8, f_dc, f_e0, f_e4, f_e8, f_ec, f_f0;
    float f_f4, f_f8, f_fc, f_100;
    int f_104, f_108;
    BillboardCutOffQuad() throw();
    virtual void vfunc_0();
};
}

pure3d::BillboardCutOffQuad::BillboardCutOffQuad() throw()
{
    f_c8 = 0;
    f_cc = 0;
    f_d0 = 0;
    f_d4 = 0;
    f_d8 = 0;
    f_dc = 0;
    f_e0 = 0;
    f_e4 = 0;
    f_e8 = 0;
    f_ec = 0;
    f_f0 = 0;
    f_104 = 0;
    f_108 = 0;
    f_f4 = 1.0f;
    f_f8 = 1.0f;
    f_fc = 1.0f;
    f_100 = 1.0f;
}
} // namespace fn_002b9520


// 0x002b95b0 pure3d::BillboardQuadGroup::vfunc_5 (6 B): matches/0x002b95b0.cpp
// sym: ?vfunc_5@BillboardQuadGroup@pure3d@@UAEHXZ
// Same code shape as 0x00055210 (propagated; names are from that function)
int pure3d::BillboardQuadGroup::vfunc_5() {
    return 4;
}


// 0x002b95c0 pure3d::BillboardQuadGroup::vfunc_7 (7 B): matches/0x002b95c0.cpp
// sym: ?vfunc_7@BillboardQuadGroup@pure3d@@UAEIXZ
hulk_uintptr pure3d::BillboardQuadGroup::vfunc_7() {
    return this->f_84;
}


// 0x002b95d0 pure3d::BillboardQuadGroup::vfunc_9 (3 B): matches/0x002b95d0.cpp
// sym: ?vfunc_9@BillboardQuadGroup@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::BillboardQuadGroup::vfunc_9() {
    return 0;
}


// 0x002b95e0 pure3d::BillboardQuadGroup::vfunc_11 (9 B): matches/0x002b95e0.cpp
// sym: ?vfunc_11@BillboardQuadGroup@pure3d@@UAEMHH@Z
hulk_freg pure3d::BillboardQuadGroup::vfunc_11(int , int ) {
    return DAT_003f32dc;
}


// 0x002b9640 pure3d::BillboardObject::vfunc_15 (6 B): matches/0x002b9640.cpp
// sym: ?vfunc_15@BillboardObject@pure3d@@UAEHXZ
// Same code shape as 0x00234f10 (propagated; names are from that function)
int pure3d::BillboardObject::vfunc_15() {
    return 8;
}


// 0x002b9650 pure3d::BillboardObject::vfunc_3 (3 B): matches/0x002b9650.cpp
// sym: ?vfunc_3@BillboardObject@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::BillboardObject::vfunc_3() {
    return true;
}


// 0x002b9660 pure3d::BillboardObject::vfunc_4 (51 B): matches/0x002b9660.cpp
// sym: ?vfunc_4@BillboardObject@pure3d@@UAEPAXXZ
void* pure3d::BillboardObject::vfunc_4() {
    Alloc_2b9660* p = (Alloc_2b9660*)thunk_FUN_0008d690(0x60);
    if (p) {
        p->init_002a4e40(this);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_0042e764);
        *(unsigned long*)((char*)p + 0x58) = 0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fff84c72 {

// 0x002b96a0 FUN_002b96a0 (18 B): matches/0x002b96a0.cpp
// sym: ??0BillboardQuadGroupLoader@fn_fff84c72@@QAE@XZ
BillboardQuadGroupLoader::BillboardQuadGroupLoader() : RenderObjectLoader_2b96a0() {}


// 0x002b96d0 FUN_002b96d0 (18 B): matches/0x002b96d0.cpp
// sym: ??0OldBillboardQuadGroupLoader@fn_fff84c72@@QAE@XZ
// Base_2b96d0's constructor is FUN_002a3e80 (RenderObjectLoader's, thiscall): declared, not defined here, so the call
// passes this in ecx (a free `void BaseInit()` byte-matched only because ecx still held this)
OldBillboardQuadGroupLoader::OldBillboardQuadGroupLoader() : Base_2b96d0() {}


// 0x002b98a0 pure3d::BillboardQuad::vfunc_2 (36 B): matches/0x002b98a0.cpp
// sym: ?vfunc_5@BillboardQuad_2b98a0@fn_fff84c72@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
BillboardQuad_2b98a0* BillboardQuad_2b98a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042e724;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002b98d0 FUN_002b98d0 (492 B): equivalent/0x002b98d0.cpp
// sym: ?FUN_002b98d0@Box_2b98d0@fn_fff84c72@@QAEXPAUMat4_2b98d0@2@000M@Z @03a0a35cd3b4 @wf546430d7934
// STATUS: equivalent (tools/equiv.py level 3: 2785 inputs, branch coverage 2/2)
// FUN_002b98d0 @ 0x002b98d0
void Box_2b98d0::FUN_002b98d0(Mat4_2b98d0 *a, Mat4_2b98d0 *c, Mat4_2b98d0 *b, Mat4_2b98d0 *d, float scale)
{
    Vec3_2b98d0 pa;
    Vec3_2b98d0 pb;
    Vec3_2b98d0 up;
    Vec3_2b98d0 fwd;
    Vec3_2b98d0 w;
    Mat4_2b98d0 rot;
    Mat4_2b98d0 comb;

    pb.x = d->m[12];
    pb.y = d->m[13];
    pb.z = d->m[14];
    pa.x = c->m[12];
    pa.y = c->m[13];
    pa.z = c->m[14];

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    fwd.x = 0.0f;
    fwd.y = 0.0f;
    fwd.z = -1.0f;
    ((owners::Obj_22d260 *)&up)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b98d0 *)c);
    ((owners::Obj_22d260 *)&fwd)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b98d0 *)c);

    double dx = (double)pb.x - (double)pa.x;
    double dy = (double)pb.y - (double)pa.y;
    double dz = (double)pb.z - (double)pa.z;
    double dot1 = up.z * dz + up.y * dy + up.x * dx;
    float t1x = (float)(up.x * dot1);
    float t1y = (float)(up.y * dot1);
    float t1z = (float)(up.z * dot1);
    double dot2 = fwd.z * dz + fwd.y * dy + fwd.x * dx;
    float t2y = (float)(fwd.y * dot2);
    float t2z = (float)(fwd.z * dot2);
    w.x = (float)(fwd.x * dot2 + t1x);
    w.y = (float)(t2y + t1y);
    w.z = (float)(t2z + t1z);

    w.FUN_0022d180();
    rot.FUN_0022b980();

    double c1 = w.z * up.z + w.y * up.y + w.x * up.x;
    float c2 = (float)(w.z * fwd.z + w.y * fwd.y + w.x * fwd.x);
    float ang;
    if (c1 > 0.0)
        ang = FUN_00018a20(c2);
    else
        ang = -FUN_00018a20(c2);
    ((owners::Matrix_22ba30 *)&rot)->FUN_0022ba30(ang);
    ((owners::Matrix_22ca90 *)&comb)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat4_2b98d0 *)(&rot), (const owners::Matrix_22ca90 *)(Mat4_2b98d0 *)c);
    FUN_002b8f60(a, &comb, b, d, scale);
}

} // namespace fn_fff84c72

// 0x002b9ac0 FUN_002b9ac0 (492 B): equivalent/0x002b9ac0.cpp [wrapped: macros]
// sym: ?FUN_002b9ac0@Box_2b9ac0@fn_002b9ac0@@QAEXPAUMat4_2b9ac0@2@000M@Z @f1416a52064c @wf09353648da9
namespace fn_002b9ac0 {
// STATUS: equivalent (tools/equiv.py level 3: 2785 inputs, branch coverage 2/2)
// FUN_002b9ac0 @ 0x002b9ac0
struct Mat4_2b9ac0 {
    float m[16];
    void FUN_0022b980();
};

struct Vec3_2b9ac0 {
    float x, y, z;
    void FUN_0022d180();
};

hulk_freg FUN_00018a20(float x);

class Box_2b9ac0 {
public:
    void FUN_002b8f60(Mat4_2b9ac0 *a, Mat4_2b9ac0 *b, Mat4_2b9ac0 *c, Mat4_2b9ac0 *d, float scale);
    void FUN_002b9ac0(Mat4_2b9ac0 *a, Mat4_2b9ac0 *c, Mat4_2b9ac0 *b, Mat4_2b9ac0 *d, float scale);
};

void Box_2b9ac0::FUN_002b9ac0(Mat4_2b9ac0 *a, Mat4_2b9ac0 *c, Mat4_2b9ac0 *b, Mat4_2b9ac0 *d, float scale)
{
    Vec3_2b9ac0 pa;
    Vec3_2b9ac0 pb;
    Vec3_2b9ac0 up;
    Vec3_2b9ac0 fwd;
    Vec3_2b9ac0 w;
    Mat4_2b9ac0 rot;
    Mat4_2b9ac0 comb;

    pb.x = d->m[12];
    pb.y = d->m[13];
    pb.z = d->m[14];
    pa.x = c->m[12];
    pa.y = c->m[13];
    pa.z = c->m[14];

    up.x = 1.0f;
    up.y = 0.0f;
    up.z = 0.0f;
    fwd.x = 0.0f;
    fwd.y = 0.0f;
    fwd.z = -1.0f;
    ((owners::Obj_22d260 *)&up)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b9ac0 *)c);
    ((owners::Obj_22d260 *)&fwd)->FUN_0022d260((owners::Obj_22d260 *)(Mat4_2b9ac0 *)c);

    #define DX (pb.x - pa.x)
#define DY (pb.y - pa.y)
#define DZ (pb.z - pa.z)
    double dot1 = up.z * DZ + up.y * DY + up.x * DX;
    float t1x = (float)(up.x * dot1);
    float t1y = (float)(up.y * dot1);
    float t1z = (float)(up.z * dot1);
    /* the original recomputes pb-pa in unrounded x87 form for this dot product too; the volatile
       reads keep the compiler from sharing the differences with dot1 (which would spill them rounded) */
    volatile Vec3_2b9ac0 *vb = &pb;
    volatile Vec3_2b9ac0 *va = &pa;
    double dot2 = fwd.z * (vb->z - va->z) + fwd.y * (vb->y - va->y) + fwd.x * (vb->x - va->x);
    float t2y = (float)(fwd.y * dot2);
    float t2z = (float)(fwd.z * dot2);
    w.x = (float)(fwd.x * dot2 + t1x);
    w.y = (float)(t2y + t1y);
    w.z = (float)(t2z + t1z);

    w.FUN_0022d180();
    rot.FUN_0022b980();

    double c1 = w.z * up.z + w.y * up.y + w.x * up.x;
    float c2 = (float)(w.z * fwd.z + w.y * fwd.y + w.x * fwd.x);
    float ang;
    if (c1 > 0.0)
        ang = -FUN_00018a20(c2);
    else
        ang = FUN_00018a20(c2);
    ((owners::Mat_22ba70 *)&rot)->FUN_0022ba70(ang);
    ((owners::Matrix_22ca90 *)&comb)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat4_2b9ac0 *)(&rot), (const owners::Matrix_22ca90 *)(Mat4_2b9ac0 *)c);
    FUN_002b8f60(a, &comb, b, d, scale);
}
} // namespace fn_002b9ac0
#undef DX
#undef DY
#undef DZ

namespace fn_fff84c72 {

// 0x002b9cb0 pure3d::BillboardCutOffQuad::vfunc_2 (36 B): matches/0x002b9cb0.cpp
// sym: ?vfunc_5@BillboardCutOffQuad_2b9cb0@fn_fff84c72@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
BillboardCutOffQuad_2b9cb0* BillboardCutOffQuad_2b9cb0::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_0042e724);
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002b9ce0 pure3d::BillboardCutOffQuad::vfunc_6 (498 B): equivalent/0x002b9ce0.cpp
// sym: ?FUN_002b9ce0@BillboardCutOffQuad@fn_fff84c72@@QAEXPAM0PAUMat4_2b9ce0@2@1@Z @5583eee26bb1 @wfe3800dcfaa1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::BillboardCutOffQuad::vfunc_6 @ 0x002b9ce0
void BillboardCutOffQuad::FUN_002b9ce0(float *outA, float *outB, Mat4_2b9ce0 *from, Mat4_2b9ce0 *to)
{
    if (enabled != 1)
        return;

    struct Frame {
        char pad00[8];
        float scaleB;
        float scaleC;
        float scaleD;
        float unused;
        V3_2b9ce0 d;
        V3_2b9ce0 t;
        char pad30[0x18];
        float scaleG;
        float len;
    } f;

    f.d.x = to->m[12] - from->m[12];
    f.d.y = to->m[13] - from->m[13];
    f.d.z = to->m[14] - from->m[14];
    f.len = (float)sqrt((double)(f.d.x * f.d.x + f.d.y * f.d.y) + (double)(f.d.z * f.d.z));

    double nx;
    double ny;
    union {
        float f;
        unsigned u;
    } absLen;
    absLen.f = f.len;
    absLen.u &= 0x7fffffff;
    if (absLen.f <= 1e-5f) {
        f.d.z = 0.0f;
        nx = 0.0;
        ny = 0.0;
    } else {
        double exact = 1.0 / (double)f.len;
        float inv = (float)exact;
        nx = exact * f.d.x;
        ny = inv * f.d.y;
        f.d.z = (float)(inv * f.d.z);
    }
    f.t.x = (float)-nx;
    f.t.y = (float)-ny;
    f.t.z = -f.d.z;

    f.scaleB = 1.0f;
    f.scaleD = 1.0f;
    FUN_002b8840(&f.scaleB, &f.scaleD, (unsigned)f_c8, (float *)f_d4, (float *)f_dc, (Mat4_2b9ce0 *)from, (V3_2b9ce0 *)(&f.t));
    f.scaleG = 1.0f;
    f.scaleC = 1.0f;
    f.unused = 1.0f;
    FUN_002b8b30(&f.scaleG, &f.scaleC, (unsigned)f_cc, (float *)f_e4, (float *)f_ec, (Mat4_2b9ce0 *)to, (V3_2b9ce0 *)(&f.t));
    FUN_002b8e20(&f.unused, (unsigned)f_d0, &f_104, f.len);

    double s1 = (double)f.scaleG * f.scaleB;
    double s2 = (double)f.scaleC * f.scaleD;
    double r1 = ((double)f_fc - f_100) * s2 + f_100;
    double r2 = ((double)f_f4 - f_f8) * s1 + f_f8;
    *outB = (float)(r1 * r2);
    *outA = (float)(s2 * s1 * f.unused);
}

} // namespace fn_fff84c72

// 0x002b9ee0 pure3d::BillboardQuadGroup::vfunc_8 (105 B): matches/0x002b9ee0.cpp
// sym: ?vfunc_8@BillboardQuadGroup@pure3d@@UAEXPAX@Z
void pure3d::BillboardQuadGroup::vfunc_8(void* __p0) { Ref_2b9ee0 * value = (Ref_2b9ee0 *)__p0;

    if (value)
        value->F0();
    if ((*(Ref_2b9ee0 * *)&this->f_84))
        (*(Ref_2b9ee0 * *)&this->f_84)->F1();
    (*(Ref_2b9ee0 * *)&this->f_84) = value;
    if (value) {
        int type = *(int*)((char*)value + 0x18);
        if (type == 1 || type == 3 || type == 7 || type == 2 || type == 4 || type == 5 || type == 6) {
            this->f_10 = 1;
            return;
        }
    }
    this->f_10 = 0;
}


// 0x002b9f50 pure3d::BillboardQuadGroup::vfunc_10 (589 B): equivalent/0x002b9f50.cpp [wrapped: conflict: pure3d::BillboardQuadGroup]
// sym: ?vfunc_10@BillboardQuadGroup@pure3d@fn_002b9f50@@UAEXXZ @6107278bb8c2 @we4d876182878
namespace fn_002b9f50 {
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 22/28, incomplete)
// pure3d::BillboardQuadGroup::vfunc_10 @ 0x002b9f50
struct Matrix {
    float m[16];
};

struct Sphere_2b9f50 {
    int w[4];
};

struct Vec3_2b9f50 {
    float x, y, z;
    void FUN_0022d210(Matrix* m);
    Sphere_2b9f50* FUN_000a8890(Sphere_2b9f50* out);
};

struct Quad_2b9f50 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Update();      // slot 5
    char pad04[0xc];
    Vec3_2b9f50 lo;                    // 0x10
    Vec3_2b9f50 hi;                    // 0x1c
};

// scratch block: in the original the callee's output buffer overlaps the last box corner
struct Frame_2b9f50 {
    Vec3_2b9f50 p;
    Vec3_2b9f50 q;
    Vec3_2b9f50 hi;
    Vec3_2b9f50 lo;
    int tail;
};

namespace pure3d {
class BillboardQuadGroup {
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

    char pad04[0x10];
    Vec3_2b9f50 min;                   // 0x14
    Vec3_2b9f50 max;                   // 0x20
    int sphere[4];              // 0x2c
    char pad3c[4];
    Matrix matrix;              // 0x40
    char pad80[0x8c - 0x80];
    Quad_2b9f50** begin;               // 0x8c
    Quad_2b9f50** end;                 // 0x90
};

void BillboardQuadGroup::vfunc_10()
{
    Frame_2b9f50 f;
    unsigned int i;
    hulk_uintptr n;

    max.x = 0.0f;
    max.y = 0.0f;
    max.z = 0.0f;
    min.x = 0.0f;
    min.y = 0.0f;
    min.z = 0.0f;
    sphere[0] = 0;
    sphere[1] = 0;
    sphere[2] = 0;
    sphere[3] = 0;

    n = end - begin;
    if (n == 0)
        return;
    for (i = 0; i < n; i++) {
        begin[i]->Update();
        Quad_2b9f50* q = begin[i];
        f.hi = q->hi;
        f.lo = q->lo;
        max.x = (max.x < f.hi.x) ? f.hi.x : max.x;
        max.y = (max.y < f.hi.y) ? f.hi.y : max.y;
        max.z = (max.z < f.hi.z) ? f.hi.z : max.z;
        min.x = (min.x < f.lo.x) ? min.x : f.lo.x;
        min.y = (min.y < f.lo.y) ? min.y : f.lo.y;
        min.z = (min.z < f.lo.z) ? min.z : f.lo.z;
    }

    f.p = max;
    f.q = min;
    f.p.FUN_0022d210(&matrix);
    f.q.FUN_0022d210(&matrix);
    max.x = (f.p.x < f.q.x) ? f.q.x : f.p.x;
    max.y = (f.p.y < f.q.y) ? f.q.y : f.p.y;
    max.z = (f.p.z < f.q.z) ? f.q.z : f.p.z;
    min.x = (f.p.x < f.q.x) ? f.p.x : f.q.x;
    min.y = (f.p.y < f.q.y) ? f.p.y : f.q.y;
    min.z = (f.p.z < f.q.z) ? f.p.z : f.q.z;
    Sphere_2b9f50* s = min.FUN_000a8890((Sphere_2b9f50*)&f.lo);
    sphere[0] = s->w[0];
    sphere[1] = s->w[1];
    sphere[2] = s->w[2];
    sphere[3] = s->w[3];
}
}
} // namespace fn_002b9f50

namespace fn_fff84c72 {

// 0x002ba1a0 FUN_002ba1a0 (93 B): equivalent/0x002ba1a0.cpp
// sym: ?FUN_002ba1a0@Target@fn_fff84c72@@QAEPAUEntry@2@HH@Z @8aff5f93480f @wf624b683306a
// STATUS: equivalent (tools/equiv.py level 3: 757 inputs, branch coverage 8/8)
// FUN_002ba1a0 @ 0x002ba1a0
Entry *Target::FUN_002ba1a0(int first, int second) { unsigned index = 0; hulk_intptr count = ((hulk_intptr)end - (hulk_intptr)begin) >> 2; if (count != 0) { do { Entry *entry = begin[index]; if (entry->first == first && entry->second == second) return begin[index]; ++index; count = ((hulk_intptr)end - (hulk_intptr)begin) >> 2; } while (index < (unsigned)count); } return 0; }


// 0x002ba220 FUN_002ba220 (987 B): equivalent/0x002ba220.cpp
// sym: ?FUN_002ba220@BillboardQuadGroup@fn_fff84c72@@QAEMXZ @9e2e381e198f @w67488ecd2785
// STATUS: equivalent (tools/equiv.py level 3: 19839 inputs, branch coverage 36/36)
// FUN_002ba220 @ 0x002ba220
hulk_freg BillboardQuadGroup::FUN_002ba220()
{
    struct Frame {
        hulk_freg x0;
        hulk_freg y0;
        hulk_freg y1;
        hulk_freg x1;
        union {
            unsigned char flag;
            int word;
        } prev;
        Vec3_2ba220 out;
        Vec3_2ba220 p1;
        Vec3_2ba220 p3;
        Vec3_2ba220 p2;
    } fr;

    Obj_2ba220 *o = DAT_0052c2a8->v89(0x500002);
    if (o == 0)
        return 1.0f;
    int mult = 1;
    ObjQuery *q = (ObjQuery *)DAT_0052c2a8->v89(0x500001);
    if (q != 0) {
        switch (q->v4()) {
        case 0x1021: case 0x1121: case 0x2012: case 0x2021:
            mult = 2;
            break;
        case 0x1022: case 0x1222: case 0x2022: case 0x2222:
            mult = 4;
            break;
        case 0x1233: case 0x2233:
            mult = 9;
            break;
        }
    }
    DAT_0052c2a8->v56(0, 0, 0, 1);
    fr.prev.flag = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    Scene_2ba220 *scene = (*(Camera**)&DAT_0052c2b4)->scene;
    Vec3_2ba220 tmp;
    void * tmp1 = (*(Camera**)&DAT_0052c2b4)->FUN_0028faa0();
    ((owners::C_22d240 *)&tmp)->FUN_0022d240((hulk_intptr)(Vec3_2ba220 *)(&pos70), (hulk_intptr)tmp1);
    scene->FUN_002940d0(&tmp, &fr.out);
    hulk_freg r = fr.out.z * 0.01f;
    fr.x0 = fr.out.x - r;
    fr.x1 = fr.out.x + r;
    fr.y0 = fr.out.y - r;
    fr.y1 = fr.out.y + r;
    (*(Display_2ba220**)&DAT_0052c2ac)->layer->v21(0);
    o->v2();
    Mesh_2ba220 *m = DAT_0052c2a8->v30(0, 1, 0x2020, 4, 0);
    *m->colors = 0xff000000;
    m->verts->x = fr.x0;
    m->verts->y = fr.y0;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    *m->colors = 0xff000000;
    m->verts->x = fr.x0;
    m->verts->y = fr.y1;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    *m->colors = 0xff000000;
    m->verts->x = fr.x1;
    m->verts->y = fr.y0;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    *m->colors = 0xff000000;
    m->verts->x = fr.x1;
    m->verts->y = fr.y1;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    o->v3(0);
    DAT_0052c2a8->v31(m);
    (*(Display_2ba220**)&DAT_0052c2ac)->layer->v16(0);
    DAT_0052c2a8->v62(fr.prev.word);
    DAT_0052c2a8->v56(1, 1, 1, 1);
    Xform_2ba220 *xf = scene->xf;
    fr.p1.x = fr.x0;
    fr.p1.y = fr.y0;
    fr.p1.z = fr.out.z;
    xf->v23(&fr.p1, &fr.p1);
    scene->FUN_00294670(fr.p1, &fr.p1);
    fr.p2.x = fr.x0;
    fr.p2.y = fr.y1;
    fr.p2.z = fr.out.z;
    xf->v23(&fr.p2, &fr.p2);
    scene->FUN_00294670(fr.p2, &fr.p2);
    fr.p3.x = fr.x1;
    fr.p3.y = fr.y0;
    fr.p3.z = fr.out.z;
    xf->v23(&fr.p3, &fr.p3);
    scene->FUN_00294670(fr.p3, &fr.p3);
    int area = (int)(__int64)((fr.p3.x - fr.p1.x) * (fr.p1.y - fr.p2.y) * 0.8f) * mult;
    double ratio = (double)o->v4(0) / (double)area;
    if (ratio >= 0.0 && ratio <= 1.0)
        return ratio;
    if (ratio > 1.0)
        return 1.0f;
    return 0.0f;
}

} // namespace fn_fff84c72

// 0x002ba600 pure3d::BillboardCutOffQuadGroup::vfunc_11 (514 B): equivalent/0x002ba600.cpp [wrapped: conflict: pure3d::BillboardCutOffQuadGroup]
// sym: ?vfunc_11@BillboardCutOffQuadGroup@pure3d@fn_002ba600@@UAEMTSlot_2ba600@3@0@Z @e3c718b38562 @w002d36512b42
namespace fn_002ba600 {
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 8/8)
// pure3d::BillboardCutOffQuadGroup::vfunc_11 @ 0x002ba600

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec2_2ba600 {
    float a, b;
};

struct Vec3_2ba600 {
    float x, y, z;
};

struct Probe_2ba600 {
    char pad00[0x30];
    Vec3_2ba600 pos;
};

union Slot_2ba600 {
    Probe_2ba600* p;
    float f;
    unsigned int u;
};

struct Frame_2ba600 {
    float outB0;
    float outA1;
    float outA0;
    float dx;
    float dy;
    float dz;
    Vec3_2ba600 normal;
    float spare[3];
};

extern "C++" __declspec(nothrow) void __cdecl FUN_002b8840(float *, float *, int, void *, void *, void *, void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_002b8b30(float *, float *, int, void *, void *, void *, void *);

namespace pure3d {

class BillboardCutOffQuadGroup {
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
    virtual hulk_freg vfunc_11(Slot_2ba600 a, Slot_2ba600 b);

    char pad04[0x98 - 4];
    int field98;
    int field9c;
    int mode;
    Vec2_2ba600 rangeA4;
    Vec2_2ba600 rangeAC;
    Vec2_2ba600 rangeB4;
    Vec2_2ba600 rangeBC;
    float fadeStart;
    float fadeEnd;
};

hulk_freg BillboardCutOffQuadGroup::vfunc_11(Slot_2ba600 a, Slot_2ba600 b)
{
    Probe_2ba600* pa = a.p;
    Probe_2ba600* pb = b.p;
    Frame_2ba600 f;

    f.dx = pb->pos.x - pa->pos.x;
    f.dy = pb->pos.y - pa->pos.y;
    f.dz = pb->pos.z - pa->pos.z;
    double xy = f.dx * f.dx + f.dy * f.dy; // MSVC reorders three-term sums; dz is reloaded (rounded)
    a.f = (float)sqrt(xy + *(volatile float *)&f.dz * *(volatile float *)&f.dz);

    unsigned int bits = a.u;
    b.u = bits & 0x7fffffff;
    hulk_freg nx;
    hulk_freg ny;
    if (!(b.f <= 1e-5f)) {
        b.f = 1.0f / a.f;
        nx = (1.0f / a.f) * f.dx; // nx uses the unrounded quotient, ny and dz the stored (rounded) one
        ny = b.f * f.dy;
        f.dz = b.f * f.dz;
    } else {
        nx = 0.0f;
        ny = 0.0f;
        f.dz = 0.0f;
    }
    f.normal.x = -nx;
    f.normal.y = -ny;
    f.normal.z = -f.dz;

    f.outA0 = 1.0f;
    f.outA1 = 1.0f;
    FUN_002b8840(&f.outA0, &f.outA1, field98, (void *)(const Vec2_2ba600 *)(&rangeA4), (void *)(const Vec2_2ba600 *)(&rangeAC), (Probe_2ba600 *)pa, (Vec3_2ba600 *)(&f.normal));
    f.outB0 = 1.0f;
    b.f = 1.0f;
    FUN_002b8b30(&f.outB0, &b.f, field9c, (void *)(const Vec2_2ba600 *)(&rangeB4), (void *)(const Vec2_2ba600 *)(&rangeBC), (Probe_2ba600 *)pb, (Vec3_2ba600 *)(&f.normal));

    hulk_freg w = 1.0f;
    if (mode == 1) {
        if (a.f < fadeStart) {
            w = 1.0f;
        } else if (a.f < fadeEnd) {
            w = 1.0f - (a.f - fadeStart) / (fadeEnd - fadeStart);
        } else {
            w = 0.0f;
        }
    }
    // MSVC reassociates the product chain; spell the original's order
    double p1 = w * b.f;
    double p2 = p1 * f.outB0;
    double p3 = p2 * f.outA1;
    return p3 * f.outA0;
}

}
} // namespace fn_002ba600

namespace fn_fff84c72 {

// 0x002ba810 pure3d::BillboardObject::vfunc_2 (36 B): matches/0x002ba810.cpp
// sym: ?vfunc_5@BillboardObject_2ba810@fn_fff84c72@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
BillboardObject_2ba810* BillboardObject_2ba810::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042e764;
    Destroy_002a4ff0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fff84c72

// 0x002ba840 pure3d::BillboardObject::vfunc_8 (91 B): matches/0x002ba840.cpp
// sym: ?vfunc_8@BillboardObject@pure3d@@UAEXHH@Z
void pure3d::BillboardObject::vfunc_8(hulk_intptr __p0, int __p1) { unsigned int a = (unsigned int)__p0; unsigned int b = (unsigned int)__p1;

    hulk_at_0052c2ac[0]->f23(0, (char*)(*(Obj_2ba840 * *)&this->f_48)->p + 0x40);
    (*(Obj_2ba840 * *)&this->f_48)->p->x = this->f_58;
    ((BillboardObject_nv_2ba840*)this)->helper_002a41e0(a, b);
    (*(Obj_2ba840 * *)&this->f_48)->p->x = 0x3f800000;
    hulk_at_0052c2ac[0]->f16(0);
}

namespace fn_fff84c72 {

// 0x002ba8a0 pure3d::BillboardQuadGroupLoader::vfunc_2 (36 B): matches/0x002ba8a0.cpp
// sym: ?vfunc_5@BillboardQuadGroupLoader_2ba8a0@fn_fff84c72@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
BillboardQuadGroupLoader_2ba8a0* BillboardQuadGroupLoader_2ba8a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042e7b4;
    Destroy_002a3e90();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002ba8d0 FUN_002ba8d0 (1887 B): equivalent/0x002ba8d0.cpp
// sym: ?FUN_002ba8d0@fn_fff84c72@@YGPAUObj_2ba8d0@1@PAUReader@1@H@Z @d014040704b2 @w3a14e233b3ab
// STATUS: equivalent (tools/equiv.py level 3: 253 inputs, branch coverage 59/61, incomplete)
// FUN_002ba8d0 @ 0x002ba8d0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
Obj_2ba8d0 *__stdcall FUN_002ba8d0(Reader *r, int unused)
{
    Frame_2ba8d0 f;
    Obj_2ba8d0 *o;

    r->stream->FUN_002647e0(&f.t19c, 1, 4, 1);
    r->stream->FUN_002647e0(&f.flag, 1, 1, 1);
    unsigned int len = (unsigned char)f.flag;
    r->stream->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    bool big = (f.t1a4 != 0);
    f.flag = big;
    if (big) {
        BillboardCutOffQuad_2ba8d0 *b = (BillboardCutOffQuad_2ba8d0 *)thunk_FUN_0008d690(0x110);
        if (b != 0)
            o = b->FUN_002b9520();
        else
            o = 0;
    } else {
        BillboardQuad_2ba8d0 *s = (BillboardQuad_2ba8d0 *)thunk_FUN_0008d690(0xc8);
        if (s != 0)
            o = s->FUN_002b8e80();
        else
            o = 0;
    }
    ((owners::Target_27b040 *)&(o->nameHolder))->FUN_0027b040((hulk_uintptr)(f.name));

    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->b8c = (f.t1a4 != 0);
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    switch ((unsigned int)f.t1a4) {
    case 0x58414f4e:
        o->f90 = 0;
        break;
    case 0x584158:
        o->f90 = 2;
        break;
    case 0x584159:
        o->f90 = 3;
        break;
    case 0x5841584c:
        o->f90 = 4;
        break;
    case 0x5841594c:
        o->f90 = 5;
        break;
    default:
        o->f90 = 1;
        break;
    }
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f3c = f.t1a4;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f80 = *(float *)&f.t1a4 * 0.5f;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f84 = *(float *)&f.t1a4 * 0.5f;
    r->stream->FUN_002647e0(&f.t1a4, 1, 4, 1);
    o->f88 = f.t1a4;

    while (r->FUN_002669f0()) {
        switch (r->FUN_00266a30()) {
        case 0x17007:
            r->stream->FUN_002647e0(&f.t13c, 1, 4, 1);
            r->stream->FUN_002647e0(f.q110, 4, 4, 1);
            o->f40.FUN_0022ba20(f.q110);
            r->stream->FUN_002647e0(f.t11c, 3, 4, 1);
            ((owners::Target_22be40 *)&(o->f40))->FUN_0022be40((const int *)(f.t11c));
            break;
        case 0x17008:
            r->stream->FUN_002647e0(&f.t120, 1, 4, 1);
            r->stream->FUN_002647e0(&f.t15c, 1, 4, 1);
            o->f94 = (f.t15c != 0) + 1;
            r->stream->FUN_002647e0(&f.t1a0, 1, 2, 1);
            o->fc4 = *(unsigned short *)&f.t1a0;
            r->stream->FUN_002647e0(&f.t1a4, 1, 2, 1);
            {
                unsigned int w = *(unsigned short *)&f.t1a4;
                if (w > o->fc4)
                    w = o->fc4;
                o->fc0 = w;
            }
            {
                float inv = 1.0f / (float)o->fc4;
                o->fb0f = inv;
                o->fa8f = inv;
            }
            break;
        case 0x17009:
            r->stream->FUN_002647e0(&f.t124, 1, 4, 1);
            r->stream->FUN_002647e0(&f.t16c, 1, 4, 1);
            {
                bool p = (f.t16c != 0);
                r->stream->FUN_002647e0(&f.t190, 1, 4, 1);
                bool q = (f.t190 != 0);
                if (p == 1) {
                    o->f94 = (q == p) * 2 + 3;
                } else if (q == 1) {
                    o->f94 = 4;
                }
            }
            {
                int *dst = &o->f98;
                int n;
                for (n = 0; n < 4; n++) {
                    r->stream->FUN_002647e0(&f.t164, 1, 4, 1);
                    dst[0] = f.t164;
                    r->stream->FUN_002647e0(&f.t188, 1, 4, 1);
                    dst[1] = f.t188;
                    dst += 2;
                }
            }
            r->stream->FUN_002647e0(&f.t160, 1, 4, 1);
            o->fb8 = f.t160;
            r->stream->FUN_002647e0(&f.t180, 1, 4, 1);
            o->fbc = f.t180;
            break;
        case 0x1700a:
            if (big == 1) {
                r->stream->FUN_002647e0(&f.t128, 1, 4, 1);
                r->stream->FUN_002647e0(&f.t158, 1, 4, 1);
                o->fc8 = FUN_002b87d0(f.t158);
                r->stream->FUN_002647e0(&f.t178, 1, 4, 1);
                o->fd4 = (float)cos((double)*(float *)&f.t178);
                r->stream->FUN_002647e0(&f.t150, 1, 4, 1);
                o->fd8 = (float)cos((double)*(float *)&f.t150);
                r->stream->FUN_002647e0(&f.t170, 1, 4, 1);
                o->fdc = (float)cos((double)*(float *)&f.t170);
                r->stream->FUN_002647e0(&f.t148, 1, 4, 1);
                o->fe0 = (float)cos((double)*(float *)&f.t148);
            }
            break;
        case 0x1700b:
            if (big == 1) {
                r->stream->FUN_002647e0(&f.t138, 1, 4, 1);
                r->stream->FUN_002647e0(&f.t168, 1, 4, 1);
                o->fcc = FUN_002b8800(f.t168);
                r->stream->FUN_002647e0(&f.t140, 1, 4, 1);
                o->fe4 = (float)cos((double)*(float *)&f.t140);
                r->stream->FUN_002647e0(&f.t144, 1, 4, 1);
                o->fe8 = (float)cos((double)*(float *)&f.t144);
                r->stream->FUN_002647e0(&f.t198, 1, 4, 1);
                o->fec = (float)cos((double)*(float *)&f.t198);
                r->stream->FUN_002647e0(&f.t14c, 1, 4, 1);
                o->ff0 = (float)cos((double)*(float *)&f.t14c);
            }
            break;
        case 0x1700c:
            if (big == 1) {
                r->stream->FUN_002647e0(&f.t134, 1, 4, 1);
                r->stream->FUN_002647e0(&f.t154, 1, 4, 1);
                o->fd0 = (f.t154 == 0x454e494c);
                r->stream->FUN_002647e0(&f.t194, 1, 4, 1);
                o->f104 = f.t194;
                r->stream->FUN_002647e0(&f.t18c, 1, 4, 1);
                o->f108 = f.t18c;
            }
            break;
        case 0x1700d:
            r->stream->FUN_002647e0(&f.t12c, 1, 4, 1);
            r->stream->FUN_002647e0(&f.t184, 1, 4, 1);
            o->ff4 = f.t184;
            r->stream->FUN_002647e0(&f.t17c, 1, 4, 1);
            o->ff8 = f.t17c;
            r->stream->FUN_002647e0(&f.t174, 1, 4, 1);
            o->ffc = f.t174;
            r->stream->FUN_002647e0(&f.t19c, 1, 4, 1);
            o->f100 = f.t19c;
            break;
        default:
            break;
        }
        r->FUN_00266be0();
    }
    return o;
}


// 0x002bb050 FUN_002bb050 (36 B): matches/0x002bb050.cpp
// sym: ??1BillboardObjectLoader_2bb050@fn_fff84c72@@QAE@XZ
BillboardObjectLoader_2bb050::~BillboardObjectLoader_2bb050() {
    vptr = hulk_at_0042e7d4;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = hulk_at_003f6098;
}


// 0x002bb080 pure3d::OldBillboardQuadGroupLoader::vfunc_2 (36 B): matches/0x002bb080.cpp
// sym: ?vfunc_5@OldBillboardQuadGroupLoader_2bb080@fn_fff84c72@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
OldBillboardQuadGroupLoader_2bb080* OldBillboardQuadGroupLoader_2bb080::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042e7c4;
    Destroy_002a3e90();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002bb0b0 FUN_002bb0b0 (1284 B): equivalent/0x002bb0b0.cpp
// sym: ?FUN_002bb0b0@fn_fff84c72@@YGPAUBase@1@PAUStream@1@PAX@Z @7fe8a3cf63ea @w4849b772cad2
// STATUS: equivalent (tools/equiv.py level 3: 2639 inputs, branch coverage 39/48, incomplete)
// FUN_002bb0b0 @ 0x002bb0b0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
Base *__stdcall FUN_002bb0b0(Stream *s, void *ctx)
{
    Frame f;
    Reader *r = s->reader;
    ((owners::X_2647e0 *)r)->FUN_002647e0((hulk_intptr)(&f.v16), (hulk_intptr)1, 4, (hulk_intptr)1);
    int kind = 0;
    for (int i = 0; i < 3; i++)
        f.pos[i] = 0;
    f.quat[0] = 0;
    f.quat[1] = 0;
    f.quat[2] = 0;
    f.quat[3] = 1.0f;
    f.f4.f = 1.0f;
    f.f8.f = 1.0f;
    f.flag = true;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int len = f.len;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.name), (hulk_intptr)len, 1, (hulk_intptr)1);
    f.name[len] = 0;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.type), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.pos), (hulk_intptr)3, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.v16), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.m88), (hulk_intptr)8, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.v40), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.v20), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.v24), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.w80), (hulk_intptr)2, 4, (hulk_intptr)1);

    while (s->FUN_002669f0()) {
        int id = s->FUN_00266a30();
        if (id == 0x17003) {
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.dummy120[1]), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.quat), (hulk_intptr)4, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.id44), (hulk_intptr)1, 4, (hulk_intptr)1);
            kind = f.id44;
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.dummy120[2]), (hulk_intptr)2, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.v48), (hulk_intptr)1, 4, (hulk_intptr)1);
            f.f4.i = f.v48;
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.v28), (hulk_intptr)1, 4, (hulk_intptr)1);
            f.f8.i = f.v28;
        } else if (id == 0x17004) {
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.dummy120[0]), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.v32), (hulk_intptr)1, 4, (hulk_intptr)1);
            f.flag = (f.v32 != 0);
        }
        s->FUN_00266be0();
    }

    Base *obj;
    bool generic = true;
    float sum = f.f8.f + f.f4.f;
    if (sum > 0.0f) {
        double c = cos((double)sum);
        if (c >= 0.0 && c <= 1.0)
            f.f8.f = (float)c;
        else
            f.f8.f = (c > 1.0) ? 1.0f : 0.0f;
        c = cos((double)f.f4.f);
        if (c >= 0.0 && c <= 1.0)
            f.f4.f = (float)c;
        else
            f.f4.f = (c > 1.0) ? 1.0f : 0.0f;

        if (kind == 0x474e53 || kind == 0x4c4244) {
            void *mem = thunk_FUN_0008d690(0x110);
            BillboardCutOffQuad_2bb0b0 *o = 0;
            if (mem)
                o = ((BillboardCutOffQuad_2bb0b0 *)mem)->FUN_002b9520();
            int a = f.f4.i;
            int b = f.f8.i;
            o->ic8 = 3;
            o->d4 = a;
            o->d8 = b;
            o->dc = a;
            o->e0 = b;
            o->icc = 0;
            obj = o;
            generic = false;
        } else if (kind == 0x4d4143) {
            void *mem = thunk_FUN_0008d690(0x110);
            BillboardCutOffQuad_2bb0b0 *o = 0;
            if (mem)
                o = ((BillboardCutOffQuad_2bb0b0 *)mem)->FUN_002b9520();
            int a = f.f4.i;
            int b = f.f8.i;
            o->ic8 = 0;
            o->icc = 3;
            o->e4 = a;
            o->e8 = b;
            o->ec = a;
            o->f0 = b;
            obj = o;
            generic = false;
        }
    }
    if (generic) {
        void *mem = thunk_FUN_0008d690(0xc8);
        obj = 0;
        if (mem)
            obj = ((Base *)mem)->FUN_002b8e80();
    }

    ((owners::Target_27b040 *)&(obj->name))->FUN_0027b040((hulk_uintptr)(f.name));

    int mode;
    switch (f.type) {
    case 0x58414f4e: mode = 0; break;
    case 0x584158: mode = 2; break;
    case 0x584159: mode = 3; break;
    case 0x5841584c: mode = 4; break;
    case 0x5841594c: mode = 5; break;
    default: mode = 1; break;
    }
    obj->b8c = f.flag;
    obj->i90 = mode;
    ((owners::Target_22be40 *)&(obj->xf))->FUN_0022be40((const int *)(f.pos));
    obj->xf.FUN_0022ba20(f.quat);
    obj->f80 = f.v40 * 0.5f;
    obj->i88 = f.v24;
    obj->v3c = f.v16;
    obj->f84 = f.v20 * 0.5f;
    for (int i = 0; i < 8; i++)
        obj->m98[i] = f.m88[i];
    obj->b8[0] = f.w80[0];
    obj->b8[1] = f.w80[1];
    return obj;
}


// 0x002bb5c0 FUN_002bb5c0 (36 B): matches/0x002bb5c0.cpp
// sym: ??1OldBillboardObjectLoader_2bb5c0@fn_fff84c72@@QAE@XZ
OldBillboardObjectLoader_2bb5c0::~OldBillboardObjectLoader_2bb5c0() {
    vptr = hulk_at_0042e7f0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    vptr = ((void**)DAT_003f6098);
}


// 0x002bb600 FUN_002bb600 (40 B): matches/0x002bb600.cpp
// sym: _FUN_002bb600
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002bb600(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}

} // namespace fn_fff84c72

// 0x002bb630 pure3d::BillboardQuad::vfunc_5 (1290 B): equivalent/0x002bb630.cpp [wrapped: conflict: pure3d::BillboardQuad]
// sym: ?vfunc_5@BillboardQuad@pure3d@fn_002bb630@@UAEXXZ @205b874508a9 @w3ed8988c26ee
namespace fn_002bb630 {
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 44/44)
// pure3d::BillboardQuad::vfunc_5 @ 0x002bb630

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


union FloatBits_2bb630 {
    float f;
    unsigned int u;
};

struct Mat_2bb630 {
    char data[0x30];
};

struct V3_2bb630 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
    void FUN_0022d210(const Mat_2bb630 *m);
};

namespace pure3d {

class BillboardQuad {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0xc];
    V3_2bb630 bmin;        // 0x10
    V3_2bb630 bmax;        // 0x1c
    V3_2bb630 ctr;         // 0x28
    float radius;   // 0x34
    char pad38[8];
    Mat_2bb630 mat;        // 0x40
    V3_2bb630 c70;         // 0x70
    char pad7c[4];
    V3_2bb630 half;        // 0x80
    char pad8c[4];
    int flag;       // 0x90
};

void BillboardQuad::vfunc_5()
{
    if (flag != 0) {
        float hx = half.x;
        float hy = half.y;
        float hz = half.z;
        ctr.ix = c70.ix;
        ctr.iy = c70.iy;
        ctr.iz = c70.iz;
        float len = (float)sqrt(hz * hz + hy * hy + hx * hx);
        radius = len;
        V3_2bb630 pn[2];
        pn[0].x = len;
        pn[0].y = len;
        pn[0].z = len;
        float nl = -len;
        pn[1].x = nl;
        pn[1].y = nl;
        pn[1].z = nl;
        pn[0].FUN_0022d210(&mat);
        pn[1].FUN_0022d210(&mat);
        V3_2bb630 &p = pn[0];
        V3_2bb630 &n = pn[1];
        bmax.x = (p.x < n.x) ? n.x : p.x;
        bmax.y = (p.y < n.y) ? n.y : p.y;
        bmax.z = (p.z < n.z) ? n.z : p.z;
        bmin.x = (p.x < n.x) ? p.x : n.x;
        bmin.y = (p.y < n.y) ? p.y : n.y;
        bmin.z = (p.z < n.z) ? p.z : n.z;
        return;
    }

    V3_2bb630 c[8];
    float zn = (half.z > 0.0f) ? -half.z : 0.0f;
    float nx = -half.x;
    c[0].x = nx;
    float ny = -half.y;
    c[0].y = ny;
    c[0].z = zn;
    zn = (half.z > 0.0f) ? -half.z : 0.0f;
    c[1].ix = half.ix;
    c[1].y = ny;
    c[1].z = zn;
    zn = (half.z > 0.0f) ? -half.z : 0.0f;
    c[2].ix = half.ix;
    c[2].iy = half.iy;
    c[2].z = zn;
    zn = (half.z > 0.0f) ? -half.z : 0.0f;
    c[3].x = nx;
    c[3].iy = half.iy;
    c[3].z = zn;
    float zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[4].x = nx;
    c[4].y = ny;
    c[4].z = zp;
    zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[5].ix = half.ix;
    c[5].y = ny;
    c[5].z = zp;
    zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[6].ix = half.ix;
    c[6].iy = half.iy;
    c[6].z = zp;
    zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[7].x = nx;
    c[7].iy = half.iy;
    c[7].z = zp;
    for (int i = 0; i < 8; i++)
        c[i].FUN_0022d210(&mat);

    bmin.iz = c[0].iz;
    bmin.ix = c[0].ix;
    bmin.iy = c[0].iy;
    bmax.ix = c[0].ix;
    bmax.iy = bmin.iy;
    bmax.iz = bmin.iz;
    for (int i = 1; i < 8; i++) {
        bmax.x = (bmax.x < c[i].x) ? c[i].x : bmax.x;
        bmax.y = (bmax.y < c[i].y) ? c[i].y : bmax.y;
        bmax.z = (bmax.z < c[i].z) ? c[i].z : bmax.z;
        bmin.x = (bmin.x < c[i].x) ? bmin.x : c[i].x;
        bmin.y = (bmin.y < c[i].y) ? bmin.y : c[i].y;
        bmin.z = (bmin.z < c[i].z) ? bmin.z : c[i].z;
    }

    float mxx = bmax.x, mxy = bmax.y, mxz = bmax.z;
    float mnx = bmin.x, mny = bmin.y, mnz = bmin.z;
    // every stage goes through the ctr members (rounded to float) in the original
    volatile float *vc = &ctr.x;
    vc[0] = mxx - mnx;
    vc[1] = mxy - mny;
    vc[2] = mxz - mnz;
    vc[0] = vc[0] * 0.5f;
    vc[1] = vc[1] * 0.5f;
    vc[2] = vc[2] * 0.5f;
    double xy = vc[0] * vc[0] + vc[1] * vc[1]; // MSVC reorders three-term sums; keep x, y, z
    float len = (float)sqrt(xy + vc[2] * vc[2]);
    FloatBits_2bb630 fb;
    fb.f = len;
    fb.u &= 0x7fffffff;
    radius = fb.f;
    vc[0] = mnx + vc[0];
    vc[1] = mny + vc[1];
    vc[2] = mnz + vc[2];
}

}
} // namespace fn_002bb630


// 0x002bbb40 FUN_002bbb40 (1595 B): equivalent/0x002bbb40.cpp [wrapped: macros]
// sym: ?FUN_002bbb40@Emitter@fn_002bbb40@@QAEXPAUQuad@2@HIIII@Z @e8296fb24bda @w9574bfde485a
namespace fn_002bbb40 {
// STATUS: equivalent (tools/equiv.py level 3: 518 inputs, branch coverage 30/33, incomplete)
// FUN_002bbb40 @ 0x002bbb40
extern "C" void __fastcall FUN_00011090(void *p);
extern "C" void __fastcall FUN_000c7920(void *p);
void __stdcall FUN_00011520(void *p, unsigned int size, int count, void(__fastcall *ctor)(void *));

struct Rng {
    Rng *FUN_0022aba0(int seed);
    hulk_freg FUN_00078780();
};
extern Rng DAT_00554bc4;
extern unsigned char DAT_00554bcc;

#define ENSURE_RNG                      \
    if (!(DAT_00554bcc & 1)) {            \
        DAT_00554bcc |= 1;                \
        DAT_00554bc4.FUN_0022aba0(0);     \
    }

struct Quad {
    char pad00[8];
    unsigned int *pos;
    char pad0c[4];
    unsigned int *col;
    unsigned int *uv;
    void FUN_0008ef00();
};

struct Mat {
    char d[0x40];
};

class Emitter {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int *a, unsigned int *b, Mat *m, unsigned int c);
    char pad04[0x34];
    unsigned char on;
    unsigned char pad39[3];
    unsigned int color;
    char xform[0x50];
    unsigned int mode90;
    int mode94;
    float uvs[8];
    float du;
    float dv;
    unsigned int c0;
    unsigned int c4;
    void FUN_002b8f60(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b90e0(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b9230(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b9310(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b98d0(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b9ac0(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b93f0(float *a, unsigned int *b, unsigned int c, int d);
    void FUN_002bbb40(Quad *q, int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6);
};

#define EmitVert(mq, mc, muv, mvert)                                 \
    do {                                                             \
        *(mq)->col = (mc);                                           \
        (mq)->uv[0] = *(const unsigned int *)&(muv)[0];              \
        ((float *)(mq)->uv)[1] = (muv)[1];                           \
        (mq)->pos[0] = *(const unsigned int *)&(mvert)[0];           \
        ((float *)(mq)->pos)[1] = (mvert)[1];                        \
        ((float *)(mq)->pos)[2] = (mvert)[2];                        \
        (mq)->FUN_0008ef00();                                        \
    } while (0)

#define EmitZero(mq)               \
    do {                           \
        *(mq)->col = 0;            \
        (mq)->uv[0] = 0;           \
        (mq)->uv[1] = 0;           \
        (mq)->pos[0] = 0;          \
        (mq)->pos[1] = 0;          \
        (mq)->pos[2] = 0;          \
        (mq)->FUN_0008ef00();      \
    } while (0)

union FI {
    float f;
    unsigned int u;
};

struct Frame {
    FI tmp0c;
    FI s10;
    FI s14;
    float uv[8];
    float vert[12];
    Mat mat;
};

void Emitter::FUN_002bbb40(Quad *q, int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
    Frame f;
    ((owners::Matrix_22ca90 *)&(f.mat))->FUN_0022ca90((const owners::Matrix_22ca90 *)xform, (const owners::Matrix_22ca90 *)(hulk_uintptr)(int)a2);
    f.s10.u = a6;
    f.s14.u = a5;
    v6(&f.s14.u, &f.s10.u, &f.mat, a3);
    if (on == 1 && f.s14.f > 0.0f && f.s10.f != 0.0f) {
        FUN_00011520(f.vert, 0xc, 4, FUN_00011090);
        switch (mode90) {
        case 0:
            FUN_002b8f60(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 2:
            FUN_002b9230(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 3:
            FUN_002b9310(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 4:
            FUN_002b98d0(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 5:
            FUN_002b9ac0(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        default:
            FUN_002b90e0(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        }
        FUN_00011520(f.uv, 8, 4, FUN_000c7920);
        switch (mode94) {
        case 1: {
            unsigned int x = c0;
            c0 = x;
            du = (float)x * (1.0f / (float)c4);
            break;
        }
        case 2:
            FUN_002b93f0(&du, &c0, c0, 1);
            break;
        case 3:
            ENSURE_RNG
            du = DAT_00554bc4.FUN_00078780();
            break;
        case 4:
            ENSURE_RNG
            dv = DAT_00554bc4.FUN_00078780();
            break;
        case 5:
            ENSURE_RNG
            du = DAT_00554bc4.FUN_00078780();
            dv = DAT_00554bc4.FUN_00078780();
            break;
        default:
            break;
        }
        f.uv[0] = uvs[0] + du;
        unsigned int col = color;
        f.uv[1] = uvs[1] + dv;
        f.uv[2] = uvs[2] + du;
        f.uv[3] = uvs[3] + dv;
        f.uv[4] = uvs[4] + du;
        f.uv[5] = uvs[5] + dv;
        f.uv[6] = uvs[6] + du;
        f.uv[7] = uvs[7] + dv;
        f.tmp0c.f = f.s14.f - 1.0f;
        f.tmp0c.u &= 0x7fffffff;
        if (!(f.tmp0c.f <= 1e-5f)) {
            const unsigned char *cb = (const unsigned char *)&color;
            f.tmp0c.u = cb[2];
            unsigned int c = (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) & 0xff;
            f.tmp0c.u = cb[3];
            c |= (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) << 8;
            f.tmp0c.u = cb[1];
            c <<= 8;
            c |= (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) & 0xff;
            f.tmp0c.u = col & 0xff;
            c <<= 8;
            c |= (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) & 0xff;
            col = c;
        }
        Quad *b = q;
        EmitVert(b, col, &f.uv[2], &f.vert[3]);
        EmitVert(b, col, &f.uv[0], &f.vert[0]);
        EmitVert(b, col, &f.uv[4], &f.vert[6]);
        EmitVert(b, col, &f.uv[4], &f.vert[6]);
        EmitVert(b, col, &f.uv[0], &f.vert[0]);
        EmitVert(b, col, &f.uv[6], &f.vert[9]);
    } else {
        Quad *b = q;
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
    }
}
} // namespace fn_002bbb40
#undef ENSURE_RNG
#undef EmitVert
#undef EmitZero


// 0x002bc1b0 pure3d::BillboardQuadGroup::vfunc_6 (531 B): equivalent/0x002bc1b0.cpp [wrapped: conflict: Gfx; pure3d::BillboardQuadGroup]
// sym: ?vfunc_6@BillboardQuadGroup@pure3d@fn_002bc1b0@@UAEXXZ @130e3f71f809 @w412667f2e34c
namespace fn_002bc1b0 {
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 20/20)
// pure3d::BillboardQuadGroup::vfunc_6 @ 0x002bc1b0
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

struct Matrix {
    float m[16];
};

struct Handle_2bc1b0 {
    char pad00[0x10];
    void *target;
};

struct Lock;

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
    virtual Lock *v30(Handle_2bc1b0 *h, int a, int b, int count, int c);
    virtual void v31(Lock *l);
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
    virtual void v60(int mode);
    virtual int v61();
    virtual void v62(int flag);
    virtual unsigned char v63();
};

class Renderer_2bc1b0 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
};

class MatrixSource_2bc1b0 {
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
    virtual Matrix *v13();
    virtual Matrix *v14();
};

struct Display_2bc1b0 {
    Renderer_2bc1b0 *renderer;
};

struct SceneNode {
    char pad00[0x18];
    MatrixSource_2bc1b0 *source;
};

struct Camera {
    char pad00[8];
    SceneNode *node;
    Matrix *FUN_0028faa0();
};


struct Quad_2bc1b0 {
    void FUN_002bbb40(Lock *lock, Matrix *view, Matrix *proj, Matrix *world, float scale, int arg);
};

struct Owner_2bc1b0 {
    char pad00[0x10];
    void *target;
};

namespace pure3d {

class BillboardQuadGroup {
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
    virtual float vfunc_11(Matrix *a, Matrix *b);

    char pad04[0x80 - 4];
    int arg80;
    Owner_2bc1b0 *owner;               // 0x84
    char disabled;              // 0x88
    unsigned char keep;         // 0x89
    char useScale;              // 0x8a
    char pad8b;
    Quad_2bc1b0 **begin;               // 0x8c
    Quad_2bc1b0 **end;                 // 0x90

    hulk_freg FUN_002ba220();
};

}

void pure3d::BillboardQuadGroup::vfunc_6()
{
    struct Frame {
        float scale;
        union {
            unsigned char flag;
            int word;
        } prev;
        int mode;
        Matrix m1;
        Matrix m2;
        Matrix m3;
    } fr;

    if ((unsigned int)(end - begin) == 0)
        return;

    fr.scale = 1.0f;
    if (useScale == 1)
        fr.scale = FUN_002ba220();

    unsigned char prev = DAT_0052c2a8->v63();
    fr.prev.flag = prev;
    if (prev != keep)
        DAT_0052c2a8->v62(keep);
    fr.mode = DAT_0052c2a8->v61();
    if (disabled == 0 && fr.mode != 1)
        DAT_0052c2a8->v60(1);

    fr.m1 = *(*(Camera**)&DAT_0052c2b4)->FUN_0028faa0();
    fr.m2 = *(*(Camera**)&DAT_0052c2b4)->node->source->v14();
    fr.m3 = *(*(Camera**)&DAT_0052c2b4)->node->source->v13();
    fr.scale = vfunc_11(&fr.m1, &fr.m2) * fr.scale;
    (*(Display_2bc1b0**)&DAT_0052c2ac)->renderer->v21(0);

    Handle_2bc1b0 *h = (Handle_2bc1b0 *)owner->target;
    Lock *lock = DAT_0052c2a8->v30(h, 0, 0x2021, (int)(end - begin) * 6, 0);
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++)
        begin[i]->FUN_002bbb40(lock, &fr.m1, &fr.m2, &fr.m3, fr.scale, arg80);
    DAT_0052c2a8->v31(lock);
    (*(Display_2bc1b0**)&DAT_0052c2ac)->renderer->v16(0);
    if (disabled == 0 && fr.mode != 1)
        DAT_0052c2a8->v60(fr.mode);
    if (fr.prev.flag != keep)
        DAT_0052c2a8->v62(fr.prev.word);
}
} // namespace fn_002bc1b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fff84c72 {

// 0x002bc430 pure3d::BillboardObjectLoader::vfunc_2 (56 B): matches/0x002bc430.cpp
// sym: ?f2@BillboardObjectLoader_2bc430@fn_fff84c72@@QAEPAV12@E@Z
BillboardObjectLoader_2bc430* BillboardObjectLoader_2bc430::f2(unsigned char flags) {
    vptr = ((void**)DAT_0042e7d4);
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = (void**)DAT_003f6098;
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x002bc4d0 pure3d::OldBillboardObjectLoader::vfunc_2 (56 B): matches/0x002bc4d0.cpp
// sym: ?v2@OldBillboardObjectLoader@fn_fff84c72@@UAEPAV12@H@Z
OldBillboardObjectLoader* OldBillboardObjectLoader::v2(int flags) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0042e7f0);
    SimpleChunkHandler_2bc4d0* r = mRef;
    if (r) {
        r->B();
        mRef = 0;
    }
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        thunk_00263f30(this);
    return this;
}

} // namespace fn_fff84c72

// 0x002bc520 FUN_002bc520 (95 B): matches/0x002bc520.cpp
// sym: ?FUN_002bc520@Buffer_2bc520@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2bc520::FUN_002bc520(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)FUN_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002bb600((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002bc580 FUN_002bc580 (75 B): matches/0x002bc580.cpp [wrapped: conflict: BillboardQuadGroup]
// sym: ??0BillboardQuadGroup@fn_002bc580@@QAE@XZ
namespace fn_002bc580 {
extern "C" void _ReadWriteBarrier();
class DrawablePrimitive_2bc580 {
  public:
    DrawablePrimitive_2bc580();
    virtual void f();
    char pad[0x3c];
};
class Sub {
  public:
    void Init_0022b980();
    char pad[0x40];
};
class BillboardQuadGroup : public DrawablePrimitive_2bc580 {
  public:
    BillboardQuadGroup();
    virtual void f();
    Sub sub;
    float scale;
    int a;
    char b, c, d, pad3;
    int e, g;
};
BillboardQuadGroup::BillboardQuadGroup() : DrawablePrimitive_2bc580() {
    scale = 1.0f;
    a = 0;
    b = 1;
    c = 0;
    d = 0;
    _ReadWriteBarrier();
    e = 0;
    g = 0;
    sub.Init_0022b980();
}
} // namespace fn_002bc580

namespace fn_fff84c72 {

// 0x002bc5d0 FUN_002bc5d0 (140 B): matches/0x002bc5d0.cpp
// sym: ??1BillboardQuadGroup_2bc5d0@fn_fff84c72@@QAE@XZ
BillboardQuadGroup_2bc5d0::~BillboardQuadGroup_2bc5d0() {
    vptr = hulk_at_0042e80c;
    _ReadWriteBarrier();
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    for (unsigned i = 0; i < (unsigned)(e - b); i++) {
        Ref_2bc5d0** p = &b[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (b)
        operator delete(b);
    Fin_002a50a0();
}

} // namespace fn_fff84c72

// 0x002bc660 FUN_002bc660 (161 B): equivalent/0x002bc660.cpp [wrapped: conflict: pure3d::BillboardCutOffQuadGroup; pure3d::BillboardQuadGroup]
// sym: ??0BillboardCutOffQuadGroup@pure3d@fn_002bc660@@QAE@XZ @15925f14b48b @wd657d179ce7f
namespace fn_002bc660 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002bc660 @ 0x002bc660
// pure3d::BillboardCutOffQuadGroup::BillboardCutOffQuadGroup @ 0x002bc660
struct Matrix {
    float m[16];
    void FUN_0022b980();
};

namespace pure3d {

class __declspec(novtable) QuadGroupBase {
public:
    virtual void v0_00038290();
    char pad04[0x3c];
    void FUN_002a5060();
    QuadGroupBase() { FUN_002a5060(); }
};

class BillboardQuadGroup : public QuadGroupBase {
public:
    Matrix transform;
    float scale;
    int f84;
    unsigned char f88;
    unsigned char f89;
    unsigned char f8a;
    char pad8b;
    int f8c;
    int f90;
    char pad94[4];
    BillboardQuadGroup() {
        scale = 1.0f;
        f84 = 0;
        f88 = 1;
        f89 = 0;
        f8a = 0;
        f8c = 0;
        f90 = 0;
        transform.FUN_0022b980();
    }
    virtual void v1();
};

class BillboardCutOffQuadGroup : public BillboardQuadGroup {
public:
    int f98, f9c, fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4, fc8;
    BillboardCutOffQuadGroup();
    virtual void v1();
};

BillboardCutOffQuadGroup::BillboardCutOffQuadGroup()
{
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    fa8 = 0;
    fac = 0;
    fb0 = 0;
    fb4 = 0;
    fb8 = 0;
    fbc = 0;
    fc0 = 0;
    fc4 = 0;
    fc8 = 0;
}

}
} // namespace fn_002bc660


// 0x002bc740 pure3d::BillboardQuadGroup::vfunc_2 (30 B): matches/0x002bc740.cpp
// sym: ??_GBillboardQuadGroup@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::BillboardQuadGroup::~BillboardQuadGroup() {}

namespace fn_fff84c72 {

// 0x002bc760 pure3d::BillboardCutOffQuadGroup::vfunc_2 (36 B): matches/0x002bc760.cpp
// sym: ?vfunc_5@BillboardCutOffQuadGroup_2bc760@fn_fff84c72@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
BillboardCutOffQuadGroup_2bc760* BillboardCutOffQuadGroup_2bc760::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042e840;
    Destroy_002bc5d0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002bc790 FUN_002bc790 (1816 B): equivalent/0x002bc790.cpp
// sym: ?FUN_002bc790@Group_2bc790@fn_fff84c72@@QAEXPAUParent_2bc790@2@PAVReader_2bc790@2@PAVFactory_2bc790@2@@Z @1f3033f32efe @w6fe0554d4bd2
// STATUS: equivalent (tools/equiv.py level 3: 15709 inputs, branch coverage 78/78)
// FUN_002bc790 @ 0x002bc790
void Group_2bc790::FUN_002bc790(Parent_2bc790 *parent, Reader_2bc790 *r, Factory_2bc790 *factory)
{
    Frame_2bc790 fr;
    char *name1 = (char *)fr.name1;
    char *name2 = (char *)fr.name2;
    fr.self = this;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.f), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n1 = fr.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)name1, (hulk_intptr)n1, 1, (hulk_intptr)1);
    name1[n1] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n2 = fr.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)name2, (hulk_intptr)n2, 1, (hulk_intptr)1);
    name2[n2] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    fr.len = fr.count != 0;
    BillboardCutOffQuadGroup_2bc790 *o;
    if (fr.len == 1) {
        void *mem = FUN_00263ea0(0xd0);
        o = 0;
        if (mem != 0)
            o = ((BillboardCutOffQuadGroup_2bc790 *)mem)->FUN_002bc660();
    } else {
        void *mem = FUN_00263ea0(0x98);
        o = 0;
        if (mem != 0)
            o = ((BillboardCutOffQuadGroup_2bc790 *)mem)->FUN_002bc580();
    }
    FUN_002a46d0(parent->p48, o);
    ((owners::Target_27b040 *)&(parent->name))->FUN_0027b040((hulk_uintptr)name1);
    ((owners::Target_27b040 *)&(o->name))->FUN_0027b040((hulk_uintptr)name1);
    unsigned __int64 id = FUN_0027b020(name2);
    new (&fr.count) content::LoadInventory_2bc790::DynamicCaster<pure3d::Shader_2bc790>();
    ::pure3d::Shader *shader = factory->v3((content::LoadInventory_2bc790::DynamicCaster<pure3d::Shader_2bc790> *)&fr.count, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found for billboard quad group \"%s\"\n", name2, name1);
        void *mem2 = FUN_00263ea0(0x20);
        shader = 0;
        if (mem2 != 0)
            shader = ((Shader_nv_2bc790*)(((::pure3d::Shader *)mem2)))->FUN_0028edf0("error", 0);
    }
    o->v8(shader);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    o->b88 = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    o->b89 = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    o->b8a = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    fr.slot1c = 0;
    fr.idx = 0;
    ((owners::Buffer_2bc520 *)&(o->list))->FUN_002bc520((unsigned int)(fr.count), (Child_2bc790 * *)((Child_2bc790 **)&fr.slot1c));

    if (!r->FUN_002669f0())
        return;
    do {
        int chunk = r->FUN_00266a30();
        if (chunk == 0x10004) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v2c), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.slot1c), (hulk_intptr)1, 4, (hulk_intptr)1);
            o->i38 = fr.slot1c;
        } else if (chunk == 0x10003) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v14), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v20), (hulk_intptr)3, 4, (hulk_intptr)1);
        } else if (chunk == 0x17005) {
            if ((unsigned int)fr.idx < (unsigned int)fr.count) {
                Child_2bc790 **slot = o->list.begin + fr.idx;
                Child_2bc790 *child = FUN_002ba8d0(r, factory);
                if (child != 0)
                    child->v0();
                if (*slot != 0)
                    (*slot)->v1();
                fr.idx++;
                *slot = child;
            }
        } else if (chunk == 0x17007) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.junkA), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(fr.q4), (hulk_intptr)4, 4, (hulk_intptr)1);
            o->mat40.FUN_0022ba20(fr.q4);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.pos), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::Target_22be40 *)&(o->mat40))->FUN_0022be40((const int *)(const Vec3_2bc790 *)(&fr.pos));
        } else if (chunk == 0x1700a) {
            if (fr.len == 1) {
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.j5), (hulk_intptr)1, 4, (hulk_intptr)1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.tag1), (hulk_intptr)1, 4, (hulk_intptr)1);
                if (fr.tag1 == 0x48544f42)
                    o->f98 = 3;
                else if (fr.tag1 == 0x54524556)
                    o->f98 = 1;
                else if (fr.tag1 == 0x545a5248)
                    o->f98 = 2;
                else
                    o->f98 = 0;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c0), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fa4 = (float)cos(fr.c0);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c1), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fa8 = (float)cos(fr.c1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c2), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fac = (float)cos(fr.c2);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c3), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fb0 = (float)cos(fr.c3);
            }
        } else if (chunk == 0x1700c) {
            if (fr.len == 1) {
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.j4), (hulk_intptr)1, 4, (hulk_intptr)1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.e2), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fa0 = fr.e2 == 0x454e494c;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.e3), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fc4 = fr.e3;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.e4), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fc8 = fr.e4;
            }
        } else if (chunk == 0x1700b) {
            if (fr.len == 1) {
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.j3), (hulk_intptr)1, 4, (hulk_intptr)1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.tag2), (hulk_intptr)1, 4, (hulk_intptr)1);
                if (fr.tag2 == 0x48544f42)
                    o->f9c = 3;
                else if (fr.tag2 == 0x54524556)
                    o->f9c = 1;
                else if (fr.tag2 == 0x545a5248)
                    o->f9c = 2;
                else
                    o->f9c = 0;
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.d1), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fb4 = (float)cos(fr.d1);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.d2), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fb8 = (float)cos(fr.d2);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.d3), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fbc = (float)cos(fr.d3);
                ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.c4), (hulk_intptr)1, 4, (hulk_intptr)1);
                o->fc0 = (float)cos(fr.c4);
            }
        } else if (chunk == 0x121204) {
            FUN_002a4b00(parent->p48, r, factory);
        } else if (chunk == 0x122000) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.junk2), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.f), (hulk_intptr)1, 4, (hulk_intptr)1);
            float v = fr.f;
            if (!(v >= 0.0f))
                v = 0.0f;
            else if (v > 1.0f)
                v = 1.0f;
            parent->f40 = v;
        }
        r->FUN_00266be0();
    } while (r->FUN_002669f0());
}

} // namespace fn_fff84c72

// 0x002bceb0 pure3d::BillboardObjectLoader::vfunc_5 (114 B): matches/0x002bceb0.cpp
// sym: ?vfunc_5@BillboardObjectLoader@pure3d@@UAEXPAX00H@Z
void pure3d::BillboardObjectLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr x) { BO ** out = (BO **)__p0; int * info = (int *)__p1; Chunk_2bceb0 * c = (Chunk_2bceb0 *)__p2;

    if (c->Id_00266c30() == 0x17006) {
        BO* o = (BO*)operator new(0x60);
        if (o) {
            o->InitBase_002a4e10(1);
            *(int**)o = &g_vt_2bceb0;
            o->f = 1.0f;
        } else {
            o = 0;
        }
        (*(Helper_2bceb0 * *)&this->f_14)->Fill_002bc790(o, c, x);
        o->Init();
        *out = o;
        info[0] = o->b;
        info[1] = o->c;
    }
}

namespace fn_fff84c72 {

// 0x002bcf30 FUN_002bcf30 (973 B): equivalent/0x002bcf30.cpp
// sym: ?FUN_002bcf30@Group_2bcf30@fn_fff84c72@@QAEXPAUParent_2bcf30@2@PAVReader_2bcf30@2@PAVFactory_2bcf30@2@@Z @3e07848dc5da @wd71bbb8aa30d
// STATUS: equivalent (tools/equiv.py level 3: 15698 inputs, branch coverage 40/40)
// FUN_002bcf30 @ 0x002bcf30
void Group_2bcf30::FUN_002bcf30(Parent_2bcf30 *parent, Reader_2bcf30 *r, Factory_2bcf30 *factory)
{
    Frame_2bcf30 fr;
    char *name1 = (char *)fr.name1;
    char *name2 = (char *)fr.name2;
    fr.self = this;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.f), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n1 = fr.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)name1, (hulk_intptr)n1, 1, (hulk_intptr)1);
    name1[n1] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n2 = fr.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)name2, (hulk_intptr)n2, 1, (hulk_intptr)1);
    name2[n2] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    bool flag1 = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    fr.len = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    fr.flag3 = fr.count != 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.count), (hulk_intptr)1, 4, (hulk_intptr)1);

    void *mem = FUN_00263ea0(0x98);
    Quad_2bcf30 *o = 0;
    if (mem != 0) {
        o = ((Quad_2bcf30 *)mem)->FUN_002bc580();
    }
    FUN_002a46d0(parent->p48, o);
    ((owners::Target_27b040 *)&(parent->name))->FUN_0027b040((hulk_uintptr)name1);
    ((owners::Target_27b040 *)&(o->name))->FUN_0027b040((hulk_uintptr)name1);
    unsigned __int64 id = FUN_0027b020(name2);
    content::LoadInventory_2bcf30::DynamicCaster<pure3d::Shader_2bcf30> caster;
    ::pure3d::Shader *shader = factory->v3(&caster, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found for billboard quad group \"%s\"\n", name2, name1);
        void *mem2 = FUN_00263ea0(0x20);
        shader = 0;
        if (mem2 != 0) {
            shader = ((Shader_nv_2bcf30*)(((::pure3d::Shader *)mem2)))->FUN_0028edf0("error", 0);
        }
    }
    o->v8(shader);
    o->b89 = fr.len;
    o->b88 = flag1;
    o->b8a = fr.flag3;
    fr.slot1c = 0;
    fr.idx = 0;
    ((owners::Buffer_2bc520 *)&(o->list))->FUN_002bc520((unsigned int)(fr.count), (Child_2bcf30 * *)((Child_2bcf30 **)&fr.slot1c));

    if (!r->FUN_002669f0()) {
        return;
    }
    do {
        int chunk = r->FUN_00266a30();
        if (chunk == 0x10004) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v2c), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.slot1c), (hulk_intptr)1, 4, (hulk_intptr)1);
            o->i38 = fr.slot1c;
        } else if (chunk == 0x10003) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v14), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&o->v20), (hulk_intptr)3, 4, (hulk_intptr)1);
        } else if (chunk == 0x17001) {
            if ((unsigned int)fr.idx < (unsigned int)fr.count) {
                Child_2bcf30 **slot = o->list.begin + fr.idx;
                Child_2bcf30 *child = FUN_002bb0b0(r, factory);
                if (child != 0) {
                    child->v0();
                }
                if (*slot != 0) {
                    (*slot)->v1();
                }
                fr.idx++;
                *slot = child;
            }
        } else if (chunk == 0x122000) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.junk), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&fr.f), (hulk_intptr)1, 4, (hulk_intptr)1);
            float v = fr.f;
            if (!(v >= 0.0f)) {
                v = 0.0f;
            } else if (v > 1.0f) {
                v = 1.0f;
            }
            parent->f40 = v;
        } else if (chunk == 0x121204) {
            FUN_002a4b00(parent->p48, r, factory);
        }
        r->FUN_00266be0();
    } while (r->FUN_002669f0());
}

} // namespace fn_fff84c72

// 0x002bd300 pure3d::OldBillboardObjectLoader::vfunc_5 (114 B): equivalent/0x002bd300.cpp [wrapped: conflict: OldBillboardObjectLoader; pure3d::BillboardObject]
// sym: ?vfunc_5@OldBillboardObjectLoader@fn_002bd300@@UAEXPAPAVDrawableContainer_2bd300@2@PAUIdPair_2bd300@2@PAUChunk@2@H@Z @1d6ee2916154 @wce78e8560790
namespace fn_002bd300 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 4/4)
// pure3d::OldBillboardObjectLoader::vfunc_5 @ 0x002bd300

// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void* thunk_FUN_0008d690(unsigned int size);

struct Chunk {
    int FUN_00266c30();
};

class DrawableContainer_2bd300 {
public:
    DrawableContainer_2bd300(int arg) throw();
    virtual void v0_00038290(); virtual void v1_000382a0(); virtual void* v2_002ba810(char); virtual void v3_002b9650();
    virtual void v4_002b9660(); virtual void v5_002a3e70(); virtual void v6_002a40d0(int, int); virtual void v7_002a4150();
    virtual void v8_002ba840(hulk_intptr, int); virtual void v9_002a4350(); virtual void v10_002a34c0(hulk_intptr); virtual void v11();
    virtual void v12_002a4570();
    char pad04[4];
    int idLo;           // 0x8
    int idHi;           // 0xc
    char pad10[0x58 - 0x10];
    float scale;        // 0x58
    char pad5c[4];
};

namespace pure3d {
class BillboardObject : public DrawableContainer_2bd300 {
public:
    BillboardObject(int arg) throw() : DrawableContainer_2bd300(arg) { scale = 1.0f; }
    virtual void v13_002a35a0(void*);
};
}

class Builder {
public:
    void FUN_002bcf30(DrawableContainer_2bd300* obj, Chunk* chunk, int arg);
};

struct IdPair_2bd300 {
    int lo, hi;
};

class OldBillboardObjectLoader {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void vfunc_5(DrawableContainer_2bd300** out, IdPair_2bd300* id, Chunk* chunk, int arg);
    char pad04[0x14 - 4];
    Builder* builder;       // 0x14
};

// equiv-map: ??0BillboardBase@@QAE@H@Z = 0x002a4e10
void OldBillboardObjectLoader::vfunc_5(DrawableContainer_2bd300** out, IdPair_2bd300* id, Chunk* chunk, int arg)
{
    if (chunk->FUN_00266c30() != 0x17002)
        return;
    void* mem = thunk_FUN_0008d690((int)sizeof(pure3d::BillboardObject));
    DrawableContainer_2bd300* obj = 0;
    if (mem != 0)
        obj = new (mem) pure3d::BillboardObject(1);
    builder->FUN_002bcf30(obj, chunk, arg);
    obj->v12_002a4570();
    *out = obj;
    id->lo = obj->idLo;
    id->hi = obj->idHi;
}
} // namespace fn_002bd300

