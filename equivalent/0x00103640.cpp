// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00103640 @ 0x00103640
struct Game;
struct Vec3 {
    float x, y, z;
};

class Waypoint;

class Anchor {
public:
    char FUN_00059a50(Vec3 *out);
};

class Pawn {
public:
    char pad0[0x10];
    Anchor *anchor;
};

class Holder {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Pawn *pawn();
};

class Marker;

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void setPosition(Vec3 pos);
    char pad_[0x7c - 4];
    Vec3 home;
    void FUN_001048d0(Marker *m);
    void FUN_00104c60(Game *g, Vec3 *a, Vec3 *b, int bc, unsigned int c0, int c4, int zero);
};

class Locator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Vec3 *position(Vec3 *out);
};

struct Registry {
    char pad0[0x28];
    struct Index *index;
};

struct Index {
    Locator *FUN_001fd780(const char *name);
};

struct Game {
    char pad0[0x28];
    Index *index;
};

extern Game *DAT_004dd700;

int FUN_000964a0(char *buf, int size, const char *fmt, ...);

union NameSlot {
    const char *name;
    float y;
};

class Marker {
public:
    char pad0[0x58];
    Holder *holder;
    Target *target;
    char pad60[4];
    char label[0x40];
    char pad_a4;
    unsigned char active;
    char pad_a6[2];
    Vec3 pos;
    int b4;
    int b8;
    int bc;
    unsigned char c0;
    char pad_c1[3];
    int c4;

    void FUN_00103640(NameSlot name, float x, float y, float z);
};

void Marker::FUN_00103640(NameSlot name, float x, float y, float z)
{
    struct Frame {
        Vec3 v1;
        Vec3 v4;
        Vec3 v2;
        Vec3 v3;
    } fr;

    if (target == 0)
        return;
    Pawn *p = holder->pawn();
    const char *nm = name.name;
    FUN_000964a0(label, 0x40, "%s", nm);
    Locator *loc = DAT_004dd700->index->FUN_001fd780(nm);
    if (loc == 0)
        return;
    active = 1;
    z = z + loc->position(&fr.v1)->z;
    name.y = y + loc->position(&fr.v2)->y;
    float nx = x + loc->position(&fr.v3)->x;
    pos.z = z;
    pos.x = nx;
    pos.y = name.y;
    target->setPosition(pos);
    p->anchor->FUN_00059a50(&fr.v4);
    b8 = 0;
    target->FUN_001048d0(this);
    fr.v1 = target->home;
    target->FUN_00104c60(DAT_004dd700, &fr.v4, &fr.v1, bc, c0, c4, 0);
}
