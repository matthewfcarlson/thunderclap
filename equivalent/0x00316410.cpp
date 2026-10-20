// STATUS: equivalent (tools/equiv.py level 3: 3081 inputs, branch coverage 99/104, incomplete)
// FUN_00316410 @ 0x00316410
// FUN_00316410 @ 0x00316410
// Resolver::FUN_00316410 (this=ecx, ret 0x20): contact emitter for a swept disc/segment against body b
// (axis b->n, half length f50, radius f54). Four cases: moving along b's axis, moving across it, the
// two-sided sweep (inside && sweep), and the general case that tests both ends of b.
// The locals live in one Frame at the original's stack slots (several slots hold different values in
// different blocks), because the callees get pointers into it.
extern "C" double __cdecl sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000110d0(const Vec3 *v);
    void FUN_00011110(const Vec3 *a, const Vec3 *b);
    void FUN_00011140(float s);
    void FUN_00011160(float s, const Vec3 *v);
    void FUN_000111b0(const Vec3 *a, const Vec3 *b);
    void FUN_00034440(const Vec3 *a, const Vec3 *b);
    void FUN_00095e80(float s, const Vec3 *v);
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
float __cdecl FUN_000186f0(float *a, float *b);

class Resolver {
public:
    char pad00[0x0c];
    float threshold;                 // 0x0c
    char pad10[4];
    Vec3 offset;                     // 0x14
    Vec3 dir;                        // 0x20
    void FUN_00314be0(Body *a, Vec3 *pa, Body *b, Vec3 *pb, float depth, Vec3 *dir);
    void FUN_00316410(Body *a, Vec3 *vel, Vec3 *axis, float range, Body *b, float lat0, float lat, bool sweep);
};

// |v| through a frame slot, as the original does it (store, mask the sign bit, reload).
static __forceinline float AbsIn(FloatBits &slot, float v)
{
    slot.f = v;
    slot.u &= 0x7fffffff;
    return slot.f;
}

