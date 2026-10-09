class Item {
  public:
    virtual void A();
    virtual void B();
};
class Container {
  public:
    char pad[8];
    int mCapacity;
    int mCount;
    Item** mItems;
    bool Add(Item* item);
};
bool Container::Add(Item* item) {
    int index = mCount;
    if (index >= mCapacity)
        return false;
    Item** slot = mItems + index;
    if (item)
        item->A();
    if (*slot)
        (*slot)->B();
    *slot = item;
    ++mCount;
    return true;
}