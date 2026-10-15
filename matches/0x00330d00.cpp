class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Obj {
    char pad[0x98];
    Ref* ref;

  public:
    void Set(Ref* p);
};
void Obj::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ref)
        ref->Release();
    ref = p;
}