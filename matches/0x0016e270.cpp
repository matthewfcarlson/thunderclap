typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Condition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    Condition(int) throw();
    char pad[8];
};
class HealthPercentCondition : public Condition {
  public:
    HealthPercentCondition() throw() : Condition(0), a(0), b(0) {}
    virtual void f5();
    int a;
    int b;
};
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Condition* v5();
};
Condition* Factory::v5() {
    return new HealthPercentCondition;
}
