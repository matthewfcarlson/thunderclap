class A_268010 {
  public:
    virtual void f();
    virtual ~A_268010();
};
class B_268010 {
  public:
    virtual void f();
    virtual ~B_268010();
};
class C_268010 : public A_268010, public B_268010 {
  public:
    virtual void f();
    virtual ~C_268010();
    int mX;
};
void C_268010::f() {
    mX = 0;
}
C_268010::~C_268010() {}
