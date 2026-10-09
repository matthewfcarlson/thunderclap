class ReaderInner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, int);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
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
    virtual void f20();
    virtual void f21();
};
class IFileDataReader {
  public:
    char pad[8];
    ReaderInner* inner;
    int vfunc_4(int a, int b);
};
int IFileDataReader::vfunc_4(int a, int b) {
    inner->f3(a, b, 1);
    inner->f21();
    return b;
}