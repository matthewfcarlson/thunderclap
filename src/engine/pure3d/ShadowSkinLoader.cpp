// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b37a0..0x002b78a0 (kind game, layer engine, confidence high), dominant class pure3d::ShadowSkinLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f35954a7 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f35954a7 {} using namespace fn_f35954a7;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f35954a7 {
class X_2b37a0 {
  public:
    int m;
    X_2b37a0();
};
extern "C" char DAT_0042e554[];
typedef unsigned int u32_2b37b0;
void __cdecl release_0008d340(u32_2b37b0);
struct Obj_2b37b0 {
    void* vf;
    char pad[12];
    u32_2b37b0 a;
    u32_2b37b0 b;
};
struct V3_2b3820 {
    float x, y, z;
};
struct Tri16 {
    unsigned short a, b, c;
};
struct Edge16_2b3820 {
    unsigned short a, b;
};
struct Mesh_2b3820 {
    char pad0[0xc];
    unsigned int count;
    unsigned short *indices;
    char *facing;
};
struct Geometry {
    char pad0[0x10];
    V3_2b3820 *verts;
    V3_2b3820 *normals;
};
class Shadow {
  public:
    char pad0[0x44];
    Mesh_2b3820 *mesh;
    Geometry *geom;
    char pad4c[0x54 - 0x4c];
    char pointLight;
    char pad55[3];
    V3_2b3820 light;
    void FUN_002b3820();
};
struct V3_2b3c70 {
    float x, y, z;
    void FUN_0022d180();
};
struct Tri_2b3c70 {
    short a, b, c;
};
struct Mesh_2b3c70 {
    char pad0[0x10];
    V3_2b3c70 *verts;
};
struct Batch_2b3c70 {
    char pad0[8];
    V3_2b3c70 *p8;
    char pad0c[4];
    int *p10;
    void FUN_0008ef00();
};
struct Sink_2b3c70 {
    char pad0[0x10];
    void *f10;
};
} // namespace fn_f35954a7
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
    virtual Batch_2b3c70 *v30(void *sink, int a, int b, int count, int c);
    virtual void v31(Batch_2b3c70 *b);
};
namespace fn_f35954a7 {
class DebugMesh {
public:
    char pad0[0x48];
    Mesh_2b3c70 *mesh;
    float scale;
    char pad50[4];
    char outline;
    char pad55[3];
    V3_2b3c70 off;
    void F();
};
struct Data_2b46c0 {
    int a;
    int flag;
    int pad;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};
class Source_2b46c0 {
  public:
};
class Obj_2b46c0 {
    char pad[0x54];

  public:
    unsigned char active;
    char pad2[15];
    int x;
    int y;
    int z;
    void Do(int p, Source_2b46c0* q);
};
struct Vec3_2b4990 {
    float x, y, z;
    void FUN_0022d180();
};
struct Vec4_2b4990 {
    float x, y, z, w;
};
class Probe_2b4990 {
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
    virtual Vec3_2b4990 *vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual char vfunc_16(Vec3_2b4990 *pos, float w);
};
struct Scene_2b4990 {
    char pad0[0x18];
    Probe_2b4990 *probe;
    void FUN_00294500(Vec3_2b4990 origin, Vec3_2b4990 *target);
    void FUN_002940d0(const Vec3_2b4990 *from, Vec3_2b4990 *out);
};
struct SceneRoot_2b4990 {
    char pad0[8];
    Scene_2b4990 *scene;
};
} // namespace fn_f35954a7
struct World {
    SceneRoot_2b4990 *root;
};
namespace fn_f35954a7 {
class Mover_2b4990 {
public:
    char pad0[0x2c];
    Vec4_2b4990 origin;
    char pad3c[0x4c - 0x3c];
    float reach;
    float pending;
    char useScene;
    char pad55[0x64 - 0x55];
    Vec3_2b4990 goal;

    void FUN_002b4990();
};
extern "C" char DAT_0042e574[];
struct ShadowSkinTopology {
    void* vptr;
    int pad4;
    void* a;
    void* b;
    void* c;
    void Reset();
};
struct Vec3_2b4b40 {
    float x, y, z;
    void FUN_0022d180();
};
struct Vec4_2b4b40 { float x, y, z, w; };
class Probe_2b4b40 {
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
    virtual Vec3_2b4b40 *Direction();
    virtual void v14();
    virtual void v15();
    virtual bool Step(Vec4_2b4b40 *pos, float w);
};
struct Space_2b4b40 {
    char pad0[0x18];
    Probe_2b4b40 *probe;
    void FUN_002940d0(const Vec3_2b4b40 *in, Vec3_2b4b40 *out);
};
struct Root_2b4b40 {
    char pad0[8];
    Space_2b4b40 *space;
};
struct Globals_2b4b40 {
    Root_2b4b40 *root;
};
struct Node {
    char pad0[0x1c];
    char *data;
};
class Tracer_2b4b40 {
public:
    char pad0[0x2c];
    Vec4_2b4b40 origin;
    char pad3c[0x4c - 0x3c];
    float result;
    float override;
    char useOffset;
    char pad55[0x64 - 0x55];
    Vec3_2b4b40 point;
    void FUN_002b4b40(Node *node);
};
struct Frame_2b4b40 {
    Vec3_2b4b40 dir;
    Vec3_2b4b40 tmp;
    Vec4_2b4b40 pos;
};
struct TrackFactory_2b4cb0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_2b4cb0 {
    void* init_002deeb0();
};
struct TrackFactory_2b4cd0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct Built_2b4cd0 {
    void* init_002defb0();
};
extern "C" char DAT_0042e584[];
struct ThisCall_002a5060 {
    void Init_002a5060();
};
extern void __fastcall Init_002a5060(void*);
typedef unsigned int u32_2b4d90;
void* alloc_00263ea0(hulk_uintptr);
struct ShadowMeshBufferImpl_nv_2b4d90 {
    void initialize_002a5060();
};
class Manager_2b4e00 {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54(int);
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74(int, int, int);
};
extern Manager_2b4e00* hulk_at_0052c2a8;
class Child_2b4e00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
class ShadowMeshBuffer_2b4e60 {
  public:
    ShadowMeshBuffer_2b4e60* Init_002df0b0(int) throw();
};
class ShadowMeshBufferLoader {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual ShadowMeshBuffer_2b4e60* vfunc_6(int);
};
class X_2b5050 {
  public:
    virtual void a();
    virtual void b();
};
struct C_2b5050 {
    X_2b5050* p;
    void f();
};
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class DrawablePrimitive_2b5240 {
  public:
    virtual void v0();
    char pad[0x0c];
    int n;
    char rest[0x2c];
    DrawablePrimitive_2b5240();
};
struct Handle {
    Ref* ptr;
    Handle() : ptr(0) {}
    void operator=(Ref* p) {
        if (p)
            p->AddRef();
        if (ptr)
            ptr->Release();
        ptr = p;
    }
};
class ShadowMeshImpl : public DrawablePrimitive_2b5240 {
  public:
    virtual void v0();
    Handle handle;
    void* a;
    void* b;
    void* c;
    void* d;
    ShadowMeshImpl();
};
extern void* hulk_at_0042e5b4[];
class Ref_2b5370 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_2b5370 {
  public:
    void Fn_002a50a0();
};
class ShadowMeshImpl_2b5370 {
  public:
    void* vptr;
    char p[0x3c];
    Ref_2b5370* m40;
    Ref_2b5370* m44;
    Ref_2b5370* m48;
    void f();
};
class Helper_2b53c0 {
  public:
    hulk_intptr run_002b52e0(pure3d::ShadowMeshImpl*);
};
extern void* thunk_FUN_0008d690(int);
class Obj_2b53f0 {
  public:
    virtual void f();
    virtual void g();
};
extern "C" char DAT_0042e5e4[];
class ShadowMeshImpl_2b55b0 {
  public:
    char p[0x10];
    int x;
    ShadowMeshImpl_2b55b0();
};
class ShadowSkinImpl : public ShadowMeshImpl_2b55b0 {
  public:
    char q[0x70 - 0x14];
    int a, b, c, d;
    ShadowSkinImpl();
};
extern void* hulk_at_0042e5e4[];
} // namespace fn_f35954a7
void operator delete(void*);
namespace fn_f35954a7 {
class Ref_2b56e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ShadowMeshImpl_2b56e0 {
  public:
    void* vptr;
    void Fin_002a50a0();
};
class ShadowSkinImpl_2b56e0 : public ShadowMeshImpl_2b56e0 {
  public:
    char pad[0x40 - 4];
    Ref_2b56e0* m40;
    Ref_2b56e0* m44;
    Ref_2b56e0* m48;
    char pad2[0x70 - 0x4c];
    Ref_2b56e0* m70;
    void* m74;
    Ref_2b56e0* m78;
    Ref_2b56e0* m7c;
    ~ShadowSkinImpl_2b56e0();
};
class Item_2b57a0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2b57a0 {
  public:
    char pad[0x7c];
    Item_2b57a0* item;
    void Set(Item_2b57a0* p);
};
extern "C" char DAT_0042e614[];
class ShadowMeshLoader {
  public:
    hulk_intptr vptr;
    int a, b, c, d;
    ShadowMeshLoader();
};
extern "C" char DAT_0042e634[];
class ShadowSkinLoader {
  public:
    hulk_intptr v;
    int a;
    int b;
    int c;
    int d;
    ShadowSkinLoader();
};
extern void* hulk_at_0042e584[];
class Ref_2b6890 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2b6890 {
  public:
    void* vptr;
    void Fin_002a50a0();
};
class ShadowMeshBufferImpl_2b6890 : public DrawablePrimitive_2b6890 {
  public:
    char pad[60];
    Ref_2b6890* m;
    ~ShadowMeshBufferImpl_2b6890();
};
struct I_2b6910 {
    virtual void A();
    virtual void B();
};
extern void* hulk_at_0042e654;
extern void* hulk_at_003f6098;
struct ShadowMeshBufferLoader_2b6910 {
    void* vptr;
    char pad[16];
    I_2b6910* member;
    void F();
};
class Ref_2b6f30 {
  public:
    virtual void f0();
    virtual void f1();
};
class Provider_2b6f30 {
  public:
    char pad[0x70];
    Ref_2b6f30* getObj_0027b240();
};
struct ShadowSkinImpl_nv_2b6f30 {
    void helper_002b57d0(Ref_2b6f30*);
};
extern void* g_vftable_2b6fb0[];
class Ref_2b6fb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2b6fb0 {
  public:
    void* vptr;
    void Fin_002a50a0();
};
class ShadowMeshBufferImpl_2b6fb0 : public DrawablePrimitive_2b6fb0 {
  public:
    char pad[0x3c];
    Ref_2b6fb0* m;
    ShadowMeshBufferImpl_2b6fb0* f2(unsigned char flags);
};


// 0x002b37a0 FUN_002b37a0 (9 B): matches/0x002b37a0.cpp
// sym: ??0X_2b37a0@fn_f35954a7@@QAE@XZ
X_2b37a0::X_2b37a0() {
    m = 0;
}


// 0x002b37b0 FUN_002b37b0 (38 B): matches/0x002b37b0.cpp
// sym: ?target@fn_f35954a7@@YIXPAUObj_2b37b0@1@@Z
void __fastcall target(Obj_2b37b0* self) {
    self->vf = (void*)((hulk_intptr)DAT_0042e554);
    release_0008d340(self->a);
    release_0008d340(self->b);
    self->vf = (void*)((hulk_intptr)DAT_003f6098);
}

} // namespace fn_f35954a7

