// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 16/16)
// CWallSlideAction::vfunc_6 @ 0x00020de0
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const Vec3 *other, float eps);
};

struct Transform {
    void FUN_00222180(const Vec3 *dir);
};

struct ResourceName {
    char data[12];
    void FUN_0027b040(const char *name);
};

class JointObject {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName name;
    char pad14[0x18 - 0x14];
    Transform transform;
    char rest[0x70 - 0x18 - sizeof(Transform)];
    JointObject *FUN_002248f0(unsigned int id);
};

struct Scene {
    void FUN_00222890(JointObject *obj, float a, int b, float c, float d, float e, float f);
};

struct Tracker {
    char pad[0x1ae0];
    Vec3 alt;
    char pad2[0x1af8 - 0x1aec];
    Vec3 main;
    bool FUN_000356c0(Vec3 *out);
};

struct Fighter {
    Tracker *FUN_00059a30();
    Scene *FUN_00059a40();
};

struct Owner {
    Fighter *FUN_000592a0();
};

class Shape {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    char pad04[0x14 - 4];
    float f14;
    char pad18[0x24 - 0x18];
    int f24;
    float f28;
    float f2c;
};

void *__cdecl FUN_00263ea0(unsigned int size);

class CWallSlideAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x1c - 4 - 0x0];
    Owner *owner;
    Shape *shape;
    JointObject *joint;
    float k;
    Vec3 slide;
};

struct Frame {
    float r;
    float g28;
    Vec3 V;
    Vec3 W;
    Vec3 T;
};

bool CWallSlideAction::vfunc_6(int arg)
{
    Fighter *fighter = owner->FUN_000592a0();
    Tracker *trk = fighter->FUN_00059a30();
    Scene *scene = fighter->FUN_00059a40();
    if (scene == 0)
        return false;

    Frame fr;
    fr.V = trk->main;
    fr.W.x = 0.0f;
    fr.W.y = 0.0f;
    fr.W.z = 0.0f;
    if (fr.V.FUN_0022d2b0(&fr.W, 1e-05f)) {
        fr.V = trk->alt;
        fr.W.x = 0.0f;
        fr.W.y = 0.0f;
        fr.W.z = 0.0f;
        if (fr.V.FUN_0022d2b0(&fr.W, 1e-05f))
            return false;
    }

    slide.z = 0.0f;
    slide.y = 0.0f;
    slide.x = 0.0f;
    if (!trk->FUN_000356c0(&slide))
        return false;

    if ((fr.V.z * slide.z + fr.V.y * slide.y + fr.V.x * slide.x) < 0.0f) {
        double n = -(fr.V.z * slide.z + fr.V.y * slide.y + fr.V.x * slide.x);
        float tx = fr.V.x;
        float ty = fr.V.y;
        float tz = fr.V.z;
        double px = tx * n;
        volatile float py = (float)(ty * n);
        volatile float pz = (float)(tz * n);
        slide.x = (float)(px + slide.x);
        slide.y = py + slide.y;
        slide.z = pz + slide.z;
    }

    k = shape->f14;
    fr.r = shape->vfunc_7();
    if (fr.r > 0.0f) {
        double len = sqrt((double)(slide.x * slide.x + slide.y * slide.y + slide.z * slide.z));
        if (len > fr.r * k)
            k = (float)(len / fr.r);
    }

    Shape *sh = shape;
    float g28 = sh->f28;
    float g2c = sh->f2c;
    int g24 = sh->f24;
    void *mem = FUN_00263ea0(0x70);
    JointObject *obj = 0;
    if (mem)
        obj = ((JointObject *)mem)->FUN_002248f0(0);
    joint = obj;
    obj->name.FUN_0027b040("wallSlide");
    joint->vfunc_0();

    fr.T.x = fr.V.x * -1.0f;
    fr.T.y = 0.0f * -1.0f;
    fr.T.z = fr.V.z * -1.0f;
    fr.T.FUN_0022d110();
    joint->transform.FUN_00222180(&fr.T);

    scene->FUN_00222890(joint, -1.0f, g24, 1.0f, g28, g2c, -1.0f);
    return true;
}
