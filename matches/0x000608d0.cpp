class Base {
  public:
    Base();
    virtual void A();
    virtual void B();
    int m4;
};

class Derived : public Base {
  public:
    Derived();
    virtual void C();
    int m8;
    int mC;
    int m10;
    int m14;
};

Derived::Derived() : Base() {
    mC = 0;
    m10 = 0;
    m14 = -1;
    m8 = 1;
}
