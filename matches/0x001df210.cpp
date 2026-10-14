class Item_1df210 {
  public:
    virtual void Destroy();
    virtual void Release();
};
class Owner_1df210 {
  public:
    char pad[0x1ec40];
    Item_1df210* items[4];
    int count;
    bool Add(Item_1df210* item);
};
bool Owner_1df210::Add(Item_1df210* item) {
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