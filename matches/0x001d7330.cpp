class Item {
  public:
    virtual void F0();
    virtual void F1();
};
class Owner {
  public:
    char pad[0x134];
    Item* item;
    void Set(Item* p);
};
void Owner::Set(Item* p) {
    if (p)
        p->F0();
    if (item)
        item->F1();
    item = p;
}
