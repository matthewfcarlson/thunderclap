// Same code shape as 0x00059790 (propagated; names are from that function)
class Item {
  public:
    virtual void First();
    virtual void Second();
};
class Owner {
  public:
    char pad[0x10];
    Item* item;
    void Set(Item* p);
};
void Owner::Set(Item* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}