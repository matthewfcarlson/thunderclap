// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fa6b0..0x002fb600 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6175a11 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6175a11 {} using namespace fn_f6175a11;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f6175a11 {
struct V3_2fa6b0 {
    float x, y, z;
    void FUN_0022d180();
};
class Thing {
  public:
    volatile int a, b, c;
    char d, e, f, g;
    volatile short h, i, j, k;
    Thing();
};
struct Vec_2fa7c0 { float x,y,z; };
struct Mesh_2fa7c0 { char pad[8]; Vec_2fa7c0* vertices; char pad2[12]; char* faces; };
struct Context { char pad[0x44]; Mesh_2fa7c0* mesh; };
struct Shape_2fa7c0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int v4(); char pad[0x24]; char data[1]; };
extern "C" void __cdecl FUN_002fa6b0(const void *, const void *, const void *, void *);
extern "C" bool __cdecl FUN_0035a4c0(int,void*,Vec_2fa7c0*,Vec_2fa7c0*,Vec_2fa7c0*,Vec_2fa7c0*,float*,Vec_2fa7c0*,Vec_2fa7c0*,bool,bool,bool);
struct Manager_2fa7c0 { void FUN_00304530(Shape_2fa7c0*,unsigned,float,Vec_2fa7c0*,Vec_2fa7c0*,Context*,int); };
struct Global_2fa7c0 { char pad[HULK_PW_BUFFER]; Manager_2fa7c0 manager; };  // (x64t4) decls/physics_world.h
struct Face_2fa7c0 { char pad[0x10]; unsigned short a,b,c,flags; bool run(Shape_2fa7c0*,Context*,int); };
struct V3_2fa8c0 {
    float x, y, z;
};
union BoolWord {
    char b;
    int w;
};
struct MeshData_2fa8c0 {
    char pad00[8];
    V3_2fa8c0* verts;
    char pad0c[0xc];
    char* tris;
};
struct Mesh_2fa8c0 {
    char pad00[0x44];
    MeshData_2fa8c0* data;
};
struct Hit_2fa8c0 {
    char pad00[0x38];
    char part38[0xc];
    char part44[0xc];
    float f50;
    float f54;
    char useAlt;
};
struct Tri_2fa8c0 {
    char pad00[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short flags;
    char pad18[0];
};
struct Tracker_2fa8c0 {
    void FUN_00304530(Hit_2fa8c0* hit, unsigned int index, float f, V3_2fa8c0* a, V3_2fa8c0* b, Mesh_2fa8c0* mesh, int flags);
};
struct Scene_2fa8c0 {
    char pad00[HULK_PW_BUFFER];  // (x64t4) decls/physics_world.h
    Tracker_2fa8c0 tracker;
};
extern "C" char FUN_00358b10(void* p38, void* p44, float v1, float v0, V3_2fa8c0* a0, V3_2fa8c0* a1, V3_2fa8c0* a2, V3_2fa8c0* normal, float* out, V3_2fa8c0* l0c, V3_2fa8c0* l18, int b1, int b2, int b4);
char FUN_00358700(void* p38, void* p44, float v1, float v0, V3_2fa8c0* a0, V3_2fa8c0* a1, V3_2fa8c0* a2, V3_2fa8c0* normal, float* out, V3_2fa8c0* l0c, V3_2fa8c0* l18, int b1, int b2, int b4);
struct TriRef {
    char pad00[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short flags;
    char pad18[8];
    char FUN_002fa8c0(Hit_2fa8c0* hit, Mesh_2fa8c0* mesh, int flags);
};
struct Vec3_2fae50 { float x, y, z; };
struct Triangle_2fae50 {
    Vec3_2fae50 a;
    Vec3_2fae50 b;
    Vec3_2fae50 c;
};
class Obj {
  public:
    char pad[16];
    unsigned short a, b, c, d;
    Obj(unsigned short x, unsigned short y, unsigned short z);
};
struct Children_2fb370 { Node** begin; Node** end; };
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual int kind();
 char padding[16]; Children_2fb370* children;
};
struct Handler_2fb370 {
 bool FUN_002fa8c0(Node*, void*, void*);
 bool FUN_002faa30(Node*, void*, void*);
 bool FUN_002fb000(Node*, void*, void*);
 bool FUN_002fb370(Node*, void*, void*);
};
struct Part_2fb5d0 {
    void Init_0030ea00();
};
struct CollisionOBB {
    hulk_uintptr v;
    char pad[0x38];
    Part_2fb5d0 b;
    char pad2[0x3f];
    Part_2fb5d0 a;
    void Target();
    void Base_00306ac0();
};


// 0x002fa6b0 FUN_002fa6b0 (112 B): equivalent/0x002fa6b0.cpp
// sym: _FUN_002fa6b0 @fe9060f50631 @wf7461ef99346
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 0/0)
// FUN_002fa6b0 @ 0x002fa6b0
// out = normalised cross product (a - b) x (a - c)
// x87: the differences to c and the z difference to b stay in registers (53 bits); the x and y differences to b
// go through the frame (rounded)
extern "C" void FUN_002fa6b0(const void * a, const void * b, const void * c, void * out)
{
    hulk_freg dx = ((const V3_2fa6b0 *)a)->x - ((const V3_2fa6b0 *)c)->x;
    hulk_freg dy = ((const V3_2fa6b0 *)a)->y - ((const V3_2fa6b0 *)c)->y;
    hulk_freg dz = ((const V3_2fa6b0 *)a)->z - ((const V3_2fa6b0 *)c)->z;
    volatile float e[3];
    e[0] = ((const V3_2fa6b0 *)a)->x - ((const V3_2fa6b0 *)b)->x;
    e[1] = ((const V3_2fa6b0 *)a)->y - ((const V3_2fa6b0 *)b)->y;
    hulk_freg ez = ((const V3_2fa6b0 *)a)->z - ((const V3_2fa6b0 *)b)->z;
    ((V3_2fa6b0 *)out)->x = e[1] * dz - ez * dy;
    ((V3_2fa6b0 *)out)->y = ez * dx - dz * e[0];
    ((V3_2fa6b0 *)out)->z = e[0] * dy - e[1] * dx;
    ((V3_2fa6b0 *)out)->FUN_0022d180();
}


