// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 3/4, incomplete)
// FUN_002304b0 @ 0x002304b0
extern "C" double sqrt(double);

// Distance between two 3D line segments.
struct Segment {
    float p0x, p0y, p0z;
    float p1x, p1y, p1z;

    float FUN_002304b0(const Segment* o);
};

float Segment::FUN_002304b0(const Segment* o)
{
    float d1x = p1x - p0x;
    float d1y = p1y - p0y;
    float d1z = p1z - p0z;
    float d2x = o->p1x - o->p0x;
    float d2y = o->p1y - o->p0y;
    float d2z = o->p1z - o->p0z;
    float rx = p0x - o->p0x;
    float ry = p0y - o->p0y;
    float rz = p0z - o->p0z;

    float a = d1z * d1z + d1x * d1x + d1y * d1y;
    float b = d2z * d1z + d2y * d1y + d2x * d1x;
    float c = d2z * d2z + d2y * d2y + d2x * d2x;
    float d = rz * d1z + ry * d1y + rx * d1x;
    float e = rz * d2z + ry * d2y + rx * d2x;

    double s;
    double t;
    float denom = c * a - b * b;
    if (denom < 1e-5f) {
        s = 0.0f;
        if (b > c)
            t = d / b;
        else
            t = e / c;
    } else {
        float inv = 1.0f / denom;
        s = (e * b - d * c) * inv;
        t = (e * a - d * b) * inv;
    }

    volatile float c2x = d2x * t;
    volatile float c2y = d2y * t;
    double c2z = t * d2z;
    volatile float c1z = d1z * s;
    volatile float xx = d1x * s + rx;
    double yy = d1y * s + ry;
    volatile float zz = c1z + rz;
    volatile float dx = xx - c2x;
    volatile float dy = yy - c2y;
    double dz = zz - c2z;
    return (float)sqrt(dz * dz + dy * dy + dx * dx);
}
