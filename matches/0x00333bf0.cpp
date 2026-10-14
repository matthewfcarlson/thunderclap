// Same code shape as 0x001b7620 (propagated; names are from that function)
class Item_333bf0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_333bf0 {
  public:
    Item_333bf0* mItem;
    Item_333bf0* Set(Item_333bf0* item);
};
Item_333bf0* Holder_333bf0::Set(Item_333bf0* item) {
    Item_333bf0* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}