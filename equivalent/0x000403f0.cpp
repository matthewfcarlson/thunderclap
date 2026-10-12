// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 18/22, incomplete)
// FUN_000403f0 @ 0x000403f0
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

class Node {
public:
    char FUN_00059a50(Vec3 *out);
};

class Ref {
public:
    virtual void vf0();
    virtual void vf1();
};

class Team {
public:
    char pad0[0x1b0];
    int id;
};

class Actor {
public:
    char pad0[0x10];
    Node *node;
    char pad1[0x11c - 0x14];
    Team *team;
    char pad2[0x12c - 0x120];
    Ref *target;
    void FUN_000393c0();
};

class Roster {
public:
    char pad0[0xc];
    int count;
    Actor *FUN_00024190(int index);
    char FUN_000242d0(Actor *a);
};

class Owner {
public:
    char pad0[0x10];
    Node *node;
    char pad1[0x11c - 0x14];
    Team *team;
    char pad2[0x328 - 0x120];
    Ref *current;
    char pad3[0x1b48 - 0x32c];
    char flag;
    char pad4[0x1d40 - 0x1b49];
    char enabled;
    void FUN_000393c0();
    void FUN_000403f0();
};

struct Globals {
    char pad0[0x20];
    Roster *roster;
};

extern Globals *DAT_004dd700;

void Owner::FUN_000403f0()
{
    if (DAT_004dd700->roster->FUN_000242d0((Actor *)this))
        return;
    if (!enabled)
        return;
    Vec3 me;
    node->FUN_00059a50(&me);
    int count = DAT_004dd700->roster->count;
    Actor *best = 0;
    float bestDist = 0;
    for (int i = 0; i < count; i++) {
        Actor *other = DAT_004dd700->roster->FUN_00024190(i);
        me.x = 0;
        me.y = 0;
        me.z = 0;
        node->FUN_00059a50(&me);
        if (other && other->team->id != team->id) {
            Vec3 op;
            other->node->FUN_00059a50(&op);
            me.x = me.x - op.x;
            me.y = me.y - op.y;
            me.z = me.z - op.z;
            float d = me.FUN_0022d110();
            if (best == 0 || d < bestDist) {
                bestDist = d;
                best = other;
            }
        }
    }
    if (best) {
        Ref *t = best->target;
        if (t == 0) {
            FUN_000393c0();
            return;
        }
        flag = 1;
        t->vf0();
        if (current)
            current->vf1();
        current = t;
    }
}
