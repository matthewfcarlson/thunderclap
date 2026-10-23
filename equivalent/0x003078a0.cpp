// STATUS: equivalent (tools/equiv.py level 3: 16463 inputs, branch coverage 56/56)
// FUN_003078a0 @ 0x003078a0
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/physics.h"

extern "C" void __fastcall FUN_002fa720(void *p);
extern "C" void __fastcall FUN_00011090(void *p);
extern "C" void __fastcall FUN_000115b0(void *p);
void __stdcall FUN_00011520(void *p, unsigned int size, int count, void(__fastcall *ctor)(void *));

void *__cdecl FUN_0008d6d0(unsigned int size);
void *FUN_0008d690(unsigned int size);

struct Reader_3078a0 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream_3078a0 {
    char pad0[0x284];
    Reader_3078a0 *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Face_3078a0 {
    int v[3];
    unsigned char c[4];
    unsigned short a;
    unsigned short b;
    unsigned short d;
    unsigned short e;
};

struct Geom_3078a0 {
    char pad00[8];
    float *verts;
    float *f0c;
    unsigned char *f10;
    unsigned short *indices;
    Face_3078a0 *faces;
    unsigned short n1c;
    char pad1e[2];
    unsigned short n20;
    char pad22[2];
    float lo[3];
    float hi[3];
    float inv[3];
};

struct CollisionMesh_nv_3078a0 {
    physics::CollisionMesh *FUN_002f3530();
};

typedef void(__cdecl *Hook_3078a0)(Stream_3078a0 *s, physics::CollisionMesh *m);

union Slot_3078a0 {
    Stream_3078a0 *s;
    unsigned int u;
    unsigned short w;
};

struct Frame_3078a0 {
    unsigned int s10;
    unsigned int s14;
    unsigned int s18;
    unsigned int i1c;
    Geom_3078a0 *saved20;
    unsigned int n24;
    hulk_uintptr x28;
    unsigned int n2c;
    unsigned int n30;
    unsigned int t34;
    unsigned int t38;
    unsigned int t3c;
    unsigned int v40;
    unsigned int sz44;
    unsigned int v48;
    float f4c;
    unsigned int v50;
    unsigned int v54;
    unsigned int v58;
    unsigned int s5c;
    float dy;
    float dz;
};

physics::CollisionMesh *FUN_003078a0(Slot_3078a0 a1)
{
    Frame_3078a0 f;
    Stream_3078a0 *stream = a1.s;
    stream->reader->FUN_002647e0(&a1.u, 1, 4, 1);
    void *mem = FUN_0008d690(0xd4);
    physics::CollisionMesh *mesh = 0;
    if (mem != 0)
        mesh = ((CollisionMesh_nv_3078a0*)(((physics::CollisionMesh*)(((physics::CollisionMesh *)mem)))))->FUN_002f3530();
    Geom_3078a0 *g = (*(Geom_3078a0 * *)&mesh->f_44);
    f.saved20 = g;
    stream->reader->FUN_002647e0(&a1.u, 1, 4, 1);
    stream->reader->FUN_002647e0(&a1.u, 1, 4, 1);
    stream->reader->FUN_002647e0(g->lo, 3, 4, 1);
    stream->reader->FUN_002647e0(g->hi, 3, 4, 1);
    float dx = g->hi[0] - g->lo[0];
    f.dy = g->hi[1] - g->lo[1];
    f.dz = g->hi[2] - g->lo[2];
    *(float *)&a1.u = dx;
    a1.u &= 0x7fffffff;
    g->inv[0] = (*(float *)&a1.u >= 1e-5f) ? 65535.0f / dx : 0.0f;
    *(float *)&a1.u = f.dy;
    a1.u &= 0x7fffffff;
    g->inv[1] = (*(float *)&a1.u >= 1e-5f) ? 65535.0f / f.dy : 0.0f;
    *(float *)&a1.u = f.dz;
    a1.u &= 0x7fffffff;
    g->inv[2] = (*(float *)&a1.u >= 1e-5f) ? 65535.0f / f.dz : 0.0f;

    while (stream->FUN_002669f0()) {
        unsigned int id = stream->FUN_00266a30();
        if (id == 0x7000008) {
            stream->reader->FUN_002647e0(&f.t34, 1, 4, 1);
            unsigned int n = f.t34;
            unsigned short *p = (unsigned short *)FUN_0008d6d0(n * 2);
            g->indices = p;
            stream->reader->FUN_002647e0(p, n, 2, 1);
        } else if (id == 0x7000006) {
            stream->reader->FUN_002647e0(&f.t38, 1, 4, 1);
            unsigned int n = (unsigned short)(__int64)f.t38;
            g->n20 = (unsigned short)(__int64)f.t38;
            unsigned int *raw = (unsigned int *)FUN_0008d6d0(n * 24 + 4);
            Face_3078a0 *arr;
            if (raw != 0) {
                raw[0] = n;
                arr = (Face_3078a0 *)(raw + 1);
                f.x28 = (hulk_uintptr)arr;
                FUN_00011520(arr, 0x18, n, FUN_002fa720);
                arr = (Face_3078a0 *)f.x28;
            } else {
                arr = 0;
            }
            unsigned int i = 0;
            g->faces = arr;
            if (g->n20 != 0) {
                do {
                    Face_3078a0 *e = (*(Geom_3078a0 * *)&mesh->f_44)->faces + i;
                    stream->reader->FUN_002647e0(&a1.u, 1, 2, 1);
                    e->a = a1.w;
                    stream->reader->FUN_002647e0(&f.s10, 1, 2, 1);
                    e->b = (unsigned short)(__int64)f.s10;
                    stream->reader->FUN_002647e0(&f.s14, 1, 2, 1);
                    e->d = (unsigned short)(__int64)f.s14;
                    stream->reader->FUN_002647e0(&f.s18, 1, 2, 1);
                    unsigned int v = (unsigned short)(__int64)f.s18;
                    e->e = (unsigned short)(__int64)((((((((v >> 4) & 0xfff) << 1) | ((v >> 2) & 1)) << 1) | ((v >> 1) & 1)) << 1) | (v & 1));
                    i++;
                } while (i < f.saved20->n20);
            }
            g = f.saved20;
        } else if (id == 0x7000003) {
            stream->reader->FUN_002647e0(&f.t3c, 1, 4, 1);
            unsigned int n = (unsigned short)(__int64)f.t3c;
            g->n1c = (unsigned short)(__int64)f.t3c;
            float *raw = (float *)FUN_0008d6d0(n * 12);
            f.x28 = (hulk_uintptr)raw;
            float *r;
            if (raw != 0) {
                FUN_00011520(raw, 0xc, n, FUN_00011090);
                r = (float *)f.x28;
            } else {
                r = 0;
            }
            g->verts = r;
            stream->reader->FUN_002647e0(r, g->n1c * 3, 4, 1);
        } else if (id == 0x7000747) {
            stream->reader->FUN_002647e0(&f.n2c, 1, 4, 1);
            f.i1c = 0;
            if (f.n2c != 0) {
                do {
                    unsigned int off = (unsigned int)(__int64)(unsigned short)(__int64)f.i1c * 24;
                    unsigned int k = 0;
                    f.x28 = off;
                    do {
                        stream->reader->FUN_002647e0(&f.v40, 1, 4, 1);
                        *(unsigned int *)((char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces + f.x28) = f.v40;
                        ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + k + 0xc] = 0xff;
                        k++;
                        f.x28 += 4;
                    } while ((int)(__int64)k < 3);
                    ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + 0xf] = 0;
                    f.i1c++;
                } while (f.i1c < f.n2c);
            }
            g = f.saved20;
        } else if (id == 0x7000748) {
            stream->reader->FUN_002647e0(&f.n30, 1, 4, 1);
            f.i1c = 0;
            if (f.n30 != 0) {
                do {
                    unsigned int off = (unsigned int)(__int64)(unsigned short)(__int64)f.i1c * 24;
                    unsigned int pos = off;
                    f.x28 = 3;
                    do {
                        stream->reader->FUN_002647e0(&f.v48, 1, 4, 1);
                        *(unsigned int *)((char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces + pos) = f.v48;
                        pos += 4;
                    } while (--f.x28 != 0);
                    int k = 0;
                    do {
                        stream->reader->FUN_002647e0(&f.f4c, 1, 4, 1);
                        unsigned int q = (unsigned int)(__int64)(int)(__int64)(f.f4c * 32.0f);
                        if (q >= 0x100)
                            q = 0xff;
                        ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + k + 0xc] = (unsigned char)(__int64)q;
                        k++;
                    } while (k < 3);
                    stream->reader->FUN_002647e0(&f.v54, 1, 4, 1);
                    stream->reader->FUN_002647e0(&f.v50, 1, 4, 1);
                    ((unsigned char *)(*(Geom_3078a0 * *)&mesh->f_44)->faces)[off + 0xf] = (unsigned char)(__int64)(int)(__int64)((1.0f - *(float *)&f.v50) * 255.0f);
                    stream->reader->FUN_002647e0(&f.v58, 1, 4, 1);
                    f.i1c++;
                } while (f.i1c < f.n30);
            }
            g = f.saved20;
        } else if (id == 0x7000800) {
            stream->reader->FUN_002647e0(&f.n24, 1, 4, 1);
            unsigned int n = f.n24;
            float *p = (float *)FUN_0008d6d0(n * 4);
            float *arr;
            if (p != 0) {
                FUN_00011520(p, 4, f.n24, FUN_000115b0);
                arr = p;
            } else {
                arr = 0;
            }
            g->f0c = arr;
            stream->reader->FUN_002647e0(arr, f.n24, 4, 1);
            stream->reader->FUN_002647e0(&f.sz44, 1, 4, 1);
            unsigned int sz = f.sz44;
            unsigned char *q = (unsigned char *)FUN_0008d6d0(sz);
            g->f10 = q;
            stream->reader->FUN_002647e0(q, sz, 1, 1);
        } else if (id == 0x7016000) {
            Hook_3078a0 h = (*(Hook_3078a0*)&DAT_00555444);
            if (h != 0)
                h(stream, mesh);
        }
        stream->FUN_00266be0();
    }
    return mesh;
}
