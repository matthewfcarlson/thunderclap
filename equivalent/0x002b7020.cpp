// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 99/99)
// pure3d::ShadowSkinLoader::vfunc_5 @ 0x002b7020
#include "compat/ptr.h"
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) { return p; }

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
void *__cdecl FUN_00266e00(int a, int b);
void __cdecl FUN_00267090(void *a);

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

    void *m1 = FUN_0008d690(0x18);
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

    void *m3 = FUN_0008d690(0x20);
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
