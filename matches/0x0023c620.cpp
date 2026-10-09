class Base {
  public:
    virtual void f();
    Base(int);
};
class Bank : public Base {
  public:
    Bank();
};
Bank::Bank() : Base(0) {}