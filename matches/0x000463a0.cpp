class Obj_463a0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D(void*, int, int);
};
class X_463a0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D(void*, int, int);
    void F(int a, int b);
};
void X_463a0::F(int a, int b) {
    Obj_463a0 o;
    D(&o, a, b);
}