class Item_3ee70 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_3ee70 {
  public:
    char pad[0x22b4];
    Item_3ee70* item;
    void Set(Item_3ee70*);
};
void Owner_3ee70::Set(Item_3ee70* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}