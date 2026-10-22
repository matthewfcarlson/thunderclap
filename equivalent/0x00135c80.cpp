// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::FlyingDashAction::vfunc_3 @ 0x00135c80
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
struct V3_135c80 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3_135c80* other, float epsilon);
};

struct Transform_135c80 {
    void FUN_00221be0(const V3_135c80* pose);
    void FUN_00221d20(float v);
};

struct ResourceName_135c80 {
    char data[12];
    void FUN_0027b040(const char* name);
};

class JointDriver_135c80 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_135c80 name;
    unsigned int flags;
    Transform_135c80 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_135c80)];
    JointDriver_135c80* FUN_002248f0(unsigned int id);
};

struct Scene_135c80 {
    char pad0[0x10];
    V3_135c80 pos;
    void FUN_00222890(JointDriver_135c80* obj, float a, float b, float c, float d, float e, float f);
};

struct Config_135c80 {
    char pad0[0x14];
    float scale;                // 0x14
    float f18;
    float f1c;
    float f20;
};

struct Target_135c80 {
    char pad0[0x10];
    V3_135c80 pos;
};

struct Stats_135c80 {
    char pad0[0x328];
    Target_135c80* target;             // 0x328
    unsigned char targetActive; // 0x32c
    char pad32d[0x2064 - 0x32d];
    V3_135c80 aim;                     // 0x2064
    float aimBias;              // 0x2070
    bool FUN_000356c0(V3_135c80* out);
    void FUN_00035550(V3_135c80* out);
};

struct Pool_135c80 {
    Stats_135c80* FUN_00059a30();
    Scene_135c80* FUN_00059a40();
    bool FUN_00059a50(V3_135c80* out);
};

struct Owner_135c80 {
    Pool_135c80* FUN_000592a0();
};

union FloatBits_135c80 {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits_135c80 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

void* __cdecl thunk_FUN_0008d690(unsigned int size);
void __cdecl FUN_00096a90(Target_135c80* t, V3_135c80* out);
extern "C" float FUN_00224ea0(float x, float z);

namespace hulkfight { namespace motion {

class FlyingDashAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Config_135c80* cfg;                // 0x1c
    Owner_135c80* owner;               // 0x20
    JointDriver_135c80* rig;             // 0x24
    V3_135c80 dir;                     // 0x28
};

char FlyingDashAction::vfunc_3(int a, int b)
{
    Pool_135c80* pool = owner->FUN_000592a0();
    Stats_135c80* stats = pool->FUN_00059a30();
    Scene_135c80* scene = pool->FUN_00059a40();
    if (scene == 0)
        return 0;

    float f18 = cfg->f18;
    float f1c = cfg->f1c;
    float f20 = cfg->f20;

    void* mem = thunk_FUN_0008d690(0x70);
    JointDriver_135c80* obj = 0;
    if (mem)
        obj = ((JointDriver_135c80*)mem)->FUN_002248f0(0);
    rig = obj;
    obj->name.FUN_0027b040("flyingDash");
    rig->vfunc_0();
    rig->transform.FUN_00221be0(&scene->pos);
    scene->FUN_00222890(rig, -1.0f, f18, 1.0f, f1c, f20, -1.0f);

    bool useTarget = false;
    V3_135c80 r;
    Target_135c80* target = stats->target;
    if (target != 0 && stats->targetActive) {
        V3_135c80 q;
        q.x = 0.0f;
        q.y = 0.0f;
        q.z = 0.0f;
        pool->FUN_00059a50(&q);
        r.x = 0.0f;
        r.y = 0.0f;
        r.z = 0.0f;
        FUN_00096a90(target, &r);
        r.x = r.x - q.x;
        r.y = 0.0f;
        r.z = r.z - q.z;
        r.FUN_0022d110();

        V3_135c80 w;
        w.x = stats->aim.x;
        w.y = 0.0f;
        w.z = stats->aim.z;
        w.FUN_0022d110();

        if (stats->aimBias <= 0.0f) {
            useTarget = true;
        } else {
            float dot = w.z * r.z + r.x * w.x + w.y * r.y;
            if (dot > 0.707106769f)
                useTarget = true;
        }
    }

    if (useTarget) {
        dir.x = r.x;
        dir.y = r.y;
        dir.z = r.z;
    } else {
        dir = stats->aim;
        dir.y = 0.0f;
        float len = dir.FUN_0022d110();
        if (AbsF(len) <= 1e-5f) {
            stats->FUN_000356c0(&dir);
            dir.y = 0.0f;
            len = dir.FUN_0022d110();
            if (AbsF(len) <= 1e-5f)
                stats->FUN_00035550(&dir);
        }
    }

    float k = cfg->scale;
    dir.x = k * dir.x;
    dir.y = k * dir.y;
    dir.z = k * dir.z;
    float ang = FUN_00224ea0(dir.x, dir.z);
    rig->transform.FUN_00221d20(ang);
    return 1;
}

}}
