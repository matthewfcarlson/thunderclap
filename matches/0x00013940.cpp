class CAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, int);
    virtual void f4();
    virtual void f5(int);
    virtual void f6(int);
    virtual void f7();
    virtual void f8();
};
void CAction::vfunc_3(int a, int b) {
    f6(b);
}