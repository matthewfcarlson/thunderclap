class V {
  public:
    virtual void f0();
    virtual void f1();
};
class Pad_277390 {
  public:
    virtual void z();
};
class Q_277390 : public Pad_277390, public V {};
class P_277390 {
  public:
    virtual void x0();
    virtual void x1();
    char pad[8];
    Q_277390* p;
};
void P_277390::x1() {
    p->f1();
}