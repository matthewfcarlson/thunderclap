// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_000a0dc0 @ 0x000a0dc0
extern "C" double sqrt(double);

struct Vec3_a0dc0 { float x, y, z; };

Vec3_a0dc0 *FUN_0009fbd0(Vec3_a0dc0 *out, Vec3_a0dc0 *a, Vec3_a0dc0 *b, Vec3_a0dc0 *c, float d, float e);

class Body_a0dc0 {
public:
    char pad000[0x1e8];
    Vec3_a0dc0 pos;
    Vec3_a0dc0 prev;
    Vec3_a0dc0 vel;
    char pad20c[0xc0];
    Vec3_a0dc0 refB;
    Vec3_a0dc0 refA;
    char pad2e4[0x15c];
    float limit;
    void FUN_000a0dc0(float a1, float a2, float a3);
};

void Body_a0dc0::FUN_000a0dc0(float a1, float a2, float a3)
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
        Vec3_a0dc0 tmp;
        Vec3_a0dc0 *r = FUN_0009fbd0(&tmp, &refA, &refB, &prev, a3, a2);
        vel.x = r->x;
        vel.y = r->y;
        vel.z = r->z;
        pos.x = vel.x + pos.x;
        pos.y = vel.y + pos.y;
        pos.z = vel.z + pos.z;
    }
}
