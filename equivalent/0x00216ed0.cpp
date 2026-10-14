// STATUS: equivalent (tools/equiv.py level 3: 1536 inputs, branch coverage 6/6)
// FUN_00216ed0 @ 0x00216ed0
// Lua 5.0 style GC step: take the next userdata awaiting finalisation, put it back on the
// root list and call its __gc metamethod.
struct Table {
    void* next;
    unsigned char tt;
    unsigned char marked;
    unsigned char flags;
};

struct TObject {
    int tt;
    int value;
};

struct Udata {
    Udata* next;
    unsigned char tt;
    unsigned char marked;
    char pad6[2];
    Table* metatable;
};

struct TString;

struct global_State {
    char pad0[0x14];
    unsigned char currentwhite;
    char pad15[0x1c - 0x15];
    Udata** rootudata;
    char pad20[0x34 - 0x20];
    Udata* tmudata;
    char pad38[0x74 - 0x38];
    TString* tmname[3];
};

struct lua_State {
    char pad0[8];
    TObject* top;
    char pad0c[4];
    global_State* l_G;
    char pad14[0x31 - 0x14];
    unsigned char allowhook;
};

TObject* FUN_00217580(Table* events, int event, TString* ename);   // luaT_gettm
void FUN_002159e0(lua_State* L, TObject* func, int nresults);      // luaD_call

// equiv-conv: FUN_00216ed0 esi
void FUN_00216ed0(lua_State* L)
{
    global_State* g = L->l_G;
    Udata** root = g->rootudata;
    Udata* u = g->tmudata;

    g->tmudata = u->next;
    u->next = *root;
    *L->l_G->rootudata = u;
    u->marked = (u->marked & 0xf8) | g->currentwhite;

    Table* mt = u->metatable;
    if (mt != 0 && (mt->flags & 4) == 0) {
        TObject* tm = FUN_00217580(mt, 2, L->l_G->tmname[2]);
        if (tm != 0) {
            unsigned char oldallow = L->allowhook;
            L->allowhook = 0;
            L->top[0] = *tm;
            L->top[1].value = (int)u;
            L->top[1].tt = 7;
            L->top += 2;
            FUN_002159e0(L, L->top - 2, 0);
            L->allowhook = oldallow;
        }
    }
}
