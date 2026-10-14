// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 31/32, incomplete)
// FUN_001e5980 @ 0x001e5980
struct V3_1e5980 {
    float x, y, z;
};

struct Matrix {
    char pad0[0x30];
    V3_1e5980 pos;                         // 0x30
};

struct Item_1e5980 {
    char pad0[8];
    int type;                       // 0x8
    char padc[4];
};

struct Parent_1e5980 {
    unsigned char valid;            // 0x0
    char pad1[3];
    int next;                       // 0x4
};

struct Node {
    char pad0[0x10];
    Parent_1e5980 *parent;                 // 0x10
    char pad14[0x34 - 0x14];
    int itemCount;                  // 0x34
    Item_1e5980 *items;                    // 0x38
};

struct NodeTable {
    char pad0[0x1c];
    Node **nodes;                   // 0x1c
};

struct Holder_1e5980 {
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
    virtual char check();           // 0x2c
};

struct Link_1e5980 {
    char pad0[0x70];
    Holder_1e5980 *holder;                 // 0x70
};

struct Quat_1e5980 {
    float v[4];
    void FUN_0022b370(Matrix *m);
};

struct Slot_1e5980 {
    virtual void v0();
    virtual void release();         // 0x4
};

struct Entity {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Matrix *worldMatrix();  // 0x3c
    int field4;
    int field8;                     // 0x8 (after the vptr and field4)
    char padc[0x40 - 0xc];
    int nodeIndex;                  // 0x40
    float scale;                    // 0x44
    char pad48[0x98 - 0x48];
    NodeTable *table;               // 0x98
    char pad9c[0x108 - 0x9c];
    unsigned short word108;         // 0x108
    char pad10a[0x144 - 0x10a];
    unsigned char flag144;          // 0x144

    int FUN_001d62c0();
    void FUN_0027cf40(int a);
    char FUN_001d7300();
    Link_1e5980 *FUN_001d72e0();
    float FUN_001d6cd0();
    void FUN_001d6770();
    int FUN_001d6c70();
};

struct Pose {
    char data[8];
    void FUN_001db780(Quat_1e5980 *q);
};

struct Entry40 {
    char pad0[0x10];
    Pose pose;                      // 0x10
    Slot_1e5980 *slot;                     // 0x18
    char pad1c[4];
    short field20;                  // 0x20
    char pad22[2];
    short field24;                  // 0x24
    unsigned char count26;          // 0x26
    unsigned char free27;           // 0x27
};

struct Entry20 {
    V3_1e5980 pos;                         // 0x00
    char padc[4];
    union {
        unsigned short flags;       // 0x10
        struct {
            unsigned char flagsLo;  // 0x10
            unsigned char flagsHi;  // 0x11
        };
    };
    short slotIndex;                // 0x12
};

struct Pool_1e5980 {
    void FUN_001c3b80(int *p);
};
Pool_1e5980 *__cdecl FUN_001c3d90();

struct Registry_1e5980 {
    void FUN_001b4540(Entity *e);
};
Registry_1e5980 *__cdecl FUN_001b6580();

struct Limits_1e5980 {
    char pad0[0x18];
    float maxY;                     // 0x18
};
struct Globals_1e5980 {
    char pad0[0x24];
    Limits_1e5980 *limits;                 // 0x24
};
extern Globals_1e5980 *DAT_004dd700;

class Manager_1e5980 {
public:
    char pad0[0x608];
    Entry40 slots[0x800];           // 0x608
    Entry20 entries[1];             // 0x14608

    void FUN_001de3f0(Entity *e);
    void FUN_001e5720(Entity *e);
    void FUN_001e5bc0(int a);
    void FUN_001e5980(int idx);
};

void Manager_1e5980::FUN_001e5980(int idx)
{
    struct Frame {
        bool found;
        V3_1e5980 pos;
        Quat_1e5980 rot;
    } fr;

    Entry20 *ent = &entries[idx];
    Entry40 *slot = &slots[ent->slotIndex];
    if (!(ent->flagsLo & 1))
        return;

    Entity *e = (Entity *)slot->slot;
    e->v0();
    e->FUN_0027cf40(e->FUN_001d62c0());

    fr.found = false;
    bool first = true;
    int n = e->nodeIndex;
    if (n >= 0) {
        Node **nodes = e->table->nodes;
        for (;;) {
            Node *node = nodes[n];
            bool hit = false;
            for (int k = 0; k < node->itemCount; ++k) {
                if (node->items[k].type == 1) {
                    hit = true;
                    break;
                }
            }
            if (hit) {
                fr.found = true;
                break;
            }
            if (!first)
                break;
            Parent_1e5980 *parent = node->parent;
            if (parent->valid == 0)
                break;
            n = parent->next;
            first = false;
            if (n < 0)
                break;
        }
    }

    ent->flags &= 0xbffe;

    float v = e->scale * 100.0f;
    if (!(v < 65000.0f))
        v = 65000.0f;
    slot->count26 = (unsigned char)e->nodeIndex;
    slot->field20 = (short)(int)v;
    slot->field24 = e->word108;

    bool noBlock;
    if (!e->FUN_001d7300())
        noBlock = true;
    else if (!e->FUN_001d72e0()->holder->check())
        noBlock = false;
    else
        noBlock = e->FUN_001d6cd0() <= 0.0f;
    slot->free27 = noBlock;

    if (e->flag144)
        ent->flagsHi |= 0x20;

    fr.rot.FUN_0022b370(e->worldMatrix());
    slot->pose.FUN_001db780(&fr.rot);

    fr.pos = e->worldMatrix()->pos;
    ent->flagsLo |= 4;
    ent->pos = fr.pos;

    if (slot->slot) {
        slot->slot->release();
        slot->slot = 0;
    }

    FUN_001c3d90()->FUN_001c3b80(&e->field8);
    FUN_001b6580()->FUN_001b4540(e);
    FUN_001de3f0(e);

    if (fr.pos.y < DAT_004dd700->limits->maxY) {
        e->FUN_001d6770();
        FUN_001e5720(e);
        FUN_001e5bc0(e->FUN_001d6c70());
    }
    if (fr.found) {
        FUN_001e5720(e);
        FUN_001e5bc0(e->FUN_001d6c70());
    }
    e->v1();
}
