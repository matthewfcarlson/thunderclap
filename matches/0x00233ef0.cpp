class Obj_233ef0 {
  public:
    virtual void A();
    virtual void B();
};
class Holder_233ef0 {
  public:
    Obj_233ef0* p;
    void Set(int unused, Obj_233ef0* x);
};
void Holder_233ef0::Set(int unused, Obj_233ef0* x) {
    if (x)
        x->A();
    if (p)
        p->B();
    p = x;
}