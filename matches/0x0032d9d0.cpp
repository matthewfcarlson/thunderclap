class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Owner {
    char pad[0x80];
    Obj* obj;

  public:
    void Set(Obj* p);
};
void Owner::Set(Obj* p) {
    if (p)
        p->AddRef();
    if (obj)
        obj->Release();
    obj = p;
}