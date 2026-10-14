// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 16/16)
// CWallSlideAction::vfunc_6 @ 0x00020de0
extern "C" double sqrt(double);

struct Vec3_20de0 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const Vec3_20de0 *other, float eps);
};

struct Transform_20de0 {
    void FUN_00222180(const Vec3_20de0 *dir);
};

struct ResourceName_20de0 {
    char data[12];
    void FUN_0027b040(const char *name);
};

class JointObject_20de0 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_20de0 name;
    char pad14[0x18 - 0x14];
    Transform_20de0 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_20de0)];
    JointObject_20de0 *FUN_002248f0(unsigned int id);
};

struct Scene_20de0 {
    void FUN_00222890(JointObject_20de0 *obj, float a, int b, float c, float d, float e, float f);
};

struct Tracker_20de0 {
    char pad[0x1ae0];
    Vec3_20de0 alt;
    char pad2[0x1af8 - 0x1aec];
    Vec3_20de0 main;
    bool FUN_000356c0(Vec3_20de0 *out);
};

struct Fighter_20de0 {
    Tracker_20de0 *FUN_00059a30();
    Scene_20de0 *FUN_00059a40();
};

struct Owner_20de0 {
    Fighter_20de0 *FUN_000592a0();
};

class Shape_20de0 {
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
    Owner_20de0 *owner;
    Shape_20de0 *shape;
    JointObject_20de0 *joint;
    float k;
    Vec3_20de0 slide;
};

struct Frame_20de0 {
    float r;
    float g28;
    Vec3_20de0 V;
    Vec3_20de0 W;
    Vec3_20de0 T;
};

bool CWallSlideAction::vfunc_6(int arg)
{
    Fighter_20de0 *fighter = owner->FUN_000592a0();
    Tracker_20de0 *trk = fighter->FUN_00059a30();
    Scene_20de0 *scene = fighter->FUN_00059a40();
    if (scene == 0)
        return false;

    Frame_20de0 fr;
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

    Shape_20de0 *sh = shape;
    float g28 = sh->f28;
    float g2c = sh->f2c;
    int g24 = sh->f24;
    void *mem = FUN_00263ea0(0x70);
    JointObject_20de0 *obj = 0;
    if (mem)
        obj = ((JointObject_20de0 *)mem)->FUN_002248f0(0);
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
