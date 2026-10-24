// STATUS: equivalent (tools/equiv.py level 3: 3239 inputs, branch coverage 32/32; Wine build 740 inputs, 32/32)
// hulkfight::ai::ProjectileDistanceCondition::vfunc_6 @ 0x001254b0
extern "C" double sqrt(double);

struct V3_1254b0 {
    float x, y, z;
};

struct Aim_1254b0 {
    bool FUN_00059a50(V3_1254b0 *out);
};

struct Body_1254b0 {
    char pad0[0x1c9];
    char flag;
};

struct Weapon_1254b0 {
    char pad0[0x1b0];
    int state;
};

struct Rig_1254b0 {
    char pad0[0x11c];
    Weapon_1254b0 *weapon;
};

struct Target_1254b0 {
    char pad0[8];
    Rig_1254b0 *rig;             // 0x08 (a Body when type == 5)
    int type;             // 0x0c
    char pad10[0x40 - 0x10];
    V3_1254b0 pos;               // 0x40
};

struct Fighter_1254b0 {
    char pad0[0x10];
    Aim_1254b0 *aim;
    Target_1254b0 *FUN_00037400();
};

struct Holder_1254b0 {
    Fighter_1254b0 *FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void v0();
    Holder_1254b0 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
};

bool __cdecl FUN_00018960(float a, float b, float eps);

class ProjectileDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int b);
    char pad04[0x0c - 4];
    int op;             // 0x0c
    float threshold;    // 0x10
    char requireLive;   // 0x14
    char skipNonBody;   // 0x15
};

bool ProjectileDistanceCondition::vfunc_6(int a, fight::Params *params, int b)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Fighter_1254b0 *f = params->FUN_000592a0()->FUN_00059a30();
    V3_1254b0 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    f->aim->FUN_00059a50(&origin);

    Target_1254b0 *t = f->FUN_00037400();
    if (t == 0)
        return false;

    int type = t->type;
    if (type == 5) {
        if (((Body_1254b0 *)t->rig)->flag == 0)
            return false;
    } else {
        if (skipNonBody != 0)
            return false;
    }

    if (requireLive != 0) {
        if (type != 1)
            return false;
        if (t->rig != 0) {
            if (t->rig->weapon->state != 3)
                return false;
        }
    }

    V3_1254b0 *p = &t->pos;
    float dx = p->x - origin.x;
    float dy = p->y - origin.y;
    float dz = p->z - origin.z;
    float dist = (float)sqrt(dz * dz + dy * dy + dx * dx);

    switch (op) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 1e-05f);
    case 3:
        return !FUN_00018960(dist, threshold, 1e-05f);
    case 4:
        return dist >= threshold;
    case 5:
        return dist > threshold;
    }
    return false;
}
