// Same code shape as 0x00059d00 (propagated; names are from that function)
class Item_294980 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_294980 {
    char pad[0x18];

  public:
    Item_294980* item;
    void Set(Item_294980* p);
};
void Owner_294980::Set(Item_294980* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}