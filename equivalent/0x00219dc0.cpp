// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_00219dc0 @ 0x00219dc0
#include "decls/data/engine/unknown.h"

struct TObject_219dc0 {
    int tt;
    union {
        float n;
        unsigned int bits;
        void *p;
    } value;
};

struct Node {
    TObject_219dc0 key;            // 0x00
    TObject_219dc0 val;            // 0x08
    Node *next;             // 0x10
};

struct Table_219dc0 {
    char pad00[7];
    unsigned char lsizenode;    // 0x07
    char pad08[4];
    TObject_219dc0 *array;             // 0x0c
    Node *node;                 // 0x10
    char pad14[8];
    int sizearray;              // 0x1c
};

    // luaO_nilobject

// Lua 5.0 luaH_getnum with lua_Number == float.
const TObject_219dc0 *__cdecl luaH_getnum(Table_219dc0 *t, int key)
{
    if (1 <= key && key <= t->sizearray)
        return &t->array[key - 1];

    float nk = (float)key;
    union {
        float f;
        unsigned int bits;
    } h;
    h.f = nk + 1.0f;
    unsigned int mod = ((1u << t->lsizenode) - 1) | 1;
    Node *n = &t->node[h.bits % mod];
    do {
        if (n->key.tt == 3 && n->key.value.n == nk)
            return &n->val;
        n = n->next;
    } while (n != 0);
    return ((TObject_219dc0*)&DAT_00426824);
}
