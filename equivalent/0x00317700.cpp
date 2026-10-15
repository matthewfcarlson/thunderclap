// STATUS: equivalent (tools/equiv.py level 3: 20036 inputs, branch coverage 122/126, incomplete)
// FUN_00317700 @ 0x00317700
// FUN_00317700 @ 0x00317700
// Resolver::FUN_00317700 (this=ecx, ret 0x10): contact emitter for two swept bodies. Each body is a segment
// (n = axis, f50 = half length) with radius f54; b58 says whether the body is "long" (capsule) or not.
// Both short: test the four end-point pairs as spheres. Both long: end-point pairs, then the parallel case or
// the closest points of the two axes. Mixed: test the short body's two end points against the long one.
// The locals live in one Frame at the original's stack slots (several slots hold different values in
// different blocks), because the callees get pointers into it.
extern "C" double __cdecl sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    void FUN_001f6bc0(const Vec3 *base, float s, const Vec3 *dir);
};

union FloatBits {
    float f;
    unsigned int u;
};

class Body {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3 *vfunc_4();
    char pad04[0x44 - 4];
    Vec3 n;                          // 0x44
    float f50;                       // 0x50
    float f54;                       // 0x54
    char b58;                        // 0x58
};

float __cdecl FUN_00083d90(float *v);

class Resolver {
public:
    char pad00[0x0c];
    float threshold;                 // 0x0c
    char pad10[4];
    Vec3 offset;                     // 0x14
    Vec3 dir;                        // 0x20
    void FUN_00314be0(Body *a, Vec3 *pa, Body *b, Vec3 *pb, float depth, Vec3 *dir);
    int FUN_00314a10(const Vec3 *a1, const Vec3 *a2, const Vec3 *axis, float f4, float f5, char flag, Vec3 *out, Vec3 *out2);
    bool FUN_00314430(Body *p, Vec3 *a1, float a2, Vec3 *a3, float *a4, Vec3 *a5, Vec3 *a6, char a7);
    bool FUN_003148c0(Vec3 *a1, Vec3 *a2, Vec3 *a3, Vec3 *a4, Vec3 *result, Vec3 *axisDir, bool computeAxis);
    bool FUN_00317700(Body *a, Body *b, char mode, bool emit);
};

