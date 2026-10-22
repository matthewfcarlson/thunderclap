typedef unsigned int size_t;
void* operator new(size_t) throw();
class CCondition_58750 {
  public:
    CCondition_58750(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class CSmartPropAngleCondition : public CCondition_58750 {
  public:
    CSmartPropAngleCondition() throw();
    virtual void f0();
    float b;
    float c;
};
CSmartPropAngleCondition::CSmartPropAngleCondition() throw() : CCondition_58750(0) {
    b = 0.0f;
    c = 1.57079637f;
}
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CSmartPropAngleCondition* vfunc_5();
};
CSmartPropAngleCondition* Factory::vfunc_5() {
    return new CSmartPropAngleCondition;
}