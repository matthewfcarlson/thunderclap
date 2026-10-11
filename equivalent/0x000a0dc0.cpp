// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_000a0dc0 @ 0x000a0dc0
extern "C" double sqrt(double);

struct Vec3 { float x, y, z; };

Vec3 *FUN_0009fbd0(Vec3 *out, Vec3 *a, Vec3 *b, Vec3 *c, float d, float e);

class Body {
public:
    char pad000[0x1e8];
    Vec3 pos;
    Vec3 prev;
    Vec3 vel;
    char pad20c[0xc0];
    Vec3 refB;
    Vec3 refA;
    char pad2e4[0x15c];
    float limit;
    void FUN_000a0dc0(float a1, float a2, float a3);
};

void Body::FUN_000a0dc0(float a1, float a2, float a3)
{
    float eps = 1e-05f;
    float absA3 = a3 < 0.0f ? -a3 : a3;
    if (!(absA3 <= eps)) {
        float len = (float)sqrt(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
        float inv = 1.0f / a3;
        float t = inv * a1;
        if (inv * len > 20.0f)
            t = a1 / len * 20.0f;
        float m = limit * 0.6f;
        if (len * t > m)
            t = m / len;
        vel.x = vel.x * t;
        vel.y = vel.y * t;
        vel.z = vel.z * t;
        prev = vel;
        Vec3 tmp;
        Vec3 *r = FUN_0009fbd0(&tmp, &refA, &refB, &prev, a3, a2);
        vel.x = r->x;
        vel.y = r->y;
        vel.z = r->z;
        pos.x = vel.x + pos.x;
        pos.y = vel.y + pos.y;
        pos.z = vel.z + pos.z;
    }
}
