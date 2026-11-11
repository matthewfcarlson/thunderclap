// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fca90..0x002fd360 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c93d4f {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9c93d4f {} using namespace fn_f9c93d4f;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f9c93d4f {
class SymMatrix_2fca90 {
  public:
    SymMatrix_2fca90();
    virtual ~SymMatrix_2fca90();
};
extern void* hulk_at_004315d0;
struct Matrix { int tag; float m11,m12,m13,m22,m23,m33; void FUN_002fcc10(const Matrix* a,const Matrix* b); };
struct Mat34 {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};
class SymTensor {
public:
    int header;
    float xx, xy, xz;
    float yy, yz, zz;
    void FUN_002fcd60(const Mat34* a);
};
struct Tensor_2fcf30 {
 char pad[4]; float a,b,c,d,e,f;
 void FUN_002fcf30(const Vector* v);
};
struct Obj_2fd080 {
    unsigned char pad[4];
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};


// 0x002fca90 FUN_002fca90 (9 B): matches/0x002fca90.cpp
// sym: ??0SymMatrix_2fca90@fn_f9c93d4f@@QAE@XZ
// Same code shape as 0x000b3de0 (propagated; names are from that function)
SymMatrix_2fca90::SymMatrix_2fca90() {}


// 0x002fcaa0 FUN_002fcaa0 (7 B): matches/0x002fcaa0.cpp
// sym: @FUN_002fcaa0@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_002fcaa0(void* self) {
    *(void**)self = &hulk_at_004315d0;
}

} // namespace fn_f9c93d4f

// 0x002fcaf0 FUN_002fcaf0 (61 B): matches/0x002fcaf0.cpp
// sym: ?FUN_002fcaf0@V_2fcaf0@owners@@QAEXPAU12@@Z
void owners::V_2fcaf0::FUN_002fcaf0(owners::V_2fcaf0* p) {
    b += p->b;
    c += p->c;
    d += p->d;
    e += p->e;
    f += p->f;
    g += p->g;
}


// 0x002fcb30 FUN_002fcb30 (65 B): matches/0x002fcb30.cpp
// sym: ?FUN_002fcb30@V_2fcb30@owners@@QAEXPAU12@0@Z
void owners::V_2fcb30::FUN_002fcb30(owners::V_2fcb30* a, owners::V_2fcb30* b) {
    x1 = a->x1 + b->x1;
    x2 = a->x2 + b->x2;
    x3 = a->x3 + b->x3;
    x4 = a->x4 + b->x4;
    x5 = a->x5 + b->x5;
    x6 = a->x6 + b->x6;
}


// 0x002fcb80 FUN_002fcb80 (63 B): matches/0x002fcb80.cpp
// sym: ?FUN_002fcb80@X_2fcb80@owners@@QAEXM@Z
void owners::X_2fcb80::FUN_002fcb80(float s) {
    a[0] *= s;
    a[1] *= s;
    a[2] *= s;
    a[3] *= s;
    a[4] *= s;
    a[5] *= s;
}