// 0x002fa720 FUN_002fa720 (48 B): matches/0x002fa720.cpp
// sym: ??0Thing@fn_f6175a11@@QAE@XZ
Thing::Thing() {
    h = 0;
    i = 1;
    j = 2;
    c = -1;
    b = -1;
    a = -1;
    f = 0;
    e = 0;
    d = 0;
    g = 0;
    k = 0;
}


// 0x002fa750 FUN_002fa750 (1 B): matches/0x002fa750.cpp
// sym: ?FUN_002fa750@fn_f6175a11@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002fa750() {}


// 0x002fa7c0 FUN_002fa7c0 (252 B): equivalent/0x002fa7c0.cpp
// sym: ?run@Face_2fa7c0@fn_f6175a11@@QAE_NPAUShape_2fa7c0@2@PAUContext@2@H@Z @1ea6fc07cf1f @wf72072274f62
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fa7c0 @ 0x002fa7c0
bool Face_2fa7c0::run(Shape_2fa7c0* shape,Context* context,int arg) {
 Vec_2fa7c0* vertices=context->mesh->vertices;
 Vec_2fa7c0* p0=vertices+a; Vec_2fa7c0* p1=vertices+b; Vec_2fa7c0* p2=vertices+c;
 Vec_2fa7c0 normal,outA,outB; float value;
 FUN_002fa6b0((Vec_2fa7c0 *)p0,(Vec_2fa7c0 *)p1,(Vec_2fa7c0 *)p2,(Vec_2fa7c0 *)(&normal));
 bool f0=(flags&1)!=0, f1=(flags&2)!=0, f2=(flags&4)!=0;
 bool result=FUN_0035a4c0(shape->v4(),shape->data,p0,p1,p2,&normal,&value,&outB,&outA,f0,f1,f2);
 if(result) {
 unsigned index=(unsigned)((char*)this-context->mesh->faces)/24;
 (*(Global_2fa7c0**)&DAT_00554c14)->manager.FUN_00304530(shape,index,value,&outB,&outA,context,arg);
 }
 return result;
}


