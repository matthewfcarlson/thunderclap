// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_00230160 @ 0x00230160
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

union FloatBits {
    float f;
    unsigned int u;
};

class Segment {
public:
    Vec3 p0;
    Vec3 p1;
    float FUN_00230160(Segment* other);
};

float Segment::FUN_00230160(Segment* other)
{
    volatile float ux = p1.x - p0.x;
    volatile float uy = p1.y - p0.y;
    volatile float uz = p1.z - p0.z;
    volatile float vx = other->p1.x - other->p0.x;
    volatile float vy = other->p1.y - other->p0.y;
    volatile float vz = other->p1.z - other->p0.z;
    volatile float wx = p0.x - other->p0.x;
    volatile float wy = p0.y - other->p0.y;
    volatile float wz = p0.z - other->p0.z;
    volatile float a = uz * uz + uy * uy + ux * ux;
    volatile float b = vz * uz + vy * uy + vx * ux;
    volatile float c = vz * vz + vy * vy + vx * vx;
    volatile float d = wz * uz + wy * uy + wx * ux;
    volatile float e = wz * vz + wy * vy + wx * vx;
    volatile float D = c * a - b * b;
    volatile float sD = D;
    volatile float tD = D;
    volatile float tN;
    double sN;
    if (D < 1.0e-5f) {
        sN = 0.0;
        sD = 1.0f;
        tN = e;
        tD = c;
    } else {
        sN = e * b - d * c;
        tN = e * a - d * b;
        if (sN < 0.0) {
            sN = 0.0;
            tN = e;
            tD = c;
        } else if (sN > D) {
            sN = D;
            tN = e + b;
            tD = c;
        }
    }
    if (tN < 0.0f) {
        tN = 0.0f;
        double nd = -d;
        if (nd < 0.0)
            sN = 0.0;
        else if (nd > a)
            sN = sD;
        else {
            sN = nd;
            sD = a;
        }
    } else if (tN > tD) {
        tN = tD;
        double bd = b - d;
        if (bd < 0.0)
            sN = 0.0;
        else if (bd > a)
            sN = sD;
        else {
            sN = bd;
            sD = a;
        }
    }
    FloatBits s;
    s.f = (float)sN;
    s.u &= 0x7fffffff;
    double sc;
    if (s.f < 1.0e-5f)
        sc = 0.0;
    else
        sc = sN / sD;
    FloatBits t;
    t.f = tN;
    t.u &= 0x7fffffff;
    double tc;
    if (t.f < 1.0e-5f)
        tc = 0.0;
    else
        tc = tN / tD;
    volatile float tvx = vx * tc;
    volatile float tvy = vy * tc;
    double tvz = tc * vz;
    volatile float suz = uz * sc;
    volatile float ax = ux * sc + wx;
    double ay = uy * sc + wy;
    volatile float az = suz + wz;
    volatile float dx = ax - tvx;
    volatile float dy = ay - tvy;
    double dz = az - tvz;
    return sqrt(dz * dz + dy * dy + dx * dx);
}
