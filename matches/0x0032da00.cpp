class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Obj {
    char pad[0x84];
    Ref* ptr;

  public:
    void Set(Ref* p);
};
void Obj::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}