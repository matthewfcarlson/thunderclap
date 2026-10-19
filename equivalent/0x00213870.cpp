// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00213870 @ 0x00213870
struct TObject_213870 {
    int tt;
    void *gc;
};
struct GCObject_213870 {
    char pad[5];
    unsigned char marked;
};
struct lua_State_213870 {
    char pad[8];
    TObject_213870 *top;
};

// index2adr: edx = L, ecx = idx
TObject_213870 *__fastcall FUN_00212bb0(int idx, lua_State_213870 *L);
TObject_213870 *__cdecl FUN_00219f60(lua_State_213870 *L, void *h, int key);
void __cdecl FUN_00217100(lua_State_213870 *L, void *h, void *v);

void FUN_00213870(lua_State_213870 *L, int idx, int key)
{
    TObject_213870 *t = FUN_00212bb0(idx, L);
    TObject_213870 *val = L->top - 1;
    TObject_213870 *slot = FUN_00219f60(L, t->gc, key);
    *slot = *val;
    if (L->top[-1].tt >= 4) {
        GCObject_213870 *v = (GCObject_213870 *)L->top[-1].gc;
        if ((v->marked & 3) != 0) {
            GCObject_213870 *h = (GCObject_213870 *)t->gc;
            if ((h->marked & 4) != 0)
                FUN_00217100(L, h, v);
        }
    }
    L->top--;
}
