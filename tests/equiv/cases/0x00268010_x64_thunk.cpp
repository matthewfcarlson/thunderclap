// 0x00268010 core::TimerList::vfunc_0_adj4 (8 B): matches/0x00268010.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?f@C_268010@fn_00268010@@W3AEXXZ
namespace fn_00268010 {
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
} // namespace fn_00268010



