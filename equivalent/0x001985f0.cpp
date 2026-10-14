// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 27/28, incomplete)
// hulkfight::motion::MissileThrowAction::vfunc_3 @ 0x001985f0
struct V3_1985f0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Node;

struct Weapon_1985f0;

class CProjectile {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Weapon_1985f0 *v5();
};

struct MissileSub {
    char pad0[0x60];
    float f60;
    float f64;
};

namespace hulkfight {
namespace motion {

class ProjectileMissile : public CProjectile {
public:
    char pad04[0x3c - 4];
    MissileSub *sub;        // 0x3c
    char pad40[0x6c - 0x40];
    V3_1985f0 dir;                 // 0x6c
    float f78;
    char pad7c[0x84 - 0x7c];
    float f84;
    float f88;
    float f8c;
    float f90;
    char pad94[0x9c - 0x94];
    int f9c;
    void FUN_00196640(Node *node);
};

}
}

struct Entity {
    char pad0[0x40];
    V3_1985f0 anchor;      // 0x40
};

struct Weapon_1985f0 {
    Entity *FUN_001d72e0();
};

struct Fighter_1985f0 {
    char pad0[0x328];
    Node *node;
    char pad32c[0x2000 - 0x32c];
    float f2000;
    char pad2004[0x20a8 - 0x2004];
    int f20a8;
    Weapon_1985f0 *FUN_00035ef0(int slot);
    float FUN_0003ec00(int mode);
    float FUN_000354c0();
    void FUN_0003acf0(int slot, int a, int b, int c, int d, int e);
};

struct Holder_1985f0 {
    Fighter_1985f0 *FUN_00059a30();
};

struct Params {
    Holder_1985f0 *FUN_000592a0();
};

struct Projectiles {
    CProjectile *FUN_001b68e0(int index);
};

struct World {
    char pad0[0x14];
    Projectiles *projectiles;
};

struct Cfg_1985f0 {
    char pad0[0x10];
    int slot;           // 0x10
    V3_1985f0 dir;             // 0x14
    float lerp[4][2];   // 0x20
    float arg40;        // 0x40
    float tLimit;       // 0x44
};

extern World *DAT_004dd700;

void __cdecl FUN_00224d70(float angle, V3_1985f0 *v);
int __cdecl FUN_00097a30(float a, float b, float c, Node *node, float d, V3_1985f0 *pos, float e, V3_1985f0 *dir,
                         int f, int g, int h, int i);

namespace hulkfight {
namespace motion {

class MissileThrowAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x18];
    Cfg_1985f0 *cfg;       // 0x1c
    Params *owner;  // 0x20
};

}
}

bool hulkfight::motion::MissileThrowAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;

    Holder_1985f0 *holder = owner->FUN_000592a0();
    Fighter_1985f0 *fighter = holder->FUN_00059a30();
    if (holder == 0 || fighter == 0)
        return false;

    int slot = cfg->slot;
    Weapon_1985f0 *weapon = fighter->FUN_00035ef0(slot);
    if (weapon == 0)
        return false;

    Projectiles *list = DAT_004dd700->projectiles;
    CProjectile *proj = 0;
    int i;
    for (i = 0; i < 0x20; i++) {
        proj = list->FUN_001b68e0(i);
        if (proj != 0 && proj->v5() == weapon)
            break;
    }
    if (i >= 0x20)
        return false;

    ProjectileMissile *missile = dynamic_cast<ProjectileMissile *>(proj);
    if (missile == 0)
        return false;

    Entity *entity = weapon->FUN_001d72e0();
    if (entity == 0)
        return false;

    float t = fighter->FUN_0003ec00(2);
    Cfg_1985f0 *c = cfg;
    float v0 = (c->lerp[0][1] - c->lerp[0][0]) * t + c->lerp[0][0];
    float v1 = (c->lerp[1][1] - c->lerp[1][0]) * t + c->lerp[1][0];
    float v2 = (c->lerp[2][1] - c->lerp[2][0]) * t + c->lerp[2][0];
    float v3 = (c->lerp[3][1] - c->lerp[3][0]) * t + c->lerp[3][0];
    Node *node = fighter->node;
    float angle = fighter->FUN_000354c0();

    V3_1985f0 d = cfg->dir;
    FUN_00224d70(angle, &d);
    d.FUN_0022d110();

    V3_1985f0 p = entity->anchor;
    FUN_00097a30(v1, v3, -1.0f, node, 0.0f, &p, cfg->arg40, &d, 0, 0, 0, 1);
    fighter->FUN_0003acf0(slot, 0, -1, 0, 0, 0);

    if (!(t >= cfg->tLimit)) {
        missile->dir.x = d.x;
        missile->dir.y = d.y;
        missile->dir.z = d.z;
        missile->FUN_00196640(node);
        missile->f78 = v1;
        missile->f84 = v1;
        missile->f88 = 0.0f;
        missile->f8c = v0;
        if (fighter->f20a8 >= 0 && fighter->f2000 < 0.0f)
            missile->f90 = -v2;
        else
            missile->f90 = v2;
        missile->f9c = 0;
        return true;
    }

    MissileSub *sub = missile->sub;
    missile->dir.x = d.x;
    missile->dir.y = d.y;
    missile->dir.z = d.z;
    missile->FUN_00196640(node);
    float v = sub->f60;
    missile->f84 = v;
    if (v > 0.0f) {
        if (v1 > v)
            v1 = v;
    }
    missile->f78 = v1;
    missile->f88 = sub->f64;
    missile->f8c = -1.0f;
    missile->f90 = 0.0f;
    missile->f9c = 1;
    return true;
}
