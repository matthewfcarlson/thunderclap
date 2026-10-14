class Item_461e0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_461e0 {
  public:
    char pad[8];
    int mCapacity;
    int mCount;
    Item_461e0** mItems;
    bool Add(Item_461e0* item);
};
bool Container_461e0::Add(Item_461e0* item) {
    int index = mCount;
    if (index >= mCapacity)
        return false;
    Item_461e0** slot = mItems + index;
    if (item)
        item->A();
    if (*slot)
        (*slot)->B();
    *slot = item;
    ++mCount;
    return true;
}