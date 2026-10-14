class Item_1cb770 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1cb770 {
    char pad[0x400];
    Item_1cb770* item;

  public:
    void Set(Item_1cb770* p);
};
void Owner_1cb770::Set(Item_1cb770* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
}