typedef unsigned int size_t;
void* operator new(size_t);
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int a;
    int b;
};
class Member {
  public:
    Member() throw();
    int a;
    int b;
};
class CGrappleCharacterTemplateCondition : public Base {
  public:
    CGrappleCharacterTemplateCondition() throw();
    virtual void f0();
    int val;
    Member m;
};
CGrappleCharacterTemplateCondition::CGrappleCharacterTemplateCondition() throw() : Base(0), val(0), m() {}
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Base* vfunc_5();
};
Base* Factory::vfunc_5() {
    return new CGrappleCharacterTemplateCondition;
}