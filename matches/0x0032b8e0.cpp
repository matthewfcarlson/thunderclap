class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
class Owner {
    char pad[0x80];
    Obj* item;

  public:
    void Set(Obj* p);
};
void Owner::Set(Obj* p) {
    if (p)
        p->Add();
    if (item)
        item->Release();
    item = p;
}