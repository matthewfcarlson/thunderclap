// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 18/22, incomplete)
// FUN_000403f0 @ 0x000403f0
#include "decls/address.h"
struct Vec3_403f0 {
    float x, y, z;
    float FUN_0022d110();
};

class Node {
public:
    char FUN_00059a50(Vec3_403f0 *out);
};

class Ref_403f0 {
public:
    virtual void vf0();
    virtual void vf1();
};

class Team_403f0 {
public:
    char pad0[0x1b0];
    int id;
};

class Actor_403f0 {
public:
    char pad0[0x10];
    Node *node;
    char pad1[0x11c - 0x14];
    Team_403f0 *team;
    char pad2[0x12c - 0x120];
    Ref_403f0 *target;
    void FUN_000393c0();
};

class Roster_403f0 {
public:
    char pad0[0xc];
    int count;
    Actor_403f0 *FUN_00024190(int index);
    char FUN_000242d0(Actor_403f0 *a);
};

class Owner_403f0 {
public:
    char pad0[0x10];
    Node *node;
    char pad1[0x11c - 0x14];
    Team_403f0 *team;
    char pad2[0x328 - 0x120];
    Ref_403f0 *current;
    char pad3[0x1b48 - 0x32c];
    char flag;
    char pad4[0x1d40 - 0x1b49];
    char enabled;
    void FUN_000393c0();
    void FUN_000403f0();
};

struct World {
    char pad0[0x20];
    Roster_403f0 *roster;
};


void Owner_403f0::FUN_000403f0()
{
    if (DAT_004dd700->roster->FUN_000242d0((Actor_403f0 *)this))
        return;
    if (!enabled)
        return;
    Vec3_403f0 me;
    node->FUN_00059a50(&me);
    int count = DAT_004dd700->roster->count;
    Actor_403f0 *best = 0;
    float bestDist = 0;
    for (int i = 0; i < count; i++) {
        Actor_403f0 *other = DAT_004dd700->roster->FUN_00024190(i);
        me.x = 0;
        me.y = 0;
        me.z = 0;
        node->FUN_00059a50(&me);
        if (other && other->team->id != team->id) {
            Vec3_403f0 op;
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
        Ref_403f0 *t = best->target;
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
