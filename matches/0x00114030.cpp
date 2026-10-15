typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
};
class HulkActionLargestCondition : public Base {
  public:
    HulkActionLargestCondition() throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int a;
    int b;
};
inline HulkActionLargestCondition::HulkActionLargestCondition() throw() : Base(0), a(0), b(0) {}
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
    return new HulkActionLargestCondition;
}