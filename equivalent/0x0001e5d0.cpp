// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// CGrabAction::vfunc_8 @ 0x0001e5d0
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3 *in, Vec3 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat *matrices;
};

struct Body {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter { char pad[4]; };
Fighter *__fastcall FUN_000592a0(void *owner);
Body *__fastcall FUN_00059a40(Fighter *f);

class Link {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Data {
    char pad0[0x20];
    Vec3 offset;
    float f2c;
};

class Effect {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat *m, int arg);
};

class CAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual char vfunc_8(int arg);
    char pad04[0x18];
    void *ownerObj;
    Data *data;
    int matrixIndex;
    Effect *effect;
    Vec3 pos;
    char finished;
    void FUN_0001df20(Vec3 *at, Vec3 *delta);
};

class CGrabAction : public CAction {
public:
    virtual char vfunc_8(int arg);
};

char CGrabAction::vfunc_8(int arg)
{
    if (finished)
        return 0;
    Fighter *fighter = FUN_000592a0(ownerObj);
    Body *body = FUN_00059a40(fighter);
    if (body == 0)
        return 0;

    Vec3 off = data->offset;
    Vec3 world;
    body->skeleton->matrices[matrixIndex].FUN_0022c2b0(&off, &world);

    Vec3 d;
    d.x = world.x - pos.x;
    d.y = world.y - pos.y;
    d.z = world.z - pos.z;
    volatile float dist = d.FUN_0022d110();
    volatile float limit = data->f2c + data->f2c;

    bool simple = dist < limit;
    if (!simple) {
        union { float f; unsigned int u; } a;
        a.f = limit;
        a.u = a.u & 0x7fffffff;
        simple = a.f <= 1e-05f;
    }
    if (simple) {
        FUN_0001df20(&world, &d);
    } else {
        double q = dist / limit;
        int n = (int)q;
        if (q - (float)n > 0.0f)
            n++;
        if (n > 0x40)
            n = 0x40;
        double step = dist / (float)n;
        Vec3 cur = pos;
        Vec3 sv = d;
        sv.x = (float)(sv.x * step);
        sv.y = (float)(sv.y * step);
        sv.z = (float)(sv.z * step);
        for (int i = 0; i < n; i++) {
            cur.x = cur.x + sv.x;
            cur.y = cur.y + sv.y;
            cur.z = cur.z + sv.z;
            FUN_0001df20(&cur, &d);
            if (finished)
                break;
        }
    }

    if (effect != 0) {
        Mat t;
        t.FUN_0022b980();
        t.m[12] = world.x;
        t.m[13] = world.y;
        t.m[14] = world.z;
        effect->vfunc_6(&t, arg);
    }
    pos.x = world.x;
    pos.y = world.y;
    pos.z = world.z;
    return !finished;
}
