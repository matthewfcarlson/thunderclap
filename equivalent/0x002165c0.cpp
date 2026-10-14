// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 16/16)
// FUN_002165c0 @ 0x002165c0
// Lua 5.0 luaC_separateudata (all-flag variant)
struct LuaTable {
    char pad0[6];
    unsigned char flags;    // 0x06
};

struct Udata {
    Udata *next;            // 0x00
    unsigned char tt;       // 0x04
    unsigned char marked;   // 0x05
    char pad06[2];
    LuaTable *metatable;    // 0x08
    unsigned int len;       // 0x0c
};

struct GlobalState {
    char pad0[0x1c];
    Udata *rootudata;       // 0x1c
    char pad20[0x34 - 0x20];
    Udata *tmudata;         // 0x34
    char pad38[0x7c - 0x38];
    void *tmname_gc;        // 0x7c
};

struct LuaState {
    char pad0[0x10];
    GlobalState *g;         // 0x10
};

void *FUN_00217580(LuaTable *mt, int event, void *name);

unsigned int FUN_002165c0(LuaState *L, int all)
{
    unsigned int deadmem = 0;
    Udata **p = &L->g->rootudata;
    Udata *curr = *p;
    Udata *collected = 0;
    Udata **lastcollected = &collected;
    while (curr->tt == 7) {
        unsigned char m = curr->marked;
        if (((m & 3) == 0 && all == 0) || (m & 8)) {
            p = &curr->next;
        } else {
            LuaTable *mt = curr->metatable;
            if (mt == 0 || (mt->flags & 4) != 0 || FUN_00217580(mt, 2, L->g->tmname_gc) == 0) {
                curr->marked |= 8;
                p = &curr->next;
            } else {
                deadmem += curr->len + 0x10;
                Udata *next = curr->next;
                curr->marked |= 8;
                *p = next;
                curr->next = 0;
                *lastcollected = curr;
                lastcollected = &curr->next;
            }
        }
        curr = *p;
    }
    *lastcollected = L->g->tmudata;
    L->g->tmudata = collected;
    return deadmem;
}
