// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 20/20)
// hulkfight::motion::BallAndChainShootAction::vfunc_3 @ 0x00184940
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

class Obj {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Xform {
    char data[0x54];
    Xform *FUN_00221c40();
    void FUN_0022c2b0(const V3 *in, V3 *out);
};

struct Skeleton {
    char pad0[0x10];
    Xform xform;
};

class Weapon {
public:
    void FUN_001d8c70(Obj *attached);
    int FUN_001d72e0();
};

class Fighter {
public:
    char pad0[0x328];
    Obj *held;
    Weapon *FUN_00035ef0(int slot);
    float FUN_0003ec00(int mode);
    float FUN_000354c0();
};

struct Holder {
    Fighter *FUN_00059a30();
    Skeleton *FUN_00059a40();
};

class Params {
public:
    Holder *FUN_000592a0();
};

struct Manager {
    char pad0[0x124];
    Fighter *active;
    void FUN_00029b50(int a, Obj *b, float c);
};

struct World {
    char pad0[0x20];
    Manager *manager;
};

struct ShootConfig {
    char pad0[0x14];
    int slot;           // 0x14
    V3 origin;          // 0x18
    V3 direction;       // 0x24
    char pad30[0x3c - 0x30];
    float lerp[3][2];   // 0x3c
    float arg54;        // 0x54
    float arg58;        // 0x58
};

extern World *DAT_004dd700;

void __cdecl FUN_00224d70(float angle, V3 *v);
int __cdecl FUN_00097a30(float a, float b, float c, Obj *obj, float d, V3 *pos, float e, V3 *dir,
                         int f, int g, int h, int i);

class BallAndChainShootAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    ShootConfig *cfg;    // 0x1c
    Params *owner;       // 0x20
    Obj *attached;       // 0x24
    V3 pos;              // 0x28
    V3 dir;              // 0x34
    float cur[3];        // 0x40
};

bool BallAndChainShootAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;

    Holder *holder = owner->FUN_000592a0();
    Fighter *fighter = holder->FUN_00059a30();
    Weapon *weapon = fighter->FUN_00035ef0(cfg->slot);
    if (weapon == 0)
        return true;

    float t = fighter->FUN_0003ec00(2);
    ShootConfig *c = cfg;
    cur[0] = (c->lerp[0][1] - c->lerp[0][0]) * t + c->lerp[0][0];
    cur[1] = (c->lerp[1][1] - c->lerp[1][0]) * t + c->lerp[1][0];
    cur[2] = (c->lerp[2][1] - c->lerp[2][0]) * t + c->lerp[2][0];

    Obj *held = fighter->held;
    if (held != 0)
        held->AddRef();
    if (attached != 0)
        attached->Release();
    attached = held;

    V3 origin = cfg->origin;
    holder->FUN_00059a40()->xform.FUN_00221c40()->FUN_0022c2b0(&origin, &pos);

    origin = cfg->direction;
    dir = origin;
    FUN_00224d70(fighter->FUN_000354c0(), &dir);
    dir.FUN_0022d110();

    if (FUN_00097a30(cur[1], cur[2], -1.0f, attached, cfg->arg58, &pos, cfg->arg54, &dir, 0, 0, 0, 1) != 0)
        weapon->FUN_001d8c70(attached);

    if (attached != 0) {
        World *w = DAT_004dd700;
        if (w != 0) {
            Manager *m = w->manager;
            if (m != 0) {
                if (m->active != 0 && m->active == fighter)
                    m->FUN_00029b50(weapon->FUN_001d72e0(), attached, cur[0]);
            }
        }
    }
    return true;
}
