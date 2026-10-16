// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 46/46)
// FUN_002c7690 @ 0x002c7690
struct V3 {
    float x, y, z;
};

struct V3i {
    int x, y, z;
};

struct UV {
    float u, v;
};

struct UVi {
    int u, v;
};

struct VertexSink {
    char pad0[8];
    V3 *pos;                // 0x08
    V3 *normal;             // 0x0c
    int *color;             // 0x10
    UV *tex;                // 0x14
    void FUN_0008ef00();
    void FUN_000c7940(V3 *p, int c, UV *t);
};

struct Mesh {
    char pad0[8];
    unsigned int flags;     // 0x08
    char pad0c[4];
    unsigned int count;     // 0x10
    unsigned short *index;  // 0x14
    V3 *posA;               // 0x18
    V3 *nrmA;               // 0x1c
    V3 *posB;               // 0x20
    V3 *nrmB;               // 0x24
    char pad28[0x38 - 0x28];
    UV *uv0;                // 0x38
    UV *uv1;                // 0x3c
    UV *uv2;                // 0x40
    UV *uv3;                // 0x44
    int *color0;            // 0x48
    int *color1;            // 0x4c
};

// Emit every indexed vertex of a mesh; the mesh arrives in eax, the sink in esi.
// equiv-conv: FUN_002c7690 eax esi stack
void FUN_002c7690(Mesh *m, VertexSink *out, char useB)
{
    unsigned int count = m->count;
    unsigned short *index = m->index;
    V3 *pos;
    V3 *nrm;
    if (useB == 1) {
        pos = m->posB;
        nrm = m->nrmB;
    } else {
        pos = m->posA;
        nrm = m->nrmA;
    }
    int *color0 = m->color0;
    int *color1 = m->color1;
    UV *uv0 = m->uv0;
    UV *uv1 = m->uv1;
    UV *uv2 = m->uv2;
    UV *uv3 = m->uv3;
    unsigned int sel = (m->flags & 0xfffc7fff) - 0x2001;
    unsigned int i;

    if (sel == 0x1f) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            int c = color0[v];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *out->color = c;
            out->FUN_0008ef00();
        }
        return;
    }
    if (sel == 0xf) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *(V3i *)out->normal = *(V3i *)&nrm[v];
            out->FUN_0008ef00();
        }
        return;
    }
    if (sel == 0) {
        if (count != 0) {
            unsigned int v = index[0];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *(UVi *)out->tex = *(UVi *)&uv0[v];
            out->FUN_0008ef00();
        }
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            out->FUN_000c7940(&pos[v], color0[v], &uv0[v]);
        }
        return;
    }
    if (sel == 0x20) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            out->FUN_000c7940(&pos[v], color0[v], &uv0[v]);
        }
        return;
    }
    if (sel == 0x10) {
        for (i = 0; i < count; i++) {
            unsigned int v = index[i];
            *(V3i *)out->pos = *(V3i *)&pos[v];
            *(V3i *)out->normal = *(V3i *)&nrm[v];
            *(UVi *)out->tex = *(UVi *)&uv0[v];
            out->FUN_0008ef00();
        }
        return;
    }
    // Generic path. index[i] is re-read for every attribute: the sink's arrays may
    // overlap the index array, and the original reloads it after each store.
    for (i = 0; i < count; i++) {
        if (nrm != 0) {
            V3 *s = &nrm[index[i]];
            float z = s->z;
            float y = s->y;
            *(int *)&out->normal->x = *(int *)&s->x;
            out->normal->y = y;
            out->normal->z = z;
        }
        if (color0 != 0)
            out->color[0] = color0[index[i]];
        if (color1 != 0)
            out->color[1] = color1[index[i]];
        if (uv0 != 0) {
            UV *s = &uv0[index[i]];
            float t = s->v;
            *(int *)&out->tex[0].u = *(int *)&s->u;
            out->tex[0].v = t;
        }
        if (uv1 != 0) {
            UV *s = &uv1[index[i]];
            float t = s->v;
            *(int *)&out->tex[1].u = *(int *)&s->u;
            out->tex[1].v = t;
        }
        if (uv2 != 0) {
            UV *s = &uv2[index[i]];
            float t = s->v;
            *(int *)&out->tex[2].u = *(int *)&s->u;
            out->tex[2].v = t;
        }
        if (uv3 != 0) {
            UV *s = &uv3[index[i]];
            float t = s->v;
            *(int *)&out->tex[3].u = *(int *)&s->u;
            out->tex[3].v = t;
        }
        {
            V3 *s = &pos[index[i]];
            float z = s->z;
            float y = s->y;
            *(int *)&out->pos->x = *(int *)&s->x;
            out->pos->y = y;
            out->pos->z = z;
        }
        out->FUN_0008ef00();
    }
}
