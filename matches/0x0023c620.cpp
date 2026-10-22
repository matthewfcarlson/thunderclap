class Branch_23c620 {
  public:
    virtual void f();
    Branch_23c620(int);
};
class Bank : public Branch_23c620 {
  public:
    Bank();
};
Bank::Bank() : Branch_23c620(0) {}