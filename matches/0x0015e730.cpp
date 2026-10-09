class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    virtual void X();
    Base();
};
class Action : public Base {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[0x18];
    int m1;
    Ref* m2;
    int m3;
    Action(int, Ref*);
};
Action::Action(int a, Ref* b) : Base() {
    int* q = &m1;
    *q = 0;
    m2 = 0;
    m3 = 0;
    m1 = a;
    if (b)
        b->A();
    if (m2)
        m2->B();
    m2 = b;
}