namespace fn_f9c93d4f {

// 0x002fcc10 FUN_002fcc10 (195 B): equivalent/0x002fcc10.cpp
// sym: ?FUN_002fcc10@Matrix@fn_f9c93d4f@@QAEXPBU12@0@Z @d50becd4311d @w9ed5bbe357e0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fcc10 @ 0x002fcc10
void Matrix::FUN_002fcc10(const Matrix* a,const Matrix* b) {
    volatile float middle = a->m12*b->m12;
    double p13 = (double)b->m13*a->m13;
    double p23 = (double)b->m23*a->m23;
    float r11 = (float)(((double)a->m11*b->m11 + middle) + p13);
    float r12 = (float)(((double)a->m11*b->m12 + (double)b->m23*a->m13) + (double)a->m12*b->m22);
    float r13 = (float)(((double)b->m33*a->m13 + (double)a->m12*b->m23) + (double)a->m11*b->m13);
    float r22 = (float)(((double)b->m22*a->m22 + p23) + middle);
    float r23 = (float)(((double)b->m23*a->m22 + (double)a->m23*b->m33) + (double)a->m12*b->m13);
    float r33 = (float)(((double)a->m33*b->m33 + p23) + p13);
    m13=r13; m22=r22; m23=r23; m33=r33; m11=r11; m12=r12;
}


// 0x002fcd60 FUN_002fcd60 (451 B): equivalent/0x002fcd60.cpp
// sym: ?FUN_002fcd60@SymTensor@fn_f9c93d4f@@QAEXPBUMat34@2@@Z @4af1c23a51a0 @wf66c5955a5ff
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_002fcd60 @ 0x002fcd60
// x87 (the listing's precision): vx and vy go through the frame (rounded); vz is used once from its register and
// then from a rounded copy; the new xx, xy, xz and the row sums stay in registers (53 bits) until they are stored;
// yy, yz, zz are rounded frame copies. Sums in the listing's order.
void SymTensor::FUN_002fcd60(const Mat34* a)
{
    float a0 = a->m00, a4 = a->m01, a8 = a->m02;
    float a10 = a->m10, a14 = a->m11, a18 = a->m12;
    float a20 = a->m20, a24 = a->m21, a28 = a->m22;
    volatile float vx = ((hulk_freg)a0 * xx + (hulk_freg)a20 * xz) + (hulk_freg)a10 * xy;
    volatile float vy = ((hulk_freg)a20 * yz + (hulk_freg)a10 * yy) + (hulk_freg)a0 * xy;
    hulk_freg vzu = ((hulk_freg)a10 * yz + (hulk_freg)a20 * zz) + (hulk_freg)a0 * xz;
    volatile float vz = (float)vzu;
    hulk_freg nxx = (vzu * a20 + (hulk_freg)vy * a10) + (hulk_freg)vx * a0;
    hulk_freg nxz = ((hulk_freg)vy * a18 + (hulk_freg)vz * a28) + (hulk_freg)vx * a8;
    hulk_freg nxy = ((hulk_freg)vz * a24 + (hulk_freg)vy * a14) + (hulk_freg)vx * a4;
    hulk_freg u1 = ((hulk_freg)a4 * xx + (hulk_freg)a24 * xz) + (hulk_freg)a14 * xy;
    hulk_freg u2 = ((hulk_freg)a24 * yz + (hulk_freg)a14 * yy) + (hulk_freg)a4 * xy;
    hulk_freg u3 = ((hulk_freg)a14 * yz + (hulk_freg)a24 * zz) + (hulk_freg)a4 * xz;
    volatile float ny = (a24 * u3 + u2 * a14) + u1 * a4;
    volatile float nyz = (u3 * a28 + u2 * a18) + u1 * a8;
    hulk_freg w2 = ((hulk_freg)a28 * yz + (hulk_freg)a18 * yy) + (hulk_freg)a8 * xy;
    hulk_freg w1 = ((hulk_freg)a8 * xx + (hulk_freg)a28 * xz) + (hulk_freg)a18 * xy;
    hulk_freg w3 = ((hulk_freg)a18 * yz + (hulk_freg)a28 * zz) + (hulk_freg)a8 * xz;
    volatile float nz = (w2 * a18 + w1 * a8) + w3 * a28;
    yy = ny;
    yz = nyz;
    zz = nz;
    xx = (float)nxx;
    xy = (float)nxy;
    xz = (float)nxz;
}


// 0x002fcf30 FUN_002fcf30 (225 B): equivalent/0x002fcf30.cpp
// sym: ?FUN_002fcf30@Tensor_2fcf30@fn_f9c93d4f@@QAEXPBUVector@2@@Z @0ed5b8c86416 @w835fb50bf2b6
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fcf30 @ 0x002fcf30
void Tensor_2fcf30::FUN_002fcf30(const Vector* v) {
 volatile float A=c*v->y-v->z*b;
 volatile float B=e*v->y-v->z*d;
 double C=(double)f*v->y-(double)v->z*e;
 volatile float roundedC=(float)C;
 float na=(float)(C*v->y-(double)B*v->z);
 float nc=(float)((double)B*v->x-(double)A*v->y);
 float nb=(float)((double)A*v->z-(double)roundedC*v->x);
 double D=(double)v->z*a-(double)c*v->x;
 float nd=(float)(D*v->z-((double)v->z*c-(double)v->x*f)*v->x);
 float ne=(float)(-(D*v->y));
 float nf=(float)(((double)d*v->x-(double)v->y*b)*v->x-((double)v->x*b-(double)a*v->y)*v->y);
 d=nd; e=ne; f=nf; a=na; b=nb; c=nc;
}

} // namespace fn_f9c93d4f

