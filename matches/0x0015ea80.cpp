class Base {
  public:
    Base();
    virtual void A();
    virtual void B();
    virtual void C();
};
class Ref {
  public:
    virtual void X();
    virtual void Release();
};
class GrappleLocomotionSteerAction : public Base {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[24];
    int m1;
    Ref* m2;
    int m3;
    GrappleLocomotionSteerAction(int, Ref*);
};
GrappleLocomotionSteerAction::GrappleLocomotionSteerAction(int x, Ref* p) {
    *(int*)this = 0x415bb4;
    volatile int* q = &m1;
    *q = 0;
    m2 = 0;
    m3 = 0;
    m1 = x;
    if (p)
        p->X();
    if (m2)
        m2->Release();
    m2 = p;
}
