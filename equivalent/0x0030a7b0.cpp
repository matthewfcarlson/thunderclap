// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 13/14, incomplete)
// FUN_0030a7b0 @ 0x0030a7b0
struct Vec3 {
    float x, y, z;
};

struct Item {
    char pad0[4];
    Vec3 delta;
    Vec3 pos;
    char pad2[0x64 - 0x1c];
    void FUN_002fd730();
};

struct ItemTable {
    char pad[0x8c];
    Item *items;
};

struct Store {
    char pad0[0x10];
    ItemTable *table;
    char pad1[0x98 - 0x14];
    Vec3 refPos;
};

struct Mover;

struct Anchor {
    char pad[0xd4];
    Vec3 pos;
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
    Anchor *anchor;
    Mover **begin;
    Mover **end;
    char pad3[0xd4 - 0x28];
    Vec3 target;
    char pad4[0xe8 - 0xe0];
    float pending;
    char hasPending;

    void FUN_0030a7b0(Vec3 a, Vec3 b);
};

void Mover::FUN_0030a7b0(Vec3 a, Vec3 b)
{
    Vec3 ref;
    if (anchor) {
        ref = anchor->pos;
    } else {
        ref = store->refPos;
    }

    struct Frame {
        Vec3 v;
        volatile float dx;
        float spare[2];
    } f;
    Vec3 &v = f.v;
    f.dx = target.x - ref.x;
    float dx = f.dx;
    double dy = target.y - ref.y;
    double dz = target.z - ref.z;

    v.x = b.y * dz - b.z * dy;
    v.z = b.x * dy - b.y * dx;
    double cy = b.z * dx - b.x * dz;

    a.x += v.x;
    a.y += cy;
    a.z += v.z;

    Item *item = &store->table->items[index];
    item->FUN_002fd730();
    item->delta.x += a.x;
    item->delta.y += a.y;
    item->delta.z += a.z;

    if ((pending > 0.0f || hasPending) && active) {
        getDelta(&v);
        afterDelta();
        b.x += v.x;
        pending = 0.0f;
        b.y += v.y;
        b.z += v.z;
    }

    item = &store->table->items[index];
    item->FUN_002fd730();
    item->pos.x += b.x;
    item->pos.y += b.y;
    item->pos.z += b.z;

    for (unsigned i = 0; i < (unsigned)(end - begin); i++)
        begin[i]->FUN_0030a7b0(a, b);

    clearDelta();
}
