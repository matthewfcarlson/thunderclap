// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 15/16, incomplete)
// FUN_002fe480 @ 0x002fe480
extern "C" void *__cdecl FUN_0008d690(unsigned int size);

struct Source_2fe480 {
    char pad0[0x18];
    int value;                // 0x18
};

struct Channel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad04[0x19 - 4];
    char muted;               // 0x19
};

struct Item_2fe480 {
    char pad0[0x20];
    Channel *channel;         // 0x20
    char pad24[0x50 - 0x24];
    char keep;                // 0x50
    char pad51[0x68 - 0x51];
    char active;              // 0x68
    char pending;             // 0x69
    void FUN_00304740(int value);
};

class Entity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(Source_2fe480 *src);
    virtual void v14(Item_2fe480 *item);
    char pad[0x8c - 8];
    Entity *FUN_002fe3a0(int a, int b);
};

class Owner_2fe480 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Item_2fe480 *v5(Entity *e);
};

class Provider_2fe480 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
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
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual Source_2fe480 *v28(Entity *e);
};

Entity *__cdecl FUN_002fe480(int a, Owner_2fe480 *owner, Provider_2fe480 *provider)
{
    Entity *mem = (Entity *)FUN_0008d690(0x8c);
    Entity *e = 0;
    if (mem)
        e = mem->FUN_002fe3a0(a, 0);
    if (e == 0)
        return 0;
    Source_2fe480 *src = 0;
    if (provider) {
        src = provider->v28(e);
        e->v13(src);
    }
    if (owner) {
        Item_2fe480 *item = owner->v5(e);
        e->v14(item);
        if (item->active || item->pending)
            item->channel->v10();
        item->channel->v8();
        if (!item->keep) {
            item->channel->muted = 0;
            item->active = 1;
            item->pending = 1;
        }
        if (src)
            item->FUN_00304740(src->value);
    }
    return e;
}
