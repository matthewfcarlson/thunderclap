// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022e1f0 @ 0x0022e1f0
struct Vec3 { float x, y, z; };

union FloatBits {
    float f;
    int i;
};

struct Plane {
    Vec3 normal;
    float d;
    bool FUN_0022e1f0(const Vec3 *a, const Vec3 *b, float *t);
};

// Segment a-b against the plane: true (and the crossing fraction in *t) when the endpoints lie on opposite sides.
bool Plane::FUN_0022e1f0(const Vec3 *a, const Vec3 *b, float *t)
{
    FloatBits da, db;
    da.f = (a->z * normal.z + a->y * normal.y) + a->x * normal.x + d;
    double distB = (b->z * normal.z + b->y * normal.y) + b->x * normal.x + d;
    db.f = (float)distB;
    if ((db.i ^ da.i) >= 0)
        return false;
    double diff = da.f - distB;
    FloatBits span;
    span.f = (float)diff;
    span.i &= 0x7fffffff;
    if (span.f <= 1e-5f)
        return false;
    *t = da.f / diff;
    return true;
}
