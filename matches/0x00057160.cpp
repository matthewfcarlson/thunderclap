void* operator new(unsigned int) throw();
class Base {
    char pad[20];

  public:
    Base() throw();
    virtual void f();
};
class CAxisUpCondition : public Base {
  public:
    CAxisUpCondition() throw();
    virtual void f();
};
CAxisUpCondition::CAxisUpCondition() throw() : Base() {}
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base* make();
};
Base* Factory::make() {
    return new CAxisUpCondition;
}