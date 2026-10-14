// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00213870 @ 0x00213870
struct TObject {
    int tt;
    void *gc;
};
struct GCObject {
    char pad[5];
    unsigned char marked;
};
struct lua_State {
    char pad[8];
    TObject *top;
};

// index2adr: edx = L, ecx = idx
// equiv-conv: FUN_00212bb0 edx ecx
TObject *FUN_00212bb0(lua_State *L, int idx);
TObject *__cdecl FUN_00219f60(lua_State *L, void *h, int key);
void __cdecl FUN_00217100(lua_State *L, void *h, void *v);

void FUN_00213870(lua_State *L, int idx, int key)
{
    TObject *t = FUN_00212bb0(L, idx);
    TObject *val = L->top - 1;
    TObject *slot = FUN_00219f60(L, t->gc, key);
    *slot = *val;
    if (L->top[-1].tt >= 4) {
        GCObject *v = (GCObject *)L->top[-1].gc;
        if ((v->marked & 3) != 0) {
            GCObject *h = (GCObject *)t->gc;
            if ((h->marked & 4) != 0)
                FUN_00217100(L, h, v);
        }
    }
    L->top--;
}
