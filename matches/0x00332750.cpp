class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Holder {
    char pad[0x80];
    Obj* ptr;

  public:
    void Set(Obj* p);
};
void Holder::Set(Obj* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}