void* operator new(unsigned int) throw();
class CAxisTimeCondition_57160 {
    char pad[20];

  public:
    CAxisTimeCondition_57160() throw();
    virtual void f();
};
class CAxisUpCondition : public CAxisTimeCondition_57160 {
  public:
    CAxisUpCondition() throw();
    virtual void f();
};
CAxisUpCondition::CAxisUpCondition() throw() : CAxisTimeCondition_57160() {}
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CAxisTimeCondition_57160* make();
};
CAxisTimeCondition_57160* Factory::make() {
    return new CAxisUpCondition;
}