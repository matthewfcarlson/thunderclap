// STATUS: equivalent (tools/equiv.py level 3: 127 inputs, branch coverage 35/38, incomplete)
// hulkfight::motion::TeleportRelativeAction::vfunc_5 @ 0x001759c0
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"

struct Vec3_1759c0 {
    float x, y, z;
};

struct Id_1759c0 {
    unsigned int lo, hi;
};

struct Matrix {
    char pad0[0x10];
    void FUN_0022c2b0(const Vec3_1759c0 *in, Vec3_1759c0 *out);
};

struct Flagged_1759c0 {
    char pad0[0x72];
    unsigned char flag72;
};

struct Holder_1759c0 {
    char pad0[0x74];
    Flagged_1759c0 *shield;
};

struct Node {
    char pad0[0x10];
    Matrix matrix;
    char pad_[0x40 - 0x10 - sizeof(Matrix)];
    Vec3_1759c0 pos;
    char pad4c[0x74 - 0x4c];
    Flagged_1759c0 *shield;
};

struct Game;
struct Actor_1759c0;

struct Tracer_1759c0 {
    bool FUN_0010aa90(Game *g, Vec3_1759c0 *a, Vec3_1759c0 *b, float scale, Vec3_1759c0 *o3, Vec3_1759c0 *o2, Vec3_1759c0 *o1,
                      Actor_1759c0 *actor, Node *n, int zero0, int zero1);
};

struct Actor_1759c0 {
    char pad0[0x12c];
    Holder_1759c0 *holder;
    char pad130[0x328 - 0x130];
    Node *node;
    char pad32c[0x1ca4 - 0x32c];
    Tracer_1759c0 *tracer;
    bool FUN_0003f400(Vec3_1759c0 *p);
    void FUN_00036e70(Id_1759c0 *id, int v);
};

struct Body_1759c0 {
    Actor_1759c0 *FUN_00059a30();
};

struct Owner_1759c0 {
    Body_1759c0 *FUN_000592a0();
};

struct HitList;

struct Manager_1759c0 {
    bool FUN_002ee140(HitList *list, Vec3_1759c0 *from, Vec3_1759c0 *to, int flags);
};

struct Params {
    char pad0[0x10];
    Vec3_1759c0 v10;
    Vec3_1759c0 limit;
    float scale;
};

struct Game;

extern Game *DAT_004dd700;
HitList *FUN_00202f00();

namespace hulkfight {
namespace motion {

class TeleportRelativeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int mode, float dt);

    char pad04[0x18];
    Params *params;  // 0x1c
    Owner_1759c0 *owner;    // 0x20
    char pad24[4];
    Id_1759c0 id;           // 0x28
};

}
}

bool hulkfight::motion::TeleportRelativeAction::vfunc_5(int mode, float dt)
{
    if (mode != 0)
        return true;
    if (owner == 0)
        return false;
    Actor_1759c0 *actor = owner->FUN_000592a0()->FUN_00059a30();
    Node *node = actor->node;
    if (node == 0)
        return false;

    Vec3_1759c0 in = params->v10;
    Vec3_1759c0 t;
    node->matrix.FUN_0022c2b0(&in, &t);

    Vec3_1759c0 q = params->limit;
    if (q.x != 0.0f) {
        Vec3_1759c0 r = params->limit;
        t.x = (t.x < r.x) ? r.x : t.x;
    }
    q = params->limit;
    if (q.y != 0.0f) {
        Vec3_1759c0 r = params->limit;
        t.y = (t.y < r.y) ? r.y : t.y;
    }
    q = params->limit;
    if (q.z != 0.0f) {
        Vec3_1759c0 r = params->limit;
        t.z = (t.z < r.z) ? r.z : t.z;
    }

    if (node->shield)
        node->shield->flag72 = 0;
    if (actor->holder && actor->holder->shield)
        actor->holder->shield->flag72 = 0;

    Tracer_1759c0 *tracer = actor->tracer;
    Game *game = DAT_004dd700;
    if (tracer && game) {
        DAT_004d2a3c = 2;
        (*(char*)&DAT_00554c1c) = 1;
        (*(float*)&DAT_00554c18) = 0.5f;
        Vec3_1759c0 s = node->pos;
        Vec3_1759c0 d;
        d.x = t.x - s.x;
        d.y = t.y - s.y;
        d.z = t.z - s.z;
        Vec3_1759c0 o2;
        Vec3_1759c0 o3;
        o2.z = d.z;
        float scale = params->scale;
        if (actor->tracer->FUN_0010aa90(game, &s, &t, scale, &o3, &o2, &d, actor, node, 0, 1))
            actor->FUN_0003f400(&t);
        else
            actor->FUN_00036e70(&id, 1);
    } else {
        HitList *list = FUN_00202f00();
        (*(float*)&DAT_00554c18) = (*(float*)&DAT_004b8540);
        DAT_004d2a3c = 2;
        (*(char*)&DAT_00554c1c) = 0;
        if ((*(Manager_1759c0**)&DAT_00554c14)->FUN_002ee140(list, &node->pos, &t, 0))
            actor->FUN_00036e70(&id, 1);
        else
            actor->FUN_0003f400(&t);
    }

    if (node->shield)
        node->shield->flag72 = 1;
    if (actor->holder && actor->holder->shield)
        actor->holder->shield->flag72 = 1;
    return true;
}
