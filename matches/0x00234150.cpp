class A {
  public:
    virtual void f();
    virtual void g();
};
void FUN_00267090(int);
class B {
  public:
    A* a;
    int b;
};
void __fastcall FUN_00234150(B* p) {
    if (p->a)
        p->a->g();
    p->a = 0;
    FUN_00267090(p->b);
}