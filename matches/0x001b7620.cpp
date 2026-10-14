class Item_1b7620 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_1b7620 {
  public:
    Item_1b7620* mItem;
    Item_1b7620* Set(Item_1b7620* item);
};
Item_1b7620* Holder_1b7620::Set(Item_1b7620* item) {
    Item_1b7620* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}