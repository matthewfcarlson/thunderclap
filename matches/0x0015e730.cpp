class Ref_15e730 {
  public:
    virtual void A();
    virtual void B();
};
class Base_15e730 {
  public:
    virtual void X();
    Base_15e730();
};
class LocomotionSteerAction_15e730 : public Base_15e730 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[0x18];
    int m1;
    Ref_15e730* m2;
    int m3;
    LocomotionSteerAction_15e730(int, Ref_15e730*);
};
LocomotionSteerAction_15e730::LocomotionSteerAction_15e730(int a, Ref_15e730* b) : Base_15e730() {
    int* q = &m1;
    *q = 0;
    m2 = 0;
    m3 = 0;
    m1 = a;
    if (b)
        b->A();
    if (m2)
        m2->B();
    m2 = b;
}
