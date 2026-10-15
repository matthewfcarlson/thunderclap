typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Base {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
    int val;
    Base(int) throw();
};
class Event : public Base {
  public:
    Event() throw() : Base(0) { val = 0; }
    virtual void a();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base* f();
};
Base* Factory::f() {
    return new Event;
}
