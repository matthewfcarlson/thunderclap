// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_00244ea0 @ 0x00244ea0
struct Region {
    char pad0[0x30];
    int boundsLo;           // 0x30
    int boundsHi;           // 0x34
};

struct Query {
    int keyLo;
    int keyHi;
    int boundsLo;
    int boundsHi;
};

// Spatial index: a sentinel node followed by the tree links.
struct Index {
    Index *root;
    Index *left;
    Index *right;
    Index *parent;
    int color;
};

extern Index *DAT_004cc08c;
extern int DAT_004e5f0c;
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
void __cdecl FUN_002448b0(Index *idx, void *item, Query *q);

namespace om {
class Entity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Region *GetRegion();
    char pad4[0x14];
    unsigned int keyLo;     // 0x18
    unsigned int keyHi;     // 0x1c
    unsigned short s20;
    unsigned short s22;

    Entity(Region *region);
};
}

om::Entity::Entity(Region *region)
{
    unsigned __int64 key = FUN_002672f0("MyEntity", 0, 0);
    keyLo = (unsigned int)key;
    keyHi = (unsigned int)(key >> 32);
    s20 = 0;
    s22 = 0;
    int count = DAT_004e5f0c;
    Index *n = DAT_004cc08c;
    if (count == 0 && n) {
        Index *sentinel = (Index *)&n->left;
        n->left = sentinel;
        n->right = sentinel;
        n->parent = sentinel;
        n->color = 0;
        n->root = sentinel;
    }
    Query q;
    q.keyLo = keyLo;
    q.keyHi = keyHi;
    q.boundsLo = region->boundsLo;
    q.boundsHi = region->boundsHi;
    FUN_002448b0(n, this, &q);
    DAT_004e5f0c++;
}
