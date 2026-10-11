// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 26/26)
// CWeaponCollisionAction::vfunc_6 @ 0x0001b3a0
struct V3 { float x, y, z; };

struct Matrix {
    float r[12];
    V3 pos;
    float w;
    void FUN_0022b980();
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3 *v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int a);
};

class Ref;
class Ref { public: int FUN_001d64a0(); };

class Anim {
public:
    virtual void v0();
    virtual void v1();
    char pad04[4];
    Ref *ref;
    int type;
    Matrix xform;
    char pad50[0x74 - 0x50];
    struct Link *link;
};

struct Link {
    char pad0[0x20];
    Node *node;
};

class Fighter;

class Slot {
public:
    char pad0[0x14];
    int id;
    int arg18;
    char pad1c[0x24 - 0x1c];
    char flag24;
    char pad25[0x38 - 0x25];
    float arg38;
};

class AnimSet {
public:
    Anim *FUN_001d72e0();
    void FUN_001d7330(class CWeaponCollisionAction *owner);
};

class Fighter {
public:
    char pad0[0x1b49];
    char flag1b49;
    bool FUN_00035ab0();
    void FUN_0003b580(int a, float b, float c);
    AnimSet *FUN_00035ef0(int id);
};

class Holder { public: Fighter *FUN_00059a30(); };
class Params { public: Holder *FUN_000592a0(); };

class CWeaponCollisionAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual bool FUN_0001b3a0(int unused);
    char pad04[0x1c - 4];
    Params *params;
    Slot *slot;
    Anim *anim;
    char hasHold;
    char pad29[0x34 - 0x29];
    Matrix xform;
    void FUN_0001b280(Node *n, int a);
};

bool CWeaponCollisionAction::FUN_0001b3a0(int unused)
{
    Fighter *f = params->FUN_000592a0()->FUN_00059a30();
    if (slot->flag24 && f->FUN_00035ab0())
        f->FUN_0003b580(1, 3.1415927f, slot->arg38);
    f->flag1b49 = 1;
    AnimSet *set = f->FUN_00035ef0(slot->id);
    if (!set)
        return false;
    Anim *a = set->FUN_001d72e0();
    if (!a)
        return false;
    set->FUN_001d7330(this);
    a->v0();
    if (anim)
        anim->v1();
    anim = a;
    if (a->type == 5)
        hasHold = (a->ref->FUN_001d64a0() == 5);
    if (anim->link && anim->link->node) {
        Node *n = anim->link->node;
        if (hasHold)
            FUN_0001b280(n, slot->arg18);
        else
            n->v7(slot->arg18);
    }
    if (hasHold) {
        xform = anim->xform;
        return true;
    }
    if (anim->link && anim->link->node) {
        Node *n = anim->link->node;
        xform.FUN_0022b980();
        V3 *p = n->v4();
        xform.pos = *p;
        return true;
    }
    xform = anim->xform;
    return true;
}
