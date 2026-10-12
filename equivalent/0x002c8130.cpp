// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 46/46)
// FUN_002c8130 @ 0x002c8130
struct Dev {
    virtual void v0(int a, int b, int c);
    virtual void v1(int a, int b, int c);
    virtual void v2(int a, int b, int c);
    virtual void v3(int a, int b, int c);
    virtual void v4(int a, int k);
    virtual void v5();
    virtual void v6(int a, int b, int k);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(const int *a, const int *b, const int *c);
    virtual void v13(const int *a, int b, const int *c);
    virtual void v14(const int *a, const int *b);
    virtual void v15(const int *a, const int *b);
    virtual void v16(const int *a, int b);
};

struct Desc {
    char pad0[8];
    unsigned type;                  // 0x8
    unsigned count;                 // 0xc
    char pad10[8];
    const int *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34;
    const int *vtx[4];              // 0x38
    const int *uv[2];               // 0x48
};

// equiv-conv: FUN_002c8130 ecx eax esi
void FUN_002c8130(unsigned char flag, Desc *d, Dev *dev)
{
    unsigned n = d->count;
    const int *a, *b, *c, *e;
    if (flag == 1) {
        c = d->p2c;
        b = d->p24;
        a = d->p20;
        e = d->p34;
    } else {
        b = d->p1c;
        a = d->p18;
        c = d->p28;
        e = d->p30;
    }
    const int *uv0 = d->uv[0];
    const int *uv1 = d->uv[1];
    const int *vtx[4];
    vtx[0] = d->vtx[0];
    vtx[1] = d->vtx[1];
    vtx[2] = d->vtx[2];
    vtx[3] = d->vtx[3];
    unsigned t = (d->type & 0xfffc7fffu) - 0x2001u;
    if (t == 31) {
        if (n == 0)
            return;
        for (unsigned i = 0; i < n; i++)
            dev->v16(a + 3 * i, uv0[i]);
        return;
    }
    if (t == 15) {
        if (n == 0)
            return;
        for (unsigned i = 0; i < n; i++)
            dev->v15(a + 3 * i, b + 3 * i);
        return;
    }
    if (t == 0 || t == 32) {
        if (n == 0)
            return;
        if (t == 0) {
            dev->v14(a, vtx[0]);
            if (n == 0)
                return;
        }
        for (unsigned i = 0; i < n; i++)
            dev->v13(a + 3 * i, uv0[i], vtx[0] + 2 * i);
        return;
    }
    if (t == 16) {
        if (n == 0)
            return;
        for (unsigned i = 0; i < n; i++)
            dev->v12(a + 3 * i, b + 3 * i, vtx[0] + 2 * i);
        return;
    }
    for (unsigned i = 0; i < n; i++) {
        if (b != 0)
            dev->v1(b[3 * i], b[3 * i + 1], b[3 * i + 2]);
        if (c != 0)
            dev->v2(c[3 * i], c[3 * i + 1], c[3 * i + 2]);
        if (e != 0)
            dev->v3(e[3 * i], e[3 * i + 1], e[3 * i + 2]);
        for (unsigned k = 0; k < 2; k++) {
            const int *u = k == 0 ? uv0 : uv1;
            if (u != 0)
                dev->v4(u[i], k);
        }
        for (unsigned k = 0; k < 4; k++) {
            if (vtx[k] != 0)
                dev->v6(vtx[k][2 * i], vtx[k][2 * i + 1], k);
        }
        dev->v0(a[3 * i], a[3 * i + 1], a[3 * i + 2]);
    }
}
