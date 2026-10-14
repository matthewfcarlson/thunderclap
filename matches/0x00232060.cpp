class Ref_232060 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_232060 {
    char pad0[4];
    Ref_232060* first;
    int value;
    Ref_232060* second;
    int limit;

  public:
    bool Set(Ref_232060* a, int b, Ref_232060* c, int d);
};
bool Owner_232060::Set(Ref_232060* a, int b, Ref_232060* c, int d) {
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
    Ref_232060** q = &second;
    *q = c;
    limit = d;
    return true;
}