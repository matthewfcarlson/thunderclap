class Item {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[0x50];
    Item* item;
    void Set(Item* p);
};
void Owner::Set(Item* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
}