// Same code shape as 0x001b7620 (propagated; names are from that function)
class Item_2ddc00 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_2ddc00 {
  public:
    Item_2ddc00* mItem;
    Item_2ddc00* Set(Item_2ddc00* item);
};
Item_2ddc00* Holder_2ddc00::Set(Item_2ddc00* item) {
    Item_2ddc00* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}