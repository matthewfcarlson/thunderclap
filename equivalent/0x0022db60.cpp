// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_0022db60 @ 0x0022db60
extern "C" double sqrt(double);

struct V3_22db60 {
    float x, y, z;
};

union Slot_22db60 {
    V3_22db60 *v;
    float *fp;
    float f;
    unsigned char b;
};

struct Frame_22db60 {
    float uu;
    float t[3];
    float R[3];
    float Rp[3];
    float pad38;
    float Qy;
    float Qz;
};

bool __cdecl FUN_0022db60(Slot_22db60 a1, Slot_22db60 a2, Slot_22db60 a3, V3_22db60 *a4, float a5, Slot_22db60 a6, float *a7)
{
    Frame_22db60 f;
    V3_22db60 *u = a2.v;
    V3_22db60 *p3 = a3.v;
    V3_22db60 *p1 = a1.v;
    V3_22db60 *c = a4;

    a1.b = 1;
    f.t[0] = p1->x - p3->x;
    f.t[1] = p1->y - p3->y;
    f.t[2] = p1->z - p3->z;
    f.uu = u->x * u->x + u->y * u->y + u->z * u->z;
    double ud = u->x * c->x + u->z * c->z + u->y * c->y;
    a2.f = c->x * c->x + c->y * c->y + c->z * c->z;
    double e = f.t[0] * u->x + f.t[1] * u->y + f.t[2] * u->z;
    a3.f = f.t[0] * c->x + f.t[1] * c->y + f.t[2] * c->z;

    if (ud < 0.0f) {
        ud = -ud;
        a1.b = 0;
        a3.f = -a3.f;
    }

    double den = a2.f * f.uu - ud * ud;
    float *out6;
    float *out7;
    if (den < 1e-05f) {
        double s;
        if (ud > a2.f)
            s = e / ud;
        else
            s = a3.f / a2.f;
        out7 = a7;
        out6 = a6.fp;
        *out7 = (float)s;
        if (s > 0.0f) {
            *out6 = 0.0f;
        } else {
            *out6 = (float)-s;
            *out7 = 0.0f;
        }
    } else {
        double inv = 1.0f / den;
        out6 = a6.fp;
        out7 = a7;
        *out6 = (float)((a3.f * ud - e * a2.f) * inv);
        *out7 = (float)((a3.f * f.uu - e * ud) * inv);
    }

    double p = *out6;
    bool sgn = a1.b != 0;
    f.t[1] = p * u->y;
    f.t[2] = p * u->z;
    double qx = p * u->x + p1->x;
    f.Qy = f.t[1] + p1->y;
    f.Qz = f.t[2] + p1->z;

    float *r;
    double q = *out7;
    if (sgn) {
        f.t[1] = q * c->y;
        f.t[2] = q * c->z;
        f.R[0] = q * c->x + p3->x;
        f.R[1] = f.t[1] + p3->y;
        f.R[2] = f.t[2] + p3->z;
        r = f.R;
    } else {
        f.R[1] = q * c->y;
        f.R[2] = q * c->z;
        f.Rp[0] = p3->x - q * c->x;
        f.Rp[1] = p3->y - f.R[1];
        f.Rp[2] = p3->z - f.R[2];
        r = f.Rp;
    }

    f.t[0] = r[0];
    double dx = f.t[0] - qx;
    f.t[1] = r[1];
    double dy = f.t[1] - f.Qy;
    f.t[2] = r[2];
    double dz = f.t[2] - f.Qz;
    double dist = sqrt(dz * dz + dy * dy + dx * dx);
    a6.f = (float)dist;
    if (dist > a5)
        return false;

    double wx, wy, wz;
    if (sgn) {
        wx = c->x - u->x;
        wy = c->y - u->y;
        wz = c->z - u->z;
    } else {
        wx = u->x + c->x;
        wy = u->y + c->y;
        wz = u->z + c->z;
    }
    double norm = sqrt(wz * wz + wy * wy + wx * wx);
    double h = sqrt(a5 * a5 - a6.f * a6.f);
    double rr = h / norm;
    *out6 = *out6 - rr;
    if (sgn)
        *out7 = *out7 - rr;
    else
        *out7 = rr - *out7;
    return true;
}
