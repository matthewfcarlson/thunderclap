class Item {
  public:
    virtual void Release();
    virtual void AddRef();
};
class Owner {
  public:
    void Remove(Item*);
    int Set(int index, Item* item);
};
int Owner::Set(int index, Item* item) {
    if (index < 0)
        return -1;
    if (item == 0)
        return -1;
    Item* old = ((Item**)this)[index];
    if (old)
        Remove(old);
    item->Release();
    old = ((Item**)this)[index];
    if (old)
        old->AddRef();
    ((Item**)this)[index] = item;
    ((int*)item)[2] = index;
    return index;
}