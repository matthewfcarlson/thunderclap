class A {
  public:
    virtual void f();
    virtual void g();
};
void thunk(int);
class B {
  public:
    A* a;
    int b;
};
void __fastcall FUN_0029c640(B* p) {
    p->a->g();
    thunk(p->b);
}