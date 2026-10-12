// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 18/18)
// hulkfight::motion::HitFloatAction::vfunc_5 @ 0x0014fad0
struct V3 {
    float x, y, z;
    bool FUN_0022d2b0(const V3 *other, float eps);
    float FUN_0022d110();
};

struct Transform {
    void FUN_0022be40(const V3 *pos);
};

class FloatObject {
public:
    virtual void vfunc_0();
    char pad04[0x18 - 4];
    Transform transform;
};

struct Target {
    char pad0[0x28];
    V3 size;
    char pad34[0x5c - 0x34];
    float limit;
};

struct PlayerCfg {
    char pad0[0x2c];
    float f2c;
    char pad30[4];
    float f34;
};

struct Player {
    char pad0[0x11c];
    PlayerCfg *cfg;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1ae0 - 0x144];
    V3 v1ae0;
    char pad1aec[0x1af8 - 0x1aec];
    V3 v1af8;
    void FUN_000359c0(int a);
    void FUN_00035550(V3 *out);
    void FUN_000357a0(const V3 *v);
};

struct Mgr {
    Player *FUN_00059a30();
    bool FUN_00059a50(V3 *out);
};

struct Holder {
    Mgr *FUN_000592a0();
};

struct Grav {
    char pad0[0x10];
    V3 v;
};

extern V3 DAT_004afa08;
extern Grav *DAT_00554c10;
float DAT_003f3320;
float DAT_003f3388;
float __cdecl FUN_00224f10(const V3 *v);
void __cdecl FUN_00224d70(float angle, V3 *v);

class Owner {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Target *vfunc_3();
};

union Arg1 {
    int skip;
    float angle;
};

class HitFloatAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(Arg1 a, float dt);
    char pad04[0x20 - 4];
    Owner *owner;
    FloatObject *floatObj;
    float time;
    float speed;
    float f30;
    float f34;
};

bool HitFloatAction::vfunc_5(Arg1 a, float dt)
{
    V3 vecA;
    V3 dir;
    V3 vecB;
    V3 pos;

    if (a.skip)
        return true;
    if (!floatObj)
        return false;
    Target *target = owner->vfunc_3();
    if (!target)
        return false;

    Holder *holder = (Holder *)owner;
    Mgr *mgr = holder->FUN_000592a0();
    Player *pl = mgr->FUN_00059a30();
    pl->FUN_000359c0(3);
    a.angle = FUN_00224f10(&target->size);
    dir = DAT_004afa08;
    FUN_00224d70(a.angle, &dir);
    float k = dt * speed;
    dir.x = dir.x * k;
    dir.z = dir.z * k;
    mgr->FUN_00059a50(&pos);

    if (pl->mode == 4) {
        vecA = pl->v1af8;
        vecB.x = 0.0f;
        vecB.y = 0.0f;
        vecB.z = 0.0f;
        if (vecA.FUN_0022d2b0(&vecB, 0.00001f)) {
            vecA = pl->v1ae0;
            vecB.x = 0.0f;
            vecB.y = 0.0f;
            vecB.z = 0.0f;
            if (vecA.FUN_0022d2b0(&vecB, 0.00001f)) {
                pl->FUN_00035550(&vecA);
                vecA.x = vecA.x * DAT_003f3388;
                vecA.z = vecA.z * DAT_003f3388;
            }
        }
        vecA.y = 0.0f;
        vecA.FUN_0022d110();
        float s = pl->cfg->f34;
        vecA.x = vecA.x * s;
        vecA.y = vecA.y * s;
        vecA.z = vecA.z * s;
        pl->FUN_000357a0(&vecA);
    } else if (pl->mode != 3) {
        dir.y = dir.y + pl->cfg->f2c;
    }

    dir.x = pos.x + dir.x;
    dir.y = pos.y + dir.y;
    dir.z = pos.z + dir.z;
    time = time + dt;
    vecB = DAT_00554c10->v;
    a.angle = vecB.y * DAT_003f3320;
    if (time > target->limit) {
        if (f34 < a.angle)
            f34 = a.angle;
    }
    f30 = f30 - dt * f34;
    dir.y = f30 * dt + dir.y;
    floatObj->transform.FUN_0022be40(&dir);
    return true;
}
