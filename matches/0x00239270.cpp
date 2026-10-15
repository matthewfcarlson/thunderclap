typedef unsigned int size_t;
void* operator new(size_t);
namespace fight {
class Condition {
  public:
    virtual void f();
    char pad[8];
    void* a;
    void* b;
    Condition(int) throw();
};
class PrintCondition : public Condition {
  public:
    PrintCondition() throw();
    virtual void f();
};
PrintCondition::PrintCondition() throw() : Condition(0) {
    a = 0;
    b = 0;
}
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Condition* vfunc_5();
};
Condition* Factory::vfunc_5() {
    return new PrintCondition;
}
} // namespace fight