// 0x002fa8c0 FUN_002fa8c0 (357 B): equivalent/0x002fa8c0.cpp
// sym: ?FUN_002fa8c0@TriRef@fn_f6175a11@@QAEDPAUHit_2fa8c0@2@PAUMesh_2fa8c0@2@H@Z @21fade602439 @wece6a1ae3dda
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_002fa8c0 @ 0x002fa8c0
char TriRef::FUN_002fa8c0(Hit_2fa8c0* hit, Mesh_2fa8c0* mesh, int flags2)
{
    struct Frame {
        float v1;
        float out;
        BoolWord b4;
        BoolWord b2;
        BoolWord b1;
        int flag;
        V3_2fa8c0 normal;
        char pad24[8];
        V3_2fa8c0* a2;
        V3_2fa8c0 l18;
        V3_2fa8c0 l0c;
    } f;
    V3_2fa8c0* verts = mesh->data->verts;
    V3_2fa8c0* a0 = &verts[i0];
    V3_2fa8c0* a1 = &verts[i1];
    f.a2 = &verts[i2];
    FUN_002fa6b0((V3_2fa8c0 *)a0, (V3_2fa8c0 *)a1, (V3_2fa8c0 *)(f.a2), (V3_2fa8c0 *)(&f.normal));
    f.b1.b = (flags & 1) != 0;
    f.b2.b = (flags & 2) == 2;
    f.b4.b = (flags & 4) == 4;
    f.v1 = hit->f54;
    float v0 = hit->f50;
    f.flag = flags2 & 1;
    if (f.flag) {
        f.v1 = DAT_004d2cb4 + f.v1;
        v0 = DAT_004d2cb4 + v0;
    }
    char ok;
    if (hit->useAlt)
        ok = FUN_00358b10(hit->part38, hit->part44, f.v1, v0, a0, a1, f.a2, &f.normal, &f.out, &f.l0c, &f.l18, f.b1.w, f.b2.w, f.b4.w);
    else
        ok = FUN_00358700(hit->part38, hit->part44, f.v1, v0, a0, a1, f.a2, &f.normal, &f.out, &f.l0c, &f.l18, f.b1.w, f.b2.w, f.b4.w);
    if (f.flag)
        f.out = DAT_004d2cb4 + f.out;
    if (ok) {
        unsigned int index = (unsigned int)((char*)this - mesh->data->tris) / 0x18;
        (*(Scene_2fa8c0**)&DAT_00554c14)->tracker.FUN_00304530(hit, index, f.out, &f.l0c, &f.l18, mesh, flags2);
    }
    return ok;
}

} // namespace fn_f6175a11

// 0x002faa30 FUN_002faa30 (1048 B): equivalent/0x002faa30.cpp [wrapped: conflict: Context]
// sym: ?FUN_002faa30@Tri_2faa30@fn_002faa30@@QAEDPAVShape_2faa30@2@PAUContext@2@H@Z @d468d296dd13 @w8be3e03a04dc
namespace fn_002faa30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_002faa30 @ 0x002faa30

struct V3_2faa30 {
    float x, y, z;
};

struct Box_2faa30 {
    V3_2faa30 lo;
    V3_2faa30 hi;
};

struct Tri_2faa30;

struct Mesh_2faa30 {
    char pad0[8];
    V3_2faa30 *verts;
    char pad1[0x18 - 0xc];
    Tri_2faa30 *tris;
};

struct Context {
    char pad[0x44];
    Mesh_2faa30 *mesh;
};

struct Basis_2faa30 {
    V3_2faa30 pos;
    char pad0c[0xc];
    V3_2faa30 axisX;                        // 0x18
    V3_2faa30 axisY;                        // 0x24
    V3_2faa30 axisZ;                        // 0x30
};

class Shape_2faa30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_2faa30 *v4();                // the shape's reference point
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
    virtual Basis_2faa30 *v15();
    char pad04[0x28 - 4];
    V3_2faa30 half;                         // 0x28
    char pad34[0x48 - 0x34];
    V3_2faa30 f48;                          // 0x48
};

