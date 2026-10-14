// Same code shape as 0x001c3d20 (propagated; names are from that function)
class A_2c6630 {
  public:
    virtual void f();
    virtual void g();
};
class B_2c6630 {
  public:
    A_2c6630* p;
    void run();
};
void B_2c6630::run() {
    if (p)
        p->g();
    p = 0;
}