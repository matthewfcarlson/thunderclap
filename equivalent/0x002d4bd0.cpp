// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 15/16, incomplete)
// pure3d::ParticleEmitter::vfunc_19 @ 0x002d4bd0
extern "C" double floor(double x);

class Child {
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
    virtual void v10(float t);
};

class ParticleEmitter {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void vfunc_19(float t);
    char pad04[0x88 - 0x04];
    Child* child;
    char pad8c[0x94 - 0x8c];
    unsigned int frameCount;
    int frame;
    float frac;
    float time;
    bool atEnd;
};

static float absf(float v)
{
    return v < 0.0f ? -v : v;
}

void ParticleEmitter::vfunc_19(float t)
{
    if (!(t >= 0.0f))
        t = 0.0f;
    else if (t > 1.0f)
        t = 1.0f;
    float d = t - time;
    if (!(absf(d) <= 1e-5f)) {
        if (frameCount <= 1) {
            frame = 0;
            time = 0.0f;
            atEnd = true;
            frac = 0.0f;
        } else {
            int n = (int)frameCount - 1;
            float s = n * t;
            int i = (int)floor((double)(n * t));
            time = t;
            frame = i;
            float f = s - (float)i;
            frac = f;
            if (absf(1.0f - f) <= 1e-5f) {
                frame = i + 1;
                atEnd = false;
                frac = 0.0f;
            } else if (absf(f) <= 1e-5f) {
                atEnd = false;
            } else {
                atEnd = true;
            }
        }
    }
    if (child != 0)
        child->v10(time);
}
