// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 12/12)
// FUN_0030bf70 @ 0x0030bf70
struct Vec3 {
    float x, y, z;
};

struct Item {
    char pad[0x10];
    Vec3 pos;
    char pad2[0x64 - 0x1c];
    void FUN_002fd730();
};

struct ItemTable {
    char pad[0x8c];
    Item *items;
};

struct Store {
    char pad[0x10];
    ItemTable *table;
};

struct Child {
    void FUN_0030a7b0(Vec3 a, Vec3 b);
};

struct Mover {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void clearDelta();
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void getDelta(Vec3 *out);
    virtual void afterDelta();

    char active;
    char pad0[3];
    int index;
    char pad1[0x18 - 0xc];
    Store *store;
    char pad2[4];
    Child **begin;
    Child **end;
    char pad3[0xe8 - 0x28];
    float pending;
    char hasPending;

    void FUN_0030bf70();
};

void Mover::FUN_0030bf70()
{
    if ((unsigned)(end - begin) == 0)
        return;

    Vec3 v;
    Vec3 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;

    if ((pending > 0.0f || hasPending) && active) {
        getDelta(&v);
        afterDelta();
        Item *item = &store->table->items[index];
        pending = 0.0f;
        item->FUN_002fd730();
        item->pos.x += v.x;
        item->pos.y += v.y;
        item->pos.z += v.z;
    } else {
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        clearDelta();
    }

    for (unsigned i = 0; i < (unsigned)(end - begin); i++)
        begin[i]->FUN_0030a7b0(w, v);
}
