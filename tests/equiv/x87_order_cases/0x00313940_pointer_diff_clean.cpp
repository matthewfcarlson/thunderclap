// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 15/16, incomplete)
// FUN_00313940 @ 0x00313940
struct Vec3_313940 {
    float x, y, z;
    void FUN_0022d180();
};

union FloatBits_313940 {
    float f;
    unsigned int u;
};

struct Box_313940 {
    char pad00[0x48];
    Vec3_313940 ext;
    Vec3_313940 row[3];
    float FUN_002fbcd0(const Vec3_313940 *axis);
    float FUN_002fbdc0(const Vec3_313940 *axis, int skip);
};

class BoxTest {
public:
    char pad00[0x0c];
    float margin;
    char pad10[4];
    Vec3_313940 d;
    bool Separated(Box_313940 *a, Box_313940 *b);
};

static inline float AbsBits(float v)
{
    FloatBits_313940 bits;
    bits.f = v;
    bits.u &= 0x7fffffff;
    return bits.f;
}

bool BoxTest::Separated(Box_313940 *a, Box_313940 *b)
{
    int i;
    int j;
    float t;

    for (i = 0; i < 3; i++) {
        double lim = b->FUN_002fbcd0(&a->row[i]) + (&a->ext.x)[i];
        t = a->row[i].z * d.z + d.y * a->row[i].y + a->row[i].x * d.x;
        lim += margin;
        if (lim < AbsBits(t)) {
            return true;
        }
        lim = a->FUN_002fbcd0(&b->row[i]) + (&b->ext.x)[i];
        t = b->row[i].y * d.y + b->row[i].z * d.z + d.x * b->row[i].x;
        lim += margin;
        if (lim < AbsBits(t)) {
            return true;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            float dot = b->row[j].y * a->row[i].y + a->row[i].x * b->row[j].x + b->row[j].z * a->row[i].z;
            float adot = AbsBits(dot);
            float diff = AbsBits(adot - 1.0f);
            if (diff <= 1e-5f) {
                continue;
            }
            Vec3_313940 cross;
            cross.x = a->row[i].y * b->row[j].z - b->row[j].y * a->row[i].z;
            cross.y = a->row[i].z * b->row[j].x - a->row[i].x * b->row[j].z;
            cross.z = b->row[j].y * a->row[i].x - a->row[i].y * b->row[j].x;
            if (margin > 0.0f) {
                cross.FUN_0022d180();
            }
            volatile float rb = b->FUN_002fbdc0(&cross, j);
            double lim = a->FUN_002fbdc0(&cross, i) + rb;
            t = cross.z * d.z + cross.y * d.y + cross.x * d.x;
            lim += margin;
            if (lim < AbsBits(t)) {
                return true;
            }
        }
    }
    return false;
}
