// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00301650..0x00302fa0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f617c19c {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f617c19c {} using namespace fn_f617c19c;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f617c19c {
struct Vec3_301650 {
    float x, y, z;
};
class Shape_301650 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_301650 *GetPos();
    virtual void v5();
    virtual int GetType();
    char pad4[0x24];
    Vec3_301650 normal;
    char pad34[4];
    Vec3_301650 dir;
};
class Contact_301650 {
public:
    char pad0[0xc];
    float f0c;
    char pad10[4];
    Vec3_301650 delta;
    char pad20[0xc];
    float dist;

    // equiv-conv: FUN_00314be0 ecx stack stack stack stack stack stack
    void FUN_00314be0(Shape_301650 *a, Vec3_301650 *p1, Shape_301650 *b, Vec3_301650 *p2, float depth, Vec3_301650 *dir);
    void FUN_00301650(Shape_301650 *b, Shape_301650 *a);
};
struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
    void FUN_000111b0(const Vec3 *a, const Vec3 *b);
    void FUN_001f6bc0(const Vec3 *a, float s, const Vec3 *b);
};
extern "C" float FUN_00083d90(float *v);
struct Span {
    int begin;
    int end;
};
class Plane_301790 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3 *vfunc_4();
    char pad04[0x38 - 4];
    Vec3 normal;
};
class Shape {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3 *vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
    char pad08[0x14 - 4];
    Span *span;
    char pad18[0x34 - 0x18];
    float radius;
    char pad38[0x44 - 0x38];
    Vec3 axis;
    float f50;
    float f54;
    char b58;
    void thunk_FUN_002fb860(Vec3 *out, int i);
};
struct Frame_301790 {
    float d0;
    float f4;
    float f8;
    float f12;
    Vec3 v16;
    Vec3 v28;
    Vec3 v40;
    Vec3 v52;
};
class Solver {
public:
    char pad0[0xc];
    float margin;
    char pad10[4];
    Vec3 rel;
    void FUN_00314be0(Shape *s, Vec3 *a, Plane_301790 *p, Vec3 *b, float d, const Vec3 *n);
    void FUN_00302c20(Shape *s, Plane_301790 *p);
    void FUN_00301790(Plane_301790 *a0, Shape *shape);
};
struct Vec3_301e10 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_001f6bc0(Vec3_301e10* base, float s, Vec3_301e10* dir);
};
union FloatBits_301e10 {
    float f;
    unsigned int u;
};
struct PtrRange_301e10 {
    char* begin;
    char* end;
};
class Cap {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_301e10* GetPos();
    char pad04[0x10];
    PtrRange_301e10* list;
    char pad18[0x44 - 0x18];
    Vec3_301e10 dir;
    float radius;
    float half;
};
class Collider_301e10 {
  public:
    char pad00[0xc];
    float margin;
    char pad10[4];
    Vec3_301e10 d;
    char FUN_00315620(Vec3_301e10* out, Vec3_301e10* axis, float ext, Vec3_301e10* u, Vec3_301e10* b,
                      float f50, float* kv, float L, float m, Cap* a, Cap* cap);
    void FUN_00314be0(Cap* a, Vec3_301e10* p1, Cap* b, Vec3_301e10* p2, float depth, Vec3_301e10* dir);
    void FUN_00318bb0(Cap* a, Cap* b);
    void FUN_00318910(Cap* a, Cap* b);
    void FUN_00317700(Cap* a, Cap* b, int x, int y);
    void FUN_00301e10(Cap* a, Cap* b);
};
struct Vec3_302200 { float x, y, z; };
class Body_302200 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_302200 *GetPos();
    char pad4[0x34 - 4];
    float radius;
};
struct Resolver_302200 {
    char pad0[0xc];
    float margin;
    void FUN_00314be0(Body_302200 *a, Vec3_302200 *pa, Body_302200 *b, Vec3_302200 *pb, float depth, Vec3N *normal);
    void Resolve(Body_302200 *a, Body_302200 *b);
};
struct V {
    float x, y, z;
};
class Shape_3023b0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual V* Pos();
    virtual void a5();
    virtual int Type();
    char pad[0x30];
    float radius;
};
class Test_3023b0 {
  public:
    char pad[0xc];
    float margin;
    float pad2;
    V d;
    float pad3[3];
    float dist2;
    bool Check(Shape_3023b0* a, Shape_3023b0* b);
};
class VecSource {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual float* Get();
};
class Obj_302480 {
  public:
    char pad[0x34];
    float radius;
};
struct Vec3_302620 { float x,y,z; };
struct Shape_302620 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec3_302620* position();
 char pad04[0x30]; float radius; char pad38[0xc]; Vec3_302620 normal; float extent; float thickness; unsigned char flag;
};
struct Weight {
    char pad[0x80];
    float w;
};
struct Link_302720 {
    char pad[0x18];
    Weight* weight;
};
struct Obj_302720 {
    Link_302720* a;
    Link_302720* b;
    char pad[4];
    float blend;
};
class Limit {
public:
    char pad[0xc];
    float value;
    bool FUN_00302720(Obj_302720* o, float v);
};
struct Body_3027b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();             // 0x18
    char pad4[0x34 - 4];
    float size;                     // 0x34
};
class Resolver_3027b0 {
public:
    char pad0[0xc];
    float threshold;                // 0xc
    char pad10[0x34 - 0x10];
    unsigned char busyA;            // 0x34
    unsigned char busyB;            // 0x35

