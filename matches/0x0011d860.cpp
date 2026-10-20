class Obj_11d860 {
  public:
    Obj_11d860();
    virtual void A();
    virtual void B();
};
class StrafeCircleAction_11d860 : public Obj_11d860 {
  public:
    char pad[0x18];
    int a, b, c;
    virtual void C();
    StrafeCircleAction_11d860(int x, Obj_11d860* p);
};
StrafeCircleAction_11d860::StrafeCircleAction_11d860(int x, Obj_11d860* p) {
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    a = x;
    if (p)
        p->A();
    if (b)
        ((Obj_11d860*)b)->B();
    b = (int)p;
}