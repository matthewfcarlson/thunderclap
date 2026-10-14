// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/10, incomplete)
// FUN_00084920 @ 0x00084920
struct V3_84920 {
    float x, y, z;
    void FUN_0022d180();
};

union FloatBits_84920 {
    float f;
    unsigned int u;
};

struct Frame_84920 {
    float dot;
    V3_84920 lo;
    V3_84920 hi;
};

class Tracker_84920 {
public:
    char pad00[0x10];
    int state;
    char pad14[0x38 - 0x14];
    V3_84920 a;
    V3_84920 b;
    V3_84920 c;
    char pad5c[0xbc - 0x5c];
    int fbc;
    void FUN_00083e60(V3_84920 d1, V3_84920 d2, V3_84920 p);
    void FUN_00084920(V3_84920 na, V3_84920 nb, V3_84920 nc);
};

void Tracker_84920::FUN_00084920(V3_84920 na, V3_84920 nb, V3_84920 nc)
{
    Frame_84920 f;
    FloatBits_84920 t;
    if (state == 3) {
        V3_84920& thisd = f.hi;
        V3_84920& argd = f.lo;
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
        V3_84920& thisd = f.lo;
        V3_84920& argd = f.hi;
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
        V3_84920& thisd = f.lo;
        V3_84920& argd = f.hi;
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
