class Item_1b6d00 {
  public:
    virtual void Release();
    virtual void AddRef();
};
class Owner_1b6d00 {
  public:
    void Remove(Item_1b6d00*);
    int Set(int index, Item_1b6d00* item);
};
int Owner_1b6d00::Set(int index, Item_1b6d00* item) {
    if (index < 0)
        return -1;
    if (item == 0)
        return -1;
    Item_1b6d00* old = ((Item_1b6d00**)this)[index];
    if (old)
        Remove(old);
    item->Release();
    old = ((Item_1b6d00**)this)[index];
    if (old)
        old->AddRef();
    ((Item_1b6d00**)this)[index] = item;
    ((int*)item)[2] = index;
    return index;
}