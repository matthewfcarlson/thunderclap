class A_1d6270 {
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
struct B_1d6270 {
    void FUN(unsigned int);
};
struct Obj_1d6270 {
    char pad[0x9c];
    A_1d6270* p;
    char pad2[0x7c];
    B_1d6270* q;
};
void __fastcall FUN_001d6270(Obj_1d6270* self) {
    unsigned int x = self->p->f11();
    self->q->FUN(x);
}