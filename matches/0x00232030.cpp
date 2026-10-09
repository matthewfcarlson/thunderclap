class Item {
  public:
    virtual void First();
    virtual void Second();
};
class Holder {
  public:
    Item* mItem;
    void Set(Item* p);
};
void Holder::Set(Item* p) {
    if (p)
        p->First();
    if (mItem)
        mItem->Second();
    mItem = p;
}