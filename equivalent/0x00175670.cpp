// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 26/26)
// hulkfight::motion::DriftToHulkAction::vfunc_5 @ 0x00175670
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
};

struct Marker {
    char pad00[0x14];
    Vec3 offset;
};

struct Item {
    char pad00[0x1b0];
    int kind;
};

struct Target {
    char pad00[0x40];
    Vec3 pos;
};

struct Actor {
    char pad000[0x11c];
    Item *item;
    char pad120[0x328 - 0x120];
    Target *target;
    char pad32c[0x2064 - 0x32c];
    Vec3 direction;
    float strength;
    char pad2074[0x20a8 - 0x2074];
    int priority;

    void FUN_0003ffa0(Target *t, int flag);
    void FUN_00035720(Vec3 *v);
};

struct Body {
    Actor *FUN_00059a30();
    void FUN_00059a50(Vec3 *out);
};

struct Owner {
    Body *FUN_000592a0();
};

struct Rival {
    char pad000[0x11c];
    Item *item;
    char pad120[0x12c - 0x120];
    Target *target;
};

struct Scene {
    char pad00[0x124];
    Rival *rival;
};

struct Game {
    char pad00[0x20];
    Scene *scene;
};

extern Game *DAT_004dd700;

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
    Marker *marker;         // 0x1c
    Owner *owner;           // 0x20
    char pad24[0x30 - 0x24];
    float timer;            // 0x30
};

}
}

bool hulkfight::motion::DriftToHulkAction::vfunc_5(int mode, float dt)
{
    struct Frame {
        Vec3 e;
        Vec3 d;
        float ax;
        float spill1c;
        float spill20;
        Vec3 v;
    } fr;

    if (mode != 0 || dt == 0.0f)
        return true;

    Game *game = DAT_004dd700;
    Body *body = owner->FUN_000592a0();
    if (body == 0)
        return false;
    Actor *actor = body->FUN_00059a30();
    if (actor == 0)
        return false;
    body->FUN_00059a50(&fr.v);

    Target *t = actor->target;
    if (t == 0) {
        if (actor->priority >= 0)
            return true;
        Item *mine = actor->item;
        if (mine == 0)
            return true;
        Rival *rival = game->scene->rival;
        if (rival == 0)
            return true;
        t = rival->target;
        if (t == 0)
            return true;
        Item *theirs = rival->item;
        if (theirs == 0)
            return true;
        if (mine->kind == theirs->kind)
            return true;
        actor->FUN_0003ffa0(t, 0);
    }

    Vec3 *w = &marker->offset;
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
