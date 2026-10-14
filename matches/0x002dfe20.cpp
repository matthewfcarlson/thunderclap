class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    Base();
    virtual void f();
    char pad[0x3c];
};
class Mid : public Base {
  public:
    int a, b, c, d, e;
    char pad2[4];
    Mid(int x, int y) : Base() {
        a = 0;
        b = 0;
        c = x;
        d = y;
        e = -1;
    }
};
class PrimGroupOptimized : public Mid {
  public:
    PrimGroupOptimized(Ref*, int, int);
    virtual void f();
    Ref* ref;
    void SetRef(Ref*);
};
inline void PrimGroupOptimized::SetRef(Ref* p) {
    if (p)
        p->AddRef();
    if (ref)
        ref->Release();
    ref = p;
}
PrimGroupOptimized::PrimGroupOptimized(Ref* p, int x, int y) : Mid(x, y) {
    ref = 0;
    SetRef(p);
}
