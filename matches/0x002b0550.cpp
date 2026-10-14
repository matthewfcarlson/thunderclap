// Same code shape as 0x001c3d20 (propagated; names are from that function)
class A_2b0550 {
  public:
    virtual void f();
    virtual void g();
};
class B_2b0550 {
  public:
    A_2b0550* p;
    void run();
};
void B_2b0550::run() {
    if (p)
        p->g();
    p = 0;
}