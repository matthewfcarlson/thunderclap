// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 27/28, incomplete)
// FUN_002f3e40 @ 0x002f3e40
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

union FloatBits {
    float f;
    unsigned int u;
};

struct Segment {
    Vec3 a;
    Vec3 b;
};

struct ClipOut {
    Vec3 a;
    Vec3 b;
    Vec3 start;
    Vec3 dir;
};

struct Bounds {
    char pad00[0x24];
    Vec3 origin;
    char pad30[0x3c - 0x30];
    Vec3 scale;
};

class RayClipper {
public:
    char pad00[0x44];
    Bounds *bounds;
    void Clip(ClipOut *out, const Segment *seg);
};

void RayClipper::Clip(ClipOut *out, const Segment *seg)
{
    Bounds *bd = bounds;
    float tmin;
    double tmax;
    int axis;
    float *s;
    float *dp;

    out->a.x = seg->a.x - bd->origin.x;
    out->a.y = seg->a.y - bd->origin.y;
    out->a.z = seg->a.z - bd->origin.z;
    out->a.x = bd->scale.x * out->a.x;
    out->a.y = out->a.y * bd->scale.y;
    out->a.z = out->a.z * bd->scale.z;
    out->b.x = seg->b.x - bd->origin.x;
    out->b.y = seg->b.y - bd->origin.y;
    out->b.z = seg->b.z - bd->origin.z;
    out->b.x = bd->scale.x * out->b.x;
    out->b.y = bd->scale.y * out->b.y;
    out->b.z = bd->scale.z * out->b.z;
    out->start = out->a;
    out->dir.x = out->b.x - out->a.x;
    out->dir.y = out->b.y - out->a.y;
    out->dir.z = out->b.z - out->a.z;

    tmax = out->dir.FUN_0022d110();
    if (tmax == 0.0f) {
        return;
    }
    if (out->a.x >= 0.0f && out->a.y >= 0.0f && out->a.z >= 0.0f && out->b.x <= 65535.0f &&
        out->b.y <= 65535.0f && out->b.z <= 65535.0f) {
        return;
    }

    tmin = 0.0f;
    s = &out->start.z;
    dp = &out->dir.z;
    for (axis = 0; axis < 3; axis++) {
        FloatBits bits;
        bits.f = *dp;
        bits.u &= 0x7fffffff;
        if (bits.f >= 1e-5f) {
            double inv = 1.0f / *dp;
            float t0 = (float)-(inv * *s);
            double t1 = (65535.0f - *s) * inv;
            float t1f = (float)t1;
            if (t0 > t1) {
                if (t1 > tmin) {
                    tmin = (float)t1;
                }
                if (t0 < tmax) {
                    tmax = t0;
                }
            } else {
                if (t0 > tmin) {
                    tmin = t0;
                }
                if (t1 < tmax) {
                    tmax = t1f;
                }
            }
        }
        s--;
        dp--;
    }

    out->a.x = tmin * out->dir.x + out->start.x;
    out->a.y = tmin * out->dir.y + out->start.y;
    out->a.z = tmin * out->dir.z + out->start.z;
    out->b.x = tmax * out->dir.x + out->start.x;
    out->b.y = tmax * out->dir.y + out->start.y;
    out->b.z = tmax * out->dir.z + out->start.z;
}
