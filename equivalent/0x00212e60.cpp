// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00212e60 @ 0x00212e60
struct TObject_212e60 {
    int tt;
    void* gc;
};
struct GCObject_212e60 {
    char pad[5];
    unsigned char marked;
};
struct lua_State_212e60 {
    char pad[8];
    TObject_212e60* top;
    TObject_212e60* base;
};
// index2adr: edx = L, ecx = idx
// equiv-conv: FUN_00212bb0 edx ecx
TObject_212e60* FUN_00212bb0(lua_State_212e60* L, int idx);
void FUN_00217100(lua_State_212e60* L, void* o, void* v);
void FUN_00212e60(lua_State_212e60* L, int idx) {
    TObject_212e60* src = L->top - 1;
    TObject_212e60* o = FUN_00212bb0(L, idx);
    *o = *src;
    if (idx < -10001) {
        if (L->top[-1].tt >= 4) {
            GCObject_212e60* v = (GCObject_212e60*)L->top[-1].gc;
            if ((v->marked & 3) != 0) {
                GCObject_212e60* f = (GCObject_212e60*)L->base[-1].gc;
                if ((f->marked & 4) != 0)
                    FUN_00217100(L, f, v);
            }
        }
    }
    L->top--;
}
