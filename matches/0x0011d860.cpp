class Obj {
  public:
    Obj();
    virtual void A();
    virtual void B();
};
class Action : public Obj {
  public:
    char pad[0x18];
    int a, b, c;
    virtual void C();
    Action(int x, Obj* p);
};
Action::Action(int x, Obj* p) {
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    a = x;
    if (p)
        p->A();
    if (b)
        ((Obj*)b)->B();
    b = (int)p;
}