// 0x002b37e0 FUN_002b37e0 (38 B): matches/0x002b37e0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??1ShadowMeshTopology@fn_002b37e0@@UAE@XZ
namespace fn_002b37e0 {
class ShadowMeshTopology_2b37e0 {
  public:
    virtual ~ShadowMeshTopology_2b37e0() throw();
};
ShadowMeshTopology_2b37e0::~ShadowMeshTopology_2b37e0() throw() {}
void ReleaseRef_0008d340(int);
class ShadowMeshTopology : public ShadowMeshTopology_2b37e0 {
  public:
    int pad04[3];
    int m10;
    int m14;
    virtual ~ShadowMeshTopology() throw();
};
ShadowMeshTopology::~ShadowMeshTopology() throw() {
    ReleaseRef_0008d340(m10);
    ReleaseRef_0008d340(m14);
}
} // namespace fn_002b37e0


// 0x002b3810 pure3d::ShadowMeshImpl::vfunc_3 (3 B): matches/0x002b3810.cpp
// sym: ?vfunc_3@ShadowMeshImpl@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ShadowMeshImpl::vfunc_3() {
    return true;
}

namespace fn_f35954a7 {

// 0x002b3820 FUN_002b3820 (1097 B): equivalent/0x002b3820.cpp
// sym: ?FUN_002b3820@Shadow@fn_f35954a7@@QAEXXZ @98e34dc3e22e @w017deaaba73d
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 49/56, incomplete)
// FUN_002b3820 @ 0x002b3820
void Shadow::FUN_002b3820()
{
    Mesh_2b3820 *m = mesh;
    unsigned int n = m->count;
    V3_2b3820 *verts = geom->verts;
    V3_2b3820 *normals = geom->normals;
    unsigned short *idx = m->indices;
    char *facing = m->facing;
    unsigned int i;
    if (!pointLight) {
        i = 0;
        if ((int)n >= 4) {
            const V3_2b3820 *p = normals;
            do {
                facing[i] = ((p[0].y * light.y + p[0].z * light.z) + p[0].x * light.x) < 0.0f;
                facing[i + 1] = ((p[1].z * light.z + p[1].x * light.x) + p[1].y * light.y) < 0.0f;
                facing[i + 2] = ((p[2].z * light.z + p[2].y * light.y) + p[2].x * light.x) < 0.0f;
                facing[i + 3] = ((p[3].z * light.z + p[3].y * light.y) + p[3].x * light.x) < 0.0f;
                i += 4;
                p += 4;
            } while (i < n - 3);
        }
        if (i < n) {
            const V3_2b3820 *p = normals + i;
            do {
                facing[i] = ((p->z * light.z + p->x * light.x) + p->y * light.y) < 0.0f;
                i++;
                p++;
            } while (i < n);
        }
    } else {
        V3_2b3820 L = light;
        i = 0;
        if ((int)n >= 4) {
            const V3_2b3820 *p = normals;
            const unsigned short *w = idx;
            do {
                const V3_2b3820 *v0 = &verts[w[0]];
                facing[i] = 0.0f < (((L.z - v0->z) * p[0].z + (L.y - v0->y) * p[0].y) + (L.x - v0->x) * p[0].x);
                const V3_2b3820 *v1 = &verts[w[6]];
                facing[i + 1] = 0.0f < (((L.z - v1->z) * p[1].z + (L.x - v1->x) * p[1].x) + (L.y - v1->y) * p[1].y);
                const V3_2b3820 *v2 = &verts[w[12]];
                facing[i + 2] = 0.0f < (((L.z - v2->z) * p[2].z + (L.y - v2->y) * p[2].y) + (L.x - v2->x) * p[2].x);
                const V3_2b3820 *v3 = &verts[w[18]];
                facing[i + 3] = 0.0f < (((L.z - v3->z) * p[3].z + (L.y - v3->y) * p[3].y) + (L.x - v3->x) * p[3].x);
                i += 4;
                p += 4;
                w += 24;
            } while (i < n - 3);
        }
        if (i < n) {
            const V3_2b3820 *p = normals + i;
            const unsigned short *w = idx + 6 * i;
            do {
                const V3_2b3820 *v0 = &verts[w[0]];
                facing[i] = 0.0f < (((L.z - v0->z) * p->z + (L.x - v0->x) * p->x) + (L.y - v0->y) * p->y);
                i++;
                p++;
                w += 6;
            } while (i < n);
        }
    }
    int edges = 0;
    int tris = 0;
    DAT_0052cbac = 0;
    DAT_0052cba8 = 0;
    if (n != 0) {
        const unsigned short *w = idx;
        for (unsigned int k = 0; k < n; k++, w += 6) {
            if (facing[k] == 0) {
                ((Tri16*)&DAT_0052cbb0)[tris].a = w[0];
                ((Tri16*)&DAT_0052cbb0)[tris].b = w[1];
                ((Tri16*)&DAT_0052cbb0)[tris].c = w[2];
                tris++;
                DAT_0052cbac = tris;
                if (w[3] == 0xffff || facing[w[3]] != 0) {
                    ((Edge16_2b3820*)&DAT_00544bb0)[edges].b = w[0];
                    ((Edge16_2b3820*)&DAT_00544bb0)[edges].a = w[1];
                    edges++;
                    DAT_0052cba8 = edges;
                }
                if (w[4] == 0xffff || facing[w[4]] != 0) {
                    ((Edge16_2b3820*)&DAT_00544bb0)[edges].b = w[1];
                    ((Edge16_2b3820*)&DAT_00544bb0)[edges].a = w[2];
                    edges++;
                    DAT_0052cba8 = edges;
                }
                if (w[5] == 0xffff || facing[w[5]] != 0) {
                    ((Edge16_2b3820*)&DAT_00544bb0)[edges].b = w[2];
                    ((Edge16_2b3820*)&DAT_00544bb0)[edges].a = w[0];
                    edges++;
                    DAT_0052cba8 = edges;
                }
            }
        }
    }
}


// 0x002b3c70 FUN_002b3c70 (1438 B): equivalent/0x002b3c70.cpp
// sym: ?F@DebugMesh@fn_f35954a7@@QAEXXZ @dcbb41984329 @wfca7d3473957
// STATUS: equivalent (tools/equiv.py level 3: 356 inputs, branch coverage 12/12)
// FUN_002b3c70 @ 0x002b3c70
void DebugMesh::F()
{
    V3_2b3c70 *verts = mesh->verts;
    unsigned int count = (*(unsigned int*)&DAT_0052cbac);
    if (count == 0)
        return;
    V3_2b3c70 T;
    T.x = off.x;
    T.y = off.y;
    T.z = off.z;
    T.x = T.x * scale;
    T.y = T.y * scale;
    T.z = T.z * scale;
    Batch_2b3c70 *batch = DAT_0052c2a8->v30((*(Sink_2b3c70**)&DAT_00554bb4)->f10, 0, 0x2020, count * 6, 0);
    if (!outline) {
        for (unsigned short i = 0; i < (*(unsigned int*)&DAT_0052cbac); i++) {
            V3_2b3c70 A = verts[((Tri_2b3c70*)&DAT_0052cbb0)[i].a];
            V3_2b3c70 B = verts[((Tri_2b3c70*)&DAT_0052cbb0)[i].b];
            V3_2b3c70 C = verts[((Tri_2b3c70*)&DAT_0052cbb0)[i].c];
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = C.x;
            batch->p8->y = C.y;
            batch->p8->z = C.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = B.x;
            batch->p8->y = B.y;
            batch->p8->z = B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = A.x;
            batch->p8->y = A.y;
            batch->p8->z = A.z;
            batch->FUN_0008ef00();
            A.x = T.x + A.x;
            A.y = T.y + A.y;
            A.z = T.z + A.z;
            B.x = T.x + B.x;
            B.y = T.y + B.y;
            B.z = T.z + B.z;
            C.x = T.x + C.x;
            C.y = T.y + C.y;
            C.z = T.z + C.z;
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = A.x;
            batch->p8->y = A.y;
            batch->p8->z = A.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = B.x;
            batch->p8->y = B.y;
            batch->p8->z = B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = C.x;
            batch->p8->y = C.y;
            batch->p8->z = C.z;
            batch->FUN_0008ef00();
        }
    } else {
        for (unsigned short i = 0; i < (*(unsigned int*)&DAT_0052cbac); i++) {
            struct Frame {
                V3_2b3c70 B;
                V3_2b3c70 C;
                V3_2b3c70 A;
                V3_2b3c70 D[3];
            } f;
            f.A = verts[((Tri_2b3c70*)&DAT_0052cbb0)[i].a];
            f.B = verts[((Tri_2b3c70*)&DAT_0052cbb0)[i].b];
            f.C = verts[((Tri_2b3c70*)&DAT_0052cbb0)[i].c];
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.C.x;
            batch->p8->y = f.C.y;
            batch->p8->z = f.C.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.B.x;
            batch->p8->y = f.B.y;
            batch->p8->z = f.B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.A.x;
            batch->p8->y = f.A.y;
            batch->p8->z = f.A.z;
            batch->FUN_0008ef00();
            f.D[0].x = f.A.x - off.x;
            f.D[0].y = f.A.y - off.y;
            f.D[0].z = f.A.z - off.z;
            f.D[1].x = f.B.x - off.x;
            f.D[1].y = f.B.y - off.y;
            f.D[1].z = f.B.z - off.z;
            f.D[2].x = f.C.x - off.x;
            f.D[2].y = f.C.y - off.y;
            f.D[2].z = f.C.z - off.z;
            f.D[0].FUN_0022d180();
            f.D[1].FUN_0022d180();
            f.D[2].FUN_0022d180();
            f.D[0].x = f.D[0].x * scale;
            f.D[0].y = f.D[0].y * scale;
            f.D[0].z = f.D[0].z * scale;
            f.D[1].x = f.D[1].x * scale;
            f.D[1].y = f.D[1].y * scale;
            f.D[1].z = f.D[1].z * scale;
            f.D[2].x = f.D[2].x * scale;
            f.D[2].y = f.D[2].y * scale;
            f.D[2].z = f.D[2].z * scale;
            f.A.x = f.D[0].x + f.A.x;
            f.A.y = f.D[0].y + f.A.y;
            f.A.z = f.D[0].z + f.A.z;
            f.B.x = f.D[1].x + f.B.x;
            f.B.y = f.D[1].y + f.B.y;
            f.B.z = f.D[1].z + f.B.z;
            f.C.x = f.D[2].x + f.C.x;
            f.C.y = f.D[2].y + f.C.y;
            f.C.z = f.D[2].z + f.C.z;
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.A.x;
            batch->p8->y = f.A.y;
            batch->p8->z = f.A.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.B.x;
            batch->p8->y = f.B.y;
            batch->p8->z = f.B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.C.x;
            batch->p8->y = f.C.y;
            batch->p8->z = f.C.z;
            batch->FUN_0008ef00();
        }
    }
    DAT_0052c2a8->v31(batch);
}

} // namespace fn_f35954a7

