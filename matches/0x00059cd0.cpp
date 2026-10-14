// Same code shape as 0x00059790 (propagated; names are from that function)
class Item_59cd0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_59cd0 {
  public:
    char pad[0x10];
    Item_59cd0* item;
    void Set(Item_59cd0* p);
};
void Owner_59cd0::Set(Item_59cd0* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}