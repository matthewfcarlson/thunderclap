class Ref_176300 {
  public:
    virtual void A();
    virtual void B();
};
class Base_176300 {
  public:
    Base_176300();
    virtual void V0();
    char pad[0x18];
};
class Move_176300 : public Base_176300 {
  public:
    int f1c;
    Ref_176300* f20;
    int f24, f28, f2c, f30, f34;
    int f38, f3c, f40, f44, f48, f4c;
    char f50;
    char p[3];
    int f54;
    Move_176300(int, Ref_176300*);
    virtual void V1();
};
Move_176300::Move_176300(int p, Ref_176300* r) {
    int* q = &f1c;
    *q = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f50 = 1;
    f54 = 0;
    f1c = p;
    if (r)
        r->A();
    {
        Ref_176300* o = f20;
        if (o)
            o->B();
    }
    Ref_176300** w = &f20;
    *w = r;
    f34 = 0;
    f30 = 0;
    f2c = 0;
    f4c = 0;
    f48 = 0;
    f44 = 0;
}