extern "C" char DAT_00415bb4[];
class Base_15ea80 {
  public:
    Base_15ea80();
    virtual void A();
    virtual void B();
    virtual void C();
};
class Ref_15ea80 {
  public:
    virtual void X();
    virtual void Release();
};
class GrappleLocomotionSteerAction : public Base_15ea80 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[24];
    int m1;
    Ref_15ea80* m2;
    int m3;
    GrappleLocomotionSteerAction(int, Ref_15ea80*);
};
GrappleLocomotionSteerAction::GrappleLocomotionSteerAction(int x, Ref_15ea80* p) {
    *(int*)this = ((int)DAT_00415bb4);
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
