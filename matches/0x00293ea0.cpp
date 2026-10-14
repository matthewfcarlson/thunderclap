class Item_293ea0 {
  public:
    virtual void Use();
};
class Owner_293ea0 {
  public:
    virtual void V();
    char pad[0x38];
    Item_293ea0* volatile items[32];
    int Add(Item_293ea0* item);
};
int Owner_293ea0::Add(Item_293ea0* item) {
    int i = 0;
    do {
        if (items[i] == 0) {
            item->Use();
            items[i] = item;
            return i;
        }
        ++i;
    } while (i < 32);
    return -1;
}
