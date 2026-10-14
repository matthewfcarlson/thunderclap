class Item_29bb60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class Owner_29bb60 {
  public:
    char pad0[0x10];
    unsigned int count;
    char pad14[8];
    Item_29bb60** items;
};
void __fastcall FUN_0029bb60(Owner_29bb60* self) {
    for (unsigned int i = 0; i < self->count; ++i) {
        self->items[i]->f3();
        self->items[i]->f4();
    }
}