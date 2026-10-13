// STATUS: equivalent (tools/equiv.py level 3: 518 inputs, branch coverage 30/33, incomplete)
// FUN_002bbb40 @ 0x002bbb40
extern "C" void __fastcall FUN_00011090(void *p);
extern "C" void __fastcall FUN_000c7920(void *p);
void __stdcall FUN_00011520(void *p, unsigned int size, int count, void(__fastcall *ctor)(void *));

struct Rng {
    Rng *FUN_0022aba0(int seed);
    float FUN_00078780();
};
extern Rng DAT_00554bc4;
extern unsigned char DAT_00554bcc;

#define ENSURE_RNG                      \
    if (!(DAT_00554bcc & 1)) {            \
        DAT_00554bcc |= 1;                \
        DAT_00554bc4.FUN_0022aba0(0);     \
    }

struct Quad {
    char pad00[8];
    unsigned int *pos;
    char pad0c[4];
    unsigned int *col;
    unsigned int *uv;
    void FUN_0008ef00();
};

struct Mat {
    char d[0x40];
    void FUN_0022ca90(const void *t, int a);
};

class Emitter {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int *a, unsigned int *b, Mat *m, unsigned int c);
    char pad04[0x34];
    unsigned char on;
    unsigned char pad39[3];
    unsigned int color;
    char xform[0x50];
    unsigned int mode90;
    int mode94;
    float uvs[8];
    float du;
    float dv;
    unsigned int c0;
    unsigned int c4;
    void FUN_002b8f60(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b90e0(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b9230(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b9310(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b98d0(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b9ac0(void *verts, Mat *m, unsigned int a4, unsigned int a3, unsigned int s);
    void FUN_002b93f0(float *a, unsigned int *b, unsigned int c, int d);
    void FUN_002bbb40(Quad *q, int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6);
};

#define EmitVert(mq, mc, muv, mvert)                                 \
    do {                                                             \
        *(mq)->col = (mc);                                           \
        (mq)->uv[0] = *(const unsigned int *)&(muv)[0];              \
        ((float *)(mq)->uv)[1] = (muv)[1];                           \
        (mq)->pos[0] = *(const unsigned int *)&(mvert)[0];           \
        ((float *)(mq)->pos)[1] = (mvert)[1];                        \
        ((float *)(mq)->pos)[2] = (mvert)[2];                        \
        (mq)->FUN_0008ef00();                                        \
    } while (0)

#define EmitZero(mq)               \
    do {                           \
        *(mq)->col = 0;            \
        (mq)->uv[0] = 0;           \
        (mq)->uv[1] = 0;           \
        (mq)->pos[0] = 0;          \
        (mq)->pos[1] = 0;          \
        (mq)->pos[2] = 0;          \
        (mq)->FUN_0008ef00();      \
    } while (0)

union FI {
    float f;
    unsigned int u;
};

struct Frame {
    FI tmp0c;
    FI s10;
    FI s14;
    float uv[8];
    float vert[12];
    Mat mat;
};

void Emitter::FUN_002bbb40(Quad *q, int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
    Frame f;
    f.mat.FUN_0022ca90(xform, a2);
    f.s10.u = a6;
    f.s14.u = a5;
    v6(&f.s14.u, &f.s10.u, &f.mat, a3);
    if (on == 1 && f.s14.f > 0.0f && f.s10.f != 0.0f) {
        FUN_00011520(f.vert, 0xc, 4, FUN_00011090);
        switch (mode90) {
        case 0:
            FUN_002b8f60(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 2:
            FUN_002b9230(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 3:
            FUN_002b9310(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 4:
            FUN_002b98d0(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        case 5:
            FUN_002b9ac0(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        default:
            FUN_002b90e0(f.vert, &f.mat, a4, a3, f.s10.u);
            break;
        }
        FUN_00011520(f.uv, 8, 4, FUN_000c7920);
        switch (mode94) {
        case 1: {
            unsigned int x = c0;
            c0 = x;
            du = (float)x * (1.0f / (float)c4);
            break;
        }
        case 2:
            FUN_002b93f0(&du, &c0, c0, 1);
            break;
        case 3:
            ENSURE_RNG
            du = DAT_00554bc4.FUN_00078780();
            break;
        case 4:
            ENSURE_RNG
            dv = DAT_00554bc4.FUN_00078780();
            break;
        case 5:
            ENSURE_RNG
            du = DAT_00554bc4.FUN_00078780();
            dv = DAT_00554bc4.FUN_00078780();
            break;
        default:
            break;
        }
        f.uv[0] = uvs[0] + du;
        unsigned int col = color;
        f.uv[1] = uvs[1] + dv;
        f.uv[2] = uvs[2] + du;
        f.uv[3] = uvs[3] + dv;
        f.uv[4] = uvs[4] + du;
        f.uv[5] = uvs[5] + dv;
        f.uv[6] = uvs[6] + du;
        f.uv[7] = uvs[7] + dv;
        f.tmp0c.f = f.s14.f - 1.0f;
        f.tmp0c.u &= 0x7fffffff;
        if (!(f.tmp0c.f <= 1e-5f)) {
            const unsigned char *cb = (const unsigned char *)&color;
            f.tmp0c.u = cb[2];
            unsigned int c = (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) & 0xff;
            f.tmp0c.u = cb[3];
            c |= (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) << 8;
            f.tmp0c.u = cb[1];
            c <<= 8;
            c |= (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) & 0xff;
            f.tmp0c.u = col & 0xff;
            c <<= 8;
            c |= (unsigned int)(int)((float)(int)f.tmp0c.u * f.s14.f) & 0xff;
            col = c;
        }
        Quad *b = q;
        EmitVert(b, col, &f.uv[2], &f.vert[3]);
        EmitVert(b, col, &f.uv[0], &f.vert[0]);
        EmitVert(b, col, &f.uv[4], &f.vert[6]);
        EmitVert(b, col, &f.uv[4], &f.vert[6]);
        EmitVert(b, col, &f.uv[0], &f.vert[0]);
        EmitVert(b, col, &f.uv[6], &f.vert[9]);
    } else {
        Quad *b = q;
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
        EmitZero(b);
    }
}
