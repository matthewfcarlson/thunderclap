class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
    char pad0[4];
    Ref* first;
    int value;
    Ref* second;
    int limit;

  public:
    bool Set(Ref* a, int b, Ref* c, int d);
};
bool Owner::Set(Ref* a, int b, Ref* c, int d) {
    if (!a)
        return false;
    if (first && !(d < limit))
        return false;
    a->A();
    if (first)
        first->B();
    first = a;
    value = b;
    if (c)
        c->A();
    if (second)
        second->B();
    Ref** q = &second;
    *q = c;
    limit = d;
    return true;
}