void Resolver::FUN_00316410(Body *a, Vec3 *vel, Vec3 *axis, float range, Body *b, float lat0, float lat, bool sweep)
{
    // Stack frame at the original's offsets from esp after `sub esp, 0x88`.
    struct Frame {
        union { Vec3 *off; FloatBits w; } s00;                       // 0x00
        FloatBits s04;                                               // 0x04
        FloatBits s08;                                               // 0x08
        FloatBits s0c;                                               // 0x0c
        FloatBits s10;                                               // 0x10
        Vec3 P;                                                      // 0x14
        FloatBits s20;                                               // 0x20
        Resolver *self;                                              // 0x24
        char pad28[3];
        bool inside;                                                 // 0x2b
        union { float pa; int count; float side; };                  // 0x2c
        union { float dp; float dist; float c2; };                   // 0x30
        union { float pm; float spa; };                              // 0x34
        union { float pp; int i; };                                  // 0x38
        union { Vec3 Q; Vec3 T; };                                   // 0x3c
        union { float sup; float sv; };                              // 0x48
        union { Vec3 R; Vec3 Y; };                                   // 0x4c
        Vec3 U;                                                      // 0x58
        Vec3 X;                                                      // 0x64
        float sin2;                                                  // 0x70
        float un;                                                    // 0x74
        float scn;                                                   // 0x78
        Vec3 Z;                                                      // 0x7c
    } fr;

    fr.self = this;
    if (range <= 9.99999997e-007f)
        return;
    fr.s00.off = &offset;
    if (((offset.z * vel->z + offset.y * vel->y) + offset.x * vel->x) > 0.0f) {
        vel->x = vel->x * -1.0f;
        vel->y = vel->y * -1.0f;
        vel->z = vel->z * -1.0f;
    }
    fr.s0c.f = ((b->n.z * axis->z + b->n.y * axis->y) + axis->x * b->n.x);
    fr.s04.u = fr.s0c.u & 0x7fffffff;                      // |cos| of the sweep axis to b's axis
    fr.s0c.f = ((b->n.z * vel->z + b->n.y * vel->y) + b->n.x * vel->x) + lat0;
    fr.s0c.u &= 0x7fffffff;
    if (!(fr.s0c.f - (AbsIn(fr.s08, lat) + b->f50) <= threshold))
        return;
    fr.inside = AbsIn(fr.s08, lat) + fr.s0c.f < b->f50;

    if (fr.s04.f >= 0.999f && !fr.inside) {
        // Sweeping along b's axis.
        fr.P.x = fr.s00.off->x + vel->x;
        fr.P.y = fr.s00.off->y + vel->y;
        fr.P.z = fr.s00.off->z + vel->z;
        lat = ((fr.P.z * b->n.z + fr.P.y * b->n.y) + fr.P.x * b->n.x);   // the dead argument slot holds the axial distance
        fr.s10.f = (AbsIn(fr.s08, lat) - range) - b->f50;
        if (!(fr.s10.f <= threshold))
            return;
        float sq = ((fr.P.x * fr.P.x + fr.P.z * fr.P.z) + fr.P.y * fr.P.y) - lat * lat;
        float r = threshold + b->f54;
        if (!(sq <= r * r))
            return;
        if (sq >= 9.99999997e-007f && sq < fr.s10.f * fr.s10.f) {
            fr.self->dir.FUN_001f6bc0(&fr.P, -lat, &b->n);
            fr.s0c.f = ((fr.self->dir.z * vel->z + fr.self->dir.y * vel->y) + fr.self->dir.x * vel->x);
            vel->FUN_001f6bc0(&fr.self->dir, FUN_00083d90(&lat) * b->f50, &b->n);
            vel->FUN_000110d0(b->vfunc_4());
            fr.s10.f = fr.self->dir.FUN_0022d110();
            if (!(FUN_00083d90(&fr.s0c.f) < 0.0f)
                && !(((fr.s00.off->z * fr.self->dir.z + fr.s00.off->y * fr.self->dir.y) + fr.s00.off->x * fr.self->dir.x) > 0.0f)) {
                fr.s10.f = -(fr.s10.f + b->f54);
                fr.self->dir.x = fr.self->dir.x * -1.0f;
                fr.self->dir.y = fr.self->dir.y * -1.0f;
                fr.self->dir.z = fr.self->dir.z * -1.0f;
            } else {
                fr.s10.f = fr.s10.f - b->f54;
            }
            fr.P.FUN_001f6bc0(vel, -fr.s10.f, &fr.self->dir);
        } else {
            fr.s0c.f = FUN_00083d90(&lat);
            fr.s00.w.f = ((fr.P.x * axis->x + fr.P.z * axis->z) + fr.P.y * axis->y);
            vel->FUN_001f6bc0(&fr.P, -(FUN_00083d90(&fr.s00.w.f) * range), axis);
            vel->FUN_000110d0(b->vfunc_4());
            fr.P.FUN_001f6bc0(vel, -(fr.s0c.f * fr.s10.f), &b->n);
            fr.self->dir.FUN_00095e80(fr.s0c.f, &b->n);
        }
        fr.self->FUN_00314be0(a, vel, b, &fr.P, fr.s10.f, &fr.self->dir);
        return;
    }

    if (fr.s04.f / range <= 0.001f) {
        // Sweeping across b's axis.
        fr.P.x = fr.s00.off->x + vel->x;
        fr.P.y = fr.s00.off->y + vel->y;
        fr.P.z = fr.s00.off->z + vel->z;
        fr.dp = ((fr.P.z * b->n.z + fr.P.y * b->n.y) + fr.P.x * b->n.x);
        fr.s08.f = AbsIn(fr.s08, fr.dp) - b->f50;
        if (!(fr.s08.f <= threshold))
            return;
        fr.self->dir.FUN_000111b0(&b->n, axis);
        fr.s0c.f = ((fr.P.z * fr.self->dir.z + fr.P.y * fr.self->dir.y) + fr.P.x * fr.self->dir.x);
        fr.s10.u = fr.s0c.u & 0x7fffffff;
        float r = fr.self->threshold + b->f54;
        if (!(fr.s10.f <= r))
            return;
        float hh = r * r - fr.s10.f * fr.s10.f;
        if (hh < 0.0f)
            return;
        fr.s20.f = (float)sqrt(hh);
        fr.pa = ((fr.P.x * axis->x + fr.P.z * axis->z) + fr.P.y * axis->y);
        fr.pp = fr.pa + range;
        fr.pm = fr.pa - range;
        fr.s0c.f = fr.pm * fr.pp;
        fr.s00.w.f = FUN_00083d90(&fr.s0c.f);
        if (!(fr.s00.w.f < 0.0f)) {
            if (!(AbsIn(fr.s04, fr.pp) <= fr.s20.f) && !(AbsIn(fr.s04, fr.pm) <= fr.s20.f))
                return;
        }
        fr.s10.f = fr.s10.f - b->f54;
        if ((!(fr.s10.f > fr.s08.f) && !(AbsIn(fr.s04, fr.s08.f / b->f50) > 0.1f))
            || !(AbsIn(fr.s04, fr.s20.f - b->f54) >= 9.99999997e-007f)) {
            // Touching b's side.
            if (AbsIn(fr.s04, fr.pa) <= fr.s20.f) {
                *vel = fr.P;
            } else {
                fr.s04.f = fr.pm;
                fr.s0c.f = fr.pp;
                fr.s04.u &= 0x7fffffff;
                fr.s0c.u &= 0x7fffffff;
                fr.s0c.f = range - (fr.s20.f - FUN_000186f0(&fr.s0c.f, &fr.s04.f) * fr.s00.w.f);
                vel->FUN_001f6bc0(&fr.P, -(FUN_00083d90(&fr.pa) * fr.s0c.f), axis);
            }
            vel->FUN_000110d0(b->vfunc_4());
            fr.self->dir.FUN_00095e80(FUN_00083d90(&fr.dp), &b->n);
            fr.P.FUN_00095e80(-fr.s08.f, &fr.self->dir);
            fr.P.x = fr.P.x + vel->x;
            fr.P.y = fr.P.y + vel->y;
            fr.P.z = fr.P.z + vel->z;
            fr.self->FUN_00314be0(a, vel, b, &fr.P, fr.s08.f, &fr.self->dir);
            return;
        }
        if (fr.s00.w.f > 0.0f) {
            // Hitting b's end cap.
            vel->FUN_001f6bc0(&fr.P, (AbsIn(fr.s04, fr.pp) < AbsIn(fr.s08, fr.pm) ? 1.0f : -1.0f) * range, axis);
            fr.P.FUN_00095e80(fr.dp, &b->n);
            fr.self->dir.FUN_00011110(vel, &fr.P);
            fr.s10.f = fr.self->dir.FUN_0022d110() - b->f54;
            vel->FUN_000110d0(b->vfunc_4());
            Vec3 *c = b->vfunc_4();
            fr.P.x = fr.P.x + c->x;
            fr.P.y = fr.P.y + c->y;
            fr.P.z = fr.P.z + c->z;
            fr.P.FUN_00011160(b->f54, &fr.self->dir);
        } else {
            // Hitting b's rim.
            if (((fr.P.z * fr.self->dir.z + fr.P.y * fr.self->dir.y) + fr.P.x * fr.self->dir.x) < 0.0f) {
                fr.self->dir.x = fr.self->dir.x * -1.0f;
                fr.self->dir.y = fr.self->dir.y * -1.0f;
                fr.self->dir.z = fr.self->dir.z * -1.0f;
            }
            vel->FUN_001f6bc0(b->vfunc_4(), fr.dp, &b->n);
            vel->FUN_00011160(fr.s10.f + b->f54, &fr.self->dir);
            fr.P.FUN_001f6bc0(b->vfunc_4(), FUN_00083d90(&fr.dp) * b->f50, &b->n);
            fr.P.FUN_00011160(b->f54, &fr.self->dir);
        }
        fr.self->FUN_00314be0(a, vel, b, &fr.P, fr.s10.f, &fr.self->dir);
        return;
    }

    if (fr.inside && sweep) {
        // Swept both ways along the axis.
        fr.P.FUN_00034440(fr.s00.off, vel);
        for (fr.count = 2; fr.count != 0; range = range * -1.0f, fr.count--) {
            fr.Q.x = range * axis->x + fr.P.x;
            fr.Q.y = range * axis->y + fr.P.y;
            fr.Q.z = range * axis->z + fr.P.z;
            fr.s04.f = ((fr.Q.z * b->n.z + fr.Q.y * b->n.y) + fr.Q.x * b->n.x);
            float s2 = ((fr.Q.x * fr.Q.x + fr.Q.z * fr.Q.z) + fr.Q.y * fr.Q.y) - fr.s04.f * fr.s04.f;
            float rr = s2 > 0.0f ? (float)sqrt(s2) : 0.0f;
            fr.s08.f = AbsIn(fr.s00.w, fr.s04.f) - b->f50;
            fr.dist = rr - b->f54;
            if (!(fr.dist < fr.self->threshold))
                continue;
            fr.s0c.f = FUN_00083d90(&fr.s04.f);
            Vec3 *c = b->vfunc_4();
            vel->x = fr.Q.x + c->x;
            vel->y = fr.Q.y + c->y;
            vel->z = fr.Q.z + c->z;
            if (fr.s08.f > fr.dist) {
                fr.self->dir = b->n;
                fr.self->dir.FUN_00011140(fr.s0c.f);
                fr.R.FUN_001f6bc0(vel, AbsIn(fr.s04, fr.s08.f) * fr.s0c.f, &b->n);
            } else {
                fr.self->dir.FUN_001f6bc0(&fr.Q, -fr.s04.f, &b->n);
                fr.self->dir.FUN_0022d110();
                fr.R.FUN_001f6bc0(b->vfunc_4(), fr.s04.f, &b->n);
                fr.R.FUN_00011160(b->f54, &fr.self->dir);
                fr.s08.f = fr.dist;
            }
            fr.self->FUN_00314be0(a, vel, b, &fr.R, fr.s08.f, &fr.self->dir);
        }
        return;
    }

    // General case: test both ends of b.
    fr.P.x = fr.s00.off->x + vel->x;
    fr.P.y = fr.s00.off->y + vel->y;
    fr.P.z = fr.s00.off->z + vel->z;
    fr.s08.f = ((fr.P.z * b->n.z + fr.P.y * b->n.y) + fr.P.x * b->n.x);
    fr.s04.f = FUN_00083d90(&fr.s08.f);
    fr.s00.w.f = ((b->n.z * axis->z + b->n.y * axis->y) + axis->x * b->n.x);
    fr.s0c.f = ((fr.P.x * axis->x + fr.P.z * axis->z) + fr.P.y * axis->y);
    fr.spa = FUN_00083d90(&fr.s0c.f);
    fr.scn = FUN_00083d90(&fr.s00.w.f);
    fr.c2 = fr.s00.w.f * fr.s00.w.f;
    fr.sin2 = 1.0f - fr.c2;
    for (fr.i = 0; fr.i < 2; fr.i++) {
        float L = fr.i == 0 ? b->f50 - fr.s08.f : fr.s08.f + b->f50;
        if (fr.c2 == 0.0f)
            continue;
        fr.s20.f = L * ((fr.sin2 / fr.c2 + 1.0f) * L);
        if (!(fr.s20.f < range * range))
            continue;
        float g = -(fr.scn * fr.s04.f);
        if (AbsIn(fr.s00.w, fr.s08.f) < b->f50
            && ((fr.s04.f > 0.0f && fr.i == 0) || (fr.s04.f < 0.0f && fr.i == 1)))
            g = g * -1.0f;
        float w = g * (float)sqrt(fr.s20.f);
        vel->x = w * axis->x;
        vel->y = w * axis->y;
        vel->z = w * axis->z;
        fr.s00.w.f = fr.P.x + vel->x;
        vel->x = fr.s00.w.f;
        vel->y = fr.P.y + vel->y;
        vel->z = fr.P.z + vel->z;
        fr.s20.f = ((vel->z * b->n.z + vel->y * b->n.y) + fr.s00.w.f * b->n.x);
        float e = -(FUN_00083d90(&fr.s20.f) * b->f50);
        fr.self->dir.x = e * b->n.x + fr.s00.w.f;
        fr.self->dir.y = e * b->n.y + vel->y;
        fr.self->dir.z = e * b->n.z + vel->z;
        float dl = ((fr.self->dir.z * fr.self->dir.z + fr.self->dir.y * fr.self->dir.y) + fr.self->dir.x * fr.self->dir.x);
        float r = fr.self->threshold + b->f54;
        if (!(dl < r * r))
            continue;
        fr.s00.w.f = (float)sqrt(dl);
        if (fr.c2 < 0.5f) {
            fr.T.FUN_000111b0(axis, &b->n);
            fr.T.FUN_0022d110();
            fr.s00.w.f = ((fr.T.x * fr.P.x + fr.T.z * fr.P.z) + fr.T.y * fr.P.y);
            if (FUN_00083d90(&fr.s00.w.f) < 0.0f) {
                fr.T.x = fr.T.x * -1.0f;
                fr.T.y = fr.T.y * -1.0f;
                fr.T.z = fr.T.z * -1.0f;
                fr.U.FUN_000111b0(&fr.T, &b->n);
            } else {
                fr.U.FUN_000111b0(&b->n, &fr.T);
            }
            fr.U.FUN_0022d110();
            fr.un = ((fr.U.z * axis->z + fr.U.y * axis->y) + fr.U.x * axis->x);
            float rad = fr.self->threshold + b->f54;
            fr.s00.w.f = fr.s00.w.f * fr.s00.w.f;
            if (rad * rad - fr.s00.w.f <= 0.0f)
                continue;
            fr.s00.w.f = (float)sqrt(rad * rad - fr.s00.w.f);
            fr.s20.f = ((fr.U.x * fr.P.x + fr.U.z * fr.P.z) + fr.U.y * fr.P.y);
            fr.sup = FUN_00083d90(&fr.s20.f);
            fr.s10.f = fr.s20.f;
            fr.s20.u &= 0x7fffffff;
            fr.side = fr.s20.f > fr.s00.w.f ? -1.0f : 1.0f;
            float z = fr.s20.f - fr.side * fr.s00.w.f;
            fr.s0c.f = z;
            fr.s0c.u &= 0x7fffffff;
            float inv = 1.0f / fr.un;
            fr.s20.f = ((fr.s00.w.f + fr.s00.w.f) - fr.s0c.f) * inv;
            fr.s10.f = z * inv;
            if (AbsIn(fr.s00.w, fr.s20.f) > range)
                fr.s20.f = FUN_00083d90(&fr.s20.f) * range;
            if (AbsIn(fr.s00.w, fr.s10.f) > range)
                fr.s10.f = FUN_00083d90(&fr.s10.f) * range;
            if (fr.sup * fr.spa > 0.0f) {
                fr.X.FUN_001f6bc0(&fr.P, -((fr.s20.f * fr.side) * fr.spa), axis);
                fr.Y.FUN_001f6bc0(&fr.P, -(fr.s10.f * fr.spa), axis);
            } else {
                fr.X.FUN_001f6bc0(&fr.P, (fr.s20.f * fr.side) * fr.spa, axis);
                fr.Y.FUN_001f6bc0(&fr.P, fr.s10.f * fr.spa, axis);
            }
            fr.sv = ((b->n.z * vel->z + b->n.y * vel->y) + b->n.x * vel->x);
            fr.s00.w.f = FUN_00083d90(&fr.sv);
            fr.self->dir.FUN_00095e80(fr.s00.w.f, &b->n);
            fr.s20.f = ((fr.X.z * b->n.z + fr.X.y * b->n.y) + fr.X.x * b->n.x) * fr.s00.w.f - b->f50;
            if (fr.s20.f < fr.self->threshold * 1.03f) {
                *vel = fr.X;
            } else {
                *vel = fr.Y;
                fr.s20.f = ((fr.Y.z * b->n.z + fr.Y.y * b->n.y) + fr.Y.x * b->n.x) * fr.s00.w.f - b->f50;
                if (fr.s20.f >= fr.self->threshold * 1.03f)
                    continue;
            }
            vel->FUN_000110d0(b->vfunc_4());
        } else {
            vel->FUN_000110d0(b->vfunc_4());
            if (fr.s00.w.f != 0.0f)
                fr.self->dir.FUN_00011140(1.0f / fr.s00.w.f);
            else
                fr.self->dir = b->n;
            fr.s20.f = fr.s00.w.f - b->f54;
        }
        fr.Z.FUN_001f6bc0(vel, -fr.s20.f, &fr.self->dir);
        fr.self->FUN_00314be0(a, vel, b, &fr.Z, fr.s20.f, &fr.self->dir);
    }
}
