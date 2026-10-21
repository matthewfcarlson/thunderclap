// STATUS: equivalent (tools/equiv.py level 3: 20031 inputs, branch coverage 16/18, incomplete)
// FUN_0024cf20 @ 0x0024cf20
extern "C" double sqrt(double);

struct Vec3_24cf20 {
    float x, y, z;
};

struct Edge_24cf20 {
    Vec3_24cf20 origin;
    char pad0c[0x18 - 0xc];
    Vec3_24cf20 axis;
    Vec3_24cf20 side;
    char pad30[0x3c - 0x30];
    char clampMode;
    bool FUN_0022d2b0(const Vec3_24cf20 *p, float eps);
};

void FUN_0024cf20(Edge_24cf20 *e, const Vec3_24cf20 *p, float *outCross, float *outAlong)
{
    double q;
    if (e->FUN_0022d2b0(p, 1e-5f)) {
        q = 0.0f;
    } else {
        // the offset is a rounded frame copy in the original
        struct { volatile float x, y, z; } d;
        d.x = e->origin.x - p->x;
        d.y = e->origin.y - p->y;
        d.z = e->origin.z - p->z;
        double c0 = e->side.z * e->axis.y - e->side.y * e->axis.z;
        double c1 = e->side.x * e->axis.z - e->side.z * e->axis.x;
        double c2 = e->side.y * e->axis.x - e->side.x * e->axis.y;
        double t = d.z * c2 + c1 * d.y + c0 * d.x;
        double lc = sqrt(c2 * c2 + c1 * c1 + c0 * c0);
        double ld = sqrt(d.z * d.z + d.y * d.y + d.x * d.x);
        q = t / (lc * ld);
    }
    *outCross = (float)q;

    if (e->clampMode != 1) {
        *outAlong = 0.0f;
    } else {
        double r;
        if (e->FUN_0022d2b0(p, 1e-5f)) {
            r = 0.0f;
        } else {
            struct { volatile float x, y, z; } d;
            d.x = e->origin.x - p->x;
            d.y = e->origin.y - p->y;
            d.z = e->origin.z - p->z;
            double s = d.z * e->axis.z + d.y * e->axis.y + d.x * e->axis.x;
            double la = sqrt(e->axis.x * e->axis.x + e->axis.y * e->axis.y + e->axis.z * e->axis.z);
            double ld = sqrt(d.z * d.z + d.y * d.y + d.x * d.x);
            r = -(s / (la * ld));
        }
        *outAlong = (float)r;
        if (r >= -1.0f && r <= 1.0f) {
            *outAlong = *outAlong;
        } else if (r > 1.0f) {
            *outAlong = 1.0f;
        } else {
            *outAlong = -1.0f;
        }
    }

    float v = *outCross;
    if (v >= -1.0f && v <= 1.0f) {
        *outCross = *outCross;
    } else if (v > 1.0f) {
        *outCross = 1.0f;
    } else {
        *outCross = -1.0f;
    }
}
