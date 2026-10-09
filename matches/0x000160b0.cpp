class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual int h(int, int);
};
class A {
  public:
    Obj* get();
};
class B {
  public:
    Obj* next();
};
class C {
  public:
    Obj* find(int);
};
struct Data {
    char pad[16];
    int value;
};
class CSmartPropSetStateAction {
  public:
    char pad[24];
    A* first;
    Data* second;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool vfunc_7(int);
};
bool CSmartPropSetStateAction::vfunc_7(int arg) {
    Obj* a = first->get();
    B* b = (B*)a;
    a = b->next();
    C* c = (C*)a;
    Obj* p = c->find(0);
    if (p)
        p->h(second->value, 1);
    return false;
}