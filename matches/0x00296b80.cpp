// Same code shape as 0x00059d00 (propagated; names are from that function)
class Item_296b80 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_296b80 {
    char pad[0x18];

  public:
    Item_296b80* item;
    void Set(Item_296b80* p);
};
void Owner_296b80::Set(Item_296b80* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}