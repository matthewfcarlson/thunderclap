class Item_29b690 {
  public:
    virtual void f();
    virtual void g();
};
class Owner_29b690 {
    char pad0[0x10];

  public:
    int index;
    char pad14[8];
    Item_29b690** slots;
    void Add(Item_29b690*);
};
void Owner_29b690::Add(Item_29b690* item) {
    if (item) {
        Item_29b690** slot = slots + index;
        item->f();
        if (*slot)
            (*slot)->g();
        *slot = item;
        ++index;
    }
}