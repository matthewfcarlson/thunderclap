// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 22/22)
// FUN_00292f60 @ 0x00292f60
extern "C" double sqrt(double);
extern "C" double floor(double);

struct Vec3_292f60 {
    float x, y, z;
};

struct Frame_292f60 {
    Vec3_292f60 a;
    Vec3_292f60 b;
};

class Sampler_292f60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(float coord, float *out);
};

// Snap *p to its floor when the two samplers disagree enough; sampler a arrives in esi, b in edi.
// equiv-conv: FUN_00292f60 esi edi stack
void FUN_00292f60(Sampler_292f60 *a, Sampler_292f60 *b, float *p)
{
    Frame_292f60 f;
    float lo = (float)floor((double)*p);
    float hi = (float)floor((double)(*p + 1.0f));
    bool bad = false;
    float dist = 0.0f;
    float dot = 0.0f;

    if (a) {
        a->v4(lo, &f.a.x);
        a->v4(hi, &f.b.x);
        f.a.x = f.a.x - f.b.x;
        f.a.y = f.a.y - f.b.y;
        f.a.z = f.a.z - f.b.z;
        dist = (float)sqrt((double)(f.a.z * f.a.z + f.a.y * f.a.y + f.a.x * f.a.x));
        if (dist > 4.0f)
            bad = true;
    }

    if (b && !bad) {
        b->v4(lo, &f.a.x);
        b->v4(hi, &f.b.x);
        dot = f.b.z * f.a.z + f.b.y * f.a.y + f.b.x * f.a.x;
        if (dot < 0.0f)
            bad = true;
    }

    if (a && b && !bad) {
        if (dist > 1.0f && dot < 0.866f)
            *p = lo;
    } else if (bad) {
        *p = lo;
    }
}
