class Base {
  public:
    virtual void F();
    virtual void G();
    char pad[0x18];
    Base();
};
class FPA : public Base {
  public:
    int a;
    Base* b;
    int c;
    int d;
    int e;
    int f;
    FPA(int x, Base* p);
    virtual void F();
    virtual void G();
};
FPA::FPA(int x, Base* p) : Base() {
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (p)
        p->F();
    if (b)
        b->G();
    b = p;
}
