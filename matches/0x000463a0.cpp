class Obj {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D(void*, int, int);
};
class X {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D(void*, int, int);
    void F(int a, int b);
};
void X::F(int a, int b) {
    Obj o;
    D(&o, a, b);
}