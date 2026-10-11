class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    Base();
    virtual void V0();
    char pad[0x18];
};
class Surf : public Base {
  public:
    int a;
    Ref* b;
    int c[6];
    float f;
    int d;
    Surf(int, Ref*);
    virtual void V0();
};
Surf::Surf(int x, Ref* r) : Base() {
    int* q = &a;
    *q = 0;
    b = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
    f = 1.0f;
    d = 0;
    a = x;
    if (r)
        r->A();
    if (b)
        b->B();
    b = r;
}
