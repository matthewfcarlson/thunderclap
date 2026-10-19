class Inner_2fc700 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class Outer_2fc700 {
  public:
    char pad[0x10];
    Inner_2fc700* p;
    void target(int a, int b);
};
void Outer_2fc700::target(int a, int b) {
    p->f6(a, b);
}