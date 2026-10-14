class Item_2b57a0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2b57a0 {
  public:
    char pad[0x7c];
    Item_2b57a0* item;
    void Set(Item_2b57a0* p);
};
void Owner_2b57a0::Set(Item_2b57a0* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
}