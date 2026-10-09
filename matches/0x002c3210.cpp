class AdaptPDDI {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int a, int b, int c);
};
void Helper(int a, int b, int c);
void AdaptPDDI::f2(int a, int b, int c) {
    Helper(a, b, c);
}
