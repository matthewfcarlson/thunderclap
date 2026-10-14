class B_295c40 {
  public:
    B_295c40();
    virtual void f();
};
class C_295c40 : public B_295c40 {
  public:
    C_295c40();
    int pad[3];
    int a;
    int b;
};
C_295c40::C_295c40() {
    a = 6;
    b = 0;
}