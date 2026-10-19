struct Provider_be230 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual int slot44();
};
struct Binding_be230 {
    void FUN_000f8500(void*, int, int);
};
struct Channel {
    char pad[0x18];
    Binding_be230 binding;
};
struct Item_be230 {
    char pad0[4];
    Provider_be230* provider;
    char pad8[0x990];
    Channel* first;
    Channel* second;
    Channel* third;
    void FUN_000bb820(void*, int, int);
    void FUN_000e5f70();
    void FUN_000e5f00(int);
};
struct Manager_be230 {
    char pad[0x2218];
    Item_be230* active;
    Item_be230* FUN_000e7620(int);
    bool FUN_000be230(int, void*, void*, void*, void*, int, int, int);
};
bool Manager_be230::FUN_000be230(int id, void* setup, void* a, void* b, void* c, int mode, int x, int y) {
    if (active)
        return false;
    Item_be230* item = FUN_000e7620(id);
    if (setup)
        item->FUN_000bb820(setup, x, y);
    if (a) {
        Binding_be230* dest = &item->first->binding;
        dest->FUN_000f8500(a, item->provider->slot44(), 1);
    }
    if (b) {
        Binding_be230* dest = &item->second->binding;
        dest->FUN_000f8500(b, item->provider->slot44(), 1);
    }
    if (c) {
        Binding_be230* dest = &item->third->binding;
        dest->FUN_000f8500(c, item->provider->slot44(), 1);
    }
    item->FUN_000e5f70();
    item->FUN_000e5f00(mode);
    active = item;
    return true;
}
