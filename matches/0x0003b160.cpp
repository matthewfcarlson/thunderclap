class Obj {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
    char pad[0x62c];
    Obj* p;

  public:
    bool F(Obj* x);
};
bool Owner::F(Obj* x) {
    if (x)
        x->A();
    if (p)
        p->B();
    p = x;
    return true;
}