class Base_23c620 {
  public:
    virtual void f();
    Base_23c620(int);
};
class Bank : public Base_23c620 {
  public:
    Bank();
};
Bank::Bank() : Base_23c620(0) {}