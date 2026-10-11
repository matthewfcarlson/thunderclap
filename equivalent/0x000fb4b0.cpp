// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_000fb4b0 @ 0x000fb4b0
struct Vec3 { float x, y, z; };
struct Target {
    char pad0[0x3c];
    unsigned int color;      // 0x3c
    char pad1[0x78 - 0x40];
    Vec3 offset;             // 0x78
};
union FloatBits {
    float f;
    unsigned int u;
};

class Fade {
public:
    int state;               // 0x0
    Target *target;          // 0x4
    float start;             // 0x8
    float duration;          // 0xc
    float time;              // 0x10
    float scale[3];          // 0x14
    Vec3 base;               // 0x20
    float floor;             // 0x2c
    unsigned char b0;        // 0x30
    unsigned char b1;        // 0x31
    unsigned char b2;        // 0x32
    unsigned char alpha;     // 0x33
    char reverse;            // 0x34
    bool FUN_000fb4b0(float dt);
};

bool Fade::FUN_000fb4b0(float dt)
{
    double end = start + duration;
    double t = dt + time;
    double cur;
    if (t >= 0.0 && t <= end)
        cur = t;
    else if (t > end)
        cur = end;
    else
        cur = 0.0;
    time = (float)cur;
    FloatBits d;
    d.f = (float)(cur - end);
    d.u &= 0x7fffffff;
    if (d.f <= 1e-5f)
        time = (float)end;
    double u;
    if (time < start)
        u = 1.0;
    else
        u = (end - time) / duration;
    if (reverse)
        u = 1.0 - u;
    double v = 1.0 - u;
    float w0 = (float)(v * scale[0]);
    float w1 = (float)(v * scale[1]);
    float w2 = (float)(v * scale[2]);
    int a = (int)(((1.0 - floor) * u + floor) * (int)alpha);
    unsigned int c = ((unsigned int)a << 8) | b2;
    c = (c << 8) | b1;
    c = (c << 8) | b0;
    target->color = c;
    target->offset.x = w0 + base.x;
    target->offset.y = w1 + base.y;
    target->offset.z = w2 + base.z;
    FloatBits e;
    e.f = (float)(time - end);
    e.u &= 0x7fffffff;
    if (e.f <= 1e-5f) {
        state = 3;
        return false;
    }
    return true;
}
