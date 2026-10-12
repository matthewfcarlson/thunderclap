// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_003130a0 @ 0x003130a0
struct V3 {
    float x, y, z;
};

struct V3Pair {
    V3 a;
    V3 b;
};

class Scaler {
public:
    char pad0[0x2008];
    V3 scale;               // 0x2008
    void FUN_003130a0(V3Pair *pairs, int count);
};

void Scaler::FUN_003130a0(V3Pair *pairs, int count)
{
    for (int i = 0; i < count; ++i) {
        V3Pair *p = &pairs[i];
        float ax = p->a.x * scale.x;
        float ay = scale.y * p->a.y;
        float az = p->a.z * scale.z;
        p->a.z = az;
        p->a.x = ax;
        p->a.y = ay;

        float bx = scale.x * p->b.x;
        float by = p->b.y * scale.y;
        float bz = p->b.z * scale.z;
        p->b.z = bz;
        p->b.x = bx;
        p->b.y = by;
    }
}
