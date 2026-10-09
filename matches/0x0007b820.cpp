class Obj {
  public:
    virtual void A();
    virtual void B();
};
class C {
  public:
    char pad[0x374c];
    Obj* items[20];
    int count;
    int total;
    int F(Obj* p);
};
int C::F(Obj* p) {
    int i = count;
    if (i == 20)
        return -1;
    if (p)
        p->A();
    if (items[i])
        items[i]->B();
    items[i] = p;
    ++count;
    ++total;
    return i;
}