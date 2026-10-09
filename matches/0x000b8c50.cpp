struct Obj;
struct Entry {
    char pad[0x14];
    int field14;
};

Obj* __cdecl GetManager();
Entry* __cdecl FindEntry(int key);

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Obj* v3(int arg);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(int arg);
};

void __stdcall TargetFn(int param1, int param2) {
    Obj* obj = GetManager()->v3(param1);
    if (obj) {
        Entry* entry = FindEntry(param2);
        if (entry) {
            obj->v19(entry->field14);
        }
    }
}
