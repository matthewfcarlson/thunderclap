typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class LuaCondition : public Base {
  public:
    LuaCondition() throw() : Base(0) {
        a = 0;
        b = 0;
    }
    virtual void f0();
    virtual void f1();
    virtual void f2();
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
    virtual Base* vfunc_5();
};
Base* Factory::vfunc_5() {
    return new LuaCondition;
}