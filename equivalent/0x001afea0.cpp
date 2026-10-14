// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001afea0 @ 0x001afea0
struct Entry_1afea0 {
    char pad0[0x16];
    unsigned char flags;        // 0x16
    char pad17;
};

struct EntryTable_1afea0 {
    char pad0[0x18];
    Entry_1afea0 *entries;             // 0x18
};

struct Owner_1afea0 {
    char pad0[0x44];
    EntryTable_1afea0 *table;          // 0x44
};

struct Link_1afea0 {
    char pad0[0x14];
    int f14;                    // 0x14
    bool FUN_002f8e10(Owner_1afea0 **ownerOut, unsigned short *indexOut);
};

struct Current;

struct Actor_1afea0 {
    char pad0[0x334];
    Current *cur334;            // 0x334
    Current *cur338;            // 0x338
    bool FUN_000373d0();
    void FUN_00038e80(int a, int b, int c, int d, int e, int f);
};

struct Holder_1afea0 {
    char pad0[8];
    Actor_1afea0 *actor;               // 0x08
};

struct Focus_1afea0 {
    char pad0[0x124];
    Current *current;           // 0x124
};

struct World {
    char pad0[0x20];
    Focus_1afea0 *focus;               // 0x20
};
extern World *DAT_004dd700;

// the original reuses the stack slots of args 1 and 3 as out-parameters
union LinkArg {
    Link_1afea0 *link;
    unsigned int word;
    unsigned short index;
};

union HolderArg {
    Holder_1afea0 *holder;
    Owner_1afea0 *owner;
};

int __stdcall FUN_001afea0(LinkArg a1, int a2, HolderArg a3, int a4, int a5, int a6, int a7)
{
    Link_1afea0 *link = a1.link;
    Actor_1afea0 *actor = a3.holder->actor;
    if (actor->FUN_000373d0()) {
        Current *cur = DAT_004dd700->focus->current;
        bool skip = false;
        if ((Actor_1afea0 *)cur != actor && actor->cur338 != cur && actor->cur334 != cur) {
            a3.owner = 0;
            a1.word = 0;
            if (link->FUN_002f8e10(&a3.owner, &a1.index)) {
                if ((a3.owner->table->entries[a1.index].flags & 8) != 0)
                    skip = true;
            }
        }
        if (!skip)
            actor->FUN_00038e80(a2, a4, link->f14, a5, a6, a7);
    }
    return 1;
}
