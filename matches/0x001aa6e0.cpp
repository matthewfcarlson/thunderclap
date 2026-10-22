typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Condition_1aa6e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
    int val;
    Condition_1aa6e0(int) throw();
};
class Event_PropStateDescCondition_1aa6e0 : public Condition_1aa6e0 {
  public:
    Event_PropStateDescCondition_1aa6e0() throw() : Condition_1aa6e0(0) { val = 0; }
    virtual void a();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Condition_1aa6e0* f();
};
Condition_1aa6e0* Factory::f() {
    return new Event_PropStateDescCondition_1aa6e0;
}
