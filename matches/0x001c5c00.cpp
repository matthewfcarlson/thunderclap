// Same code shape as 0x001c3d20 (propagated; names are from that function)
class A_1c5c00 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c5c00 {
  public:
    A_1c5c00* p;
    void run();
};
void B_1c5c00::run() {
    if (p)
        p->g();
    p = 0;
}