// 0x002fd020 FUN_002fd020 (82 B): matches/0x002fd020.cpp
// sym: ?FUN_002fd020@Transform_2fd020@owners@@QAEXPAM0@Z
void owners::Transform_2fd020::FUN_002fd020(float* v, float* out) {
    out[0] = m04 * v[0] + m08 * v[1] + m0c * v[2];
    out[1] = m10 * v[1] + m14 * v[2] + m08 * v[0];
    out[2] = m18 * v[2] + m0c * v[0] + m14 * v[1];
}

namespace fn_f9c93d4f {

// 0x002fd080 FUN_002fd080 (26 B): matches/0x002fd080.cpp
// sym: ?FUN_002fd080@fn_f9c93d4f@@YIXPAUObj_2fd080@1@@Z
void __fastcall FUN_002fd080(Obj_2fd080* p) {
    p->f = 0x3f800000;
    p->d = 0x3f800000;
    p->a = 0x3f800000;
    p->e = 0;
    p->c = 0;
    p->b = 0;
}

} // namespace fn_f9c93d4f

// 0x002fd0a0 FUN_002fd0a0 (21 B): matches/0x002fd0a0.cpp
// sym: ?FUN_002fd0a0@C_2fd0a0@owners@@QAEXXZ
void owners::C_2fd0a0::FUN_002fd0a0() {
    pad[6] = 0;
    pad[4] = 0;
    pad[1] = 0;
    pad[5] = 0;
    pad[3] = 0;
    pad[2] = 0;
}


// 0x002fd0c0 FUN_002fd0c0 (389 B): equivalent/0x002fd0c0.cpp
// sym: ?FUN_002fd0c0@Sym3_2fd0c0@owners@@QAEXPBU12@@Z @ad5f990f99fb @wd6a63d39ca1a
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// FUN_002fd0c0 @ 0x002fd0c0
// Inverse of a symmetric 3x3 matrix stored as six floats; zero when the pivot product vanishes.
// Intermediates are kept as double (the original keeps them unrounded on the x87 stack).
void owners::Sym3_2fd0c0::FUN_002fd0c0(const owners::Sym3_2fd0c0 *a)
{
    double inv = 1.0 / a->xx;
    double piv = inv * a->xx;
    hulk_freg t0 = (float)(inv * a->xy);
    hulk_freg t1 = (float)(inv * a->xz);
    hulk_freg t2 = (float)(inv * a->yy);
    hulk_freg t3 = (float)(inv * a->yz);
    double e4 = inv * a->zz;
    hulk_freg t4 = (float)e4;
    double e5 = e4 * t2;
    volatile float u = (float)e5;      // the original stores and reloads it rounded
    double q = e5 * piv;
    if (q == 0.0) {
        yy = 0.0f;
        xx = 0.0f;
        yz = 0.0f;
        xz = 0.0f;
        xy = 0.0f;
        zz = 0.0f;
        return;
    }
    xx = (float)piv;
    double r1 = (double)t3 * t1;
    volatile float m0 = (float)r1;     // likewise (fst [esp])
    xy = t0;
    xz = t1;
    yy = t2;
    yz = t3;
    zz = t4;
    double d = inv / (((r1 * t0 + r1 * t0) + q) - ((double)t1 * t1) * t2 - ((double)t0 * t0) * t4 - ((double)t3 * t3) * piv);
    hulk_freg x1 = (float)((u - (double)t3 * t3) * d);
    hulk_freg x2 = (float)(-(((double)t0 * t4 - m0) * d));
    hulk_freg x3 = (float)(((double)t3 * t0 - (double)t1 * t2) * d);
    hulk_freg x4 = (float)(((double)t4 * xx - (double)t1 * t1) * d);
    hulk_freg x5 = (float)(-(((double)t3 * xx - (double)t0 * t1) * d));
    hulk_freg x6 = (float)(((double)t2 * xx - (double)t0 * t0) * d);
    xz = x3;
    yy = x4;
    yz = x5;
    zz = x6;
    xx = x1;
    xy = x2;
}

