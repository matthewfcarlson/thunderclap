class CCondition_49480 {
  public:
    CCondition_49480(int);
    virtual void f();
};
class CSmartPropTypeCondition : public CCondition_49480 {
  public:
    CSmartPropTypeCondition();
    virtual void f();
    char pad[8];
    int a, b;
};
CSmartPropTypeCondition::CSmartPropTypeCondition() : CCondition_49480(0) {
    a = 0;
    b = 0;
}