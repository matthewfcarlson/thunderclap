// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00356bf0..0x00357740 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f10b45e7 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f10b45e7 {} using namespace fn_f10b45e7;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f10b45e7 {
struct Grad_356e50 {
    float x, y;
};
struct Grad_356fa0 {
    float x, y, z;
};
struct Obj {
    unsigned char b;
    Obj() { b = 1; }
    ~Obj();
    void Init_003572b0();
};


// 0x00356bf0 FUN_00356bf0 (57 B): matches/0x00356bf0.cpp
// sym: _FUN_00356bf0
extern "C" void FUN_00356bf0(float a, float b, float c, float* x, float* y, float* z) {
    hulk_freg s = (hulk_freg)sin(c) * a;
    *x = s * (hulk_freg)cos(b);
    *y = s * (hulk_freg)sin(b);
    *z = a * (hulk_freg)cos(c);
}


// 0x00356c30 FUN_00356c30 (130 B): matches/0x00356c30.cpp
// sym: _FUN_00356c30
extern "C" unsigned int __cdecl FUN_00356c30(unsigned int value) {
    unsigned int result;
    unsigned char table[16];
    unsigned int index = value;
    unsigned int zero = 0;

    if (index & 0xFFFF0000) {
        index >>= 16;
        result = 0x10;
    } else {
        result = 0;
    }

    if (index & 0xFF00) {
        index >>= 8;
        result |= 8;
    }

    if (index & 0xF0) {
        index >>= 4;
        result |= 4;
    }

    table[0] = zero;
    table[1] = zero;
    table[2] = 1;
    table[3] = 1;
    table[4] = 2;
    table[5] = 2;
    table[6] = 2;
    table[7] = 2;
    table[8] = 3;
    table[9] = 3;
    table[10] = 3;
    table[11] = 3;
    table[12] = 3;
    table[13] = 3;
    table[14] = 3;
    table[15] = 3;

    return (int)(signed char)table[index] | result;
}


// 0x00356e50 FUN_00356e50 (332 B): equivalent/0x00356e50.cpp
// sym: ?FUN_00356e50@fn_f10b45e7@@YGMPBM@Z @9e44a5962e5d @w87c0f7de3638
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 0/0)
// FUN_00356e50 @ 0x00356e50
// 2D gradient (Perlin) noise at point p[0], p[1].
hulk_freg __stdcall FUN_00356e50(const float *p)
{
    hulk_freg xs = p[0] + 4096.0f;
    int xi = (int)(__int64)xs;
    hulk_freg fx = xs - (hulk_freg)xi;
    int ix = xi & 0xff;
    float fx1 = fx - 1.0f;

    hulk_freg ys = p[1] + 4096.0f;
    int yi = (int)(__int64)ys;
    int iy = yi & 0xff;
    int a = DAT_0056bfc8[ix];
    float fy = ys - (hulk_freg)yi;
    int iy1 = (iy + 1) & 0xff;
    int ix1 = (ix + 1) & 0xff;
    float fy1 = fy - 1.0f;
    int b = DAT_0056bfc8[ix1];

    float u = (3.0f - (fx + fx)) * fx * fx;

    const Grad_356e50 *g00 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[a + iy]];
    const Grad_356e50 *g10 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[iy + b]];
    const Grad_356e50 *g11 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[b + iy1]];
    const Grad_356e50 *g01 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[a + iy1]];

    hulk_freg d00 = fy * g00->y + fx * g00->x;
    hulk_freg d10 = fy * g10->y + fx1 * g10->x;
    float x0 = (d10 - d00) * u + d00;

    hulk_freg d01 = fx * g01->x + fy1 * g01->y;
    hulk_freg d11 = fy1 * g11->y + fx1 * g11->x;
    hulk_freg x1 = d01 + (d11 - d01) * u;

    return (x1 - x0) * ((3.0f - (fy + fy)) * fy * fy) + x0;
}


