class Item_59790 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_59790 {
  public:
    char pad[0x10];
    Item_59790* item;
    void Set(Item_59790* p);
};
void Owner_59790::Set(Item_59790* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}