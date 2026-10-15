class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Obj {
    char pad[0x80];
    Ref* p;

  public:
    void Set(Ref* q);
};
void Obj::Set(Ref* q) {
    if (q)
        q->AddRef();
    if (p)
        p->Release();
    p = q;
}