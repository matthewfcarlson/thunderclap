typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class Sub {
  public:
    Sub() throw();
    char pad[8];
};
class Condition : public Base {
  public:
    Condition() throw() : Base(0), field(0), sub() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int field;
    Sub sub;
};
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Condition* vfunc_5();
};
Condition* Factory::vfunc_5() {
    return new Condition;
}
