// Same code shape as 0x001b7620 (propagated; names are from that function)
class Item_333ba0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_333ba0 {
  public:
    Item_333ba0* mItem;
    Item_333ba0* Set(Item_333ba0* item);
};
Item_333ba0* Holder_333ba0::Set(Item_333ba0* item) {
    Item_333ba0* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}