struct Registry_2faa30 {
    char FUN_00304530(Shape_2faa30 *shape, unsigned int index, float depth, V3_2faa30 *o1, V3_2faa30 *o2, Context *ctx, int flags);
};
struct Manager_2faa30 {
    char pad[HULK_PW_BUFFER];  // (x64t4) decls/physics_world.h
    Registry_2faa30 reg;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_002fa6b0(const void *, const void *, const void *, void *);
extern "C" char FUN_0035a2a0(V3_2faa30 *a1, V3_2faa30 *a2, V3_2faa30 *axisX, V3_2faa30 *axisY, V3_2faa30 *axisZ, V3_2faa30 *v0, V3_2faa30 *v1, V3_2faa30 *v2, V3_2faa30 *normal,
                  float *depth, V3_2faa30 *centre, V3_2faa30 *outN, int f1, int f2, int f4);

union Flag_2faa30 {
    char b;
    int w;
};

struct Frame_2faa30 {
    V3_2faa30 v2;
    V3_2faa30 v1;
    Box_2faa30 tri;
    float depth;
    V3_2faa30 vB;
    V3_2faa30 pt;
    V3_2faa30 v0;
    Box_2faa30 sb;
    char pad70[0x88 - 0x70];
    Flag_2faa30 f4;
    Flag_2faa30 f2;
    Flag_2faa30 f1;
    Basis_2faa30 *t2;
    Basis_2faa30 *t3;
    V3_2faa30 normal;
    V3_2faa30 centre;
    V3_2faa30 outN;
};

class Tri_2faa30 {
public:
    char FUN_002faa30(Shape_2faa30 *shape, Context *ctx, int flags);
    char pad0[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short triFlags;
    char pad1[8];
};

char Tri_2faa30::FUN_002faa30(Shape_2faa30 *shape, Context *ctx, int flags)
{
    Frame_2faa30 f;
    V3_2faa30 *verts = ctx->mesh->verts;
    f.v0 = verts[i0];
    f.v1 = verts[i1];
    f.v2 = verts[i2];

    if (f.v0.x < f.v1.x) {
        f.tri.lo.x = f.v0.x;
        f.tri.hi.x = f.v1.x;
    } else {
        f.tri.hi.x = f.v0.x;
        f.tri.lo.x = f.v1.x;
    }
    if (f.tri.lo.x > f.v2.x)
        f.tri.lo.x = f.v2.x;
    else if (f.tri.hi.x < f.v2.x)
        f.tri.hi.x = f.v2.x;

    if (f.v0.y < f.v1.y) {
        f.tri.lo.y = f.v0.y;
        f.tri.hi.y = f.v1.y;
    } else {
        f.tri.hi.y = f.v0.y;
        f.tri.lo.y = f.v1.y;
    }
    if (f.tri.lo.y > f.v2.y)
        f.tri.lo.y = f.v2.y;
    else if (f.tri.hi.y < f.v2.y)
        f.tri.hi.y = f.v2.y;

    if (f.v0.z < f.v1.z) {
        f.tri.lo.z = f.v0.z;
        f.tri.hi.z = f.v1.z;
    } else {
        f.tri.hi.z = f.v0.z;
        f.tri.lo.z = f.v1.z;
    }
    if (f.tri.lo.z > f.v2.z)
        f.tri.lo.z = f.v2.z;
    else if (f.tri.hi.z < f.v2.z)
        f.tri.hi.z = f.v2.z;

    f.pt = *shape->v4();
    f.sb.hi.x = shape->half.x + f.pt.x;
    f.sb.hi.y = shape->half.y + f.pt.y;
    f.sb.hi.z = shape->half.z + f.pt.z;
    f.sb.lo.x = f.pt.x - shape->half.x;
    f.sb.lo.y = f.pt.y - shape->half.y;
    f.sb.lo.z = f.pt.z - shape->half.z;
    if (!((char)((owners::Box_2f3360 *)&(f.tri))->FUN_002f3360((owners::Box_2f3360 *)(Box_2faa30 *)(&f.sb))))
        return 0;

    FUN_002fa6b0((V3_2faa30 *)(&f.v0), (V3_2faa30 *)(&f.v1), (V3_2faa30 *)(&f.v2), (V3_2faa30 *)(&f.normal));

    f.f1.b = (triFlags & 1) != 0;
    f.f2.b = (triFlags & 2) == 2;
    f.f4.b = (triFlags & 4) == 4;
    int touch = flags & 1;
    f.vB = shape->f48;
    if (touch) {
        f.vB.x = f.vB.x + DAT_004d2cb4;
        f.vB.y = f.vB.y + DAT_004d2cb4;
        f.vB.z = f.vB.z + DAT_004d2cb4;
    }
    Basis_2faa30 *b1 = shape->v15();
    f.t2 = shape->v15();
    f.t3 = shape->v15();
    Basis_2faa30 *b4 = shape->v15();
    char hit = FUN_0035a2a0(&b4->pos, &f.vB, &f.t3->axisX, &f.t2->axisY, &b1->axisZ, &f.v0, &f.v1, &f.v2,
                            &f.normal, &f.depth, &f.centre, &f.outN, f.f1.w, f.f2.w, f.f4.w);
    if (touch)
        f.depth = f.depth + DAT_004d2cb4;
    if (hit) {
        unsigned int index = (unsigned int)((char *)this - (char *)ctx->mesh->tris) / 24;
        (*(Manager_2faa30**)&DAT_00554c14)->reg.FUN_00304530(shape, index, f.depth, &f.centre, &f.outN, ctx, flags);
    }
    return hit;
}
} // namespace fn_002faa30

namespace fn_f6175a11 {

// 0x002fae50 FUN_002fae50 (424 B): equivalent/0x002fae50.cpp
// sym: _FUN_002fae50 @f00424348853 @wa15839fc26f3
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_002fae50 @ 0x002fae50
// Moeller-Trumbore ray / triangle test; *outT receives the hit distance.
// volatile floats are values the original spills to the stack (rounded to 32 bits); doubles are values it
// keeps in x87 registers.
extern "C" bool FUN_002fae50(const void *tri, const void *origin, const void * dir_, float *outT)
{
    const Vec3_2fae50 * dir = (const Vec3_2fae50 *)dir_;
    volatile float e1x = ((const Triangle_2fae50 *)tri)->b.x - ((const Triangle_2fae50 *)tri)->a.x;
    volatile float e1y = ((const Triangle_2fae50 *)tri)->b.y - ((const Triangle_2fae50 *)tri)->a.y;
    volatile float e1z = ((const Triangle_2fae50 *)tri)->b.z - ((const Triangle_2fae50 *)tri)->a.z;
    volatile float e2x = ((const Triangle_2fae50 *)tri)->c.x - ((const Triangle_2fae50 *)tri)->a.x;
    volatile float e2y = ((const Triangle_2fae50 *)tri)->c.y - ((const Triangle_2fae50 *)tri)->a.y;
    volatile float e2z = ((const Triangle_2fae50 *)tri)->c.z - ((const Triangle_2fae50 *)tri)->a.z;

    double px = (double)e2z * dir->y - (double)e2y * dir->z;
    double py = (double)e2x * dir->z - (double)e2z * dir->x;
    double pz = (double)e2y * dir->x - (double)e2x * dir->y;

    double detx = (double)e1z * pz;
    detx = detx + (double)e1y * py;
    detx = detx + (double)e1x * px;
    volatile float det = (float)detx;
    if (detx < 1e-5f)
        return false;

    volatile float sx = ((const Vec3_2fae50 *)origin)->x - ((const Triangle_2fae50 *)tri)->a.x;
    volatile float sy = ((const Vec3_2fae50 *)origin)->y - ((const Triangle_2fae50 *)tri)->a.y;
    double szx = (double)((const Vec3_2fae50 *)origin)->z - ((const Triangle_2fae50 *)tri)->a.z;
    volatile float sz = (float)szx;

    double ud = szx * pz;
    ud = ud + (double)sy * py;
    ud = ud + (double)sx * px;
    volatile float u = (float)ud;
    if (u < 0.0f)
        return false;
    if (u > det)
        return false;

    volatile float qx = sy * e1z - sz * e1y;
    volatile float qy = sz * e1x - e1z * sx;
    double qzx = (double)sx * e1y - (double)sy * e1x;
    volatile float qz = (float)qzx;

    double v = qzx * dir->z;
    v = v + (double)qx * dir->x;
    v = v + (double)qy * dir->y;
    if (v < 0.0f)
        return false;
    if ((double)u + v > det)
        return false;

    double t = (double)qz * e2z;
    t = t + (double)qy * e2y;
    t = t + (double)qx * e2x;
    *outT = (float)(t / det);
    return true;
}

} // namespace fn_f6175a11

// 0x002fb000 FUN_002fb000 (311 B): equivalent/0x002fb000.cpp [wrapped: conflict: Context]
// sym: ?run@Tri_2fb000@fn_002fb000@@QAEDPAVShape_2fb000@2@PAUContext@2@H@Z @1419d48d3b3e @w58b65099d526
namespace fn_002fb000 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_002fb000 @ 0x002fb000
// FUN_002fb000 @ 0x002fb000

struct V3_2fb000 { float x, y, z; };

struct Tri_2fb000;

struct Mesh_2fb000 {
    char pad0[8];
    V3_2fb000* verts;
    char pad1[0x18 - 0xc];
    Tri_2fb000* tris;
};

struct Context {
    char pad[0x44];
    Mesh_2fb000* mesh;
};

class Shape_2fb000 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_2fb000* v4(); // the shape's reference point, tested against the triangle
};

