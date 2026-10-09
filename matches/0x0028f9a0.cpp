class A {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6(int);
    virtual void F7();
    virtual void F8(int);
    virtual void F9();
    virtual void F10(int);
    virtual void F11();
    virtual void F12(int);
};
class B {
  public:
    virtual void G0();
    virtual void G1();
    virtual void G2();
    virtual void G3();
    virtual void G4();
    virtual void G5();
    virtual void G6();
    virtual void G7();
    virtual void G8();
    virtual void G9();
    virtual void G10();
    virtual void G11();
    virtual void G12();
    virtual void G13(int);
};
extern A* gA;
extern B** gB;
class X {
  public:
    int refs;
    char pad[0xc8];
    int a, b, c, d;
    char pad2[0x18];
    unsigned char flag;
    void Fn();
};
void X::Fn() {
    ++refs;
    gA->F4();
    if (d) {
        gA->F6(a);
        gA->F8(b);
        gA->F10(c);
        gA->F12(d);
    }
    (**gB).G13(0);
    flag = 1;
}