// 0x002b4210 FUN_002b4210 (1198 B): equivalent/0x002b4210.cpp [wrapped: conflict: Gfx; Shadow]
// sym: ?FUN_002b4210@Shadow@fn_002b4210@@QAEXXZ @76a345044573 @w34053899d4cc
namespace fn_002b4210 {
// STATUS: equivalent (tools/equiv.py level 3: 295 inputs, branch coverage 10/10)
// FUN_002b4210 @ 0x002b4210
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

union FI_2b4210 {
    float f;
    int i;
};
struct V3_2b4210 {
    float x, y, z;
    void FUN_0022d180();
};
struct Edge16_2b4210 {
    short a, b;
};
struct Vi {
    int x, y, z;
};
struct Builder {
    char pad00[8];
    FI_2b4210 *pos;
    char pad0c[4];
    int *color;
    void FUN_0008ef00();
};
class Layer_2b4210 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20(unsigned int tag, int color);
};
class Gfx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual Builder *v78(Layer_2b4210 *layer, int b, int c, int d, int e);
    virtual void v7c(Builder *b);
};
struct Holder_2b4210 {
    char pad00[0x10];
    Layer_2b4210 *layer;
};

struct Geom_2b4210 {
    char pad00[0x10];
    V3_2b4210 *verts;
};
class Shadow {
public:
    char pad00[0x48];
    Geom_2b4210 *geom;
    float scale;
    char pad50[4];
    char pointLight;
    char pad55[3];
    V3_2b4210 light;
    void FUN_002b4210();
};

void Shadow::FUN_002b4210()
{
    Builder *b = DAT_0052c2a8->v78((*(Holder_2b4210**)&DAT_00554bb4)->layer, 0, 0x2020, (*(unsigned int*)&DAT_0052cba8) * 6, 0);
    (*(Holder_2b4210**)&DAT_00554bb4)->layer->v20(0x46464944, DAT_004d06dc);
    V3_2b4210 *verts = geom->verts;
    if (!pointLight) {
        V3_2b4210 O;
        float s = scale;
        O.x = s * light.x;
        O.y = s * light.y;
        O.z = s * light.z;
        for (unsigned short i = 0; i < (*(unsigned int*)&DAT_0052cba8); i++) {
            V3_2b4210 *A = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].a];
            V3_2b4210 *B = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].b];
            int Az = ((Vi *)A)->z;
            float Ax = A->x;
            float Ay = A->y;
            Vi Bc = *(Vi *)B;
            FI_2b4210 A2[3];
            A2[0].f = O.x + A->x;
            A2[1].f = O.y + A->y;
            A2[2].f = O.z + A->z;
            FI_2b4210 B2[3];
            B2[0].f = O.x + B->x;
            B2[1].f = O.y + B->y;
            B2[2].f = O.z + B->z;
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[2].i = Az;
                p[0].f = Ax;
                p[1].f = Ay;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = B2[0].i;
                p[1].i = B2[1].i;
                p[2].i = B2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
        }
    } else {
        V3_2b4210 L = light;
        for (unsigned short i = 0; i < (*(unsigned int*)&DAT_0052cba8); i++) {
            V3_2b4210 *A = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].a];
            V3_2b4210 *B = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].b];
            Vi Ac = *(Vi *)A;
            Vi Bc = *(Vi *)B;
            V3_2b4210 D1, D2;
            D1.x = A->x - L.x;
            D1.y = A->y - L.y;
            D1.z = A->z - L.z;
            D2.x = B->x - L.x;
            D2.y = B->y - L.y;
            D2.z = B->z - L.z;
            D1.FUN_0022d180();
            D2.FUN_0022d180();
            D1.x = D1.x * scale;
            D1.y = D1.y * scale;
            D1.z = D1.z * scale;
            D2.x = D2.x * scale;
            D2.y = D2.y * scale;
            D2.z = D2.z * scale;
            FI_2b4210 A2[3];
            A2[0].f = D1.x + A->x;
            A2[1].f = D1.y + A->y;
            A2[2].f = D1.z + A->z;
            FI_2b4210 B2[3];
            B2[0].f = D2.x + B->x;
            B2[1].f = D2.y + B->y;
            B2[2].f = D2.z + B->z;
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Ac.x;
                p[1].i = Ac.y;
                p[2].i = Ac.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = B2[0].i;
                p[1].i = B2[1].i;
                p[2].i = B2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
        }
    }
    DAT_0052c2a8->v7c(b);
}
} // namespace fn_002b4210
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35954a7 {

// 0x002b46c0 FUN_002b46c0 (76 B): matches/0x002b46c0.cpp
// sym: ?Do@Obj_2b46c0@fn_f35954a7@@QAEXHPAVSource_2b46c0@2@@Z
void Obj_2b46c0::Do(int p, Source_2b46c0* q) {
    Data_2b46c0* d = ((Data_2b46c0 *)((owners::C_29c550 *)q)->FUN_0029c550(p));
    if (d->flag == 0) {
        active = 0;
        x = d->e;
        y = d->f;
        z = d->g;
    } else {
        active = 1;
        x = d->b;
        y = d->c;
        z = d->d;
    }
}

} // namespace fn_f35954a7

// 0x002b4710 FUN_002b4710 (381 B): equivalent/0x002b4710.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_002b4710@Obj_2b4710@fn_002b4710@@QAEXXZ @4ad7ab409d38 @w2096b377b924
namespace fn_002b4710 {
// STATUS: equivalent (tools/equiv.py level 3: 154 inputs, branch coverage 4/4)
// FUN_002b4710 @ 0x002b4710
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

struct Stream {
    char pad0[0x8];
    float *pos;
    char pad1[4];
    int *flag;
    void FUN_0008ef00();
};
struct Idx { unsigned short a, b, c; unsigned short pad[3]; };
struct Vec3_2b4710 { float x, y, z; };
struct MeshA { char pad0[0xc]; unsigned int count; Idx *indices; };
struct MeshB { char pad0[0x10]; Vec3_2b4710 *verts; Vec3_2b4710 *offsets; };
class Obj_2b4710 {
public:
    char pad0[0x44];
    MeshA *a;
    MeshB *b;
    void FUN_002b4710();
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
    virtual Stream *v30(int a, int b, int c, int d, int e);
    virtual void v31(Stream *s);
};

void Obj_2b4710::FUN_002b4710()
{
    unsigned int n = a->count;
    Stream *s = DAT_0052c2a8->v30(0, 2, 0x2020, n * 2, 0);
    Idx *idx = a->indices;
    Vec3_2b4710 *q = b->offsets;
    Vec3_2b4710 *v = b->verts;
    for (unsigned int i = 0; i < n; i++) {
        const Vec3_2b4710 &p0 = v[idx[i].a];
        const Vec3_2b4710 &p1 = v[idx[i].b];
        const Vec3_2b4710 &p2 = v[idx[i].c];
        hulk_freg mx = (p1.x - p0.x) * 0.5f + p0.x;
        hulk_freg my = (p1.y - p0.y) * 0.5f + p0.y;
        float mz = (p1.z - p0.z) * 0.5f + p0.z;
        hulk_freg nx = (p2.x - mx) * 0.5f + mx;
        hulk_freg ny = (p2.y - my) * 0.5f + my;
        hulk_freg nz = (p2.z - mz) * 0.5f + mz;
        *s->flag = -1;
        s->pos[0] = nx;
        s->pos[1] = ny;
        s->pos[2] = nz;
        s->FUN_0008ef00();
        hulk_freg x2 = nx + q[i].x;
        hulk_freg y2 = ny + q[i].y;
        hulk_freg z2 = nz + q[i].z;
        *s->flag = -1;
        s->pos[0] = x2;
        s->pos[1] = y2;
        s->pos[2] = z2;
        s->FUN_0008ef00();
    }
    DAT_0052c2a8->v31(s);
}
} // namespace fn_002b4710
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002b4890 FUN_002b4890 (245 B): equivalent/0x002b4890.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_002b4890@Object@fn_002b4890@@QAEXXZ @2343582b799a @w9ab5eea95d05
namespace fn_002b4890 {
// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 4/4)
// FUN_002b4890 @ 0x002b4890
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

struct Vertex_2b4890 { unsigned int x; float y,z; };
struct Triangle_2b4890 { unsigned short index[3]; char pad[6]; };
struct Indices { char pad[12]; unsigned int count; Triangle_2b4890* triangles; };
struct Positions { char pad[16]; Vertex_2b4890* vertices; };
struct Stream { char pad[8]; Vertex_2b4890* position; char pad2[4]; unsigned int* color; void FUN_0008ef00(); };
struct Gfx {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual Stream* v30(int,int,int,unsigned int,int); virtual void v31(Stream*);
};
struct Object { char pad[68]; Indices* indices; Positions* positions; void FUN_002b4890(); };
void Object::FUN_002b4890() {
 Indices* mesh=indices;
 Vertex_2b4890* vertices=positions->vertices;
 unsigned int count=mesh->count;
 Triangle_2b4890* tri=mesh->triangles;
 Stream* stream=DAT_0052c2a8->v30(0,0,0x2020,count*3,0);
 for(unsigned int i=0;i<count;++i,++tri) {
  for(int j=0;j<3;++j) {
   *stream->color=0xff0000ff;
   Vertex_2b4890* src=&vertices[tri->index[j]];
   unsigned int x=src->x;
   float z=src->z;
   float y=src->y;
   stream->position->x=x;
   stream->position->y=y;
   stream->position->z=z;
   stream->FUN_0008ef00();
  }
 }
 DAT_0052c2a8->v31(stream);
}
} // namespace fn_002b4890
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35954a7 {

// 0x002b4990 FUN_002b4990 (331 B): equivalent/0x002b4990.cpp
// sym: ?FUN_002b4990@Mover_2b4990@fn_f35954a7@@QAEXXZ @76a9523ec4c9 @wb93a99b45dcc
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 11/12, incomplete)
// FUN_002b4990 @ 0x002b4990
void Mover_2b4990::FUN_002b4990()
{
    if (pending != 0.0f) {
        reach = pending;
        return;
    }
    if (reach != 0.0f)
        return;

    Scene_2b4990 *scene = (*(World**)&DAT_0052c2b0)->root->scene;
    Probe_2b4990 *probe = scene->probe;
    Vec4_2b4990 pos = origin;
    Vec3_2b4990 dir;
    scene->FUN_00294500(*(Vec3_2b4990 *)&origin, (Vec3_2b4990 *)&pos);
    if (useScene == 0) {
        ((owners::M_22c3b0 *)(probe->vfunc_13()))->FUN_0022c3b0((float *)(const Vec3_2b4990 *)(&goal), (float *)(Vec3_2b4990 *)(&dir));
    } else {
        Vec3_2b4990 from;
        scene->FUN_002940d0(&goal, &from);
        dir.x = pos.x - from.x;
        dir.y = pos.y - from.y;
        dir.z = pos.z - from.z;
        dir.FUN_0022d180();
    }
    unsigned int steps = 1;
    do {
        pos.x = dir.x + pos.x;
        pos.y = dir.y + pos.y;
        pos.z = dir.z + pos.z;
        if (probe->vfunc_16((Vec3_2b4990 *)&pos, pos.w) == 0)
            break;
        steps++;
    } while (steps < 100);
    reach = (float)steps;
}


