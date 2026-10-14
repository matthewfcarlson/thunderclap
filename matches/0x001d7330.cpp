class Item_1d7330 {
  public:
    virtual void F0();
    virtual void F1();
};
class Owner_1d7330 {
  public:
    char pad[0x134];
    Item_1d7330* item;
    void Set(Item_1d7330* p);
};
void Owner_1d7330::Set(Item_1d7330* p) {
    if (p)
        p->F0();
    if (item)
        item->F1();
    item = p;
}
