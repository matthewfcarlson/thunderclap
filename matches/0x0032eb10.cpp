class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
class Owner {
    char pad[0x9c];
    Obj* ptr;

  public:
    void Set(Obj* p);
};
void Owner::Set(Obj* p) {
    if (p)
        p->Add();
    if (ptr)
        ptr->Release();
    ptr = p;
}