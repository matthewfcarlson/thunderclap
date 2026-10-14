class X_285a20 {
  public:
    virtual void f0();
    virtual void f1();
};
class C_285a20 {
  public:
    char pad[0x28];
    X_285a20* p;
    void run();
};
void C_285a20::run() {
    if (p) {
        p->f1();
        p = 0;
    }
}