// Same code shape as 0x001b7620 (propagated; names are from that function)
class Item {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder {
  public:
    Item* mItem;
    Item* Set(Item* item);
};
Item* Holder::Set(Item* item) {
    Item* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}