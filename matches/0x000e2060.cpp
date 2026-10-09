class FELayout {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
};
class Inner {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual bool a12(int, int);
};
class SingleLayout : public FELayout {
  public:
    char pad[0x40];
    Inner* inner;
    virtual void g5();
    virtual void g6();
    virtual bool g7(int, int);
};
bool SingleLayout::g7(int a, int b) {
    if (!inner)
        return false;
    return inner->a12(a, b);
}