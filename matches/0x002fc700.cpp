class Inner_2fc700 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Outer_2fc700 {
  public:
    char pad[0x10];
    Inner_2fc700* p;
};
void __fastcall target(Outer_2fc700* self) {
    self->p->f6();
}