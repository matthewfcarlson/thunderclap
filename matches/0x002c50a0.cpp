// Same code shape as 0x001c3d20 (propagated; names are from that function)
class A_2c50a0 {
  public:
    virtual void f();
    virtual void g();
};
class B_2c50a0 {
  public:
    A_2c50a0* p;
    void run();
};
void B_2c50a0::run() {
    if (p)
        p->g();
    p = 0;
}