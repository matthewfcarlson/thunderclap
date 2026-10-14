class Obj_3b160 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_3b160 {
    char pad[0x62c];
    Obj_3b160* p;

  public:
    bool F(Obj_3b160* x);
};
bool Owner_3b160::F(Obj_3b160* x) {
    if (x)
        x->A();
    if (p)
        p->B();
    p = x;
    return true;
}