// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 46/46)
// FUN_002c7e40 @ 0x002c7e40
struct V3 {
    float x, y, z;
};

struct V2 {
    int a;
    int b;
};

class Renderer {
public:
    virtual void vfunc_0(V3 v);
    virtual void vfunc_1(V3 v);
    virtual void vfunc_2(V3 v);
    virtual void vfunc_3(V3 v);
    virtual void vfunc_4(unsigned int color, int channel);
    virtual void vfunc_5();
    virtual void vfunc_6(V2 v, int channel);
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(V3 *a, V3 *b, V2 *c);
    virtual void vfunc_13(V3 *a, unsigned int color, V2 *c);
    virtual void vfunc_14(V3 *a, V2 *c);
    virtual void vfunc_15(V3 *a, V3 *b);
    virtual void vfunc_16(V3 *a, unsigned int color);
};

struct Batch {
    char pad0[8];
    unsigned int flags;         // 0x8
    char padc[4];
    unsigned int count;         // 0x10
    unsigned short *indices;    // 0x14
    V3 *pos0;                   // 0x18
    V3 *pos1;                   // 0x1c
    V3 *pos0b;                  // 0x20
    V3 *pos1b;                  // 0x24
    V3 *pos2;                   // 0x28
    V3 *pos2b;                  // 0x2c
    V3 *extra;                  // 0x30
    V3 *extraB;                 // 0x34
    V2 *uv0;                    // 0x38
    V2 *uv1;                    // 0x3c
    V2 *uv2;                    // 0x40
    V2 *uv3;                    // 0x44
    unsigned int *col0;         // 0x48
    unsigned int *col1;         // 0x4c
};

// batch arrives in eax, mode in cl, renderer in esi.
// equiv-conv: FUN_002c7e40 eax ecx esi
void FUN_002c7e40(Batch *s, char mode, Renderer *r)
{
    unsigned int n = s->count;
    unsigned short *idx = s->indices;
    V3 *p0;
    V3 *p1;
    V3 *p2;
    V3 *q;
    unsigned int *colors[2];
    V2 *uvs[4];
    unsigned int i;

    if (mode == 1) {
        p0 = s->pos0b;
        p2 = s->pos2b;
        p1 = s->pos1b;
        q = s->extraB;
    } else {
        p0 = s->pos0;
        p1 = s->pos1;
        p2 = s->pos2;
        q = s->extra;
    }
    colors[0] = s->col0;
    colors[1] = s->col1;
    uvs[0] = s->uv0;
    uvs[1] = s->uv1;
    uvs[2] = s->uv2;
    uvs[3] = s->uv3;

    switch (s->flags & 0xfffc7fff) {
    case 0x2020:
        for (i = 0; i < n; i++)
            r->vfunc_16(&p0[idx[i]], colors[0][idx[i]]);
        return;
    case 0x2010:
        for (i = 0; i < n; i++)
            r->vfunc_15(&p0[idx[i]], &p1[idx[i]]);
        return;
    case 0x2001:
        if (n > 0)
            r->vfunc_14(&p0[idx[0]], &uvs[0][idx[0]]);
        for (i = 0; i < n; i++)
            r->vfunc_13(&p0[idx[i]], colors[0][idx[i]], &uvs[0][idx[i]]);
        return;
    case 0x2021:
        for (i = 0; i < n; i++)
            r->vfunc_13(&p0[idx[i]], colors[0][idx[i]], &uvs[0][idx[i]]);
        return;
    case 0x2011:
        for (i = 0; i < n; i++)
            r->vfunc_12(&p0[idx[i]], &p1[idx[i]], &uvs[0][idx[i]]);
        return;
    default:
        for (i = 0; i < n; i++) {
            if (p1)
                r->vfunc_1(p1[idx[i]]);
            if (p2)
                r->vfunc_2(p2[idx[i]]);
            if (q)
                r->vfunc_3(q[idx[i]]);
            for (unsigned int j = 0; j < 2; j++) {
                if (colors[j])
                    r->vfunc_4(colors[j][idx[i]], j);
            }
            for (unsigned int j = 0; j < 4; j++) {
                if (uvs[j])
                    r->vfunc_6(uvs[j][idx[i]], j);
            }
            r->vfunc_0(p0[idx[i]]);
        }
        return;
    }
}
