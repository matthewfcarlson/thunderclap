class Inner_1d7590 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    void helper(int);
};
struct Wrap_1d7590 {
    char pad[0x10];
    Inner_1d7590* ptr;
};
class Outer_1d7590 {
  public:
    char pad[0xa0];
    Wrap_1d7590* ptr;
    void run();
};
void Outer_1d7590::run() {
    Wrap_1d7590* w = ptr;
    if (w) {
        Inner_1d7590* p = w->ptr;
        if (p) {
            p->helper(0);
            p->f7();
        }
    }
}