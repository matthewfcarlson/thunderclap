class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Holder {
    char pad[0x80];
    Obj* p;

  public:
    void Set(Obj* q);
};
void Holder::Set(Obj* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}