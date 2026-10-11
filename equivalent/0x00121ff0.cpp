// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 16/16)
// hulkfight::ai::PathFormationAction::vfunc_3 @ 0x00121ff0
struct Fighter { char pad[4]; };

struct Holder {
    char pad0[0x380];
    int value;
};

struct Stats {
    char pad0[0x11c];
    Holder *holder;
};

Fighter *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(Fighter *f);

struct Item {
    unsigned char active;
    char pad1[3];
    int f20, f24, f28, f2c, f30, f34;
};

struct ResourceName {
    char data[8];
    void FUN_0027b040(const char *name);
};

struct Pair {
    int a;
    int b;
};

struct StatsBlock {
    char pad0[8];
    int a;
    int b;
};

struct Settings {
    char pad0[0x150];
    int level;
    char pad154[0x2cc - 0x154];
    int value;
    void FUN_00065dd0(const Pair *p);
};
Settings *__cdecl FUN_000678d0();

struct Owner {
    char pad0[0x2c];
    int count;
    char pad30[4];
    const char *name;
};

struct Ring {
    Item **first;
    Item **last;
    Item **buff;
    Item **end;
};

struct Queue {
    char pad0[0x18];
    Ring ring;
};

struct World {
    char pad0[0x1c];
    Queue *queue;
};
extern World *DAT_004dd700;

class PathFormationAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Item item;
    float f38;
    float f3c;
    float f40;
    float f44;
    int f48;
    char pad4c[0x64 - 0x4c];
    int f64, f68, f6c, f70;
    int f74;
    int f78;
    Owner *owner;
    void *fighterOwner;
    char pad84[0xa0 - 0x84];
    int fa0, fa4, fa8, fac, fb0, fb4;
    Stats *stats;
    char padbc[4];
    ResourceName name;
};

bool PathFormationAction::vfunc_3(int a, int b)
{
    if (fighterOwner == 0)
        return false;
    fa0 = 0; fa4 = 0; fa8 = 0; fac = 0; fb0 = 0; fb4 = 0;
    item.active = 0;
    item.f20 = 0; item.f24 = 0; item.f28 = 0; item.f2c = 0; item.f30 = 0; item.f34 = 0;
    Fighter *fighter = FUN_000592a0(fighterOwner);
    Stats *s = FUN_00059a30(fighter);
    stats = s;
    if (s != 0) {
        Holder *h = s->holder;
        if (h != 0)
            f78 = h->value;
    }
    f3c = 0.2f;
    f38 = 1.0f;
    f40 = 1.0f;
    f44 = 0.3f;
    f48 = 0;
    f64 = 0; f68 = 0; f6c = 0; f70 = 0;
    f74 = 2;

    Ring *r = &DAT_004dd700->queue->ring;
    if (r->last < r->end) {
        if (r->last != 0)
            *r->last = &item;
        Item **end = r->end;
        r->last = r->last + 1;
        if (r->last == end)
            r->last = r->buff;
        if (r->first == r->last)
            r->last = r->last + (end - r->buff);
    }

    name.FUN_0027b040(owner->name);
    Stats *s2 = FUN_00059a30(fighter);
    int count = owner->count;
    FUN_000678d0()->value = count;
    if (FUN_000678d0()->level < owner->count) {
        StatsBlock *sb = (StatsBlock *)s2;
        Pair p;
        p.a = sb->a;
        p.b = sb->b;
        FUN_000678d0()->FUN_00065dd0(&p);
    }
    return true;
}