bool Resolver::FUN_00317700(Body *a, Body *b, char mode, bool emit)
{
    // Stack frame, at the original's offsets (comments: offset from esp after the register pushes).
    struct Frame {
        union { float rb0; float e2; float B1; float r0; };          // 0x10
        union { float d; Body *s1; };                                // 0x14
        union { int i0; FloatBits tmp; float qq; };                  // 0x18
        union { int rc; float Y; float A1; };                        // 0x1c
        float d0;                                                    // 0x20
        union { float ra; float t1; };                               // 0x24
        union { float sinAB; float t2; };                            // 0x28
        Vec3 pB;                                                     // 0x2c
        union { float ra0; Vec3 *pa2; };                             // 0x38
        char pad3c[2];
        char swapped;                                                // 0x3e
        bool hit;                                                    // 0x3f
        Vec3 pA;                                                     // 0x40
        union { int j0; Vec3 *pb2; float lenSq; };                   // 0x4c
        union { Vec3 u; Vec3 qr; Vec3 negDir; };                     // 0x50
        float rb;                                                    // 0x5c
        union { float e1; float disc; };                             // 0x60
        union { Vec3 Q0; Vec3 N; };                                  // 0x64
        union { Vec3 P0; Vec3 W; };                                  // 0x70
        union { Vec3 w; Vec3 P; };                                   // 0x7c
        union { float len; FloatBits tb; };                          // 0x88
        Vec3 Q;                                                      // 0x8c
        int j;                                                       // 0x98
        union { float nd; FloatBits ad; float sd; };                 // 0x9c
        union { Vec3 *outA; int i; };                                // 0xa0
        union { Vec3 *outB; float C1; };                             // 0xa4
        union { Vec3 R; Vec3 S; };                                   // 0xa8
        FloatBits ta;                                                // 0xb4
        Vec3 hit2;                                                   // 0xb8
        FloatBits diff;                                              // 0xc4
        float cosAB;                                                 // 0xc8
        Vec3 axis;                                                   // 0xcc
        Vec3 pA2;                                                    // 0xd8
    } fr;

    fr.hit = 0;
    if (emit) {
        fr.outA = &fr.pA;
        fr.outB = &fr.pB;
    } else {
        fr.outB = 0;
        fr.outA = 0;
    }

    if (!a->b58 && !b->b58) {
        // Both short: test the end points of the two axes as spheres.
        fr.ra0 = a->f50;
        for (fr.i0 = 0; fr.i0 < 2; fr.i0++) {
            fr.rb0 = b->f50;
            for (fr.j0 = 0; fr.j0 < 2; fr.j0++) {
                fr.u.x = fr.ra0 * a->n.x;
                fr.u.y = fr.ra0 * a->n.y;
                fr.u.z = fr.ra0 * a->n.z;
                fr.w.x = fr.rb0 * b->n.x;
                fr.w.y = fr.rb0 * b->n.y;
                fr.w.z = fr.rb0 * b->n.z;
                Vec3 *ca = a->vfunc_4();
                fr.P0.x = fr.u.x + ca->x;
                fr.P0.y = fr.u.y + ca->y;
                fr.P0.z = fr.u.z + ca->z;
                Vec3 *cb = b->vfunc_4();
                fr.Q0.x = fr.w.x + cb->x;
                fr.Q0.y = fr.w.y + cb->y;
                fr.Q0.z = fr.w.z + cb->z;
                dir.x = fr.P0.x - fr.Q0.x;
                dir.y = fr.P0.y - fr.Q0.y;
                dir.z = fr.P0.z - fr.Q0.z;
                fr.len = dir.FUN_0022d110();
                if ((b->f54 + a->f54) + threshold >= fr.len
                    && !(((fr.u.z * dir.z + fr.u.y * dir.y) + fr.u.x * dir.x) > 0.0f)
                    && !(((fr.w.z * dir.z + fr.w.y * dir.y) + fr.w.x * dir.x) < 0.0f)) {
                    if (emit) {
                        float ha = -a->f54;
                        fr.pA.x = ha * dir.x + fr.P0.x;
                        fr.pA.y = ha * dir.y + fr.P0.y;
                        fr.pA.z = ha * dir.z + fr.P0.z;
                        float hb = b->f54;
                        fr.pB.x = hb * dir.x + fr.Q0.x;
                        fr.pB.y = hb * dir.y + fr.Q0.y;
                        fr.pB.z = hb * dir.z + fr.Q0.z;
                        FUN_00314be0(a, &fr.pA, b, &fr.pB, fr.len - (b->f54 + a->f54), &dir);
                    }
                    return true;
                }
                fr.rb0 = fr.rb0 * -1.0f;
            }
            fr.ra0 = fr.ra0 * -1.0f;
        }
        return fr.hit;
    }

    if (a->b58 && b->b58) {
        // Both long.
        volatile Vec3 *offw = &offset;
        volatile Vec3 *dirw = &dir;
        fr.cosAB = ((a->n.z * b->n.z + a->n.y * b->n.y) + b->n.x * a->n.x);
        fr.N.x = a->n.y * b->n.z - a->n.z * b->n.y;
        fr.N.y = a->n.z * b->n.x - b->n.z * a->n.x;
        fr.N.z = b->n.y * a->n.x - a->n.y * b->n.x;
        fr.axis = fr.N;
        fr.sinAB = fr.N.FUN_0022d110();
        fr.ra = a->f50;
        for (fr.i = 0; fr.i < 2; fr.i++) {
            fr.rb = b->f50;
            for (fr.j = 0; fr.j < 2; fr.j++, fr.rb = fr.rb * -1.0f) {
                Vec3 *ca = a->vfunc_4();
                fr.P.x = fr.ra * a->n.x + ca->x;
                fr.P.y = fr.ra * a->n.y + ca->y;
                fr.P.z = fr.ra * a->n.z + ca->z;
                Vec3 *cb = b->vfunc_4();
                fr.Q.x = fr.rb * b->n.x + cb->x;
                fr.Q.y = fr.rb * b->n.y + cb->y;
                fr.Q.z = fr.rb * b->n.z + cb->z;
                offw->x = fr.P.x - fr.Q.x;
                offw->y = fr.P.y - fr.Q.y;
                offw->z = fr.P.z - fr.Q.z;
                if ((fr.rb * fr.ra) * fr.cosAB > 0.0f)
                    continue;

                float hmax = a->f54 < b->f54 ? b->f54 : a->f54;
                if (fr.sinAB < threshold / hmax) {
                    // Nearly parallel axes.
                    float s = fr.rb < 0.0f ? -1.0f : (fr.rb > 0.0f ? 1.0f : 0.0f);
                    dirw->x = s * b->n.x;
                    dirw->y = s * b->n.y;
                    dirw->z = s * b->n.z;
                    fr.d = ((dir.z * offset.z + dir.y * offset.y) + dir.x * offset.x);
                    if (!(fr.d < threshold))
                        continue;
                    float rmin = a->f50 < b->f50 ? a->f50 : b->f50;
                    if (!(rmin + rmin > -fr.d))
                        continue;
                    fr.Q.x = fr.d * dir.x + fr.Q.x;
                    fr.Q.y = fr.d * dir.y + fr.Q.y;
                    fr.Q.z = fr.d * dir.z + fr.Q.z;
                    int rc;
                    if (a->f54 < b->f54)
                        rc = FUN_00314a10(&fr.P, &fr.Q, &a->n, a->f54, b->f54, 1, &fr.pA, &fr.pA2);
                    else
                        rc = FUN_00314a10(&fr.Q, &fr.P, &b->n, b->f54, a->f54, 1, &fr.pA, &fr.pA2);
                    fr.rc = rc;
                    if (rc == -1)
                        continue;
                    if (emit) {
                        fr.nd = -fr.d;
                        fr.pB.x = fr.nd * dir.x + fr.pA.x;
                        fr.pB.y = fr.nd * dir.y + fr.pA.y;
                        fr.pB.z = fr.nd * dir.z + fr.pA.z;
                        FUN_00314be0(a, &fr.pA, b, &fr.pB, fr.d, &dir);
                        if (fr.rc == 2) {
                            fr.pB.FUN_001f6bc0(&fr.pA2, fr.nd, &dir);
                            FUN_00314be0(a, &fr.pA2, b, &fr.pB, fr.d, &dir);
                        }
                    }
                    return true;
                }

                // Separation along each axis, beyond the other body's reach.
                fr.ta.f = ((a->n.z * offset.z + a->n.y * offset.y) + a->n.x * offset.x);
                fr.ta.u &= 0x7fffffff;
                float sa = fr.ta.f - fr.sinAB * b->f54;
                if (sa > threshold)
                    continue;
                fr.tb.f = ((b->n.z * offset.z + b->n.y * offset.y) + offset.x * b->n.x);
                fr.tb.u &= 0x7fffffff;
                float sb = fr.tb.f - fr.sinAB * a->f54;
                if (sb > threshold)
                    continue;
                if (sa <= sb) {
                    fr.swapped = 1;
                    float s = FUN_00083d90(&fr.rb);
                    dirw->x = s * b->n.x;
                    dirw->y = s * b->n.y;
                    dirw->z = s * b->n.z;
                } else {
                    fr.swapped = 0;
                    float s = FUN_00083d90(&fr.ra);
                    dirw->x = s * a->n.x;
                    dirw->y = s * a->n.y;
                    dirw->z = s * a->n.z;
                    offw->x = offset.x * -1.0f;
                    offw->y = offset.y * -1.0f;
                    offw->z = offset.z * -1.0f;
                }

                // Closest points of the two axes.
                FUN_003148c0(&fr.P, &fr.Q, &a->n, &b->n, &fr.R, &fr.axis, false);
                float px = fr.P.x - fr.R.x;
                float py = fr.P.y - fr.R.y;
                float pz = fr.P.z - fr.R.z;
                fr.qr.x = fr.Q.x - fr.R.x;
                fr.qr.y = fr.Q.y - fr.R.y;
                fr.qr.z = fr.Q.z - fr.R.z;
                fr.e1 = ((px * fr.N.x + pz * fr.N.z) + py * fr.N.y);
                fr.e2 = ((fr.qr.x * fr.N.x + fr.qr.z * fr.N.z) + fr.qr.y * fr.N.y);
                float da = ((px * px + pz * pz) + py * py) - fr.e1 * fr.e1;
                fr.Y = ((fr.qr.x * fr.qr.x + fr.qr.z * fr.qr.z) + fr.qr.y * fr.qr.y) - fr.e2 * fr.e2;
                if (!(0.0f < da))
                    da = 0.0f;
                if (!(0.0f < fr.Y))
                    fr.Y = 0.0f;
                float za = a->f54 * a->f54 - da;
                za = za > 0.0f ? (float)sqrt(za) : 0.0f;
                float zb = b->f54 * b->f54 - fr.Y;
                zb = zb > 0.0f ? (float)sqrt(zb) : 0.0f;
                fr.diff.f = fr.e1 - fr.e2;
                fr.ad.u = fr.diff.u & 0x7fffffff;
                if (!(fr.ad.f - (zb + za) < threshold))
                    continue;

                Body *s2;
                if (fr.swapped) {
                    s2 = a;
                    fr.s1 = b;
                    fr.pb2 = &fr.P;
                    fr.pa2 = &fr.Q;
                } else {
                    s2 = b;
                    fr.s1 = a;
                    fr.pb2 = &fr.Q;
                    fr.pa2 = &fr.P;
                }
                float c = 1.0f - fr.sinAB * fr.sinAB;
                c = c > 0.0f ? (float)sqrt(c) : 0.0f;
                fr.rc = FUN_00314a10(fr.pa2, fr.pb2, &fr.s1->n, fr.s1->f54, c * s2->f54, 1, &fr.pA, &fr.hit2);
                if (fr.rc == 1 || fr.rc == 2) {
                    fr.pB.x = fr.pA.x - fr.pa2->x;
                    fr.pB.y = fr.pA.y - fr.pa2->y;
                    fr.pB.z = fr.pA.z - fr.pa2->z;
                    fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                }
                if ((fr.rc == 1 || fr.rc == 2) && fr.d0 < threshold && fr.sinAB < 0.5f) {
                    if (!emit)
                        return true;
                    fr.pB.FUN_001f6bc0(&fr.pA, -fr.d0, &dir);
                    FUN_00314be0(s2, &fr.pA, fr.s1, &fr.pB, fr.d0, &dir);
                }
                if (fr.rc == 2) {
                    fr.pB.x = fr.hit2.x - fr.pa2->x;
                    fr.pB.y = fr.hit2.y - fr.pa2->y;
                    fr.pB.z = fr.hit2.z - fr.pa2->z;
                    fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                    if (fr.d0 < threshold && fr.sinAB < 0.5f) {
                        if (!emit)
                            return true;
                        fr.pB.FUN_001f6bc0(&fr.hit2, -fr.d0, &dir);
                        FUN_00314be0(s2, &fr.hit2, fr.s1, &fr.pB, fr.d0, &dir);
                    }
                }

                // Points of s2's axis at the distance s1's radius from s1's axis: solve the quadratic.
                fr.W.x = fr.N.z * s2->n.y - fr.N.y * s2->n.z;
                fr.W.y = fr.N.x * s2->n.z - fr.N.z * s2->n.x;
                fr.W.z = fr.N.y * s2->n.x - fr.N.x * s2->n.y;
                fr.W.FUN_0022d110();
                Body *s1 = fr.s1;
                float p = ((fr.W.z * s1->n.z + fr.W.y * s1->n.y) + fr.W.x * s1->n.x);
                float q = ((s1->n.z * offset.z + s1->n.y * offset.y) + offset.x * s1->n.x);
                fr.A1 = ((1.0f - p * p) * s2->f54) * s2->f54;
                float r = ((fr.W.z * offset.z + fr.W.y * offset.y) + fr.W.x * offset.x);
                fr.B1 = ((r - q * p) * s2->f54) * 2.0f;
                fr.C1 = (((offset.z * offset.z + offset.y * offset.y) + offset.x * offset.x) - q * q) - s1->f54 * s1->f54;
                float ac = fr.C1 * fr.A1;
                fr.disc = (fr.B1 * fr.B1) - (ac * 4.0f);
                fr.tmp.f = ac;
                fr.tmp.u &= 0x7fffffff;
                if (fr.tmp.f < 9.99999997e-007f) {
                    bool solved = false;
                    if (fr.disc >= 0.0f) {
                        float sg = FUN_00083d90(&fr.B1);
                        fr.sd = (float)sqrt(fr.disc);
                        fr.qq = ((fr.sd * sg) + fr.B1) * -2.0f;
                        if (fr.qq != 0.0f && fr.A1 != 0.0f) {
                            fr.t1 = fr.qq / fr.A1;
                            fr.t2 = fr.C1 / fr.qq;
                            solved = true;
                        }
                    }
                    if (!solved) {
                        fr.t2 = 0.0f;
                        fr.t1 = 0.0f;
                        if (offset.FUN_00018990() < fr.s1->f54) {
                            fr.t1 = 1.0f;
                            fr.t2 = -1.0f;
                        }
                    }
                } else {
                    if (!(fr.disc >= 0.0f))
                        continue;
                    float root = (float)sqrt(fr.disc);
                    float inv = 1.0f / fr.A1;
                    fr.t1 = ((root - fr.B1) * inv) * 0.5f;
                    fr.t2 = ((-fr.B1 - root) * inv) * 0.5f;
                }
                fr.tmp.f = fr.t1;
                fr.tmp.u &= 0x7fffffff;
                if (!(fr.tmp.f <= 1.0f))
                    fr.t1 = FUN_00083d90(&fr.t1);
                fr.tmp.f = fr.t2;
                fr.tmp.u &= 0x7fffffff;
                if (!(fr.tmp.f <= 1.0f))
                    fr.t2 = FUN_00083d90(&fr.t2);

                                float s = fr.t1 * s2->f54;
                fr.pA.x = fr.W.x * s + fr.pb2->x;
                fr.pA.y = fr.W.y * s + fr.pb2->y;
                fr.pA.z = fr.W.z * s + fr.pb2->z;
                fr.pB.x = fr.pA.x - fr.pa2->x;
                fr.pB.y = fr.pA.y - fr.pa2->y;
                fr.pB.z = fr.pA.z - fr.pa2->z;
                fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                if (fr.d0 < threshold) {
                    if (!emit)
                        return true;
                    fr.pB.FUN_001f6bc0(&fr.pA, -fr.d0, &dir);
                    FUN_00314be0(s2, &fr.pA, fr.s1, &fr.pB, fr.d0, &dir);
                }
                s = fr.t2 * s2->f54;
                fr.pA.x = fr.W.x * s + fr.pb2->x;
                fr.pA.y = fr.W.y * s + fr.pb2->y;
                fr.pA.z = fr.W.z * s + fr.pb2->z;
                fr.pB.x = fr.pA.x - fr.pa2->x;
                fr.pB.y = fr.pA.y - fr.pa2->y;
                fr.pB.z = fr.pA.z - fr.pa2->z;
                fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                if (fr.d0 < threshold && emit) {
                    fr.pB.FUN_001f6bc0(&fr.pA, -fr.d0, &dir);
                    FUN_00314be0(s2, &fr.pA, fr.s1, &fr.pB, fr.d0, &dir);
                }
                return true;
            }
            fr.ra = fr.ra * -1.0f;
        }
        return fr.hit;
    }

    // One long body (lng) and one short one (sht): test the short body's end points.
    Body *lng = a;
    Body *sht = b;
    if (b->b58) {
        offset.x = offset.x * -1.0f;
        offset.y = offset.y * -1.0f;
        offset.z = offset.z * -1.0f;
        lng = b;
        sht = a;
    }
    fr.r0 = sht->f50;
    for (fr.j = 0; fr.j < 2; fr.j++) {
        Vec3 *cs = sht->vfunc_4();
        fr.S.x = fr.r0 * sht->n.x + cs->x;
        fr.S.y = fr.r0 * sht->n.y + cs->y;
        fr.S.z = fr.r0 * sht->n.z + cs->z;
        Vec3 *cl = lng->vfunc_4();
        offset.x = cl->x - fr.S.x;
        offset.y = cl->y - fr.S.y;
        offset.z = cl->z - fr.S.z;
        fr.lenSq = ((offset.z * offset.z + offset.y * offset.y) + offset.x * offset.x);
        if (FUN_00314430(lng, &fr.S, sht->f54, &dir, &fr.lenSq, fr.outA, fr.outB, mode)) {
            fr.hit = 1;
            if (!emit)
                return true;
            if (lng == a) {
                FUN_00314be0(lng, &fr.pA, sht, &fr.pB, fr.lenSq, &dir);
            } else {
                fr.negDir = dir;
                fr.negDir.x = fr.negDir.x * -1.0f;
                fr.negDir.y = fr.negDir.y * -1.0f;
                fr.negDir.z = fr.negDir.z * -1.0f;
                FUN_00314be0(sht, &fr.pB, lng, &fr.pA, fr.lenSq, &fr.negDir);
            }
        }
        fr.r0 = fr.r0 * -1.0f;
    }
    return fr.hit;
}
