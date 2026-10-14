class Item_196640 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_196640 {
  public:
    char pad[0x50];
    Item_196640* item;
    void Set(Item_196640* p);
};
void Owner_196640::Set(Item_196640* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
}