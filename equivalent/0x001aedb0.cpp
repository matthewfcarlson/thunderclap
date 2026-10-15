// STATUS: equivalent (tools/equiv.py level 3: 1944 inputs, branch coverage 33/34, incomplete)
// FUN_001aedb0 @ 0x001aedb0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
struct Ctx;

struct Rec {
    int id;                 // 0x00
    int idx;                // 0x04
    float x, y, z;          // 0x08
    Rec *parent;            // 0x14
    float g;                // 0x18
    float h;                // 0x1c
    char closed;            // 0x20
    char pad21[3];
    int last;               // 0x24
    void FUN_001ad2b0(Ctx *d);
};

struct ANode {
    char hdr[0x10];
    Rec rec;                // 0x10
};

struct Map;

struct BNode {
    char hdr[0x10];
    ANode *an;              // 0x10
    Map *map;               // 0x14
};

struct Key {
    BNode *unused;
    Map *map;
};

struct Map {
    char pad0[0x14];
    int size;               // 0x14
    BNode *FUN_00230ea0();
    void FUN_00230de0(void *node);
    void *FUN_00230ba0(void *cmp, void *key);
    void *FUN_00230be0(void *cmp, void *key);
    void FUN_00230c30(void *node, void *cmp, void *parent);
};

struct Iter {
    int tile;
    int cur;
    int idx;
    int flag;
    void FUN_001ad7d0(Ctx *d);
};

int __cdecl FUN_001ad4d0(void *, void *);
int __cdecl FUN_001ad4f0(void *, void *);
int __cdecl FUN_001aea70(void *, void *);
int __cdecl FUN_001aeae0(void *, void *);
char __cdecl FUN_001ad730(int tile, Ctx *d);
void *FUN_0008d6d0(unsigned int size);
void thunk_FUN_00267090(void *p);
extern "C" double sqrt(double);

struct Frame {
    float g;                // 0x10
    Map *bspill;            // 0x14
    int cnt;                // 0x18
    ANode *key_node;        // 0x1c
    Map *key_map;           // 0x20
    ANode *P;               // 0x24
    int hi;                 // 0x28
    void *bnode;            // 0x2c
    Map *bspill2;           // 0x30
    Iter it2;               // 0x34
    Iter it1;               // 0x44
    int w54;                // 0x54
    Rec rec;                // 0x58
};

Rec *FUN_001aedb0(Map *a, Map *b, Rec *c, Ctx *d, int *e)
{
    Frame f;
    BNode *last = b->FUN_00230ea0();
    if (last->an->rec.id == c->id)
        return &b->FUN_00230ea0()->an->rec;

    last = b->FUN_00230ea0();
    f.it1.tile = last->an->rec.id;
    f.it1.idx = -1;
    f.it1.flag = (unsigned char)FUN_001ad730(f.it1.tile, d);
    f.it1.FUN_001ad7d0(d);
    if (b->size == 0)
        return 0;
    f.cnt = 0;
    for (;;) {
        int old = f.cnt;
        f.cnt = old + 1;
        if (old == 0x80)
            return 0;
        BNode *node = b->FUN_00230ea0();
        f.P = node->an;
        f.hi = (int)node->map;
        node = b->FUN_00230ea0();
        f.bspill = b;
        b->FUN_00230de0(node);
        thunk_FUN_00267090(node);
        f.it2.tile = f.P->rec.id;
        f.it2.idx = -1;
        f.it2.flag = (unsigned char)FUN_001ad730(f.it2.tile, d);
        f.it2.FUN_001ad7d0(d);
        int idx = f.it2.idx;
        while (idx != -1) {
            f.rec.id = f.it2.cur;
            *(int *)&f.rec.x = f.it1.idx;
            *(int *)&f.rec.y = f.it1.flag;
            *(int *)&f.rec.z = *(&f.it1.flag + 1);
            f.rec.parent = 0;
            f.rec.g = 0;
            f.rec.h = 0;
            f.rec.last = 0;
            f.rec.idx = idx;
            *(int *)&f.rec.closed = 0;
            char isNew = 1;
            void *parent = a->FUN_00230be0((void *)FUN_001ad4f0, &f.rec);
            if (parent == 0) {
                f.key_node = 0;
                f.key_map = 0;
            } else {
                ANode *n = (ANode *)FUN_0008d6d0(0x38);
                if (n != 0)
                    n->rec = f.rec;
                a->FUN_00230c30(n, (void *)FUN_001ad4d0, parent);
                f.key_node = n;
                f.key_map = a;
                if (n != 0) {
                    n->rec.FUN_001ad2b0(d);
                    goto have_node;
                }
            }
            f.key_node = (ANode *)a->FUN_00230ba0((void *)FUN_001ad4f0, &f.rec);
            f.key_map = a;
            isNew = 0;
        have_node:
            {
                ANode *an = f.key_node;
                Rec *N = &an->rec;
                ANode *P = f.P;
                double dx = P->rec.x - N->x;
                double dy = P->rec.y - N->y;
                double dz = P->rec.z - N->z;
                f.g = (float)(sqrt(dz * dz + dy * dy + dx * dx) + P->rec.g);
                if (isNew || f.g < N->g) {
                    N->idx = f.rec.idx;
                    if (!isNew && !N->closed) {
                        f.bnode = b->FUN_00230ba0((void *)FUN_001aeae0, &f.key_node);
                        if (f.bnode != 0) {
                            b->FUN_00230de0(f.bnode);
                            thunk_FUN_00267090(f.bnode);
                        }
                    }
                    N->g = f.g;
                    N->parent = &P->rec;
                    double ex = N->x - c->x;
                    double ey = N->y - c->y;
                    double ez = N->z - c->z;
                    N->h = (float)(sqrt(ez * ez + ey * ey + ex * ex) * 1.5f + f.g);
                    if (N->id == c->id) {
                        *e = f.it1.idx;
                        // the callees took &f.key_node, so it is re-read from the frame here
                        f.key_node->rec.last = f.it1.idx;
                        return &f.key_node->rec;
                    }
                    void *bp = b->FUN_00230be0((void *)FUN_001aeae0, &f.key_node);
                    if (bp != 0) {
                        BNode *nb = (BNode *)FUN_0008d6d0(0x18);
                        if (nb != 0) {
                            nb->an = f.key_node;
                            nb->map = f.key_map;
                        }
                        b->FUN_00230c30(nb, (void *)FUN_001aea70, bp);
                    }
                    N->closed = 0;
                }
            }
            f.it2.FUN_001ad7d0(d);
            idx = f.it2.idx;
        }
        f.P->rec.closed = 1;
        if (b->size == 0)
            return 0;
    }
}
