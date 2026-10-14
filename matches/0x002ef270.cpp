class Inner_2ef270 {
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
};
class Target_2ef270 {
  public:
    char pad[0x20];
    Inner_2ef270* p;
    char pad2[0x44];
    unsigned char a, b;
    void run();
};
void Target_2ef270::run() {
    a = 1;
    b = 1;
    p->f8();
    p->f9();
}