struct Registry_2fb000 {
    char FUN_00304530(Shape_2fb000* shape, unsigned int index, float depth, V3_2fb000* o1, V3_2fb000* o2, Context* ctx, int flags);
};
struct Manager_2fb000 { char pad[HULK_PW_BUFFER]; Registry_2fb000 reg; };  // (x64t4) decls/physics_world.h

extern "C++" __declspec(nothrow) void __cdecl FUN_002fa6b0(const void *, const void *, const void *, void *);
extern "C" char FUN_00359260(V3_2fb000* ref, float margin, V3_2fb000* a, V3_2fb000* b, V3_2fb000* c, V3_2fb000* n, float* depth, V3_2fb000* o1, V3_2fb000* o2,
                  int f1, int f2, int f3);

union Flag_2fb000 { char b; int w; };
struct Frame_2fb000 {
    float margin;
    float depth;
    Flag_2fb000 f3;
    Flag_2fb000 f2;
    Flag_2fb000 f1;
    int touch;
    V3_2fb000 normal;
    V3_2fb000 o2;
    V3_2fb000 o1;
};

class Tri_2fb000 {
public:
    char run(Shape_2fb000* shape, Context* ctx, int flags);
    char pad0[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short triFlags;
    char pad1[8];
};

char Tri_2fb000::run(Shape_2fb000* shape, Context* ctx, int flags)
{
    Frame_2fb000 f;
    V3_2fb000* verts = ctx->mesh->verts;
    V3_2fb000* v0 = &verts[i0];
    V3_2fb000* v1 = &verts[i1];
    V3_2fb000* v2 = &verts[i2];

    FUN_002fa6b0((V3_2fb000 *)v0, (V3_2fb000 *)v1, (V3_2fb000 *)v2, (V3_2fb000 *)(&f.normal));

    f.f1.b = (triFlags & 1) != 0;
    f.f2.b = (triFlags & 2) == 2;
    f.f3.b = (triFlags & 4) == 4;
    f.margin = *(float*)((char*)shape + 0x34);
    f.touch = flags & 1;
    if (f.touch)
        f.margin = 0.02f + f.margin;

    char hit = FUN_00359260(shape->v4(), f.margin, v0, v1, v2, &f.normal, &f.depth, &f.o1, &f.o2,
                             f.f1.w, f.f2.w, f.f3.w);
    if (f.touch)
        f.depth = 0.02f + f.depth;
    if (hit) {
        unsigned int index = (unsigned int)((char*)this - (char*)ctx->mesh->tris) / 24;
        (*(Manager_2fb000**)&DAT_00554c14)->reg.FUN_00304530(shape, index, f.depth, &f.o1, &f.o2, ctx, flags);
    }
    return hit;
}
} // namespace fn_002fb000

