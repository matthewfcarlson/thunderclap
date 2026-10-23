// STATUS: equivalent (tools/equiv.py level 3: 952 inputs, branch coverage 66/82, incomplete)
// FUN_000a89c0 @ 0x000a89c0
// cl-flags: /GS

struct V3 {
    float x, y, z;
    void FUN_0022d110x();
    float FUN_0022d110();
};

struct Sph {
    float x, y, z, r;
};

struct BBox {
    float mn[3];
    float mx[3];
    void FUN_000a87f0(V3 *p);
    void FUN_000a8890(Sph *out);
};

struct Mat4 {
    float m[16];
};

struct Comp {
    char pad0[0xa8];
    char ba8;
    void FUN_001c4b50(Sph *out);
};

struct Sub74 {
    char pad0[0x20];
    void *p20;
};
struct Sub {
    char pad0[0x74];
    Sub74 *p74;
};

struct Ent {
    char pad0[0x11c];
    Comp *p11c;
    Sub *FUN_001d72e0();
};

struct Reg {
    int FUN_001dcf50();
    Ent *FUN_001dc0b0(int k);
};

struct Ray {
    char FUN_00201e00(V3 *from, V3 *to, int one, V3 *outA, BBox *outB, int z1, int z2);
};

struct Arg1 {
    char pad0[0xc];
    Reg *p0c;
    char pad10[0x24 - 0x10];
    Ray *p24;
};

struct P170 {
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
    virtual void v12(int a);
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
    virtual void v24(int a, int b, int c);
};

struct Q {
    int a;
    int b;
    int c[4];
    char d;
    char pad[3];
};

unsigned int *FUN_000964d0();
char FUN_002f15a0(V3 *p, V3 *d, V3 *hit, float len, void *obj, Q *q);

class Picker {
public:
    char pad0[0x170];
    P170 *p170;
    char pad174[4];
    float f178;
    float f17c;
    Mat4 m180;
    int FUN_000a8670(V3 *buf, int n);
    int F(Arg1 *a1, int *ids, float *weights, int n, float bias, Mat4 *m, V3 *pt);
};

int Picker::F(Arg1 *a1, int *ids, float *weights, int n, float bias, Mat4 *m, V3 *pt)
{
    struct Frame {
        BBox bb;
        V3 hit;
        int spill48;
        void *obj20;
        float len;
        Sph os;
        Q q;
        int counts[8];
        V3 buf[8][8];
        char flags[8];
        Sph sph;
    } fr;
    int valid = 0;
    int i;
    if (n <= 0) {
        return -1;
    }
    for (i = 0; i < n; i++) {
        valid++;
        p170->v24(ids[i], 0, 0);
        fr.flags[i] = 1;
        p170->v12(0);
        m180 = *m;
        f178 = 1.0f;
        f17c = 0.3f;
        int cnt = FUN_000a8670(fr.buf[i], 8);
        fr.counts[i] = cnt;
        bool hit = cnt <= 0;
        if (cnt > 0) {
            V3 *p = fr.buf[i];
            for (int j = 0; j < cnt; j++, p++) {
                if (a1->p24->FUN_00201e00(pt, p, 1, &fr.hit, &fr.bb, 0, 0)) {
                    hit = true;
                    break;
                }
            }
        }
        if (hit) {
            valid--;
            fr.flags[i] = 0;
        }
    }
    if (valid <= 0) {
        return -1;
    }
    fr.bb.mn[0] = 1.0e12f;
    fr.bb.mn[1] = 1.0e12f;
    fr.bb.mn[2] = 1.0e12f;
    fr.bb.mx[0] = -1.0e12f;
    fr.bb.mx[1] = -1.0e12f;
    fr.bb.mx[2] = -1.0e12f;
    for (i = 0; i < n; i++) {
        if (fr.flags[i] && fr.counts[i] > 0) {
            V3 *p = fr.buf[i];
            for (int k = fr.counts[i]; k != 0; k--, p++)
                fr.bb.FUN_000a87f0(p);
        }
    }
    if (fr.bb.mn[0] > fr.bb.mx[0] || fr.bb.mn[1] > fr.bb.mx[1] || fr.bb.mn[2] > fr.bb.mx[2]) {
        return -1;
    }
    fr.bb.FUN_000a87f0(pt);
    fr.bb.FUN_000a8890(&fr.sph);
    Reg *reg = a1->p0c;
    int M = reg->FUN_001dcf50();
    if (M > 0 && valid > 0) {
        for (int k = 0; k < M; k++) {
            if (valid <= 0)
                break;
            Ent *e = reg->FUN_001dc0b0(k);
            if (!e || !e->p11c || !e->p11c->ba8)
                continue;
            e->p11c->FUN_001c4b50(&fr.os);
            double rs = fr.sph.r + fr.os.r;
            double dx = fr.sph.x - fr.os.x;
            double dy = fr.sph.y - fr.os.y;
            double dz = fr.sph.z - fr.os.z;
            double d2 = dz * dz + dy * dy + dx * dx;
            if (!(rs * rs >= d2))
                continue;
            Sub *s = e->FUN_001d72e0();
            if (!s || !s->p74 || !s->p74->p20)
                continue;
            fr.obj20 = s->p74->p20;
            fr.q.a = 2;
            fr.q.b = 0;
            fr.q.c[0] = 0;
            fr.q.c[1] = 0;
            fr.q.c[2] = 0;
            fr.q.c[3] = 0;
            fr.q.d = 1;
            for (int mi = 0; mi < n; mi++) {
                if (fr.flags[mi]) {
                    int cnt = fr.counts[mi];
                    for (int j = 0; j < cnt; j++) {
                        V3 *p = &fr.buf[mi][j];
                        V3 *D = (V3 *)&fr.bb;
                        fr.hit.x = p->x - pt->x;
                        D->x = fr.hit.x;
                        fr.hit.y = p->y - pt->y;
                        D->y = fr.hit.y;
                        fr.hit.z = p->z - pt->z;
                        D->z = fr.hit.z;
                        fr.len = D->FUN_0022d110();
                        if (FUN_002f15a0(pt, D, &fr.hit, fr.len, fr.obj20, &fr.q)) {
                            valid--;
                            fr.flags[mi] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    double sum = 0.0;
    for (i = 0; i < n; i++) {
        if (fr.flags[i])
            sum += weights[i];
    }
    float sumf = (float)sum;
    if (sum == 0.0) {
        return -1;
    }
    unsigned int *rng = FUN_000964d0();
    unsigned int za = rng[0];
    za = 0x9069 * (za & 0xffff) + (za >> 16);
    rng[0] = za;
    unsigned int zb = rng[1];
    zb = 0x4650 * (zb & 0xffff) + (zb >> 16);
    rng[1] = zb;
    union { unsigned int u; float f; } r;
    r.u = ((rng[0] << 16) + (zb & 0xffff)) & 0x7fffff | 0x3f800000;
    float target = (float)(((double)sumf + (double)bias) * (double)(r.f - 1.0f));
    double acc = 0.0;
    for (i = 0; i < n; i++) {
        if (fr.flags[i])
            acc += weights[i];
        if (acc >= target) {
            return i;
        }
    }
    return -1;
}
