// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 22/22)
// FUN_001f7320 @ 0x001f7320
struct Vec3 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022b9c0();
    void FUN_0022baf0(Vec3 *axis, float angle);
    void FUN_0022c2b0(Vec3 *in, Vec3 *out);
};

class Rng {
public:
    float FUN_000787e0(float lo, float hi);
    float FUN_00143100();
};

class Actor {
public:
    void FUN_000352b0(Vec3 *out);
};

struct Controlled {
    char pad0[0x124];
    Actor *actor;
};

class Caster {
public:
    char FUN_00201f20(Vec3 *from, int mask, Vec3 *hit, Vec3 *normal, void **hitObj, int *hitPart);
};

class Source {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual Matrix *vf14();
};

class Camera {
public:
    Source *FUN_00099180();
};

struct Scene {
    char pad0[8];
    Camera *camera;
    char pad1[0x20 - 0x0c];
    Controlled *controlled;
    Caster *caster;
};

class Renderer {
public:
    void FUN_0027ffc0(int id, Matrix *m);
    void FUN_00283a10(float dt);
};

extern float DAT_004e58dc;
extern float DAT_004e58d8;
Rng *FUN_000964d0();
Renderer *FUN_0027f250();

class Spawner {
public:
    void FUN_001f7320(Scene *scene, float dt);
    void FUN_001f6cd0(void *hitObj, int hitPart, Vec3 *hit, Vec3 *normal, Vec3 *axis, int kind,
                      float a, float b, int c, int d);

    char pad0[0x4c];
    char sparksA;
    char sparksC;
    char sparksB;
    char pad1;
    int slotA;
    int slotC;
};

void Spawner::FUN_001f7320(Scene *scene, float dt)
{
    Vec3 hit1;
    Vec3 normal1;
    Vec3 hit2;
    if (sparksA) {
        DAT_004e58dc = DAT_004e58dc - dt;
        if (DAT_004e58dc < 0.0f) {
            Rng *rng = FUN_000964d0();
            DAT_004e58dc = rng->FUN_000787e0(0.0f, 0.1f);
            void *hitObj = 0;
            int hitPart = 0;
            Vec3 p;
            scene->controlled->actor->FUN_000352b0(&p);
            p.y = p.y + 5.0f;
            p.x = rng->FUN_00143100() * 10.0f + p.x;
            p.z = rng->FUN_00143100() * 10.0f + p.z;
            if (scene->caster->FUN_00201f20(&p, 0, &hit1, &normal1, &hitObj, &hitPart)) {
                if (hitObj != 0) {
                    Vec3 axis;
                    axis.x = 1.0f;
                    axis.y = 0.0f;
                    axis.z = 0.0f;
                    FUN_001f6cd0(hitObj, hitPart, &hit1, &normal1, &axis, 6, 1.0f, 1.0f, 0, 0);
                }
            }
        }
        Matrix m;
        m.FUN_0022b980();
        if (scene->camera->FUN_00099180()) {
            Matrix *src = scene->camera->FUN_00099180()->vf14();
            m = *src;
            m.FUN_0022b9c0();
        }
        Renderer *r = FUN_0027f250();
        r->FUN_0027ffc0(slotA, &m);
    }
    if (sparksB) {
        DAT_004e58d8 = DAT_004e58d8 - dt;
        if (DAT_004e58d8 < 0.0f) {
            Rng *rng = FUN_000964d0();
            DAT_004e58d8 = rng->FUN_000787e0(0.0f, 0.2f);
            void *hitObj = 0;
            int hitPart = 0;
            Vec3 p;
            scene->controlled->actor->FUN_000352b0(&p);
            Matrix m;
            m.FUN_0022b980();
            Vec3 axis;
            axis.x = 0.0f;
            axis.y = 1.0f;
            axis.z = 0.0f;
            m.FUN_0022baf0(&axis, rng->FUN_000787e0(0.0f, 6.2831855f));
            Vec3 v;
            v.x = rng->FUN_000787e0(10.0f, 50.0f);
            v.y = 5.0f;
            v.z = 0.0f;
            m.FUN_0022c2b0(&v, &v);
            p.x = p.x + v.x;
            p.y = p.y + v.y;
            p.z = p.z + v.z;
            if (scene->caster->FUN_00201f20(&p, 0, &hit2, &hit1, &hitObj, &hitPart)) {
                if (hitObj != 0) {
                    Vec3 axis2;
                    axis2.x = 1.0f;
                    axis2.y = 0.0f;
                    axis2.z = 0.0f;
                    FUN_001f6cd0(hitObj, hitPart, &hit2, &hit1, &axis2, 7, 1.0f, 1.0f, 0, 0);
                }
            }
        }
    }
    if (sparksC) {
        Matrix m;
        m.FUN_0022b980();
        if (scene->camera->FUN_00099180()) {
            Matrix *src = scene->camera->FUN_00099180()->vf14();
            m = *src;
            m.FUN_0022b9c0();
        }
        Renderer *r = FUN_0027f250();
        r->FUN_0027ffc0(slotC, &m);
    }
    FUN_0027f250()->FUN_00283a10(dt);
}