// 0x002b4b10 FUN_002b4b10 (47 B): matches/0x002b4b10.cpp
// sym: ?Reset@ShadowSkinTopology@fn_f35954a7@@QAEXXZ
void ShadowSkinTopology::Reset() {
    vptr = (void*)((hulk_intptr)DAT_0042e574);
    ReleaseThing(a);
    ReleaseThing(b);
    ReleaseThing(c);
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}


// 0x002b4b40 FUN_002b4b40 (365 B): equivalent/0x002b4b40.cpp
// sym: ?FUN_002b4b40@Tracer_2b4b40@fn_f35954a7@@QAEXPAUNode@2@@Z @164b793424e9 @w39a548c8fa1a
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 13/14, incomplete)
// FUN_002b4b40 @ 0x002b4b40
void Tracer_2b4b40::FUN_002b4b40(Node *node)
{
    if (override != 0.0f) {
        result = override;
        return;
    }
    if (result != 0.0f || node == 0)
        return;

    Space_2b4b40 *space = (*(Globals_2b4b40**)&DAT_0052c2b0)->root->space;
    Probe_2b4b40 *probe = space->probe;
    Frame_2b4b40 f;
    f.pos = origin;
    const Vec3_2b4b40 *shift = (const Vec3_2b4b40 *)(node->data + 0x30);
    f.pos.x = f.pos.x + shift->x;
    f.pos.y = f.pos.y + shift->y;
    f.pos.z = f.pos.z + shift->z;
    space->FUN_002940d0((Vec3_2b4b40 *)&f.pos, (Vec3_2b4b40 *)&f.pos);
    if (!useOffset) {
        ((owners::M_22c3b0 *)(probe->Direction()))->FUN_0022c3b0((float *)(const Vec3_2b4b40 *)(&point), (float *)(Vec3_2b4b40 *)(&f.dir));
    } else {
        space->FUN_002940d0(&point, &f.tmp);
        f.dir.x = f.pos.x - f.tmp.x;
        f.dir.y = f.pos.y - f.tmp.y;
        f.dir.z = f.pos.z - f.tmp.z;
        f.dir.FUN_0022d180();
    }
    unsigned int n = 1;
    do {
        float w = f.pos.w;
        f.pos.x = f.dir.x + f.pos.x;
        f.pos.y = f.dir.y + f.pos.y;
        f.pos.z = f.dir.z + f.pos.z;
        if (!probe->Step(&f.pos, w))
            break;
        n++;
    } while (n < 100);
    result = (float)n;
}

} // namespace fn_f35954a7

// 0x002b4cb0 pure3d::ShadowMeshLoader::vfunc_6 (24 B): matches/0x002b4cb0.cpp
// sym: ?vfunc_6@ShadowMeshLoader@pure3d@@UAEPAXXZ
// Same code shape as 0x0013e710 (propagated; names are from that function)
void* pure3d::ShadowMeshLoader::vfunc_6() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_2b4cb0*)p)->init_002deeb0());
    return (void*)(0);
}


// 0x002b4cd0 pure3d::ShadowSkinLoader::vfunc_6 (24 B): matches/0x002b4cd0.cpp
// sym: ?vfunc_6@ShadowSkinLoader@pure3d@@UAEPAXXZ
// Same code shape as 0x0013e710 (propagated; names are from that function)
void* pure3d::ShadowSkinLoader::vfunc_6() {
    void* p = Allocate(0x58);
    if (p)
        return (void*)(((Built_2b4cd0*)p)->init_002defb0());
    return (void*)(0);
}


// 0x002b4cf0 FUN_002b4cf0 (32 B): matches/0x002b4cf0.cpp
// sym: ?FUN_002b4cf0@ShadowMeshBufferImpl@pure3d@@QAEPAV12@XZ
pure3d::ShadowMeshBufferImpl* pure3d::ShadowMeshBufferImpl::FUN_002b4cf0() {
    ((ThisCall_002a5060*)(this))->Init_002a5060();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042e584);
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x10) = 2;
    return (pure3d::ShadowMeshBufferImpl*)(this);
}


// 0x002b4d10 pure3d::ShadowMeshBufferImpl::vfunc_9 (3 B): matches/0x002b4d10.cpp
// sym: ?vfunc_9@ShadowMeshBufferImpl@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::ShadowMeshBufferImpl::vfunc_9() {
    return 0;
}

namespace fn_f35954a7 {

// 0x002b4d20 pure3d::ShadowMeshBufferImpl::vfunc_7 (3 B): matches/0x002b4d20.cpp
// sym: ?GetZero@fn_f35954a7@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f35954a7

// 0x002b4d30 pure3d::ShadowMeshBufferImpl::vfunc_8 (3 B): matches/0x002b4d30.cpp
// sym: ?vfunc_8@ShadowMeshBufferImpl@pure3d@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::ShadowMeshBufferImpl::vfunc_8(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x002b4d40 pure3d::ShadowMeshBufferImpl::vfunc_5 (6 B): matches/0x002b4d40.cpp
// sym: ?vfunc_5@ShadowMeshBufferImpl@pure3d@@UAEHXZ
int pure3d::ShadowMeshBufferImpl::vfunc_5() {
    return (int)(0x200);
}

namespace fn_f35954a7 {

// 0x002b4d50 pure3d::ShadowMeshBufferImpl::vfunc_10 (1 B): matches/0x002b4d50.cpp
// sym: ?FUN_002b4d50@fn_f35954a7@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002b4d50() {}

} // namespace fn_f35954a7

// 0x002b4d60 FUN_002b4d60 (34 B): matches/0x002b4d60.cpp
// sym: ?FUN_002b4d60@ShadowMeshBufferImpl@pure3d@@QAEPAV12@H@Z
pure3d::ShadowMeshBufferImpl* pure3d::ShadowMeshBufferImpl::FUN_002b4d60(int arg) {
    Init_002a5060(this);
    *(void**)this = (void*)((hulk_intptr)DAT_0042e584);
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x10) = 2;
    return (pure3d::ShadowMeshBufferImpl*)(this);
}


// 0x002b4d90 pure3d::ShadowMeshBufferImpl::vfunc_4 (52 B): matches/0x002b4d90.cpp
// sym: ?vfunc_4@ShadowMeshBufferImpl@pure3d@@UAEPAXXZ
void* pure3d::ShadowMeshBufferImpl::vfunc_4() {
    pure3d::ShadowMeshBufferImpl* p = (pure3d::ShadowMeshBufferImpl*)alloc_00263ea0(0x48);
    if (p) {
        ((ShadowMeshBufferImpl_nv_2b4d90*)(p))->initialize_002a5060();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042e584);
        *(u32_2b4d90*)((char*)p + 0x40) = 0;
        *(u32_2b4d90*)((char*)p + 0x10) = 2;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x002b4dd0 pure3d::ShadowMeshBufferImpl::vfunc_3 (3 B): matches/0x002b4dd0.cpp
// sym: ?vfunc_3@ShadowMeshBufferImpl@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ShadowMeshBufferImpl::vfunc_3() {
    return true;
}


// 0x002b4e00 pure3d::ShadowMeshBufferImpl::vfunc_6 (92 B): matches/0x002b4e00.cpp
// sym: ?vfunc_6@ShadowMeshBufferImpl@pure3d@@UAEXXZ
void pure3d::ShadowMeshBufferImpl::vfunc_6() {
    hulk_at_0052c2a8->m54(2);
    hulk_at_0052c2a8->m74(0, 0, 3);
    (*(Child_2b4e00 * *)&this->f_40)->g();
    hulk_at_0052c2a8->m54(1);
    hulk_at_0052c2a8->m74(0, 0, 4);
    (*(Child_2b4e00 * *)&this->f_40)->g();
}

namespace fn_f35954a7 {

// 0x002b4e60 pure3d::ShadowMeshBufferLoader::vfunc_6 (26 B): matches/0x002b4e60.cpp
// sym: ?vfunc_6@ShadowMeshBufferLoader@fn_f35954a7@@UAEPAVShadowMeshBuffer_2b4e60@2@H@Z
ShadowMeshBuffer_2b4e60* ShadowMeshBufferLoader::vfunc_6(int x) {
    ShadowMeshBuffer_2b4e60* p = (ShadowMeshBuffer_2b4e60*)alloc_00263ea0(0x58);
    if (p)
        return p->Init_002df0b0(x);
    return 0;
}


// 0x002b5050 FUN_002b5050 (22 B): matches/0x002b5050.cpp
// sym: ?f@C_2b5050@fn_f35954a7@@QAEXXZ
// Same code shape as 0x00045820 (propagated; names are from that function)
void C_2b5050::f() {
    if (p) {
        p->b();
        p = 0;
    }
}

} // namespace fn_f35954a7

// 0x002b5070 FUN_002b5070 (76 B): matches/0x002b5070.cpp [wrapped: conflict: alloc]
// sym: ??0ShadowMeshVertices@fn_002b5070@@QAE@HH@Z
namespace fn_002b5070 {
extern "C++" __declspec(nothrow) void* alloc_0008d6d0(hulk_uintptr);
class ShadowMeshVertices {
  public:
    virtual ~ShadowMeshVertices();
    int m1;
    int count;
    int count2;
    void* p1;
    void* p2;
    ShadowMeshVertices(int, int);
};
ShadowMeshVertices::ShadowMeshVertices(int a, int b) {
    m1 = 0;
    p1 = 0;
    p2 = 0;
    count = a;
    count2 = b;
    p1 = alloc_0008d6d0(a * 12);
    p2 = alloc_0008d6d0(count2 * 12);
}
} // namespace fn_002b5070


// 0x002b50c0 pure3d::ShadowMeshVertices::vfunc_2 (59 B): matches/0x002b50c0.cpp [wrapped: conflict: pure3d::ShadowMeshVertices]
// sym: ?vfunc_2@ShadowMeshVertices@pure3d@fn_002b50c0@@UAEPAV123@E@Z
namespace fn_002b50c0 {
typedef unsigned char byte_2b50c0;
void thunk_0008d330(void*);
void thunk_val_0008d340(unsigned int);
extern void* hulk_at_0042e554;
extern void* ref_vftable_2b50c0;
namespace pure3d {
class ShadowMeshVertices {
  public:
    virtual void f0();
    virtual void f1();
    virtual ShadowMeshVertices* vfunc_2(byte_2b50c0);
    char pad[0x10 - 4];
};
ShadowMeshVertices* ShadowMeshVertices::vfunc_2(byte_2b50c0 param) {
    *(void**)this = &hulk_at_0042e554;
    thunk_val_0008d340(*(unsigned int*)((char*)this + 0x10));
    thunk_val_0008d340(*(unsigned int*)((char*)this + 0x14));
    *(void**)this = &ref_vftable_2b50c0;
    if (param & 1)
        thunk_0008d330(this);
    return this;
}
} // namespace pure3d
} // namespace fn_002b50c0


