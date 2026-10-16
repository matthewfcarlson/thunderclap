// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 26/26)
// hulkfight::motion::DriftToHulkAction::vfunc_5 @ 0x00175670
#include "decls/address.h"
struct Vec3_175670 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
};

struct Marker_175670 {
    char pad00[0x14];
    Vec3_175670 offset;
};

struct Item_175670 {
    char pad00[0x1b0];
    int kind;
};

struct Target_175670 {
    char pad00[0x40];
    Vec3_175670 pos;
};

struct Actor_175670 {
    char pad000[0x11c];
    Item_175670 *item;
    char pad120[0x328 - 0x120];
    Target_175670 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_175670 direction;
    float strength;
    char pad2074[0x20a8 - 0x2074];
    int priority;

    void FUN_0003ffa0(Target_175670 *t, int flag);
    void FUN_00035720(Vec3_175670 *v);
};

struct Body_175670 {
    Actor_175670 *FUN_00059a30();
    void FUN_00059a50(Vec3_175670 *out);
};

struct Owner_175670 {
    Body_175670 *FUN_000592a0();
};

struct Rival {
    char pad000[0x11c];
    Item_175670 *item;
    char pad120[0x12c - 0x120];
    Target_175670 *target;
};

struct Scene_175670 {
    char pad00[0x124];
    Rival *rival;
};

struct World {
    char pad00[0x20];
    Scene_175670 *scene;
};


namespace hulkfight {
namespace motion {

class DriftToHulkAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int mode, float dt);

    char pad04[0x18];
    Marker_175670 *marker;         // 0x1c
    Owner_175670 *owner;           // 0x20
    char pad24[0x30 - 0x24];
    float timer;            // 0x30
};

}
}

bool hulkfight::motion::DriftToHulkAction::vfunc_5(int mode, float dt)
{
    struct Frame {
        Vec3_175670 e;
        Vec3_175670 d;
        float ax;
        float spill1c;
        float spill20;
        Vec3_175670 v;
    } fr;

    if (mode != 0 || dt == 0.0f)
        return true;

    World *game = DAT_004dd700;
    Body_175670 *body = owner->FUN_000592a0();
    if (body == 0)
        return false;
    Actor_175670 *actor = body->FUN_00059a30();
    if (actor == 0)
        return false;
    body->FUN_00059a50(&fr.v);

    Target_175670 *t = actor->target;
    if (t == 0) {
        if (actor->priority >= 0)
            return true;
        Item_175670 *mine = actor->item;
        if (mine == 0)
            return true;
        Rival *rival = game->scene->rival;
        if (rival == 0)
            return true;
        t = rival->target;
        if (t == 0)
            return true;
        Item_175670 *theirs = rival->item;
        if (theirs == 0)
            return true;
        if (mine->kind == theirs->kind)
            return true;
        actor->FUN_0003ffa0(t, 0);
    }

    Vec3_175670 *w = &marker->offset;
    fr.ax = w->x + t->pos.x;
    fr.d.x = fr.ax - fr.v.x;
    fr.d.y = (w->y + t->pos.y) - fr.v.y;
    fr.d.z = (w->z + t->pos.z) - fr.v.z;
    float len = fr.d.FUN_00018990();
    float m = (timer > dt ? dt / timer : 1.0f) * len;
    fr.e = fr.d;
    fr.e.FUN_0022d110();
    fr.e.x = fr.e.x * m;
    fr.e.y = fr.e.y * m;
    fr.e.z = fr.e.z * m;
    actor->FUN_00035720(&fr.e);
    actor->direction = fr.e;
    actor->direction.FUN_0022d110();
    actor->strength = 1.0f;
    timer = timer - dt;
    return !(timer <= 0.0f);
}
