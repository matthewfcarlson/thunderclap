class Item_232030 {
  public:
    virtual void First();
    virtual void Second();
};
class Holder_232030 {
  public:
    Item_232030* mItem;
    void Set(Item_232030* p);
};
void Holder_232030::Set(Item_232030* p) {
    if (p)
        p->First();
    if (mItem)
        mItem->Second();
    mItem = p;
}