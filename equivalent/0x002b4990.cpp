// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/12, incomplete)
// FUN_002b4990 @ 0x002b4990
struct Vec3 {
    float x, y, z;
    void FUN_0022c3b0();
    void FUN_0022d180();
};

struct Vec4 {
    float x, y, z, w;
};

class Probe {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual Vec3 *vfunc_13(const Vec3 *from, Vec3 *out);
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual char vfunc_16(Vec3 *pos, float w);
};

struct Scene {
    char pad0[0x18];
    Probe *probe;
    void FUN_00294500(Vec3 origin, Vec3 *target);
    void FUN_002940d0(const Vec3 *from, Vec3 *out);
};

struct SceneRoot {
    char pad0[8];
    Scene *scene;
};

struct World {
    SceneRoot *root;
};
extern World *DAT_0052c2b0;

class Mover {
public:
    char pad0[0x2c];
    Vec4 origin;
    char pad3c[0x4c - 0x3c];
    float reach;
    float pending;
    char useScene;
    char pad55[0x64 - 0x55];
    Vec3 goal;

    void FUN_002b4990();
};

void Mover::FUN_002b4990()
{
    if (pending != 0.0f) {
        reach = pending;
        return;
    }
    if (reach != 0.0f)
        return;

    Scene *scene = DAT_0052c2b0->root->scene;
    Probe *probe = scene->probe;
    Vec4 pos = origin;
    Vec3 dir;
    scene->FUN_00294500(*(Vec3 *)&origin, (Vec3 *)&pos);
    if (useScene == 0) {
        probe->vfunc_13(&goal, &dir)->FUN_0022c3b0();
    } else {
        Vec3 from;
        scene->FUN_002940d0(&goal, &from);
        dir.x = pos.x - from.x;
        dir.y = pos.y - from.y;
        dir.z = pos.z - from.z;
        dir.FUN_0022d180();
    }
    unsigned int steps = 1;
    do {
        pos.x = dir.x + pos.x;
        pos.y = dir.y + pos.y;
        pos.z = dir.z + pos.z;
        if (probe->vfunc_16((Vec3 *)&pos, pos.w) == 0)
            break;
        steps++;
    } while (steps < 100);
    reach = (float)steps;
}
