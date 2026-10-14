// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// FUN_002138e0 @ 0x002138e0
// Lua 5.0 lua_setmetatable
struct GCObject_2138e0 {
    char pad[5];
    unsigned char marked;
};

struct TObject_2138e0 {
    int tt;
    GCObject_2138e0* gc;
};

struct Table_2138e0 {
    char pad[8];
    GCObject_2138e0* metatable;    // 0x8
};

struct lua_State_2138e0 {
    char pad[8];
    TObject_2138e0* top;
};

// index2adr
// equiv-conv: FUN_00212bb0 edx ecx
TObject_2138e0* FUN_00212bb0(lua_State_2138e0* L, int idx);
void __cdecl FUN_00217100(lua_State_2138e0* L, void* o, void* v);

int FUN_002138e0(lua_State_2138e0* L, int objindex)
{
    TObject_2138e0* obj = FUN_00212bb0(L, objindex);
    GCObject_2138e0* mt = 0;
    if (L->top[-1].tt != 0)
        mt = L->top[-1].gc;
    if (obj->tt != 5 && obj->tt != 7) {
        L->top--;
        return 0;
    }
    ((Table_2138e0*)obj->gc)->metatable = mt;
    if (mt != 0 && (mt->marked & 3) != 0 && (obj->gc->marked & 4) != 0)
        FUN_00217100(L, obj->gc, mt);
    L->top--;
    return 1;
}
