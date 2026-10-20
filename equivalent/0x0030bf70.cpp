// STATUS: equivalent (tools/equiv.py level 3: 204 inputs, branch coverage 12/12)
// FUN_0030bf70 @ 0x0030bf70
struct Vec3_30bf70 {
    float x, y, z;
};

struct Item_30bf70 {
    char pad[0x10];
    Vec3_30bf70 pos;
    char pad2[0x64 - 0x1c];
    void FUN_002fd730();
};

struct ItemTable_30bf70 {
    char pad[0x8c];
    Item_30bf70 *items;
};

struct Store {
    char pad[0x10];
    ItemTable_30bf70 *table;
};

struct Child_30bf70 {
    void FUN_0030a7b0(Vec3_30bf70 a, Vec3_30bf70 b);
};

struct Mover_30bf70 {
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
    virtual void getDelta(Vec3_30bf70 *out);
    virtual void afterDelta();

    char active;
    char pad0[3];
    int index;
    char pad1[0x18 - 0xc];
    Store *store;
    char pad2[4];
    Child_30bf70 **begin;
    Child_30bf70 **end;
    char pad3[0xe8 - 0x28];
    float pending;
    char hasPending;

    void FUN_0030bf70();
};

void Mover_30bf70::FUN_0030bf70()
{
    if ((unsigned)(end - begin) == 0)
        return;

    Vec3_30bf70 v;
    Vec3_30bf70 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;

    if ((pending > 0.0f || hasPending) && active) {
        getDelta(&v);
        afterDelta();
        Item_30bf70 *item = &store->table->items[index];
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
