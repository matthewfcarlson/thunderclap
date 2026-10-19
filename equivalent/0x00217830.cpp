// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 17/18, incomplete)
// FUN_00217830 @ 0x00217830
struct Table_217830;
struct TObject_217830 {
    int tt;
    union {
        Table_217830* h;
        int n;
        int w;
    } value;
};
struct Table_217830 {
    char pad0[6];
    unsigned char flags;
    char pad7;
    Table_217830* metatable;
};
struct GlobalState_217830 {
    char pad0[0x74];
    void* tmname;
};
struct lua_State_217830 {
    char pad0[8];
    TObject_217830* top;
    char pad0c[4];
    GlobalState_217830* G;
    char pad14[4];
    TObject_217830* stack_last;
    TObject_217830* stack;
};
TObject_217830* __cdecl FUN_00219e90(Table_217830* h, TObject_217830* key);
TObject_217830* __cdecl FUN_00217580(Table_217830* mt, int event, void* name);
TObject_217830* __cdecl FUN_002175b0(lua_State_217830* L, TObject_217830* o, int event);
void __cdecl FUN_00214c90(lua_State_217830* L, TObject_217830* o, const char* op);
void __cdecl FUN_00214a90(lua_State_217830* L, const char* msg);
void __cdecl FUN_00215460(lua_State_217830* L, int n);
void __cdecl FUN_002159e0(lua_State_217830* L, TObject_217830* func, int nresults);

void __cdecl FUN_00217830(lua_State_217830* L, TObject_217830* t, TObject_217830* key, TObject_217830* val) {
    for (int loop = 0; loop < 100; ++loop) {
        TObject_217830* metamethod = 0;
        if (t->tt == 5) {
            Table_217830* table = t->value.h;
            TObject_217830* entry = FUN_00219e90(table, key);
            if (entry->tt == 0) {
                Table_217830* meta = table->metatable;
                if (meta && !(meta->flags & 1))
                    metamethod = FUN_00217580(meta, 0, L->G->tmname);
            }
            if (!metamethod) {
                *val = *entry;
                return;
            }
        } else {
            metamethod = FUN_002175b0(L, t, 0);
            if (metamethod->tt == 0)
                FUN_00214c90(L, t, "index");
        }

        if (metamethod->tt == 6) {
            *L->top = *metamethod;
            L->top[1] = *t;
            L->top[2] = *key;
            int resultOffset = (char*)val - (char*)L->stack;
            if ((char*)L->stack_last - (char*)L->top <= 0x18)
                FUN_00215460(L, 3);
            L->top += 3;
            FUN_002159e0(L, L->top - 3, 1);
            L->top -= 1;
            TObject_217830* destination = (TObject_217830*)((char*)L->stack + resultOffset);
            *destination = *L->top;
            return;
        }
        t = metamethod;
    }
    FUN_00214a90(L, "loop in gettable");
}
