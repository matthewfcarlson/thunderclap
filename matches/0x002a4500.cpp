class Item_2a4500 {
  public:
    virtual void First();
    virtual void Release();
};
struct Slot_2a4500 {
    Item_2a4500* item;
    char pad[12];
};
class Owner_2a4500 {
  public:
    char pad[0x48];
    Slot_2a4500* slots;
    void Set(int index, Item_2a4500* item);
};
void Owner_2a4500::Set(int index, Item_2a4500* item) {
    Slot_2a4500* s = slots + index;
    if (item)
        item->First();
    Item_2a4500* old = s->item;
    if (old)
        old->Release();
    s->item = item;
}