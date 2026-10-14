class A_338630 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct B_338630 {
    char pad[4];
    A_338630* p;
};
void __fastcall target(B_338630* self) {
    self->p->f2();
}