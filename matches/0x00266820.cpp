// Same code shape as 0x00059d00 (propagated; names are from that function)
class Item_266820 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_266820 {
    char pad[0x18];

  public:
    Item_266820* item;
    void Set(Item_266820* p);
};
void Owner_266820::Set(Item_266820* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}