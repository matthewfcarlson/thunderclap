// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00212e60 @ 0x00212e60
struct TObject {
    int tt;
    void* gc;
};
struct GCObject {
    char pad[5];
    unsigned char marked;
};
struct lua_State {
    char pad[8];
    TObject* top;
    TObject* base;
};
// index2adr: edx = L, ecx = idx
// equiv-conv: FUN_00212bb0 edx ecx
TObject* FUN_00212bb0(lua_State* L, int idx);
void FUN_00217100(lua_State* L, void* o, void* v);
void FUN_00212e60(lua_State* L, int idx) {
    TObject* src = L->top - 1;
    TObject* o = FUN_00212bb0(L, idx);
    *o = *src;
    if (idx < -10001) {
        if (L->top[-1].tt >= 4) {
            GCObject* v = (GCObject*)L->top[-1].gc;
            if ((v->marked & 3) != 0) {
                GCObject* f = (GCObject*)L->base[-1].gc;
                if ((f->marked & 4) != 0)
                    FUN_00217100(L, f, v);
            }
        }
    }
    L->top--;
}
