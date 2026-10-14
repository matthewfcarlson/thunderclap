class Item_59d00 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_59d00 {
    char pad[0x18];

  public:
    Item_59d00* item;
    void Set(Item_59d00* p);
};
void Owner_59d00::Set(Item_59d00* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}