// 0x00356fa0 FUN_00356fa0 (651 B): equivalent/0x00356fa0.cpp
// sym: ?FUN_00356fa0@fn_f10b45e7@@YGMPAM@Z @d9bd4a727249 @w25b088d61d7d
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 0/0)
// FUN_00356fa0 @ 0x00356fa0
hulk_freg __stdcall FUN_00356fa0(float *p)
{
    double x = p[0] + 4096.0f;
    int xa = (int)(__int64)x;
    double fx = x - xa;
    int xi = xa & 0xff;
    float fx1 = (hulk_freg)(fx - 1.0f);

    double y = p[1] + 4096.0f;
    int ya = (int)(__int64)y;
    double fy = y - ya;
    int yi = ya & 0xff;
    int yi1 = (yi + 1) & 0xff;
    float fy1 = (hulk_freg)(fy - 1.0f);

    double z = p[2] + 4096.0f;
    int za = (int)(__int64)z;
    int zi = za & 0xff;
    int zi1 = (zi + 1) & 0xff;
    float fz = (hulk_freg)(z - za);

    int xi1 = (xi + 1) & 0xff;
    int a = DAT_0056bfc8[xi];
    int b = DAT_0056bfc8[xi1];
    int aa = DAT_0056bfc8[a + yi];
    int ab = DAT_0056bfc8[a + yi1];
    int ba = DAT_0056bfc8[b + yi];
    int bb = DAT_0056bfc8[b + yi1];

    hulk_freg fz1 = fz - 1.0f;
    float u = (hulk_freg)((3.0f - (fx + fx)) * fx * fx);
    float v = (hulk_freg)((3.0f - (fy + fy)) * fy * fy);

    const Grad_356fa0 &g000 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + aa];
    const Grad_356fa0 &g100 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + ba];
    const Grad_356fa0 &g010 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + ab];
    const Grad_356fa0 &g110 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + bb];
    const Grad_356fa0 &g001 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + aa];
    const Grad_356fa0 &g101 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + ba];
    const Grad_356fa0 &g011 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + ab];
    const Grad_356fa0 &g111 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + bb];

    double d000 = fz * g000.z + fy * g000.y + fx * g000.x;
    double d100 = fz * g100.z + fy * g100.y + fx1 * g100.x;
    double l00 = d000 + (d100 - d000) * u;
    double d010 = fz * g010.z + fy1 * g010.y + fx * g010.x;
    double d110 = fz * g110.z + fy1 * g110.y + fx1 * g110.x;
    double l10 = d010 + (d110 - d010) * u;
    float m0 = (hulk_freg)(l00 + (l10 - l00) * v);

    double d001 = fz1 * g001.z + fy * g001.y + fx * g001.x;
    double d101 = fz1 * g101.z + fy * g101.y + fx1 * g101.x;
    float l01 = (hulk_freg)(d001 + (d101 - d001) * u);
    double d011 = fz1 * g011.z + fy1 * g011.y + fx * g011.x;
    double d111 = fz1 * g111.z + fy1 * g111.y + fx1 * g111.x;
    double l11 = d011 + (d111 - d011) * u;
    double m1 = l01 + (l11 - l01) * v;

    double w = (3.0f - (fz + fz)) * fz * fz;
    return (hulk_freg)(m0 + (m1 - m0) * w);
}

} // namespace fn_f10b45e7

// 0x003572b0 FUN_003572b0 (1044 B): equivalent/0x003572b0.cpp [wrapped: helper definitions (4 out-of-line function bodies)]
// sym: ?FUN_003572b0@NoiseInit@fn_003572b0@@QAEXXZ @1fae2520027b @w2570f42d46c0
namespace fn_003572b0 {
// STATUS: equivalent (tools/equiv.py level 3: 19873 inputs, branch coverage 21/22, incomplete)
// FUN_003572b0 @ 0x003572b0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


// Gradient noise tables (Perlin's classic init): permutation p, 1-D gradients g1, 2-D gradients g2, 3-D gradients g3.
struct NoiseTables {
    float g1[0x202];
    int p[0x202];
    float g3[0x202][3];
    float g2[0x202][2];
};

struct RandState {
    unsigned int s0;
    unsigned int s1;
};

static unsigned int Next()
{
    RandState *r = (*(RandState**)&DAT_004e5acc);
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    return (r->s0 << 16) + (r->s1 & 0xffff);
}

// Perlin's normalize2/normalize3: the components are read back from the table (rounded), and the divisions by
// the length are one reciprocal 1/s (unrounded) and multiplies, as the original computes them.
static void normalize2(float v[2])
{
    double r = 1.0f / sqrt(v[0] * v[0] + v[1] * v[1]);
    v[0] = (float)(v[0] * r);
    v[1] = (float)(v[1] * r);
}

static void normalize3(float v[3])
{
    double r = 1.0f / sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] = (float)(v[0] * r);
    v[1] = (float)(v[1] * r);
    v[2] = (float)(v[2] * r);
}

struct NoiseInit {
    char start;
    void FUN_003572b0();
};

void NoiseInit::FUN_003572b0()
{
    if (start == 0)
        return;
    NoiseTables &t = (*(NoiseTables*)&DAT_0056b7c0);
    int i = 0;
    do {
        t.p[i] = i;
        t.g1[i] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g2[i][0] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g2[i][1] = (float)(Next() % 512 - 256) * 0.00390625f;
        normalize2(t.g2[i]);
        t.g3[i][0] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g3[i][1] = (float)(Next() % 512 - 256) * 0.00390625f;
        t.g3[i][2] = (float)(Next() % 512 - 256) * 0.00390625f;
        normalize3(t.g3[i]);
        i++;
    } while (i < 0x100);

    while (--i) {
        int k = t.p[i];
        int j = Next() % 256;
        t.p[i] = t.p[j];
        t.p[j] = k;
    }

    // forward word copies (the original's rep movsd): the last two words read entries this copy just wrote
    // (0x100 and 0x101), which a memcpy of overlapping ranges does not promise
    for (i = 0; i < 0x102; i++)
        t.g1[0x100 + i] = t.g1[i];
    for (i = 0; i < 0x102; i++)
        t.p[0x100 + i] = t.p[i];
    for (i = 0; i < 0x102; i++) {
        t.g2[0x100 + i][0] = t.g2[i][0];
        t.g2[0x100 + i][1] = t.g2[i][1];
        t.g3[0x100 + i][0] = t.g3[i][0];
        t.g3[0x100 + i][1] = t.g3[i][1];
        t.g3[0x100 + i][2] = t.g3[i][2];
    }
    start = 0;
}
} // namespace fn_003572b0

namespace fn_f10b45e7 {

// 0x003576d0 FUN_003576d0 (63 B): matches/0x003576d0.cpp
// sym: ?getObj@fn_f10b45e7@@YAPAUObj@1@XZ
Obj* getObj() {
    static Obj obj;
    obj.Init_003572b0();
    return &obj;
}

} // namespace fn_f10b45e7
