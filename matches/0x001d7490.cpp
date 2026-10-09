class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Owner {
  public:
    char pad[0x11c];
    Ref* value;
    void Set(Ref* p);
};
void Owner::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (value)
        value->Release();
    value = p;
}