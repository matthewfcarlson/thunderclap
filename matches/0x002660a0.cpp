// Same code shape as 0x00059790 (propagated; names are from that function)
class Item_2660a0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_2660a0 {
  public:
    char pad[0x10];
    Item_2660a0* item;
    void Set(Item_2660a0* p);
};
void Owner_2660a0::Set(Item_2660a0* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}