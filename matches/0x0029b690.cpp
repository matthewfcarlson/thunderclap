class Item {
  public:
    virtual void f();
    virtual void g();
};
class Owner {
    char pad0[0x10];

  public:
    int index;
    char pad14[8];
    Item** slots;
    void Add(Item*);
};
void Owner::Add(Item* item) {
    if (item) {
        Item** slot = slots + index;
        item->f();
        if (*slot)
            (*slot)->g();
        *slot = item;
        ++index;
    }
}