    void FUN_003023b0(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301790(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301410(Body_3027b0 *a, Body_3027b0 *b, float c);
    void FUN_00301460(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_003014f0(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301310(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00301e10(Body_3027b0 *a, Body_3027b0 *b);
    void FUN_00302200(Body_3027b0 *a, Body_3027b0 *b);
    char FUN_003027b0(Body_3027b0 *a1, Body_3027b0 *a2);
};
struct NodeList_302a00 {
    Node **begin;
    Node **end;
};
class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();
    char pad4[0x14 - 4];
    NodeList_302a00 *children;
};
struct Query_302a00 {
    char pad0[0xc];
    float limit;
};
union Slot_302a00 {
    Node *node;
    float best;
};
hulk_freg FUN_003015c0(Node *node, int a3);
hulk_freg FUN_003024d0(Node *node, int a3);
hulk_freg FUN_00302620(Node *node, int a3);
hulk_freg FUN_00302480(Node *node, int a3);
class Solver_302a00 {
public:
    char FUN_00302720(Query_302a00 *q, float v);
    char FUN_00302a00(Query_302a00 *q, Slot_302a00 arg, int a3);
};
class Item_302b70 {
  public:
    virtual void a();
    virtual void b();
    virtual int c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual int Compare();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual bool Check(Item_302b70*, int);
    char pad[16];
    int value;
    unsigned char flag;
};
class Owner_302b70 {
  public:
    char pad[12];
    int field;
    void F(Item_302b70*, Item_302b70*);
    void Pair_00302c20(Item_302b70*, Item_302b70*);
    void Order_003027b0(Item_302b70*, Item_302b70*);
};
class Entity;
struct EntityList_302c20 {
    Entity **begin;
    Entity **end;
};
class Entity {
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
    virtual bool CanCollide(Entity *other, int mask);
    char pad04[0x10];
    EntityList_302c20 *children;
};
class Collider_302c20 {
public:
    char pad0[0xc];
    int mask;
    void FUN_00302b70(Entity *a, Entity *b);
    void FUN_00302c20(Entity *a, Entity *b);
};
struct Shape_302d90 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual int type();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual bool apply(Shape_302d90*, float);
};
struct Item_302d90 { char pad[0x20]; Shape_302d90* shape; char pad2[0x2c]; unsigned char flag; };
struct Pair_302d90 { Item_302d90* first; Item_302d90* second; hulk_freg FUN_002f8f10(int); };
hulk_freg __cdecl FUN_003015c0(Shape_302d90*, Shape_302d90*);
hulk_freg __cdecl FUN_00302480(Shape_302d90*, Shape_302d90*);
struct Handler_302d90 {
 char pad[0xc]; float value; float minimum; char pad2[0x28]; int setting;
 bool FUN_00302a00(Pair_302d90*,Shape_302d90*,Shape_302d90*);
 bool FUN_00302720(Pair_302d90*,float);
 bool target(Pair_302d90*);
};
extern const float zero_302e60;
struct Entry_302e60 {
    int* a;
    int* b;
    int c;
    float value;
    unsigned char active;
    char pad[3];
};
struct Range_302e60 {
    Entry_302e60* first;
    Entry_302e60* end;
};
struct Owner_302e60 {
    char pad0[4];
    Range_302e60* range;
    char pad8[0x28];
    int result;
    char pad34[8];
    float decrement;
    char Check_00302d90(Entry_302e60*);
    void Update_00302b70(int, int);
    void Run();
};


// 0x00301650 FUN_00301650 (317 B): equivalent/0x00301650.cpp
// sym: ?FUN_00301650@Contact_301650@fn_f617c19c@@QAEXPAVShape_301650@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 4/4)
// FUN_00301650 @ 0x00301650
    // equiv-conv: FUN_00314be0 ecx stack stack stack stack stack stack
void Contact_301650::FUN_00301650(Shape_301650 *b, Shape_301650 *a)
{
    if (a->GetType() == 8)
        return;

    Vec3_301650 *bp = b->GetPos();
    Vec3_301650 *ap = a->GetPos();
    delta.x = ap->x - bp->x;
    delta.y = ap->y - bp->y;
    delta.z = ap->z - bp->z;

    Vec3_301650 *dir = &b->dir;
    float s = dir->z * a->normal.z + dir->y * a->normal.y + dir->x * a->normal.x;
    float absS = s;
    *(unsigned *)&absS = *(unsigned *)&s & 0x7fffffff;

    float d = dir->z * delta.z + dir->y * delta.y + dir->x * delta.x;
    dist = d;
    if (d < absS + f0c) {
        float t = -absS;
        Vec3_301650 p1;
        Vec3_301650 p2;
        ap = a->GetPos();
        p1.x = t * dir->x + ap->x;
        p1.y = t * dir->y + ap->y;
        p1.z = t * dir->z + ap->z;
        t = -dist;
        ap = a->GetPos();
        p2.x = t * dir->x + ap->x;
        p2.y = t * dir->y + ap->y;
        p2.z = t * dir->z + ap->z;
        FUN_00314be0(a, &p1, b, &p2, dist - absS, dir);
    }
}


// 0x00301790 FUN_00301790 (1599 B): equivalent/0x00301790.cpp
// sym: ?FUN_00301790@Solver@fn_f617c19c@@QAEXPAVPlane_301790@2@PAVShape@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3041 inputs, branch coverage 47/48, incomplete)
// FUN_00301790 @ 0x00301790
// equiv-map: ?thunk_FUN_002fb860@Shape@@QAEXPAUVec3@@H@Z = 0x002fb940
void Solver::FUN_00301790(Plane_301790 *a0, Shape *shape)
{
    Frame_301790 f;
    Vec3 *pc = a0->vfunc_4();
    Vec3 *sc = shape->vfunc_4();
    rel.x = sc->x - pc->x;
    rel.y = sc->y - pc->y;
    rel.z = sc->z - pc->z;
    const Vec3 *n = &a0->normal;
    f.d0 = n->z * rel.z + n->y * rel.y + n->x * rel.x;
    if (f.d0 > shape->radius + margin)
        return;

    if (shape->span && ((shape->span->end - shape->span->begin) & 0xfffffffc)) {
        switch (shape->vfunc_6()) {
        case 0:
        case 7:
            FUN_00302c20(shape, a0);
            return;
        case 2: {
            float t = n->z * shape->axis.z + n->y * shape->axis.y + n->x * shape->axis.x;
            *(int *)&t &= 0x7fffffff;
            if (!(f.d0 - (t * shape->f50 + shape->f54) <= margin))
                return;
            FUN_00302c20(shape, a0);
            return;
        }
        case 5: {
            for (int i = 0; i < 4; i++) {
                shape->thunk_FUN_002fb860(&f.v40, i);
                float t = f.v40.z * n->z + f.v40.y * n->y + f.v40.x * n->x;
                *(int *)&t &= 0x7fffffff;
                if (f.d0 - t < margin) {
                    FUN_00302c20(shape, a0);
                    return;
                }
            }
            return;
        }
        default:
            return;
        }
    }

    switch (shape->vfunc_6()) {
    case 0:
    case 7: {
        float res = f.d0 - shape->radius;
        float k = -shape->radius;
        Vec3 *c = shape->vfunc_4();
        f.v16.FUN_001f6bc0(c, k, n);
        if (!(res < margin))
            return;
        f.v28.FUN_001f6bc0(&f.v16, -res, n);
        FUN_00314be0(shape, &f.v16, a0, &f.v28, res, n);
        return;
    }
    case 2: {
        const Vec3 *ax = &shape->axis;
        if (!shape->b58) {
            f.f12 = n->z * ax->z + n->y * ax->y + n->x * ax->x;
            float a = f.f12;
            *(int *)&a &= 0x7fffffff;
            float res = f.d0 - (a * shape->f50 + shape->f54);
            if (!(res <= margin))
                return;
            float k = -(FUN_00083d90(&f.f12) * shape->f50);
            Vec3 *c = shape->vfunc_4();
            f.v16.FUN_001f6bc0(c, k, ax);
            f.v16.FUN_001f6bc0(&f.v16, -shape->f54, n);
            f.v28.FUN_001f6bc0(&f.v16, -res, n);
            FUN_00314be0(shape, &f.v16, a0, &f.v28, res, n);

            float a2 = f.f12;
            *(int *)&a2 &= 0x7fffffff;
            float res2 = f.d0 - (shape->f54 - a2 * shape->f50);
            if (!(res2 <= margin))
                return;
            float k2 = -(FUN_00083d90(&f.f12) * shape->f50);
            Vec3 *c2 = shape->vfunc_4();
            f.v16.FUN_001f6bc0(c2, k2, ax);
            f.v16.FUN_001f6bc0(&f.v16, -shape->f54, n);
            f.v28.FUN_001f6bc0(&f.v16, -res2, n);
            FUN_00314be0(shape, &f.v16, a0, &f.v28, res2, n);
            return;
        }
        f.v28.FUN_000111b0(ax, n);
        f.v16.FUN_000111b0(ax, &f.v28);
        f.v16.FUN_0022d180();
        f.f4 = (f.v16.y * n->y + f.v16.z * n->z + f.v16.x * n->x) * shape->f54;
        float absS = f.f4;
        *(int *)&absS &= 0x7fffffff;
        f.f8 = (n->z * ax->z + n->y * ax->y + ax->x * n->x) * shape->f50;
        f.f12 = f.f8;
        *(int *)&f.f12 &= 0x7fffffff;
        float res1 = f.d0 - absS - f.f12;
        if (res1 < margin) {
            float k1 = -(FUN_00083d90(&f.f4) * shape->f54);
            Vec3 *c = shape->vfunc_4();
            f.v40.FUN_001f6bc0(c, k1, &f.v16);
            float k2 = -(FUN_00083d90(&f.f8) * shape->f50);
            f.v40.FUN_001f6bc0(&f.v40, k2, ax);
            f.v52.FUN_001f6bc0(&f.v40, -res1, n);
            FUN_00314be0(shape, &f.v40, a0, &f.v52, res1, n);
        }
        float absS2 = f.f4;
        *(int *)&absS2 &= 0x7fffffff;
        f.f12 = f.f8;
        *(int *)&f.f12 &= 0x7fffffff;
        float res2 = f.d0 - absS2 + f.f12;
        if (!(res2 < margin))
            return;
        float k1 = -(FUN_00083d90(&f.f4) * shape->f54);
        Vec3 *c = shape->vfunc_4();
        f.v40.FUN_001f6bc0(c, k1, &f.v16);
        float k2 = FUN_00083d90(&f.f8) * shape->f50;
        f.v40.FUN_001f6bc0(&f.v40, k2, ax);
        f.v52.FUN_001f6bc0(&f.v40, -res2, n);
        FUN_00314be0(shape, &f.v40, a0, &f.v52, res2, n);
        return;
    }
    case 5: {
        for (int i = 0; i < 4; i++) {
            shape->thunk_FUN_002fb860(&f.v28, i);
            f.f12 = f.v28.y * n->y + f.v28.z * n->z + f.v28.x * n->x;
            float a = f.f12;
            *(int *)&a &= 0x7fffffff;
            float res = f.d0 - a;
            if (!(res < margin))
                continue;
            f.f8 = -FUN_00083d90(&f.f12);
            Vec3 *c = shape->vfunc_4();
            f.v16.x = f.f8 * f.v28.x + c->x;
            f.v16.y = f.v28.y * f.f8 + c->y;
            f.v16.z = f.v28.z * f.f8 + c->z;
            f.v28.x = -res * n->x + f.v16.x;
            f.v28.y = -res * n->y + f.v16.y;
            f.v28.z = -res * n->z + f.v16.z;
            FUN_00314be0(shape, &f.v16, a0, &f.v28, res, n);
        }
        return;
    }
    default:
        return;
    }
}


// 0x00301e10 FUN_00301e10 (998 B): equivalent/0x00301e10.cpp
// sym: ?FUN_00301e10@Collider_301e10@fn_f617c19c@@QAEXPAVCap@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3041 inputs, branch coverage 30/30)
// FUN_00301e10 @ 0x00301e10
void Collider_301e10::FUN_00301e10(Cap* a, Cap* b) {
    Vec3_301e10 k, contactA, contactB, axial, radial;
    float radialGap;
    Vec3_301e10* posA = a->GetPos();
    Vec3_301e10* posB = b->GetPos();
    d.x = posB->x - posA->x;
    d.y = posB->y - posA->y;
    d.z = posB->z - posA->z;

    Vec3_301e10* axisA = &a->dir;
    Vec3_301e10* axisB = &b->dir;
    double crossX = axisA->y * axisB->z - axisA->z * axisB->y;
    double crossY = axisA->z * axisB->x - axisA->x * axisB->z;
    volatile float crossZ = axisA->x * axisB->y - axisA->y * axisB->x;
    double radii = b->radius * a->radius;
    volatile float roundedRadii = (float)radii;
    k.x = (float)(radii * crossX);
    k.y = (float)(crossY * roundedRadii);
    double kz = crossZ * roundedRadii;
    k.z = (float)kz;
    double squaredLength = kz * k.z + k.y * k.y + k.x * k.x;
    volatile float roundedSquaredLength = (float)squaredLength;
    if (squaredLength > 9.99999997475243e-007f) {
        double projectedDistance = k.z * d.z + k.y * d.y + k.x * d.x;
        FloatBits_301e10 absoluteProjection;
        absoluteProjection.f = (float)projectedDistance;
        absoluteProjection.u &= 0x7fffffff;
        if (absoluteProjection.f > 9.99999997475243e-007f) {
            volatile float length = (float)sqrt((double)roundedSquaredLength);
            double inverseLength = 1.0f / length;
            volatile float roundedInverseLength = (float)inverseLength;
            double signedDistance = inverseLength * projectedDistance;
            double sign = signedDistance < 0.0 ? -1.0f : signedDistance > 0.0 ? 1.0f : 0.0f;
            double scale = sign * roundedInverseLength;
            double scaleA = scale * a->half;
            contactA.x = (float)(k.x * scaleA);
            contactA.y = (float)(k.y * scaleA);
            contactA.z = (float)(k.z * scaleA);
            double scaleB = -(scale * b->half);
            contactB.x = (float)(k.x * scaleB);
            contactB.y = (float)(k.y * scaleB);
            contactB.z = (float)(k.z * scaleB);
            FloatBits_301e10 absoluteDistance;
            absoluteDistance.f = (float)signedDistance;
            absoluteDistance.u &= 0x7fffffff;
            double separation = absoluteDistance.f - a->half - b->half;
            volatile float roundedSeparation = (float)separation;
            if (separation < margin) {
                bool aHasItems = a->list && ((int)(a->list->end - a->list->begin) & ~3) != 0;
                if (!aHasItems) {
                    bool bHasItems = b->list && ((int)(b->list->end - b->list->begin) & ~3) != 0;
                    if (!bHasItems &&
                        FUN_00315620(&contactA, axisA, a->radius, &contactB, axisB, b->radius, &k.x, length,
                                     roundedSeparation, a, b) &&
                        (*(char*)&DAT_00555481) == 0)
                        return;
                }
            }
        }
    } else {
        double alongAxis = axisA->z * d.z + axisA->y * d.y + axisA->x * d.x;
        axial.x = (float)(alongAxis * axisA->x);
        axial.y = (float)(alongAxis * axisA->y);
        axial.z = (float)(alongAxis * axisA->z);
        radial.x = d.x - axial.x;
        radial.y = d.y - axial.y;
        radial.z = d.z - axial.z;
        double radialLength = radial.FUN_0022d110();
        if (radialLength > 9.99999997475243e-007f) {
            double axisGap = radialLength - (b->half + a->half);
            volatile float roundedAxisGap = (float)axisGap;
            if (axisGap <= margin) {
                double axialLength = axial.FUN_0022d110();
                double otherGap = axialLength - (b->radius + a->radius);
                if (otherGap <= margin) {
                    radialGap = (float)otherGap;
                    FloatBits_301e10 absAxisGap, absRadialGap;
                    absAxisGap.f = roundedAxisGap;
                    absAxisGap.u &= 0x7fffffff;
                    absRadialGap.f = radialGap;
                    absRadialGap.u &= 0x7fffffff;
                    if (absAxisGap.f < absRadialGap.f) {
                        contactA.x = axial.x * a->radius;
                        contactA.y = axial.y * a->radius;
                        contactA.z = axial.z * a->radius;
                        ((owners::Vec3_11160 *)&contactA)->FUN_00011160(a->half, (const owners::Vec3_11160 *)(Vec3_301e10 *)(&radial));
                        Vec3_301e10* origin = a->GetPos();
                        contactA.x = contactA.x + origin->x;
                        contactA.y = contactA.y + origin->y;
                        contactA.z = contactA.z + origin->z;
                        contactB.FUN_001f6bc0(&contactA, roundedAxisGap, &radial);
                        radial.x = radial.x * -1.0f;
                        radial.y = radial.y * -1.0f;
                        radial.z = radial.z * -1.0f;
                        FUN_00314be0(a, &contactA, b, &contactB, roundedAxisGap, &radial);
                    }
                }
            }
        }
    }
    FUN_00318bb0(a, b);
    FUN_00318910(a, b);
    FUN_00317700(a, b, 1, 1);
}


// 0x00302200 FUN_00302200 (421 B): equivalent/0x00302200.cpp
// sym: ?Resolve@Resolver_302200@fn_f617c19c@@QAEXPAVBody_302200@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00302200 @ 0x00302200
void Resolver_302200::Resolve(Body_302200 *a, Body_302200 *b)
{
    struct { volatile float x; float y; float z; } d;
    Vec3_302200 *pb = b->GetPos();
    Vec3_302200 *pa = a->GetPos();
    d.x = pa->x - pb->x;
    d.y = pa->y - pb->y;
    d.z = pa->z - pb->z;
    float len = (float)sqrt(d.z * d.z + d.y * d.y + d.x * d.x);

    double reach = a->radius;
    reach = reach + b->radius;
    reach = reach + margin;
    if (reach > len) {
        Vec3N n;
        n.x = d.x;
        n.y = d.y;
        n.z = d.z;
        if (len <= 0.0f)
            n.x = 1.0f;
        n.FUN_0022d180();

        n.x = n.x * -1.0f;
        n.y = n.y * -1.0f;
        n.z = n.z * -1.0f;

        float ra = a->radius;
        Vec3_302200 *q = a->GetPos();
        Vec3_302200 p1;
        p1.x = ra * n.x + q->x;
        p1.y = n.y * ra + q->y;
        p1.z = n.z * ra + q->z;

        float rb = b->radius;
        n.x = n.x * -1.0f;
        n.y = n.y * -1.0f;
        n.z = n.z * -1.0f;
        q = b->GetPos();
        Vec3_302200 p2;
        p2.x = rb * n.x + q->x;
        p2.y = n.y * rb + q->y;
        p2.z = n.z * rb + q->z;

        FUN_00314be0(a, &p1, b, &p2, len - (a->radius + b->radius), &n);
    }
}


// 0x003023b0 FUN_003023b0 (193 B): equivalent/0x003023b0.cpp
// sym: ?Check@Test_3023b0@fn_f617c19c@@QAE_NPAVShape_3023b0@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 8/8)
// Test_3023b0::Check @ 0x003023b0
// Demoted from matches/: the original compares the squared distance it just stored with fst (53-bit register
// copy); MSVC 7.1 byte-matches only with the reload spelling, which clang rounds to float (Wine-build divergence).
bool Test_3023b0::Check(Shape_3023b0* a, Shape_3023b0* b) {
    if (a->Type() == 8 || a->Type() == 1)
        return true;
    V* pb = b->Pos();
    V* pa = a->Pos();
    d.x = pa->x - pb->x;
    d.y = pa->y - pb->y;
    d.z = pa->z - pb->z;
    float* q = &dist2;
    volatile V* dv = &d;
    hulk_freg t = dv->z * dv->z + dv->y * dv->y;
    // x87: the original stores the squared distance with fst and compares the register copy (53 bits)
    hulk_freg s = t + dv->x * dv->x;
    *q = s;
    if (s < 1e-6f)
        return false;
    hulk_freg r = a->radius + b->radius + margin;
    return s < r * r;
}


// 0x00302480 FUN_00302480 (79 B): matches/0x00302480.cpp
// sym: ?dist@fn_f617c19c@@YAMPAVObj_302480@1@0@Z
hulk_freg dist(Obj_302480* a, Obj_302480* b) {
    float* p = ((VecSource*)a)->Get();
    float* q = ((VecSource*)b)->Get();
    hulk_freg x = q[0] - p[0];
    hulk_freg y = q[1] - p[1];
    hulk_freg z = q[2] - p[2];
    return (hulk_freg)sqrt(y * y + z * z + x * x) - (a->radius + b->radius);
}

} // namespace fn_f617c19c

// 0x003024d0 FUN_003024d0 (332 B): equivalent/0x003024d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_003024d0@fn_003024d0@@YAMPAVBox_3024d0@1@PAVOther_3024d0@1@@Z
namespace fn_003024d0 {
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 6/6)
// FUN_003024d0 @ 0x003024d0
struct Vec3_3024d0 {
    float x, y, z;
};

union FloatBits_3024d0 {
    float f;
    unsigned int u;
};

static float Abs(float v)
{
    FloatBits_3024d0 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class Other_3024d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_3024d0 *vfunc_4();
    char pad04[0x30];
    float margin;
};

class Box_3024d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_3024d0 *vfunc_4();
    char pad04[0x34];
    int axisAligned;
    char pad3c[0x48 - 0x3c];
    float extentX;
    float extentY;
    float extentZ;
    Vec3_3024d0 axisX;
    Vec3_3024d0 axisY;
    Vec3_3024d0 axisZ;
};

// Signed distance bound of a point-ish object against an oriented (or axis-aligned) box: max over axes.
hulk_freg __cdecl FUN_003024d0(Box_3024d0 *box, Other_3024d0 *other)
{
    Vec3_3024d0 *p = other->vfunc_4();
    Vec3_3024d0 *q = box->vfunc_4();
    Vec3_3024d0 d;
    d.x = q->x - p->x;
    d.y = q->y - p->y;
    d.z = q->z - p->z;

    double a; // register value in the original (b and c are frame copies)
    volatile float b;
    volatile float c;
    if (box->axisAligned == 0) {
        float dotX = d.z * box->axisX.z + d.y * box->axisX.y + d.x * box->axisX.x;
        a = Abs(dotX) - (box->extentX + other->margin);
        float dotY = d.z * box->axisY.z + d.y * box->axisY.y + d.x * box->axisY.x;
        b = Abs(dotY) - (box->extentY + other->margin);
        float dotZ = d.z * box->axisZ.z + d.y * box->axisZ.y + d.x * box->axisZ.x;
        c = Abs(dotZ) - (box->extentZ + other->margin);
    } else {
        a = Abs(d.x) - (box->extentX + other->margin);
        b = Abs(d.y) - (box->extentY + other->margin);
        c = Abs(d.z) - (box->extentZ + other->margin);
    }
    double best = a;
    if (best < b)
        best = b;
    if (best < c)
        best = c;
    return best;
}
} // namespace fn_003024d0

