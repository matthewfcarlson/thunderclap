// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 51/51)
// FUN_002eea80 @ 0x002eea80
extern "C" void *memset(void *dst, int c, unsigned int n);

struct Info {
    char pad0[0xc];
    int kind;                       // 0xc
};

struct Sub {
    char pad0[0x18];
    Info *info;                     // 0x18
};

struct Child {
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
    virtual void touch();           // 0x28
    char pad4[0x10 - 4];
    Sub *sub;                       // 0x10
    char pad14[0x18 - 0x14];
    unsigned char active;           // 0x18
    unsigned char ready;            // 0x19
};

struct Item {
    char pad0[0x20];
    Child *child;                   // 0x20
    char pad24[0x60 - 0x24];
    unsigned int flags;             // 0x60
    char pad64[4];
    unsigned char hot;              // 0x68
    unsigned char hot2;             // 0x69
};

struct Checker {
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
    virtual char accept(Item *item);    // 0x2c
};

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();                 // 0x18
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void attach(Child *c, int flag);    // 0x3c
    char pad4[0x38 - 4];
    int slot;                       // 0x38
};

struct Node {
    char pad0[0x10];
    Target *target;                 // 0x10
};

struct Holder {
    char pad0[0x20];
    int ref;                        // 0x20
};

struct Link {
    Holder *a;                      // 0x0
    Holder *b;                      // 0x4
    int pad[3];
};

struct Bits {
    unsigned int nbits;
    unsigned int words[1];
};

struct Solver {
    void FUN_00302ed0(int a, int b, int *c);
};

class Mgr {
public:
    Item **begin;                   // 0x00
    Item **end;                     // 0x04
    char pad8[8];
    Bits *bits;                     // 0x10
    Item **items;                   // 0x14
    unsigned int count;             // 0x18
    char pad1c[0x2c - 0x1c];
    int value;                      // 0x2c
    int valueCopy;                  // 0x30
    char pad34[0x3c - 0x34];
    Node **nodesBegin;              // 0x3c
    Node **nodesEnd;                // 0x40
    char pad44[0x4c - 0x44];
    Link *linksBegin;               // 0x4c
    Link *linksEnd;                 // 0x50
    char pad54[0x5c - 0x54];
    Child **hitBegin;               // 0x5c
    Child **hitEnd;                 // 0x60
    Child **hitCap;                 // 0x64
    char pad68[4];
    unsigned char force;            // 0x6c
    char pad6d[3];
    Solver solver;                  // 0x70
    char pad71[0x78 - 0x71];
    int *valuePtr;                  // 0x78
    char pad7c[0xa0 - 0x7c];
    int dirty;                      // 0xa0
    char pada4[0xb4 - 0xa4];
    Checker *checker;               // 0xb4

    void FUN_002ed730();
    void FUN_002ed240(unsigned int i);
    void FUN_002ed3d0(unsigned int i);
    void FUN_002eea80();
};

void Mgr::FUN_002eea80()
{
    valueCopy = value;
    unsigned int nwords = (bits->nbits + 0x1f) >> 5;
    if (nwords != 0)
        memset(&bits->words[0], 0, nwords * 4);
    valuePtr = &value;
    FUN_002ed730();
    hitEnd = hitBegin;

    for (unsigned int i = 0; i < count; ++i) {
        Item *it = items[i];
        if (!it->child->active)
            continue;
        if (it->hot || it->hot2 || force) {
            bits->words[i >> 5] |= 1u << (i & 0x1f);
            FUN_002ed240(i);
            FUN_002ed3d0(i);
        }
        if (it->hot || it->hot2) {
            if (!(it->flags & 0x80000000))
                continue;
            Child *c = it->child;
            if (!c->ready)
                c->touch();
            if (!checker->accept(it))
                continue;
            Child **p = hitEnd;
            if (p >= hitCap)
                continue;
            hitEnd = p + 1;
            if (p)
                *p = c;
        }
    }

    int nnodes = nodesEnd - nodesBegin;
    for (int i = 0; i < nnodes; ++i) {
        Target *t = nodesBegin[i]->target;
        if (t->type() == 4) {
            unsigned int nhits = hitEnd - hitBegin;
            for (unsigned int j = 0; j < nhits; ++j) {
                dirty = 0;
                Child *c = hitBegin[j];
                if (c->sub->info->kind != 3 || t->slot == 5)
                    t->attach(c, 1);
            }
        }
    }

    int nlinks = linksEnd - linksBegin;
    for (int i = 0; i < nlinks; ++i) {
        dirty = 0;
        Link *l = &linksBegin[i];
        solver.FUN_00302ed0(l->a->ref, l->b->ref, &value);
    }

    unsigned int nitems = end - begin;
    for (unsigned int i = 0; i < nitems; i = i + 1, nitems = end - begin) {
        Item *it = begin[i];
        it->hot2 = 0;
        it->hot = 0;
    }
    force = 0;
}
