// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 11/12, incomplete)
// FUN_002b4990 @ 0x002b4990
#include "decls/data/game/global.h"

struct Vec3_2b4990 {
    float x, y, z;
    void FUN_0022c3b0(const Vec3_2b4990*, Vec3_2b4990*);
    void FUN_0022d180();
};

struct Vec4_2b4990 {
    float x, y, z, w;
};

class Probe_2b4990 {
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
    virtual Vec3_2b4990 *vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual char vfunc_16(Vec3_2b4990 *pos, float w);
};

struct Scene_2b4990 {
    char pad0[0x18];
    Probe_2b4990 *probe;
    void FUN_00294500(Vec3_2b4990 origin, Vec3_2b4990 *target);
    void FUN_002940d0(const Vec3_2b4990 *from, Vec3_2b4990 *out);
};

struct SceneRoot_2b4990 {
    char pad0[8];
    Scene_2b4990 *scene;
};

struct World {
    SceneRoot_2b4990 *root;
};

class Mover_2b4990 {
public:
    char pad0[0x2c];
    Vec4_2b4990 origin;
    char pad3c[0x4c - 0x3c];
    float reach;
    float pending;
    char useScene;
    char pad55[0x64 - 0x55];
    Vec3_2b4990 goal;

    void FUN_002b4990();
};

void Mover_2b4990::FUN_002b4990()
{
    if (pending != 0.0f) {
        reach = pending;
        return;
    }
    if (reach != 0.0f)
        return;

    Scene_2b4990 *scene = (*(World**)&DAT_0052c2b0)->root->scene;
    Probe_2b4990 *probe = scene->probe;
    Vec4_2b4990 pos = origin;
    Vec3_2b4990 dir;
    scene->FUN_00294500(*(Vec3_2b4990 *)&origin, (Vec3_2b4990 *)&pos);
    if (useScene == 0) {
        probe->vfunc_13()->FUN_0022c3b0(&goal, &dir);
    } else {
        Vec3_2b4990 from;
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
        if (probe->vfunc_16((Vec3_2b4990 *)&pos, pos.w) == 0)
            break;
        steps++;
    } while (steps < 100);
    reach = (float)steps;
}