// 0x002b5100 FUN_002b5100 (176 B): matches/0x002b5100.cpp [wrapped: conflict: alloc]
// sym: ??0ShadowMeshVertices_2b5100@fn_002b5100@@QAE@ABU01@@Z
namespace fn_002b5100 {
void* __cdecl alloc_0008d6d0(hulk_uintptr) throw();
struct V3_2b5100 {
    unsigned a, b, c;
    void Set(const V3_2b5100& s) {
        a = s.a;
        b = s.b;
        c = s.c;
    }
};
struct NonCopyable_2b5100 {
    virtual ~NonCopyable_2b5100() throw();
};
struct Init1_2b5100 {
    unsigned m4;
    Init1_2b5100() throw() { m4 = 0; }
};
struct ShadowMeshVertices_2b5100 : NonCopyable_2b5100, Init1_2b5100 {
    unsigned m8, mc;
    V3_2b5100* m10;
    V3_2b5100* m14;
    ShadowMeshVertices_2b5100(const ShadowMeshVertices_2b5100& o) throw();
    virtual ~ShadowMeshVertices_2b5100() throw();
};
ShadowMeshVertices_2b5100::ShadowMeshVertices_2b5100(const ShadowMeshVertices_2b5100& o) throw() {
    unsigned i = 0;
    m8 = o.m8;
    mc = o.mc;
    m10 = (V3_2b5100*)alloc_0008d6d0(m8 * 12);
    m14 = (V3_2b5100*)alloc_0008d6d0(mc * 12);
    for (; i < m8; i++)
        m10[i].Set(o.m10[i]);
    for (i = 0; i < mc; i++)
        m14[i].Set(o.m14[i]);
}
} // namespace fn_002b5100


// 0x002b5200 pure3d::ShadowMeshTopology::vfunc_2 (59 B): matches/0x002b5200.cpp [wrapped: conflict: pure3d::ShadowMeshVertices]
// sym: ?vfunc_2@ShadowMeshVertices@pure3d@fn_002b5200@@UAEPAV123@E@Z
namespace fn_002b5200 {
// Same code shape as 0x002b50c0 (propagated; names are from that function)
typedef unsigned char byte_2b5200;
void thunk_0008d330(void*);
void thunk_val_0008d340(unsigned int);
extern void* hulk_at_0042e564;
extern void* ref_vftable_2b5200;
namespace pure3d {
class ShadowMeshVertices {
  public:
    virtual void f0();
    virtual void f1();
    virtual ShadowMeshVertices* vfunc_2(byte_2b5200);
    char pad[0x10 - 4];
};
ShadowMeshVertices* ShadowMeshVertices::vfunc_2(byte_2b5200 param) {
    *(void**)this = &hulk_at_0042e564;
    thunk_val_0008d340(*(unsigned int*)((char*)this + 0x10));
    thunk_val_0008d340(*(unsigned int*)((char*)this + 0x14));
    *(void**)this = &ref_vftable_2b5200;
    if (param & 1)
        thunk_0008d330(this);
    return this;
}
} // namespace pure3d
} // namespace fn_002b5200

namespace fn_f35954a7 {

// 0x002b5240 FUN_002b5240 (77 B): matches/0x002b5240.cpp
// sym: ??0ShadowMeshImpl@fn_f35954a7@@QAE@XZ
ShadowMeshImpl::ShadowMeshImpl() : DrawablePrimitive_2b5240(), handle(), a(0), b(0), c(0), d(0) {
    n = 2;
    handle = (*(Ref**)&DAT_00554bb0);
}

} // namespace fn_f35954a7

// 0x002b5290 pure3d::ShadowMeshImpl::vfunc_9 (3 B): matches/0x002b5290.cpp
// sym: ?vfunc_9@ShadowMeshImpl@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::ShadowMeshImpl::vfunc_9() {
    return 0;
}


// 0x002b52a0 pure3d::ShadowMeshImpl::vfunc_7 (3 B): matches/0x002b52a0.cpp [wrapped: same definition as 0x002b4d20 in this TU]
// sym: ?GetZero@fn_002b52a0@@YAIXZ
namespace fn_002b52a0 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_002b52a0


// 0x002b52b0 pure3d::ShadowMeshImpl::vfunc_8 (3 B): matches/0x002b52b0.cpp
// sym: ?vfunc_8@ShadowMeshImpl@pure3d@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::ShadowMeshImpl::vfunc_8(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x002b52c0 pure3d::ShadowMeshImpl::vfunc_5 (6 B): matches/0x002b52c0.cpp
// sym: ?vfunc_5@ShadowMeshImpl@pure3d@@UAEHXZ
// Same code shape as 0x00274850 (propagated; names are from that function)
int pure3d::ShadowMeshImpl::vfunc_5() {
    return (int)(0x10);
}

namespace fn_f35954a7 {

// 0x002b52d0 pure3d::ShadowMeshImpl::vfunc_10 (1 B): matches/0x002b52d0.cpp
// sym: ?FUN_002b52d0@fn_f35954a7@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002b52d0() {}

} // namespace fn_f35954a7

// 0x002b52e0 FUN_002b52e0 (141 B): matches/0x002b52e0.cpp [wrapped: conflict: ShadowMeshImpl]
// sym: ??0ShadowMeshImpl@fn_002b52e0@@QAE@PAX@Z
namespace fn_002b52e0 {
// data: gGlobal_2b52e0 = DAT_00554bb0

class Ref_2b52e0 {
  public:
    virtual void A();
    virtual void B();
};
class DrawablePrimitive_2b52e0 {
  public:
    virtual void FnQ_00038290();
    DrawablePrimitive_2b52e0();
};
inline Ref_2b52e0* Acq(Ref_2b52e0* x) {
    if (x)
        x->A();
    return x;
}
class ShadowMeshImpl : public DrawablePrimitive_2b52e0 {
  public:
    virtual void FnV_000382a0();
    int pad10[3];
    int mValue;
    char pad14[0x2c];
    Ref_2b52e0* m0;
    Ref_2b52e0* m1;
    Ref_2b52e0* m2;
    Ref_2b52e0* m3;
    Ref_2b52e0* m4;
    ShadowMeshImpl(void*);
};
class Input_2b52e0 {
  public:
    char pad[0x44];
    Ref_2b52e0* a;
    Ref_2b52e0* b;
};
ShadowMeshImpl::ShadowMeshImpl(void* arg) {
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    mValue = 2;
    Ref_2b52e0* p = Acq((*(Ref_2b52e0**)&DAT_00554bb0));
    if (m0)
        m0->B();
    m0 = p;
    p = ((Input_2b52e0*)arg)->a;
    if (p)
        p->A();
    if (m1)
        m1->B();
    m1 = p;
    p = ((Input_2b52e0*)arg)->b;
    if (p)
        p->A();
    if (m2)
        m2->B();
    m2 = p;
}
} // namespace fn_002b52e0

namespace fn_f35954a7 {

// 0x002b5370 FUN_002b5370 (74 B): matches/0x002b5370.cpp
// sym: ?f@ShadowMeshImpl_2b5370@fn_f35954a7@@QAEXXZ
void ShadowMeshImpl_2b5370::f() {
    vptr = hulk_at_0042e5b4;
    _ReadWriteBarrier();
    if (m40) {
        m40->f1();
        m40 = 0;
    }
    if (m44) {
        m44->f1();
        m44 = 0;
    }
    if (m48) {
        m48->f1();
        m48 = 0;
    }
    ((Helper_2b5370*)this)->Fn_002a50a0();
}

} // namespace fn_f35954a7

// 0x002b53c0 pure3d::ShadowMeshImpl::vfunc_4 (31 B): matches/0x002b53c0.cpp
// sym: ?vfunc_4@ShadowMeshImpl@pure3d@@UAEPAXXZ
// Same code shape as 0x00224c60 (propagated; names are from that function)
void* pure3d::ShadowMeshImpl::vfunc_4() {
    Helper_2b53c0* p = (Helper_2b53c0*)thunk_FUN_0008d690(0x70);
    if (p)
        return (void*)(p->run_002b52e0(this));
    return (void*)(0);
}

namespace fn_f35954a7 {

// 0x002b53e0 FUN_002b53e0 (1 B): matches/0x002b53e0.cpp
// sym: _FUN_002b53e0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_002b53e0() {}


// 0x002b53f0 FUN_002b53f0 (26 B): matches/0x002b53f0.cpp
// sym: ?target@fn_f35954a7@@YAXXZ
// Same code shape as 0x00085d70 (propagated; names are from that function)
// data: globalObj_2b53f0 = DAT_00554bb0
void target() {
    if ((*(Obj_2b53f0**)&DAT_00554bb0)) {
        (*(Obj_2b53f0**)&DAT_00554bb0)->g();
        (*(Obj_2b53f0**)&DAT_00554bb0) = 0;
    }
}

} // namespace fn_f35954a7

// 0x002b5410 pure3d::ShadowMeshImpl::vfunc_6 (212 B): matches/0x002b5410.cpp [wrapped: conflict: Gfx; pure3d::ShadowMeshImpl]
// sym: ?vfunc_6@ShadowMeshImpl@pure3d@fn_002b5410@@UAEXXZ
namespace fn_002b5410 {
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

struct Vector {
    float x, y, z;
};
struct Matrix {
    float elements[16];
    void FUN_0022cdb0();
    void FUN_0022c2b0(Vector*, Vector*);
    void FUN_0022c3b0(Vector*, Vector*);
};
struct MatrixSource_2b5410 {
    Matrix* FUN_0028faa0();
};
struct Gfx {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54(int);
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74(int, int, int);
};
namespace pure3d {
struct ShadowMeshImpl {
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
    char padding[0x48];
    unsigned int state;
    char padding50[4];
    unsigned char mode;
    char padding55[3];
    Vector first;
    Vector second;
    void FUN_002b4990();
    void FUN_002b3820();
    void FUN_002b4210();
    void FUN_002b3c70();
};
void ShadowMeshImpl::vfunc_6() {
    Matrix matrix = *(*(MatrixSource_2b5410**)&DAT_0052c2b4)->FUN_0028faa0();
    matrix.FUN_0022cdb0();
    if (mode)
        matrix.FUN_0022c2b0(&second, &first);
    else
        matrix.FUN_0022c3b0(&second, &first);
    FUN_002b4990();
    FUN_002b3820();
    DAT_0052c2a8->slot54(2);
    DAT_0052c2a8->slot74(0, 0, 3);
    FUN_002b4210();
    FUN_002b3c70();
    DAT_0052c2a8->slot54(1);
    DAT_0052c2a8->slot74(0, 0, 4);
    FUN_002b4210();
    FUN_002b3c70();
    state = 0;
}
} // namespace pure3d
} // namespace fn_002b5410
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002b5560 pure3d::ShadowSkinTopology::vfunc_2 (68 B): matches/0x002b5560.cpp [wrapped: conflict: ShadowSkinTopology]
// sym: ?vfunc_2@ShadowSkinTopology@fn_002b5560@@UAEPAV12@E@Z
namespace fn_002b5560 {
typedef unsigned char u8_2b5560;
typedef unsigned int u32_2b5560;
extern int hulk_at_0042e574;
extern int ref_vtable;
void release_0008d340(void*);
void release_self_0008d330(void*);
class ShadowSkinTopology {
  public:
    virtual void v0();
    virtual void v1();
    virtual ShadowSkinTopology* vfunc_2(u8_2b5560);
    u32_2b5560 a;
    hulk_uintptr b;
    hulk_uintptr c;
    hulk_uintptr d;
};
ShadowSkinTopology* ShadowSkinTopology::vfunc_2(u8_2b5560 param) {
    *(int**)this = &hulk_at_0042e574;
    release_0008d340((void*)b);
    release_0008d340((void*)c);
    release_0008d340((void*)d);
    *(int**)this = &ref_vtable;
    if (param & 1)
        release_self_0008d330((void*)this);
    return this;
}
} // namespace fn_002b5560

