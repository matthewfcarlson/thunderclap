// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// FUN_002138e0 @ 0x002138e0
// Lua 5.0 lua_setmetatable
struct GCObject {
    char pad[5];
    unsigned char marked;
};

struct TObject {
    int tt;
    GCObject* gc;
};

struct Table {
    char pad[8];
    GCObject* metatable;    // 0x8
};

struct lua_State {
    char pad[8];
    TObject* top;
};

// index2adr
// equiv-conv: FUN_00212bb0 edx ecx
TObject* FUN_00212bb0(lua_State* L, int idx);
void __cdecl FUN_00217100(lua_State* L, void* o, void* v);

int FUN_002138e0(lua_State* L, int objindex)
{
    TObject* obj = FUN_00212bb0(L, objindex);
    GCObject* mt = 0;
    if (L->top[-1].tt != 0)
        mt = L->top[-1].gc;
    if (obj->tt != 5 && obj->tt != 7) {
        L->top--;
        return 0;
    }
    ((Table*)obj->gc)->metatable = mt;
    if (mt != 0 && (mt->marked & 3) != 0 && (obj->gc->marked & 4) != 0)
        FUN_00217100(L, obj->gc, mt);
    L->top--;
    return 1;
}
