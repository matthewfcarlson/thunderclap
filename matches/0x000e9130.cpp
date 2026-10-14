class NewItem {
  public:
    virtual void Dispose();
};
class OldItem {
  public:
    virtual void First();
    virtual void Release();
};
class Owner_e9130 {
  public:
    char pad[0x64];
    OldItem* item;
    void Set(NewItem* p);
};
void Owner_e9130::Set(NewItem* p) {
    if (p)
        p->Dispose();
    if (item)
        item->Release();
    item = (OldItem*)p;
}