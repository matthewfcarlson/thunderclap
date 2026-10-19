// STATUS: equivalent (tools/equiv.py level 3: 20031 inputs, branch coverage 15/16, incomplete)
// FUN_00213e50 @ 0x00213e50
// FUN_00213e50 @ 0x00213e50
// FUN_00213e50 @ 0x00213e50
// Lua 5.0 lua_setupvalue: aux_upvalue inlined, then pops the stack top into the upvalue
#include "decls/data/game/global.h"

struct GCObject_213e50 {
    char pad[5];
    unsigned char marked;
};

struct TObject_213e50 {
    int tt;
    GCObject_213e50 *gc;
};

struct TString_213e50 {
    char pad[0x10];
    char str[1];
};

struct Proto_213e50 {
    char pad[0x1c];
    TString_213e50 **upvalues;     // 0x1c
    char pad20[4];
    int sizeupvalues;       // 0x24
};

struct UpVal {
    char pad[8];
    TObject_213e50 *v;             // 0x8
};

struct Closure_213e50 {
    char pad[5];
    unsigned char marked;       // 0x5
    unsigned char isC;          // 0x6
    unsigned char nupvalues;    // 0x7
    union {
        struct {
            char pad[8];
            TObject_213e50 upvalue[1]; // 0x10
        } c;
        struct {
            char pad[4];
            Proto_213e50 *p;           // 0xc
            char pad2[8];
            UpVal *upvals[1];   // 0x18
        } l;
    };
};

struct lua_State_213e50 {
    char pad[8];
    TObject_213e50 *top;
};


// index2adr
TObject_213e50 *__fastcall FUN_00212bb0(int idx, lua_State_213e50 *L);
void __cdecl FUN_00217100(lua_State_213e50 *L, void *o, void *v);

const char *__cdecl FUN_00213e50(lua_State_213e50 *L, int funcindex, int n)
{
    TObject_213e50 *fi = FUN_00212bb0(funcindex, L);
    if (fi->tt != 6)
        return 0;

    Closure_213e50 *f = (Closure_213e50 *)fi->gc;
    TObject_213e50 *val;
    const char *name;
    if (f->isC) {
        if (n > f->nupvalues)
            return 0;
        val = &f->c.upvalue[n - 1];
        name = ((char*)&DAT_003f335c);
    } else {
        Proto_213e50 *p = f->l.p;
        if (n > p->sizeupvalues)
            return 0;
        name = p->upvalues[n - 1]->str;
        val = f->l.upvals[n - 1]->v;
        if (name == 0)
            return 0;
    }

    L->top--;
    *val = *L->top;
    if (L->top->tt >= 4) {
        GCObject_213e50 *o = L->top->gc;
        if ((o->marked & 3) != 0 && (fi->gc->marked & 4) != 0)
            FUN_00217100(L, fi->gc, o);
    }
    return name;
}
