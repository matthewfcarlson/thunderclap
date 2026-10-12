// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/10, incomplete)
// FUN_00084920 @ 0x00084920
struct V3 {
    float x, y, z;
    void FUN_0022d180();
};

union FloatBits {
    float f;
    unsigned int u;
};

struct Frame {
    float dot;
    V3 lo;
    V3 hi;
};

class Tracker {
public:
    char pad00[0x10];
    int state;
    char pad14[0x38 - 0x14];
    V3 a;
    V3 b;
    V3 c;
    char pad5c[0xbc - 0x5c];
    int fbc;
    void FUN_00083e60(V3 d1, V3 d2, V3 p);
    void FUN_00084920(V3 na, V3 nb, V3 nc);
};

void Tracker::FUN_00084920(V3 na, V3 nb, V3 nc)
{
    Frame f;
    FloatBits t;
    if (state == 3) {
        V3& thisd = f.hi;
        V3& argd = f.lo;
        thisd.x = c.x - b.x;
        thisd.y = c.y - b.y;
        thisd.z = c.z - b.z;
        argd.x = nc.x - nb.x;
        argd.y = nc.y - nb.y;
        argd.z = nc.z - nb.z;
        thisd.FUN_0022d180();
        argd.FUN_0022d180();
        t.f = argd.z * thisd.z + argd.y * thisd.y + argd.x * thisd.x - 1.0f;
        t.u &= 0x7fffffff;
        if (t.f <= 1e-05f) {
            state = 9;
        } else {
            FUN_00083e60(thisd, argd, nb);
            state = 5;
        }
    } else if (state == 4) {
        V3& thisd = f.lo;
        V3& argd = f.hi;
        thisd.x = c.x - b.x;
        thisd.y = c.y - b.y;
        thisd.z = c.z - b.z;
        argd.x = nc.x - nb.x;
        argd.y = nc.y - nb.y;
        argd.z = nc.z - nb.z;
        thisd.FUN_0022d180();
        argd.FUN_0022d180();
        t.f = argd.z * thisd.z + argd.y * thisd.y + argd.x * thisd.x - 1.0f;
        t.u &= 0x7fffffff;
        if (t.f <= 1e-05f) {
            state = 10;
        } else {
            FUN_00083e60(thisd, argd, nb);
            state = 6;
        }
    } else if (state == 13) {
        V3& thisd = f.lo;
        V3& argd = f.hi;
        thisd.x = c.x - b.x;
        thisd.y = c.y - b.y;
        thisd.z = c.z - b.z;
        argd.x = nc.x - nb.x;
        argd.y = nc.y - nb.y;
        argd.z = nc.z - nb.z;
        thisd.FUN_0022d180();
        argd.FUN_0022d180();
        FUN_00083e60(thisd, argd, nb);
        fbc = 0;
        state = 14;
    }
    a = na;
    b = nb;
    c = nc;
}
