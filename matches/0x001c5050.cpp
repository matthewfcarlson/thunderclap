class Item_1c5050 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_1c5050 {
  public:
    char pad[0x14];
    Item_1c5050* item;
    void Set(Item_1c5050* p);
};
void Owner_1c5050::Set(Item_1c5050* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}