class X {
  public:
    virtual void f0();
    virtual void f1();
};
class C {
  public:
    char pad[0x28];
    X* p;
    void run();
};
void C::run() {
    if (p) {
        p->f1();
        p = 0;
    }
}