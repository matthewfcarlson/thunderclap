// Same code shape as 0x001b7620 (propagated; names are from that function)
class Item_2fc3a0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_2fc3a0 {
  public:
    Item_2fc3a0* mItem;
    Item_2fc3a0* Set(Item_2fc3a0* item);
};
Item_2fc3a0* Holder_2fc3a0::Set(Item_2fc3a0* item) {
    Item_2fc3a0* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}