// STATUS: equivalent (tools/equiv.py level 3: 324 inputs, branch coverage 8/8)
// FUN_00219c30 @ 0x00219c30
union Value_219c30 {
    float n;
    void *p;
    int i;
};

struct TValue_219c30 {
    int tt;
    Value_219c30 value;
};

struct Node {
    TValue_219c30 key;                 // 0x00
    TValue_219c30 val;                 // 0x08
    Node *next;                 // 0x10
};

struct Global_219c30 {
    char pad0[0x60];
    Node dummynode;             // 0x60
};

struct lua_State_219c30 {
    char pad0[0x10];
    Global_219c30 *g;                  // 0x10
};

struct Table_219c30 {
    char pad0[7];
    unsigned char lsizenode;    // 0x7
    char pad8[8];
    Node *node;                 // 0x10
    Node *lastfree;             // 0x14
};

void *__cdecl FUN_0021add0(lua_State_219c30 *L, void *block, unsigned int oldsize, unsigned int newsize);
void __cdecl FUN_00214a90(lua_State_219c30 *L, const char *msg);

// Lua 5.0 setnodevector: L arrives in ebx and the table in esi.
// equiv-conv: FUN_00219c30 ebx esi stack
void FUN_00219c30(lua_State_219c30 *L, Table_219c30 *t, int lsize)
{
    int size = 1 << lsize;

    if (lsize > 24)
        FUN_00214a90(L, "table overflow");

    if (lsize == 0) {
        t->node = &L->g->dummynode;
    } else {
        t->node = (Node *)FUN_0021add0(L, 0, 0, size * sizeof(Node));
        for (int i = 0; i < size; i++) {
            t->node[i].next = 0;
            t->node[i].key.tt = 0;
            t->node[i].val.tt = 0;
        }
    }
    t->lsizenode = (unsigned char)lsize;
    t->lastfree = &t->node[size - 1];
}
