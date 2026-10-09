class V {
  public:
    virtual void f0();
    virtual void f1();
};
class Pad {
  public:
    virtual void z();
};
class Q : public Pad, public V {};
class P {
  public:
    virtual void x0();
    virtual void x1();
    char pad[8];
    Q* p;
};
void P::x1() {
    p->f1();
}