// STATUS: equivalent (tools/equiv.py level 3: 18665 inputs, branch coverage 43/44, incomplete)
// FUN_000145b0 @ 0x000145b0
#include "compat/ptr.h"
void *FUN_0008d690(hulk_uintptr size);

struct Vec3_145b0 {
    float x, y, z;
};

class Ref_145b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    Ref_145b0 *FUN_00059260(void *arg);
};

struct Slot_145b0 {
    bool FUN_00231e80(struct Node *n);
};

struct Node {
    void FUN_00231ad0(Slot_145b0 *slot, Ref_145b0 *ref, int flag);
};

class Source_145b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual Node *vfunc_8(Ref_145b0 *ref, int flag);
};

struct Link_145b0 {
    Ref_145b0 *first;
};

struct Pos_145b0 {
    void FUN_00059a50(Vec3_145b0 *out);
};

struct Actor_145b0 {
    char pad000[0x10];
    Link_145b0 *link;                 // 0x10
    char pad014[0xdc - 0x14];
    Slot_145b0 slot;                  // 0xdc
    char pad0dd[0x11c - 0xdd];
    void *f11c;
    char pad120[0x20b0 - 0x120];
    int f20b0;
    bool FUN_000360f0();
    int FUN_00038f90(int a1, int f2c, int zero);   // tested as a full int (test eax,eax)
};

struct Body_145b0 {
    char pad00[0x10];
    Pos_145b0 *pos;
};

struct Handle_145b0 {
    Body_145b0 *FUN_00059a30();
    void FUN_00059a40();
};

struct Config_145b0 {
    char pad00[0x2c];
    int f2c;
    int limit;                  // 0x30
    Source_145b0 *source34;           // 0x34
    char pad38[0x40 - 0x38];
    Source_145b0 *source40;           // 0x40
};

struct Roster_145b0 {
    char pad00[0x0c];
    int count;                  // 0x0c
    Actor_145b0 *FUN_00024190(int index);
};

struct Game_145b0 {
    char pad00[0x20];
    Roster_145b0 *roster;
};

extern Game_145b0 *DAT_004dd700;

struct Owner_145b0 {
    char pad00[8];
    void *f08;
    Handle_145b0 *FUN_000592a0();
};

class Tracker_145b0 {
public:
    char pad00[0x1c];
    Owner_145b0 *owner;               // 0x1c
    Config_145b0 *config;             // 0x20
    char pad24[0x34 - 0x24];
    Actor_145b0 *seen[8];             // 0x34
    int seenCount;              // 0x54
    int counter;                // 0x58

    void FUN_000145b0(int a1, int a2, int a3);
};

void Tracker_145b0::FUN_000145b0(int a1, int a2, int a3)
{
    Handle_145b0 *handle = owner->FUN_000592a0();
    Body_145b0 *self = handle->FUN_00059a30();
    handle->FUN_00059a40();
    Vec3_145b0 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    self->pos->FUN_00059a50(&v);

    Roster_145b0 *roster = DAT_004dd700->roster;
    int n = roster->count;
    for (int i = 0; i < n; i++) {
        Actor_145b0 *cand = roster->FUN_00024190(i);
        if (cand == (Actor_145b0 *)self || cand == 0)
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
        Source_145b0 *s1 = config->source40;
        if (s1 != 0) {
            void *mem = FUN_0008d690(0x14);
            Ref_145b0 *r = 0;
            if (mem)
                r = ((Ref_145b0 *)mem)->FUN_00059260(owner->f08);
            r->vfunc_0();
            Node *node = s1->vfunc_8(r, 0);
            if (node != 0) {
                Slot_145b0 *selfSlot = (Slot_145b0 *)((char *)self + 0xdc);
                if (!selfSlot->FUN_00231e80(node))
                    node->FUN_00231ad0(selfSlot, r, -1);
            }
            r->vfunc_1();
        }

        Source_145b0 *s2 = config->source34;
        if (s2 != 0) {
            void *mem = FUN_0008d690(0x14);
            Ref_145b0 *r = 0;
            if (mem)
                r = ((Ref_145b0 *)mem)->FUN_00059260(cand->link->first);
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
