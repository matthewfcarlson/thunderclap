// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 3/4, incomplete)
// FUN_0022ae20 @ 0x0022ae20
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
};

union FloatBits {
    float f;
    unsigned int u;
};

struct Rng {
    unsigned int s0;
    unsigned int s1;

    float Next()
    {
        s0 = (s0 & 0xffff) * 0x9069 + (s0 >> 16);
        s1 = (s1 & 0xffff) * 0x4650 + (s1 >> 16);
        unsigned int r = (s0 << 16) + (s1 & 0xffff);
        FloatBits m;
        m.u = (r & 0x7fffff) | 0x3f800000;
        FloatBits v;
        v.f = m.f - 1.0f;
        v.u |= r & 0x80000000;
        return v.f;
    }

    void FUN_0022ae20(V3 *out);
};

void Rng::FUN_0022ae20(V3 *out)
{
    V3 v;
    float len2;
    do {
        v.x = Next();
        v.y = Next();
        v.z = Next();
        len2 = v.z * v.z + v.y * v.y + v.x * v.x;
    } while (len2 > 1.0f || len2 < 0.001f);
    double inv = 1.0 / sqrt((double)len2);
    out->x = (float)(v.x * inv);
    out->y = (float)(v.y * inv);
    out->z = (float)(v.z * inv);
}
