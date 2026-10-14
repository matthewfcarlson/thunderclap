// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00103640 @ 0x00103640
struct Game_103640;
struct Vec3_103640 {
    float x, y, z;
};

class Waypoint;

class Anchor_103640 {
public:
    char FUN_00059a50(Vec3_103640 *out);
};

class Pawn_103640 {
public:
    char pad0[0x10];
    Anchor_103640 *anchor;
};

class Holder_103640 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Pawn_103640 *pawn();
};

class Marker_103640;

class Target_103640 {
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
    virtual void setPosition(Vec3_103640 pos);
    char pad_[0x7c - 4];
    Vec3_103640 home;
    void FUN_001048d0(Marker_103640 *m);
    void FUN_00104c60(Game_103640 *g, Vec3_103640 *a, Vec3_103640 *b, int bc, unsigned int c0, int c4, int zero);
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
    virtual Vec3_103640 *position(Vec3_103640 *out);
};

struct Registry_103640 {
    char pad0[0x28];
    struct Index_103640 *index;
};

struct Index_103640 {
    Locator *FUN_001fd780(const char *name);
};

struct Game_103640 {
    char pad0[0x28];
    Index_103640 *index;
};

extern Game_103640 *DAT_004dd700;

int FUN_000964a0(char *buf, int size, const char *fmt, ...);

union NameSlot_103640 {
    const char *name;
    float y;
};

class Marker_103640 {
public:
    char pad0[0x58];
    Holder_103640 *holder;
    Target_103640 *target;
    char pad60[4];
    char label[0x40];
    char pad_a4;
    unsigned char active;
    char pad_a6[2];
    Vec3_103640 pos;
    int b4;
    int b8;
    int bc;
    unsigned char c0;
    char pad_c1[3];
    int c4;

    void FUN_00103640(NameSlot_103640 name, float x, float y, float z);
};

void Marker_103640::FUN_00103640(NameSlot_103640 name, float x, float y, float z)
{
    struct Frame {
        Vec3_103640 v1;
        Vec3_103640 v4;
        Vec3_103640 v2;
        Vec3_103640 v3;
    } fr;

    if (target == 0)
        return;
    Pawn_103640 *p = holder->pawn();
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