namespace fn_f6175a11 {

// 0x002fb160 FUN_002fb160 (38 B): matches/0x002fb160.cpp
// sym: ??0Obj@fn_f6175a11@@QAE@GGG@Z
Obj::Obj(unsigned short x, unsigned short y, unsigned short z) {
    a = x;
    b = y;
    c = z;
    d = 7;
}

} // namespace fn_f6175a11

// 0x002fb190 FUN_002fb190 (478 B): equivalent/0x002fb190.cpp [wrapped: conflict: Context]
// sym: ?run@Tri_2fb190@fn_002fb190@@QAEDPAUV3_2fb190@2@PAUContext@2@H@Z @e8612663097d @w8a0c3af0114a
namespace fn_002fb190 {
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 6/6)
// FUN_002fb190 @ 0x002fb190

struct V3_2fb190 { float x, y, z; };

struct Tri_2fb190;

struct Mesh_2fb190 {
    char pad0[8];
    V3_2fb190* verts;
    char pad1[0x18 - 0xc];
    Tri_2fb190* tris;
};

struct Context {
    char pad[0x44];
    Mesh_2fb190* mesh;
};

struct CollisionRay_2fb190 {
    char data[0x84];
    void FUN_00306ef0(const V3_2fb190* origin, const V3_2fb190* dir, unsigned int mask);
    void FUN_00306fb0();
};