namespace fn_f35954a7 {

// 0x002b55b0 FUN_002b55b0 (39 B): matches/0x002b55b0.cpp
// sym: ??0ShadowSkinImpl@fn_f35954a7@@QAE@XZ
ShadowSkinImpl::ShadowSkinImpl() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042e5e4);
    *(int*)((char*)this + 0x10) = 2;
}


// 0x002b55e0 pure3d::ShadowSkinImpl::vfunc_5 (6 B): matches/0x002b55e0.cpp
// sym: ?FUN_002b55e0@fn_f35954a7@@YAIXZ
// Same code shape as 0x00036c80 (propagated; names are from that function)
unsigned int FUN_002b55e0(void) {
    return 0x20;
}


// 0x002b55f0 pure3d::ShadowSkinImpl::vfunc_10 (1 B): matches/0x002b55f0.cpp
// sym: ?FUN_002b55f0@fn_f35954a7@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002b55f0() {}

} // namespace fn_f35954a7

// 0x002b5600 pure3d::ShadowSkinImpl::vfunc_3 (3 B): matches/0x002b5600.cpp
// sym: ?vfunc_3@ShadowSkinImpl@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ShadowSkinImpl::vfunc_3() {
    return true;
}


// 0x002b5610 FUN_002b5610 (202 B): equivalent/0x002b5610.cpp [wrapped: conflict: pure3d::ShadowSkinImpl]
// sym: ??0ShadowSkinImpl@pure3d@fn_002b5610@@QAE@PAUFUN_002b52e0@2@@Z @46ee39bc68fe @w2cffcacc2f43
namespace fn_002b5610 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_002b5610 @ 0x002b5610
struct Ref_2b5610 { virtual void AddRef(); virtual void Release(); char pad[12]; unsigned count; };
struct Matrix { char data[64]; void FUN_0022b980(); };
struct ShadowMeshVertices_2b5610 : Ref_2b5610 { ShadowMeshVertices_2b5610* FUN_002b5100(Ref_2b5610*); };
void* __cdecl FUN_0008d6d0(unsigned);
void* __cdecl FUN_0008d690(unsigned);
struct FUN_002b52e0 { virtual void dummy(); char pad04[12]; unsigned type; char pad14[52]; Ref_2b5610* object; char pad4c[36]; Ref_2b5610* resource; Matrix* matrices; Ref_2b5610* resource2; unsigned tail; FUN_002b52e0(FUN_002b52e0*); };
namespace pure3d {
struct ShadowSkinImpl : FUN_002b52e0 { virtual void dummy(); ShadowSkinImpl(FUN_002b52e0*); };
}
pure3d::ShadowSkinImpl::ShadowSkinImpl(FUN_002b52e0* src) : FUN_002b52e0(src) {
 resource=0; matrices=0; resource2=0; tail=0; type=2;
 Ref_2b5610* p=src->resource;
 if(p) p->AddRef();
 if(resource) resource->Release();
 resource=p;
 p=src->resource2;
 if(p) p->AddRef();
 if(resource2) resource2->Release();
 resource2=p;
 Matrix* mem=(Matrix*)FUN_0008d6d0((resource->count+1)*64);
 matrices=mem;
 mem[resource->count].FUN_0022b980();
 ShadowMeshVertices_2b5610* obj=(ShadowMeshVertices_2b5610*)FUN_0008d690(24);
 Ref_2b5610* result=obj ? obj->FUN_002b5100(src->object) : 0;
 if(result) result->AddRef();
 if(object) object->Release();
 object=result;
}
} // namespace fn_002b5610

