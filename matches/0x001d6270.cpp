class A {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual unsigned int f11();
};
struct B {
    void FUN(unsigned int);
};
struct Obj {
    char pad[0x9c];
    A* p;
    char pad2[0x7c];
    B* q;
};
void __fastcall FUN_001d6270(Obj* self) {
    unsigned int x = self->p->f11();
    self->q->FUN(x);
}