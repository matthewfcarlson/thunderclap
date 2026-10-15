class Item {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Owner {
    char pad[0x80];
    Item* item;

  public:
    void Set(Item* p);
};
void Owner::Set(Item* p) {
    if (p)
        p->AddRef();
    if (item)
        item->Release();
    item = p;
}