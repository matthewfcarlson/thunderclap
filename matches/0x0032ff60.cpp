class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Owner {
    char pad[0x88];
    Ref* ptr;

  public:
    void Set(Ref* p);
};
void Owner::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}