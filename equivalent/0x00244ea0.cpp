// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_00244ea0 @ 0x00244ea0
#include "decls/address.h"
struct Region_244ea0 {
    char pad0[0x30];
    int boundsLo;           // 0x30
    int boundsHi;           // 0x34
};

struct Query_244ea0 {
    int keyLo;
    int keyHi;
    int boundsLo;
    int boundsHi;
};

// Spatial index: a sentinel node followed by the tree links.
struct Index_244ea0 {
    Index_244ea0 *root;
    Index_244ea0 *left;
    Index_244ea0 *right;
    Index_244ea0 *parent;
    int color;
};

extern Index_244ea0 *DAT_004cc08c;
extern int DAT_004e5f0c;
void __cdecl FUN_002448b0(Index_244ea0 *idx, void *item, Query_244ea0 *q);

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
    virtual Region_244ea0 *GetRegion();
    char pad4[0x14];
    unsigned int keyLo;     // 0x18
    unsigned int keyHi;     // 0x1c
    unsigned short s20;
    unsigned short s22;

    Entity(Region_244ea0 *region);
};
}

om::Entity::Entity(Region_244ea0 *region)
{
    unsigned __int64 key = FUN_002672f0("MyEntity", 0, 0);
    keyLo = (unsigned int)key;
    keyHi = (unsigned int)(key >> 32);
    s20 = 0;
    s22 = 0;
    int count = DAT_004e5f0c;
    Index_244ea0 *n = DAT_004cc08c;
    if (count == 0 && n) {
        Index_244ea0 *sentinel = (Index_244ea0 *)&n->left;
        n->left = sentinel;
        n->right = sentinel;
        n->parent = sentinel;
        n->color = 0;
        n->root = sentinel;
    }
    Query_244ea0 q;
    q.keyLo = keyLo;
    q.keyHi = keyHi;
    q.boundsLo = region->boundsLo;
    q.boundsHi = region->boundsHi;
    FUN_002448b0(n, this, &q);
    DAT_004e5f0c++;
}
