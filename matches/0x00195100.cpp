class Base_195100 {
  public:
    virtual void F();
    virtual void G();
    char pad[0x18];
    Base_195100();
};
class FPA : public Base_195100 {
  public:
    int a;
    Base_195100* b;
    int c;
    int d;
    int e;
    int f;
    FPA(int x, Base_195100* p);
    virtual void F();
    virtual void G();
};
FPA::FPA(int x, Base_195100* p) : Base_195100() {
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
