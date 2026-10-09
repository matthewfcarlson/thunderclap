class Item {
  public:
    virtual void Destroy();
    virtual void Release();
};
class Owner {
  public:
    char pad[0x1ec40];
    Item* items[4];
    int count;
    bool Add(Item* item);
};
bool Owner::Add(Item* item) {
    int n = count;
    if (n >= 4)
        return false;
    int i = 0;
    while (i < count) {
        if (items[i] == item)
            return false;
        ++i;
    }
    if (item)
        item->Destroy();
    if (items[n])
        items[n]->Release();
    items[n] = item;
    count = count + 1;
    return true;
}