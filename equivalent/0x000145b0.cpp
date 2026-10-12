// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 43/44, incomplete)
// FUN_000145b0 @ 0x000145b0
void *FUN_0008d690(unsigned int size);

struct Vec3 {
    float x, y, z;
};

class Ref {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    Ref *FUN_00059260(void *arg);
};

struct Slot {
    bool FUN_00231e80(struct Node *n);
};

struct Node {
    void FUN_00231ad0(Slot *slot, Ref *ref, int flag);
};

class Source {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual Node *vfunc_8(Ref *ref, int flag);
};

struct Link {
    Ref *first;
};

struct Pos {
    void FUN_00059a50(Vec3 *out);
};

struct Actor {
    char pad000[0x10];
    Link *link;                 // 0x10
    char pad014[0xdc - 0x14];
    Slot slot;                  // 0xdc
    char pad0dd[0x11c - 0xdd];
    void *f11c;
    char pad120[0x20b0 - 0x120];
    int f20b0;
    bool FUN_000360f0();
    bool FUN_00038f90(int a1, int f2c, int zero);
};

struct Body {
    char pad00[0x10];
    Pos *pos;
};

struct Handle {
    Body *FUN_00059a30();
    void FUN_00059a40();
};

struct Config {
    char pad00[0x2c];
    int f2c;
    int limit;                  // 0x30
    Source *source34;           // 0x34
    char pad38[0x40 - 0x38];
    Source *source40;           // 0x40
};

struct Roster {
    char pad00[0x0c];
    int count;                  // 0x0c
    Actor *FUN_00024190(int index);
};

struct Game {
    char pad00[0x20];
    Roster *roster;
};

extern Game *DAT_004dd700;

struct Owner {
    char pad00[8];
    void *f08;
    Handle *FUN_000592a0();
};

class Tracker {
public:
    char pad00[0x1c];
    Owner *owner;               // 0x1c
    Config *config;             // 0x20
    char pad24[0x34 - 0x24];
    Actor *seen[8];             // 0x34
    int seenCount;              // 0x54
    int counter;                // 0x58

    void FUN_000145b0(int a1, int a2, int a3);
};

void Tracker::FUN_000145b0(int a1, int a2, int a3)
{
    Handle *handle = owner->FUN_000592a0();
    Body *self = handle->FUN_00059a30();
    handle->FUN_00059a40();
    Vec3 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    self->pos->FUN_00059a50(&v);

    Roster *roster = DAT_004dd700->roster;
    int n = roster->count;
    for (int i = 0; i < n; i++) {
        Actor *cand = roster->FUN_00024190(i);
        if (cand == (Actor *)self || cand == 0)
            continue;
        if (cand->f20b0 != 0)
            continue;
        if (cand->FUN_000360f0())
            continue;
        if (cand->f11c == 0)
            continue;

        bool known = false;
        for (int k = 0; k < seenCount; k++) {
            if (seen[k] == cand) {
                known = true;
                break;
            }
        }
        if (known)
            continue;

        int f2c = config->f2c;
        if (!cand->FUN_00038f90(a1, f2c, 0))
            continue;

        counter = counter + 1;
        Source *s1 = config->source40;
        if (s1 != 0) {
            void *mem = FUN_0008d690(0x14);
            Ref *r = 0;
            if (mem)
                r = ((Ref *)mem)->FUN_00059260(owner->f08);
            r->vfunc_0();
            Node *node = s1->vfunc_8(r, 0);
            if (node != 0) {
                Slot *selfSlot = (Slot *)((char *)self + 0xdc);
                if (!selfSlot->FUN_00231e80(node))
                    node->FUN_00231ad0(selfSlot, r, -1);
            }
            r->vfunc_1();
        }

        Source *s2 = config->source34;
        if (s2 != 0) {
            void *mem = FUN_0008d690(0x14);
            Ref *r = 0;
            if (mem)
                r = ((Ref *)mem)->FUN_00059260(cand->link->first);
            r->vfunc_0();
            Node *node = s2->vfunc_8(r, 0);
            if (node != 0)
                node->FUN_00231ad0(&cand->slot, r, -1);
            r->vfunc_1();
        }

        if (seenCount < 8) {
            seen[seenCount] = cand;
            seenCount = seenCount + 1;
            int limit = config->limit;
            if (limit > 0 && counter >= limit)
                break;
        }
    }
}
