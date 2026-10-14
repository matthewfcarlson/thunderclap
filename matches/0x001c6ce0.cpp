// Same code shape as 0x00059790 (propagated; names are from that function)
class Item_1c6ce0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_1c6ce0 {
  public:
    char pad[0x10];
    Item_1c6ce0* item;
    void Set(Item_1c6ce0* p);
};
void Owner_1c6ce0::Set(Item_1c6ce0* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}