namespace fn_f617c19c {

// 0x00302620 FUN_00302620 (244 B): equivalent/0x00302620.cpp
// sym: ?FUN_00302620@fn_f617c19c@@YAMPAUShape_302620@1@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 4/4)
// FUN_00302620 @ 0x00302620
hulk_freg __cdecl FUN_00302620(Shape_302620* a, Shape_302620* b) {
 float limit = a->flag ? a->extent : a->thickness + a->extent;
 Vec3_302620* pa=a->position(); Vec3_302620* pb=b->position();
 float dx=pb->x-pa->x, dy=pb->y-pa->y;
 hulk_freg dzWide=(hulk_freg)pb->z-pa->z; // kept in st0 for the dot product, stored rounded as dz
 float dz=dzWide;
 hulk_freg dot=dzWide*a->normal.z; dot+=dy*a->normal.y; dot+=dx*a->normal.x;
 hulk_freg negDot=-dot;
 hulk_freg x=negDot*a->normal.x+dx, y=negDot*a->normal.y+dy, z=negDot*a->normal.z+dz;
 union { float f; unsigned int u; } length, distance;
 length.f=(float)sqrt(z*z+y*y+x*x); length.u &= 0x7fffffff;
 float edge=length.f-((hulk_freg)a->thickness+b->radius);
 distance.f=dot; distance.u &= 0x7fffffff;
 hulk_freg face=distance.f-((hulk_freg)limit+b->radius);
 return face<edge ? edge : face;
}


// 0x00302720 FUN_00302720 (129 B): equivalent/0x00302720.cpp
// sym: ?FUN_00302720@Limit@fn_f617c19c@@QAE_NPAUObj_302720@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00302720 @ 0x00302720
// 0x00302720: update the blend factor of obj from the ratio of v to the summed weights of its two links
bool Limit::FUN_00302720(Obj_302720* o, float v)
{
    if (v > value) {
        if ((o->b->weight->w + o->a->weight->w) * DAT_004d2960 == 0.0f) {
            o->blend = DAT_004d2f14;
            return false;
        }
        float ratio = v / ((o->b->weight->w + o->a->weight->w) * DAT_004d2960);
        if (ratio < DAT_004d2f14)
            o->blend = ratio;
        else
            o->blend = DAT_004d2f14;
        return false;
    }
    o->blend = 0.0f;
    return true;
}


// 0x003027b0 FUN_003027b0 (552 B): equivalent/0x003027b0.cpp
// sym: ?FUN_003027b0@Resolver_3027b0@fn_f617c19c@@QAEDPAUBody_3027b0@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3081 inputs, branch coverage 41/41)
// FUN_003027b0 @ 0x003027b0
char Resolver_3027b0::FUN_003027b0(Body_3027b0 *a1, Body_3027b0 *a2)
{
    FUN_003023b0(a1, a2);

    bool pairHandled = false;
    if (a1->size < a2->size) {
        if (DAT_004d2f7c * a1->size < threshold) {
            pairHandled = true;
            busyA = 1;
            switch (a2->type()) {
            case 2:
                FUN_00301460(a2, a1);
                break;
            case 5:
                FUN_00301410(a2, a1, a1->size);
                break;
            case 8:
                FUN_00301790(a2, a1);
                break;
            default:
                FUN_003014f0(a1, a2);
                break;
            }
        }
    } else {
        if (DAT_004d2f7c * a2->size < threshold) {
            pairHandled = true;
            busyB = 1;
            switch (a1->type()) {
            case 2:
                FUN_00301460(a1, a2);
                break;
            case 5:
                FUN_00301410(a1, a2, a2->size);
                break;
            case 8:
                FUN_00301790(a1, a2);
                break;
            default:
                FUN_003014f0(a1, a2);
                break;
            }
        }
    }

    if (!pairHandled) {
        switch (a1->type()) {
        case 2:
            if (a2->type() == 2)
                FUN_00301e10(a1, a2);
            break;
        case 5: {
            int t = a2->type();
            if (t == 2)
                FUN_00301310(a1, a2);
            else if (t == 5)
                ((owners::C_3012d0 *)this)->FUN_003012d0((hulk_intptr)(Body_3027b0 *)a1, (hulk_intptr)(Body_3027b0 *)a2);
            break;
        }
        case 7: {
            int t = a2->type();
            if (t == 2)
                FUN_00301460(a2, a1);
            else if (t == 5)
                FUN_00301410(a2, a1, a1->size);
            else if (t == 7)
                FUN_00302200(a1, a2);
            else
                FUN_003014f0(a1, a2);
            break;
        }
        case 8:
            if (a2->type() != 8)
                FUN_00301790(a1, a2);
            break;
        default:
            FUN_003014f0(a1, a2);
            break;
        }
    }

    busyA = 0;
    busyB = 0;
    return 0;
}


// 0x00302a00 FUN_00302a00 (327 B): equivalent/0x00302a00.cpp
// sym: ?FUN_00302a00@Solver_302a00@fn_f617c19c@@QAEDPAUQuery_302a00@2@TSlot_302a00@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 22/23, incomplete)
// FUN_00302a00 @ 0x00302a00
char Solver_302a00::FUN_00302a00(Query_302a00 *q, Slot_302a00 arg, int a3)
{
    Node *node = arg.node;
    NodeList_302a00 *list = node->children;

    if (list != 0 && (((hulk_intptr)list->end - (hulk_intptr)list->begin) & ~3) != 0) {
        arg.best = DAT_004d2f14;
        unsigned int n = (unsigned int)(((hulk_intptr)list->end - (hulk_intptr)list->begin) >> 2);
        unsigned int i = 0;
        while (i < n) {
            Slot_302a00 child;
            child.node = node->children->begin[i];
            if (FUN_00302a00(q, child, a3) == 1)
                return 1;
            if (!(arg.best < q->limit))
                arg.best = q->limit;
            i++;
            n = (unsigned int)(((hulk_intptr)node->children->end - (hulk_intptr)node->children->begin) >> 2);
        }
        if (arg.best < q->limit)
            q->limit = arg.best;
        return 0;
    }

    float v;
    switch (node->type()) {
    case 2:
        v = FUN_00302620(node, a3);
        return FUN_00302720(q, v);
    case 5:
        v = FUN_003024d0(node, a3);
        return FUN_00302720(q, v);
    case 7:
        v = FUN_00302480(node, a3);
        return FUN_00302720(q, v);
    case 8:
        v = FUN_003015c0(node, a3);
        return FUN_00302720(q, v);
    default:
        return 0;
    }
}


// 0x00302b70 FUN_00302b70 (161 B): matches/0x00302b70.cpp
// sym: ?F@Owner_302b70@fn_f617c19c@@QAEXPAVItem_302b70@2@0@Z
void Owner_302b70::F(Item_302b70* a, Item_302b70* b) {
    if (a->Check(b, field)) {
        if (!a->flag) {
            if (a->value)
                Pair_00302c20(a, b);
        } else if (!b->flag) {
            if (b->value)
                Pair_00302c20(b, a);
        } else if (a->Compare() == 1 || b->Compare() == 1)
            Pair_00302c20(b, a);
        else {
            int x = a->Compare();
            int y = b->Compare();
            if (x > y)
                Order_003027b0(a, b);
            else
                Order_003027b0(b, a);
        }
    }
}


// 0x00302c20 FUN_00302c20 (364 B): matches/0x00302c20.cpp
// sym: ?FUN_00302c20@Collider_302c20@fn_f617c19c@@QAEXPAVEntity@2@0@Z
// FUN_00302c20 @ 0x00302c20
void Collider_302c20::FUN_00302c20(Entity *a, Entity *b)
{
    EntityList_302c20 *listA = a->children;
    EntityList_302c20 *listB = b->children;
    if (listA != 0) {
        if (listB != 0) {
            for (unsigned int i = 0; i < (unsigned int)(listA->end - listA->begin); i++) {
                if (b->CanCollide(listA->begin[i], mask)) {
                    for (unsigned int j = 0; j < (unsigned int)(listB->end - listB->begin); j++) {
                        if (a->CanCollide(listB->begin[j], mask))
                            FUN_00302b70(listA->begin[i], listB->begin[j]);
                    }
                }
            }
        } else {
            for (unsigned int i = 0; i < (unsigned int)(listA->end - listA->begin); i++) {
                if (b->CanCollide(listA->begin[i], mask))
                    FUN_00302b70(b, listA->begin[i]);
            }
        }
    } else {
        for (unsigned int j = 0; j < (unsigned int)(listB->end - listB->begin); j++) {
            if (a->CanCollide(listB->begin[j], mask))
                FUN_00302b70(a, listB->begin[j]);
        }
    }
}


// 0x00302d90 FUN_00302d90 (193 B): equivalent/0x00302d90.cpp
// sym: ?target@Handler_302d90@fn_f617c19c@@QAE_NPAUPair_302d90@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 12/12)
// FUN_00302d90 @ 0x00302d90
bool Handler_302d90::target(Pair_302d90* pair) {
 float v=pair->FUN_002f8f10(setting);
 value = v > minimum ? v : minimum;
 Shape_302d90* first=pair->first->shape;
 Shape_302d90* second=pair->second->shape;
 bool result;
 if(first->type()==8) {
  if(second->type()==8) return false;
  result=FUN_00302720(pair,FUN_003015c0(first,second));
 } else if(second->type()==8) {
  result=FUN_00302720(pair,FUN_003015c0(second,first));
 } else if(pair->first->flag) {
  result=FUN_00302a00(pair,first,second);
 } else {
  result=FUN_00302720(pair,FUN_00302480(pair->second->shape,pair->first->shape));
 }
 if(result) result=first->apply(pair->second->shape,value);
 return result;
}


// 0x00302e60 FUN_00302e60 (111 B): matches/0x00302e60.cpp
// sym: ?Run@Owner_302e60@fn_f617c19c@@QAEXXZ
void Owner_302e60::Run() {
    Entry_302e60* p = range->first;
    Entry_302e60* e = range->end;
    while (p != e) {
        result = 0;
        if (p->active) {
            if (p->value <= 0.0f) {
                if (Check_00302d90(p)) {
                    int x = *(int*)((char*)p->b + 0x20);
                    int y = *(int*)((char*)p->a + 0x20);
                    Update_00302b70(y, x);
                    p->c = result;
                }
            } else
                p->value -= decrement;
        }
        e = range->end;
        ++p;
    }
}

} // namespace fn_f617c19c

// 0x00302ed0 FUN_00302ed0 (31 B): matches/0x00302ed0.cpp
// sym: ?FUN_00302ed0@Obj_302ed0@owners@@QAEXHHH@Z
void owners::Obj_302ed0::FUN_00302ed0(hulk_intptr x, hulk_intptr y, hulk_intptr z) {
    b = c;
    a = ((int)z);
    Other(((int)x), ((int)y));
}


// 0x00302ef0 FUN_00302ef0 (29 B): matches/0x00302ef0.cpp
// sym: ?FUN_00302ef0@Thing_302ef0@owners@@QAEXHHH@Z
void owners::Thing_302ef0::FUN_00302ef0(hulk_intptr x, hulk_intptr y, hulk_intptr z) {
    c = ((int)z);
    a = ((int)x);
    b = ((int)y);
    Init();
}

