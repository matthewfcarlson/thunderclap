// STATUS: equivalent (tools/equiv.py level 3: 127 inputs, branch coverage 35/38, incomplete)
// hulkfight::motion::TeleportRelativeAction::vfunc_5 @ 0x001759c0
struct Vec3 {
    float x, y, z;
};

struct Id {
    unsigned int lo, hi;
};

struct Matrix {
    char pad0[0x10];
    void FUN_0022c2b0(const Vec3 *in, Vec3 *out);
};

struct Flagged {
    char pad0[0x72];
    unsigned char flag72;
};

struct Holder {
    char pad0[0x74];
    Flagged *shield;
};

struct Node {
    char pad0[0x10];
    Matrix matrix;
    char pad_[0x40 - 0x10 - sizeof(Matrix)];
    Vec3 pos;
    char pad4c[0x74 - 0x4c];
    Flagged *shield;
};

struct Game;
struct Actor;

struct Tracer {
    bool FUN_0010aa90(Game *g, Vec3 *a, Vec3 *b, float scale, Vec3 *o3, Vec3 *o2, Vec3 *o1,
                      Actor *actor, Node *n, int zero0, int zero1);
};

struct Actor {
    char pad0[0x12c];
    Holder *holder;
    char pad130[0x328 - 0x130];
    Node *node;
    char pad32c[0x1ca4 - 0x32c];
    Tracer *tracer;
    bool FUN_0003f400(Vec3 *p);
    void FUN_00036e70(Id *id, int v);
};

struct Body {
    Actor *FUN_00059a30();
};

struct Owner {
    Body *FUN_000592a0();
};

struct HitList;

struct Manager {
    bool FUN_002ee140(HitList *list, Vec3 *from, Vec3 *to, int flags);
};

struct Params {
    char pad0[0x10];
    Vec3 v10;
    Vec3 limit;
    float scale;
};

struct Game;

extern Game *DAT_004dd700;
extern int DAT_004d2a3c;
extern Manager *DAT_00554c14;
extern float DAT_00554c18;
extern char DAT_00554c1c;
extern float DAT_004b8540;
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
    Owner *owner;    // 0x20
    char pad24[4];
    Id id;           // 0x28
};

}
}

bool hulkfight::motion::TeleportRelativeAction::vfunc_5(int mode, float dt)
{
    if (mode != 0)
        return true;
    if (owner == 0)
        return false;
    Actor *actor = owner->FUN_000592a0()->FUN_00059a30();
    Node *node = actor->node;
    if (node == 0)
        return false;

    Vec3 in = params->v10;
    Vec3 t;
    node->matrix.FUN_0022c2b0(&in, &t);

    Vec3 q = params->limit;
    if (q.x != 0.0f) {
        Vec3 r = params->limit;
        t.x = (t.x < r.x) ? r.x : t.x;
    }
    q = params->limit;
    if (q.y != 0.0f) {
        Vec3 r = params->limit;
        t.y = (t.y < r.y) ? r.y : t.y;
    }
    q = params->limit;
    if (q.z != 0.0f) {
        Vec3 r = params->limit;
        t.z = (t.z < r.z) ? r.z : t.z;
    }

    if (node->shield)
        node->shield->flag72 = 0;
    if (actor->holder && actor->holder->shield)
        actor->holder->shield->flag72 = 0;

    Tracer *tracer = actor->tracer;
    Game *game = DAT_004dd700;
    if (tracer && game) {
        DAT_004d2a3c = 2;
        DAT_00554c1c = 1;
        DAT_00554c18 = 0.5f;
        Vec3 s = node->pos;
        Vec3 d;
        d.x = t.x - s.x;
        d.y = t.y - s.y;
        d.z = t.z - s.z;
        Vec3 o2;
        Vec3 o3;
        o2.z = d.z;
        float scale = params->scale;
        if (actor->tracer->FUN_0010aa90(game, &s, &t, scale, &o3, &o2, &d, actor, node, 0, 1))
            actor->FUN_0003f400(&t);
        else
            actor->FUN_00036e70(&id, 1);
    } else {
        HitList *list = FUN_00202f00();
        DAT_00554c18 = DAT_004b8540;
        DAT_004d2a3c = 2;
        DAT_00554c1c = 0;
        if (DAT_00554c14->FUN_002ee140(list, &node->pos, &t, 0))
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
