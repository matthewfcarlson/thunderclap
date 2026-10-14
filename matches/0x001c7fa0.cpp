class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Slot {
  public:
    Ref* p;
    void Clear() {
        Ref* q = p;
        if (q) {
            q->Release();
            p = 0;
        }
    }
};
class Obj {
    char pad[8];
    Slot a;
    Slot b;

  public:
    void Set(Ref* x, Ref* y);
};
void Obj::Set(Ref* x, Ref* y) {
    if (x) {
        if (a.p)
            a.Clear();
        a.p = x;
        x->AddRef();
    }
    if (y) {
        if (b.p)
            b.Clear();
        b.p = y;
        y->AddRef();
    }
}