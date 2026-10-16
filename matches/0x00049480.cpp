class Base {
  public:
    Base(int);
    virtual void f();
};
class CSmartPropTypeCondition : public Base {
  public:
    CSmartPropTypeCondition();
    virtual void f();
    char pad[8];
    int a, b;
};
CSmartPropTypeCondition::CSmartPropTypeCondition() : Base(0) {
    a = 0;
    b = 0;
}