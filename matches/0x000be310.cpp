struct Provider {
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
    virtual unsigned int slot44(int);
};
struct Binding {
    void FUN_000f8500(void*, unsigned int);
};
struct Channel {
    char pad[0x18];
    Binding binding;
};
struct Item {
    char pad0[4];
    Provider* provider;
    char pad8[0x990];
    Channel* first;
    Channel* second;
    Channel* third;
    void FUN_000bb970(void*, unsigned int, unsigned int);
    void FUN_000e5f70();
    void FUN_000e5f00(unsigned int);
};
struct Owner {
    char pad[0x2218];
    Item* active;
    Item* FUN_000e7620(unsigned int);
    bool FUN_000be310(unsigned int, void*, void*, void*, void*, unsigned int, unsigned int, unsigned int);
};
bool Owner::FUN_000be310(unsigned int id, void* setup, void* a, void* b, void* c, unsigned int mode,
                         unsigned int x, unsigned int y) {
    if (active)
        return false;
    Item* item = FUN_000e7620(id);
    if (setup)
        item->FUN_000bb970(setup, x, y);
    if (a) {
        Binding* binding = &item->first->binding;
        unsigned int value = item->provider->slot44(1);
        binding->FUN_000f8500(a, value);
    }
    if (b) {
        Binding* binding = &item->second->binding;
        unsigned int value = item->provider->slot44(1);
        binding->FUN_000f8500(b, value);
    }
    if (c) {
        Binding* binding = &item->third->binding;
        unsigned int value = item->provider->slot44(1);
        binding->FUN_000f8500(c, value);
    }
    item->FUN_000e5f70();
    item->FUN_000e5f00(mode);
    active = item;
    return true;
}