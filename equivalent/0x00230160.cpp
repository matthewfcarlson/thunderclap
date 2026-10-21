// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 22/22)
// FUN_00230160 @ 0x00230160
extern "C" double sqrt(double);
struct Vec3_230160 {
    float x, y, z;
};
union FloatBits_230160 {
    float value;
    unsigned int bits;
};
class Segment_230160 {
  public:
    Vec3_230160 p0, p1;
    float FUN_00230160(Segment_230160* other);
};
float Segment_230160::FUN_00230160(Segment_230160* other) {
    float ux = p1.x - p0.x, uy = p1.y - p0.y, uz = p1.z - p0.z;
    float vx = other->p1.x - other->p0.x, vy = other->p1.y - other->p0.y, vz = other->p1.z - other->p0.z;
    float wx = p0.x - other->p0.x, wy = p0.y - other->p0.y, wz = p0.z - other->p0.z;
    float uu = uz * uz + uy * uy + ux * ux;
    float uv = vz * uz + vy * uy + vx * ux;
    float vv = vz * vz + vy * vy + vx * vx;
    float wu = wz * uz + wy * uy + wx * ux;
    float wv = wz * vz + wy * vy + wx * vx;
    float determinant = vv * uu - uv * uv;
    float sDenominator = determinant, tDenominator = determinant;
    float tNumerator;
    double sNumerator;
    if (determinant < 1.0e-5f) {
        sNumerator = 0.0;
        sDenominator = 1.0f;
        tNumerator = wv;
        tDenominator = vv;
    } else {
        sNumerator = wv * uv - wu * vv;
        tNumerator = wv * uu - wu * uv;
        if (sNumerator < 0.0) {
            sNumerator = 0.0;
            tNumerator = wv;
            tDenominator = vv;
        } else if (sNumerator > determinant) {
            sNumerator = determinant;
            tNumerator = wv + uv;
            tDenominator = vv;
        }
    }
    if (tNumerator < 0.0f) {
        tNumerator = 0.0f;
        double boundary = -wu;
        if (boundary < 0.0)
            sNumerator = 0.0;
        else if (boundary > uu)
            sNumerator = sDenominator;
        else {
            sNumerator = boundary;
            sDenominator = uu;
        }
    } else if (tNumerator > tDenominator) {
        tNumerator = tDenominator;
        double boundary = uv - wu;
        if (boundary < 0.0)
            sNumerator = 0.0;
        else if (boundary > uu)
            sNumerator = sDenominator;
        else {
            sNumerator = boundary;
            sDenominator = uu;
        }
    }
    FloatBits_230160 magnitude;
    magnitude.value = (float)sNumerator;
    magnitude.bits &= 0x7fffffff;
    double s = magnitude.value < 1.0e-5f ? 0.0 : sNumerator / sDenominator;
    magnitude.value = tNumerator;
    magnitude.bits &= 0x7fffffff;
    double t = magnitude.value < 1.0e-5f ? 0.0 : tNumerator / tDenominator;
    volatile float tvx = vx * t, tvy = vy * t;
    double tvz = t * vz;
    volatile float suz = uz * s;
    volatile float nearestX = ux * s + wx;
    double nearestY = uy * s + wy;
    volatile float nearestZ = suz + wz;
    volatile float dx = nearestX - tvx, dy = nearestY - tvy;
    double dz = nearestZ - tvz;
    double zy = dz * dz + dy * dy; // keep the original's summation order
    return sqrt(zy + dx * dx);
}