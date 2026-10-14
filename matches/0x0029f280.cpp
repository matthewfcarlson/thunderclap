struct Item_29f280 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
struct Container_29f280 {
    char pad[0x10];
    int count;
    char pad2[4];
    Item_29f280** items;
};
struct Receiver_29f280 {
    void first(int);
    void second(int, Item_29f280*);
};
struct Obj_29f280 {
    Container_29f280* container;
    char pad[8];
    Receiver_29f280* receiver;
    int n;
};
int* __fastcall FUN_0029f280(Obj_29f280* self) {
    self->receiver->first(self->n);
    for (int i = 0; i < self->n; ++i) {
        Container_29f280* c = self->container;
        Item_29f280* item = i < c->count ? c->items[i] : (Item_29f280*)0;
        item->f6();
        self->receiver->second(i, item);
    }
    return (int*)self->receiver;
}