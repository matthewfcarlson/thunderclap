// STATUS: equivalent (tools/equiv.py level 3: 1536 inputs, branch coverage 6/6)
// FUN_00216ed0 @ 0x00216ed0
// Lua 5.0 style GC step: take the next userdata awaiting finalisation, put it back on the
// root list and call its __gc metamethod.
#include "compat/ptr.h"
struct Table_216ed0 {
    void* next;
    unsigned char tt;
    unsigned char marked;
    unsigned char flags;
};

struct TObject_216ed0 {
    int tt;
    int value;
};

struct Udata_216ed0 {
    Udata_216ed0* next;
    unsigned char tt;
    unsigned char marked;
    char pad6[2];
    Table_216ed0* metatable;
};

struct TString;

struct global_State_216ed0 {
    char pad0[0x14];
    unsigned char currentwhite;
    char pad15[0x1c - 0x15];
    Udata_216ed0** rootudata;
    char pad20[0x34 - 0x20];
    Udata_216ed0* tmudata;
    char pad38[0x74 - 0x38];
    TString* tmname[3];
};

struct lua_State_216ed0 {
    char pad0[8];
    TObject_216ed0* top;
    char pad0c[4];
    global_State_216ed0* l_G;
    char pad14[0x31 - 0x14];
    unsigned char allowhook;
};

TObject_216ed0* FUN_00217580(Table_216ed0* events, int event, TString* ename);   // luaT_gettm
void FUN_002159e0(lua_State_216ed0* L, TObject_216ed0* func, int nresults);      // luaD_call

// equiv-conv: FUN_00216ed0 esi
void FUN_00216ed0(lua_State_216ed0* L)
{
    global_State_216ed0* g = L->l_G;
    Udata_216ed0** root = g->rootudata;
    Udata_216ed0* u = g->tmudata;

    g->tmudata = u->next;
    u->next = *root;
    *L->l_G->rootudata = u;
    u->marked = (u->marked & 0xf8) | g->currentwhite;

    Table_216ed0* mt = u->metatable;
    if (mt != 0 && (mt->flags & 4) == 0) {
        TObject_216ed0* tm = FUN_00217580(mt, 2, L->l_G->tmname[2]);
        if (tm != 0) {
            unsigned char oldallow = L->allowhook;
            L->allowhook = 0;
            L->top[0] = *tm;
            L->top[1].value = (hulk_intptr)u;
            L->top[1].tt = 7;
            L->top += 2;
            FUN_002159e0(L, L->top - 2, 0);
            L->allowhook = oldallow;
        }
    }
}
