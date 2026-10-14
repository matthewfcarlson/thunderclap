// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 84/90, incomplete)
// FUN_00307240 @ 0x00307240
struct Vec3_307240 {
    float x, y, z;
    void FUN_001f6bc0(const float *a, float t, const float *b) throw();
};

struct Ctx_307240 {
    float v0[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

union Arg_307240 {
    Ctx_307240 *ctx;
    unsigned int n2;
};

extern unsigned short *DAT_0055543c;
extern unsigned short *DAT_00555440;
void __cdecl FUN_00307030(unsigned int w) throw();

static __forceinline void Append(unsigned short w)
{
    unsigned short c = *DAT_0055543c;
    if (c < 0x400) {
        DAT_00555440[c] = w;
        (*DAT_0055543c)++;
    }
}

struct Stream {
    unsigned short w[1];
    void FUN_00307240(Arg_307240 a);
};

void Stream::FUN_00307240(Arg_307240 a)
{
    struct Frame {
        unsigned short *p;
        union {
            float absTmp;
            unsigned int code;
        } c;
        union {
            unsigned int n;
            float val;
        } u;
        Vec3_307240 save;
        Vec3_307240 out;
    } f;

    Ctx_307240 *ctx = a.ctx;
    Arg_307240 pa;
    pa.ctx = ctx;
    f.p = (unsigned short *)this;
    for (;;) {
        unsigned int h = *f.p;
        unsigned int op = (h >> 12) & 3;
        unsigned int cnt = 0;
        unsigned int ebp = 0;
        a.n2 = 0;
        switch (op) {
        case 0:
            cnt = h & 0xfff;
            break;
        case 1:
            ebp = (h >> 6) & 0x3f;
            cnt = h & 0x3f;
            break;
        case 2:
            a.n2 = (h >> 6) & 0x3f;
            cnt = h & 0x3f;
            break;
        default:
            ebp = (h >> 8) & 0xf;
            a.n2 = (h >> 4) & 0xf;
            cnt = h & 0xf;
            break;
        }
        unsigned short *esi = f.p + 1;
        if ((unsigned short)cnt != 0) {
            unsigned int n = (unsigned short)cnt;
            do {
                Append(*esi);
                esi++;
                n--;
            } while (n != 0);
        }
        unsigned int code = (unsigned short)(*f.p) >> 14;
        if (code == 3)
            return;
        f.u.n = *esi;
        f.u.val = (float)(int)f.u.n;
        esi++;
        float P, Q;
        if (ctx->v3[code] >= 0.0f) {
            P = ctx->v1[code];
            Q = ctx->v0[code];
        } else {
            P = ctx->v0[code];
            Q = ctx->v1[code];
        }
        if (P + 2.0f < f.u.val) {
            if (op & 1) {
                if ((unsigned short)ebp == 0)
                    return;
                unsigned int n = (unsigned short)ebp;
                do {
                    Append(*esi);
                    esi++;
                    n--;
                } while (n != 0);
                return;
            }
            f.p = f.p + *esi;
            continue;
        }
        if (Q - 2.0f > f.u.val) {
            if (op & 1)
                esi = esi + (unsigned short)ebp;
            else
                esi = esi + 1;
            if (op & 2) {
                unsigned int n = (unsigned short)a.n2;
                if (n == 0)
                    return;
                do {
                    Append(*esi);
                    esi++;
                    n--;
                } while (n != 0);
                return;
            }
            f.p = f.p + *esi;
            continue;
        }
        f.c.absTmp = ctx->v3[code];
        *(unsigned int *)&f.c.absTmp &= 0x7fffffff;
        if (f.c.absTmp < 1e-05f) {
            if (op & 1) {
                if ((unsigned short)ebp != 0) {
                    unsigned int n = (unsigned short)ebp;
                    do {
                        Append(*esi);
                        esi++;
                        n--;
                    } while (n != 0);
                }
            } else {
                unsigned short *sub = f.p + *esi;
                esi++;
                ((Stream *)sub)->FUN_00307240(pa);
            }
            if (!(op & 2)) {
                f.p = f.p + *esi;
                continue;
            }
            unsigned int n = a.n2;
            if ((unsigned short)n == 0)
                return;
            unsigned int m = (unsigned short)n;
            do {
                Append(*esi);
                esi++;
                m--;
            } while (m != 0);
            return;
        }
        if (op == 3) {
            unsigned int n = a.n2 + ebp;
            if ((unsigned short)n == 0)
                return;
            unsigned int m = (unsigned short)n;
            do {
                Append(*esi);
                esi++;
                m--;
            } while (m != 0);
            return;
        }
        float t = (f.u.val - ctx->v2[code]) / ctx->v3[code];
        f.c.code = code;
        f.out.FUN_001f6bc0(ctx->v2, t, ctx->v3);
        if (ctx->v3[f.c.code] >= 0.0f) {
            f.save = *(Vec3_307240 *)ctx->v1;
            *(Vec3_307240 *)ctx->v1 = f.out;
            if (op & 1) {
                if ((unsigned short)ebp != 0) {
                    unsigned int n = (unsigned short)ebp;
                    do {
                        FUN_00307030(*esi);
                        esi++;
                        n--;
                    } while (n != 0);
                }
            } else {
                unsigned short *sub = f.p + *esi;
                esi++;
                ((Stream *)sub)->FUN_00307240(pa);
            }
            *(Vec3_307240 *)ctx->v1 = f.save;
            f.save = *(Vec3_307240 *)ctx->v0;
            *(Vec3_307240 *)ctx->v0 = f.out;
            if (op & 2) {
                unsigned int n = a.n2;
                if ((unsigned short)n != 0) {
                    unsigned int m = (unsigned short)n;
                    do {
                        FUN_00307030(*esi);
                        esi++;
                        m--;
                    } while (m != 0);
                }
            } else {
                unsigned short *sub = f.p + *esi;
                ((Stream *)sub)->FUN_00307240(pa);
            }
            *(Vec3_307240 *)ctx->v0 = f.save;
            return;
        }
        f.save = *(Vec3_307240 *)ctx->v0;
        *(Vec3_307240 *)ctx->v0 = f.out;
        if (op & 1) {
            if ((unsigned short)ebp != 0) {
                unsigned int n = (unsigned short)ebp;
                do {
                    FUN_00307030(*esi);
                    esi++;
                    n--;
                } while (n != 0);
            }
        } else {
            unsigned short *sub = f.p + *esi;
            esi++;
            ((Stream *)sub)->FUN_00307240(pa);
        }
        *(Vec3_307240 *)ctx->v0 = f.save;
        f.save = *(Vec3_307240 *)ctx->v1;
        *(Vec3_307240 *)ctx->v1 = f.out;
        if (op & 2) {
            unsigned int n = a.n2;
            if ((unsigned short)n != 0) {
                unsigned int m = (unsigned short)n;
                do {
                    FUN_00307030(*esi);
                    esi++;
                    m--;
                } while (m != 0);
            }
        } else {
            unsigned short *sub = f.p + *esi;
            ((Stream *)sub)->FUN_00307240(pa);
        }
        *(Vec3_307240 *)ctx->v1 = f.save;
        return;
    }
}