namespace fn_f35954a7 {

// 0x002b56e0 FUN_002b56e0 (144 B): matches/0x002b56e0.cpp
// sym: ??1ShadowSkinImpl_2b56e0@fn_f35954a7@@QAE@XZ
ShadowSkinImpl_2b56e0::~ShadowSkinImpl_2b56e0() {
    vptr = hulk_at_0042e5e4;
    _ReadWriteBarrier();
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    if (m7c) {
        m7c->Release();
        m7c = 0;
    }
    if (m78) {
        m78->Release();
        m78 = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    operator delete(m74);
    *(void* volatile*)&vptr = g_vftable2;
    Ref_2b56e0* t = *(Ref_2b56e0* volatile*)&m40;
    if (t) {
        t->Release();
        m40 = 0;
    }
    if (m44) {
        m44->Release();
        m44 = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    Fin_002a50a0();
}


// 0x002b57a0 FUN_002b57a0 (38 B): matches/0x002b57a0.cpp
// sym: ?Set@Owner_2b57a0@fn_f35954a7@@QAEXPAVItem_2b57a0@2@@Z
void Owner_2b57a0::Set(Item_2b57a0* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
}

} // namespace fn_f35954a7

// 0x002b57d0 FUN_002b57d0 (2418 B): equivalent/0x002b57d0.cpp [wrapped: macros]
// sym: ?Update@ShadowMeshImpl@pure3d@fn_002b57d0@@QAEXPAUSkel@3@@Z @efe6201e7d0f @w2457c16eb10e
namespace fn_002b57d0 {
// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 38/42, incomplete)
// FUN_002b57d0 @ 0x002b57d0
struct V3 {
    float x, y, z;
};
struct Mat {
    float m[16];
    void FUN_0022ca90(const Mat* a, const Mat* b);
};
struct Rec0 {
    float x, y, z;
    short idx;
    unsigned char c0;
    unsigned char pad0f;
    unsigned int pad10;
};
struct Rec1 {
    float x, y, z;
    short idx;
    unsigned short pad0e;
    float w0, w1;
    unsigned char c0, c1;
    unsigned short pad1a;
};
struct Rec2 {
    float x, y, z;
    short idx;
    unsigned short pad0e;
    float w0, w1, w2;
    unsigned char c0, c1, c2, c3;
};
struct TriIdx {
    unsigned short a, b, c;
    unsigned short pad[3];
};
struct Topo {
    char pad00[8];
    Rec0* r0;
    Rec1* r1;
    Rec2* r2;
    int n0;
    int n1;
    int n2;
};
struct Skel {
    char pad00[0xc];
    unsigned int count;
    char pad10[0x1c - 0x10];
    Mat* mats;
    void FUN_00284820(int z);
};
struct SrcMats {
    char pad00[0x10];
    unsigned int count;
    char pad14[0x20 - 0x14];
    Mat* mats;
};
struct IdxBuf {
    char pad00[0xc];
    int count;
    TriIdx* tris;
};
struct OutBuf {
    char pad00[0x10];
    V3* verts;
    V3* normals;
};
namespace pure3d {
class ShadowMeshImpl {
  public:
    char pad00[0x44];
    IdxBuf* idx;
    OutBuf* out;
    char pad4c[0x70 - 0x4c];
    SrcMats* src;
    Mat* cache;
    Topo* topo;
    void FUN_002b4b40(Skel* s);
    void vfunc_6_002b5410();
    void Update(Skel* arg);
};
} // namespace pure3d
#define XG_X(M, x, y, z) (((y) * (M)->m[4] + (z) * (M)->m[8]) + (x) * (M)->m[0] + (M)->m[12])
#define XG_Y(M, x, y, z) (((y) * (M)->m[5] + (x) * (M)->m[1]) + (z) * (M)->m[9] + (M)->m[13])
#define XG_Z(M, x, y, z) (((y) * (M)->m[6] + (x) * (M)->m[2]) + (z) * (M)->m[10] + (M)->m[14])
#define XF_X(M, x, y, z) ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12])
#define XF_Y(M, x, y, z) ((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13])
#define XF_Z(M, x, y, z) ((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14])

void pure3d::ShadowMeshImpl::Update(Skel* arg) {
    if (!arg)
        return;
    arg->FUN_00284820(0);
    unsigned int cnt = src->count;
    if (arg->count < cnt)
        cnt = arg->count;
    bool changed = false;
    if (cnt != 0) {
        for (unsigned int i = 0; i < cnt; i++) {
            Mat transformed;
            transformed.FUN_0022ca90(&src->mats[i], &arg->mats[i]);
            if (!changed) {
                for (int r = 0; r < 4 && !changed; r++) {
                    for (int c = 0; c < 4; c++) {
                        if (!(transformed.m[r * 4 + c] == cache[i].m[r * 4 + c])) {
                            changed = true;
                            break;
                        }
                    }
                }
            }
            cache[i] = transformed;
        }
        if (changed) {
            IdxBuf* ib = idx;
            int nt = ib->count;
            TriIdx* tris = ib->tris;
            OutBuf* ob = out;
            V3* ov = ob->verts;
            V3* nrms = ob->normals;
            Topo* T = topo;
            Rec0* R0 = T->r0;
            Rec1* R1 = T->r1;
            Rec2* R2 = T->r2;
            int N0 = T->n0;
            int N1 = T->n1;
            int N2 = T->n2;
            for (int j = 0; j < N2; j++) {
                Rec2* r = &R2[j];
                Mat* M0 = &cache[r->c0];
                double rx = XG_X(M0, r->x, r->y, r->z) * r->w0;
                volatile float ry = (float)(XG_Y(M0, r->x, r->y, r->z) * r->w0);
                volatile float rz = (float)(XG_Z(M0, r->x, r->y, r->z) * r->w0);
                Mat* M1 = &cache[r->c1];
                float w1 = r->w1;
                rx = XG_X(M1, r->x, r->y, r->z) * w1 + rx;
                ry = (float)(XG_Y(M1, r->x, r->y, r->z) * w1 + ry);
                rz = (float)(XG_Z(M1, r->x, r->y, r->z) * w1 + rz);
                Mat* M2 = &cache[r->c2];
                float w2 = r->w2;
                rx = XG_X(M2, r->x, r->y, r->z) * w2 + rx;
                double ry2 = XG_Y(M2, r->x, r->y, r->z) * w2 + ry;
                rz = (float)(XG_Z(M2, r->x, r->y, r->z) * w2 + rz);
                V3* o = &ov[r->idx];
                o->x = (float)rx;
                o->y = (float)ry2;
                o->z = rz;
            }
            for (int j = 0; j < N1; j++) {
                Rec1* r = &R1[j];
                Mat* M0 = &cache[r->c0];
                volatile float x0 = (float)(XG_X(M0, r->x, r->y, r->z) * r->w0);
                volatile float y0 = (float)(XG_Y(M0, r->x, r->y, r->z) * r->w0);
                double z0 = XG_Z(M0, r->x, r->y, r->z) * r->w0;
                Mat* M1 = &cache[r->c1];
                float w1 = r->w1;
                V3* o = &ov[r->idx];
                float xo = (float)(XG_X(M1, r->x, r->y, r->z) * w1 + x0);
                float yo = (float)(XG_Y(M1, r->x, r->y, r->z) * w1 + y0);
                volatile float zo = (float)(XG_Z(M1, r->x, r->y, r->z) * w1 + z0);
                o->x = xo;
                o->z = zo;
                o->y = yo;
            }
            for (int j = 0; j < N0; j++) {
                Rec0* r = &R0[j];
                Mat* M0 = &cache[r->c0];
                V3* o = &ov[r->idx];
                float xo = (float)XF_X(M0, r->x, r->y, r->z);
                float yo = (float)XF_Y(M0, r->x, r->y, r->z);
                volatile float zo = (float)XF_Z(M0, r->x, r->y, r->z);
                o->x = xo;
                o->z = zo;
                o->y = yo;
            }
            for (int t = 0; t < nt; t++) {
                TriIdx* ti = &tris[t];
                V3* pa = &ov[ti->a];
                V3* pb = &ov[ti->b];
                V3* pc = &ov[ti->c];
                double ex = pb->x - pa->x;
                double ey = pb->y - pa->y;
                double ez = pb->z - pa->z;
                volatile float fx = pc->x - pb->x;
                volatile float fy = pc->y - pb->y;
                double fz = pc->z - pb->z;
                V3* nrm = &nrms[t];
                nrm->x = (float)(fz * ey - fy * ez);
                nrm->y = (float)(ez * fx - fz * ex);
                nrm->z = (float)(fy * ex - fx * ey);
            }
        }
    }
    FUN_002b4b40(arg);
    vfunc_6_002b5410();
}
} // namespace fn_002b57d0
#undef XF_X
#undef XF_Y
#undef XF_Z
#undef XG_X
#undef XG_Y
#undef XG_Z

namespace fn_f35954a7 {

// 0x002b6150 FUN_002b6150 (27 B): matches/0x002b6150.cpp
// sym: ??0ShadowMeshLoader@fn_f35954a7@@QAE@XZ
ShadowMeshLoader::ShadowMeshLoader() {
    a = 0;
    b = 0x1001a;
    c = 0;
    d = 0;
    vptr = ((hulk_intptr)DAT_0042e614);
}


// 0x002b6870 FUN_002b6870 (27 B): matches/0x002b6870.cpp
// sym: ??0ShadowSkinLoader@fn_f35954a7@@QAE@XZ
ShadowSkinLoader::ShadowSkinLoader() {
    a = 0;
    b = 0x10019;
    c = 0;
    d = 0;
    v = ((hulk_intptr)DAT_0042e634);
}


// 0x002b6890 FUN_002b6890 (36 B): matches/0x002b6890.cpp
// sym: ??1ShadowMeshBufferImpl_2b6890@fn_f35954a7@@QAE@XZ
ShadowMeshBufferImpl_2b6890::~ShadowMeshBufferImpl_2b6890() {
    vptr = hulk_at_0042e584;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a50a0();
}

} // namespace fn_f35954a7

// 0x002b68c0 FUN_002b68c0 (74 B): matches/0x002b68c0.cpp [wrapped: conflict: ShadowMeshBufferLoader]
// sym: ?target@fn_002b68c0@@YIPAVShadowMeshBufferLoader@1@PAV21@@Z
namespace fn_002b68c0 {
extern "C" char DAT_0042e654[];
class ShadowMeshBufferLoader {
  public:
    hulk_intptr a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
extern "C++" __declspec(nothrow) int __cdecl alloc_mem_0008d690(int);
int __fastcall init_obj_002df7f0(int);
ShadowMeshBufferLoader* __fastcall target(ShadowMeshBufferLoader* self) {
    self->b = 0;
    self->c = 0x10023;
    self->d = 0;
    self->e = 0;
    self->a = ((hulk_intptr)DAT_0042e654);
    int p = alloc_mem_0008d690(0x2c);
    self->f = p ? init_obj_002df7f0(p) : 0;
    return self;
}
} // namespace fn_002b68c0

namespace fn_f35954a7 {

// 0x002b6910 FUN_002b6910 (25 B): matches/0x002b6910.cpp
// sym: ?F@ShadowMeshBufferLoader_2b6910@fn_f35954a7@@QAEXXZ
void ShadowMeshBufferLoader_2b6910::F() {
    vptr = &hulk_at_0042e654;
    member->B();
    vptr = &hulk_at_003f6098;
}

} // namespace fn_f35954a7

// 0x002b6eb0 pure3d::ShadowMeshImpl::vfunc_2 (95 B): matches/0x002b6eb0.cpp [wrapped: conflict: ShadowMeshImpl]
// sym: ?vfunc_2@ShadowMeshImpl@fn_002b6eb0@@QAEPAV12@E@Z
namespace fn_002b6eb0 {
extern "C" char DAT_0042e5b4[];
struct RelObj_2b6eb0 {
    virtual void vfunc_0();
    virtual void Release();
};



class ShadowMeshImpl {
  public:
    void BaseCleanup_002a50a0();

    void* volatile m_vptr;
    char pad[0x3C];
    RelObj_2b6eb0* volatile m_a;
    RelObj_2b6eb0* volatile m_b;
    RelObj_2b6eb0* volatile m_c;

    ShadowMeshImpl* vfunc_2(unsigned char flags);
};

ShadowMeshImpl* ShadowMeshImpl::vfunc_2(unsigned char flags) {
    m_vptr = (void*)((hulk_intptr)DAT_0042e5b4);
    RelObj_2b6eb0* a = m_a;
    if (a != 0) {
        a->Release();
        m_a = 0;
    }
    RelObj_2b6eb0* b = m_b;
    if (b != 0) {
        b->Release();
        m_b = 0;
    }
    RelObj_2b6eb0* c = m_c;
    if (c != 0) {
        c->Release();
        m_c = 0;
    }
    BaseCleanup_002a50a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002b6eb0


// 0x002b6f10 pure3d::ShadowSkinImpl::vfunc_2 (30 B): matches/0x002b6f10.cpp
// sym: ??_GShadowSkinImpl@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ShadowSkinImpl::~ShadowSkinImpl() {}


// 0x002b6f30 pure3d::ShadowSkinImpl::vfunc_6 (60 B): matches/0x002b6f30.cpp
// sym: ?vfunc_6@ShadowSkinImpl@pure3d@@UAEXXZ
void pure3d::ShadowSkinImpl::vfunc_6() {
    if (!(*(Ref_2b6f30 * *)&this->f_7c)) {
        Ref_2b6f30* r = (*(Provider_2b6f30 * *)&this->f_70)->getObj_0027b240();
        if (r)
            r->f0();
        if ((*(Ref_2b6f30 * *)&this->f_7c))
            (*(Ref_2b6f30 * *)&this->f_7c)->f1();
        (*(Ref_2b6f30 * *)&this->f_7c) = r;
    }
    ((ShadowSkinImpl_nv_2b6f30*)this)->helper_002b57d0((*(Ref_2b6f30 * *)&this->f_7c));
}


// 0x002b6f70 pure3d::ShadowMeshLoader::vfunc_2 (31 B): matches/0x002b6f70.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002b6f70@@UAEPAV123@E@Z
namespace fn_002b6f70 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2b6f70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2b6f70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002b6f70


// 0x002b6f90 pure3d::ShadowSkinLoader::vfunc_2 (31 B): matches/0x002b6f90.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002b6f90@@UAEPAV123@E@Z
namespace fn_002b6f90 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2b6f90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2b6f90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002b6f90

namespace fn_f35954a7 {

// 0x002b6fb0 pure3d::ShadowMeshBufferImpl::vfunc_2 (57 B): matches/0x002b6fb0.cpp
// sym: ?f2@ShadowMeshBufferImpl_2b6fb0@fn_f35954a7@@QAEPAV12@E@Z
ShadowMeshBufferImpl_2b6fb0* ShadowMeshBufferImpl_2b6fb0::f2(unsigned char flags) {
    vptr = g_vftable_2b6fb0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a50a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f35954a7

// 0x002b6ff0 pure3d::ShadowMeshBufferLoader::vfunc_2 (45 B): matches/0x002b6ff0.cpp [wrapped: conflict: ShadowMeshBufferLoader]
// sym: ?f2@ShadowMeshBufferLoader@fn_002b6ff0@@QAEPAU12@E@Z
namespace fn_002b6ff0 {
extern void* shadowVftable;
extern void* refVftable;
struct Interface_2b6ff0 {
    virtual void a();
    virtual void b();
};
struct ShadowMeshBufferLoader {
    void* vptr;
    char pad[0x10];
    Interface_2b6ff0* member;
    ShadowMeshBufferLoader* f2(unsigned char);
};
extern void cleanup_00263f30(ShadowMeshBufferLoader*);
ShadowMeshBufferLoader* ShadowMeshBufferLoader::f2(unsigned char flag) {
    vptr = &shadowVftable;
    member->b();
    vptr = &refVftable;
    if (flag & 1)
        cleanup_00263f30(this);
    return this;
}
} // namespace fn_002b6ff0


// 0x002b7020 pure3d::ShadowSkinLoader::vfunc_5 (2176 B): equivalent/0x002b7020.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?v5@ShadowSkinLoader@pure3d@fn_002b7020@@UAE_KPAPAVTarget_2b7020@3@PA_KPAVReader@3@PAVInv_2b7020@3@@Z @262da5fdcb19 @wd073e599e50e
inline void *operator new(size_t, void *p) { return p; }
namespace fn_002b7020 {
// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 99/99)
// pure3d::ShadowSkinLoader::vfunc_5 @ 0x002b7020
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



class Ref_2b7020 {
public:
    virtual void AddRef();
    virtual void Release();
};

namespace content {
class ObjectLoader : public Ref_2b7020 {
public:
    virtual void o2();
    virtual void o3();
    virtual void o4();
};
namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void cast(); };
}
}

void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d6d0(unsigned int size);
extern "C" void *__cdecl FUN_00266e00(int a, int b);
extern "C" void __cdecl FUN_00267090(void *a);

struct Mat_2b7020 {
    float m[16];
    void FUN_0022b980();
    void FUN_00011550();
};
void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Mat_2b7020::*ctor)());

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

namespace pure3d { class Skeleton; }

class Inv_2b7020 {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void *i3(void *caster, unsigned __int64 key);
};

struct NameHolder_2b7020 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

class SkelObj {
public:
    virtual void AddRef();
    virtual void Release();
    Ref_2b7020 *FUN_0027b240();
};

class ShadowMeshVertices_2b7020 : public Ref_2b7020 {
public:
    ShadowMeshVertices_2b7020 *FUN_002b5070(int a, hulk_intptr b);
};

struct Rec0_2b7020 {
    unsigned int x, y, z;
    unsigned short idx;
    unsigned char c0;
    unsigned char pad0f;
    unsigned int pad10;
};
struct Rec1_2b7020 {
    unsigned int x, y, z;
    unsigned short idx;
    unsigned short pad0e;
    unsigned int d10, d14;
    unsigned char c0, c1;
    unsigned short pad1a;
};
struct Rec2_2b7020 {
    unsigned int x, y, z;
    unsigned short idx;
    unsigned short pad0e;
    unsigned int d10, d14, d18;
    unsigned char c0, c1, c2, c3;
};
struct Vertex_2b7020 {
    unsigned int x, y, z;
    unsigned int pad0c;
    unsigned int w0, w1, w2;
    unsigned char c[4];
};

namespace pure3d {

class ShadowMeshTopology : public Ref_2b7020 {
public:
    int pad04;
    int nVerts;
    int nFaces;
    unsigned char *tris;
    unsigned char *flags;
    ShadowMeshTopology(int v, int f)
    {
        pad04 = 0;
        tris = 0;
        flags = 0;
        nVerts = v;
        nFaces = f;
        tris = (unsigned char *)FUN_0008d6d0(f * 12);
        flags = (unsigned char *)FUN_0008d6d0(nFaces);
    }
};

class ShadowSkinTopology : public Ref_2b7020 {
public:
    int pad04;
    Rec0_2b7020 *r0;
    Rec1_2b7020 *r1;
    Rec2_2b7020 *r2;
    int n0;
    int n1;
    int n2;
    ShadowSkinTopology(int a, int b, int c)
    {
        pad04 = 0;
        r0 = 0;
        r1 = 0;
        r2 = 0;
        n0 = a;
        n1 = b;
        n2 = c;
        r0 = (Rec0_2b7020 *)FUN_0008d6d0(a * 20);
        r1 = (Rec1_2b7020 *)FUN_0008d6d0(n1 * 0x1c);
        r2 = (Rec2_2b7020 *)FUN_0008d6d0(n2 << 5);
    }
};

}

struct SkelRef {
    char pad00[0xc];
    int count;
};

class Mesh_2b7020 {
public:
    char pad00[0x14];
    float v14[6];
    float v2c[3];
    int f38;
    char pad3c[0x44 - 0x3c];
    Ref_2b7020 *topo;
    Ref_2b7020 *skinTopo;
    char pad4c[0x70 - 0x4c];
    SkelObj *skel;
    Mat_2b7020 *mats;
    Ref_2b7020 *skinTopo2;
    SkelRef *f7c;
};

struct MeshHolder { Mesh_2b7020 *mesh; };

struct Copy24 { unsigned int a[6]; };
struct Copy16 { unsigned int a[4]; };

class Target_2b7020 {
public:
    char pad00[8];
    char pad08[0x14 - 0x8];
    Copy24 c14;
    Copy16 c2c;
    char pad3c[0x48 - 0x3c];
    MeshHolder *holder;
};

namespace pure3d {
class ShadowSkinLoader : public content::ObjectLoader {
public:
    virtual unsigned __int64 v5(Target_2b7020 **objOut, unsigned __int64 *hashOut, Reader *R, Inv_2b7020 *inv);
    virtual Target_2b7020 *v6();
};
}

struct Frame_2b7020 {
    char pad0[3];
    unsigned char len;      // 0x03
    hulk_intptr nf;                 // 0x04 (read, then reused for topo)
    hulk_intptr A;                  // 0x08
    hulk_intptr vbuf;               // 0x0c
    int nv;                 // 0x10
    int c14;                // 0x14 (caster slot / count for chunk 24)
    char pad18[0x30 - 0x18];
    hulk_intptr x30;                // 0x30 (read, then reused for obj)
    int cnt9;               // 0x34
    int cnt2;               // 0x38
    int cnt8;               // 0x3c
    int tmp1;               // 0x40
    int tmp8;               // 0x44
    char name1[0x100];      // 0x48
    char name2[0x100];      // 0x148
};

static bool Zero(unsigned int *p)
{
    return *(float *)p == 0.0f;
}

unsigned __int64 pure3d::ShadowSkinLoader::v5(Target_2b7020 **objOut, unsigned __int64 *hashOut, Reader *R, Inv_2b7020 *inv)
{
    Frame_2b7020 f;
    unsigned int n;

    R->stream->FUN_002647e0(&f.len, 1, 1, 1);
    n = f.len;
    R->stream->FUN_002647e0(f.name1, n, 1, 1);
    f.name1[n] = 0;
    R->stream->FUN_002647e0(&f.x30, 1, 4, 1);
    R->stream->FUN_002647e0(&f.len, 1, 1, 1);
    n = f.len;
    R->stream->FUN_002647e0(f.name2, n, 1, 1);
    f.name2[n] = 0;
    R->stream->FUN_002647e0(&f.nv, 1, 4, 1);
    R->stream->FUN_002647e0(&f.nf, 1, 4, 1);

    int nvv = f.nv;
    hulk_intptr nfv = f.nf;
    Target_2b7020 *obj = v6();
    f.x30 = (hulk_intptr)obj;
    ((NameHolder_2b7020 *)((char *)obj + 8))->FUN_0027b040(f.name1);
    Mesh_2b7020 *A = obj->holder->mesh;
    f.A = (hulk_intptr)A;

    void *m1 = FUN_0008d690((int)sizeof(pure3d::ShadowMeshTopology));
    pure3d::ShadowMeshTopology *topo;
    if (m1)
        topo = new (m1) pure3d::ShadowMeshTopology(nvv, nfv);
    else
        topo = 0;
    f.nf = (hulk_intptr)topo;
    if (topo)
        topo->AddRef();
    if (A->topo)
        A->topo->Release();
    A->topo = topo;

    void *m2 = FUN_0008d690(0x18);
    ShadowMeshVertices_2b7020 *st;
    if (m2)
        st = ((ShadowMeshVertices_2b7020 *)m2)->FUN_002b5070(nvv, nfv);
    else
        st = 0;
    if (st)
        st->AddRef();
    if (A->skinTopo)
        A->skinTopo->Release();
    A->skinTopo = st;

    unsigned char *vbuf = (unsigned char *)FUN_00266e00(1, nvv << 5);
    f.vbuf = (hulk_intptr)vbuf;
    unsigned __int64 key = FUN_0027b020(f.name2);
    SkelObj *sk = (SkelObj *)inv->i3(new (&f.c14) content::LoadInventory::DynamicCaster<pure3d::Skeleton>, key);
    A->skel = sk;
    if (sk) {
        sk->AddRef();
        Ref_2b7020 *r = A->skel->FUN_0027b240();
        A->f7c = (SkelRef *)r;
        r->AddRef();
        int cnt = A->f7c->count + 1;
        void *mem = FUN_0008d6d0(cnt << 6);
        Mat_2b7020 *mats;
        if (mem) {
            FUN_00011520(mem, 0x40, cnt, &Mat_2b7020::FUN_00011550);
            mats = (Mat_2b7020 *)mem;
        } else {
            mats = 0;
        }
        A->mats = mats;
        (mats + A->f7c->count)->FUN_0022b980();
    }

    if (R->FUN_002669f0()) {
        do {
            R->FUN_00266a30();
            int id = R->FUN_00266c30() - 0x10003;
            if (id == 24) {
                R->stream->FUN_002647e0(&f.c14, 1, 4, 1);
                for (unsigned int i = 0; i < (unsigned int)f.c14; i++)
                    R->stream->FUN_002647e0(topo->tris + i * 12, 6, 2, 1);
            } else if (id == 2) {
                R->stream->FUN_002647e0(&f.cnt2, 1, 4, 1);
                unsigned char *p = vbuf;
                for (unsigned int i = 0; i < (unsigned int)f.cnt2; i++) {
                    R->stream->FUN_002647e0(p, 3, 4, 1);
                    p += 0x20;
                }
            } else if (id == 9) {
                R->stream->FUN_002647e0(&f.cnt9, 1, 4, 1);
                unsigned char *p = vbuf + 0x10;
                for (unsigned int i = 0; i < (unsigned int)f.cnt9; i++) {
                    R->stream->FUN_002647e0(p, 3, 4, 1);
                    p += 0x20;
                }
            } else if (id == 8) {
                R->stream->FUN_002647e0(&f.cnt8, 1, 4, 1);
                unsigned char *p = vbuf + 0x1d;
                for (unsigned int i = 0; i < (unsigned int)f.cnt8; i++) {
                    R->stream->FUN_002647e0(&f.tmp8, 1, 4, 1);
                    unsigned int tmp = f.tmp8;
                    p[-1] = (unsigned char)(tmp >> 24);
                    p[0] = (unsigned char)(tmp >> 16);
                    p[1] = (unsigned char)(tmp >> 8);
                    p[2] = (unsigned char)tmp;
                    p += 0x20;
                }
            } else if (id == 1) {
                R->stream->FUN_002647e0(A->v2c, 3, 4, 1);
                R->stream->FUN_002647e0(&f.tmp1, 1, 4, 1);
                A->f38 = f.tmp1;
            } else if (id == 0) {
                R->stream->FUN_002647e0(A->v14, 3, 4, 1);
                R->stream->FUN_002647e0(&A->v14[3], 3, 4, 1);
            }
            R->FUN_00266be0();
        } while (R->FUN_002669f0());
    }

    int n0 = 0, n1 = 0, n2 = 0;
    Vertex_2b7020 *vtx = (Vertex_2b7020 *)vbuf;
    for (int i = 0; i < nvv; i++) {
        if (Zero(&vtx[i].w2) && Zero(&vtx[i].w1))
            n0++;
        else if (Zero(&vtx[i].w2))
            n1++;
        else
            n2++;
    }

    void *m3 = FUN_0008d690((int)sizeof(pure3d::ShadowSkinTopology));
    pure3d::ShadowSkinTopology *stop;
    if (m3)
        stop = new (m3) pure3d::ShadowSkinTopology(n0, n1, n2);
    else
        stop = 0;
    if (stop)
        stop->AddRef();
    if (A->skinTopo2)
        A->skinTopo2->Release();
    A->skinTopo2 = stop;

    int o0 = 0, o1 = 0, o2 = 0;
    for (unsigned int i = 0; i < (unsigned int)nvv; i++) {
        Vertex_2b7020 *v = &vtx[i];
        if (Zero(&v->w2) && Zero(&v->w1)) {
            Rec0_2b7020 *r = (Rec0_2b7020 *)((char *)stop->r0 + o0);
            r->x = v->x;
            r->y = v->y;
            r->z = v->z;
            r->idx = (unsigned short)i;
            r->c0 = v->c[0];
            o0 += 0x14;
        } else if (Zero(&v->w2)) {
            Rec1_2b7020 *r = (Rec1_2b7020 *)((char *)stop->r1 + o1);
            r->x = v->x;
            r->y = v->y;
            r->z = v->z;
            r->idx = (unsigned short)i;
            r->c0 = v->c[0];
            r->c1 = v->c[1];
            r->d10 = v->w0;
            r->d14 = v->w1;
            o1 += 0x1c;
        } else {
            Rec2_2b7020 *r = (Rec2_2b7020 *)((char *)stop->r2 + o2);
            r->x = v->x;
            r->y = v->y;
            r->z = v->z;
            r->idx = (unsigned short)i;
            r->c0 = v->c[0];
            r->c1 = v->c[1];
            r->c2 = v->c[2];
            r->d10 = v->w0;
            r->d14 = v->w1;
            r->d18 = v->w2;
            o2 += 0x20;
        }
    }
    FUN_00267090(vbuf);
    // the original loads each block into temporaries before storing it (obj may alias the mesh)
    Copy24 t24 = *(Copy24 *)&A->v14[0];
    obj->c14 = t24;
    Copy16 t16 = *(Copy16 *)&A->v2c[0];
    obj->c2c = t16;
    *objOut = obj;
    return *hashOut = FUN_002672f0(f.name1, 0, 0);
}
} // namespace fn_002b7020
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