struct Registry_2fb190 {
    char FUN_00304530(CollisionRay_2fb190* shape, unsigned int index, float depth, V3_2fb190* o1, V3_2fb190* o2, Context* ctx, int flags);
};
struct Manager_2fb190 { char pad[HULK_PW_BUFFER]; Registry_2fb190 reg; };  // (x64t4) decls/physics_world.h

extern "C++" __declspec(nothrow) void __cdecl FUN_002fa6b0(const void *, const void *, const void *, void *);

class Tri_2fb190 {
public:
    char run(V3_2fb190* p, Context* ctx, int flags);
    char pad0[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short triFlags;
    char pad1[8];
};

static inline float absf(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}

// x87: the three edge tests and the plane distance stay in registers (53 bits)
char Tri_2fb190::run(V3_2fb190* p, Context* ctx, int flags)
{
    struct Frame {
        float diff;
        V3_2fb190 n;
        V3_2fb190 hit;
        V3_2fb190 dir;
        CollisionRay_2fb190 obj;
    } f;
    V3_2fb190* verts = ctx->mesh->verts;
    V3_2fb190* v0 = &verts[i0];
    V3_2fb190* v1 = &verts[i1];
    V3_2fb190* v2 = &verts[i2];

    hulk_freg t1 = (v2->z - v1->z) * (p->x - v1->x) - (v2->x - v1->x) * (p->z - v1->z);
    hulk_freg t2 = (v1->z - v0->z) * (p->x - v0->x) - (p->z - v0->z) * (v1->x - v0->x);
    if (!(t2 * t1 >= 0.0f))
        return 0;
    hulk_freg t3 = (v0->z - v2->z) * (p->x - v2->x) - (p->z - v2->z) * (v0->x - v2->x);
    if (!(t3 * t1 >= 0.0f))
        return 0;

    FUN_002fa6b0((V3_2fb190 *)v0, (V3_2fb190 *)v1, (V3_2fb190 *)v2, (V3_2fb190 *)(&f.n));
    if (absf(f.n.y) <= 1e-5f)
        return 0;

    hulk_freg plane = f.n.y * v0->y + f.n.x * v0->x + f.n.z * v0->z;
    f.hit.x = p->x;
    f.hit.z = p->z;
    f.dir.x = 0.0f;
    f.dir.y = -1.0f;
    f.dir.z = 0.0f;
    double neg = -plane;
    double part = neg + f.n.z * p->z;
    f.hit.y = (float)((part + f.n.x * p->x) * (-1.0f / f.n.y));
    f.diff = p->y - f.hit.y;

    f.obj.FUN_00306ef0(p, &f.dir, 0x5368d4a5);
    unsigned int index = (unsigned int)((char*)this - (char*)ctx->mesh->tris) / 24;
    (*(Manager_2fb190**)&DAT_00554c14)->reg.FUN_00304530(&f.obj, index, f.diff, &f.hit, &f.n, ctx, flags);
    f.obj.FUN_00306fb0();
    return 1;
}
} // namespace fn_002fb190

namespace fn_f6175a11 {

// 0x002fb370 FUN_002fb370 (195 B): equivalent/0x002fb370.cpp
// sym: ?FUN_002fb370@Handler_2fb370@fn_f6175a11@@QAE_NPAUNode@2@PAX1@Z @4546331bcf05 @wa7a87d1afb05
// STATUS: equivalent (tools/equiv.py level 3: 277 inputs, branch coverage 12/12)
// FUN_002fb370 @ 0x002fb370
bool Handler_2fb370::FUN_002fb370(Node* node, void* arg, void* arg2) {
 bool result=false;
 Children_2fb370* children=node->children;
 if(children) {
  unsigned int i=0;
  while(i < (unsigned int)(children->end-children->begin)) {
   result=FUN_002fb370(children->begin[i],arg,arg2);
   ++i;
  }
 }
 switch(node->kind()) {
 case 2: return FUN_002fa8c0(node,arg,arg2);
 case 5: return FUN_002faa30(node,arg,arg2);
 case 7: return FUN_002fb000(node,arg,arg2);
 }
 return result;
}

} // namespace fn_f6175a11

