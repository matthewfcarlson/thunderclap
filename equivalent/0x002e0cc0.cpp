// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 38/38)
// FUN_002e0cc0 @ 0x002e0cc0
#include "compat/ptr.h"
struct V3_2e0cc0 {
    int x, y, z;
};

struct VtxRec {
    int idx;
    V3_2e0cc0 v;
};

struct UvRec {
    int idx;
    int a, b;
};

struct Pair8 {
    int a, b;
};

struct Entry8 {
    int a, b;
    void FUN_002c6d60(int *src);
};

struct VtxVec {
    VtxRec *begin;
    VtxRec *end;
    VtxRec *cap;
};

struct UvVec {
    UvRec *begin;
    UvRec *end;
    UvRec *cap;
};

struct Src_2e0cc0 {
    char pad0[0x14];
    VtxRec *vbegin;        // 0x14
    VtxRec *vend;          // 0x18
    char pad1c[4];
    VtxRec *nbegin;        // 0x20
    VtxRec *nend;          // 0x24
    char pad28[4];
    UvVec uv[4];           // 0x2c
    UvVec ext[2];          // 0x5c
};

struct Mesh_2e0cc0 {
    char pad0[0x10];
    V3_2e0cc0 *f10;
    V3_2e0cc0 *f14;
    Pair8 *uv[4];          // 0x18
    Entry8 *ext[2];        // 0x28
    void FUN_002c7070();
};

class Model_2e0cc0 {
public:
    char pad0[0x5c];
    Mesh_2e0cc0 *mesh;            // 0x5c
    void FUN_002e0cc0(Src_2e0cc0 *src, char flag);
};

void Model_2e0cc0::FUN_002e0cc0(Src_2e0cc0 *src, char flag)
{
    if (flag == 1)
        mesh->FUN_002c7070();
    unsigned int i;
    if (mesh->f10 != 0) {
        hulk_uintptr n = src->vend - src->vbegin;
        for (i = 0; i < n; i++) {
            VtxRec *e = &src->vbegin[i];
            int idx = e->idx;
            V3_2e0cc0 *d = &mesh->f10[idx];
            d->x = e->v.x;
            d->y = e->v.y;
            d->z = e->v.z;
        }
    }
    if (mesh->f14 != 0) {
        hulk_uintptr n = src->nend - src->nbegin;
        for (i = 0; i < n; i++) {
            VtxRec *e = &src->nbegin[i];
            int idx = e->idx;
            V3_2e0cc0 *d = &mesh->f14[idx];
            d->x = e->v.x;
            d->y = e->v.y;
            d->z = e->v.z;
        }
    }
    int k;
    for (k = 0; k < 4; k++) {
        if (mesh->uv[k] != 0) {
            hulk_intptr n = src->uv[k].end - src->uv[k].begin;
            for (int j = 0; j < n; j++) {
                UvRec *e = &src->uv[k].begin[j];
                Pair8 *base = mesh->uv[k];
                int a = e->a;
                int idx = e->idx;
                base[idx].a = a;
                base[idx].b = e->b;
            }
        }
    }
    for (k = 0; k < 2; k++) {
        if (mesh->ext[k] != 0) {
            hulk_intptr n = src->ext[k].end - src->ext[k].begin;
            for (int j = 0; j < n; j++) {
                UvRec *e = &src->ext[k].begin[j];
                mesh->ext[k][e->idx].FUN_002c6d60(&e->a);
            }
        }
    }
}
