class Base {
  public:
    virtual void A();
    virtual void B();
    Base();
};
class X : public Base {
  public:
    virtual void A();
    virtual void B();
    X();
};
X::X() {}