// 0x002fb440 FUN_002fb440 (368 B): equivalent/0x002fb440.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002fb440@Tri_2fb440@fn_002fb440@@QAE_NPAVRay_2fb440@2@PAUMesh_2fb440@2@H@Z @83194ab6a4aa @wd4dfa88f52a6
namespace fn_002fb440 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002fb440 @ 0x002fb440

struct V3_2fb440 { float x, y, z; };
class Ray_2fb440 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3_2fb440* GetOrigin();
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
    virtual V3_2fb440* GetDirection();
    virtual float GetLength();
};
struct Tri_2fb440 {
    char pad0[0x10];
    unsigned short idx[3];
    char pad16[2];
    bool FUN_002fb440(Ray_2fb440* ray, struct Mesh_2fb440* mesh, int flags);
};
struct MeshData_2fb440 {
    char pad0[8];
    V3_2fb440* verts;
    char padc[0x18 - 0xc];
    Tri_2fb440* tris;
};
struct Mesh_2fb440 {
    char pad0[0x44];
    MeshData_2fb440* data;
};
struct Hitter {
    void FUN_00304530(Ray_2fb440* ray, hulk_uintptr index, float t, V3_2fb440* point, V3_2fb440* normal, Mesh_2fb440* mesh, int flags);
};
struct Globals_2fb440 {
    char pad0[HULK_PW_BUFFER];  // (x64t4) decls/physics_world.h
    Hitter hitter;
};
extern "C++" __declspec(nothrow) bool __cdecl FUN_002fae50(const void *, const void *, const void *, float *);
extern "C++" __declspec(nothrow) void __cdecl FUN_002fa6b0(const void *, const void *, const void *, void *);

bool Tri_2fb440::FUN_002fb440(Ray_2fb440* ray, Mesh_2fb440* mesh, int flags)
{
    V3_2fb440 tri[3];
    V3_2fb440* verts = mesh->data->verts;
    tri[0] = verts[idx[0]];
    tri[1] = verts[idx[1]];
    tri[2] = verts[idx[2]];
    float t;
    V3_2fb440* dir = ray->GetDirection();
    V3_2fb440* org = ray->GetOrigin();
    bool hit = FUN_002fae50((V3_2fb440 *)tri, (V3_2fb440 *)org, (V3_2fb440 *)dir, &t);
    if (!(t >= 0.0f))
        return false;
    if (!(ray->GetLength() >= t))
        return false;
    if (!hit)
        return false;
    V3_2fb440 normal;
    V3_2fb440 point;
    FUN_002fa6b0((V3_2fb440 *)(&tri[0]), (V3_2fb440 *)(&tri[1]), (V3_2fb440 *)(&tri[2]), (V3_2fb440 *)(&normal));
    V3_2fb440* d2 = ray->GetDirection();
    V3_2fb440* o2 = ray->GetOrigin();
    point.x = t * d2->x + o2->x;
    point.y = t * d2->y + o2->y;
    point.z = t * d2->z + o2->z;
    hulk_uintptr index = ((hulk_uintptr)this - (hulk_uintptr)mesh->data->tris) / 0x18;
    (*(Globals_2fb440**)&DAT_00554c14)->hitter.FUN_00304530(ray, index, t, &point, &normal, mesh, flags);
    return hit;
}
} // namespace fn_002fb440

namespace fn_f6175a11 {

// 0x002fb5d0 FUN_002fb5d0 (33 B): matches/0x002fb5d0.cpp
// sym: ?Target@CollisionOBB@fn_f6175a11@@QAEXXZ
void CollisionOBB::Target() {
    v = ((hulk_intptr)DAT_004317dc);
    a.Init_0030ea00();
    b.Init_0030ea00();
    Base_00306ac0();
}

} // namespace fn_f6175a11
