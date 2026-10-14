class Inner_1afe70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int, int, int, int);
};
struct Holder_1afe70 {
    char pad[8];
    Inner_1afe70* p;
};
void __stdcall target(Holder_1afe70* self, int a, int b, int c, int d, int e) {
    self->p->f6(b, a, c, d, e);
}