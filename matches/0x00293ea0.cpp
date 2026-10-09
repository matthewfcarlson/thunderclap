class Item {
  public:
    virtual void Use();
};
class Owner {
  public:
    virtual void V();
    char pad[0x38];
    Item* volatile items[32];
    int Add(Item* item);
};
int Owner::Add(Item* item) {
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
