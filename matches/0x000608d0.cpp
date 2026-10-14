class Base_608d0 {
  public:
    Base_608d0();
    virtual void A();
    virtual void B();
    int m4;
};

class Derived_608d0 : public Base_608d0 {
  public:
    Derived_608d0();
    virtual void C();
    int m8;
    int mC;
    int m10;
    int m14;
};

Derived_608d0::Derived_608d0() : Base_608d0() {
    mC = 0;
    m10 = 0;
    m14 = -1;
    m8 = 1;
}
