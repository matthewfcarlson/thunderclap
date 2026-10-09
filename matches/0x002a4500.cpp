class Item {
  public:
    virtual void First();
    virtual void Release();
};
struct Slot {
    Item* item;
    char pad[12];
};
class Owner {
  public:
    char pad[0x48];
    Slot* slots;
    void Set(int index, Item* item);
};
void Owner::Set(int index, Item* item) {
    Slot* s = slots + index;
    if (item)
        item->First();
    Item* old = s->item;
    if (old)
        old->Release();
    s->item = item;
}