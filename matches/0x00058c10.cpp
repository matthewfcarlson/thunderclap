typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class CCondition_58c10 {
  public:
    CCondition_58c10(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int a;
    int b;
};
class CStageCondition : public CCondition_58c10 {
  public:
    CStageCondition() throw();
    virtual void f0();
    int stage;
    int other;
};
CStageCondition::CStageCondition() throw() : CCondition_58c10(0) {
    stage = 2;
    other = 0;
}
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CStageCondition* f5();
};
CStageCondition* Factory::f5() {
    return new CStageCondition;
}