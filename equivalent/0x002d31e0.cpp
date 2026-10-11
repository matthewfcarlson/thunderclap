// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 13/14, incomplete)
// pure3d::ParticleGenerator::vfunc_10 @ 0x002d31e0
extern "C" double floor(double);

class ParticleGenerator {
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
    virtual void vfunc_10(float t);
    virtual void vfunc_11();

    char pad04[0xc];
    char atKey;
    char pad11[3];
    float time;
    float frac;
    unsigned count;
    int index;
};

void ParticleGenerator::vfunc_10(float t)
{
    if (t >= 0.0f) {
        if (!(t <= 1.0f))
            t = 1.0f;
    } else {
        t = 0.0f;
    }

    float delta = t - time;
    *(unsigned *)&delta &= 0x7fffffff;
    if (delta <= 1e-05f)
        return;

    if (count <= 1) {
        index = 0;
        time = 0;
        atKey = 1;
        frac = 0;
        return;
    }

    float x = (float)(int)(count - 1) * t;
    int idx = (int)floor(x);
    time = t;
    index = idx;
    float f = x - (float)idx;
    frac = f;

    float rem = f - 1.0f;
    *(unsigned *)&rem &= 0x7fffffff;
    if (rem <= 1e-05f) {
        index = idx + 1;
        atKey = 0;
        frac = 0;
        return;
    }
    float af = f;
    *(unsigned *)&af &= 0x7fffffff;
    if (af <= 1e-05f)
        atKey = 0;
    else
        atKey = 1;
}
