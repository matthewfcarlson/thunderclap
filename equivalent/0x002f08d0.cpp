// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 53/54, incomplete)
// FUN_002f08d0 @ 0x002f08d0
extern "C" double sqrt(double);
struct V3_2f08d0 {
    float x, y, z;
};

extern "C" float __cdecl FUN_00083d90(float *v);

union FBits_2f08d0 {
    float f;
    unsigned int u;
};

// Segment (p -> p + dir) vs sphere around q: finds the entry point.
bool FUN_002f08d0(V3_2f08d0 *p, V3_2f08d0 *q, V3_2f08d0 *dir, float tol, float radius, V3_2f08d0 *out)
{
    float c0 = p->x * p->x + p->y * p->y + p->z * p->z;
    float dot0 = p->y * dir->y + p->x * dir->x + p->z * dir->z;
    float r2 = radius * radius;
    FBits_2f08d0 ab;
    ab.f = dot0;
    ab.u &= 0x7fffffff;
    bool cl = ab.f > tol;

    if (c0 <= r2 && !cl) {
        out->x = p->x;
        out->y = p->y;
        out->z = p->z;
        return true;
    }

    V3_2f08d0 diff;
    diff.x = q->x - p->x;
    diff.y = q->y - p->y;
    diff.z = q->z - p->z;
    float e = q->y * dir->y + q->x * dir->x + q->z * dir->z;

    V3_2f08d0 P;
    if (cl) {
        if (e * dot0 > 0.0f) {
            if ((e > tol && dot0 > tol) || (-e > tol && -dot0 > tol))
                return false;
        }
        float s = dot0 < 0.0f ? -1.0f : (0.0f < dot0 ? 1.0f : 0.0f);
        float t = (s * tol - dot0) / (e - dot0);
        if (t - 0.01f > 0.0f && t + 0.01f < 1.0f) {
            P.x = diff.x * t + p->x;
            P.y = diff.y * t + p->y;
            P.z = diff.z * t + p->z;
            double m = -(double)(FUN_00083d90(&dot0) * tol);
            double x2 = m * dir->x + P.x;
            double y2 = m * dir->y + P.y;
            double z2 = m * dir->z + P.z;
            double qq = z2 * z2 + y2 * y2 + x2 * x2;
            if (qq <= r2) {
                out->x = P.x;
                out->y = P.y;
                out->z = P.z;
                return true;
            }
        }
    }

    double dd = e - dot0;
    double n2 = diff.z * diff.z + diff.x * diff.x + diff.y * diff.y;
    float K = (float)(n2 - dd * dd);
    double pd = diff.x * p->x + diff.y * p->y + diff.z * p->z;
    double B2 = (pd - dd * dot0) * 2.0;
    double D = B2 * B2 - ((c0 - (double)dot0 * dot0 - r2) * K) * 4.0f;
    if (D < 0.0f)
        return false;
    double sq = sqrt(D);
    float t1 = (float)((sq - B2) / (K * 2.0));
    float t2 = (float)((-B2 - sq) / (K * 2.0));

    bool ok1 = (t1 - 0.01f > 0.0f) && (t1 + 0.01f < 1.0f);
    bool ok2 = (t2 - 0.01f > 0.0f) && (t2 + 0.01f < 1.0f);
    V3_2f08d0 R1, R2;
    if (ok1) {
        R1.x = diff.x * t1 + p->x;
        R1.y = diff.y * t1 + p->y;
        R1.z = diff.z * t1 + p->z;
        FBits_2f08d0 v;
        v.f = R1.x * dir->x + R1.y * dir->y + R1.z * dir->z;
        v.u &= 0x7fffffff;
        ok1 = v.f <= tol;
    }
    if (ok2) {
        R2.x = diff.x * t2 + p->x;
        R2.y = diff.y * t2 + p->y;
        R2.z = diff.z * t2 + p->z;
        FBits_2f08d0 v;
        v.f = R2.x * dir->x + R2.y * dir->y + R2.z * dir->z;
        v.u &= 0x7fffffff;
        ok2 = v.f <= tol;
    }
    if (ok1) {
        V3_2f08d0 *r = &R1;
        if (ok2 && !(t1 < t2))
            r = &R2;
        out->x = r->x;
        out->y = r->y;
        out->z = r->z;
        return true;
    }
    if (ok2) {
        out->x = R2.x;
        out->y = R2.y;
        out->z = R2.z;
        return true;
    }
    return false;
}
