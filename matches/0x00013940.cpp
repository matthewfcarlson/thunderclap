class CAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int vfunc_3(int, int);
    virtual void f4();
    virtual void f5(int);
    virtual int f6(int);
    virtual void f7();
    virtual void f8();
};
int CAction::vfunc_3(int a, int b) {
    return f6(b);
}