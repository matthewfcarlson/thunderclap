// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 14/14)
// FUN_000a8670 @ 0x000a8670
struct Matrix;

struct Vec3_a8670 {
    float x, y, z;
    char FUN_0022d2b0(const Vec3_a8670 *other, float eps) const;
    void FUN_0022d210(const Matrix *m);
};

class Curve_a8670 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual float v11();
    virtual void v12(float t);
};

struct Follower_a8670 {
    char pad0[0xd0];
    Vec3_a8670 position;
};

struct Matrix {
    float m[16];
};

struct PathSampler {
    char pad0[0x170];
    Curve_a8670 *curve;
    Follower_a8670 *follower;
    char pad178[8];
    Matrix transform;
    int FUN_000a8670(Vec3_a8670 *out, int count);
};

int PathSampler::FUN_000a8670(Vec3_a8670 *out, int count)
{
    if (curve == 0)
        return -1;

    float length = curve->v11();
    int written = 0;
    int lastIndex = 0;
    Vec3_a8670 last;
    Vec3_a8670 pos;

    if (count > 0) {
        float denom = (float)(count - 1);
        lastIndex = count - 1;
        for (int i = 0; i < count; i++) {
            curve->v12((float)i * length / denom);
            curve->v7();
            pos = follower->position;
            if (i != 0) {
                if (pos.FUN_0022d2b0(&last, 1e-5f))
                    continue;
                if (i != lastIndex && pos.FUN_0022d2b0(&last, 0.1f))
                    continue;
            }
            last = pos;
            pos.FUN_0022d210(&transform);
            out[written] = pos;
            written++;
        }
    }
    return written;
}
