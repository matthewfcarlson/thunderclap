class Helper {
  public:
    void run(void*, int);
};
class DebugConsole {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(int, int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    char pad[0xa0];
    Helper* h;
};
void DebugConsole::vfunc_6(int a, int b) {
    int local[4];
    local[0] = 4;
    local[1] = (int)this;
    local[2] = a;
    local[3] = b;
    h->run(local, 16);
}