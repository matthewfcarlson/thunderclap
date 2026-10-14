// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 9/10, incomplete)
// pure3d::SpriteParticleUpdater::vfunc_4 @ 0x002d1db0
extern float DAT_004d0ed4;

struct Vec3_2d1db0 {
    float x, y, z;
};

struct Particle_2d1db0 {
    Vec3_2d1db0 pos;
    char pad0c[4];
    float scaled;
    char pad14[6];
    short size;
    char pad1c[0x2c - 0x1c];
    float age;
    float life;
};

struct Curve_2d1db0 {
    char pad0[0x18];
    float *table;
};

class Emitter_2d1db0 {
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
    virtual void v11();
    virtual void v12();
    virtual unsigned int GetCount();
    char pad[0x1bc - 4];
    Curve_2d1db0 *curve;
    char pad1c0[8];
    Particle_2d1db0 **particles;
};

struct SpriteParticleUpdater {
    char pad0[0x18];
    void (__cdecl *onUpdate)(float dt, int idx, Emitter_2d1db0 *em, Particle_2d1db0 *p);
    void (__cdecl *onUpdate2)(float dt, int idx, Emitter_2d1db0 *em, Particle_2d1db0 *p);
    void (__cdecl *onFrac)(float dt, int idx, float frac, Emitter_2d1db0 *em, Particle_2d1db0 *p);
    void (__cdecl *onFracPos)(float dt, int idx, float frac, Emitter_2d1db0 *em, Particle_2d1db0 *p, Vec3_2d1db0 *pos);
    void FUN_002d1db0(float dt, Emitter_2d1db0 *em);
};

void SpriteParticleUpdater::FUN_002d1db0(float dt, Emitter_2d1db0 *em)
{
    if (!(dt > 0.0f))
        return;

    unsigned int count = em->GetCount();
    Curve_2d1db0 *curve = em->curve;
    unsigned int i;
    for (i = 0; i < count; i++) {
        Particle_2d1db0 *p = em->particles[i];
        float step = dt;
        if (p->age >= 0.0f) {
            p->age = dt + p->age;
        } else {
            step = dt - p->age;
            p->age = step;
        }
        if (p->age < p->life) {
            float t = (p->age / p->life) * 20.0f;
            int idx = (int)t;
            float frac = t - (float)idx;
            Vec3_2d1db0 pos = p->pos;
            float *tbl = curve->table;
            float a = tbl[idx];
            float b = tbl[idx + 1];
            p->scaled = ((b - a) * frac + a) * (float)p->size * DAT_004d0ed4;
            onUpdate(step, idx, em, p);
            onUpdate2(step, idx, em, p);
            onFrac(step, idx, frac, em, p);
            onFracPos(step, idx, frac, em, p, &pos);
        }
    }
}
