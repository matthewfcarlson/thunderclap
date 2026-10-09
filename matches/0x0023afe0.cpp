class ScriptReader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void slot8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    int first(int, int, int);
    void second(int, int, int);
    void vfunc_8(int, int, int, int);
};
void ScriptReader::vfunc_8(int a, int b, int c, int d) {
    int x = first(a, b, 4);
    second(x, c, d);
}
